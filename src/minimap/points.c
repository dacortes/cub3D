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

void	fdf_print_point(char *start, t_point p, char *end)
{
	if (start)
		printf("%s", start);
	printf("(%d, %d, %d)", p.x, p.y, p.z); // FORBIDDEN FUNCTION
	if (end)
		printf("%s", end);
}

void	fdf_print_f_point(char *start, t_f_point p, char *end)
{
	if (start)
		printf("%s", start);
	printf("(%f, %f, %f)", p.x, p.y, p.z); // FORBIDDEN FUNCTION
	if (end)
		printf("%s", end);
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
