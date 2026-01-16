# Key-Value


## Structure
The project follows a modular structure to separate the entry point from the core logic:
- `main.cpp`: Program entry and CLI interface.
- `src/`: Implementation files for storage logic and data structures.
- `include/`: Header files and interface definitions.
- `obj/`: Isolated build artifacts for clean incremental compilation.

## Build Requirements
- **Compiler**: `g++`
- **Build Tool**: `make`
- **Environment**: Linux/Unix-based systems

## Build Instructions
The project utilizes a custom Makefile.

### Manual Build
To generate the binary without immediate execution:
```bash
make
```

### Cleanup
To remove object files and binary:
```bash
make clean
```