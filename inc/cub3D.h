/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:07:12 by dacortes          #+#    #+#             */
/*   Updated: 2023/12/21 18:30:46 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/******************************************************************************/
/*                            INCLUDES                                        */
/******************************************************************************/

# ifdef INC_MAC
#  include "../lib/minilibx_mac/mlx.h"
# endif
# ifdef INC_LINUX
#  include "../lib/minilibx_linux/mlx.h"
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# include "../lib/libft/libft.h"
# include "../lib/libft/ft_printf.h"
# include "../lib/libft/get_next_line.h"
# include "minimap.h"

/******************************************************************************/
/*                            MACROS                                          */
/******************************************************************************/

# define ARG 1
# define MEM 2
# define OPN 3
# define MAP 4
# define FRM 5
# define PRR 6

# define TRUE   1
# define FALSE  0
# define ERROR -1

# define NORTH	4.71
# define EAST	0
# define SOUTH	1.57
# define WEST	3.14

/******************************************************************************/
/*                            COLORS                                          */
/******************************************************************************/

# define E "\033[m"        //end
# define R "\033[1;31m"    //red
# define G "\033[1;32m"    //green
# define Y "\033[1;33m"    //yellow
# define B "\033[1;34m"    //blue
# define T "\033[1;35m"	   //Turquesa
# define C "\033[1;36m"    //Cyan
# define O "\033[38;5;208m" //orange
# define F "\033[38;5;128m"  //purple

/******************************************************************************/
/*                            STRUCTURES                                      */
/******************************************************************************/

struct						s_minimap;
typedef struct s_minimap	t_minimap;

typedef struct s_aux
{
	int		player;
	char	*line;
	int		iter;
	int		no;
	int		so;
	int		we;
	int		ea;
	int		floor;
	int		ceiling;
}	t_aux;

typedef struct s_bob
{
	float	perp_wall_dist;
	int		line_height;
	int		calculated_drawstart;
	int		drawstart;
	int		calculated_drawend;
	int		drawend;
	int		color;
	t_img	*texture;
}	t_bob;

typedef struct point_s
{
	int				x;
	int				y;
	int				z;
	int				color;
}	t_point;

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;	
}	t_color;

typedef struct s_f_point
{
	float			x;
	float			y;
	float			z;
	int				color;
}	t_f_point;

typedef struct s_ray
{
	t_f_point	vect;
	t_f_point	cam_intersect;
	t_f_point	deltas;
	t_f_point	distances;
	t_point		position;
	t_point		directions;
	t_f_point	colisions;
	int			i;
	int			side;
}	t_ray;

typedef struct s_player
{
	t_f_point		position;
	float			dir_rad;
	t_f_point		dir_vect;
	float			dir_vect_len;
	t_f_point		cam_vect;
	float			cam_vect_len;
	t_f_point		camera;
	t_point			movement;
}	t_player;

typedef struct s_map
{
	int			rows;
	int			cols;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		**map;
	t_img		texture_no;
	t_img		texture_so;
	t_img		texture_we;
	t_img		texture_ea;
	t_color		floor;
	t_color		ceiling;
	t_player	player;
	t_minimap	*minimap;
	t_img		img;
	int			squares_size; // Should be deleted
}	t_map;

typedef struct s_minimap
{
	int				squares_size;
	int				rows;
	int				cols;
	t_point			img_position;
	t_map			*map;
	t_point			offsets;
	t_img			img;
}	t_minimap;

/******************************************************************************/
/*                            FUNCTIONS                                       */
/******************************************************************************/

/* src/init/init.c */
int			init_var(t_map *map, t_minimap *minimap);
int			init_texture(t_img *texture, t_img *img, char *path);
int			init_mlx(t_img *map, t_img *mini, char *name_win, int type);

/* src/parsing/check_access.c */
int			parse_text(char *path);
int			check_access(t_map *data);
int			parse_open(char *file, int *fd);
int			check_extension(char *path, char *extension);
/* src/parsing/getcolor.c */
int			get_color(t_color *set, t_aux *chk, char *find, int *stt);
/* src/parsing/getmap.c */
int			get_map(t_aux *chk, char *file, t_map *data);
int			get_dimensions(t_map *data, t_aux *chk, int *started);
/* src/parsing/getpath.c */
int			get_data(t_map *data, t_aux *chk);
/* src/parsing/parse.c */
int			parse_map(t_aux *chk, char *file, t_map *data);
int			parse_data(t_aux *chk, int fd, t_map *data);
/* src/parsing/utils.c */
int			is_space(char c);
int			is_num(char *str);
int			ignore_space(char *str, int *iter);
int			error_get_data(char **set, char *find);
int			msg_error(int err, int exit_, char *cm);
/* src/parsing/utils2.c*/
int			is_player(int player);
int			empty_line(t_aux *chk);
int			is_line_map(t_aux *chk);
int			is_map(char pos, int *player);
/* test */
int			clear_data(t_map*data);
void		draw_minimap(t_minimap *minimap);

/* points.c */
int			fdf_mk_color(int transparency, int red, int green, int blue);
void		fdf_print_point(char *start, t_point p, char *end);
void		fdf_print_f_point(char *start, t_f_point p, char *end);
t_point		fdf_set_point(int x, int y, int z, int color);
t_f_point	fdf_set_f_point(float x, float y, float z, int color);
void		fdf_draw_line(t_img *img, t_point p1, t_point p2, int clr);

/* src/minimap/utils.c */
void		fdf_swap_point(t_point *p1, t_point *p2);
/* main */
void		my_mlx_pixel_put(t_img *data, int x, int y, int color);

/* src/minimap/bob_ross.c */
void		cub3d(t_map *map, t_ray *ray);
/* loop */
int			run_game(t_map *map);
int			fdf_key_press_hook(int key, t_point *movement);
int			fdf_key_release_hook(int key, t_point *movement);

/* src/minimap/minimap.c */
int			minimap_draw_square(t_minimap *minimap, t_point pixel,
				t_point squares_size, int border);
void		draw_minimap_tiles(t_minimap *minimap);
void		draw_minimap(t_minimap *minimap);
void		draw_player(t_minimap *minimap);

/* src/utils.c */
int			close_win(t_map *map);
int			get_square_on_position(t_map *map, t_f_point position);
t_f_point	from_rad_to_vect(float radians, float len);

/* ray_calculator */
void		ray_calculator(t_map *map, t_ray *ray);
#endif
