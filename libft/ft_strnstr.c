/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 14:03:14 by mandriic          #+#    #+#             */
/*   Updated: 2021/10/01 14:03:21 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_find_local(const char *haystack, const char *needle, size_t len)
{
	size_t	i_n;
	size_t	i_h;
	size_t	mem;
	size_t	mem2;

	i_n = 0;
	i_h = 0;
	while (needle[i_n] != '\0' && haystack[i_h] != '\0' && i_h < len)
	{
		mem = i_h;
		mem2 = 0;
		while (needle[i_n] == haystack[i_h]
			&& needle[i_n] != '\0' && haystack[i_h] != '\0' && i_h < len)
		{	
			i_n++;
			i_h++;
			mem2++;
			if (needle[i_n] == '\0')
				return ((char *)haystack + mem);
		}
		i_h -= mem2;
		i_n = 0;
		i_h++;
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (len == 0 && haystack == 0)
		return (0);
	if (*needle == 0)
		return ((char *)haystack);
	return (ft_find_local(haystack, needle, len));
}
