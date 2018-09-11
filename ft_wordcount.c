/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmulaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 21:52:42 by tmulaud           #+#    #+#             */
/*   Updated: 2018/09/11 13:44:14 by tmulaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_wordcount(char const *s, char c)
{
	unsigned int	counter1;
	int				counter2;

	counter1 = 0;
	counter2 = 0;
	while (s[counter1])
	{
		while (s[counter1] == c)
			counter1++;
		if (s[counter1] != '\0' && s[counter1] != c)
			counter2++;
		while (s[counter1] && (s[counter1] != c) && s[counter1] != '\0')
			counter1++;
	}
	return (counter2);
}
