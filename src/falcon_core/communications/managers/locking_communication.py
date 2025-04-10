"""Base class for global context managers."""

from typing import TYPE_CHECKING

from .dependancies import TypeVar, time, uuid, valkey

if TYPE_CHECKING:
    from .typing import Callable

T = TypeVar("T")
R = TypeVar("R")


class LockingCommunication:
    """A base class implementing locking communication with Falcon.

    This class is involved in primitive communications such as status.
    It is not a full-fledged context manager and will update state variables.
    """

    _client: valkey.Valkey
    _namespace: str
    _lock_timeout: int
    _max_retries: int
    _retry_delay: float

    def __init__(
        self,
        namespace: str = "global",
        lock_timeout: int = 5,
        max_retries: int = 3,
        retry_delay: float = 0.2,
    ):
        """Initialize the context manager.

        Args:
            namespace: The namespace for the lock.
            lock_timeout: Lock timeout in seconds.
            max_retries: Maximum number of retries.
            retry_delay: Delay between retries in seconds.
        """
        self._namespace = namespace
        self._client = valkey.Valkey()
        self._lock_timeout = lock_timeout
        self._max_retries = max_retries
        self._retry_delay = retry_delay

    def __enter__(self):
        """Return the context manager."""
        return self

    def __exit__(self, exc_type, exc_value, traceback):
        """Clean up resources when exiting the context."""
        self._client.close()

    def _lock(
        self,
        target_key: str,
        callable: "Callable[...,T]",
        blocking: bool = True,
        *args,
        **kwargs,
    ) -> tuple[bool, T | None]:
        """Execute a callable with a lock.

        Args:
            target_key: The key to lock.
            callable: The function to call.
            lock_timeout: Lock timeout in seconds.
            blocking: If False, returns status instead of raising exception when lock can't be acquired.
            args: Arguments to pass to the callable.
            kwargs: Keyword arguments to pass to the callable.

        Returns:
            tuple: (success, result) - success is True if operation was successful, result is the return value of callable.

        Raises:
            PermissionError: If blocking is True and unable to acquire lock.
        """
        lock_key = f"lock:{self._namespace}:{target_key}"
        lock_id = str(uuid.uuid4())

        # Acquire lock with timeout
        acquired = self._client.set(lock_key, lock_id, nx=True, ex=self._lock_timeout)

        if acquired:
            try:
                # Perform the update under lock protection and capture the result
                result = callable(*args, **kwargs)
                return True, result
            finally:
                # Release the lock (only if it's still ours)
                script = """
                if redis.call('get', KEYS[1]) == ARGV[1] then
                    return redis.call('del', KEYS[1])
                else
                    return 0
                end
                """
                self._client.eval(script, 1, lock_key, lock_id)
        else:
            if blocking:
                msg = "Failed to acquire lock"
                raise PermissionError(msg)
            return False, None

    def _with_retry(
        self,
        operation: "Callable[..., R]",
        *args,
        **kwargs,
    ) -> R | None:
        """Execute an operation with retries.

        Args:
            operation: The operation to execute with retries
            *args: Arguments to pass to the operation
            **kwargs: Keyword arguments to pass to the operation

        Returns:
            tuple: (success, result) - success is True if operation was successful,
                  result is the return value from the operation
        """
        retries = 0
        while retries <= self._max_retries:
            if out := operation(*args, **kwargs):
                return out

            # We couldn't acquire the lock or operation failed, so we'll retry
            retries += 1
            if retries <= self._max_retries:
                time.sleep(self._retry_delay)

        # We've exhausted our retries
        return None

    def _with_bool_retry(
        self,
        operation: "Callable[..., R]",
        *args,
        **kwargs,
    ) -> bool:
        """Execute an operation with retries.

        Args:
            operation: The operation to execute with retries
            *args: Arguments to pass to the operation
            **kwargs: Keyword arguments to pass to the operation

        Returns:
            bool: True if operation was successful, False otherwise
        """
        return bool(self._with_retry(operation, *args, **kwargs))

    def set(
        self,
        key: str,
        value: str,
        blocking: bool = True,
    ) -> bool:
        """Set the program status using distributed locks.

        Args:
            key: The key of the variable.
            value: The value of the variable.
            target_application: The application to set the status for.
            lock_timeout: Lock timeout in seconds.
            blocking: If False, returns status instead of raising exception when lock can't be acquired.

        Returns:
            bool: True if status was set successfully, False if non-blocking and lock wasn't acquired.

        """
        return self._lock(
            callable=self._set,
            target_key=key,
            key=key,
            value=value,
            blocking=blocking,
        )[0]

    @property
    def namespace(self) -> str:
        """Return the namespace."""
        return self._namespace

    def _set(self, key: str, value: str):
        """Set a global variable.

        Args:
            key: The key of the variable.
            value: The value of the variable.
        """
        self._client.hset(self._namespace, key, value)

    def _get(self, key: str) -> str | None:
        """Get a global variable.

        Args:
            key: The key of the variable.

        Returns:
            The value of the variable.

        Raises:
            TypeError: If the value is not a string or None.
        """
        out = self._client.hget(self._namespace, key)
        if isinstance(out, bytes):
            out = out.decode("utf-8")
        if isinstance(out, str):
            return out
        if out is None:
            return None
        msg = f"Expected str or None, got {type(out)}"
        raise TypeError(msg)

    def get(self, key: str) -> str:
        """Get a global variable.

        Args:
            key: The key of the variable.

        Returns:
            The value of the variable.

        Raises:
            TypeError: If the value is not a string.
        """
        out = self._get(key=key)
        if isinstance(out, str):
            return out
        msg = f"Expected str, got {type(out)}"
        raise TypeError(msg)
