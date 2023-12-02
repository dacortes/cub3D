/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:57:07 by dacortes          #+#    #+#             */
/*   Updated: 2023/11/28 15:05:50 by jrenau-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"


#define N -1
t_f_point	from_rad_to_vect(float degrees, float len);

int	fdf_key_press_hook(int key, t_point *movement)
{
	if (key == KEY_A && !movement->x)
		movement->x = -1;
	if (key == KEY_D && !movement->x)
		movement->x = 1;
	if (key == KEY_W && !movement->y)
		movement->y = -1;
	if (key == KEY_S && !movement->y)
		movement->y = 1;
	if (key == KEY_LEFT && !movement->z)
		movement->z = -1;
	if (key == KEY_RIGHT && !movement->z)
		movement->z = 1;
	fdf_print_pnt(*movement);
	printf("The pressed key was: %d\n", key);
	return (1);	
}

int	fdf_key_release_hook(int key, t_point *movement)
{
	if (key == KEY_A && movement->x == -1)
		movement->x = 0;
	if (key == KEY_D && movement->x == 1)
		movement->x = 0;
	if (key == KEY_W && movement->y == -1)
		movement->y = 0;
	if (key == KEY_S && movement->y == 1)
		movement->y = 0;
	if (key == KEY_LEFT && movement->z == -1)
		movement->z = 0;
	if (key == KEY_RIGHT && movement->z == 1)
		movement->z= 0;
	fdf_print_pnt(*movement);
	printf("The released key was: %d\n", key);
	return (1);	
}

int run_game(t_map *map)
{
	t_minimap	*minimap;
	t_player	*player;

	player = &map->player;
	minimap = map->minimap;
	map->player.dir_rad +=  ROTATION_DELTA * map->player.movement.z;
	map->player.dir_rad +=  ROTATION_DELTA * map->player.movement.z;
	map->player.dir_vect = from_rad_to_vect(map->player.dir_rad, map->player.dir_vect_len); // this should go inside minimap
	player->position.x +=  player->movement.x * MOVEMENT_DELTA ;
	player->position.y +=  player->movement.y * MOVEMENT_DELTA ;
	printf("py: %d, py:%d\n", player->position.x, player->position.y);
	//player.position.x += player.dir_vect.x * (float) player.movement.x * MOVEMENT_DELTA *50000000;
	//player.position.y += player.dir_vect.y * (float) player.movement.y * MOVEMENT_DELTA *50000000;
	/*
	printf("py: %d, py:%d\n", player.position.x, player.position.y);
	printf("sdaf: %f\n", player.dir_vect.x * player.movement.x * MOVEMENT_DELTA*50000000);
	printf("sdaf: %f\n", player.dir_vect.y * player.movement.y * MOVEMENT_DELTA*50000000);
	printf("dx: %f, dy:%f\n", player.dir_vect.x, player.dir_vect.y);
	printf("mx: %d, my:%d\n", player.movement.x, player.movement.y);
	printf("px: %d, py:%d\n\n", player.position.x, player.position.y);
//	printf(" radianes %f\n", map->player.dir_rad);
	*/
	draw_minimap(minimap);
	mlx_put_image_to_window(minimap->img.mlx_ptr, minimap->img.win_ptr,
			minimap->img.img, 0, 0);
	return (1);
}


int	main(void)
{
	t_img		img;
	t_map		map;
	t_minimap	minimap;
	char	map_mtrx[5][6] = {
		{1,1,1,1,1,1},
		{1,0,0,0,0,1},
		{1,1,1,1,1,1},
		{1,1,N,N,1,1},
		{1,1,N,N,1,1}
	};

	img.mlx_ptr = mlx_init();
	img.win_ptr = mlx_new_window(img.mlx_ptr, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(img.mlx_ptr, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_pxl, &img.line_len,
								&img.endian);
	//img.addr = mlx_get_data_addr(minimap.img.img, &minimap.img.bits_pxl,
			//&minimap.img.line_len, &minimap.img.endian);

	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(img.mlx_ptr, img.win_ptr, img.img, 0, 0);

int	clear_data(t_map *data)
{
	int	i;

	if (data->no)
		free(data->no);
	if (data->so)
		free(data->so);
	if (data->we)
		free(data->we);
	if (data->ea)
		free(data->ea);
	i = 0;
	while (i < data->row)
	{
		free (data->map[i]);
		data->map[i] = NULL;
		++i;
	}
	if (data->map)
	{
		free (data->map);
		data->map = NULL;
	}
	return (EXIT_SUCCESS);
}

int	printf_map(t_map data)
{
	int	i;
	int	j;


	i = 0;
	while (i < data.row)
	{
		j = 0;
		while (j < data.col)
		{
			printf("% d", data.map[i][j++]);
		}
		printf("\n");
		i++;
	}
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_map	data;
	t_aux	chk;
	int		fd;


	map.map = malloc (sizeof(char**) * 5);
	for (int i = 0; i < 5; i++)
	{
		map.map[i] = malloc(sizeof(char*) * 6);
		for (int j = 0; j < 6; j++)
		{
			map.map[i][j] = map_mtrx[i][j];
		}
	}

	map.rows = 5;
	map.cols = 6;
	map.player.position.x = 2.5 * SQUARES_SIZE;
	map.player.position.y = 1.5 * SQUARES_SIZE;
	map.player.movement = fdf_set_point(0, 0, 0, 0);
	map.player.dir_rad = 1.57 * 1.5;
	map.player.dir_rad = 0;
	map.player.dir_vect_len = 0.5;
	map.player.dir_vect = from_rad_to_vect(map.player.dir_rad, map.player.dir_vect_len); // this should go inside minimap
	map.minimap = &minimap;
	fdf_print_f_pnt(map.player.dir_vect);
	printf("  this was the dir_vector \n");
//	map.player.direction.x = -2;
//	map.player.direction.y = 1;
	minimap.rows = map.rows - 0;
	minimap.cols = map.cols - 0;
	minimap.offsets = fdf_set_point(0,0,0,0); // Caution the offsets must be lower or equal than map.[rows|cols] - minimap.[rows|cols]
	minimap.squares_size = SQUARES_SIZE;
	minimap.map = &map;
	fdf_print_pnt(minimap.offsets);
	//minimap.map = &map;
	minimap.img.mlx_ptr = img.mlx_ptr;
	minimap.img.win_ptr = img.win_ptr;
	minimap.img.img = mlx_new_image(minimap.img.mlx_ptr, 1920, 1080);
	minimap.img.width = 1920;
	minimap.img.height = 1080;
	minimap.img.addr = mlx_get_data_addr(minimap.img.img, &minimap.img.bits_pxl,
			&minimap.img.line_len, &minimap.img.endian);
	draw_minimap(&minimap);
	mlx_put_image_to_window(minimap.img.mlx_ptr, minimap.img.win_ptr,
			minimap.img.img, 0, 0);
	mlx_hook(minimap.img.win_ptr, 2, 1L << 0, fdf_key_press_hook, &map.player.movement); // This has to be changed to movement
	mlx_hook(minimap.img.win_ptr, 3, 1L << 1, fdf_key_release_hook, &map.player.movement); // This has to be changed to movement
	mlx_loop_hook(img.mlx_ptr, run_game, (void *) &map);
	mlx_loop(img.mlx_ptr);

	free(map.map);

	fd = -1;
	if (ac != 2)
		exit (msg_error(ARG, -1, NULL));
	parse_open(av[1], &fd);
	parse_data(&chk, fd, &data);
	parse_map(&chk, av[1], &data);
	// ft_printf("texture no %s\n", data.no);
	// ft_printf("texture ea %s\n", data.ea);
	// ft_printf("texture so %s\n", data.so);
	// ft_printf("texture we %s\n", data.we);
	// ft_printf("--------------->Color");
	// ft_printf("--->floor\n");
	ft_printf("red :%d\n", data.floor.red);
	ft_printf("green :%d\n", data.floor.green);
	ft_printf("blue :%d\n", data.floor.blue);
	ft_printf("--->ceiling\n");
	ft_printf("red :%d\n", data.ceiling.red);
	ft_printf("green :%d\n", data.ceiling.green);
	ft_printf("blue :%d\n", data.ceiling.blue);
	// printf_map(data);
	clear_data(&data);
	if (fd >= 0)
		close (fd);
	return (EXIT_SUCCESS);
}
