/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 00:47:14 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/10/19 01:06:52 by rlouvrie         ###   ########.fr       */
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
	ft_putstr_fd(name, 2);
	ft_putstr_fd(" --help' for more information.\n", 2);
}
