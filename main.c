/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmulaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:53:33 by tmulaud           #+#    #+#             */
/*   Updated: 2018/09/26 10:26:24 by tmulaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_builtin(t_vars *t_v, int i)
{
	t_v->e = -1;
	if (i == 0)
		ft_echo(t_v);
	else if (i == 1)
		ft_export(t_v);
	else if (i == 2)
		ft_unsetenv(t_v);
	else if (i == 3)
	{
		ft_cd(t_v);
		ft_bzero((void *)t_v->cwd, sizeof(t_v->cwd));
		getcwd(t_v->cwd, sizeof(t_v->cwd));
		t_v->var = "PWD";
		t_v->val = t_v->cwd;
		ft_setenv(t_v, -1, 0, -1);
	}
	else if (i == 4)
		ft_env(t_v);
	else if (i == 5)
		t_v->e = 9;
}


int				main(void)
{
	extern char	**environ;
	t_vars		t_v;

	t_v.e = -1;
	t_v.line = NULL;
	t_v.args = NULL;
	t_v.path = NULL;
	t_v.paths = NULL;
	t_v.env_len = ft_arrlen(environ);
	t_v.env = (char **)ft_memalloc(sizeof(char *) * (t_v.env_len + 1));
	while (++t_v.e < t_v.env_len)
		t_v.env[t_v.e] = ft_strdup(environ[t_v.e]);
	t_v.env[t_v.e] = NULL;
	t_v.e = 0;
	ft_shlvl(&t_v);
	while (1)
	{
		ft_init_vars(&t_v);
		if (t_v.e != 0)
			ft_errexit(&t_v);
		ft_putstr("$>");
		get_next_line(STDIN, &t_v.line);
		ft_check_line(&t_v);
	}
	return (0);
}
