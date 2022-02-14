NAME = libpr_f.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC = 	./ft_printf_mod.c \
		./ft_num_to_base_mod.c\
		./ft_putchar_mod.c\
		./ft_print_string_mod.c\
		./ft_parsing_mod.c\
		./ft_pointer_mod.c\
		./ft_dec_ent_mod.c\
		./ft_itoa_mod.c\
		./ft_unsign_mod.c\
		./ft_strlen_mod.c\
		./ft_hex_low_mod.c\
		./ft_hex_high_mod.c

OBJ = $(SRC:%.c=%.o)
all: $(NAME)

$(NAME): $(OBJ) ft_printf.h
	ar rcs $(NAME) $(OBJ)
$(OBJ): $(SRC)
	$(CC) $(FLAGS) -c $(SRC)
clean:
	rm -f $(OBJ) $(BOBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all