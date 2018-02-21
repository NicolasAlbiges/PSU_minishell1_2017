/*
** EPITECH PROJECT, 2018
** prompt.c
** File description:
** the prompte function of the minishell1
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

name_env_t const tab_name[] = {{"cd", cd}, {"env", env},
			{"exit", exit_env}, {"setenv", set_env},
			{"unsetenv", unset_env}};

char	*modif_gnl(char *str)
{
	char *str_bis = malloc(sizeof(char) * my_strlen(str));
	int ct = 0;

	while (str[ct] != '\n') {
		str_bis[ct] = str[ct];
		ct ++;
	}
	str_bis[ct] = '\0';
	return (str_bis);
}

void	prompt(void)
{
	if (isatty(0) == 1)
		my_printf("$> ");
}

int	check_gnl(char *name, char **envp, env_st_t *env_st)
{
	int ct = 0;
	char **str;

	str = word_array(name);
	while (ct < 5) {
		if (my_strcmp(str[0], tab_name[ct].name) == 0) {
			(tab_name[ct].name_str)(str, envp, env_st);
			return (0);
		}
		ct ++;
	}
	exec(envp, env_st, str);
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	char *str;
	int end;
	env_st_t *env_st;

	env_st = fill_struct(envp);
	end = 0;
	prompt();
	while (!end) {
		str = get_next_line(0);
		if (isatty(0) == 1 && str == NULL) {
			my_printf("exit\n");
			exit(0);
		}
		if (my_strlen(str) > 0)
			check_gnl(str, env_st->envp_cpy, env_st);
		else if (isatty(0) != 1)
			end = !end;
		prompt();
	}
	return (0);
}
