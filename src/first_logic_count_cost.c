/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_logic_count_cost.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <mandriic@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:33:18 by mandriic          #+#    #+#             */
/*   Updated: 2022/02/08 11:33:22 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_algo(t_vars *vars)
{
	t_list	*temp_b;
	int		check;
	int		size;
	int		i;

	temp_b = vars->list_b;
	check = ft_check(vars->list_a);
	if (check == 1)
		push_all_b(vars);
	while (vars->list_b)
	{	
		i = -1;
		while (++i < 9 && size != 2)
		{
			vars->oper = i;
			ft_count_opt(vars);
			size = ft_lstsize(vars->list_b);
		}
		if (size == 2)
			ft_costs(vars);
		ft_find_lowcost(vars);
		temp_b = vars->list_b;
		ft_define_vars(temp_b);
	}
	ft_low2first(vars->list_a, vars);
}

void	ft_sub_count_cost(t_vars *vars)
{
	if (vars->count % 2 == 1)
	{
		vars->temp_a->content->cost_temp = vars->i;
		vars->temp_a = vars->temp_a->next;
	}
	while (1)
	{
		vars->temp_a->content->cost_temp = vars->i--;
		if (!vars->temp_a->next)
		{
			vars->flag = 0;
			break ;
		}
		vars->temp_a = vars->temp_a->next;
	}
}

void	ft_count_cost(t_list *list, t_vars *vars)
{
	vars->i = 0;
	vars->temp_a = list;
	vars->flag = 1;
	vars->count = ft_lstsize(list);
	while (vars->flag && vars->temp_a && vars->temp_a->next)
	{
		vars->temp_a->content->cost_temp = vars->i;
		if (vars->temp_a->next && (vars->count / 2) == vars->i)
		{
			ft_sub_count_cost(vars);
		}
		vars->i++;
		vars->temp_a = vars->temp_a->next;
	}
}

void	ft_costs(t_vars *vars)
{
	ft_count_cost(vars->list_a, vars);
	ft_count_cost(vars->list_b, vars);
	ft_count_cost_sum(vars->list_a, vars->list_b, vars);
}
