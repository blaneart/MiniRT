# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/10 19:51:10 by ablanar           #+#    #+#              #
#    Updated: 2020/02/11 17:33:30 by ablanar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME =	miniRT

PREF = ./bonus_files

SRC = 	ft_add_ambient.c ft_add_camera.c ft_add_cylinder.c \
		ft_add_lights.c ft_add_plane.c ft_add_resolution.c ft_add_spheres.c \
		ft_add_square.c ft_add_triangle.c ft_atof.c ft_atoi.c ft_basic_op.c \
		ft_check_cy.c ft_check_pl.c ft_check_sp.c ft_check_sq.c\
		ft_draw.c ft_inter_cy.c ft_inter_pl.c ft_inter_sp.c ft_inter_sq.c \
		ft_inter_tr.c ft_parse_coor.c ft_shade_cy.c \
		ft_shade_tr.c ft_shade_sq.c ft_shade_pl.c ft_shade_sp.c ft_strlen.c \
		ft_vectors1.c ft_vectors2.c ft_write_bmp.c get_next_line.c \
		get_next_line_utils.c ft_check_obst.c ft_intersect.c ft_ray.c main.c \
		ft_check_input.c ft_check_input2.c ft_check_input3.c \
		ft_check_input4.c ft_check_input5.c ft_ray2.c ft_ray3.c

LST = 	ft_inter_cu_bonus.c ft_add_cube_bonus.c ft_shade_cu_bonus.c \
		ft_obs_cu_bonus.c ft_inter_cy_cup_bonus.c ft_shade_cy_ci_bonus.c \
		ft_check_cup_bonus.c ft_check_obst_bonus.c ft_intersect_bonus.c \
		ft_ray_bonus.c main_bonus.c ft_add_spheres_bonus.c ft_basic_op_bonus.c \
		ft_add_ambient_bonus.c ft_add_camera_bonus.c ft_add_cylinder_bonus.c \
		ft_add_lights_bonus.c ft_add_plane_bonus.c ft_add_resolution_bonus.c \
		ft_add_square_bonus.c ft_add_triangle_bonus.c ft_atof_bonus.c \
		ft_atoi_bonus.c  ft_check_sq_bonus.c ft_inter_sq_bonus.c \
		ft_check_cy_bonus.c ft_check_pl_bonus.c ft_check_sp_bonus.c \
		ft_draw_with_threads.c ft_inter_cy_bonus.c ft_inter_pl_bonus.c \
		ft_inter_sp_bonus.c ft_strlen_bonus.c ft_shade_sp_bonus.c \
		ft_inter_tr_bonus.c ft_parse_coor_bonus.c ft_shade_cy_bonus.c \
		ft_shade_tr_bonus.c ft_shade_sq_bonus.c ft_shade_pl_bonus.c \
		ft_vectors1_bonus.c ft_vectors2_bonus.c ft_write_bmp_bonus.c \
		get_next_line_bonus.c get_next_line_utils_bonus.c \
		ft_check_input_bonus.c ft_check_values_bonus.c ft_cam_mov_bonus.c \
		ft_colors_with_filters.c ft_numbers_bonus.c ft_reader_checker_bonus.c\
		ft_split_bonus.c ft_val_checker_bonus.c ft_val_checker_bonus2.c \
		ft_values_in_obj.c ft_cam_mov_bonus2.c


OBJS =	$(SRC:.c=.o)

BON =	$(addprefix $(PREF)/,$(LST:%.c=%.o))

CC =	gcc

FRAME = 	-framework OpenGL -framework AppKit

LMINX =		-I /usr/local/include -L /usr/local/lib -lmlx

CFLAGS =	-Wall -Wextra -Werror

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
	gcc $(FRAME) $(CFLAGS) $(LMINX) -o $(NAME) $(OBJS)

bonus:	$(BON)
	gcc $(FRAME) -I ./bonus_files $(CFLAGS) $(LMINX) -o $(NAME) $(BON)
clean:
	rm -f *.o ./bonus_files/*.o
fclean: clean
	rm -f $(NAME)
re: fclean all
