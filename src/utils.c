/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 08:48:44 by dacortes          #+#    #+#             */
/*   Updated: 2023/12/18 08:51:01 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	close_win(t_map *map)
{
	(void)map;
	exit (printf("Exit cub3D\n") * EXIT_SUCCESS);
}

int get_square_on_position(t_map *map, t_f_point position)
{
	int row;
	int col;
	int	result;

	row = position.y;
	col = position.x;
	result = map->map[row][col];

	return (result);

}

t_f_point	from_rad_to_vect(float radians, float len)
{
	t_f_point rotated;

	rotated.x = len * cos(radians); //x * cos(radians) - y * sin(radians);
	rotated.y = len * sin(radians); //x * sin(radians) + y * cos(radians);
	return (rotated);
}

