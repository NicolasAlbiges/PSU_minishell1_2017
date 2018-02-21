/*
** EPITECH PROJECT, 2018
** exec.c
** File description:
** the exec of the minishel1
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "gnl.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>
#include <sys/wait.h>

void	status(int w)
{
	if (WIFSIGNALED(w)) {
		my_printf("Segmentation fault");
		if (WCOREDUMP(w))
			my_printf(" (core dumped)");
		my_printf("\n");
	}
}

int	strat_exec(char *name, char **envp, char **str)
{
	int w;
	int val;

	if ((val = fork()) == -1)
		return (0);
	if (val == 0) {
		if (execve(name, str, envp) == -1)
			return (0);
		exit(0);
	} else
		wait(&w);
	status(w);
	return (0);
}

int	exec(char **envp, env_st_t* env_st, char **str)
{
	int ct = 0;
	int b = 0;

	while (str[0][ct] != '\0') {
		if (str[0][ct] == '/')
			b = 1;
		ct ++;
	}
	if (b == 1) {
		if (access(str[0], F_OK) != -1) {
			strat_exec(str[0], envp, str);
			return (0);
		}
		my_printf("%s: Command not found.\n", str[0]);
	} else {
		check_path_env(envp, str[0], env_st, str);
	}
	return (0);
}
