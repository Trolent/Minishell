/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:18:24 by gschwand          #+#    #+#             */
/*   Updated: 2025/02/06 12:45:45 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_env(char **argv, t_env *env)
{
	if (argv[1])
	{
		ft_dprintf(STDERR_FILENO,
			"minishell: env: ‘%s’: No such file or directory\n", argv[1]);
		return (127);
	}
	else
	{
		while (env)
		{
			if (ft_dprintf(STDOUT_FILENO, "%s=%s\n", env->key, env->value) < 0)
				return (perror("minishell: env: write error"), 125);
			env = env->next;
		}
	}
	return (0);
}
