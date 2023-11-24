#include "../../inc/cub3D.h"
#include <stdio.h>

int minimap_draw_square(t_minimap *minimap, t_point pixel, int width, int height)
{
	int		i;
	int		j;

	i = 0;
	while (i < width)
	{
		j = 0;
		while (j < height)
		{
			my_mlx_pixel_put(&minimap->img,  pixel.x + i, pixel.y + j, pixel.color);
			j++;
		}
		i++;
	}
	return (0);
}

/*
int init_minimap_img(t_minimap minimap)
{
	return (0);
}
*/

void draw_minimap(t_minimap *minimap)
{
	t_point coord;
	t_point pixel;
	int		square_type;

	coord.y = 0;
	while (coord.y < minimap->rows)
	{
		coord.x = 0;	
		while (coord.x < minimap->cols)
		{
			square_type = minimap->map->map[coord.y + minimap->offsets.y][coord.x + minimap->offsets.x] ;
			if (square_type == 1)
				pixel.color = fdf_mk_color(125, 0, 255, 0);	
			else if (square_type == -1)
				pixel.color = fdf_mk_color(0, 0, 0, 0);	
			else
				pixel.color = fdf_mk_color(125, 0, 0, 255);	
			pixel.x = coord.x * minimap->squares_size;
			pixel.y = coord.y * minimap->squares_size;
			minimap_draw_square(minimap, pixel, minimap->squares_size, minimap->squares_size);
			coord.x++;
		}
		coord.y++;	
	}
}
