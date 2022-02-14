/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <mandriic@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:50:23 by mandriic          #+#    #+#             */
/*   Updated: 2022/02/08 11:50:26 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap_bonus.h"

void	ft_swap_a(t_vars *vars, int prnt)
{
	t_list	*temp;
	t_list	*sec;
	int		size;

	size = ft_lstsize(vars->list_a);
	if (vars->list_a && size == 2)
	{	
		temp = vars->list_a;
		sec = vars->list_a->next;
		vars->list_a = vars->list_a->next;
		vars->list_a->next = temp;
		vars->list_a->next->next = NULL;
	}		
	else if (vars->list_a && size > 2)
	{
		temp = vars->list_a;
		sec = vars->list_a->next->next;
		vars->list_a = vars->list_a->next;
		vars->list_a->next = temp;
		vars->list_a->next->next = sec;
	}
	if (prnt == 1)
		ft_printf("sa\n");
}

void	ft_swap_b(t_vars *vars, int prnt)
{
	t_list	*frst;
	t_list	*sec;
	int		size;

	size = ft_lstsize(vars->list_b);
	if (size == 2)
	{	
		frst = vars->list_b;
		sec = vars->list_b->next;
		vars->list_b = sec;
		vars->list_b->next = frst;
		vars->list_b->next->next = NULL;
	}
	else if (vars->list_b && size > 2)
	{
		frst = vars->list_b;
		sec = vars->list_b->next->next;
		vars->list_b = vars->list_b->next;
		vars->list_b->next = frst;
		vars->list_b->next->next = sec;
	}
	if (prnt == 1)
		ft_printf("sb\n");
}
