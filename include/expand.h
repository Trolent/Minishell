/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:01:34 by trolland          #+#    #+#             */
/*   Updated: 2025/02/07 15:01:32 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H
# include "minishell.h"

typedef struct s_files
{
	char			*name;
	bool			join;
	struct s_files	*next;
}					t_files;

// expand_debugg.c
void				print_tab(char **tab);
void				ft_print_lst_files(t_files *files);

// lst_file_utils.c
t_files				*files_new(char *str);
t_files				*files_new_dup(char *str);
void				ft_lstdelone_files(t_files **files, t_files *to_delete);
int					files_addback_new(t_files **alst, t_files *new);
void				files_addback(t_files **alst, t_files *new);

// lst_file_utils2.c
void				ft_free_lst_files_expand(t_files **files);

// sort_files.c
void				ft_strlcat_files(char *dst, const char *src, size_t lenres);

// wildcard.c
char				*expand_wildcard(char *str);

// wildcard_utils.c
void				free_curr_name(t_files *curr);
char				*write_files(t_files *files);

// expand_files.c
void				dq_copy(char *str, int *i, t_data *data, t_files **lst);
char				*expand_filename(char *str, t_data *data);
void				files_clear(t_files **head);
int					check_decla_var(char *str);
char				*files_join(t_files **lst);
void				var_copy(char *str, int *i, t_data *data, t_files **lst);
void				var_copy_redir(char *str, int *i, t_data *data,
						t_files **lst);
void				status_copy(int *i, t_data *data, t_files **head);
void				sq_copy(char *str, int *i, t_files **lst);
void				regular_copy(char *str, int *i, t_files **lst);
void				dq_copy(char *str, int *i, t_data *data, t_files **lst);
char				*expand_hd(char *str, t_data *data);
void				files_eat(t_files **node);
char				**build_cmd_array(t_files **head);
void				files_addback_lst(t_files **main, t_files **sub);
char				**expand_cmd(char **strs, t_data *data);
void				files_remove_quotes(t_files *lst);
int					files_len(t_files *lst);
int					ifs_countword(char *str);
int					is_ifs(char c);
char				*ifs_copy(char *str);
char				*expand_string(char *str, t_data *data, t_files **head);
char				*extract_var_name(char *str, int *i);
void				del_files_not_hidden(t_files **files);
void				del_files_hidden(t_files **files);
void				free_tab(char **tab);

#endif
