/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:27:08 by dacortes          #+#    #+#             */
/*   Updated: 2023/12/21 10:27:19 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

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
