#include "push_swap.h"
#include <unistd.h>
int main(int argc, char **argv)
{
	char *buff;
	buff = malloc(100);
	read(STDIN_FILENO, buff, 100);
	printf("%s\n", buff);
	if (argc > 2)
	{
		int	i;

	i = 1;
	while(argv[i])
	{
 		pars_string(vars, &argv[i][0]);
 		i++;
	}
	vars->last_list_a = ft_lstlast(vars->list_a);
	ft_lstiter(vars->list_a, ft_max_min);
	ft_algo(vars);
	vars->last_list_a = ft_lstlast(vars->list_a);
	
	}
}