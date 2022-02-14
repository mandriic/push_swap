/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:09:56 by mandriic          #+#    #+#             */
/*   Updated: 2021/10/08 16:10:01 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*start_lst;

	start_lst = NULL;
	while (lst)
	{
		new_lst = ft_lstnew(f(lst->content));
		if (new_lst == 0)
			ft_lstclear(&start_lst, del);
		ft_lstadd_back(&start_lst, new_lst);
		lst = lst->next;
	}
	return (start_lst);
}
