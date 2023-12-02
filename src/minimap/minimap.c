#include "../../inc/cub3D.h"
#include <stdio.h>

void draw_minimap_tiles(t_minimap *minimap);
void draw_player(t_minimap *minimap);

int minimap_draw_square(t_minimap *minimap, t_point pixel, t_point squares_size, int border)
{
	int		i;
	int		j;

	i = 0;
	while (i < squares_size.x)
	{
		j = 0;
		while (j < squares_size.y)
		{
			my_mlx_pixel_put(&minimap->img,  pixel.x + i, pixel.y + j, pixel.color);
			if (i == 0 || j == 0 || i == squares_size.x -1 || j == squares_size.y - 1)
				my_mlx_pixel_put(&minimap->img,  pixel.x + i, pixel.y + j, border);
			j++;
		}
		i++;
	}
	return (0);
}

void draw_minimap_tiles(t_minimap *minimap)
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
				pixel.color = fdf_mk_color(0, 0, 125, 60);	
			else if (square_type == -1)
				pixel.color = fdf_mk_color(0, 0, 0, 0);	
			else
				pixel.color = fdf_mk_color(254, 0, 0, 255);	
			pixel.x = coord.x * minimap->squares_size;
			pixel.y = coord.y * minimap->squares_size;
			minimap_draw_square(minimap, pixel, fdf_set_point(minimap->squares_size, minimap->squares_size, 0, 0), fdf_mk_color(0, 255, 125, 0));
			coord.x++;
		}
		coord.y++;	
	}
}

void	draw_player(t_minimap *minimap)
{
	t_point		position;
	t_point		direction_end;
	t_player		player;

	player = minimap->map->player;
	position = fdf_set_point(player.position.x, player.position.y, 0, 0);
	position.x -= minimap->offsets.x * minimap->squares_size;
	position.y -= minimap->offsets.y * minimap->squares_size;
	position.color = fdf_mk_color(0, 255, 255, 0);	
	direction_end = position;
	direction_end.x += player.dir_vect.x * minimap->squares_size;
	direction_end.y += player.dir_vect.y * minimap->squares_size;
	fdf_draw_line(&minimap->img, position, direction_end, position.color);
	position.x -= PLAYER_WIDTH / 2;
	position.y -= PLAYER_HEIGHT / 2;

	minimap_draw_square(minimap, position, fdf_set_point(PLAYER_WIDTH, PLAYER_HEIGHT, 0, 0),
			fdf_mk_color(0, 255 , 255 , 255));

	//fdf_print_pnt(position);
	//fdf_print_pnt(direction_end);
	//printf("DRAWING LINE\n");
}

void draw_minimap(t_minimap *minimap)
{
	draw_minimap_tiles(minimap);
	draw_player(minimap);
}
