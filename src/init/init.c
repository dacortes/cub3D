/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:36:50 by dacortes          #+#    #+#             */
/*   Updated: 2023/12/21 18:44:04 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	init_var(t_map *map, t_minimap *minimap)
{
	map->player.movement = fdf_set_point(0, 0, 0, 0);
	map->player.dir_vect_len = 0.6666;
	map->player.dir_vect = from_rad_to_vect(map->player.dir_rad, \
		map->player.dir_vect_len);
	map->player.cam_vect_len = 0.76666;
	map->minimap = minimap;
	minimap->rows = map->rows - 0;
	minimap->cols = map->cols - 0;
	minimap->offsets = fdf_set_point(0, 0, 0, 0);
	if (map->rows > map->cols)
		minimap->squares_size = MINIMAP_SIZE / map->rows;
	else
		minimap->squares_size = MINIMAP_SIZE / map->cols;
	minimap->img.height = minimap->squares_size * map->rows;
	minimap->img.width = minimap->squares_size * map->cols;
	minimap->map = map;
	return (EXIT_SUCCESS);
}

int	init_texture(t_img *texture, t_img *img, char *path)
{
	texture->img = mlx_xpm_file_to_image(img->mlx_ptr, path, &texture->width, \
		&texture->height);
	texture->addr = mlx_get_data_addr(texture->img, &texture->bits_pxl, \
		&texture->line_len, &texture->endian);
	return (EXIT_SUCCESS);
}

int	init_mlx(t_img *map, t_img *mini, char *name_win, int type)
{
	if (type && !mini)
	{
		map->mlx_ptr = mlx_init();
		map->win_ptr = mlx_new_window(map->mlx_ptr, SCREEN_WIDTH, \
			SCREEN_HEIGHT, name_win);
		map->img = mlx_new_image(map->mlx_ptr, SCREEN_WIDTH, \
			SCREEN_HEIGHT);
		map->addr = mlx_get_data_addr(map->img, &map->bits_pxl, \
			&map->line_len, &map->endian);
	}
	else
	{
		mini->mlx_ptr = map->mlx_ptr;
		mini->win_ptr = map->win_ptr;
		mini->img = mlx_new_image(mini->mlx_ptr, mini->width, mini->height);
		mini->addr = mlx_get_data_addr(mini->img, &mini->bits_pxl, \
			&mini->line_len, &mini->endian);
	}
	return (EXIT_SUCCESS);
}
