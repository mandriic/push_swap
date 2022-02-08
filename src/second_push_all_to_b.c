/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_push_all_to_b.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <mandriic@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:36:33 by mandriic          #+#    #+#             */
/*   Updated: 2022/02/08 21:36:40 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	ft_find_min2(t_list *temp_a, t_vars *vars)
{
	int		min2;

	vars->count = 0;
	min2 = INT_MAX;
	if (temp_a->content->num == *temp_a->content->min)
		return (*temp_a->content->min);
	while (temp_a && temp_a->content->num != *temp_a->content->min
		&& vars->count <= 30)
	{
		vars->last = ft_lstlast(temp_a);
		if (vars->last->content->num == *temp_a->content->max)
			vars->last = ft_lstpenlast(temp_a);
		if (!vars->last)
			break ;
		if (temp_a->content->num < min2 && temp_a->content->num
			> vars->last->content->num
			&& temp_a->content->num - vars->last->content->num < 100)
			min2 = temp_a->content->num;
		temp_a = temp_a->next;
		vars->count++;
	}
	if (min2 == *temp_a->content->max)
		return (INT_MAX);
	else
		return (min2);
}

void	ft_minmax(t_vars *vars)
{
	while (vars->list_a->content->num != *vars->list_a->content->max)
		ft_rotate_a(vars, 1);
	ft_push_a(vars, 1);
	while (vars->list_a->content->num != *vars->list_a->content->min)
		ft_rotate_a_rev(vars, 1);
	ft_push_b(vars, 1);
}

void	push_all_b(t_vars *vars)
{
	vars->last = ft_lstlast(vars->list_a);
	while (vars->list_a->content->num != *vars->list_a->content->min
		&& vars->last->content->num != *vars->list_a->content->min)
	{
		if (vars->list_a->content->num == *vars->list_a->content->max)
			ft_rotate_a(vars, 1);
		else
			ft_push_a(vars, 1);
	}
	if (vars->list_a->content->num == *vars->list_a->content->min)
		ft_rotate_a(vars, 1);
	while (vars->list_a->content->num != *vars->list_a->content->min)
	{
		vars->list_a->content->cost = 0;
		vars->list_a->content->operacion = 0;
		vars->min2 = ft_find_min2(vars->list_a, vars);
		if ((vars->list_a->content->num == vars->min2
				&& vars->list_a->content->num
				!= *vars->list_a->content->min) || vars->list_a->content->num
			== *vars->list_a->content->max)
			ft_rotate_a(vars, 1);
		else
			ft_push_a(vars, 1);
	}
	ft_minmax(vars);
}
