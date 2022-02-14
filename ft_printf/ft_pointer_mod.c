/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:33:46 by mandriic          #+#    #+#             */
/*   Updated: 2021/12/01 12:38:04 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(void *pointer)
{
	int		i;
	char	*hex;

	i = 0;
	hex = ft_num_to_base((long unsigned int)pointer, "0123456789abcdef");
	ft_putchar('0');
	ft_putchar('x');
	if (*hex == 0)
	{
		free (hex);
		return (write(1, "0", 1) + 2);
	}
	while (hex[i] != '\0')
		ft_putchar(hex[i++]);
	free(hex);
	return (i + 2);
}
