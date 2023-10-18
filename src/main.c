/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:00:29 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/10/18 23:53:36 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/safewipe.h"

void	print_usage(const char *name)
{
	if (!name)
		return ;
	ft_putstr_fd("Usage: ", 1);
	ft_putstr_fd(name, 1);
	ft_putstr_fd(" [OPTION]... [FILE]...\n"
		"Remove (using the DoD 5220.22-M standard) the FILE(s).\n\n"
		"Try '", 0);
	ft_putstr_fd(name, 1);
	ft_putstr_fd(" --help' for more information.\n", 1);
}

int	main(int argc, char **argv)
{
	t_safewipe	srm;

	if (argc < 2)
		print_usage(argv[0]);
	else
	{
		(void)srm;
		return (1);
	}
	return (0);
}
