# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabduvak <aabduvak@42ISTANBUL.COM.TR>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 16:23:46 by aabduvak          #+#    #+#              #
#    Updated: 2022/08/27 04:47:16 by aabduvak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors

BLACK			=	"\033[0;30m"
RED				=	"\033[0;31m"
GREEN			=	"\033[0;32m"
YELLOW			=	"\033[0;33m"
CYAN			=	"\033[0;35m"
BLUE			=	"\033[0;36m"
WHITE			=	"\033[0;37m"
END				=	"\033[0;0m"

# Files

SRCS			= $(shell find sources -type f -name "*.c")
OBJS			= $(SRCS:sources/%.c=sources/bin/%.o)

# Command and Flags

NAME			= cub3D
CC				= gcc
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror
LIBFT			= ./libft/libft.a
MINILIBX		= ./lib/minilibx/libmlx.a

# Directories

INC_FT			= ./libft/sources
INC_GN			= ./libft/GNL/sources
INC_PR			= ./libft/ft_printf/sources
INC_MX			= ./lib/minilibx/mlx.h
INC				= ./includes/
BIN				= ./sources/bin/
LIB				= ./lib/.$(NAME)

# Operating System

GET_OS := $(shell uname -s)

ifeq ($(GET_OS), Darwin)
	OS			= MACOS
	FRAMEWORK	= -framework OpenGL -framework AppKit
	LFLAGS		= -I./includes
else
	OS			= LINUX
	FRAMEWORK	= -L./lib/minilibx -l./lib/minilibx -L/usr/lib -I./lib/minilibx -lXext -lX11 -lm -lz
	LFLAGS		= -I/usr/include -O3	
endif

# Rules

all : $(LIB) $(LIBFT) $(NAME)

$(LIBFT):
	@make -C ./libft

$(LIB):
	@make -C ./lib

$(BIN):
	@mkdir $(BIN)

$(BIN)%.o: sources/%.c
	@mkdir -p $(shell dirname $@)
	@echo $(YELLOW) "Compiling..." $< $(END)
	@$(CC) $(CFLAGS) $(LFLAGS) -c $< -o $@ -I$(INC_PR) -I$(INC_GN) -I$(INC_FT) -I$(INC)

$(NAME): $(BIN) $(OBJS)
	@echo $(YELLOW) "Building... $(NAME)" $(END)
	@$(CC) $(OBJS) $(FRAMEWORK) -o $(NAME) $(LIBFT) $(MINILIBX)
	@echo $(GREEN) "$(NAME) created successfully!\n" $(END)

# $< input files
# $@ output files
# in makefile used to create oputput files in their subfolder

clean :
	@echo $(YELLOW) "Removing object files...$(NAME)" $(END)
	@$(RM) $(OBJS)
	@echo $(RED) "All files deleted successfully!\n" $(END)

fclean : clean
	@echo $(YELLOW) "Removing $(NAME)..." $(END)
	@$(RM) $(NAME)
	@$(RM) $(BIN)
	@echo $(RED) "$(NAME) deleted successfully!\n" $(END)

ffclean: fclean
	@make fclean -C ./libft

fffclean: ffclean
	@make fclean -C ./lib

norm :
	@norminette libft/
	@norminette includes/
	@norminette sources

re : ffclean all

run : $(NAME)
	@./$(NAME) game.cub

test :
	@./maps/map_test.sh

help :
	@echo "------------------------------------ <<HELP COMMAND>> ------------------------------------"
	@echo ""
	@echo "make            --------- compiles all *.c files and create libftprintf.a library"
	@echo "make clean      --------- cleans all *.o files in sources"
	@echo "make fclean 	   --------- cleans all *.o files in sources and libftprintf.a library"
	@echo "make re         --------- cleans all files and compiles again"
	@echo "make norm       --------- controls all *.c and *.h codes to norminette standart"
	@echo "make run        --------- compile and run program"
	@echo "make leaks      --------- checks all leaks in the program and creates output.file"

.PHONY: all clean fclean re run
