/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:12:16 by trolland          #+#    #+#             */
/*   Updated: 2025/02/06 18:34:04 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int	handle_error(const char *msg, const char *arg, int ret)
{
	if (arg)
		ft_dprintf(STDERR_FILENO, "minishell: env: '%s': %s\n", arg, msg);
	else
		perror(msg);
	return (ret);
}

int	ft_env(char **argv, t_env *env)
{
	if (argv[1])
		return (handle_error("No such file or directory", argv[1], 127));
	while (env)
	{
		if (ft_dprintf(STDOUT_FILENO, "%s=%s\n", env->key, env->value) < 0)
			return (handle_error("write error", NULL, 125));
		env = env->next;
	}
	return (0);
}
