/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:07:48 by mandriic          #+#    #+#             */
/*   Updated: 2021/09/28 14:08:15 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	idx;

	idx = 0;
	if (*dest == 0 && *src == 0)
		return (0);
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[idx] && idx + 1 < dstsize)
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (ft_strlen(src));
}
