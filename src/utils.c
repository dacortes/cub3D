/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 08:48:44 by dacortes          #+#    #+#             */
/*   Updated: 2023/12/19 12:13:56 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	close_win(t_map *map)
{
	(void)map;
	exit (printf("Exit cub3D\n") * EXIT_SUCCESS);
}

int	get_square_on_position(t_map *map, t_f_point position)
{
	int	row;
	int	col;
	int	result;

	row = position.y;
	col = position.x;
	result = map->map[row][col];
	return (result);
}

t_f_point	from_rad_to_vect(float radians, float len)
{
	t_f_point	rotated;

	rotated.x = len * cos(radians);
	rotated.y = len * sin(radians);
	return (rotated);
}
