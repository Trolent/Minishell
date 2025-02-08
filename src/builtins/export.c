/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:04:39 by trolland          #+#    #+#             */
/*   Updated: 2025/02/08 13:02:56 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int	check_export(char *arg, t_data *data)
{
	if (check_and_update_env(&data->export, arg))
		return (1);
	if (check_and_update_env(&data->env, arg))
		return (1);
	return (0);
}

static int	print_env_lst(t_env *lst)
{
	int	print;

	print = 0;
	while (lst)
	{
		if (lst->value)
			print = ft_dprintf(STDOUT_FILENO, "declare -x %s=\"%s\"\n",
					lst->key, lst->value);
		else
			print = ft_dprintf(STDOUT_FILENO, "declare -x %s\n", lst->key);
		if (print == -1)
			return (perror("minishell: export: write error"), print);
		lst = lst->next;
	}
	return (print);
}

int	ft_export(char **args, t_data *data)
{
	int	i;
	int	e;
	int	tmp;

	e = 0;
	tmp = 0;
	i = 0;
	if (!args[1])
		return (print_env_lst(data->export));
	while (args[++i])
	{
		tmp = check_export(args[i], data);
		if (tmp)
			e = tmp;
	}
	return (e);
}
