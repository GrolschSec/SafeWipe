/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:58:16 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/10/19 00:57:19 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/safewipe.h"

int	parse_single_option(char c, t_safewipe *srm)
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

void	parse_options(char **argv, t_safewipe *srm)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		if (argv[i][0] == '-')
		{
			if (strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0)
			{
				srm->opts.h = 1;
				return ;
			}
			j = 1;
			while (argv[i][j])
			{
				if (!parse_single_option(argv[i][j], srm))
				{
					srm->err = 1;
					option_err(argv[0], argv[i][j]);
					return ;
				}
				j++;
			}
		}
	}
}
