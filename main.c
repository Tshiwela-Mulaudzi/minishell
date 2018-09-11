/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmulaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 10:29:08 by tmulaud           #+#    #+#             */
/*   Updated: 2018/09/11 15:11:53 by tmulaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int		delegate(char **args, int len)
{
	int ret;

	ret = 0;
	if (ft_strcmp(args[0], "echo") == 0)
		ret = ft_echo(args);
	else if (ft_strcmp(args[0], "cd") == 0)
		ret = ft_cd(args);
	else if (ft_strcmp(args[0], "env") == 0)
		ret = ft_env();
	else if (ft_strcmp(args[0], "setenv") == 0)
		ret = ft_setenv(args, len);
	else if (ft_strcmp(args[0], "unsetenv") == 0)
		ret = ft_unsetenv(args, len);
	else if (ft_strcmp(args[0], "exit") == 0)
		ret = ft_exit(args);
	else if (ft_strcmp(args[0], "help") == 0)
		ret = ft_help(args);
	return (ret);
}
int		main(int argc, char **argv)
{
	execute(argv);
	return EXIT_SUCCESS;
}

