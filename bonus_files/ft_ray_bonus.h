/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 14:02:23 by ablanar           #+#    #+#             */
/*   Updated: 2020/02/13 15:38:28 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RAY_BONUS_H
# define FT_RAY_BONUS_H
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <sys/errno.h>
# include <string.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

typedef struct	s_pixel
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
}				t_pixel;

typedef struct	s_bmp
{

	unsigned int	*wentry;
	unsigned int	*hentry;
	unsigned int	*sizeoffile;
	unsigned int	padding;
	unsigned int	pixbyrow;
}				t_bmp;

typedef struct	s_line
{
	char			*line;
	struct s_line	*next;
}				t_line;

typedef struct	s_node
{
	int				fd;
	t_line			*line;
	struct s_node	*next;
}				t_node;

typedef struct	s_vector
{
	float x;
	float y;
	float z;
}				t_vector;

typedef struct	s_cam
{
	t_vector		norm;
	t_vector		o;
	float			fov;
	struct s_cam	*next;
	struct s_cam	*prev;
}				t_cam;

typedef struct	s_l
{
	t_vector	coor;
	float		b;
	t_vector	color;
	struct s_l	*next;
}				t_l;

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}				t_mlx;

typedef struct	s_amb
{
	float		r;
	t_vector	color;
}				t_amb;

typedef struct	s_sp
{
	t_vector	coor;
	float		r;
	t_vector	color;
	struct s_sp	*next;
}				t_sp;

typedef struct	s_pl
{
	t_vector		coor;
	t_vector		norm;
	t_vector		color;
	struct s_pl		*next;
}				t_pl;

typedef struct	s_sq
{
	t_vector		coor;
	t_vector		norm;
	float			size;
	t_vector		color;
	struct s_sq		*next;
}				t_sq;

typedef struct	s_cs
{
	t_vector		coor;
	t_vector		norm;
	float			size;
	t_vector		color;
	t_vector		up;
	t_vector		r;
	t_vector		*k;
	struct s_cs		*next;
}				t_cs;

typedef struct	s_cu
{
	t_vector		coor;
	t_vector		norm;
	float			size;
	t_vector		color;
	struct s_cu		*next;
}				t_cu;

typedef struct	s_cy
{
	t_vector		coor;
	t_vector		norm;
	t_vector		color;
	float			h;
	float			d;
	struct s_cy		*next;
}				t_cy;

typedef struct	s_tr
{
	t_vector	c[3];
	t_vector	color;
	struct s_tr	*next;
}				t_tr;

typedef struct	s_obj
{
	t_sp *sp;
	t_pl *pl;
	t_sq *sq;
	t_tr *tr;
	t_cy *cy;
	t_cu *cu;
	t_cs *cs;
}				t_obj;

typedef struct	s_info
{
	int		res[2];
	t_cam	*cam;
	t_obj	obj;
	t_l		*l;
	t_amb	al;
	t_mlx	mlx;
	int		filter;
}				t_info;

typedef	struct	s_thread_data
{
	int		thread_id;
	t_info	*info;
}				t_thread_data;

t_vector		g_up;
t_vector		g_right;
void			ft_recalculate(t_vector *norm, t_vector *ups, t_vector *rights);
float			ft_atof(char *s);
int				ft_atoi(char *s);
int				ft_parse_rt(int fd, t_info *info);
int				get_next_line(int fd, char **line);
int				ft_check(char *s);
t_vector		ft_parcor(char *s);
int				ft_add_a(t_info *info, char *line);
int				ft_add_c(t_info *info, char *line);
int				ft_add_l(t_info *info, char *line);
int				ft_add_spheres(t_info *info, char *line);
int				ft_add_sq(t_info *info, char *line);
int				ft_add_cy(t_info *info, char *line);
int				ft_add_plane(t_info *info, char *line);
int				ft_add_tr(t_info *info, char *line);
int				ft_add_r(t_info *info, char *line);
void			ft_draw(t_info info);
double			ft_to_radiant(float degree);
void			ft_swap(double *a, double *b);
double			ft_abs(double a);
double			ft_d_count(int hight, float fov);
int				ft_solveq(double *a, double *x0, double *x1);
t_vector		ft_normilize(t_vector v);
t_vector		ft_vmult(t_vector s1, t_vector s2);
t_vector		ft_vecsum(t_vector s1, t_vector s2);
double			ft_veclen(t_vector v);
double			ft_dot_product(t_vector s1, t_vector s2);
t_vector		ft_constmult(double k, t_vector s);
t_vector		ft_vsbst(t_vector s1, t_vector s2);
t_vector		ft_inv(t_vector v);
void			ft_fill_v(t_vector *v, float x, float y, float z);
int				ft_intersect(int x, int y, t_info info);
int				ft_shade_sp(t_info info, t_vector d, t_sp *sp);
void			ft_inter_sp(t_vector d, t_info info, double *t, int *color);
int				ft_check_obst(t_info info, t_vector l, t_vector d);
void			ft_inter_pl(t_vector d, t_info info, double *t, int *color);
int				ft_color(t_vector *coef, t_vector color, t_info info);
int				ft_shade_pl(t_info info, t_vector d, t_pl *pl);
void			ft_inter_sq(t_vector d, t_info info, double *t, int *color);
t_vector		ft_norm_pl(t_vector norm, t_vector cam);
int				ft_shade_sq(t_info info, t_vector d, t_sq *sq);
void			ft_inter_tr(t_vector d, t_info info, double *t, int *color);
int				ft_shade_tr(t_info info, t_vector d, t_tr *tr, t_vector norm);
void			ft_inter_cy(t_vector d, t_info info, double *t, int *color);
int				ft_shade_cy(t_info info, t_vector d, t_cy *cy);
int				ft_shade_cy_ci(t_info info, t_vector d, t_cy *cy);
int				ft_save(t_info info);
int				ft_add_cube(t_info *info, char *line);
int				ft_obs_cy(t_info info, t_cy *cy, t_vector l, t_vector d);
int				ft_obs_pl(t_info info, t_pl *pl, t_vector l, t_vector d);
int				ft_obs_sp(t_info info, t_sp *sp, t_vector l, t_vector d);
int				ft_obs_sq(t_info info, t_sq *sq, t_vector l, t_vector d);
int				ft_shade_cy_beh(t_info info, t_vector d, t_cy *cy);
int				ft_strlen(char *str);
int				get_next_line(int fd, char **line);
t_line			*ft_find_fd(int fd, t_node **list);
int				ft_clean(t_node **list, t_line *cur, int fd);
int				ft_check_gnl(char *s);
int				ft_exit(t_info *info);
t_vector		ft_get_coef(t_vector c, t_vector l, t_vector norm, t_l *light);
void			ft_get_spec(t_vector *coef, t_vector *ld, t_l *light,
							t_vector norm);
int				ft_add_cube(t_info *info, char *line);
void			ft_inter_cu(t_vector d, t_info info, double *t, int *color);
int				ft_add_square(t_sq **square, t_vector *c, float size);
int				ft_shade_cu(t_info info, t_vector d, t_cs *sq);
int				ft_obs_cu(t_info info, t_cu *cu, t_vector l, t_vector d);
t_cs			*ft_add_cs(t_cs **s, t_vector *c, float size, t_vector color);
int				ft_obs_cu(t_info info, t_cu *cu, t_vector l, t_vector d);
void			ft_fill_cs(t_vector *c, t_vector norm, t_vector up, t_vector r);
int				ft_shade_cy_ci(t_info info, t_vector d, t_cy *cy);
void			ft_inter_cy_ci(t_vector d, t_info info, double *t, int *color);
void			ft_cy_help(t_cy *cy, double *a, t_vector d, t_info info);
int				ft_obs_cy_cup(t_info info, t_cy *cy, t_vector l, t_vector d);
void			ft_cu_help(t_cs **cs, t_cu *cu, t_vector *s);
int				ft_check_input(char *line);
void			ft_change_cam(t_cam **cam, int pos);
int				ft_check_objects_val(t_info *info);
int				ft_check_inp(t_info info);
int				ft_sizeof_tab(char **tab);
int				ft_check_int(char *line);
int				ft_check_fl(char *line);
int				ft_free_tab(char **tab);
int				ft_check_color(char *line);
int				ft_check_res(char **line);
int				ft_check_color_val(t_vector color);
int				ft_check_norm_val(t_vector norm);
int				ft_check_cameras_val(t_cam *cam);
int				ft_check_cu(char **line);
int				ft_check_tr(char **line);
int				ft_check_cy(char **line);
int				ft_check_sq(char **line);
int				ft_check_plane(char **line);
char			**ft_split(char *line, char c);
int				ft_check_lights_val(t_l *lights);
int				ft_check_obj_val(t_obj obj);
int				ft_check_cu_val(t_cu *cu);
int				ft_check_tr_val(t_tr *tr);
int				ft_check_cy_val(t_cy *cy);
int				ft_check_sq_val(t_sq *sq);
int				ft_check_pl_val(t_pl *pl);
int				ft_check_sp_val(t_sp *sp);
int				ft_check_pos(char *line);
int				ft_check_a(char **line);
int				ft_check_norm(char *line);
int				ft_check_c(char **line);
int				ft_check_l(char **line);
int				deal_mouse(int b, int x, int y, t_info *info);
void			ft_draw_help(t_info info);
#endif
