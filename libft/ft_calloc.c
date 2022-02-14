/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:09:58 by mandriic          #+#    #+#             */
/*   Updated: 2021/09/28 16:10:01 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	char	*tmp;
	size_t	sum;

	sum = (size * count);
	p = malloc (count * size);
	if (p)
	{
		if (NULL == p)
			return (0);
		tmp = (char *)p;
		while (sum > 0)
		{
			*tmp = 0;
			tmp++;
			sum--;
		}
	}
	return (p);
}
