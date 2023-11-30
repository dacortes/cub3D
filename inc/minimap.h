#define PLAYER_WIDTH 5
#define PLAYER_HEIGHT 5
#define SQUARES_SIZE 200

#include <math.h>
struct minimap_s;
typedef struct minimap_s t_minimap;
typedef struct point_s{
	int				x;
	int				y;
	int				z;
	int				color;
}	t_point;

typedef struct f_point_s{
	float			x;
	float			y;
	float			z;
	int				color;
}	t_f_point;

typedef struct player_s{
	t_f_point		position;
	float			dir_rad;
	t_f_point		dir_vect;
	float			dir_vect_len;
	t_f_point		camera;
	t_point		movement;
} t_player;
		
typedef struct map_s{
	char					**map;
	int				squares_size;
	int						rows;	
	int						cols;	
	int						width;
	int						hieght;
	t_player				player;
	t_minimap				*minimap;
}	t_map;

typedef struct minimap_s{
	int				squares_size;
	int				rows;
	int				cols;
	t_point			img_position;
	t_map			*map;
	t_point			offsets;
	t_img			img;
}	t_minimap		;

/* events stuff */
#define KEY_W			13
#define KEY_A			0
#define KEY_S			1
#define KEY_D			2
#define KEY_LEFT		123
#define KEY_RIGHT		124
#define MOVEMENT_DELTA	10
#define ROTATION_DELTA	0.01

/* minimap */
void draw_minimap(t_minimap *minimap);

/* points.c */
int		fdf_mk_color(int transparency, int red, int green, int blue);
void	fdf_print_pnt(t_point p);
void	fdf_print_f_pnt(t_f_point p);
t_point	fdf_set_point(int x, int y, int z, int color);
void	fdf_put_pixel(void *img_ptr, unsigned int x, unsigned int y, int color);
void	fdf_draw_line(t_img *img, t_point p1, t_point p2, int clr);

/* main */

void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
