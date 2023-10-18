/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:15:26 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/10/19 00:57:43 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/safewipe.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(const char *str, int fd)
{
	int	i;

	if (!str)
		return ;
	i = -1;
	while (str[++i])
		ft_putchar_fd(str[i], fd);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
		ptr[i++] = c;
	return (s);
}

void	init_srm(t_safewipe *srm)
{
	srm->err = 0;
	ft_memset(&srm->opts, 0, sizeof(srm->opts));
}
