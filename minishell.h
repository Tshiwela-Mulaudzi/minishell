/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmulaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:43:00 by tmulaud           #+#    #+#             */
/*   Updated: 2018/09/26 10:20:24 by tmulaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#define STDIN 0
# define EXIT_STATUS
# define BUFF_SIZE 100

# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# include <sys/wait.h>
# include <sys/stat.h>
#include <sys/types.h>
# include <fcntl.h>
#include <dirent.h>
#include <stdlib.h>

typedef struct	s_vars
{
	int			args_len;
	int			env_len;
	int			e;
	int			len;
	char		*line;
	char		*path;
	char		*home;
	char		*pwd;
	char		*temp;
	char		*newlvl;
	char		*both;
	char		*var;
	char		*val;
	char		**e_args;
	char		**temp1;
	char		**temp2;
	char		**args;
	char		**paths;
	char		cwd[512];
	char		**env;
}				t_vars;

typedef struct	s_ints
{
	int			i;
	int			j;
	int			l;
	int			m;
	int			len;
}				t_ints;



void			ft_init_vars(t_vars *t_v);
void			ft_check_args(t_vars *t_v, int i, const char **in);
void			ft_extern(t_vars *t_v);
void			ft_check_line(t_vars *t_v);
void			ft_errexit(t_vars *t_v);
void			ft_shlvl(t_vars *t_v);
void			ft_shsplit(t_vars *t_v, int i, int j, int k);
int				ft_argcount(char *str, int i, int counter);
int				ft_chrpos(char *str, char c);
void			ft_export(t_vars *t_v);
void			ft_setenv(t_vars *t_v, int j, int m, int l);
void			ft_env(t_vars *t_v);
void			ft_builtin(t_vars *t_v, int i);
void			ft_echo(t_vars *t_v);
void			ft_cd(t_vars *t_v);
char			*ft_envseek(t_vars *t_v, char *arg);
void			ft_unsetenv(t_vars *t_v);
int				ft_arrlen(char **arr);
void			ft_arrdel(char **arr);
int				ft_chrpos(char *str, char c);



#endif
