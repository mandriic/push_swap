#include "push_swap.h"
void ft_intcopy(int *dest, const char *src)
{
	int i = -1;
	while (src[++i])
	{
		dest[i] = ft_atoi(&src[i]);
	}
}
void ft_print_int(int *arr)
{
	int i = 0;
	while (arr[i] != '\0')
		ft_printf("%d", arr[i++]);
}
void ft_pars(t_vars *vars)

{
	int i;
	int j = 0;
	int i2 = 0;
	i = 1;
	int len_subarr=0;
	vars->i_numarr = 0;
	
	while (vars->argv[i][j])
	{
		if(!ft_isdigit (vars->argv[i][j]) && vars->argv[i][j] != ' ' && vars->argv[i][j] != '-' && vars->argv[i][j] != '+')
			ft_error("nodigit");
		if(vars->argv[i][j] == ' ')
		{
			vars->sub_arr = ft_split_mod(vars->argv[i], ' ', vars->i_subarr);
			i++;
		}
		j++;
		if (vars->sub_arr)
		{
			len_subarr = ft_strlen(*(*vars->sub_arr));
			if (!vars->num_arr)
				vars->num_arr = malloc(sizeof(int *) * len_subarr + 1);
			vars->num_arr[len_subarr] = '\0';
			ft_intcopy(vars->num_arr, *vars->sub_arr);
			ft_print_int(vars->num_arr);
		}
	}

}
// 		j = 0;
// 		while (vars->argv[i][j])
// 		{
// 			if (vars->argv[i][j] == ' ')
// 			{
// 				vars->sub_arr= ft_split(vars->argv[i], ' ');
// 				break;
// 			}
// 			j++;
// 		}
// 		i2 = -1;
// 		if (vars->sub_arr)
// 		{
// 			while (vars->sub_arr[++i2])
// 				vars->num_arr[i2] = ft_atoi(vars->sub_arr[i2]);
// 		printf("%d\n", vars->num_arr[4]);
// 		printf("argc 	%d\n", argc);
// 		}

// 		else
// 		{
// 			vars->num_arr[i - 1] = ft_atoi(vars->argv[i]);
// 		}
// 	i++;
// 	vars->num_arr[argc - 1] = '\0';	
// 	}
