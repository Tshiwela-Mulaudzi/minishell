/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   needed3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmulaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 11:36:21 by tmulaud           #+#    #+#             */
/*   Updated: 2018/09/26 09:52:08 by tmulaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_arrlen(char **arr)
{
	int counter;

	counter = 0;
	if (arr != NULL && arr[counter] != NULL)
	{
		while (arr[counter])
			++counter;
	}
	return (counter);
}

void ft_arrdel(char **arr)
{
	int counter;
	int length;

	counter = 0;
	if (arr == NULL)
		return ;
	length = ft_arrlen(arr);
	while (arr[counter] != NULL && counter < length)
	{
		free(arr[counter]);
		arr[counter] = NULL;
		counter++;
	}
	if (arr != NULL)
		free(arr);
	arr = NULL;
}

int ft_chrpos(char *str, char c)
{
	int counter;
	int i;

	i = 0;
	counter = 0;
	while(str[i] && str[i] != c)
	{
		counter++;
		i++;
	}
	if (str[counter] == c)
		return (counter);
	else
		return (-1);
}

void			ft_check_line(t_vars *t_v)
{
	const char	*in[6];

	in[0] = "echo";
	in[1] = "setenv";
	in[2] = "unsetenv";
	in[3] = "cd";
	in[4] = "env";
	in[5] = "exit";
	if (t_v->line != NULL)
	{
		ft_shsplit(t_v, 0, -1, 0);
		if (t_v->args[0] != NULL)
			ft_check_args(t_v, -1, in);
	}
	else
		t_v->args = NULL;
}
