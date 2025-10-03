# falcon-core

Python compiled version of the main repository for falcon autotuning.

## Install from source

We recommend using the [uv](https://docs.astral.sh/uv/getting-started/installation/) package manager. To install via uv first setup an empty venv

```console
uv venv -y; uv pip install .
```

Everything should be installed and ready to go.

If you are interested in running the tests, you can instead run

```console
uv venv -y; uv pip install '.[test]' 
```

To get the typings moved correctly you should go to the source directory of falcon-core and run

```console
make python-types
```
