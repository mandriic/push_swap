/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_find_lowcost.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <mandriic@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:28:35 by mandriic          #+#    #+#             */
/*   Updated: 2022/02/08 21:28:40 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_operations_2(t_vars *vars, t_list *low)
{
	if (low->content->operacion == 6)
	{
		ft_rotate_b_rev(vars, 1);
		ft_rotate_a (vars, 1);
	}
	else if (low->content->operacion == 7)
	{
		ft_rev_rot_ab(vars, 1);
		ft_rotate_a (vars, 1);
	}
	else if (low->content->operacion == 8)
	{
		ft_rev_rot_ab(vars, 1);
		ft_rotate_b (vars, 1);
	}
}

void	ft_operations_1(t_vars *vars, t_list *low)
{
	if (low->content->operacion == 1)
	{
		ft_rotate_b(vars, 1);
		ft_rotate_ab(vars, 1);
	}
	else if (low->content->operacion == 2)
	{
		ft_rotate_ab(vars, 1);
		ft_rotate_a(vars, 1);
	}
	else if (low->content->operacion == 3)
	{
		ft_rotate_b_rev(vars, 1);
		ft_rev_rot_ab(vars, 1);
	}
	else if (low->content->operacion == 4)
	{
		ft_rev_rot_ab (vars, 1);
		ft_rotate_a_rev (vars, 1);
	}
	else if (low->content->operacion == 5)
	{
		ft_rotate_b(vars, 1);
		ft_rotate_a_rev(vars, 1);
	}
}

void	ft_push_lowcost(t_list *low, t_vars *vars)
{
	ft_operations_1(vars, low);
	ft_operations_2(vars, low);
	ft_rotatefin(low, vars);
	vars->temp_b = vars->list_b;
	vars->temp_a = vars->list_a;
	while (vars->list_b && vars->list_b != low)
	{
		ft_doble_rotate(low, vars);
		if (vars->list_b != low)
		{
			if (((t_data *)low->content)->rotate == 0)
				ft_rotate_b(vars, 1);
			else if (((t_data *)low->content)->rotate == 1)
				ft_rotate_b_rev(vars, 1);
		}
	}
	ft_correct_push(vars, low);
}

void	ft_find_lowcost(t_vars *vars)
{
	t_list	*temp_b;
	int		lowcost;	

	temp_b = vars->list_b;
	lowcost = INT_MAX;
	while (temp_b)
	{
		if (temp_b->content->cost < lowcost)
			lowcost = temp_b->content->cost;
		temp_b = temp_b->next;
	}
	temp_b = vars->list_b;
	while (1)
	{
		if (temp_b->content->cost == lowcost)
		{
			ft_push_lowcost(temp_b, vars);
			break ;
		}
		temp_b = temp_b->next;
	}
}
