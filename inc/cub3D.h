/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:07:12 by dacortes          #+#    #+#             */
/*   Updated: 2023/11/24 08:26:22 by dacortes         ###   ########.fr       */
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
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	t_color	floor;
	t_color	ceiling;
}	t_map;

/******************************************************************************/
/*                            FUNCTIONS                                       */
/******************************************************************************/

/* src/parsing/getcolor.c */
int	get_color(t_color *set, t_aux *chk, char *find, int *stt);
/* src/parsing/getpath.c */
int	check_access(t_map *data);
int	parse_open(char *file, int *fd);
// int	get_get_data(char *line, t_map*data, t_aux *chk);
int	get_get_data(t_map *data, t_aux *chk);
/* src/parsing/parse.c */
int	parse_data(t_aux *chk, int fd, t_map *data);
/* src/parsing/utils.c */
int	is_space(char c);
int	ignore_space(char *str, int *iter);
int	error_get_data(char **set, char *find);
int	msg_error(int err, int exit_, char *cm);

/* test */
int	clear_data(t_map*data);
#endif 