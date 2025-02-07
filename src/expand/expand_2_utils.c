/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_2_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:21:15 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/07 15:40:03 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "token.h"
#include "expand.h"
#include "env.h"

int	files_wordcount(t_files *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

char	**build_cmd_array(t_files **head)
{
	int		i;
	int		len;
	char	**strs;

	i = 0;
	if (!head || !*head)
		return (NULL);
	len = files_wordcount(*head);
	if (!len)
		return (NULL);
	strs = malloc(sizeof(char *) * (len + 1));
	if (!strs)
		return (files_clear(head), NULL);
	while (*head)
	{
		strs[i] = ft_strdup((*head)->name);
		if (!strs[i])
			return (files_clear(head), ft_free_tab(strs), NULL);
		files_eat(head);
		i++;
	}
	strs[i] = NULL;
	return (strs);
}
