/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:00:29 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/10/19 16:46:31 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/safewipe.h"

int	main(int argc, char **argv)
{
	t_safewipe	srm;

	if (argc < 2)
		return (print_usage(argv[0]), help_err(argv[0]), 1);
	else
	{
		init_srm(&srm);
		parse_options(argv, &srm);
		if (srm.opts.h)
			return (print_usage(argv[0]), display_help(), 0);
		if (srm.err)
			return (srm.err);
		parse_files(argv, &srm);
		rewrite_files(&srm);
		exit_clean(&srm);
	}
	return (0);
}
