#ifndef HELPERS_H
#define HELPERS_H


/* prompt to be printed */
#define PROMPT_MSG "Maury&Manal# " /* Needed to work with signal */

/* Resume from the unused attibute */
#define UNUSED __attribute__((unused))

/* buffer size for each read call in _getline */
#define BUFFER_SIZE 1024

/************** FORMATTED STRING FOR HELP BUILT IN **************/


#define HELP_CD_MSG "cd=\n"\
"cd:\tcd [dir]\n\n"\
"       change the shell working directory. \n\n"\
"       If no argument given to cd the command will be interpreted\n"\
"       as cd $HOME.\n"\
"       if the argumenthelp is - (cd -), the command will be interpreted\n"\
"       as cd $OLDPWD. \n\n"


#define HELP_EXIT_MSG "exit=\n"\
"exit:\textit [STATUS]\n\n"\
"      Exit of the simple-shell.\n\n"\
"      Exits the shell with a status of N. If N is omitted, the exit status\n"\
"      is that of the last command executed.\n\n"



#define HELP_ENV_MSG "env=\n"\
"env:\tenv \n\n"\
"	print enviroment.\n\n"\
"	The env command will be print a complete list of enviroment variables.\n\n"


#define HELP_SETENV_MSG "setenv=\n"\
"setenv:\tsetenv VARIABLE VALUE\n\n"\
"      change or add an enviroment variable.\n\n"\
"      initialize a new enviroment variable, or modify an existing one\n"\
"      when there are not correct numbers of arguments print error message.\n\n"


#define  HELP_UNSETENV_MSG "unsetenv=\n"\
"unsetenv:\tunsetenv VARIABLE\n\n"\
"      The unsetenv function deletes one variable from the enviroment.\n\n"\
"      when there are not correct numbers of arguments prints error message.\n\n"

#define HELP_MSG "help=\n"\
"help:\thelp [BUILTIN_NAME]\n\n"\
"	Display information about built_inn commands.\n\n"\
"	Display brief summaries of built_inn commands.  IF BUILTIN_NAME is\n"\
"	specified, gives detailed help on all commands matching BUILTIN_NAME,\n"\
"	otherwise the list  of help topics is printed BUILTIN_NAME list.\n"\
"	Arguments:\n\n"\
"	BUILTIN_NAME specifying a help topic.\n\n"\
"	cd\t[dir]\n"\
"	exit\t[status]\n"\
"	env\n"\
"	setenv\t[variable value]\n"\
"	unset\t[variable]\n"\
"	help\t[built_name]\n\n"


#endif
