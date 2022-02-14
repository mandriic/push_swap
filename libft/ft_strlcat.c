/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 12:16:25 by mandriic          #+#    #+#             */
/*   Updated: 2021/10/01 12:16:38 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_size;
	size_t	dest_size;

	src_size = ft_strlen(src);
	dest_size = ft_strlen(dest);
	i = 0;
	if (size == 0)
		return (src_size);
	else if (dest_size > size)
		return (src_size + size);
	else
	{
		while (src[i] != '\0' && (dest_size + 1 + i) < size)
		{
			dest[i + dest_size] = src[i];
			i++;
		}
		dest[i + dest_size] = '\0';
		if (size < dest_size)
			return (src_size + size);
		return (dest_size + src_size);
	}
}
