/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:47:17 by trolland          #+#    #+#             */
/*   Updated: 2025/02/07 16:24:34 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "expand.h"

void	free_curr_name(t_files *curr)
{
	free(curr->name);
	free(curr);
}

void	ft_strlcat_files(char *dst, const char *src, size_t lenres)
{
	ft_strlcat(dst, "\n", lenres);
	ft_strlcat(dst, src, lenres);
	ft_strlcat(dst, "\n", lenres);
}

char	*write_files(t_files *files)
{
	t_files	*tmp;
	char	*res;
	int		lenres;

	tmp = files;
	lenres = 0;
	while (tmp)
	{
		lenres += ft_strlen(tmp->name) + 2;
		tmp = tmp->next;
	}
	res = ft_calloc(sizeof(char), lenres + 1);
	if (!res)
		return (perror("minishell: ft_calloc"), NULL);
	tmp = files;
	while (tmp)
	{
		ft_strlcat_files(res, tmp->name, lenres + 1);
		tmp = tmp->next;
	}
	return (res);
}

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
