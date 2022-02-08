/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <mandriic@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:52:54 by mandriic          #+#    #+#             */
/*   Updated: 2022/02/08 11:53:00 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_max_min(void *data)
{
	if (*(int *)((t_data *)data)->max < ((int)((t_data *)data)->num))
	{
		*(int *)((t_data *)data)->max = (int)((t_data *)data)->num;
	}
	if (*(int *)((t_data *)data)->min > ((int)((t_data *)data)->num))
	{
		*(int *)((t_data *)data)->min = (int)((t_data *)data)->num;
	}
}

t_data	*ft_create_data(int num)
{
	t_data		*data;
	static int	min = 2147483647;
	static int	max = -2147483648;

	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	data->num = num;
	data->min = &min;
	data->max = &max;
	return (data);
}

int	ft_check_strting(char *string)
{
	int	i;

	i = -1;
	while (string[++i])
	{
		if (!ft_isdigit(string[i]) && string[i] != '+'
			&& string[i] != '-' && string[i] != ' ')
		{
			ft_error_fn("");
			exit(0);
		}
	}
	return (1);
}

void	pars_string(t_vars *vars, char *string)
{
	char	**temp_str;
	t_data	*data;

	vars->i = 0;
	temp_str = ft_split(string, ' ');
	while (1)
	{
		if (ft_check_strting(temp_str[vars->i]))
			vars->num = ft_atoi(&temp_str[vars->i][0]);
		free(temp_str[vars->i]);
		data = ft_create_data(vars->num);
		if (!vars->list_a)
			vars->list_a = ft_lstnew(((t_data *)data));
		else
		{
			vars->temp_tlist = ft_lstnew(((t_data *)data));
			ft_lstadd_back(&vars->list_a, vars->temp_tlist);
		}
		vars->i++;
		if (!temp_str[vars->i])
		{
			free(temp_str);
			break ;
		}
	}
}

void	ft_isrepite(t_vars *vars)
{
	t_list		*temp_a;
	t_list		*temp_a_sec;
	long long	num;

	temp_a = vars->list_a;
	while (temp_a)
	{
		temp_a_sec = vars->list_a;
		num = temp_a->content->num;
		while (temp_a_sec != temp_a && temp_a_sec)
		{
			if (temp_a->content->num == temp_a_sec->content->num
				|| num > INT_MAX)
				ft_error_fn("");
			temp_a_sec = temp_a_sec->next;
		}
		temp_a = temp_a->next;
	}
}
