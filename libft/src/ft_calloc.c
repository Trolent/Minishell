/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:17:32 by trolland          #+#    #+#             */
/*   Updated: 2023/11/06 16:57:50 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*calloc;

	if ((int)count < 0 && (int)size < 0)
		return (NULL);
	if ((int)count == 0 || (int)size == 0)
	{
		count = 1;
		size = 1;
	}
	calloc = malloc(size * count);
	if (!calloc)
		return (NULL);
	ft_bzero(calloc, (size * count));
	return (calloc);
}
