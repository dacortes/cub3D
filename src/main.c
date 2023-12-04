/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:57:07 by dacortes          #+#    #+#             */
/*   Updated: 2023/12/04 13:26:51 by jrenau-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

#define N -1
t_f_point	from_rad_to_vect(float degrees, float len);



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
	map.squares_size = SQUARES_SIZE;
	map.player.position.x = 2.5 * SQUARES_SIZE;
	map.player.position.y = 1.5 * SQUARES_SIZE;
	map.player.movement = fdf_set_point(0, 0, 0, 0);
	map.player.dir_rad = 1.57 * 1.5;
	map.player.dir_rad = 0;
	map.player.dir_vect_len = 0.5;
	map.player.dir_vect = from_rad_to_vect(map.player.dir_rad, map.player.dir_vect_len); // this should go inside minimap
	map.player.cam_vect_len = 0.333;
	map.minimap = &minimap;
	fdf_print_f_pnt(map.player.dir_vect);
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
}
