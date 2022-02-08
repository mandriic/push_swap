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



SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))

OBJECTS			= 	$(SOURCES:.c=.o)

NAME			=	push_swap

CC				=	gcc
RM				=	rm -f

CFLAGS			=	-Wall -Wextra -Werror

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)

$(NAME):		$(LIBFT) $(FT_PRINTF) $(OBJECTS) $(HEADER)
				$(CC) $(CFLAGS) $(LIBFT) $(FT_PRINTF) $(OBJECTS)  -o $(NAME)



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

