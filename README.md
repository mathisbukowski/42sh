
# 42sh Project -- Epitech First Year

## Introduction
Welcome to the 42sh project at Epitech. This project involves creating an implementation of a shell in C (looks like [TCSH](https://www.tcsh.org/)), following the specific programming standards of Epitech. This README provides all the necessary instructions for compiling, running and understanding the project.


## Prerequisites
To compile and run this project, you will need the following:

- A Unix-like operating system (Linux, macOS)
- GCC (GNU Compiler Collection) for compiling C code
- GNU Make for automating the compilation process

## File Structure

Here is a structure of the project : 

```txt
├── include                     # Header files (.h)
├── lib                         # Library of functions
├── Makefile                    # Makefile to compile the project
├── src                         # Source files and subdirectories for the project
│   ├── main.c                  # Main program entry point
│   ├── main_shell.c            # Core shell functionalities
│   ├── pipes.c                 # Handling of pipes
│   ├── redirections.c          # Management of redirections
│   ├── signals.c               # Signal handling
│   ├── utils                   # Utility functions
│   ├── renderer                # Input renderer
│   ├── local_variables         # Local variables manager
│   ├── job_manager             # Job control manager
│   ├── input_manager           # Input handling
│   ├── historical              # History management
│   ├── globbings.c             # Globbing functionalities
│   ├── commands                # Shell built-in commands
│   ├── command_runner.c        # Command execution
│   ├── builtin_command_list.c  # Table of built-in functions
│   └── aliases                 # Aliases management
├── tests                       # Unit tests
└── tmp                         # Temporary files for history and double left redirection

```
## Compilation

To compile the project, use the make command at the root of the project folder. This will compile all the necessary files and create an executable named 42sh.

```bash
make
```

To clean up the object files and dependencies generated during compilation, you can use:
```bash
make clean
```

To remove everything that has been built (including the executable), use:
```bash
make fclean
```

To recompile all the project:
```bash
make re
```

To compile the documentation (Prerequisites: You must have [Doxygen](https://www.doxygen.nl/) and the [Doxyfile](https://github.com/EpitechPromo2028/B-PSU-200-LIL-2-1-42sh-mathis.bukowski/blob/main/Doxyfile) :
```bash
make documentation
```
## Features


The 42sh shell supports a wide range of features, designed to provide a robust and flexible user experience:

- Aliases: Ability to create, use, and manage aliases within the shell, improving command line efficiency.
- Process Management: Support for background processes using the ampersand (`&`) syntax, allowing tasks to run concurrently.
- Line Editing: Enhanced line editing capabilities, which include intuitive navigation and editing of the command line.
- History: Command history management that allows users to recall and edit previous commands easily.
- Pipes: Use of pipes (`|`) to direct the output of one command as input to another, facilitating complex workflows.
- Redirections: Comprehensive input and output redirections (`>`, `<`, `>>`, `<<`), enabling fine control over data flow in command execution.
- Built-in Commands:
    - `cd`: Change the current directory.
    - `set` and `unset`: Set or unset shell variables.
    - `setenv` and `unsetenv`: Set or unset environment variables.
    - `alias` and `unalias`: Manage aliases, allowing users to define and remove command shortcuts.
    - `searchalias`: Search and display information about defined aliases.
    - `env`: Display the current environment variables or run a command in a modified environment.
- Logical Operators: Support for logical conjunction (`&&`) and disjunction (`||`), enabling conditional execution of commands based on the success or failure of previous commands.
- Globbings: Pattern matching capabilities that allow users to specify groups of filenames with wildcard characters.
## Usage

After compilation, you can start the shell by running the executable:

```bash
./42sh
```

Once the shell is launched, you can enter Unix shell commands and more other tests for seeing all the functionnalities.

You can do this for having help :
```bash
./42sh --help
```

And execute help command directly in the shell.

## Authors

The 42sh project was developed by a dedicated team of students at Epitech. Below are the contributors who played a key role in its creation and ongoing development:

- Alexandre Detoeuf - Developer. Contact: alexandre.detoeuf@epitech.eu
- Mathis Bukowski - Developer. Contact: mathis.bukowski@epitech.eu
- Maxime Bertin - Developer. Contact: maxime.bertin@epitech.eu
- Rafael Drouart - Developer. Contact: rafael.drouart@epitech.eu
- Raphaël Richaud - Developer. Contact: raphael.richaud@epitech.eu

For any queries regarding the project, please feel free to reach out to any of the authors via their provided contact information.

