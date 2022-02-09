/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <mandriic@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:15:15 by mandriic          #+#    #+#             */
/*   Updated: 2022/02/08 12:15:20 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "./push_swap_bonus.h"
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>
# define BUFFER_SIZE 1

typedef struct s_vars
{
	t_list	*list_a;
	t_list	*list_b;
	t_list	*last_list_a;
	t_list	*last_list_b;
	t_list	*temp_tlist;
	t_list	*temp_a;
	t_list	*temp_b;
	t_list	*last;
	int		oper;
	int		corr;
	int		flag;
	int		i;
	int		num;
	int		count;
	int		a;
	int		a_n;
	int		b;
	int		c;
	int		lst;
	int		min;
	int		min2;
	int		size;
	char	*check_str;
}t_vars;
void	ft_rotate_all_2(t_vars *vars);
t_data	*ft_create_data(int num);	
void	ft_print_all_num(t_list *lst, char *str);
void	rotate_all(t_vars *vars);
char	*ft_strjoin_mod(char *s1, char *s2);
char	*ft_strdup_mod(char *s, int check);
int		ft_strchr_mod(const char *s, char c);
int		ft_strlen_mod(const char *s);
void	ft_correct_push(t_vars *vars, t_list *low);
void	ft_doble_rotate(t_list *low, t_vars *vars);
void	ft_rotatefin(t_list *low, t_vars *vars);
void	ft_find_lowcost(t_vars *vars);
void	ft_low2first(t_list *list_a, t_vars *vars);
void	ft_define_vars(t_list *temp_b);
void	ft_costs(t_vars *vars);
void	ft_find_rotate(t_vars *vars, t_list *temp_b, int count);
void	ft_find_rotate(t_vars *vars, t_list *temp_b, int count);
void	ft_five(t_vars *vars);
void	ft_count_opt(t_vars *vars);
void	push_all_b(t_vars *vars);
void	ft_count_cost_sum(t_list *list_a, t_list *list_b, t_vars *vars);
void	ft_max_min(void *data);
void	ft_max_min(void *data);
void	pars_string(t_vars *vars, char *string);
t_list	*ft_lstpenlast(t_list *lst);
void	ft_isrepite(t_vars *vars);
void	ft_rotate_ab(t_vars *vars, int prnt);
void	ft_rev_rot_ab(t_vars *vars, int prnt);
void	ft_count_cost_sum(t_list *list_a, t_list *list_b, t_vars *vars);
void	ft_rotate_a_rel(t_list *list);
void	ft_rotate_b_rel(t_list *list);
void	ft_rot_a_rev_rel(t_list *list);
void	ft_rot_b_rev_rel(t_list *list);
void	ft_push_a_rel(t_list *list);
void	ft_push_b_rel(t_list *list);
void	ft_rev_rot_ab_rel(t_list *temp_a, t_list *temp_b);
void	ft_rotate_ab_rel(t_list *temp_a, t_list *temp_b);
int		ft_check(t_list *temp_a);
void	ft_find_lowcost(t_vars *vars);
void	ft_swap_b(t_vars *vars, int prnt);
void	ft_algo(t_vars *vars);
void	ft_rotate_b_rev(t_vars *vars, int prnt);
void	ft_rotate_b(t_vars *vars, int prnt);
void	ft_push_b(t_vars *vars, int prnt);
void	ft_push_a(t_vars *vars, int prnt);
void	ft_rotate_a_rev(t_vars *vars, int prnt);
void	ft_print_all_num(t_list *lst, char *str);
void	ft_print_all(t_list *lst);
void	ft_rotate_a(t_vars *vars, int prnt);
void	ft_swap_a(t_vars *vars, int prnt);
void	ft_pars(t_vars *vars, char **argv);
void	ft_error_fn(void);

#endif
