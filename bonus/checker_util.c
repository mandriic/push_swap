/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <mandriic@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:03:16 by mandriic          #+#    #+#             */
/*   Updated: 2022/02/09 15:03:20 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap_bonus.h"
#include <unistd.h>

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
				ft_error_fn();
			temp_a_sec = temp_a_sec->next;
		}
		temp_a = temp_a->next;
	}
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
			ft_error_fn();
			exit(0);
		}
		if (string[i] == '+' || string[i] == '-')
		{
			if (string[i + 1] == '+' || string[i + 1] == '-' || !string[i + 1])
			{
				ft_error_fn();
				exit(0);
			}
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

void	ft_pars(t_vars *vars, char **argv)
{
	int	i;

	i = 1;
	if (!argv[i][0])
	{
		ft_error_fn();
	}
	while (argv[i] && argv[i][0])
	{
		pars_string(vars, &argv[i][0]);
		i++;
	}
	ft_isrepite(vars);
	i = ft_lstsize(vars->list_a);
	rotate_all(vars);
}
