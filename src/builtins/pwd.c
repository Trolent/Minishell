/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:03:00 by gschwand          #+#    #+#             */
/*   Updated: 2025/02/06 12:53:27 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_pwd(char **argv, t_env *env)
{
	char	*buf;

	(void)argv;
	(void)env;
	buf = getcwd(NULL, 0);
	if (buf == NULL)
		return (perror(PWDERROR), 1);
	if (ft_dprintf(STDOUT_FILENO, "%s\n", buf) == -1)
		return (perror("minishell: pwd: write error"), free(buf), 1);
	free(buf);
	return (0);
}
