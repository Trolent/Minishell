/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_interactive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:33:07 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/09 10:32:45 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AST.h"
#include "exec.h"
#include "minishell.h"
#include "token.h"

static void	non_interactive_input(t_data *data, t_token **tk, char *line)
{
	free(line);
	data->ast_root = parse(tk);
	token_clear(tk);
	if (data->ast_root)
		data->status = exec_recursion(data->ast_root, data);
	ast_free(data->ast_root);
	fdlst_clear_leftovers(&data->fdlst);
}

void	non_interactive_shell(t_data *data)
{
	char	*line;
	t_token	*tk;
	size_t	line_count;

	line_count = 0;
	tk = NULL;
	while (++line_count)
	{
		line = readline(NULL);
		if (!line)
			break ;
		if (tokenize(line, &tk, data))
		{
			data->status = 2;
			ft_dprintf(STDERR_FILENO, "minishell: line %d: `%s'\n", line_count,
				line);
			free(line);
			break ;
		}
		non_interactive_input(data, &tk, line);
	}
}
