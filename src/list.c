/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:27:50 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/10/19 17:22:07 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/safewipe.h"

void	add_files(char *name, t_safewipe *srm)
{
	t_files	*new_node;
	t_files	*last_node;

	new_node = (t_files *)malloc(sizeof(t_files) + 1);
	if (!new_node)
	{
		srm->err = 2;
		return ;
	}
	new_node->name = strdup(name);
	if (!new_node->name)
	{
		srm->err = 2;
		return ;
	}
	new_node->next = NULL;
	if (srm->files == NULL)
	{
		srm->files = new_node;
		return ;
	}
	last_node = srm->files;
	while (last_node->next)
		last_node = last_node->next;
	last_node->next = new_node;
}
