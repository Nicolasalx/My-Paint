##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

MAIN_SRC	=	src/main.c \
				src/main_loop.c \
				src/manage_event.c \
				src/create_all_data.c \
				src/free_all_data.c

UI_SRC 		=	src/user_interface/ini_user_interface.c \
				src/user_interface/declaration_ui.c

COLOR_SRC	=	src/color_selection/ini_color_select.c \
				src/color_selection/declaration_button_color.c

HEADER_SRC	=	src/header/declaration_header.c \
				src/header/ini_button_header.c \
				src/header/declaration_file_header.c \
				src/toolbar/declaration_toolbar.c \
				src/toolbar/ini_toolbar.c \
				src/toolbar/declaration_icon.c \
				src/header/declaration_edit_header.c \
				src/header/declaration_view.c \
				src/header/declaration_layer.c \
				src/header/declaration_help.c

LAYER_SRC	=	src/layer/declaration_layer.c \
				src/layer/create_default_layer.c \
				src/layer/create_new_layer.c \
				src/layer/render_layer.c \
				src/layer/create_screen_shot.c

TOOL_SRC	=	src/tool/create_all_tool.c \
				src/tool/render_all_tool.c \
				src/tool/declaration_all_tool.c \
				src/tool/pencil/create_pencil.c \
				src/tool/pencil/render_pencil.c

SRC			=	$(MAIN_SRC) \
				$(UI_SRC) \
				$(COLOR_SRC) \
				$(HEADER_SRC) \
				$(LAYER_SRC) \
				$(TOOL_SRC)

CFLAGS		=	-W -Wall -Wextra -I ./include/lib -I ./include\
				-lcsfml-system -lcsfml-graphics \
				-lcsfml-window -lm

NAME		=	my_paint

LIBNAME		=	lib/my_lib.a

SRC_TESTS	=	tests/tests_interface.c \
				tests/tests.c

RUN_TEST	=	--coverage -lcriterion

NAME_TESTS	=	unit_tests

OBJ			=	$(SRC:.c=.o)

$(NAME): $(OBJ)
	cd lib/ && $(MAKE)
	gcc -o $(NAME) $(OBJ) $(LIBNAME) $(CFLAGS)

all: $(NAME)

clean:
	cd lib/ && $(MAKE) clean
	rm -f $(OBJ)
	rm -f *.gcno
	rm -f *.gcda
	rm -f gmon.out

fclean: clean
	cd lib/ && $(MAKE) fclean
	rm -f $(NAME)
	rm -f $(NAME_TESTS)

re: fclean all

unit_tests:	SRC := $(patsubst src/main.c%,%,$(SRC))
unit_tests: fclean
	cd lib/ && $(MAKE)
	gcc -o $(NAME_TESTS) $(SRC_TESTS) $(SRC) $(LIBNAME) $(CFLAGS) $(RUN_TEST)

tests_run: unit_tests
	./$(NAME_TESTS) --always-succeed --quiet

gcovr:
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

## ? USAGE : make profiling arg="arg_for_my_prog"
profiling: CFLAGS += -pg
profiling: re
	@printf "\e[0m------------------------------\e[0m\n"
	./$(NAME) $(arg)
	@printf "\e[0m------------------------------\e[0m\n"
	gprof $(NAME) gmon.out

debug: CFLAGS += -g3
debug: re
	gdb -ex "run" -ex "bt full" -ex "detach" -ex "quit" --args $(NAME) $(arg)

std_func_used:
	cd lib/ && $(MAKE) std_func_used
	$(MAKE) re
	@printf "\n----------| PROGRAM |----------\e[1;96m\n"
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

.PHONY: all clean fclean re unit_tests tests_run gcovr profiling debug \
	std_func_used
