
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
void render(t_map *map)
{
	int 		cam_i;
	int			cam_end;
	t_f_point	ray_v;
	t_f_point	cam_0;

	cam_end = SCREEN_WIDTH / 2;
	cam_i = 0 - cam_end;
	cam_0 = fdf_set_f_point(map->player.position.x + map->player.dir_vect.x,
		map->player.position.y + map->player.dir_vect.y, 0, 0);
	while (cam_i < cam_end)
	{
		ray_v.x = cam_0.x + (map->player.cam_vect.x * cam_i / SCREEN_WIDTH);
		ray_v.y = cam_0.y + (map->player.cam_vect.y * cam_i / SCREEN_WIDTH);
		if (cam_i % 20 == 0)
			print_half_ray(map, ray_v);
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
