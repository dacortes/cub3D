#include "../../inc/cub3D.h"
#include <stdio.h>

int minimap_draw_square(t_minimap *minimap, t_point coord, int width, int height)
{
	int		i;
	int		j;

//	row = minimap.offset.x + row;
//	col = minimap.offset.y + col;
	if (coord.x > minimap->cols || coord.y > minimap->rows)
	{
		printf("error on draw square inp\n");
		return (-1);
	}
	i = 0;
	while (i < width)
	{
		j = 0;
		while (j < height)
		{
			//fdf_put_pixel(minimap->img.img, coord.x * width + i,
			//coord.y * height + j, coord.color);
			my_mlx_pixel_put(&minimap->img,  coord.x * width + i,
					coord.y * height + j, coord.color);
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
	int		square_type;

	coord.y = 0;
	while (coord.y < minimap->rows)
	{
		coord.x = 0;	
		while (coord.x < minimap->cols)
		{
			square_type = minimap->map->map[coord.y + minimap->offsets.y][coord.x + minimap->offsets.x] ;
			if (square_type == 1)
			{
				coord.color = fdf_mk_color(125, 0, 255, 0);	
			}
			else if (square_type == -1)
			{
				coord.color = fdf_mk_color(0, 0, 0, 0);	
			}
			else
			{
				coord.color = fdf_mk_color(125, 0, 0, 255);	
			}
			minimap_draw_square(minimap, coord, minimap->squares_size, minimap->squares_size);
			coord.x++;
		}
		coord.y++;	
	}
}
