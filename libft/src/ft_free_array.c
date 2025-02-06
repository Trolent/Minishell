/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:33:53 by trolland          #+#    #+#             */
/*   Updated: 2025/02/06 13:35:09 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_array(char **strs, int len)
{
	int	i;

	i = 0;
	while (strs[i] && i < len)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}
