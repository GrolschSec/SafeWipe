/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 00:47:14 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/10/19 02:02:46 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/safewipe.h"

void	option_err(char *name, char opt)
{
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": invalid option -- '", 2);
	ft_putchar_fd(opt, 2);
	ft_putstr_fd("'\n", 2);
}

void	help_err(char *name)
{
	ft_putstr_fd("Try '", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(" --help' for more information.\n", 2);
}

void	display_help(void)
{
	ft_putstr_fd("Options:\n", 1);
	ft_putstr_fd("  -f			"
		"Suppress error messages for\n"
		"			 missing files.\n", 1);
	ft_putstr_fd("  -i			"
		"Prompt for each file removal.\n", 1);
	ft_putstr_fd("  -r			"
		"Remove directories and their\n"
		"			 contents recursively.\n", 1);
	ft_putstr_fd("  -h, --help		"
		"Display this help text and exit.\n", 1);
}

void	print_usage(const char *name)
{
	if (!name)
		return ;
	ft_putstr_fd("Usage: ", 1);
	ft_putstr_fd(name, 1);
	ft_putstr_fd(" [OPTION]... [FILE]...\n"
		"Remove (using the DoD 5220.22-M standard) the FILE(s).\n\n", 1);
}
