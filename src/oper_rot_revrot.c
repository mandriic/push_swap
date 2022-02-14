/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_rot_revrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <mandriic@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:43:51 by mandriic          #+#    #+#             */
/*   Updated: 2022/02/08 11:43:54 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_rotate_a(t_vars *vars, int prnt)
{
	t_list	*temp;
	t_list	*last;
	int		size;

	size = ft_lstsize(vars->list_a);
	if (size == 1)
		return ;
	if (size == 2)
	{
		ft_swap_a(vars, 1);
		return ;
	}
	if (vars->list_a->next != NULL)
	{
		temp = vars->list_a;
		vars->list_a = vars->list_a->next;
		temp->next = NULL;
		last = ft_lstlast(vars->list_a);
		last->next = temp;
		if (prnt == 1)
			ft_printf("ra\n");
	}
}

void	ft_rotate_b(t_vars *vars, int prnt)
{
	t_list	*temp;
	t_list	*last;
	int		size;

	size = ft_lstsize(vars->list_b);
	if (size == 1)
		return ;
	if (size == 2)
	{
		ft_swap_b(vars, 1);
		return ;
	}
	if (vars->list_b)
	{
		temp = vars->list_b;
		vars->list_b = vars->list_b->next;
		temp->next = NULL;
		last = ft_lstlast(vars->list_b);
		last->next = temp;
		if (prnt == 1)
			ft_printf("rb\n");
	}
}

t_list	*ft_lstpenlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (1)
	{
		if (lst->next->next != NULL)
			lst = lst->next;
		else
			break ;
	}
	return (lst);
}

void	ft_rotate_a_rev(t_vars *vars, int prnt)
{
	t_list	*temp;
	t_list	*last;
	t_list	*penlast;
	int		size;

	size = ft_lstsize(vars->list_a);
	if (size == 1)
		return ;
	if (size == 2)
	{
		ft_swap_a(vars, 1);
		return ;
	}
	last = ft_lstlast(vars->list_a);
	penlast = ft_lstpenlast(vars->list_a);
	temp = vars->list_a;
	vars->list_a = last;
	vars->list_a->next = temp;
	penlast->next = NULL;
	if (prnt == 1)
		ft_printf("rra\n");
}

void	ft_rotate_b_rev(t_vars *vars, int prnt)
{
	t_list	*temp;
	t_list	*last;
	t_list	*penlast;
	int		size;

	size = ft_lstsize(vars->list_b);
	if (size == 1)
		return ;
	if (size == 2)
	{
		ft_swap_b(vars, 1);
		return ;
	}
	last = ft_lstlast(vars->list_b);
	penlast = ft_lstpenlast(vars->list_b);
	temp = vars->list_b;
	vars->list_b = last;
	vars->list_b->next = temp;
	penlast->next = NULL;
	if (prnt == 1)
		ft_printf("rrb\n");
}
