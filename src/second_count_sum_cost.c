/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_count_sum_cost.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <mandriic@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:23:54 by mandriic          #+#    #+#             */
/*   Updated: 2022/02/08 21:23:58 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_pars_cost_1(t_vars *vars, t_list *temp_a, t_list *temp_b, int count)
{
	if (temp_b->content->cost == -1)
	{
		temp_b->content->cost = temp_b->content->cost_temp + vars->corr;
		ft_find_rotate(vars, temp_b, count);
		temp_b->content->rot_b_go = temp_a->content->num;
		temp_b->content->operacion = vars->oper;
	}
	else if (temp_b->content->cost > temp_b->content->cost_temp
		+ temp_a->content->cost_temp + vars->corr)
	{
		temp_b->content->cost = temp_b->content->cost_temp
			+ temp_a->content->cost_temp + vars->corr;
		ft_find_rotate(vars, temp_b, count);
		temp_b->content->operacion = vars->oper;
		temp_b->content->rot_b_go = temp_a->content->num;
	}
	vars->flag = 1;
}

void	ft_pars_cost_2(t_vars *vars, t_list *temp_a, t_list *temp_b, int count)
{
	if (temp_b->content->cost == -1)
	{
		temp_b->content->cost = temp_b->content->cost_temp
			+ temp_a->content->cost_temp + vars->corr;
		temp_b->content->rot_a_go = 0;
		if (temp_a->next->next == vars->last)
		{
			temp_b->content->cost = temp_b->content->cost
				+ temp_a->next->content->cost;
			temp_b->content->rot_a_go = 1;
			temp_b->content->rot_b_go = temp_a->content->num;
		temp_b->content->operacion = vars->oper;
		}
		temp_b->content->operacion = vars->oper;
	}
	else if (temp_b->content->cost > temp_b->content->cost_temp
		+ temp_a->content->cost_temp + vars->corr)
	{	
		temp_b->content->cost = temp_b->content->cost_temp
			+ temp_a->content->cost_temp + vars->corr;
		temp_b->content->operacion = vars->oper;
		ft_find_rotate(vars, temp_b, count);
	}
	temp_b->content->rot_b_go = temp_a->content->num;
	vars->flag = 1;
}

void	ft_pars_cost_3(t_vars *vars, t_list *temp_a, t_list *temp_b, int count)
{
	if (temp_b->content->cost == -1)
	{
		temp_b->content->cost = (temp_b->content->cost_temp
				+ temp_a->next->content->cost_temp + vars->corr);
		ft_find_rotate(vars, temp_b, count);
		temp_b->content->rot_b_go = temp_a->content->num;
		temp_b->content->operacion = vars->oper;
	}
	else if (temp_b->content->cost > (temp_b->content->cost_temp
			+ temp_a->next->content->cost_temp + vars->corr))
	{	
		temp_b->content->cost = (temp_b->content->cost_temp
				+ temp_a->next->content->cost_temp + vars->corr);
		ft_find_rotate(vars, temp_b, count);
		temp_b->content->operacion = vars->oper;
		vars->flag = 1;
	}
	temp_b->content->rot_b_go = temp_a->content->num;
}

void	ft_pars_cost_root(t_vars *vars, t_list *list_a)
{
	if (vars->temp_a->content->num == *list_a->content->min
		&& vars->temp_b->content->num > vars->last->content->num)
		ft_pars_cost_1(vars, vars->temp_a, vars->temp_b, vars->i);
	else if (vars->temp_b->content->num < vars->temp_a->content->num
		&& vars->temp_b->content->num > vars->last->content->num)
		ft_pars_cost_2(vars, vars->temp_a, vars->temp_b, vars->i);
	else if (vars->temp_b->content->num > vars->temp_a->content->num
		&& vars->temp_b->content->num
		< vars->temp_a->next->content->num)
		ft_pars_cost_3(vars, vars->temp_a, vars->temp_b, vars->i);
}

void	ft_count_cost_sum(t_list *list_a, t_list *list_b, t_vars *vars)
{
	vars->corr = 0;
	if (vars->oper > 0)
		vars->corr = 2;
	vars->temp_b = list_b;
	vars->last = ft_lstlast(vars->list_a);
	while (vars->temp_b)
	{
		vars->i = 0;
		vars->temp_a = list_a;
		vars->flag = 0;
		while (vars->temp_a && vars->flag != 1 && vars->temp_a->next)
		{
			if (vars->temp_b->content->num == *list_a->content->max)
				ft_find_rotate(vars, vars->temp_b, vars->i);
			ft_pars_cost_root(vars, list_a);
			vars->i++;
				vars->temp_a = vars->temp_a->next;
		}
		vars->temp_b = vars->temp_b->next;
	}
}
