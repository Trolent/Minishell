/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_file_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 10:06:38 by gschwand          #+#    #+#             */
/*   Updated: 2025/02/07 16:20:38 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"


void	files_addback(t_files **alst, t_files *new)
{
	t_files	*tmp;

	if (!*alst)
	{
		*alst = new;
		return ;
	}
	tmp = *alst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

t_files	*files_new(char *str)
{
	t_files	*new;

	new = malloc(sizeof(t_files));
	if (!new)
	{
		perror("minishell: files_new");
		return (NULL);
	}
	new->name = str;
	new->next = NULL;
	return (new);
}

t_files	*files_new_dup(char *str)
{
	t_files	*new;

	new = malloc(sizeof(t_files));
	if (!new)
	{
		perror("minishell: files_new_dup");
		return (NULL);
	}
	new->name = ft_strdup(str);
	if (!new->name)
	{
		perror("minishell: files_new_dup");
		free(new);
		return (NULL);
	}
	new->next = NULL;
	return (new);
}
