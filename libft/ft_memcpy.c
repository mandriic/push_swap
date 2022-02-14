/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 13:34:48 by mandriic          #+#    #+#             */
/*   Updated: 2021/09/28 13:34:53 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	int			count;

	if (dst == 0 && src == 0)
		return (0);
	s = (char *) src;
	d = (char *) dst;
	count = 0;
	while (n--)
	{
		d[count] = s[count];
		count++;
	}
	return (dst);
}
