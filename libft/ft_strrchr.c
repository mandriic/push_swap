/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 12:24:15 by mandriic          #+#    #+#             */
/*   Updated: 2021/10/01 12:24:18 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	count;

	count = ft_strlen(s);
	while (s[count] != (char)c && count != 0)
		count--;
	if (s[count] == (char)c)
		return ((char *)s + count);
	else
		return (0);
}
