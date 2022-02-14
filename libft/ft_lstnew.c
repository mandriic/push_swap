/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:32:52 by mandriic          #+#    #+#             */
/*   Updated: 2021/10/06 15:33:01 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(t_data *content)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (NULL == list)
		return (0);
	(*list).content = content;
	(*list).next = NULL;
	return (list);
}
