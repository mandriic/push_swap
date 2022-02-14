#include "push_swap.h"
void ft_error(char *s)
{
	ft_printf("ERROR\n%s\n", s);
	exit(0);
}
int main(int argc, char const *argv[])
{
	t_vars vars;

	if (argc)
	{
		int i = 0;
		vars.argv = argv;
	//	printf("%s\n", vars.argv[1]);
		vars.sub_arr = NULL;
		
		ft_pars(&vars);
	//	printf("%d\n", vars.num_arr[0]);
		return (0);
	}
}