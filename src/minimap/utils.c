/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:21:51 by dacortes          #+#    #+#             */
/*   Updated: 2023/12/21 10:24:36 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bits_pxl / 8));
	*(unsigned int *)dst = color;
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
	printf("(%d, %d, %d)", p.x, p.y, p.z);
	if (end)
		printf("%s", end);
}

void	fdf_print_f_point(char *start, t_f_point p, char *end)
{
	if (start)
		printf("%s", start);
	printf("(%f, %f, %f)", p.x, p.y, p.z);
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
