/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:07:12 by dacortes          #+#    #+#             */
/*   Updated: 2023/11/20 17:44:44 by codespace        ###   ########.fr       */
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
# define PRR 4

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
typedef	struct s_get_color
{
	int	red;
	int	green;
	int	blue;
}	t_get_color;

typedef struct s_path_text
{
	char	*so;
	char	*we;
	char	*ea;
}	t_path_text;

/******************************************************************************/
/*                            FUNCTIONS                                       */
/******************************************************************************/

/* src/parsing/getpath.c */
int	parse_open(char *file, int *fd);
int	get_path_text(char *line, t_path_text *text);
/* src/parsing/utils.c */
int	is_space(char c);
int	msg_error(int err, int exit_, char *cm);
#endif 