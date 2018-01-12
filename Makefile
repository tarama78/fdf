# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 09:45:36 by tnicolas          #+#    #+#              #
#    Updated: 2018/01/11 16:10:36 by tnicolas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                      __      ___                             #
#                                      \ \    / (_)                            #
#                 ___  ___ _ __ __ _  __\ \  / / _ _ __ ___                    #
#                / __|/ _ \ '__/ _` |/ _ \ \/ / | | '_ ` _ \                   #
#                \__ \  __/ | | (_| |  __/\  /  | | | | | | |                  #
#                |___/\___|_|  \__, |\___| \/   |_|_| |_| |_|                  #
#                               __/ |                                          #
#                              |___/                                           #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FILES = main.c \
		lib/ft_set_coord.c \
		lib/ft_put_px.c \
		lib/ft_put_line.c \
		lib/ft_reset_win.c \
		lib/ft_print_win.c \
		init/ft_init_a.c \
		init/ft_check_error.c \
		init/ft_init_file.c \
		init/ft_set_cte.c \
		fdf/ft_key_event.c \
		fdf/ft_mouse_event.c \
		fdf/ft_error.c \
		fdf/ft_close.c \
		fdf/ft_print_result.c

HFILES = includes/fdf.h \
		 includes/fdf_struct.h

CC = gcc
CFLAGS = -Wall -Wextra -g ###############################################-Werror

INC_DIR = includes/ \
		  $(LIBFT_DIR)includes/ \
		  $(LIBFT_DIR)includes/ft_printf/ \
		  minilibx_macos/
SRCS_DIR = srcs/
OBJ_DIR = objs/

LIBFT_DIR = libft/
LIBFT_LIB = -L $(LIBFT_DIR) -lft
LIBX_DIR = minilibx_macos/
LIBX_LIB = -L $(LIBX_DIR) -lmlx -framework OpenGL -framework AppKit
#LIBX_LIB = -lmlx -framework OpenGL -framework AppKit

INC := $(addprefix -I , $(INC_DIR))
SRCS := $(addprefix $(SRCS_DIR), $(FILES))
OBJ := $(addprefix $(OBJ_DIR), $(FILES:.c=.o))

NORMAL = "\x1B[0m"
RED = "\x1B[31m"
GREEN = "\x1B[32m"
YELLOW = "\x1B[33m"
BLUE = "\x1B[34m"
MAGENTA = "\x1B[35m"
CYAN = "\x1B[36m"
WHITE = "\x1B[37m"

START = @printf $(GREEN)"FDF\n--------------------\n"$(NORMAL)
END = @printf $(GREEN)"--------------------\n"$(NORMAL)

all:
	@printf $(GREEN)"MINILIBX\n--------------------\n"$(YELLOW)
	@make -C $(LIBX_DIR)
	@printf $(GREEN)"\n--------------------\n"$(NORMAL)
	@make -C $(LIBFT_DIR)
	$(START)
	@make $(NAME)
	$(END)

$(NAME): $(OBJ_DIR) $(OBJ) $(LIBFT_DIR)libft.a $(LIBX_DIR)libmlx.a
	@printf $(CYAN)"-> create program : $(NAME)\n"$(NORMAL)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIBFT_LIB) $(LIBX_LIB)

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c $(HFILES) $(OBJ_DIR) $(LIBFT_DIR)libft.a $(LIBX_DIR)libmlx.a

	@printf $(YELLOW)"-> $<\n"$(NORMAL)
	@$(CC) -c $(INC) $< -o $@ $(CFLAGS)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $(OBJ))

clean:
	@make -C $(LIBFT_DIR) clean
	@printf $(GREEN)"MINILIBX\n--------------------\n"$(YELLOW)
	@make -C $(LIBX_DIR) clean
	@printf $(GREEN)"\n--------------------\n"$(NORMAL)
	$(START)
	@printf $(RED)"-x remove .o files\n"$(NORMAL)
	@rm -rf $(OBJ_DIR)
	$(END)

fclean: clean
	@make -C $(LIBFT_DIR) cleanlib
	@printf $(GREEN)"MINILIBX\n--------------------\n"$(YELLOW)
	@make -C $(LIBX_DIR) clean
	@printf $(GREEN)"\n--------------------\n"$(NORMAL)
	$(START)
	@printf $(RED)"-x remove $(NAME)\n"$(NORMAL)
	@rm -f $(NAME)
	$(END)

re: fclean all

exec:
	@clear
	@make all
	@printf $(MAGENTA)"EXEC FDF\n--------------------\n"$(NORMAL)
	@./fdf fdf_example/maps/42.fdf
	@printf $(MAGENTA)"--------------------\n"$(NORMAL)

reexec:
	@clear
	@make re
	@printf $(MAGENTA)"EXEC FDF\n--------------------\n"$(NORMAL)
	@./fdf fdf_example/maps/42.fdf
	@printf $(MAGENTA)"--------------------\n"$(NORMAL)

open:
	@vim +Line $(SRCS) $(HFILES) Makefile

norm:
	@printf $(BLUE)"NORME LIBFT\n--------------------\n"$(NORMAL)
	@norminette $(SRCS) $(HFILES)
	@printf $(BLUE)"--------------------\n"$(NORMAL)

.PHONY: all clean fclean re open norm
