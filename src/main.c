/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:57:07 by dacortes          #+#    #+#             */
/*   Updated: 2023/11/22 17:47:22 by jrenau-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bits_pxl / 8));
	*(unsigned int*)dst = color;
}

#define N -1
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

	printf("woook\n");
	img.mlx_ptr = mlx_init();
	img.win_ptr = mlx_new_window(img.mlx_ptr, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(img.mlx_ptr, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_pxl, &img.line_len,
								&img.endian);
	//img.addr = mlx_get_data_addr(minimap.img.img, &minimap.img.bits_pxl,
			//&minimap.img.line_len, &minimap.img.endian);

	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(img.mlx_ptr, img.win_ptr, img.img, 0, 0);



	printf("testing minimap\n");
	map.map = malloc (sizeof(char**) * 5);
	printf("fresh  minimap: %p val: %d\n",minimap.map->map, 42); // minimap.map->map[0][0]);
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
	minimap.rows = map.rows - 0;
	minimap.cols = map.cols - 0;
	minimap.offsets = fdf_set_point(0,0,0,0); // Caution the offsets must be lower or equal than map.[rows|cols] - minimap.[rows|cols]
	minimap.squares_size = 20;
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

	mlx_loop(img.mlx_ptr);

	free(map.map);
}
