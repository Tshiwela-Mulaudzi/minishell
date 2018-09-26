/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   needed2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmulaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 08:33:44 by tmulaud           #+#    #+#             */
/*   Updated: 2018/09/26 09:51:26 by tmulaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_init_vars(t_vars *t_v)
{
	char		*temp;

	if (t_v->line != NULL)
		ft_strdel(&t_v->line);
	if (t_v->args != NULL)
		ft_arrdel(t_v->args);
	if (t_v->path != NULL)
		ft_strdel(&t_v->path);
	if (t_v->paths != NULL && *t_v->paths != NULL)
		ft_arrdel(t_v->paths);
	t_v->home = ft_envseek(t_v, "HOME");
	t_v->pwd = ft_envseek(t_v, "PWD");
	temp = ft_envseek(t_v, "PATH");
	if (temp)
		t_v->paths = ft_strsplit(temp, ':');
	else
		t_v->paths = NULL;
	if (getcwd(t_v->cwd, sizeof(t_v->cwd)) == NULL)
		t_v->e = 1;
	t_v->args_len = 0;
	t_v->line = NULL;
}

int				ft_argcount(char *str, int i, int counter)
{
	while (i < (int)ft_strlen(str) && str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '"')
			i++;
		else
		{
			counter++;
			if (i > 0 && str[i - 1] == '"' && i != (int)ft_strlen(str))
			{
				while (str[i] && str[i] != '"')
					i++;
			}
			else
			{
				while (str[i] && str[i] != ' ' && str[i] != '\t')
					i++;
			}
		}
	}
	return (counter);
}

void			ft_shsplit(t_vars *t_v, int i, int j, int k)
{
	t_v->args_len = ft_argcount(t_v->line, 0, 0);
	t_v->args = (char**)ft_memalloc(sizeof(char *) * (t_v->args_len + 1));
	if (!t_v->args)
		t_v->e = 2;
	while (t_v->e == 0 && ++j < t_v->args_len && t_v->line[i])
	{
		k = 0;
		while ((t_v->line[i] == ' ' || t_v->line[i] == '\t'
			|| t_v->line[i] == '"') && t_v->line[i])
			i++;
		if (i > 0 && t_v->line[i - 1] == '"')
		{
			while (t_v->line[i + k] != '"' && t_v->line[i + k])
				k++;
		}
		else
		{
			while ((t_v->line[i + k] != ' ' && t_v->line[i + k] != '\t')
				&& t_v->line[i + k])
				k++;
		}
		t_v->args[j] = ft_strsub(t_v->line, i, k);
		i += k;
	}
	t_v->args[j] = NULL;
}

