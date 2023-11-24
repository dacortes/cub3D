#include "../../inc/cub3D.h"

int	fdf_mk_color(int transparency, int red, int green, int blue)
{
	int	color;

	color = 0;
	color = color | transparency;
	color = color << 8;
	color = color | red;
	color = color << 8;
	color = color | green;
	color = color << 8;
	color = color | blue;
	return (color);
}

void	fdf_print_pnt(t_point p)
{
	printf("(%d, %d, %d)", p.x, p.y, p.z);
}

t_point	fdf_set_point(int x, int y, int z, int color)
{
	t_point	result;

	result.x = x;
	result.y = y;
	result.z = z;
	result.color = color;
	return (result);
}
/*
void	fdf_put_pixel(void *img_ptr, unsigned int x, unsigned int y, int color)
{
	char	*img_dta;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		bytes_per_pixel;

//	x += img->width / 2; 
//	y += img->height / 2; 
	if (x >= img->width) // maybe not needed
		return ; 		// maybe not needed
	if (y >= img->height) // maybe not needed
		return ; 		// maybe not needed
	img_dta = mlx_get_data_addr(img_ptr, &bits_per_pixel, &size_line, &endian);//maybe its already on the img structure?
	bytes_per_pixel = bits_per_pixel / 8;
	if (bytes_per_pixel != 4)
		ft_printf("The bytes per pixel is not 4 !!!!!!!!\n");
	ft_memcpy(img_dta + ((x * bytes_per_pixel) % size_line + y * size_line),
		&color, sizeof(int));
}
*/