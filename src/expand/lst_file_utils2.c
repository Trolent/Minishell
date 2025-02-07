/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_file_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:37:59 by gschwand          #+#    #+#             */
/*   Updated: 2025/02/07 14:59:45 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"

void	ft_free_lst_files_expand(t_files **files)
{
	t_files	*tmp;

	while (*files)
	{
		tmp = (*files)->next;
		free((*files)->name);
		free(*files);
		*files = NULL;
		*files = tmp;
	}
}
