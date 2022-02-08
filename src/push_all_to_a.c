/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_all_to_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <mandriic@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:59:59 by mandriic          #+#    #+#             */
/*   Updated: 2022/02/08 12:00:02 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotatefin(t_list *low, t_vars *vars)
{
	t_list	*temp_b;
	int		size;
	int		count;

	count = 0;
	size = ft_lstsize(vars->list_b);
	temp_b = vars->list_b;
	while (temp_b != low)
	{
		count++;
		temp_b = temp_b->next;
	}
	if ((size / 2) >= count)
	low->content->rotate = 0;
	else
	low->content->rotate = 1;
}

void	ft_doble_rotate(t_list *low, t_vars *vars)
{
	while (vars->list_b != low && low->content->rot_b_go
		!= vars->list_a->content->num
		&& low->content->rotate == low->content->rot_a_go)
	{
		vars->last = ft_lstlast(vars->list_a);
		if ((vars->list_b->content->num < vars->list_a->content->num
				&& vars->list_b->content->num > vars->last->content->num)
			|| (vars->list_b->content->num > vars->temp_a->content->num
				&& vars->list_b->content->num
				< vars->list_a->next->content->num)
			|| (vars->list_a->content->num == *vars->list_a->content->min
				&& vars->last->content->num < low->content->num))
			break ;
		if (((t_data *)low->content)->rot_a_go == 0)
			ft_rotate_ab(vars, 1);
		else if (((t_data *)low->content)->rot_a_go == 1)
			ft_rev_rot_ab(vars, 1);
	}
}

void	ft_rotate_correct(t_vars *vars, t_list *low)
{
	int	size_a;

	size_a = ft_lstsize(vars->list_a);
	vars->last = ft_lstlast(vars->list_a);
	vars->count = 0;
	vars->temp_a = vars->list_a;
	while (vars->temp_a->next && vars->list_b)
	{
		if (((vars->list_b->content->num < vars->temp_a->content->num
					&& vars->list_b->content->num > vars->last->content->num)
				|| ((vars->list_b->content->num > vars->temp_a->content->num
						&& vars->list_b->content->num
						< vars->temp_a->next->content->num)
					&& vars->temp_a->content->num
					!= *vars->list_a->content->max)))
			break ;
		vars->temp_a = vars->temp_a->next;
		vars->count++;
	}
	if ((size_a / 2) >= vars->count)
		low->content->rot_a_go = 0;
	else
		low->content->rot_a_go = 1;
}

void	ft_correct_push(t_vars *vars, t_list *low)
{
	while (1)
	{
		ft_rotate_correct(vars, low);
		vars->last = ft_lstlast(vars->list_a);
		if ((vars->list_a->content->num == *vars->list_a->content->min
				&& vars->last->content->num < vars->list_b->content->num)
			|| (vars->list_b->content->num == *vars->list_a->content->max
				&& vars->list_a->content->num == *vars->list_a->content->min))
			break ;
		else if ((vars->list_b->content->num < vars->list_a->content->num
				&& vars->list_b->content->num > vars->last->content->num))
			break ;
		else if (vars->list_b->content->rot_a_go == 0)
			ft_rotate_a(vars, 1);
		else if (vars->list_b->content->rot_a_go == 1)
			ft_rotate_a_rev(vars, 1);
	}
	ft_push_b(vars, 1);
}
