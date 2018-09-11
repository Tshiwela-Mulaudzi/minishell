/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmulaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 14:37:06 by tmulaud           #+#    #+#             */
/*   Updated: 2018/09/11 15:55:16 by tmulaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		numcommands(void)
{
	return sizeof(commands_str);
}

int		launch(char **args)
{
	pid_t pid;
	pid_t wpid;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			write(1, "lsh", 3);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		write(1, "lsh", 3);
	}
	else
	{
		while (1)
		{
			wpid = waitpid(pid, &status, WUNTRACED);
		}
		while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}

int execute(char **args)
{
	int i;
	if (args[0] == NULL)
	{
		write(1, "Command not found\n",18);
		return (1);	
	}

	i = 0;
	while (i < sizeof(commands_str))
	{
		if (ft_strcmp(args[0], commands_str[i]) == 0)
		{
			return (*commands_func[i]);
		}
		i++;
	}

	launch(args);
}
