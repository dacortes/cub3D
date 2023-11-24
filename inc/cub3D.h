/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:07:12 by dacortes          #+#    #+#             */
/*   Updated: 2023/11/22 11:53:16 by jrenau-v         ###   ########.fr       */
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

# include "minimap.h"
# include "../lib/libft/libft.h"


/******************************************************************************/
/*                            MACROS                                          */
/******************************************************************************/


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


#endif 
