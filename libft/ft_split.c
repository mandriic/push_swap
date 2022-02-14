/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:42:07 by mandriic          #+#    #+#             */
/*   Updated: 2021/10/04 13:42:12 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_fill(char **str, char const *s, char c)
{
	int	i;
	int	i2;
	int	start;
	int	end;

	i = 0;
	i2 = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			i++;
			continue ;
		}
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		end = i;
		str[i2] = ft_substr(s, start, end - start);
		i2++;
	}
	str[i2] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		wds;
	int		i;

	if (!s)
		return (0);
	wds = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (ft_strchr(&c, s[i]) && s[i + 1] != c && s[i + 1] != '\0' )
			wds++;
		i++;
	}
	str = (char **) malloc(sizeof(char *) * (wds + 2));
	if (str)
	{
		return (ft_fill(str, s, c));
	}
	return (0);
}
