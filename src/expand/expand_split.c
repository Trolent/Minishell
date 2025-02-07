/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 11:35:52 by gschwand          #+#    #+#             */
/*   Updated: 2025/02/07 15:00:35 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"

t_files	*create_new_file_node(char *name)
{
	t_files	*new_node;

	new_node = (t_files *)malloc(sizeof(t_files));
	if (!new_node)
		return (NULL);
	new_node->name = name;
	new_node->next = NULL;
	return (new_node);
}

// Ajout d'un élément à la fin de la liste
void	add_file_node(t_files **head, t_files *new_node)
{
	t_files	*temp;

	if (!*head)
	{
		*head = new_node;
		return ;
	}
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
}
