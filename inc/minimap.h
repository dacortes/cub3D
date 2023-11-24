typedef struct map_s{
	char			**map;
	int	rows;	
	int	cols;	
}	t_map;

typedef struct point_s{
	int		x;
	int		y;
	int		z;
	int		color;
}	t_point;

typedef struct minimap_s{
	int				squares_size;
	int	rows;
	int	cols;
	t_point			img_position;
	t_map			*map;
	t_point			offsets;
	t_img			img;
}	t_minimap		;

/* minimap */
void draw_minimap(t_minimap *minimap);

/* points.c */
int		fdf_mk_color(int transparency, int red, int green, int blue);
void	fdf_print_pnt(t_point p);
t_point	fdf_set_point(int x, int y, int z, int color);
void	fdf_put_pixel(void *img_ptr, unsigned int x, unsigned int y, int color);

/* main */

void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
