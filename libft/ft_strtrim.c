/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 13:29:38 by mandriic          #+#    #+#             */
/*   Updated: 2021/10/02 13:29:43 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	count;

	if (!s1 || !set)
		return (0);
	while (*s1 != '\0' && ft_strchr(set, *s1))
		s1++;
	count = ft_strlen(s1);
	while (count > 1 && ft_strchr(set, s1[count]))
		count--;
	if (count == 1)
		return (NULL);
	else
	{
		str = ft_substr(s1, 0, count + 1);
		return (str);
	}
}
