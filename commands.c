/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmulaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 15:15:42 by tmulaud           #+#    #+#             */
/*   Updated: 2018/09/11 11:24:01 by tmulaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_echo(char **args, struct struct1 s1)
{
	int counter;
	char *temp;

	counter = 0;
	if (argslen > 1)
	{
		while (counter < argslen)
		{
			temp = args[counter];
			ft_putstr(temp);
			if (counter != argslen)
			{
				write(1, " ", 1);
			}
		}
	}
	write(1, "\n", 1);
}
int		ft_exit(char **args)
{
	return EXIT_SUCCESS;
	return (0);
}

int		ft_cd(char **args)
{
	if (args[1] == NULL)
	{
		write(1, "Error: \n", 8);
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			write(1, "something\n", 10);
		}
	}
	return (1);
}

int ft_help(char **args)
{
	//hopefully will come back
	write(1, "Use the system's man command for more\n",38 );
	return (1);
}

int ft_env(void)
{
	extern char **environ;
	int counter;
	char	*var;

	counter = 0;
	var = *environ;

	while (counter++)
	{
		ft_putstr(s);
		ft_putchar('\n');
		var = *(environ + counter);
	}
}
