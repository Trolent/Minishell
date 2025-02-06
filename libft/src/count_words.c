/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:23:10 by trolland          #+#    #+#             */
/*   Updated: 2024/05/19 17:48:34 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *str, char charset)
{
	int	i;
	int	expecting;
	int	word_count;

	i = 0;
	expecting = 1;
	word_count = 0;
	while (str[i])
	{
		if (str[i] != charset && expecting == 1)
		{
			word_count++;
			expecting = 0;
		}
		if (str[i] == charset && expecting == 0)
			expecting = 1;
		i++;
	}
	return (word_count);
}
