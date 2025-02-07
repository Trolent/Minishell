/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:03:05 by trolland          #+#    #+#             */
/*   Updated: 2025/02/07 15:03:08 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "expand.h"
#include <dirent.h>

// Function to add a file to the list
static void	add_file(t_files **files, const char *name)
{
	t_files	*new_file;

	new_file = malloc(sizeof(t_files));
	if (!new_file)
		return ;
	new_file->name = ft_strdup(name);
	new_file->next = *files;
	*files = new_file;
}

// Custom wildcard matching function
static int	wildcard_match(const char *pattern, const char *str)
{
	if (*pattern == '\0' && *str == '\0')
		return (1);
	if (*pattern == '*' && *(pattern + 1) != '\0' && *str == '\0')
		return (0);
	if (*pattern == '?' || *pattern == *str)
		return (wildcard_match(pattern + 1, str + 1));
	if (*pattern == '*')
		return (wildcard_match(pattern + 1, str) || wildcard_match(pattern, str
				+ 1));
	return (0);
}

// Function to filter files based on the pattern
static void	filter_files(t_files **files, const char *pattern)
{
	t_files	*prev;
	t_files	*curr;

	prev = NULL;
	curr = *files;
	while (curr)
	{
		if (!wildcard_match(pattern, curr->name))
		{
			if (prev)
				prev->next = curr->next;
			else
				*files = curr->next;
			free_curr_name(curr);
			if (prev)
				curr = prev->next;
			else
				curr = *files;
		}
		else
		{
			prev = curr;
			curr = curr->next;
		}
	}
}

// Function to read files from the current directory
static t_files	*read_files(const char *pattern)
{
	DIR				*dir;
	struct dirent	*entry;
	t_files			*files;

	dir = opendir(".");
	files = NULL;
	if (!dir)
		return (NULL);
	entry = readdir(dir);
	while (entry != NULL)
	{
		if (entry->d_name[0] != '.' || pattern[0] == '.')
			add_file(&files, entry->d_name);
		entry = readdir(dir);
	}
	closedir(dir);
	return (files);
}

// Main function to expand wildcards
char	*expand_wildcard(char *str)
{
	t_files	*files;
	char	*res;

	files = read_files(str);
	if (!files)
		return (str);
	filter_files(&files, str);
	if (!files)
		return (str);
	res = write_files(files);
	ft_free_lst_files_expand(&files);
	free(str);
	return (res);
}
