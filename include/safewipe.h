/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safewipe.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:04:21 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/10/19 14:55:33 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAFEWIPE_H
# define SAFEWIPE_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct s_files	t_files;

enum e_type
{
	NONE,
	ISDIR,
	ISFILE
};

enum e_access 
{
	NO,
	WRITE
};

struct s_files
{
	int		fd;
	int		type;
	int		right;
	char	*name;
	t_files	*next;
};	

/*	--force 		*/
/* 	--interactive	*/
/* 	--recursive		*/
/*	--help			*/
typedef struct s_options
{
	int	f;
	int	i;
	int	r;
	int	h;
}				t_options;

typedef struct s_safewipe
{
	int			err;
	t_options	opts;
	t_files		*files;
}				t_safewipe;

/* PARSING_1 */
int		set_option_flag(char c, t_safewipe *srm);
void	process_flags(char **argv, t_safewipe *srm, int i);
void	parse_options(char **argv, t_safewipe *srm);
void	parse_files(char **argv, t_safewipe *srm);
int		exist(const char *name);
/* PARSING_2 */
void	get_rights(t_safewipe *srm);
int		is_directory(const char *path);
/* UTILS_1 */
size_t	ft_strlen(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(const char *str, int fd);
void	*ft_memset(void *s, int c, size_t n);
void	init_srm(t_safewipe *srm);
/* UTILS 2 */
void	option_err(char *name, char opt);
void	help_err(char *name);
void	display_help(void);
void	print_usage(const char *name);
/* LIST */
void	add_files(char *name, t_safewipe *srm);
/* CLEAN */
void	clean_list(t_files *files);
void	exit_clean(t_safewipe *srm);
#endif
