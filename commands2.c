/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmulaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 11:55:18 by tmulaud           #+#    #+#             */
/*   Updated: 2018/09/11 14:52:10 by tmulaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_setenv(char **args, int len)
{
	extern char **environ;
	char **temp;
	int ret;

	temp = environ;
	while (temp != NULL)
	{
		if (ft_strncpy(args, temp, len) = 0 && temp[counter2] == '=')
		{
			ret = 1;
			ft_strclr(temp);
			ft_strcpy(temp, args);
		}
	}
	if (ret != 1)
	{
		ret = 0;
		temp = (char **)malloc(sizeof(char *) * size + 1);
		ft_memcpy(temp, environ, sizeof(char *) * count);
		environ = temp;
		ft_strcpy(environ(count), args);
		environ(count) + 1 = NULL;
	}
	return (ret);
}

int ft_ensetenv(char **args, int len)
{
	extern char **environ;
	char **temp;
	int i;

	while (i < len)
	{
		if (args[counter1][counter2] == '\0' || args[counter1][counter2] == NULL || 
				ft_strchr(args[counter2], '=') != NULL)
		{
			continue;
		}
		temp = environ;
		len = ft_strlen(args[count]);
		while (temp[count] != NULL)
		{
			if (ft_strncmp(args[count], temp[count], len) = 0 ||
					temp[count][len] == '=')
			{
				ret = 0;
				k--;
				while (temp++ != 1)
					temp[count] = temp[count + 1];
			}
		}
	}
	return (ret);
}
