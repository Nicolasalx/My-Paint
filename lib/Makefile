##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## lib_Makefile
##

SRCERROR	=	error/error_manager.c \
				error/error_declaration.c \
				error/my_puterror.c \
				error/my_exit.c \
				error/print_fatal_error_and_exit.c

SRCBITSHIFT	=	bit_shift/get_bit_value.c \
				bit_shift/set_all_bit_to_zero.c \
				bit_shift/set_bit_to_one.c \
				bit_shift/set_bit_to_zero.c

SRCFILE		=	file/count_nb_line.c \
				file/count_lines_size.c \
				file/my_file_to_str.c \
				file/my_filelen.c \
				file/open_file.c \
				file/is_a_dir.c

SRCLINKEDLIST=	linked_list/create_node.c \
				linked_list/append_node.c \
				linked_list/delete_node.c \
				linked_list/remove_node.c \
				linked_list/my_listlen.c \
				linked_list/insert_node.c

SRCGRAPHICAL=	graphical/animated_sprite.c \
				graphical/sprite.c \
				graphical/music.c \
				graphical/time.c \
				graphical/mouse_is_over.c \
				graphical/randint.c \
				graphical/texture.c

SRCMALLOC	=	malloc/my_malloc.c \
				malloc/malloc_board.c \
				malloc/free_board.c \
				malloc/malloc_str.c \
				malloc/my_str_to_board.c \
				malloc/malloc_array.c \
				malloc/my_str_to_word.c \
				malloc/malloc_adv_board.c \
				malloc/count_size_word.c \
				malloc/my_strdup.c \
				malloc/my_boarddup.c \
				malloc/my_adv_strcat.c \
				malloc/my_adv_strcpy.c \
				malloc/free_x.c

SRCCHAR		=	char/is_alpha.c \
				char/is_alphanum.c \
				char/is_digit.c \
				char/is_lower.c \
				char/is_upper.c

SRCNUMBER	=	number/my_pow.c \
				number/my_get_nb.c \
				number/get_min_value.c \
				number/get_max_value.c \
				number/count_nb_digit.c \
				number/my_swap.c \
				number/my_sort.c \
				number/my_put_array.c \
				number/my_put_nb.c \
				number/sum_array.c \
				number/my_nb_to_str.c \
				number/ini_array.c \
				number/my_put_double.c \
				number/my_abs.c \
				number/max_value.c \
				number/min_value.c

SRCSTRING	=	string/my_putstr.c \
				string/my_strcat.c \
				string/my_strcmp.c \
				string/my_strcpy.c \
				string/my_strlen.c \
				string/is_in_str.c \
				string/my_str_only_cont.c \
				string/my_str_cont_atleast.c \
				string/count_occur.c \
				string/count_nb_word.c \
				string/my_swap_char.c \
				string/my_revstr.c \
				string/my_putboard.c \
				string/my_putchar.c \
				string/ini_str_to_zero.c \
				string/my_strncmp.c \
				string/shift_str_to_left.c \
				string/my_boardlen.c \
				string/my_put_x_str.c

SRC			=	$(SRCGRAPHICAL) \
				$(SRCLINKEDLIST) \
				$(SRCMALLOC) \
				$(SRCCHAR) \
				$(SRCNUMBER) \
				$(SRCSTRING) \
				$(SRCFILE) \
				$(SRCBITSHIFT) \
				$(SRCERROR)

OBJ			=	$(SRC:.c=.o)

CFLAGS		=	-W -Wall -Wextra -I ../include -O2 -fno-builtin

LIBFLAG		=

NAME		=	my_lib.a

%.o : %.c
	@ gcc $(CFLAGS) -c $(LIBFLAG) $< -o $@ && \
	printf "gcc $(CFLAGS) -c $(LIBFLAG) $< -o $@ [\e[92mOK\e[0m]\n" || \
	printf "gcc $(CFLAGS) -c $(LIBFLAG) $< -o $@ [\e[91mKO\e[0m]\n"

$(NAME): $(OBJ)
	@ ar rc $(NAME) $(OBJ) && \
	printf "ar rc $(NAME) $(OBJ) [\e[92mLINKING OK\e[0m]\n" || \
	printf "ar rc $(NAME) $(OBJ) [\e[91mLINKING KO\e[0m]\n"

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

shared: LIBFLAG += -fPIC
shared: re clean
	gcc -shared -o $(NAME) $(OBJ)

std_func_used: shared
	@printf "\n------------| LIB |------------\e[1;96m\n"
	@symbols=$$(nm -D $(NAME) | awk '$$NF ~ /@GLIBC/ {print $$NF}'); \
	for symbol in $$symbols; do \
		if [[ "$$symbol" =~ ^__.* ]]; then \
			continue; \
		elif [ "$$symbol" = "puts@GLIBC_2.2.5" ]; then \
			printf "%s\e[0;1m <- \e[1;91mused in printf\e[1;96m\n" \
			"$${symbol%@*}"; \
		else \
			printf "%s\n" "$${symbol%@*}"; \
		fi; \
	done
	@printf "\e[0m-------------------------------\n\n"
	@rm -f $(NAME)

.PHONY: all clean fclean re shared std_func_used
