/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safewipe.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:04:21 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/10/18 23:42:58 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAFEWIPE_H
# define SAFEWIPE_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_files	t_files;

struct s_files
{
	int		fd;
	char	*name;
	t_files	*next;
};	

typedef struct s_options
{
	int	f;	/* --force */
	int	i;	/* --interactive */
	int	r;	/* --recursive */
	int	h;	/* --help */
}				t_options;

typedef struct s_safewipe
{
	t_options	opts;
	t_files		*files;
}				t_safewipe;

/* MAIN */
void	print_usage(const char *name);
/* PARSING_1 */
/* UTILS_1 */
size_t	ft_strlen(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(const char *str, int fd);
#endif
