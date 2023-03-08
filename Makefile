##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

MAIN_SRC	=	src/main/main.c \
				src/main/main_loop.c \
				src/main/update_window_data.c \
				src/main/manage_event.c \
				src/main/create_all_data.c \
				src/main/free_all_data.c

UI_SRC 		=	src/user_interface/ini/ini_user_interface.c \
				src/user_interface/ini/declaration_ui.c \
				src/user_interface/render/display_ui.c

COLOR_SRC	=	src/color_selection/ini/ini_color_select.c \
				src/color_selection/ini/declaration_button_color.c \
				src/color_selection/render/interaction_tool_color.c

TOOL_BAR_SRC= 	src/toolbar/ini/declaration_toolbar.c \
				src/toolbar/ini/ini_toolbar.c \
				src/toolbar/ini/declaration_icon.c \
				src/toolbar/render/size_pen.c \
				src/toolbar/render/display_toolbar.c

HEADER_SRC	=	src/header/ini/declaration/declaration_header.c \
				src/header/ini/initialisation/ini_button_header.c \
				src/header/ini/declaration/declaration_file_header.c \
				src/header/ini/declaration/declaration_edit_header.c \
				src/header/ini/declaration/declaration_view.c \
				src/header/ini/declaration/declaration_layer.c \
				src/header/ini/declaration/declaration_help.c \
				src/header/render/interaction_file_button.c \
				src/header/render/interaction_edit_button.c \
				src/header/render/interaction_view_button.c \
				src/header/render/interaction_layer_button.c \
				src/header/render/interaction_help_button.c \
				src/header/render/interaction_header_all_button.c \
				src/header/ini/initialisation/ini_button_file.c \
				src/header/ini/initialisation/ini_button_edit.c \
				src/header/ini/initialisation/ini_button_view.c \
				src/header/ini/initialisation/ini_button_layer.c \
				src/header/ini/initialisation/ini_button_help.c

UI_LAYER_SRC=	src/ui_layer/declaration_layer.c \
				src/ui_layer/ini_layer.c

LAYER_SRC	=	src/layer/ini/declaration_layer.c \
				src/layer/ini/create_default_layer.c \
				src/layer/ini/create_new_layer.c \
				src/layer/render/render_layer.c \
				src/layer/ini/create_screen_shot.c \
				src/layer/render/render_background.c \
				src/layer/render/render_overview.c \
				src/layer/ini/create_layer_name.c

UI_LAYER_SRC=	src/ui_layer/ini/declaration_layer.c \
				src/ui_layer/ini/layer_box.c \
				src/ui_layer/ini/eye_sprite.c

TOOL_SRC	=	src/tool/create_all_tool.c \
				src/tool/render_all_tool.c \
				src/tool/declaration_all_tool.c \
				src/tool/pencil/create_pencil.c \
				src/tool/pencil/render_pencil.c \
				src/tool/eraser/create_eraser.c \
				src/tool/eraser/render_eraser.c \
				src/tool/brush/create_brush.c \
				src/tool/brush/render_brush.c \
				src/tool/feather_pen/create_feather_pen.c \
				src/tool/feather_pen/render_feather_pen.c \
				src/tool/hand/render_hand.c

UNDO_REDO_SRC=	src/undo_redo/ini/declaration_icon.c \
				src/undo_redo/ini/ini_undo_redo.c \
				src/undo_redo/render/display_icon.c

IMAGE_SRC	=	src/image/import_image.c \
				src/image/export_image.c \
				src/image/load_image.c

SRC			=	$(MAIN_SRC) \
				$(UI_SRC) \
				$(COLOR_SRC) \
				$(HEADER_SRC) \
				$(LAYER_SRC) \
				$(UI_LAYER_SRC) \
				$(TOOL_SRC) \
				$(TOOL_BAR_SRC) \
				$(UNDO_REDO_SRC) \
				$(IMAGE_SRC)

CFLAGS		=	-W -Wall -Wextra -I ./include/lib -I ./include \
				-lcsfml-system -lcsfml-graphics \
				-lcsfml-window

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
