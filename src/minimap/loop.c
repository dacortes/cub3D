
#include "../inc/cub3D.h"

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
	map->player.dir_vect = from_rad_to_vect(map->player.dir_rad, map->player.dir_vect_len); // this should go inside minimap
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
	mlx_put_image_to_window(minimap->img.mlx_ptr, minimap->img.win_ptr,
			minimap->img.img, 0, 0);
	return (1);
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
	fdf_print_pnt(*movement);
	printf("The pressed key was: %d\n", key);
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
	fdf_print_pnt(*movement);
	printf("The released key was: %d\n", key);
	return (1);	
}
