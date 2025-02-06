/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:17:32 by trolland          #+#    #+#             */
/*   Updated: 2023/11/06 16:58:17 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*from;
	unsigned char	*to;
	int				i;

	from = (unsigned char *)src;
	to = (unsigned char *)dst;
	if (from == to || len == 0)
		return (dst);
	else if (to > from && to - from < (int)len)
	{
		i = len;
		while (--i >= 0)
			to[i] = from[i];
	}
	else if (from > to && from - to < (int)len)
	{
		i = -1;
		while (++i < (int)len)
			to[i] = from[i];
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
