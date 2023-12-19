/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:57:07 by dacortes          #+#    #+#             */
/*   Updated: 2023/12/19 09:32:29 by dacortes         ###   ########.fr       */
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
	check_extension(av[1], ".cub");
	parse_open(av[1], &fd);
	parse_data(&chk, fd, data);
	parse_map(&chk, av[1], data);
	printf_map(*data);
	if (fd >= 0)
		close (fd);
	return (EXIT_SUCCESS);
}

int	hooks(t_map *map)
{
	mlx_hook(map->img.win_ptr, 17, 0, close_win, map);
	mlx_hook(map->img.win_ptr, 2, 1L << 0, fdf_key_press_hook, \
		&map->player.movement);
	mlx_hook(map->img.win_ptr, 3, 1L << 1, fdf_key_release_hook, \
		&map->player.movement);
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_map		map;
	t_minimap	minimap;

	init_parse(&map, ac, av);
	init_mlx(&map.img, NULL, "cub3D", TRUE);
	init_var(&map, &minimap);
	init_mlx(&map.img, &minimap.img, NULL, FALSE);
	init_texture(&map.texture_no, &map.img, map.no);
	init_texture(&map.texture_so, &map.img, map.so);
	init_texture(&map.texture_we, &map.img, map.we);
	init_texture(&map.texture_ea, &map.img, map.ea);
	hooks(&map);
	mlx_loop_hook(map.img.mlx_ptr, run_game, (void *) &map);
	mlx_loop(map.img.mlx_ptr);
	free(map.map);
	clear_data(&map);
	return (EXIT_SUCCESS);
}
