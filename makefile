# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/09 17:00:24 by ade-la-c          #+#    #+#              #
#    Updated: 2020/12/19 17:52:39 by ade-la-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= Cub3D

SRCS			= get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c \
				main.c file_init.c utils.c data_parsing_1.c \


OBJS			= $(SRCS:.c=.o)

MLX				= libmlx.dylib

CC				= gcc

RM				= rm -fr

CFLAGS			= -Wall -Werror -Wextra

LIBS			= -L./libft -lft -L. -lmlx -framework OpenGL \
							-framework AppKit -lm

.c.o:
				@${CC} ${CFLAGS} -c $^ -o $@

all:			$(NAME)

$(NAME):		$(OBJS)
				@echo "$(CL_GREEN)-> COMPILING LIBFT$(CL_RESET)"
				@echo "$(CL_GREY)"
				@$(MAKE) -C ./libft bonus
				@echo "$(CL_RESET)"
				@echo "$(CL_GREEN)-> COMPILING MLX$(CL_RESET)"
				@echo "$(CL_GREY)"
				@make -C ./mlx
				@mv ./mlx/$(MLX) .
				@echo "$(CL_RESET)"
				@echo "$(CL_GREEN)-> COMPILING CUB3D$(CL_RESET)"
				@echo "$(CL_GREY)"
				$(CC) -o $(NAME) $(OBJS) $(LIBS)
				@echo "$(CL_RESET)"

clean:
				@echo "$(CL_GREEN)-> CLEAN$(CL_RESET)"
				@echo "$(CL_GREY)"
				@$(MAKE) -C ./libft clean
				@$(MAKE) -C ./mlx clean
				$(RM) $(OBJS)
				@echo "$(CL_RESET)"

fclean:			clean
				@echo "$(CL_GREEN)-> FCLEAN$(CL_RESET)"
				@echo "$(CL_GREY)"
				@$(MAKE) -C ./libft fclean
				$(RM) $(NAME)
				$(RM) $(MLX)
				@echo "$(CL_RESET)"

re:				fclean all

mclean:			all clean

.PHONY:			all clean fclean re