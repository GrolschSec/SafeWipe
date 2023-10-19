/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:17:59 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/10/19 14:15:13 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/safewipe.h"

void	clean_list(t_files *files)
{
	t_files *tmp;

	if (!files)
		return ;
	while (files)
	{
		if (files->name)
			free(files->name);
		tmp = files->next;
		free(files);
		files = tmp;
	}
	return ;
}

void	exit_clean(t_safewipe *srm)
{
	clean_list(srm->files);
	exit(srm->err);
}
