/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:03:44 by dacortes          #+#    #+#             */
/*   Updated: 2023/11/26 15:40:41 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	is_map(char pos, int *player)
{
	if (pos == 'N' || pos == 'S' || pos == 'E' || pos == 'W')
		(*player)++;
	return (pos == '1' || pos == '0' || is_space(pos) || pos == 'N'
		|| pos == 'S' || pos == 'E' || pos == 'W');
}

int	check_line_map(t_map *data, t_aux *chk)
{
	int	current;

	current = 0;
	chk->iter = 0;
	while (chk->line[chk->iter])
	{
		is_map(chk->line[chk->iter++], &chk->player);
		current++;
	}
	if (data->row < current)
		data->row = current; 
	return (EXIT_SUCCESS);
}
/* 34*/
int	get_map(t_map *data, t_aux *chk)
{
	int	space;
	(void)data;
	space = 0;
	if (chk->line[0] && ft_strchr(chk->line, '1'))
	{
		ft_printf("%s", chk->line);
		check_line_map(data, chk);
		data->col++;
	}
	return  (EXIT_SUCCESS);
}