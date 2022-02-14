/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <mandriic@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:12:45 by mandriic          #+#    #+#             */
/*   Updated: 2022/02/08 12:12:48 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_error_fn(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	vars = (t_vars){};
	if (argc > 1)
	{
		ft_pars(&vars, argv);
	}
	return (0);
}

void	ft_pars(t_vars *vars, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		pars_string(vars, &argv[i][0]);
		i++;
	}
	ft_lstiter(vars->list_a, ft_max_min);
	ft_isrepite(vars);
	i = ft_lstsize(vars->list_a);
	if (i <= 5 && ft_check(vars->list_a) == 1)
		ft_five(vars);
	else
		ft_algo(vars);
}
