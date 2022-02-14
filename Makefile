LIBFT_PATH		=	libft
LIBFT			=	$(LIBFT_PATH)/libft.a

PRINTF_PATH		=	ft_printf
FT_PRINTF		=	$(PRINTF_PATH)/libpr_f.a

SOURCES_DIR		= 	./src
SOURCES_FILES	=	push_swap.c\
					parsing.c\
					first_logic_count_cost.c\
					second_count_sum_cost.c\
					second_push_all_to_b.c\
					third_count_cost_optional.c\
					third_find_lowcost.c\
					push_all_to_a.c\
					add_funcions.c\
					low_nums.c\
					oper_swap.c\
					oper_rot_revrot.c\
					oper_doble_push.c\

SRC_DIR_BONUS	= 	./bonus
SRC_FILES_BONUS	=	checker.c\
					oper_doble_push_bonus.c\
					oper_rot_revrot_bonus.c\
					oper_swap_bonus.c\
					../get_next_line/get_next_line.c\
					../get_next_line/get_next_line_utils.c\
					checker_util.c\

SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))
SOURCES_BONUS	=	$(addprefix $(SRC_DIR_BONUS)/, $(SRC_FILES_BONUS))

OBJECTS			= 	$(SOURCES:.c=.o)
OBJECTS_BONUS	= 	$(SOURCES_BONUS:.c=.o)

NAME			=	push_swap
NAME_BONUS		=	checker

CC				=	gcc
RM				=	rm -f

CFLAGS			=	-Wall -Wextra -Werror

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)
bonus:			$(NAME_BONUS)

$(NAME):		$(LIBFT) $(FT_PRINTF) $(OBJECTS)
				$(CC) $(CFLAGS) $(LIBFT) $(FT_PRINTF) $(OBJECTS)  -o $(NAME)

$(NAME_BONUS):	$(LIBFT) $(FT_PRINTF) $(OBJECTS_BONUS) 
				$(CC) $(CFLAGS) $(LIBFT) $(FT_PRINTF) $(OBJECTS_BONUS)   -o $(NAME_BONUS)


$(LIBFT):
				$(MAKE) -C $(LIBFT_PATH)

$(FT_PRINTF):
				$(MAKE) -C $(PRINTF_PATH)

clean:
				$(MAKE) -C $(LIBFT_PATH) clean
				$(MAKE) -C $(PRINTF_PATH) clean
				$(RM) $(OBJECTS)

fclean:			clean
				$(MAKE) -C $(LIBFT_PATH) fclean
				$(RM) $(NAME)

re:				fclean all

clean_bonus:
				$(MAKE) -C $(LIBFT_PATH) clean
				$(MAKE) -C $(PRINTF_PATH) clean
				$(RM) $(OBJECTS_BONUS)

fclean_bonus:	clean_bonus
				$(MAKE) -C $(LIBFT_PATH) fclean
				$(RM) $(NAME_BONUS)

re_bonus:		fclean_bonus bonus

