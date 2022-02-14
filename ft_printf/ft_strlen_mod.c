/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:48:09 by mandriic          #+#    #+#             */
/*   Updated: 2021/11/25 20:48:31 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen_mod(const char *s)
{
	int	count;

	if (*s == 0)
		return (0);
	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}
