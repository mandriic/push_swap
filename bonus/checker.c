/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <mandriic@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:52:36 by mandriic          #+#    #+#             */
/*   Updated: 2022/02/09 14:52:39 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap_bonus.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc > 1)
	{	
		vars = (t_vars){};
		if (argc > 1)
		{
			ft_pars(&vars, argv);
		}
		if (!ft_check(vars.list_a))
			printf("%s\n", "OK");
		else
			printf("%s\n", "KO" );
	}
	return (0);
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

void	ft_error_fn(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_rotate_all_2(t_vars *vars)
{
	if (vars->check_str[0] == 'r' && vars->check_str[1] == 'b')
		ft_rotate_b(vars, 0);
	else if (vars->check_str[0] == 'r' && vars->check_str[1] == 'r'
		&& vars->check_str[2] == 'r')
		ft_rev_rot_ab(vars, 0);
	else if (vars->check_str[0] == 'r' && vars->check_str[1] == 'r')
		ft_rotate_ab(vars, 0);
	else if (vars->check_str[0] == 'p' && vars->check_str[1] == 'b')
		ft_push_a(vars, 0);
	else if (vars->check_str[0] == 'p' && vars->check_str[1] == 'a')
		ft_push_b(vars, 0);
}

void	rotate_all(t_vars *vars)
{
	while (1)
	{
		vars->check_str = get_next_line(0);
		if (!vars->check_str)
			break ;
		if (vars->check_str[0] == 'r' && vars->check_str[1]
			=='r' && vars->check_str[2] == 'a')
			ft_rotate_a_rev(vars, 0);
		else if (vars->check_str[0] == 'r' && vars->check_str[1] == 'r'
			&& vars->check_str[2] == 'b')
			ft_rotate_b_rev(vars, 0);
		else if (vars->check_str[0] == 's' && vars->check_str[1] == 'a')
			ft_swap_a(vars, 0);
		else if (vars->check_str[0] == 's' && vars->check_str[1] == 'b')
			ft_swap_b(vars, 0);
		else if (vars->check_str[0] == 'r' && vars->check_str[1] == 'a')
			ft_rotate_a(vars, 0);
		else
			ft_rotate_all_2(vars);
	}
}
