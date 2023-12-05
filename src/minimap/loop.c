
#include "../inc/cub3D.h"

void render(t_map *map);

int run_game(t_map *map)
{
	t_minimap	*minimap;
	t_player	*player;
	t_f_point	initial_position; 
	player = &map->player;
	minimap = map->minimap;
	initial_position = player->position;
	map->player.dir_rad +=  ROTATION_DELTA * map->player.movement.z;
	map->player.dir_rad +=  ROTATION_DELTA * map->player.movement.z;
	map->player.dir_vect = from_rad_to_vect(map->player.dir_rad, map->player.dir_vect_len);
	map->player.cam_vect = from_rad_to_vect((map->player.dir_rad + 1.57079633), map->player.cam_vect_len);
	if (player->movement.y != 0 && player->movement.x != 0)
	{
		player->position.x += (player->dir_vect.x * MOVEMENT_DELTA * player->movement.y) /2;
		player->position.y += (player->dir_vect.y * MOVEMENT_DELTA * player->movement.y) /2;
		player->position.x -= (player->dir_vect.y * MOVEMENT_DELTA * player->movement.x) /2;
		player->position.y += (player->dir_vect.x * MOVEMENT_DELTA * player->movement.x) /2;
	}
	else if (player->movement.y != 0)
	{
		player->position.x += (player->dir_vect.x * MOVEMENT_DELTA) * player->movement.y ;
		player->position.y += (player->dir_vect.y * MOVEMENT_DELTA) * player->movement.y ;
	}
	else if (player->movement.x != 0)
	{
		player->position.x -= (player->dir_vect.y * MOVEMENT_DELTA) * player->movement.x ;
		player->position.y += (player->dir_vect.x * MOVEMENT_DELTA) * player->movement.x ;
	}
	if (get_square_on_position(map, player->position) != 0)
		player->position = initial_position;
	draw_minimap(minimap);
	render(map);
	mlx_put_image_to_window(minimap->img.mlx_ptr, minimap->img.win_ptr,
			minimap->img.img, 0, 0);
	return (1);
}

void print_half_ray(t_map *map, t_f_point ray_v)
{
	t_point ray_start_img = fdf_set_point(map->player.position.x * map->minimap->squares_size, map->player.position.y * map->minimap->squares_size, 0, 0);
	t_point ray_end_img = fdf_set_point(ray_v.x * map->minimap->squares_size, ray_v.y * map->minimap->squares_size, 0, 0);
	fdf_draw_line(&map->minimap->img, ray_start_img, ray_end_img, fdf_mk_color(0,0,0,0));
}

void set_coliding_variables(t_f_point player_pos, t_ray *ray)
{
	ray->deltas = fdf_set_f_point(1.0 / ray->vect.x, 1.0 / ray->vect.y, 0, 0);
	ray->position = fdf_set_point(player_pos.x, player_pos.y, 0, 0);
	if (ray->vect.x < 0)
	{
		ray->distances.x = (player_pos.x - (int) player_pos.x ) * ray->deltas.x; 	
		ray->directions.x = -1;
	}	
	else
	{
		ray->distances.x = ( (float) (1 + player_pos.x) - player_pos.x ) * ray->deltas.x; 	
		ray->directions.x = 1;
	}
	if (ray->vect.y < 0)
	{
		ray->distances.y = (player_pos.y - (int) player_pos.y ) * ray->deltas.y; 	
		ray->directions.y = -1;
	}	
	else
	{
		ray->distances.y = ( (float) (1 + player_pos.y) - player_pos.y ) * ray->deltas.y;
		ray->directions.y = 1;
	}
}


void	joan(t_map *map, t_ray *ray)
{
	float	diferential;
	float	constant;
	float	x, y;
	t_point		starts, ends;

	if (!ray->side) //get y from x
	{
		diferential = ray->vect.y / ray->vect.x;
		constant = map->player.position.y - map->player.position.x * diferential; 
		x = ray->vect.x + map->player.position.x;	
		y = x * diferential + constant;
	}
	else  //get x from y
	{
		diferential = ray->vect.x / ray->vect.y;
		constant = map->player.position.x - map->player.position.y * diferential; 
		y = ray->vect.y + map->player.position.y;	
		x = y * diferential + constant;
	}

	starts.x = map->player.position.x * map->minimap->squares_size;
	starts.y = map->player.position.y * map->minimap->squares_size;
	ends.x = x * map->minimap->squares_size;
	ends.y = y * map->minimap->squares_size;

	fdf_draw_line(&map->minimap->img, starts, ends, fdf_mk_color(125, 255, 255, 255));	

}

void	colide_ray(t_map *map, t_ray *ray)
{
	int colided;

	colided = 0;
	set_coliding_variables(map->player.position, ray);
	if (ray->vect.x == 0 || ray->vect.y == 0)
		return ;
	while (!colided)
	{
		if (ray->distances.x < ray->distances.y)
		{
//			ft_printf("sdaf\n");
//			printf("   directions%d\n", ray->directions.x);
//			printf("   ray+_x=%d\n", ray->position.x);
			ray->position.x += ray->directions.x;
			ray->distances.x += ray->deltas.x;
			ray->side = 0;
//			printf("   ray+_x=%d\n", ray->position.x);
//			printf("   directions=%d\n", ray->directions.x);
		}
		else
		{
//			ft_printf("fasd\n");
			ray->position.y += ray->directions.y;
			ray->distances.y += ray->deltas.y;
			ray->side = 1;
		}
		fdf_print_point("Ray position: ", ray->position, "\n");
		printf("ray+_x=%d\n", ray->position.x);
		printf("ray+_y=%d\n", ray->position.y);
//		printf("deltas_x=%f\n", ray->deltas.x);
//		printf("deltas_y=%f\n", ray->deltas.y);
//		printf("direction_x=%d\n", ray->directions.x);
//		printf("direction_y=%d\n", ray->directions.y);
		colided = (map->map[ray->position.y][ray->position.x] != 0);
		joan(map, ray);
	}
}

void render(t_map *map)
{
	int 		cam_i;
	int			cam_end;
	t_ray		ray;
	t_f_point	cam_0;

	cam_end = SCREEN_WIDTH / 2;
	cam_i = 0 - cam_end;
	cam_0 = fdf_set_f_point(map->player.position.x + map->player.dir_vect.x,
		map->player.position.y + map->player.dir_vect.y, 0, 0);
	while (cam_i < cam_end)
	{
		ray.vect.x = cam_0.x + (map->player.cam_vect.x * cam_i / SCREEN_WIDTH);
		ray.vect.y = cam_0.y + (map->player.cam_vect.y * cam_i / SCREEN_WIDTH);
		if (cam_i % 20 == 0)
			print_half_ray(map, ray.vect);
		colide_ray(map, &ray);
		cam_i++;
	}
}

int	fdf_key_press_hook(int key, t_point *movement)
{
	if (key == KEY_D && !movement->x)
		movement->x = 1;
	if (key == KEY_A && !movement->x)
		movement->x = -1;
	if (key == KEY_W && !movement->y)
		movement->y = 1;
	if (key == KEY_S && !movement->y)
		movement->y = -1;
	if (key == KEY_RIGHT && !movement->z)
		movement->z = 1;
	if (key == KEY_LEFT && !movement->z)
		movement->z = -1;
	return (1);	
}

int	fdf_key_release_hook(int key, t_point *movement)
{
	if (key == KEY_D && movement->x == 1)
		movement->x = 0;
	if (key == KEY_A && movement->x == -1)
		movement->x = 0;
	if (key == KEY_W && movement->y == 1)
		movement->y = 0;
	if (key == KEY_S && movement->y == -1)
		movement->y = 0;
	if (key == KEY_RIGHT && movement->z == 1)
		movement->z= 0;
	if (key == KEY_LEFT && movement->z == -1)
		movement->z = 0;
	return (1);	
}
