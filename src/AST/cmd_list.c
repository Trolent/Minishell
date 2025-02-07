/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:22:11 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/07 16:41:06 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "AST.h"

static t_cmdlst	*cmdlst_last(t_cmdlst *lst)
{
	t_cmdlst	*index;

	index = lst;
	if (!lst)
		return (NULL);
	while (index->next)
		index = index->next;
	return (index);
}

void	cmdlst_add_back(t_cmdlst **lst, t_cmdlst *new)
{
	if (!*(lst))
		*lst = new;
	else
		cmdlst_last(*lst)->next = new;
}

void	cmdlst_clear(t_cmdlst **lst)
{
	t_cmdlst	*tmp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->str);
		free((*lst));
		*lst = tmp;
	}
}

t_cmdlst	*cmdlst_new(char *value, int type, int fd)
{
	t_cmdlst	*new;

	new = malloc(sizeof(t_cmdlst));
	if (!new)
	{
		perror("minishell: cmdlst_new");
		return (NULL);
	}
	*new = (t_cmdlst){};
	new->str = ft_strdup(value);
	new->fd = fd;
	if (!new->str)
	{
		perror("minishell: cmdlst_new");
		return (free(new), NULL);
	}
	new->type = type;
	return (new);
}
