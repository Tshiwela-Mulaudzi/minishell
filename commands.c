/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmulaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 14:10:13 by tmulaud           #+#    #+#             */
/*   Updated: 2018/09/26 10:25:44 by tmulaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(t_vars *t_v)
{
	t_ints		k;
	char		*temp;

	k.i = 0;
	k.j = -1;
	if (t_v->args_len > 1)
	{
		while (++k.i < t_v->args_len)
		{
			if (t_v->args[k.i][0] == '$')
				temp = ft_envseek(t_v, t_v->args[k.i]);
			else
				temp = t_v->args[k.i];
			ft_putstr(temp);
			if (k.i != t_v->args_len)
				write(1, " ", 1);
		}
	}
	write(1, "\n", 1);
}

void	ft_cd(t_vars *t_v)
{
	if (t_v->args_len == 1)
		t_v->path = ft_strdup(t_v->home);
	else if (t_v->args_len > 1)
	{
		if (t_v->args[1][0] == '~')
		{
			t_v->newlvl = t_v->args[1];
			t_v->path = ft_strjoin(t_v->home, ++t_v->newlvl);
			t_v->newlvl--;
		}
		else if (ft_strcmp(t_v->args[1], "-") == 0)
			t_v->path = ft_strdup(ft_envseek(t_v, "OLDPWD"));
		else
			t_v->path = ft_strdup(t_v->args[1]);
	}
	t_v->len = chdir(t_v->path);
	if (t_v->len == 0)
	{
		t_v->var = "OLDPWD";
		t_v->val = t_v->cwd;
		ft_setenv(t_v, -1, 0, -1);
	}
	else
		ft_putendl("Error: chdir Failed");
}

void			ft_errexit(t_vars *t_v)
{
	ft_arrdel(t_v->env);
	if (t_v->paths != NULL)
		ft_arrdel(t_v->paths);
	if (t_v->e == 1)
		write(1, "Error: cannot get current working directory", 43);
	if (t_v->e == 2)
		write(1, "Error: cannot malloc", 20);
	if (t_v->e == 9)
	{
		ft_putendl("Exiting");
		exit(EXIT_SUCCESS);
	}
}



