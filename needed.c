/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   needed.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmulaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 07:45:28 by tmulaud           #+#    #+#             */
/*   Updated: 2018/09/26 09:53:04 by tmulaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_export(t_vars *t_v)
{
	int		i;

	i = 1;
	while (i < t_v->args_len)
	{
		if (ft_chrpos(t_v->args[i], '=') != -1)
		{
			t_v->var = ft_strsub(t_v->args[i], 0,
				ft_chrpos(t_v->args[i], '='));
			t_v->val = ft_strsub(t_v->args[i], ft_chrpos(t_v->args[i], '=') + 1,
				ft_strlen(t_v->args[i]) - (ft_chrpos(t_v->args[i], '=') + 1));
			ft_setenv(t_v, -1, 0, -1);
			ft_strdel(&t_v->var);
			ft_strdel(&t_v->val);
		}
		else if ((i + 1) < t_v->args_len)
		{
			t_v->var = t_v->args[i];
			t_v->val = t_v->args[i + 1];
			ft_setenv(t_v, -1, 0, -1);
			i++;
		}
		i++;
	}
}

char		*ft_envseek(t_vars *t_v, char *arg)
{
	t_ints	k;
	char	*temp1;
	char	*temp2;

	k.i = 0;
	k.j = -1;
	if (arg[0] == '$')
		arg++;
	k.l = ft_strlen(arg);
	while (++k.j < t_v->env_len && t_v->env[k.j] != NULL)
	{
		if ((int)ft_strlen(t_v->env[k.j]) > k.l)
			temp1 = ft_strsub(t_v->env[k.j], 0, k.l);
		if (!temp1)
			continue ;
		else if (ft_strcmp(temp1, arg) == 0 && t_v->env[k.j][k.l] == '=')
		{
			temp2 = ft_strchr(t_v->env[k.j], '=');
			ft_strdel(&temp1);
			return (++temp2);
		}
		ft_strdel(&temp1);
	}
	return (NULL);
}

void			ft_extern(t_vars *t_v)
{
	int			sig;
	int			pid;

	sig = 1;
	if (t_v->path == NULL && t_v->e == 0)
	{
		ft_putstr("Error: Command Not Found: ");
		ft_putendl(t_v->args[0]);
	}
	else if (t_v->path != NULL && t_v->e == 0)
	{
		pid = fork();
		if (pid < 0)
			ft_putendl("Error: Forking Failed");
		else if (pid > 0)
			wait(&sig);
		else if (pid == 0)
			execve(t_v->path, t_v->e_args, t_v->env);
	}
	else if (t_v->e == -1)
		t_v->e = 0;
}

void			ft_check_args(t_vars *t_v, int i, const char **in)
{
	while (++i < 6 && t_v->e == 0)
	{
		if (t_v->e == 0 && ft_strcmp(t_v->args[0], in[i]) == 0)
			ft_builtin(t_v, i);
	}
	i = -1;
	if (t_v->e == 0 && access(t_v->args[0], F_OK) == -1)
	{
		while (t_v->e == 0 && ++i < ft_arrlen(t_v->paths))
		{
			t_v->temp = ft_strjoin(t_v->paths[i], "/");
			t_v->path = ft_strjoin(t_v->temp, t_v->args[0]);
			ft_strdel(&t_v->temp);
			if (access(t_v->path, F_OK) != -1)
				break ;
			else
				ft_strdel(&t_v->path);
		}
	}
	else if (t_v->e == 0)
		t_v->path = ft_strdup(t_v->args[0]);
	t_v->e_args = t_v->args;
	ft_extern(t_v);
}

void			ft_shlvl(t_vars *t_v)
{
	int		lvl;

	lvl = ft_atoi(ft_envseek(t_v, "SHLVL")) + 1;
	t_v->newlvl = ft_itoa(lvl);
	t_v->var = "SHLVL";
	t_v->val = t_v->newlvl;
	ft_setenv(t_v, -1, 0, -1);
	ft_strdel(&t_v->newlvl);
}
