/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_nums.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <mandriic@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:36:52 by mandriic          #+#    #+#             */
/*   Updated: 2022/02/08 11:36:55 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h" 

void	ft_tres(t_vars *vars)
{
	vars->a = vars->list_a->content->num;
	vars->b = vars->list_a->next->content->num;
	vars->c = vars->list_a->next->next->content->num;
	if (ft_check(vars->list_a) == 1)
	{
		if (vars->a > vars->b && vars->b < vars->c && vars->a < vars->c)
			ft_swap_a(vars, 1);
		if (vars->a > vars->b && vars->b < vars->c && vars->a > vars->c)
			ft_rotate_a(vars, 1);
		if (vars->a > vars->b && vars->b > vars->c)
		{
			ft_swap_a(vars, 1);
			ft_rotate_a_rev(vars, 1);
		}
		if (vars->a < vars->b && vars->b > vars->c && vars->a > vars->c)
			ft_rotate_a_rev(vars, 1);
		if (vars->a < vars->b && vars->b > vars->c && vars->a < vars->c)
		{
			ft_swap_a(vars, 1);
			ft_rotate_a(vars, 1);
		}
	}
}

void	ft_five_push_to_b(t_vars *vars)
{
	if (vars->count == 4)
	{
		while (vars->list_a->content->num != *vars->list_a->content->max
			&& vars->list_a->content->num != *vars->list_a->content->min)
			ft_rotate_a(vars, 1);
		ft_push_a(vars, 1);
	}
	if (vars->count == 5)
	{
		while (vars->list_a->content->num != *vars->list_a->content->max
			&& vars->list_a->content->num != *vars->list_a->content->min)
			ft_rotate_a(vars, 1);
		ft_push_a(vars, 1);
		while (vars->list_a->content->num != *vars->list_a->content->max
			&& vars->list_a->content->num != *vars->list_a->content->min)
			ft_rotate_a(vars, 1);
		ft_push_a(vars, 1);
	}
}

void	ft_five(t_vars *vars)
{
	vars->count = ft_lstsize(vars->list_a);
	if (vars->count == 2)
	{
		if (vars->list_a->content->num > vars->list_a->next->content->num)
			ft_rotate_a(vars, 1);
		return ;
	}
	ft_five_push_to_b(vars);
	ft_tres(vars);
	if (vars->count == 5)
	{
		if (vars->list_b->content->num > vars->list_b->next->content->num)
			ft_swap_b(vars, 1);
		ft_push_b(vars, 1);
		ft_push_b(vars, 1);
		ft_rotate_a(vars, 1);
	}
	if (vars->count == 4)
	{
		ft_push_b(vars, 1);
		if (ft_check(vars->list_a))
			ft_rotate_a(vars, 1);
	}
}
