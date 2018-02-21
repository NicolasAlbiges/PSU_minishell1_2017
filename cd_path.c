/*
** EPITECH PROJECT, 2018
** cd_path.c
** File description:
** the path for the cd minishell1
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
#include <errno.h>

int	cd_oldpwd(char **str, char **envp, env_st_t *env_st, int cd_min)
{
	char *pwd;
	int ct = 0;
	char *str_wd = NULL;

	if (error_oldpwd(str, cd_min, env_st) == 1)
		return (0);
	while (envp[env_st->ind][ct] != '=')
		ct ++;
	pwd = get_path(envp, env_st, ct + 1);
	str_wd = my_getcwd(NULL, 0);
	if (chdir(pwd) == -1) {
		my_printf(": No such file or directory.\n");
		return (0);
	}
	change_env(NULL, str_wd, 0, env_st);
	change_env(pwd, NULL, 1, env_st);
	return (0);
}

int	change_home(char *home, env_st_t *env_st)
{
	char *str_oldwd;

	str_oldwd = my_getcwd(NULL, 0);
	if (chdir(home) == -1) {
		my_printf("cd: Can't change to home directory.\n");
		return (1);
	}
	env_st->cd_abl = 1;
	change_env(NULL, str_oldwd, 0, env_st);
	change_env(home, NULL, 1, env_st);
	return (1);
}

int	cd_home(char **str, char **envp, env_st_t *env_st, int cd_min)
{
	int ct = 0;
	char *home;

	cd_min = check_val(envp, "HOME", env_st);
	if (str[1] == NULL) {
		if (cd_min == 0) {
			my_printf("%s: No home directory.\n", str[0]);
			return (1);
		}
		while (envp[env_st->ind][ct] != '=')
			ct ++;
		home = get_path(envp, env_st, ct + 1);
		change_home(home, env_st);
		return (1);
	}
	return (0);
}

int	cd_pwd(char **str, env_st_t *env_st)
{
	char *str_wd = NULL;
	char *str_oldwd = NULL;

	str_oldwd = my_getcwd(NULL, 0);
	if (chdir(str[1]) == -1) {
		if (errno == 20) {
			my_printf("%s: Not a directory.\n", str[1]);
			return (0);
		}
		my_printf("%s: No such file or directory.\n", str[1]);
		return (0);
	}
	str_wd = my_getcwd(NULL, 0);
	env_st->cd_abl = 1;
	change_env(NULL, str_oldwd, 0, env_st);
	change_env(str_wd, NULL, 1, env_st);
	return (0);
}
