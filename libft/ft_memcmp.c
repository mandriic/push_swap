/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 12:08:07 by mandriic          #+#    #+#             */
/*   Updated: 2021/10/01 12:08:52 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				count;
	const unsigned char	*str1;
	const unsigned char	*str2;

	count = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (count < n && str1[count] == str2[count])
		count++;
	if (count == n)
		return (0);
	else
		return (str1[count] - str2[count]);
}
