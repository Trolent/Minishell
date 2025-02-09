/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_files_double_quote.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akdovlet <akdovlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:01:11 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/09 19:32:54 by akdovlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "expand.h"
#include "minishell.h"
#include "token.h"

// ""

static int	dq_len(char *str, bool end_quote)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '$' && (is_variable(str[(i) + 1]) || str[i + 1] == '?'))
			break ;
		if (str[i] == '"')
		{
			if(end_quote)
			{
				len++;
				break ;
			}
			end_quote = true;
		}
		i++;
		len++;
	}
	return (len);
}
//  "  "'

static void	dq_copy_tmp(char *str, int *i, t_files **tmp, bool *end_quote)
{
	int		j;
	int		len;
	char	*dup;

	j = 0;
	len = dq_len(str + *i, *end_quote);
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return ;
	while (str[*i])
	{
		if ((str[*i] == '$' && is_variable(str[(*i) + 1])) || (str[*i] == '$'
				&& str[(*i) + 1] == '?'))
			break ;
		if (str[*i] == '"')
		{
			if (*end_quote)
			{
				dup[j++] = str[(*i)++];
				break ;
			}
			*end_quote =  true;
		}
		dup[j++] = str[(*i)++];
	}
	dup[j] = '\0';
	files_addback(tmp, files_new(dup));
}

// " $S $A $B"

void	dq_copy(char *str, int *i, t_data *data, t_files **lst)
{
	char	*fusion;
	t_files	*tmp_lst;
	bool	end_quote;

	end_quote = false;
	tmp_lst = NULL;
	while (str[*i])
	{
		if (str[*i] == '$' && is_variable(str[(*i) + 1]))
			var_copy_redir(str, i, data, &tmp_lst);
		else if (str[*i] == '$' && str[(*i) + 1] == '?')
			status_copy(i, data, &tmp_lst);
		else
			dq_copy_tmp(str, i, &tmp_lst, &end_quote);
		if (str[*i] == '"')
		{
			dq_copy_tmp(str, i, &tmp_lst, &end_quote);
			(*i)++;
			break ;
		}
	}
	fusion = files_join(&tmp_lst);
	if (!fusion)
		return ;
	files_addback(lst, files_new(fusion));
}
// "$SALUT"

static int	dq_len2(char *str, bool end_quote)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '$' && (is_variable(str[(i) + 1]) || str[i + 1] == '?'))
			break ;
		if (str[i] == '"')
		{
			if(end_quote)
			{
				len++;
				break ;
			}
			end_quote = true;
		}
		i++;
		len++;
	}
	return (len);
}

static int	dq_copy_tmp2(char *str, int *i, t_files **tmp, bool *end_quote)
{
	int		j;
	int		end;
	int		len;
	char	*dup;

	j = 0;
	end = 0;
	len = dq_len2(str + *i, *end_quote);
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (-1);
	while (str[*i])
	{
		if (str[*i] == '$' && (is_variable(str[(*i) + 1]) || str[(*i) + 1] == '?'))
			break ;
		if (str[*i] == '"')
		{
			if (*end_quote)
			{
				dup[j++] = str[(*i)++];
				end = 1;
				break ;
			}
			*end_quote =  true;
		}
		dup[j++] = str[(*i)++];
	}
	dup[j] = '\0';
	files_addback(tmp, files_new(dup));
	return (end);
}

void	dq_copy2(char *str, int *i, t_data *data, t_files **lst)
{
	char	*fusion;
	t_files	*tmp_lst;
	bool	end_quote;

	end_quote = false;
	tmp_lst = NULL;
	while (str[*i])
	{
		if (str[*i] == '$' && is_variable(str[(*i) + 1]))
			var_copy_redir(str, i, data, &tmp_lst);
		else if (str[*i] == '$' && str[(*i) + 1] == '?')
			status_copy(i, data, &tmp_lst);
		else if (dq_copy_tmp2(str, i, &tmp_lst, &end_quote))
			break ;
	}
	fusion = files_join(&tmp_lst);
	if (!fusion)
		return ;
	files_addback(lst, files_new(fusion));
}
