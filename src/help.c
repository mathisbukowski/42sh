/*
** EPITECH PROJECT, 2024
** B-PSU-200-LIL-2-1-42sh-mathis.bukowski
** File description:
** help.c
*/

#include "minishell.h"
#include <stdio.h>

void display_help_usage(void)
{
    printf("42sh, a simple shell implementation\n");
    printf("Usage:\n");
    printf("  ./42sh -h, --help    display this help and exit\n");
    printf("  ./42sh\t\tstart the shell\n");
}

void display_help_first(void)
{
    printf("42sh, a simple shell implementation\n");
    printf("Options:\n");
    printf("  help\tdisplay this help and exit\n");
    printf("Commands:\n");
    printf("  cd [DIRECTORY]  change the current directory to DIRECTORY\n");
    printf("  cd -\t\t  change the current directory to the previous "
    "one\n");
    printf("  cd ~\t\t  change the current directory to the home director"
    "y\n");
    printf("  exit\t\t  exit the shell\n");
    printf("  ls  \t\t  list directory contents\n");
    printf("  pwd \t\t  print name of current/working directory\n");
    printf("  env \t\t  display the current environment\n");
    printf("  setenv [VAR] [VALUE]  set the environment variable VAR to "
    "VALUE\n");
    printf("  unsetenv [VAR]  remove the environment variable VAR\n");
    printf("  echo [STRING]   print STRING to the terminal\n");
    printf("  alias [NAME] [COMMAND]  create an alias for COMMAND\n");
}

void display_help_second(void)
{
    printf("  unalias [NAME]  remove the alias NAME\n");
    printf("  history \t  display the command history\n");
    printf("  fg  \t\t  continue a stopped job by bringing it to the for"
    "eground\n");
    printf("  bg [JOB_ID]\t  continue a stopped job by sending it to the back"
    "ground\n");
}

int command_help(info_t *info)
{
    display_help_first();
    display_help_second();
    return 0;
}
