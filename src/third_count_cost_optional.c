/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_count_cost_optional.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <mandriic@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:52:08 by mandriic          #+#    #+#             */
/*   Updated: 2022/02/08 21:52:12 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_count_opt3(t_vars *vars)
{
	if (vars->oper == 6)
	{
		ft_rotate_b_rev(vars, 0);
		ft_rotate_a (vars, 0);
		ft_costs(vars);
		ft_rotate_b(vars, 0);
		ft_rotate_a_rev(vars, 0);
	}
	if (vars->oper == 7)
	{
		ft_rev_rot_ab(vars, 0);
		ft_rotate_a (vars, 0);
		ft_costs(vars);
		ft_rotate_a_rev(vars, 0);
		ft_rotate_ab(vars, 0);
	}
	if (vars->oper == 8)
	{
		ft_rev_rot_ab(vars, 0);
		ft_rotate_b (vars, 0);
		ft_costs(vars);
		ft_rotate_b_rev(vars, 0);
		ft_rotate_ab(vars, 0);
	}
}

void	ft_count_opt2(t_vars *vars)
{
	if (vars->oper == 3)
	{
		ft_rotate_b_rev(vars, 0);
		ft_rev_rot_ab(vars, 0);
		ft_costs(vars);
		ft_rotate_b(vars, 0);
		ft_rotate_ab(vars, 0);
	}
	if (vars->oper == 4)
	{
		ft_rev_rot_ab (vars, 0);
		ft_rotate_a_rev (vars, 0);
		ft_costs(vars);
		ft_rotate_ab(vars, 0);
		ft_rotate_a(vars, 0);
	}
	if (vars->oper == 5)
	{
		ft_rotate_b(vars, 0);
		ft_rotate_a_rev(vars, 0);
		ft_costs(vars);
		ft_rotate_b_rev(vars, 0);
		ft_rotate_a(vars, 0);
	}
}

void	ft_count_opt(t_vars *vars)
{
	vars->corr = 0;
	if (vars->oper > 0)
		vars->corr = 2;
	if (vars->oper == 0)
		ft_costs(vars);
	if (vars->oper == 1)
	{
		ft_rotate_b(vars, 0);
		ft_rotate_ab(vars, 0);
		ft_costs(vars);
		ft_rotate_b_rev(vars, 0);
		ft_rev_rot_ab(vars, 0);
	}
	if (vars->oper == 2)
	{
		ft_rotate_ab(vars, 0);
		ft_rotate_a(vars, 0);
		ft_costs(vars);
		ft_rev_rot_ab(vars, 0);
		ft_rotate_a_rev(vars, 0);
	}
	ft_count_opt2(vars);
	ft_count_opt3(vars);
}
