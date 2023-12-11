
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
	ray->deltas = fdf_set_f_point(fabs(1.0 / ray->vect.x), fabs(1.0 / ray->vect.y), 0, 0);
	ray->position = fdf_set_point(player_pos.x, player_pos.y, 0, 0);
	if (ray->vect.x < 0)
	{
		ray->distances.x = (player_pos.x - ray->position.x ) * ray->deltas.x; 	
		ray->directions.x = -1;
	}	
	else
	{
		ray->distances.x = ( ((float) (1 + ray->position.x)) - player_pos.x ) * ray->deltas.x; 	
		ray->directions.x = 1;
	}
	if (ray->vect.y < 0)
	{
		ray->distances.y = (player_pos.y - ray->position.y ) * ray->deltas.y; 	
		ray->directions.y = -1;
	}	
	else
	{
		ray->distances.y = ( (float) (1 + ray->position.y) - player_pos.y ) * ray->deltas.y;
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
		// printf("sdafffff\n");
		diferential = ray->vect.y / ray->vect.x;
		// printf("diferential: %f\n", diferential);
		if (fabs(diferential) > 50.0)
			diferential = 50.0 * ((diferential > 0) * 2 - 1);

		constant = map->player.position.y - map->player.position.x * diferential; 
		x = ray->position.x + (ray->vect.x < 0); //+ map->player.position.x;
		y = x * diferential + constant;
	}
	else  //get x from y
	{
		// printf("ffffasd\n");
		diferential = ray->vect.x / ray->vect.y;
		// printf("diferential: %f\n", diferential);
		if (fabs(diferential) > 50.0)
			diferential = 50.0 * ((diferential > 0) * 2 - 1);
		constant = map->player.position.x - map->player.position.y * diferential; 
		y = ray->position.y + (ray->vect.y < 0);// + map->player.position.y;	
		x = y * diferential + constant;
	}

	//fdf_print_f_point("Player position", map->player.position, "\n");
	//fdf_print_f_point("Ray vector ", ray->vect, "\n");
	//fdf_print_point("Ray position ", ray->position, "\n");
	// printf("diferential: %f, constant: %f\n", diferential, constant);
	// printf("x: %f, y: %f\n", x, y);
	starts.x = map->player.position.x * map->minimap->squares_size; // should aply offset
	starts.y = map->player.position.y * map->minimap->squares_size; // should aply offset
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
		return ; // Should be handled
	// fdf_print_f_point("Deltas: ", ray->deltas, "\n");
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
		joan(map, ray);
	}
	// fdf_print_f_point("Player position: ", map->player.position, "\n");
	// fdf_print_f_point("Ray cam intersect: ", ray->cam_intersect, "\n");
	// fdf_print_f_point("Ray vector: ", ray->vect, "\n");
	// fdf_print_point("Ray position: ", ray->position, "\n");
	// printf("\n");
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
		// if (cam_i++ != 0)
		// 	continue;
		ray.cam_intersect.x = cam_0.x + (map->player.cam_vect.x * cam_i / cam_end);
		ray.cam_intersect.y = cam_0.y + (map->player.cam_vect.y * cam_i / cam_end);
		if (cam_i % 1 == 0)
			print_half_ray(map, ray.cam_intersect);
		ray.vect.x = ray.cam_intersect.x - map->player.position.x;
		ray.vect.y = ray.cam_intersect.y - map->player.position.y;
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
