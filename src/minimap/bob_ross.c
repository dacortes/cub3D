/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bob_ross.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:38:38 by dacortes          #+#    #+#             */
/*   Updated: 2023/12/21 17:43:47 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	bobross_init(t_bob *ross, t_map *map, t_ray *ray)
{
	if (!ray->side)
	{
		ross->perp_wall_dist = (ray->distances.x - ray->deltas.x);
		if (ray->vect.x < 0)
			ross->texture = &map->texture_we;
		else
			ross->texture = &map->texture_ea;
	}
	else
	{
		ross->perp_wall_dist = (ray->distances.y - ray->deltas.y);
		if (ray->vect.y < 0)
			ross->texture = &map->texture_no;
		else
			ross->texture = &map->texture_so;
	}
	ross->line_height = (int)(SCREEN_HEIGHT / ross->perp_wall_dist);
	ross->calculated_drawstart = (-ross->line_height / 2 + SCREEN_HEIGHT / 2);
	ross->calculated_drawend = ross->line_height / 2 + SCREEN_HEIGHT / 2;
	return (EXIT_SUCCESS);
}

void	bobross_working(t_bob *ross, t_point *pixel, t_map *map, t_ray *ray)
{
	int	y;

	y = 0;
	while (y < ross->drawstart)
		my_mlx_pixel_put(&map->img, ray->i, y++, fdf_mk_color(0,
				map->ceiling.red, map->ceiling.green, map->ceiling.blue));
	while (y < ross->drawend)
	{
		if (ray->side)
			pixel->x = ross->texture->width * (ray->colisions.x
					- (int)ray->colisions.x);
		else
			pixel->x = ross->texture->width * (ray->colisions.y
					- (int) ray->colisions.y);
		pixel->y = ross->texture->height * (((float)(y - ross->drawstart
						- (ross->calculated_drawstart - ross->drawstart)))
				/ (ross->calculated_drawend - ross->calculated_drawstart));
		ross->color = (*(int *)(ross->texture->addr + (pixel->y
						* ross->texture->line_len + pixel->x
						* (ross->texture->bits_pxl / 8)))) & 0x00ffffff;
		my_mlx_pixel_put(&map->img, ray->i, y++, ross->color);
	}
	while (y < (SCREEN_HEIGHT - 1))
		my_mlx_pixel_put(&map->img, ray->i, y++,
			fdf_mk_color(0, map->floor.red, map->floor.green, map->floor.blue));
}

void	cub3d(t_map *map, t_ray *ray)
{
	t_point	pixel;
	t_bob	ross;

	bobross_init(&ross, map, ray);
	if (ross.calculated_drawstart < 0)
		ross.drawstart = 0;
	else
		ross.drawstart = ross.calculated_drawstart;
	if (ross.calculated_drawend >= SCREEN_HEIGHT)
		ross.drawend = SCREEN_HEIGHT - 1;
	else
		ross.drawend = ross.calculated_drawend;
	bobross_working(&ross, &pixel, map, ray);
}
