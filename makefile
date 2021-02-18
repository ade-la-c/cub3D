# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/09 17:00:24 by ade-la-c          #+#    #+#              #
#    Updated: 2021/02/18 17:40:59 by ade-la-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= Cub3D

SRCS			= includes/get_next_line/get_next_line.c \
				includes/get_next_line/get_next_line_utils.c \
				srcs/main.c \
				srcs/parsing/file_parsing.c \
				srcs/parsing/data_parsing.c \
				srcs/parsing/map_parsing.c \
				srcs/parsing/map_verif.c \
				srcs/utils/utils.c \
				srcs/utils/utils_2.c \
				srcs/utils/minilibx_utils.c \
				srcs/event.c \
				srcs/visual/movement.c \
				srcs/visual/rotation.c \
				srcs/visual/algo_raycasting.c \
				srcs/visual/start_position.c \
				srcs/visual/texture.c \
				#srcs/visual/sprite.c \

OBJS			= $(SRCS:.c=.o)

MLX				= libmlx.dylib

CC				= gcc

RM				= rm -f

CFLAGS			=  -Wall -Werror -Wextra -I. -g -fsanitize=address

LIBS			= -L./includes/libft -lft -L. -lmlx -framework OpenGL \
							-framework AppKit -lm

CL_GREY		= \033[38;2;128;128;128m

CL_GREEN	= \033[38;2;0;153;0m

CL_RESET	= \033[0m

.c.o:
				@${CC} ${CFLAGS} -c $^ -o $@

all:			$(NAME)

$(NAME):		$(OBJS)
				@echo "$(CL_GREEN)-> COMPILING LIBFT$(CL_RESET)"
				@echo "$(CL_GREY)"
				@$(MAKE) -C ./includes/libft bonus
				@echo "$(CL_RESET)"
				@echo "$(CL_GREEN)-> COMPILING MLX$(CL_RESET)"
				@echo "$(CL_GREY)"
				@make -C ./includes/mlx
				@mv ./includes/mlx/$(MLX) .
				@echo "$(CL_RESET)"
				@echo "$(CL_GREEN)-> COMPILING CUB3D$(CL_RESET)"
				@echo "$(CL_GREY)"
				$(CC) ${CFLAGS} -o $(NAME) $(OBJS) $(LIBS)
				@echo "$(CL_RESET)"

clean:
				@echo "$(CL_GREEN)-> CLEAN$(CL_RESET)"
				@echo "$(CL_GREY)"
				@$(MAKE) -C ./includes/libft clean
				@$(MAKE) -C ./includes/mlx clean
				$(RM) $(OBJS)
				@echo "$(CL_RESET)"

fclean:			clean
				@echo "$(CL_GREEN)-> FCLEAN$(CL_RESET)"
				@echo "$(CL_GREY)"
				@$(MAKE) -C ./includes/libft fclean
				$(RM) $(NAME)
				$(RM) $(MLX)
				@echo "$(CL_RESET)"

re:				fclean all

mclean:			all clean

.PHONY:			all clean fclean re