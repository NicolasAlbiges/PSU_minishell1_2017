/*
** EPITECH PROJECT, 2018
** other.c
** File description:
** other function for the mini shell
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include <fcntl.h>
#include <stdio.h>

env_st_t	*fill_struct(char **envp)
{
	env_st_t* new_node = malloc(sizeof(env_st_t));
	int ctp = 0;

	new_node->len_w = 0;
	new_node->ind = 0;
	new_node->unset = 0;
	new_node->cd_abl = 0;
	new_node->envp_bsc = create_env();
	if (envp[0] == NULL) {
		new_node->envp_cpy = create_env();
		new_node->len_h = 2;
	} else {
		while (envp[ctp] != NULL) {
			ctp ++;
		}
		new_node->len_h = ctp;
		new_node->envp_cpy = copy_env(envp, new_node, 0);
	}
	return (new_node);
}

char	*maloc_str(int ct, int b, int ctb, char **str)
{
	char *str_tmp = malloc(sizeof(char)
				* (my_strlen(str[1]) + my_strlen(str[2])) + 2);

	while (ctb != (my_strlen(str[1]) + my_strlen(str[2]) + 1)) {
		if (b == 0 && str[1][ct] != '\0') {
			str_tmp[ctb] = str[1][ct];
			ct ++;
		}
		if (b == 0 && str[1][ct] == '\0') {
			ctb ++;
			str_tmp[ctb] = '=';
			b = 1;
			ct = 0;
		} else if (b == 1) {
			str_tmp[ctb] = str[2][ct];
			ct ++;
		}
		ctb ++;
	}
	return (str_tmp);
}

char	*copy_str_arr(char *line, int *ct)
{
	int ctp = *ct;
	int len = 0;
	char *str;

	while (line[ctp] != 32 && line[ctp] != 9 && line[ctp] != '\0') {
		len ++;
		ctp ++;
	}
	ctp = 0;
	str = malloc(sizeof(char) * (len + 1));
	while (line[*ct] != 32 && line[*ct] != 9 && line[*ct] != '\0') {
		str[ctp] = line[*ct];
		ctp ++;
		(*ct) ++;
	}
	str[ctp] = '\0';
	len = 0;
	ctp = 0;
	ct --;
	return (str);
}

int	epur_str(char *str)
{
	int ct = 0;
	int len = 0;
	int b = 0;

	while (str[ct] != '\0') {
		if (b == 0 && (str[ct] == 32 || str[ct] == 9)) {
			b = 1;
		}
		if (str[ct] != 32 && str[ct] != 9) {
			len ++;
			b =0;
		}
		ct ++;
	}
	return (len);
}

char	**word_array(char *line)
{
	int len = 0;
	int ct = 0;
	int ctb = 0;
	char **str;

	if ((len = epur_str(line)) == 0)
		return (0);
	str = malloc(sizeof(char *) * (len + 1));
	len = 0;
	while (line[ct] != '\0') {
		if (line[ct] != 32 && line[ct] != 9) {
			str[ctb] = copy_str_arr(line, &ct);
			ctb ++;
		} else
			ct ++;
	}
	str[ctb] = NULL;
	return (str);
}
