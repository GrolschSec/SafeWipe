/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:58:16 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/10/19 01:56:18 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/safewipe.h"

int	set_option_flag(char c, t_safewipe *srm)
{
	if (c == 'f')
		srm->opts.f = 1;
	else if (c == 'i')
		srm->opts.i = 1;
	else if (c == 'r')
		srm->opts.r = 1;
	else
		return (0);
	return (1);
}

void	process_flags(char **argv, t_safewipe *srm, int i)
{
	int	j;

	j = 1;
	while (argv[i][j])
	{
		if (!set_option_flag(argv[i][j], srm))
		{
			if (!srm->err && !srm->opts.h)
				option_err(argv[0], argv[i][j]);
			srm->err = 1;
			return ;
		}
		j++;
	}
}

void	parse_options(char **argv, t_safewipe *srm)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0)
		{
			srm->opts.h = 1;
			return ;
		}
	}
	i = 0;
	while (argv[++i])
	{
		if (argv[i][0] == '-')
			process_flags(argv, srm, i);
	}
}
