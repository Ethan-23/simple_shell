# Simple_shell

## Description
Super simple version of shell meant to handle simple commands and built in commands env and exit. The shell also can search through the PATH to find executables.

## Usage
You can compile our shell with:
gcc -Wall -Werror -Wextra -pedantic *.c -o shell

### Once compiled you can use the command below to get into the shell
* ./shell - brings you into our very simple version of a shell where certain commands can be handled. 
### Once inside the shell here are some of the built-in commands you can run
* exit - Exits from the shell
* env - Shows the enviroment of the shell

### Modes
There is interacive mode which pipes commands into our shell (EX. echo "env" | ./hsh)
There is also non interactive mode which just runs commands in our shell (EX. $ env)

**Created By:**
Ethan Roberts and Manny Figueroa