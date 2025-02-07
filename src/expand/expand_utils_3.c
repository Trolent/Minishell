/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:27:54 by gschwand          #+#    #+#             */
/*   Updated: 2025/02/07 15:39:11 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "expand.h"

void	del_files_not_hidden(t_files **files)
{
	t_files	*node;
	t_files	*tmp;

	node = *files;
	while (node && node->name[0] == '.')
	{
		tmp = node;
		node = node->next;
	}
	tmp->next = NULL;
	ft_free_lst_files_expand(&node);
}
