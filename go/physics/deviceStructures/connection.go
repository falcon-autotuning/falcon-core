package devicestructures

import "C"

import (
	"runtime"
	"sync"
	"unsafe"
)

type Connection struct {
	handle C.ConnectionHandle
	mu     sync.RWMutex
	closed bool
}

// Internal cleanup
func (c *Connection) closeHandle() {
	c.mu.Lock()
	defer c.mu.Unlock()
	if !c.closed && c.handle != nil {
		C.Connection_destroy(c.handle)
		c.closed = true
		c.handle = nil
	}
}

func NewBarrierGate(name string) *Connection {
	cname := C.CString(name)
	defer C.free(unsafe.Pointer(cname))
	conn := &Connection{handle: C.Connection_create_barrier_gate(cname)}
	runtime.SetFinalizer(conn, func(c *Connection) { c.closeHandle() })
	return conn
}

func NewPlungerGate(name string) *Connection {
	cname := C.CString(name)
	defer C.free(unsafe.Pointer(cname))
	conn := &Connection{handle: C.Connection_create_plunger_gate(cname)}
	runtime.SetFinalizer(conn, func(c *Connection) { c.closeHandle() })
	return conn
}

func NewReservoirGate(name string) *Connection {
	cname := C.CString(name)
	defer C.free(unsafe.Pointer(cname))
	conn := &Connection{handle: C.Connection_create_reservoir_gate(cname)}
	runtime.SetFinalizer(conn, func(c *Connection) { c.closeHandle() })
	return conn
}

func NewScreeningGate(name string) *Connection {
	cname := C.CString(name)
	defer C.free(unsafe.Pointer(cname))
	conn := &Connection{handle: C.Connection_create_screening_gate(cname)}
	runtime.SetFinalizer(conn, func(c *Connection) { c.closeHandle() })
	return conn
}

func NewOhmic(name string) *Connection {
	cname := C.CString(name)
	defer C.free(unsafe.Pointer(cname))
	conn := &Connection{handle: C.Connection_create_ohmic(cname)}
	runtime.SetFinalizer(conn, func(c *Connection) { c.closeHandle() })
	return conn
}

func ConnectionFromJSON(json string) *Connection {
	cjson := C.CString(json)
	defer C.free(unsafe.Pointer(cjson))
	conn := &Connection{handle: C.Connection_from_json_string(cjson)}
	runtime.SetFinalizer(conn, func(c *Connection) { c.closeHandle() })
	return conn
}

func (c *Connection) Close() error {
	c.closeHandle()
	runtime.SetFinalizer(c, nil)
	return nil
}

func (c *Connection) Name() string {
	c.mu.RLock()
	defer c.mu.RUnlock()
	if c.closed || c.handle == nil {
		return ""
	}
	return C.GoString(C.Connection_name(c.handle))
}

func (c *Connection) Type() string {
	c.mu.RLock()
	defer c.mu.RUnlock()
	if c.closed || c.handle == nil {
		return ""
	}
	return C.GoString(C.Connection_type(c.handle))
}

func (c *Connection) IsDotGate() bool {
	c.mu.RLock()
	defer c.mu.RUnlock()
	if c.closed || c.handle == nil {
		return false
	}
	return bool(C.Connection_is_dot_gate(c.handle))
}

func (c *Connection) IsBarrierGate() bool {
	c.mu.RLock()
	defer c.mu.RUnlock()
	if c.closed || c.handle == nil {
		return false
	}
	return bool(C.Connection_is_barrier_gate(c.handle))
}

func (c *Connection) IsPlungerGate() bool {
	c.mu.RLock()
	defer c.mu.RUnlock()
	if c.closed || c.handle == nil {
		return false
	}
	return bool(C.Connection_is_plunger_gate(c.handle))
}

func (c *Connection) IsReservoirGate() bool {
	c.mu.RLock()
	defer c.mu.RUnlock()
	if c.closed || c.handle == nil {
		return false
	}
	return bool(C.Connection_is_reservoir_gate(c.handle))
}

func (c *Connection) IsScreeningGate() bool {
	c.mu.RLock()
	defer c.mu.RUnlock()
	if c.closed || c.handle == nil {
		return false
	}
	return bool(C.Connection_is_screening_gate(c.handle))
}

func (c *Connection) IsOhmic() bool {
	c.mu.RLock()
	defer c.mu.RUnlock()
	if c.closed || c.handle == nil {
		return false
	}
	return bool(C.Connection_is_ohmic(c.handle))
}

func (c *Connection) IsGate() bool {
	c.mu.RLock()
	defer c.mu.RUnlock()
	if c.closed || c.handle == nil {
		return false
	}
	return bool(C.Connection_is_gate(c.handle))
}

func (c *Connection) Equal(other *Connection) bool {
	c.mu.RLock()
	defer c.mu.RUnlock()
	if c.closed || c.handle == nil {
		return false
	}
	return bool(C.Connection_equal(c.handle, other.handle))
}

func (c *Connection) NotEqual(other *Connection) bool {
	c.mu.RLock()
	defer c.mu.RUnlock()
	if c.closed || c.handle == nil {
		return false
	}
	return bool(C.Connection_not_equal(c.handle, other.handle))
}

func (c *Connection) ToJSON() string {
	c.mu.RLock()
	defer c.mu.RUnlock()
	if c.closed || c.handle == nil {
		return ""
	}
	return C.GoString(C.Connection_to_json_string(c.handle))
}
