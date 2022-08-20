# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 07:59:14 by aabduvak          #+#    #+#              #
#    Updated: 2022/08/20 00:25:39 by aabduvak         ###   ########.fr        #
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

GET_OS := $(shell uname -s)

ifeq ($(GET_OS), Darwin)
	OS			=		MACOS
	LINK		=		https://projects.intra.42.fr/uploads/document/document/9232/minilibx_opengl.tgz
	ARCHIEVE	=		minilibx_opengl.tgz
	FOLDER		=		minilibx_opengl_20191021
else
	OS			=		LINUX
	LINK		=		https://projects.intra.42.fr/uploads/document/document/9225/minilibx-linux.tgz
	ARCHIEVE	=		minilibx-linux.tgz
	FOLDER		=		minilibx-linux
endif

DIR				= $(shell echo $(PWD))
RM				= rm -rf
NAME			= minilibx

# Directories

LIB				= ./.$(NAME)

# Rules

all : $(LIB)

fclean : 
	@echo $(YELLOW) "Removing $(NAME)..." $(END)
	@$(RM) $(NAME)* $(LIB)
	@echo $(RED) "$(NAME) deleted successfully!\n" $(END)

re : fclean all

$(LIB):
	@curl -O $(LINK)
	@gunzip -c $(ARCHIEVE) | tar xopf -
	@mv $(FOLDER) $(NAME)
	make -C $(NAME)
	@$(RM) *.tgz
	@mkdir $(LIB)

.PHONY: all  fclean re