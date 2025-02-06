/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:58:03 by trolland          #+#    #+#             */
/*   Updated: 2025/02/06 13:58:08 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int	handle_error(const char *msg)
{
	perror(msg);
	return (1);
}

int	ft_pwd(char **argv, t_env *env)
{
	char	*buf;

	(void)argv;
	(void)env;
	buf = getcwd(NULL, 0);
	if (buf == NULL)
		return (handle_error(PWDERROR));
	if (ft_dprintf(STDOUT_FILENO, "%s\n", buf) == -1)
		return (free(buf), handle_error("minishell: pwd: write error"));
	free(buf);
	return (0);
}
