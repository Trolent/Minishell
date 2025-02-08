/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pidlst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:10:15 by trolland          #+#    #+#             */
/*   Updated: 2025/02/08 13:10:18 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_pidlst	*ft_lstnew_pidlst(pid_t pid)
{
	t_pidlst	*new;

	new = malloc(sizeof(t_pidlst));
	if (!new)
		return (perror("minishell: pidlst_new"), NULL);
	new->next = NULL;
	new->pid = pid;
	return (new);
}

void	ft_lstadd_back_pidlst(t_pidlst **lst, t_pidlst *new)
{
	t_pidlst	*tmp;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	pidlst_clear(t_pidlst **lst)
{
	t_pidlst	*tmp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}
