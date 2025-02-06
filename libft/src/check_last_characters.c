/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_last_characters.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:20:04 by trolland          #+#    #+#             */
/*   Updated: 2024/02/27 16:13:30 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_last_characters(char *str, char *last)
{
	unsigned char	u1;
	unsigned char	u2;
	size_t			str_len;
	size_t			last_len;

	str_len = ft_strlen(str);
	last_len = ft_strlen(last);
	if (str_len <= last_len)
		return (0);
	while (last_len > 0)
	{
		u1 = str[str_len - 1];
		u2 = last[last_len - 1];
		if (u1 != u2)
			return (0);
		str_len--;
		last_len--;
	}
	return (1);
}
