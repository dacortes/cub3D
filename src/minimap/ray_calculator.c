/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calculator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:28:20 by dacortes          #+#    #+#             */
/*   Updated: 2023/12/21 18:28:46 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

t_f_point	calculate_colision(t_map *map, t_ray *ray)
{
	float		diferential;
	float		constant;
	t_f_point	colision;

	if (!ray->side)
	{
		diferential = ray->vect.y / ray->vect.x;
		if (fabs(diferential) > 50.0)
			diferential = 50.0 * ((diferential > 0) * 2 - 1);
		constant = map->player.position.y
			- map->player.position.x * diferential;
		colision.x = ray->position.x + (ray->vect.x < 0);
		colision.y = colision.x * diferential + constant;
	}
	else
	{
		diferential = ray->vect.x / ray->vect.y;
		if (fabs(diferential) > 50.0)
			diferential = 50.0 * ((diferential > 0) * 2 - 1);
		constant = map->player.position.x
			- map->player.position.y * diferential;
		colision.y = ray->position.y + (ray->vect.y < 0);
		colision.x = colision.y * diferential + constant;
	}
	return (colision);
}

void	ray_calculator(t_map *map, t_ray *ray)
{
	t_f_point	colision;
	t_point		starts;
	t_point		ends;

	colision = calculate_colision(map, ray);
	starts.x = map->player.position.x
		* map->minimap->squares_size;
	starts.y = map->player.position.y
		* map->minimap->squares_size;
	ends.x = colision.x * map->minimap->squares_size;
	ends.y = colision.y * map->minimap->squares_size;
	ray->colisions = fdf_set_f_point(colision.x, colision.y, 0, 0);
	fdf_draw_line(&map->minimap->img, starts, ends,
		fdf_mk_color(0, 225, 255, 255));
}
