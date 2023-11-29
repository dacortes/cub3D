/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:57:07 by dacortes          #+#    #+#             */
/*   Updated: 2023/11/28 10:10: by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

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

	fd = -1;
	if (ac != 2)
		exit (msg_error(ARG, -1, NULL));
	parse_open(av[1], &fd);
	parse_data(&chk, fd, &data);
	parse_map(&chk, av[1], &data);
	ft_printf("texture no %s\n", data.no);
	ft_printf("texture ea %s\n", data.ea);
	ft_printf("texture so %s\n", data.so);
	ft_printf("texture we %s\n", data.we);
	printf_map(data);
	clear_data(&data);
	if (fd >= 0)
		close (fd);
	return (EXIT_SUCCESS);
	/*void	*mlx;
	void	*mlx_win;
	t_data	img;
	char	mtrx[][] = {
		{1,1,1,1,1,1},
		{1,0,0,0,0,1},
		{1,0,0,0,0,1},
		{1,0,0,0,0,1},
		{1,1,1,1,1,1}
	};
	t_map	map;
	t_minimap	minimap;

	map.map = map_mtrx;
	map.rows = 6;
	map.cols = 5;

	minimap.rows = map.rows;
	minimap.cols = map.cols;
	minimap.img = mlx_new_image(mlx, 1920, 1080);



	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	printf("testing minimap\n");
	minimap(mlx_win);
	printf("tested minimap\n");
	mlx_loop(mlx);*/
}
