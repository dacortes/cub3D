typedef struct map_s{
	char			**map;
	unsigned int	rows;	
	unsigned int	cols;	
}	t_map;

typedef struct point_s{
	int		x;
	int		y;
	int		z;
	int		color;
}	t_point;

typedef struct minimap_s{
	int				squares_size;
	unsigned int	rows;
	unsigned int	cols;
	t_point			offsets;
	img_dta			img;
	t_point			img_position;
	t_map			*map;
}	t_minimap		;

/* minimap */
void minimap(void *mlx_win);

/* points.c */
int		fdf_mk_color(int transparency, int red, int green, int blue);
void	fdf_print_pnt(t_point p);
t_point	fdf_set_point(int x, int y, int z);
void	fdf_put_pixel(void *img_ptr, unsigned int x, unsigned int y, int color);


