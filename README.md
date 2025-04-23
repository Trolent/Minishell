# Minishell - Your Own Little Bash

Welcome to my Minishell project! This project is part of the curriculum at 42 School and consists in developing a simplified Unix shell. The goal is to recreate the behavior of Bash in its most essential features, while gaining deep understanding of processes, redirections, file descriptors, and shell grammar.

## Objectives

The main objectives of this project are to:

- Understand and implement **Unix process management** using `fork`, `execve`, `wait`, `pipe`, etc.
- Manage **file descriptors and redirections** (`<`, `>`, `>>`, `<<`).
- Create a **tokenizer and parser** to process command-line input (quotes, variables, etc.).
- Handle **signals** and interactive user input with behavior similar to Bash.
- Implement **built-in shell commands** with correct behavior.
- Bonus: Add support for **logical operators**, **wildcards**, and **grouped commands**.

## Features

- **Prompt display**: Shows a custom prompt when waiting for user input.
- **Command execution**: Supports absolute/relative paths and PATH search.
- **Redirections**: Handles `>`, `>>`, `<`, and heredoc `<<` with delimiter.
- **Pipes**: Executes commands in a pipeline (`cmd1 | cmd2 | cmd3`).
- **Environment variables**: Expands `$VAR`, `$?`, and supports `export`, `unset`, etc.
- **Quotes management**: `'` and `"` handled per Bash rules.
- **Signal handling**: `ctrl-C`, `ctrl-D`, `ctrl-\` behave correctly in interactive mode.
- **Built-in commands**: Includes all required shell built-ins.
- **Abstract Syntax Tree**: Internal command structure built using a full AST.
- **Bonus logic**: Handles `&&`, `||`, parentheses, wildcards `*`, and grouped execution.

## Usage

### Compilation

To compile the project, use the following commands:

```bash
make        # Compiles the minishell executable
make clean  # Deletes the compiled object files
make fclean # Deletes the object files and the executable
make re     # Fully recompiles the project

## Executing Minishell

To start the shell, simply run:

```bash
./minishell```

Once running, you can use it like a basic Bash shell:

```bash
minishell$ echo Hello World
Hello World

minishell$ export VAR=42
minishell$ echo $VAR
42

minishell$ ls -l | grep minishell > result.txt
minishell$ cat << EOF
> This is a line
> Another one
> EOF
```

If the command is invalid or the syntax is incorrect, the shell will display an Error message and return to the prompt without crashing.

## Minishell Built-ins

The following built-in commands are implemented:

| Command             | Description                             |
|---------------------|-----------------------------------------|
| `echo [-n]`         | Prints arguments to stdout              |
| `cd [path]`         | Changes current directory               |
| `pwd`               | Prints the current directory            |
| `export VAR=value`  | Sets an environment variable            |
| `unset VAR`         | Removes an environment variable         |
| `env`               | Displays current environment variables  |
| `exit [code]`       | Exits the shell with an optional status |

These built-ins are handled internally by the shell, without calling external binaries. Each one mimics Bash behavior as closely as possible within the scope of the project.

## Minishell Bonus Features

When compiled using `make bonus`, the shell includes the following advanced features:

| Feature             | Description                                                                 |
|---------------------|-----------------------------------------------------------------------------|
| `&&` / `||`         | Executes commands conditionally based on previous success/failure           |
| Parentheses         | Groups commands to define execution priority: `(cmd1 && cmd2) || cmd3`      |
| Wildcard `*`        | Expands to files in current working directory (e.g., `ls *.c`)               |
| Heredoc `<<`        | Reads input until a defined delimiter is encountered (e.g., `cat << EOF`)   |

These features are fully integrated with the parsing logic and are executed via an Abstract Syntax Tree, making the shell robust and scalable.

## Keyboard Shortcuts and Behavior

Minishell supports interactive keyboard input with behaviors matching Bash:

| Key        | Behavior                                                  |
|------------|-----------------------------------------------------------|
| `ctrl-C`   | Interrupts the current command and displays a new prompt  |
| `ctrl-D`   | Exits the shell if the line is empty (EOF)                |
| `ctrl-\`   | Ignored (no output, no quit signal)                       |

The prompt is redrawn cleanly after interrupts, and no core dump occurs when pressing `ctrl-\`.

## Screenshot

A simple example with pipe, logical operator and command groups.

![Minishell Screenshot](https://github.com/Trolent/Minishell/blob/main/image/Capture%20d%E2%80%99%C3%A9cran%202025-04-12%20%C3%A0%2010.00.10.png)


## Educational Value

This project provided a deep dive into:

- **Unix system programming**:
  - Processes: `fork`, `execve`, `wait`, `waitpid`
  - Signals: `sigaction`, `kill`, `SIGINT`, `SIGQUIT`
  - File descriptors: `pipe`, `dup`, `dup2`, `open`, `close`

- **Shell grammar parsing**:
  - Tokenizer for operators, quotes, variables
  - Abstract Syntax Tree for logical operator priority
  - Syntax validation for redirections and pipelines

- **Memory management**:
  - Strict adherence to freeing all heap memory
  - No leaks tolerated (except from `readline`, per subject)

- **Modularity & architecture**:
  - Clear separation of concerns (lexer, parser, executor)
  - Use of custom `libft`
  - Scalable AST-based command execution model

---

Thank you for taking the time to explore this project! I hope it serves as a useful and inspiring example for learning how shells work at a low level. 🐚✨

Project made with the help of my teammate [AK Dovlet](https://github.com/akdovlet)


