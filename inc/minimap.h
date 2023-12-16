
#define PLAYER_WIDTH 5
#define PLAYER_HEIGHT 5
//#define SQUARES_SIZE 20
#define MINIMAP_SIZE 200
#define MAP_SQUARES_SIZE 1
#define MOVEMENT_DELTA	0.05
// #define MOVEMENT_DELTA	0.2
#define ROTATION_DELTA	0.01
# define SCREEN_WIDTH 2480
# define SCREEN_HEIGHT 1240
#include <math.h>

typedef struct	s_img {
	void	*img;
	void	*mlx_ptr;
	void	*win_ptr;
	char	*addr;
	int		bits_pxl;
	int		line_len;
	int		endian;
	int		width;  //maybe not needed
	int		height;  //maybe not needed
}				t_img;

// typedef struct map_s{
// 	char			**map;
// 	int	rows;	
// 	int	cols;	
// }	t_map;


// struct minimap_s;
// typedef struct minimap_s t_minimap;
// typedef struct point_s{
// 	int				x;
// 	int				y;
// 	int				z;
// 	int				color;
// }	t_point;


// typedef struct f_point_s{
// 	float			x;
// 	float			y;
// 	float			z;
// 	int				color;
// }	t_f_point;

// typedef struct player_s{
// 	t_f_point		position;
// 	float			dir_rad;
// 	t_f_point		dir_vect;
// 	float			dir_vect_len;
// 	t_f_point		camera;
// 	t_point			movement;
// } t_player;
		
// typedef struct map_s{
// 	char			**map;
// 	int				squares_size;
// 	int				rows;	
// 	int				cols;	
// 	int				width;
// 	int				hieght;
// 	t_player		player;
// 	t_minimap		*minimap;
// }	t_map			;

// typedef struct minimap_s{
// 	int				squares_size;
// 	int				rows;
// 	int				cols;
// 	t_point			img_position;
// 	t_map			*map;
// 	t_point			offsets;
// 	t_img			img;
// }	t_minimap		;

// typedef struct minimap_s{
// 	int				squares_size;
// 	int	rows;
// 	int	cols;
// 	t_point			img_position;
// 	// t_map			*map;
// 	t_point			offsets;
// 	t_img			img;
// }	t_minimap		;


/* KEY MAPPING */
#define KEY_W			13
#define KEY_A			0
#define KEY_S			1
#define KEY_D			2
#define KEY_LEFT		123
#define KEY_RIGHT		124

/* minimap */
// void draw_minimap(t_minimap *minimap);


/* points.c */
// int			fdf_mk_color(int transparency, int red, int green, int blue);
// void		fdf_print_pnt(t_point p);
// void		fdf_print_f_pnt(t_f_point p);
// t_point		fdf_set_point(int x, int y, int z, int color);
// void		fdf_put_pixel(void *img_ptr, unsigned int x, unsigned int y, int color);
// void		fdf_draw_line(t_img *img, t_point p1, t_point p2, int clr);

// /* main */
// void	my_mlx_pixel_put(t_img *data, int x, int y, int color);

// /* loop */
// int			run_game(t_map *map);
// int			fdf_key_press_hook(int key, t_point *movement);
// int			fdf_key_release_hook(int key, t_point *movement);

// /* src/minimap/minimap.c */
// int			minimap_draw_square(t_minimap *minimap, t_point pixel, t_point squares_size, int border);
// void		draw_minimap_tiles(t_minimap *minimap);
// void		draw_minimap(t_minimap *minimap);
// void		draw_player(t_minimap *minimap);

// /* src/utils.c */
// int			get_square_on_position(t_map *map, t_f_point position);
// t_f_point	from_rad_to_vect(float radians, float len);


// /* points.c */
// int		fdf_mk_color(int transparency, int red, int green, int blue);
// void	fdf_print_pnt(t_point p);
// t_point	fdf_set_point(int x, int y, int z, int color);
// void	fdf_put_pixel(void *img_ptr, unsigned int x, unsigned int y, int color);

// /* main */

// void	my_mlx_pixel_put(t_img *data, int x, int y, int color);

