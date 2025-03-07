# Simple Shell

## Description
This project is a simple UNIX shell implementation built in C. It provides an interactive command-line interface where users can execute commands, including built-in shell commands and external programs.

## Features
- Execute built-in shell commands (e.g., `cd`, `exit`, `env`)
- Execute external commands using `fork`, `exec`, and `wait`
- Handle command-line arguments
- Implement a basic command-line parser
- Support for interactive and non-interactive modes

## Installation
To compile and run the shell:

```sh
git clone https://github.com/Mercy105/simple_shell.git
cd simple_shell
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

## Usage
To start the shell, compile and run the program:

```sh
./hsh


