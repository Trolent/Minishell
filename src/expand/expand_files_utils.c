/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_files_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:03:43 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/07 15:20:32 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"
#include "minishell.h"

static int	files_len(t_files *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		if (lst->name)
			len += ft_strlen(lst->name);
		lst = lst->next;
	}
	return (len);
}

void	files_eat(t_files **node)
{
	t_files	*tmp;

	if (!*node || !node)
		return ;
	tmp = (*node)->next;
	if ((*node)->name)
		free((*node)->name);
	free(*node);
	*node = tmp;
}

void	files_clear(t_files **head)
{
	if (!*head || !head)
		return ;
	while (*head)
		files_eat(head);
}

char	*files_join(t_files **lst)
{
	int		len;
	int		i;
	int		j;
	char	*fusion;

	if (!*lst || !lst)
		return (NULL);
	i = 0;
	len = files_len(*lst);
	fusion = malloc(sizeof(char) * (len + 1));
	if (!fusion)
		return (NULL);
	while (*lst)
	{
		if ((*lst)->name)
		{
			j = 0;
			while ((*lst)->name[j])
				fusion[i++] = (*lst)->name[j++];
		}
		files_eat(lst);
	}
	fusion[i] = '\0';
	return (fusion);
}
