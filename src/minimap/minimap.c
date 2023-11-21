#include "../../inc/cub3D.h"

int minimap_draw(t_minimap minimap, unsigned int row, unsigned int col)
{
	int		i;
	int		j;
	int		color;

	if (minimap->map.map[row][col])
		color = fdf_mk_color(125, 0, 255, 0);	
	else
		color = fdf_mk_color(125, 0, 0, 255);	
//	row = minimap.offset.x + row;
//	col = minimap.offset.y + col;
	if (row > minimap->map.rows || col > minimap->map.cols)
		return (-1);
	if (row > minimap.rows || col > minimap.cols)
		return (-1);
	i = 0;
	while (i < minimap.squares_size)
	{
		j = 0;
		while (j < minimap.squares_size)
		{
			fdf_put_pixel(minimap.image, row * minimap.squares_size + i,
				col * minimap.squares_size + j, color);
			j++;
		}
		i++;
	}
	return (0);
}

int init_minimap_img(t_minimap minimap)
{
	return (0);
}

void minimap(t_minimap minimap)
{
	int row;
	int col;

	if (mlx_win)
		printf("Hello minimap\n");
	row = 0;
	while (row < minimap.rows)
	{
		col = 0;	
		while (col < minimap.cols)
		{
			minimap_draw(minimap, row, col);
			col++;
		}
		row++;	
	}
}
