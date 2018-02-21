/*
** EPITECH PROJECT, 2018
** path.c
** File description:
** pathing for the minishell1
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

char*	pathing(char **envp, int *ct, int ctb)
{
	char *str;
	int ctp = *ct;
	int len = 0;

	while (envp[ctb][ctp] != ':'
	&& envp[ctb][ctp] != '\0') {
		len ++;
		ctp ++;
	}
	ctp = 0;
	str = malloc(sizeof(char) * (len + 2));
	while (envp[ctb][*ct] != ':'
	&& envp[ctb][*ct] != '\0') {
		str[ctp] = envp[ctb][*ct];
		(*ct) ++;
		ctp ++;
	}
	str[ctp] = '/';
	str[ctp + 1] = '\0';
	return (str);
}

int	check_path_bsc(char **envp, char *name, char **str_arr)
{
	int ct = 0;
	char *str;

	while (envp[0][ct] != '=')
		ct ++;
	ct ++;
	while (envp[0][ct] != '\0') {
		str = my_strcat(pathing(envp, &ct, 0), name, 0);
		if (envp[0][ct] == '\0')
			ct --;
		if (access(str, F_OK) != -1) {
			strat_exec(str, envp, str_arr);
			return (0);
		}
		ct ++;
	}
	my_printf("%s: Command not found.\n", str_arr[0]);
	return (0);
}

int	check_same(char **envp, env_st_t* env_st)
{
	int ct = 0;

	while (envp[env_st->ind][ct] != '=')
		ct ++;
	ct ++;
	return (ct + 1);
}

int	check_path_env(char **envp, char *name,
		env_st_t* env_st, char **str_arr)
{
	int ct = 0;
	char *str;

	if (check_val(envp, "PATH", env_st) == 0) {
		check_path_bsc(env_st->envp_bsc, name, str_arr);
		return (0);
	}
	ct = check_same(envp, env_st);
	while (envp[env_st->ind][ct] != '\0') {
		str = my_strcat(pathing(envp, &ct, env_st->ind), name, 0);
		if (envp[env_st->ind][ct] == '\0')
			ct --;
		if (access(str, F_OK) != -1) {
			strat_exec(str, envp,  str_arr);
			return (0);
		}
		ct ++;
	}
	my_printf("%s: Command not found.\n", str_arr[0]);
	return (0);
}
