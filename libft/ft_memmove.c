/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:23:31 by mandriic          #+#    #+#             */
/*   Updated: 2021/09/28 14:23:34 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;
	size_t		count;

	if (dst == 0 && src == 0)
		return (0);
	d = dst;
	s = src;
	count = 0;
	if (src < dst)
	{
		while (len--)
			d[len] = s[len];
	}
	else
	{
		while (len--)
		{
			d[count] = s[count];
			count++;
		}
	}
	return (dst);
}
