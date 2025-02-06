/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:37:36 by trolland          #+#    #+#             */
/*   Updated: 2025/02/06 13:39:29 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int	parse_flags(char **strs, int *i)
{
	int	flag;
	int	j;

	flag = 0;
	while (strs[*i] && strs[*i][0] == '-' && strs[*i][1] == 'n')
	{
		j = 1;
		while (strs[*i][j] == 'n')
			j++;
		if (strs[*i][j] != '\0')
			break ;
		flag = 1;
		(*i)++;
	}
	return (flag);
}

int	builtin_echo(char **strs)
{
	int	i;
	int	err;
	int	nl;

	i = 1;
	err = 0;
	nl = parse_flags(strs, &i);
	while (strs[i])
	{
		err = ft_dprintf(STDOUT_FILENO, "%s", strs[i]);
		if (strs[i + 1])
			err = ft_dprintf(STDOUT_FILENO, " ");
		i++;
	}
	if (!nl)
		err = ft_dprintf(STDOUT_FILENO, "\n");
	if (err == -1)
		return (perror("minishell: echo: write error"), 1);
	return (0);
}
