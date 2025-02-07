/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:52:23 by akdovlet          #+#    #+#             */
/*   Updated: 2025/02/07 16:38:23 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "type.h"

// env_cpy.c
char	**env_copy_to_char_arr(t_env *env);
int		env_copy(t_env **cpy, char **env);

// env_lst_utils.c
int		find_chr(char *str, char c);
t_env	*ft_last(t_env *lst);
void	env_add_back(t_env **lst, t_env *new);
char	*copy_key(char *str);
t_env	*env_new(char *var);

// env_setup.c
t_env	*env_new_key(char *key, char *value);
int		env_default_setup(t_data *data);
int		env_lstdup(t_env **dst, t_env *src);

// env_setup2.c
int		env_setup(t_data *data, char **env);

// env_utils.c
char	*env_get_value(t_env *env, char *key, t_data *data);
t_env	*env_get_node(t_env *env, char *key);
t_env	*env_get_real_node(t_env **env, char *key);
void	env_clear(t_env **lst);

#endif
