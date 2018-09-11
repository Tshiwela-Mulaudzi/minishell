/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmulaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 10:27:28 by tmulaud           #+#    #+#             */
/*   Updated: 2018/09/11 15:50:54 by tmulaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H
# define BUFF_SIZE 50

# include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>


char *commands_str[] = 
{
	"cd",
	"echo",
	"env",
	"exit",
	"setenv",
	"unsetenv",
	"help"
};

int (*commands_func[])(char **) =
{
	&ft_cd,
	&ft_echo,
	&ft_env,
	&ft_exit,
	&ft_setenv,
	&ft_unsetenv,
	&ft_help
};

typedef struct struct1
{
	int argslen;
	int	counter1;
	int counter2;
	int count;
	int len;
	int size;
}				s1;


int			get_next_line(int const fd, char **line);
size_t		ft_strlen(const char *s);
char		*ft_strchr(const char *s, int c);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strnew(size_t size);
void		*ft_memalloc(size_t size);
void		*ft_memset(void *b, int c, size_t len);
int			main(int argc, char **argv);
int			count_words(char *str);
char		*malloc_word(char *str);
int			launch(char **args);
char		**ft_strsplit(char const *s, char c);
char		*ft_strndup(const char *s, size_t n);
int			ft_wordcount(char const *s, char c);
char		*ft_strncpy(char *dst, const char *src, size_t len);
int			ft_echo(char **args);
int			ft_exit(char **args);
int			ft_cd(char **args);
int			ft_help(char **args);
int			ft_setenv(char **args, int len);
int			ft_unsetenv(char **args, int len);
int			delegate(char **args, int len);
int			ft_env(void);
int			ft_strcmp(const char *s1, const char *s2);
int 		execute(char **args);

#endif
