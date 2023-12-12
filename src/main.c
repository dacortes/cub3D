/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:57:07 by dacortes          #+#    #+#             */
/*   Updated: 2023/12/12 18:46:34 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

#define N -1
t_f_point	from_rad_to_vect(float degrees, float len);


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
	while (i < data->rows)
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
	while (i < data.rows)
	{
		j = 0;
		while (j < data.cols)
		{
			printf("% d", data.map[i][j++]);
		}
		printf("\n");
		i++;
	}
	return (EXIT_SUCCESS);
}

int	init_parse(t_map *data, int ac, char **av)
{
	t_aux	chk;
	int		fd;

	fd = -1;
	if (ac != 2)
		exit (msg_error(ARG, -1, NULL));
	parse_open(av[1], &fd);
	parse_data(&chk, fd, data);
	parse_map(&chk, av[1], data);
	printf_map(*data);
	if (fd >= 0)
		close (fd);	
	return (EXIT_SUCCESS);
}

int	close_win(t_map *minimap)
{
	(void)minimap;
	exit (0);
}


// int	main(int ac, char **av)
// {
// 	t_img		img;
// 	t_map		map;
// 	t_minimap	minimap;

// 	init_parse(&map, ac, av);
// 	img.mlx_ptr = mlx_init();
// 	img.win_ptr = mlx_new_window(img.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, "Hello world!");
// 	// map.img.mlx_ptr = img.mlx_ptr;
// 	// map.img.win_ptr = img.win_ptr;
// 	// map.img.img = mlx_new_image(map.img.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
// 	// map.img.width = SCREEN_WIDTH;
// 	// map.img.height = SCREEN_HEIGHT;
// 	// map.img.addr = mlx_get_data_addr(map.img.img, &map.img.bits_pxl,
// 	// 		&map.img.line_len, &map.img.endian);
		

// 	map.squares_size = MAP_SQUARES_SIZE;
// 	map.player.movement = fdf_set_point(0, 0, 0, 0);
// 	map.player.dir_vect_len = 0.5;
// 	map.player.dir_vect = from_rad_to_vect(map.player.dir_rad, map.player.dir_vect_len); // this should go inside minimap
// 	map.player.cam_vect_len = 0.333;
// 	map.minimap = &minimap;
// 	minimap.rows = map.rows - 0;
// 	minimap.cols = map.cols - 0;
// 	minimap.offsets = fdf_set_point(0,0,0,0); // Caution the offsets must be lower or equal than map.[rows|cols] - minimap.[rows|cols]
// 	minimap.squares_size = SQUARES_SIZE;
// 	minimap.map = &map;
// 	minimap.img.mlx_ptr = img.mlx_ptr;
// 	minimap.img.win_ptr = img.win_ptr;
// 	minimap.img.img = mlx_new_image(minimap.img.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
// 	minimap.img.width = SCREEN_WIDTH;
// 	minimap.img.height = SCREEN_HEIGHT;
// 	minimap.img.addr = mlx_get_data_addr(minimap.img.img, &minimap.img.bits_pxl,
// 			&minimap.img.line_len, &minimap.img.endian);
// map.img = minimap.img;
// //minimap.img.img = NULL;
// 	mlx_hook(minimap.img.win_ptr, 2, 1L << 0, fdf_key_press_hook, &map.player.movement); // This has to be changed to movement
// 	mlx_hook(minimap.img.win_ptr, 3, 1L << 1, fdf_key_release_hook, &map.player.movement); // This has to be changed to movement
// 	mlx_hook(minimap.img.win_ptr, 17, 0, close_win, &minimap);
// 	mlx_loop_hook(img.mlx_ptr, run_game, (void *) &map);
// 	mlx_loop(img.mlx_ptr);
// 	free(map.map);
// 	clear_data(&map);
// 	return (EXIT_SUCCESS);
// }

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

// int say_hello(t_map *map)
// {
// 	int y = 0;
// 	while (y < 500)
// 		my_mlx_pixel_put(&map->img, 5, y++, 0x00FF00);
// 	mlx_put_image_to_window(map->img.mlx_ptr, map->img.win_ptr, map->img.img, 0, 0);
// 	return (1);
// }

// int	main(int ac, char **av)
// {
// 	(void)ac;
// 	(void)av;
// 	t_map	map;
// //	t_img		img_minimap;

// 	map.img.mlx_ptr = mlx_init();
// 	map.img.win_ptr = mlx_new_window(map.img.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, "Pan");
// 	map.img.img = mlx_new_image(map.img.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
// 	map.img.addr = mlx_get_data_addr(map.img.img, &map.img.bits_pxl,
// 		&map.img.line_len, &map.img.endian);
// 	// int y = 0;
// 	// while (y < 500)
// 	// 	my_mlx_pixel_put(&map.img, 5, y++, 0x00FF00);


// //	img_minimap.mlx_ptr = map.img.mlx_ptr;
// //	img_minimap.win_ptr = map.img.win_ptr;
// //	img_minimap.img = mlx_new_image(img_minimap.mlx_ptr, MINIMAP_SIZE, MINIMAP_SIZE);
// //	img_minimap.addr = mlx_get_data_addr(img_minimap.img, &img_minimap.bits_pxl,
// //		&img_minimap.line_len, &img_minimap.endian);
// 	//t_minimap	minimap;

// /*
// 	init_parse(&map, ac, av);
// 	map.player.movement = fdf_set_point(0, 0, 0, 0);
// 	map.player.dir_vect_len = 0.5;
// 	map.player.dir_vect = from_rad_to_vect(map.player.dir_rad, map.player.dir_vect_len); // this should go inside minimap
// 	map.player.cam_vect_len = 0.333;
// 	map.minimap = &minimap;
// 	minimap.rows = map.rows - 0;
// 	minimap.cols = map.cols - 0;
// 	minimap.offsets = fdf_set_point(0,0,0,0); // Caution the offsets must be lower or equal than map.[rows|cols] - minimap.[rows|cols]
// 	if (map.rows > map.cols) 
// 		minimap.squares_size = MINIMAP_SIZE / map.rows;
// 	else
// 		minimap.squares_size = MINIMAP_SIZE / map.cols;	
// 	minimap.img.width = MINIMAP_SIZE;
// 	minimap.img.height = MINIMAP_SIZE;
// */
// //	minimap.img = img_minimap;







// 	// mlx_put_image_to_window(img_minimap.mlx_ptr, img_minimap.win_ptr,img_minimap.img, 0, 0);
// 	// run_game(&map);
	
// 	// mlx_put_image_to_window(map.img.mlx_ptr, map.img.win_ptr,map.img.img, 0, 0);
// 	mlx_hook(map.img.win_ptr, 17, 0, close_win, &map);
// 	mlx_hook(map.img.win_ptr, 2, 1L << 0, fdf_key_press_hook, &map.player.movement); // This has to be changed to movement
// 	mlx_hook(map.img.win_ptr, 3, 1L << 1, fdf_key_release_hook, &map.player.movement); // This has to be changed to movement
// 	//mlx_loop_hook(map.img.win_ptr, run_game, (void *) &map);
// 	mlx_loop_hook(map.img.win_ptr, say_hello, NULL);
// 	mlx_loop(map.img.mlx_ptr);
// 	// free(map.map);
// 	// clear_data(&map);
// 	return (EXIT_SUCCESS);
// }

int	say_hello(t_map *map)
{
	int y = 0;
	while (y < 500)
	{
		my_mlx_pixel_put(&map->img, 5, y++, 0x00FF00);
	}
	mlx_put_image_to_window(map->img.mlx_ptr, map->img.win_ptr, map->img.img, 0, 0);
	return (1);
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_map	map;

	map.img.mlx_ptr = mlx_init();
	map.img.win_ptr = mlx_new_window(map.img.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, "Pan");
	map.img.img = mlx_new_image(map.img.mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	map.img.addr = mlx_get_data_addr(map.img.img, &map.img.bits_pxl,
		&map.img.line_len, &map.img.endian);
	mlx_hook(map.img.win_ptr, 17, 0, close_win, &map);
	mlx_hook(map.img.win_ptr, 2, 1L << 0, fdf_key_press_hook, &map);
	mlx_hook(map.img.win_ptr, 3, 1L << 1, fdf_key_release_hook, &map);
	mlx_loop_hook(map.img.win_ptr, say_hello, &map);
	mlx_loop(map.img.mlx_ptr);
	return (EXIT_SUCCESS);
}