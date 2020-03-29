# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/10 19:51:10 by ablanar           #+#    #+#              #
#    Updated: 2020/03/29 17:14:04 by art              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	miniRT

SRC =   ft_inter_cu.c ft_add_cube.c ft_shade_cu.c \
		ft_obs_cu.c ft_inter_cy_cup.c ft_shade_cy_ci.c \
		ft_check_cup.c ft_check_obst.c ft_intersect.c \
		ft_ray.c main.c ft_add_spheres.c ft_basic_op.c \
		ft_add_ambient.c ft_add_camera.c ft_add_cylinder.c \
		ft_add_lights.c ft_add_plane.c ft_add_resolution.c \
		ft_add_square.c ft_add_triangle.c ft_atof.c \
		ft_atoi.c  ft_check_sq.c ft_inter_sq.c \
		ft_check_cy.c ft_check_pl.c ft_check_sp.c \
		ft_draw_with_threads.c ft_inter_cy.c ft_inter_pl.c \
		ft_inter_sp.c ft_strlen.c ft_shade_sp.c \
		ft_inter_tr.c ft_parse_coor.c ft_shade_cy.c \
		ft_shade_tr.c ft_shade_sq.c ft_shade_pl.c \
		ft_vectors1.c ft_vectors2.c ft_write_bmp.c \
		get_next_line.c get_next_line_utils.c \
		ft_check_input.c ft_check_values.c ft_cam_mov.c \
		ft_colors_with_filters.c ft_numbers.c ft_reader_checker.c\
		ft_split.c ft_val_checker.c ft_val_checker2.c \
		ft_values_in_obj.c ft_cam_mov2.c


OBJS =	$(SRC:.c=.o)

CC =	gcc

FRAME = 	-framework OpenGL -framework AppKit

LMINX =		-I /usr/local/include -L./minilibx_opengl/ -lmlx

CFLAGS =	-Wall -Wextra -Werror

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
	@make -s -C minilibx_opengl
	gcc $(FRAME) $(CFLAGS) $(LMINX) -o $(NAME) $(OBJS)

clean:
	rm -f *.o
	rm -f ./minilibx_opengl/*.o
fclean: clean
	rm -f ./minilibx_opengl/libmlx.a
	rm -f $(NAME)
re: fclean all
