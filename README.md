simple shell
a project handled by maurice and manal
its basically creating our own working shell
understand the concepts and pattern 
wasnt easy but was fun ....go through work for details.
Allowed editors: vi, vim, emacs
All your files will be compiled on Ubuntu 14.04 LTS
Your programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
All your files should end with a new line
A README.md file, at the root of the folder of the project is mandatory
Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
Your shell should not have any memory leaks
No more than 5 functions per file
All your header files should be include guarded
This program displays a prompt and waits that the user types a command. A command line always ends with a new line (when user push ENTER key).
The prompt is displayed again each time a command has been executed.
When the user enters exit, Hell shell will end and returns the status 0.
When the user enters exit [status], Hell Shell will end and returns the inputted status, where status is a value from 0 to 255.
The user could stop the program using Ctrl+D (end of file).
The shell handles the command lines with arguments and pathways.
The program does not quit when the user imputs ^C (Ctrl+C).
The program prints the current enviroment when the user types env.
This program executes the most common shell commands as ls, grep, find, pwd, rm, cp, mv, exit, env, history, etc... with arguments.
If an executable cannot be found, It prints an error message and displays the prompt again.
This Shell supports commentaries using #,
The Hell Shell does NOT support wildcard characters such as ls *.dat in parameters (or commands).
This shell does NOT support pipes |, shell logical operators as && or ||, neither commands separator ;.
