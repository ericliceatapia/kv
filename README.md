# kv - Key-Value Store

A minimalist C++ Key-Value store developed for Operating Systems coursework.

## Features

-   **Batch Processing**: Execute multiple commands in a single run.
-   **Persistence**: Automatic laod/save to `database.txt`.
-   **Modularity**: Separated parser, logic, and interface.

## Build Requirements

-   **Compiler**: `g++`
-   **Build Tool**: `make`
-   **Environment**: Linux/Unix-based systems

## Build Instructions

The project utilizes a custom Makefile.

```bash
make        # build
make clean  # remove build artifacts
```

## Command Format

Commands use a comma-separated format:

-   `p,key,value`: Put/Update a key.
-   `g,key`: Get a key.
-   `d,key`: Delete a key.
-   `c`: Clear all keys and values.
-   `a`: List all keys and values.
    **Example**: `./kv p,1,eric g,1 d,1 a`

## Structure

The project follows a modular structure to separate the entry point from the core logic:

-   `main.cpp`: Program entry and CLI interface.
-   `src/`: Implementation files for storage logic and data structures.
-   `include/`: Header files and interface definitions.
-   `obj/`: Isolated build artifacts for clean incremental compilation.
