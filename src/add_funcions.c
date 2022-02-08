/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_funcions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <mandriic@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:27:29 by mandriic          #+#    #+#             */
/*   Updated: 2022/02/08 11:27:32 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_rotate(t_vars *vars, t_list *temp_b, int count)
{
	int	size_a;

	size_a = ft_lstsize(vars->list_a);
	if ((size_a / 2) >= count)
		((t_data *)temp_b->content)->rot_a_go = 0;
	else
		((t_data *)temp_b->content)->rot_a_go = 1;
}

void	ft_low2first(t_list *list_a, t_vars *vars)
{
	int		count;
	int		size;
	t_list	*temp_a;

	size = ft_lstsize(list_a);
	count = 0;
	temp_a = vars->list_a;
	while (temp_a->content->num != *vars->list_a->content->min)
	{
		count++;
		temp_a = temp_a->next;
	}
	temp_a = list_a;
	while (vars->list_a->content->num != *temp_a->content->min)
	{
		if ((size / 2) <= count)
			ft_rotate_a_rev(vars, 1);
		else
			ft_rotate_a(vars, 1);
	}
}

int	ft_check(t_list *temp_a)
{
	int	len;
	int	count;

	len = ft_lstsize(temp_a);
	count = 1;
	while (temp_a->next)
	{
		if (temp_a->content->num < temp_a->next->content->num)
			temp_a = temp_a->next;
		else
			return (1);
		count++;
	}
	if (count == len)
		return (0);
	return (1);
}

void	ft_define_vars(t_list *temp_b)
{
	while (temp_b)
	{
		temp_b->content->cost = -1;
		temp_b->content->cost_temp = 0;
		temp_b->content->operacion = 0;
		temp_b = temp_b->next;
	}
}
