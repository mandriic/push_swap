/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:03:46 by mandriic          #+#    #+#             */
/*   Updated: 2021/10/06 13:03:50 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_int2char2(long long int i, char *p)
{
	if (i / 10 == 0)
	{
		*p++ = i + '0';
		*p = '\0';
		return (p);
	}
	else
	{
		p = ft_int2char2(i / 10, p);
		*p++ = i % 10 + '0';
		*p = '\0';
		return (p);
	}
}

static char	*itoa_local(int n)
{
	static char		arr[11];
	char			*str;
	long long int	temp_num;

	str = arr;
	temp_num = (long long int)n;
	if (n < 0)
	{
		*str++ = '-';
		temp_num *= -1;
		ft_int2char2(temp_num, str);
		return (str - 1);
	}
	ft_int2char2(temp_num, str);
	return (str);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	*temp;
	int		i;

	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	i = 0;
	temp = itoa_local(n);
	while (temp[i] != '\0')
		write(fd, &temp[i++], 1);
}
