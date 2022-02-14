/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 12:01:52 by mandriic          #+#    #+#             */
/*   Updated: 2021/10/01 12:04:47 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			count;
	unsigned char	*p;

	if (c == 0 && n == 0)
		return (0);
	p = (unsigned char *)s;
	count = 0;
	while (p[count] != (unsigned char)c && (count + 1) < n)
		count++;
	if (p[count] == (unsigned char)c)
	{
		return (p + count);
	}
	else
		return (0);
}
