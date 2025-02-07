/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trolland <trolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 10:22:33 by gschwand          #+#    #+#             */
/*   Updated: 2025/02/07 14:55:15 by trolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"

void	ft_strlcat_files(char *dst, const char *src, size_t lenres)
{
	ft_strlcat(dst, "\n", lenres);
	ft_strlcat(dst, src, lenres);
	ft_strlcat(dst, "\n", lenres);
}
