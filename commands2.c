/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmulaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 15:53:22 by tmulaud           #+#    #+#             */
/*   Updated: 2018/09/26 09:45:15 by tmulaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_env(t_vars *t_v)
{
	t_ints	k;

	k.i = 0;
	k.j = -1;
	k.m = -1;
	k.len = -1;
	k.l = -1;
	if (t_v->args_len == 1)
	{
		while (t_v->env[++k.l] != NULL)
			ft_putendl(t_v->env[k.l]);
	}
}

void		ft_unsetenv(t_vars *t_v)
{
	t_ints	k;

	k.i = 0;
	while (++k.i < t_v->args_len)
	{
		k.j = -1;
		k.l = -1;
		k.len = ft_strlen(t_v->args[k.i]);
		if (ft_envseek(t_v, t_v->args[k.i]) != NULL)
		{
			t_v->temp2 = (char **)ft_memalloc(sizeof(char *) * (t_v->env_len));
			while (++k.l < t_v->env_len)
			{
				if (ft_strncmp(t_v->args[k.i], t_v->env[k.l], k.len) == 0
					&& t_v->env[k.l][k.len] == '=')
					continue;
				else
					t_v->temp2[++k.j] = ft_strdup(t_v->env[k.l]);
			}
			t_v->temp2[++k.j] = NULL;
			ft_arrdel(t_v->env);
			t_v->env = t_v->temp2;
			t_v->env_len--;
		}
	}
}

void		ft_setenv(t_vars *t_v, int j, int m, int l)
{
	t_v->len = ft_strlen(t_v->var);
	t_v->temp = ft_strjoin(t_v->var, "=");
	t_v->both = ft_strjoin(t_v->temp, t_v->val);
	while (t_v->env[++j] != NULL && m != 1)
	{
		if (ft_strncmp(t_v->var, t_v->env[j], t_v->len) == 0
			&& t_v->env[j][t_v->len] == '=')
		{
			ft_strdel(&t_v->env[j]);
			t_v->env[j] = t_v->both;
			m = 1;
		}
	}
	if (m != 1)
	{
		t_v->temp2 = (char **)ft_memalloc(sizeof(char *) * (t_v->env_len + 2));
		while (++l < t_v->env_len)
			t_v->temp2[l] = ft_strdup(t_v->env[l]);
		t_v->temp2[l] = t_v->both;
		t_v->temp2[++l] = NULL;
		ft_arrdel(t_v->env);
		t_v->env = t_v->temp2;
		t_v->env_len++;
	}
	ft_strdel(&t_v->temp);
}
