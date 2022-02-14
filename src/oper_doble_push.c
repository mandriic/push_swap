/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_doble_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <mandriic@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:41:09 by mandriic          #+#    #+#             */
/*   Updated: 2022/02/08 11:41:17 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_push_a(t_vars *vars, int prnt)
{
	vars->temp_b = NULL;
	vars->temp_a = vars->list_a;
	if (vars->list_b && vars->list_a && vars->list_a->next)
	{
		vars->temp_b = vars->list_b;
		vars->list_a = vars->list_a->next;
		vars->list_b = vars->temp_a;
		vars->list_b->next = vars->temp_b;
	}
	else if (vars->list_b && vars->list_a->next == NULL)
	{
		vars->temp_b = vars->list_b;
		vars->list_b = vars->temp_a;
		vars->list_b->next = vars->temp_b;
		vars->list_a = NULL;
	}
	else
	{
		vars->list_a = vars->temp_a->next;
		vars->list_b = vars->temp_a;
		vars->list_b->next = NULL;
	}
	if (prnt == 1)
		ft_printf("pb\n");
}

void	ft_push_b(t_vars *vars, int prnt)
{
	vars->temp_a = NULL;
	vars->temp_b = vars->list_b;
	if (vars->list_a && vars->list_b && vars->list_b->next == NULL)
	{
		vars->temp_a = vars->list_a;
		vars->list_a = vars->temp_b;
		vars->list_a->next = vars->temp_a;
		vars->list_b = NULL;
	}
	else if (vars->list_b && vars->list_b->next != NULL)
	{
		vars->temp_a = vars->list_a;
		vars->list_b = vars->list_b->next;
		vars->list_a = vars->temp_b;
		vars->list_a->next = vars->temp_a;
	}
	else
	{
		vars->list_b = vars->temp_b->next;
		vars->list_a = vars->temp_b;
		vars->list_a->next = NULL;
	}
	if (prnt == 1)
		ft_printf("pa\n");
}

void	ft_rev_rot_ab(t_vars *vars, int prnt)
{
	ft_rotate_a_rev(vars, 0);
	ft_rotate_b_rev(vars, 0);
	if (prnt == 1)
		ft_printf("rrr\n");
}

void	ft_rotate_ab(t_vars *vars, int prnt)
{
	ft_rotate_a(vars, 0);
	ft_rotate_b(vars, 0);
	if (prnt == 1)
		ft_printf("rr\n");
}
