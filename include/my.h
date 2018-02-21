/*
** EPITECH PROJECT, 2017
** header
** File description:
** my.h
*/

#include<stdarg.h>

#ifndef MY_H

#define MY_H

typedef struct env_st
{
	int len_w;
	int len_h;
	int unset;
	int ind;
	int cd_abl;
	char **envp_cpy;
	char **envp_bsc;
}env_st_t;

typedef struct name_env
{
	char *name;
	int (*name_str)(char **str, char **envp, env_st_t *env_st);
}name_env_t;

typedef struct spec
{
	char spec_pf;
	int (*spec_p)(va_list ap, int ct, char *str, char *str_temp);
}spec_t;

typedef struct length
{
	char *sep_pf;
	int (*sep_p)(va_list ap, int ct, char *str, char *str_temp);
}length_t;

typedef struct flag
{
	char flag_pf;
	int (*flag_p)(char *str, int ctp, long long temp, char *str_temp);
}flag_t;

typedef struct flag_char
{
	char flag_c_pf;
	int (*flag_c_p)(char *str, int ctp, char *temp, char *str_temp);
}flag_char_t;

char	*maloc_str(int ct, int b, int ctb, char **str);
int	check_path_env(char **envp, char *name, env_st_t* env_st, char **str_arr);
int	check_path_bsc(char **envp, char *name, char **str_arr);
int	strat_exec(char *name, char **envp, char **str);
char*	pathing(char **envp, int *ct, int ctb);
int	error_oldpwd(char **str, int cd_min, env_st_t *env_st);
char **create_env(void);
int	check_name(char **str);
int	set_name_value(char **str, char **envp, env_st_t* env_st);
int	set_name(char **str, char **envp, env_st_t* env_st);
char	**unset_env_name(char **str, char **envp, env_st_t* env_st);
int	check_env(char *envp, char *name);
int	error_set_env(char **str, env_st_t* env_st);
int	strat_set_env(char **str, char **envp, env_st_t* env_st, int b);
int	set_env(char **str, char **envp, env_st_t* env_st);
int	env(char **str, char **envp, env_st_t *env_st);
char	**copy_env(char **envp, env_st_t* env_st, int ct);
int	delet_val(char *str, char **envp, env_st_t* env_st);
int	change_env(char *pwd, char *oldpwd, int b, env_st_t *env_st);
char	*my_getcwd(char *str, int ctb);
char	*get_path(char **envp, env_st_t *env_st, int ct);
int	cd_pwd(char **str, env_st_t *env_st);
int	cd_home(char **str, char **envp, env_st_t *env_st, int cd_min);
int	cd_oldpwd(char **str, char **envp, env_st_t *env_st, int cd_min);
int	exec(char **envp, env_st_t* env_st, char **str);
int	set_env(char **str, char **envp, env_st_t* env_st);
int	unset_env(char **str, char **envp, env_st_t* env_st);
int	exit_env(char **str, char **envp, env_st_t *env_st);
int	env(char **str, char **envp, env_st_t *env_st);
int	cd(char **str, char **envp, env_st_t *env_st);
env_st_t	*fill_struct(char **envp);
char	**word_array(char *line);
int	epur_str(char *str);
char	*copy_str_arr(char *line, int *ct);
int	check_val(char **envp, char *name, env_st_t* env_st);
int	check_env(char *envp, char *name);
int	my_putchar(char c);
int	my_put_nbr(int nb);
int	my_putstr(char *str, int len);
char	*my_revstr(char *str);
char	*my_strcat(char *dest, char *src, int b);
int	my_strcmp(char *s1, char *s2);
char	*my_strdup(char *src);
int	my_strlen(char *str);
char	*my_strncat(char *dest, char *src, int n);
int	my_strncmp(char *s1, char *s2, int n);
char	*my_strcpy(char *dest, char const *src);
char	*my_strncpy(char *dest, char *src, int n);
void	my_swap(int *a, int *b);
char	*swap_output(char *base, int nb);
long long	my_put_long_long(long long nb);
void	my_put_unsg_ll(unsigned long long nb);
int	my_long_long_len(long long nb);
int	flag_x(va_list ap, int ct, char *str, char *str_temp);
int	flag_xx(va_list ap, int ct, char *str, char *str_temp);
int	flag_o(va_list ap, int ct, char *str, char *str_temp);
int	flag_long(va_list ap, int ct, char *str, char *str_temp);
int	flag_h_nbr(va_list ap, int ct, char *str, char *str_temp);
int	flag_long_long(va_list ap, int ct, char *str, char *str_temp);
int	flag_unsg_short(va_list ap, int ct, char *str, char *str_temp);
int	flag_unsg_l(va_list ap, int ct, char *str, char *str_temp);
int	flag_unsg_ll(va_list ap, int ct, char *str, char *str_temp);
int	flag_p(va_list ap, int ct, char *str, char *str_temp);
int	flag_s(va_list ap, int ct, char *str, char *str_temp);
int	flag_c(va_list ap, int ct, char *str, char *str_temp);
int	flag_b(va_list ap, int ct, char *str, char *str_temp);
int	flag_ll_x(va_list ap, int ct, char *str, char *str_temp);
int	flag_ll_xx(va_list ap, int ct, char *str, char *str_temp);
int	flag_ll_o(va_list ap, int ct, char *str, char *str_temp);
int	flag_ll_b(va_list ap, int ct, char *str, char *str_temp);
int	flag_plus(char *str_temp, long long rst, int b, int nbr);
int	flag_plus_bis(char *str_temp, long long rst, int b);
int	nbr_disp(int temp_len, char *str_temp, int nbr, int b);
int	nbr_disp_bis(int temp_len, char *str_temp, int nbr_f, int b);
int	nbr_disp_bis(int temp_len, char *str_temp, int nbr_f, int b);
int	nbr_disp_thd(long long rst);
void	base(unsigned long long nbr, char *str);
void	separator_flag(char *str, va_list ap, int ct, char *str_temp);
void	flag_one(char *str, va_list ap, int ct, char *str_temp);
int	choise_flag(char *str, int ct, int b);
char	*copy_flag(char *str, char *temp, int ct);
char	*copy_str(char *str, char *str_temp, int ct);
void	my_printf(char *str, ...);
int	len_flag(char *str, int ct);
void	flag_sign(long long rst);
int	flag_flag(char *str, int ct);
int	choise_flag_flag(char *str, int ctp, long long temp, char *str_temp);
int	choise_flg_flg_c(char *str, int ctp, char* temp, char *str_temp);
void	flag_nbr_disp(int nbr, int len_f);
int	flag_nbr(char *str, char *str_temp, int ctp, int temp);
void	flag_zero_disp(int nbr, int len_f);
int	flag_long_long_d(va_list ap, int ct, char *str, char *str_temp);
int	flag_hh_x(va_list ap, int ct, char *str, char *str_temp);
int	flag_hh_xx(va_list ap, int ct, char *str, char *str_temp);
int	flag_hh_o(va_list ap, int ct, char *str, char *str_temp);
int	flag_hh_b(va_list ap, int ct, char *str, char *str_temp);
int	flag_hh_u(va_list ap, int ct, char *str, char *str_temp);
int	flag_ss(va_list ap, int ct, char *str, char *str_temp);
int	flag_hh_d(va_list ap, int ct, char *str, char *str_temp);
void	flag_has_o(char *str_temp);
void	flag_has_x(char *str_temp);
void	flag_has_xx(char *str_temp);

#endif
