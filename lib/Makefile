# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabduvak <aabduvak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 07:59:14 by aabduvak          #+#    #+#              #
#    Updated: 2022/08/08 08:24:55 by aabduvak         ###   ########.fr        #
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
	@curl -O https://projects.intra.42.fr/uploads/document/document/9232/minilibx_opengl.tgz
	@gunzip -c $(NAME)_opengl.tgz | tar xopf -
	@mv $(NAME)_opengl_20191021 $(NAME)
	make -C $(NAME)
	@$(RM) *.tgz
	@mkdir $(LIB)

.PHONY: all  fclean re