/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:00:29 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/10/19 01:10:35 by rlouvrie         ###   ########.fr       */
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
		"Remove (using the DoD 5220.22-M standard) the FILE(s).\n\n", 1);
}

int	main(int argc, char **argv)
{
	t_safewipe	srm;

	if (argc < 2)
		return (print_usage(argv[0]), help_err(argv[0]), 1);
	else
	{
		init_srm(&srm);
		parse_options(argv, &srm);
		if (srm.err)
			return (srm.err);
	}
	return (0);
}
