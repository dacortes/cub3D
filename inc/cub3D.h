/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:07:12 by dacortes          #+#    #+#             */
/*   Updated: 2023/11/29 16:34:58 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

typedef struct	s_img {
	void	*img;
	void	*mlx_ptr;
	void	*win_ptr;
	char	*addr;
	int		bits_pxl;
	int		line_len;
	int		endian;
	int		width;  //maybe not needed
	int		height;  //maybe not needed
}				t_img;

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
# define PRR 5

# define TRUE   1
# define FALSE  0
# define ERROR -1
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

typedef	struct s_color
{
	int	red;
	int	green;
	int	blue;	
}	t_color;

typedef struct s_map
{
	int		row;
	int		col;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	**map;
	t_color	floor;
	t_color	ceiling;
}	t_map;

typedef struct minimap_s
{
	int				squares_size;
	int	rows;
	int	cols;
	t_point			img_position;
	t_map			*map;
	t_point			offsets;
	t_img			img;
}	t_minimap;

/******************************************************************************/
/*                            FUNCTIONS                                       */
/******************************************************************************/

/* src/parsing/check_access.c */
int	parse_text(char *path);
int	check_access(t_map *data);
int	parse_open(char *file, int *fd);
/* src/parsing/getcolor.c */
int	get_color(t_color *set, t_aux *chk, char *find, int *stt);
/* src/parsing/getmap.c */
int	get_map(t_aux *chk, char *file, t_map *data);
int	get_dimensions(t_map *data, t_aux *chk, int *started);
/* src/parsing/getpath.c */
int	get_data(t_map *data, t_aux *chk);
/* src/parsing/parse.c */
int	parse_map(t_aux *chk, char *file, t_map *data);
int	parse_data(t_aux *chk, int fd, t_map *data);
/* src/parsing/utils.c */
int	is_space(char c);
int	is_num(char *str);
int	ignore_space(char *str, int *iter);
int	error_get_data(char **set, char *find);
int	msg_error(int err, int exit_, char *cm);
/* src/parsing/utils2.c*/
int is_player(int player);
int	empty_line(t_aux *chk);
int	is_line_map(t_aux *chk);
int	is_map(char pos, int *player);
/* test */
int	clear_data(t_map*data);
void draw_minimap(t_minimap *minimap);

/* points.c */
int		fdf_mk_color(int transparency, int red, int green, int blue);
void	fdf_print_pnt(t_point p);
t_point	fdf_set_point(int x, int y, int z, int color);
void	fdf_put_pixel(void *img_ptr, unsigned int x, unsigned int y, int color);

/* main */

void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
#endif
