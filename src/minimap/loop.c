/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:46:34 by jrenau-v          #+#    #+#             */
/*   Updated: 2023/12/21 18:28:41 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	render(t_map *map);

void	move_player(t_player *player)
{
	if (player->movement.y != 0 && player->movement.x != 0)
	{
		player->position.x += (player->dir_vect.x
				* MOVEMENT_DELTA * player->movement.y) / 2;
		player->position.y += (player->dir_vect.y
				* MOVEMENT_DELTA * player->movement.y) / 2;
		player->position.x -= (player->dir_vect.y
				* MOVEMENT_DELTA * player->movement.x) / 2;
		player->position.y += (player->dir_vect.x
				* MOVEMENT_DELTA * player->movement.x) / 2;
	}
	else if (player->movement.y != 0)
	{
		player->position.x += (player->dir_vect.x
				* MOVEMENT_DELTA) * player->movement.y ;
		player->position.y += (player->dir_vect.y
				* MOVEMENT_DELTA) * player->movement.y ;
	}
	else if (player->movement.x != 0)
	{
		player->position.x -= (player->dir_vect.y
				* MOVEMENT_DELTA) * player->movement.x ;
		player->position.y += (player->dir_vect.x
				* MOVEMENT_DELTA) * player->movement.x ;
	}
}

int	run_game(t_map *map)
{
	t_minimap	*minimap;
	t_player	*player;
	t_f_point	initial_position;

	mlx_clear_window(map->minimap->img.mlx_ptr, map->minimap->img.win_ptr);
	player = &map->player;
	minimap = map->minimap;
	initial_position = player->position;
	map->player.dir_rad += ROTATION_DELTA * map->player.movement.z;
	map->player.dir_rad += ROTATION_DELTA * map->player.movement.z;
	map->player.dir_vect = from_rad_to_vect(map->player.dir_rad,
			map->player.dir_vect_len);
	map->player.cam_vect = from_rad_to_vect((map->player.dir_rad + 1.57079633),
			map->player.cam_vect_len);
	move_player(player);
	if (get_square_on_position(map, player->position) != 0)
		player->position = initial_position;
	draw_minimap(minimap);
	render(map);
	mlx_put_image_to_window(map->img.mlx_ptr,
		map->img.win_ptr, map->img.img, 0, 0);
	mlx_put_image_to_window(minimap->img.mlx_ptr,
		minimap->img.win_ptr, minimap->img.img, 0, 0);
	return (1);
}

void	set_coliding_variables(t_f_point player_pos, t_ray *ray)
{
	ray->deltas = fdf_set_f_point(fabs(1.0 / ray->vect.x),
			fabs(1.0 / ray->vect.y), 0, 0);
	ray->position = fdf_set_point(player_pos.x, player_pos.y, 0, 0);
	if (ray->vect.x < 0)
	{
		ray->distances.x = (player_pos.x - ray->position.x) * ray->deltas.x;
		ray->directions.x = -1;
	}
	else
	{
		ray->distances.x = (((float)(1 + ray->position.x)) - player_pos.x)
			* ray->deltas.x;
		ray->directions.x = 1;
	}
	if (ray->vect.y < 0)
	{
		ray->distances.y = (player_pos.y - ray->position.y) * ray->deltas.y;
		ray->directions.y = -1;
	}
	else
	{
		ray->distances.y = ((float)(1 + ray->position.y) - player_pos.y)
			* ray->deltas.y;
		ray->directions.y = 1;
	}
}

void	colide_ray(t_map *map, t_ray *ray)
{
	int	colided;

	colided = 0;
	set_coliding_variables(map->player.position, ray);
	while (!colided)
	{
		if (ray->distances.x < ray->distances.y)
		{
			ray->position.x += ray->directions.x;
			ray->distances.x += ray->deltas.x;
			ray->side = 0;
		}
		else
		{
			ray->position.y += ray->directions.y;
			ray->distances.y += ray->deltas.y;
			ray->side = 1;
		}
		colided = (map->map[ray->position.y][ray->position.x] != 0);
		ray_calculator(map, ray);
	}
}

void	render(t_map *map)
{
	int			cam_i;
	int			cam_end;
	t_ray		ray;
	t_f_point	cam_0;

	cam_end = SCREEN_WIDTH / 2;
	cam_i = 0 - cam_end;
	ray.i = 0;
	cam_0 = fdf_set_f_point(map->player.position.x + map->player.dir_vect.x,
			map->player.position.y + map->player.dir_vect.y, 0, 0);
	while (cam_i < cam_end)
	{
		ray.cam_intersect.x = cam_0.x
			+ (map->player.cam_vect.x * cam_i / cam_end);
		ray.cam_intersect.y = cam_0.y
			+ (map->player.cam_vect.y * cam_i / cam_end);
		ray.vect.x = ray.cam_intersect.x - map->player.position.x;
		ray.vect.x += ((ray.vect.x > 0) * 2 - 1) * 0.0001;
		ray.vect.y = ray.cam_intersect.y - map->player.position.y;
		ray.vect.y += ((ray.vect.y > 0) * 2 - 1) * 0.0001;
		colide_ray(map, &ray);
		cub3d(map, &ray);
		cam_i++;
		ray.i++;
	}
}
