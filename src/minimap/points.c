#include "../../inc/cub3D.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bits_pxl / 8));
	*(unsigned int*)dst = color;
}


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
	printf("(%d, %d, %d)", p.x, p.y, p.z); // FORBIDDEN FUNCTION
}

void	fdf_print_f_pnt(t_f_point p)
{
	printf("(%f, %f, %f)", p.x, p.y, p.z); // FORBIDDEN FUNCTION
}

void	fdf_swap_point(t_point *p1, t_point *p2)
{
	t_point	aux_p;

	aux_p = *p1;
	*p1 = *p2;
	*p2 = aux_p;
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

t_f_point	fdf_set_f_point(float x, float y, float z, int color)
{
	t_f_point	result;

	result.x = x;
	result.y = y;
	result.z = z;
	result.color = color;
	return (result);
}

void	fdf_draw_on_same_x(void *img, t_point p1, t_point p2, int clr)
{
	t_point	lst_p;	
	t_point	cur_p;	

	if (p1.y > p2.y)
		fdf_swap_point(&p1, &p2);
	lst_p = p1;
	cur_p = p1;
	while (cur_p.y <= p2.y)
	{
		my_mlx_pixel_put(img, p1.x, cur_p.y, clr);
		cur_p.y++;
	}
}

void	fdf_draw_line(t_img *img, t_point p1, t_point p2, int clr)
{
	float	d;
	t_point	lst_p;	
	t_point	cur_p;	


	if (p1.x == p2.x)
		return (fdf_draw_on_same_x(img, p1, p2, clr));
	if (p1.x > p2.x)
		fdf_swap_point(&p1, &p2);
	lst_p = p1;
	cur_p = p1;
	d = (float)(p2.y - p1.y) / (float)(p2.x - p1.x);
	while (cur_p.x <= p2.x)
	{
		my_mlx_pixel_put(img, cur_p.x, cur_p.y, clr);
		if (lst_p.y != cur_p.y
			&& (lst_p.y + 1 != cur_p.y && lst_p.y != cur_p.y + 1))
		{
			lst_p.x = cur_p.x;
			lst_p.y += ((d > 0) * 2) - 1;
			fdf_draw_line(img, lst_p, cur_p, clr);
		}
		lst_p = cur_p;
		cur_p.x++;
		cur_p.y = p1.y + (cur_p.x - p1.x) * d;
	}
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
