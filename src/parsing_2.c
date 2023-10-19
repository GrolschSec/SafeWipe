/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:42:16 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/10/19 16:42:08 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/safewipe.h"

int is_directory(const char *path)
{
    struct stat statbuf;

	if (stat(path, &statbuf) != 0)
		return (0);
	return S_ISDIR(statbuf.st_mode);
}

void	get_rights(t_safewipe *srm)
{
	t_files *tmp;

	tmp = srm->files;
	while (tmp)
	{
		if (is_directory(tmp->name))
			tmp->type = ISDIR;
		else
			tmp->type = ISFILE;
		if (access(tmp->name, W_OK) == 0)
			tmp->right = WRITE;
		else
			tmp->right = NO;
		tmp = tmp->next;
	}
}
