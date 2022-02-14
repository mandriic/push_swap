#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include <stdio.h>

typedef struct t_list 
{
	const char **argv;
	char **sub_arr;
	int *num_arr;
	int i_numarr;
	int i_subarr;

}t_vars;
void ft_pars(t_vars *vars);
void ft_error(char *s);

#endif