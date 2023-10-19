/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:46:43 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/10/19 17:55:57 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/safewipe.h"

void	rewrite_files(t_safewipe *srm)
{
	t_files *tmp;

	tmp = srm->files;
	while (tmp)
	{
		if (tmp->type != ISFILE)
		{
			tmp = tmp->next;
			continue ;
		}
		wipe_file(tmp);
		tmp = tmp->next;
	}
}

void	open_file(t_files *file)
{
	file->fd = open(file->name, O_RDWR);
    if (file->fd < 0)
	{
		file->fd = -1;
		ft_error(file->name);
		return ;
    }
	if (fstat(file->fd, &file->st) != 0)
	{
		file->err = 1;
		ft_error(file->name);
		return ;
	}
}

void	write_random_buff(t_files *file)
{
	unsigned char	*randbuff;
	size_t			i;

	randbuff = malloc(file->st.st_size);
    if (!randbuff)
	{
        // Handle error
        return ;
    }
	i = -1;
	while (++i < (size_t)file->st.st_size)
		randbuff[i] = rand() % 256;
    lseek(file->fd, 0, SEEK_SET);
    write(file->fd, randbuff, file->st.st_size);
    free(randbuff);
}

void	write_pass(t_files *file, unsigned char value)
{
    unsigned char *buff = malloc(file->st.st_size);
    if (!buff)
	{
        // Handle error
        return ;
    }
    memset(buff, value, file->st.st_size);
    lseek(file->fd, 0, SEEK_SET);
    write(file->fd, buff, file->st.st_size);
    free(buff);
}

void	wipe_file(t_files *file)
{
	open_file(file);
	if (file->err || file->fd == -1)
	{
		// Handle error
	}
	write_pass(file, 0x00);
	write_pass(file, 0xFF);
	write_random_buff(file);
	close(file->fd);
	file->fd = -1;
	if (unlink(file->name) == -1)
	{
        // Handle error
        return ;
    }
}
