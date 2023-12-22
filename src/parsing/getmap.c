/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:03:44 by dacortes          #+#    #+#             */
/*   Updated: 2023/12/11 12:32:08 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	put_content(t_map *data, t_aux *chk, int *col, int i)
{
	if (chk->line[i] == '1')
		data->map[chk->iter][(*col)++] = 1;
	else if (chk->line[i] == '0')
		data->map[chk->iter][(*col)++] = 0;
	else if (is_player(chk->line[i]))
	{
		if (chk->line[i] == 'N')
			data->player.dir_rad = NORTH;
		else if (chk->line[i] == 'E')
			data->player.dir_rad = EAST;
		else if (chk->line[i] == 'W')
			data->player.dir_rad = WEST;
		else if (chk->line[i] == 'S')
			data->player.dir_rad = SOUTH;
		data->player.position.x = (*col + 0.5) * MAP_SQUARES_SIZE;
		data->player.position.y = (chk->iter + 0.5) * MAP_SQUARES_SIZE;
		data->map[chk->iter][(*col)++] = 0;
	}
	return (EXIT_SUCCESS);
}

int	set_chr_map(t_map *data, t_aux *chk)
{
	int	col;
	int	tab;
	int	i;

	i = 0;
	col = 0;
	while (chk->line && chk->line[i] && chk->line[i] != '\n')
	{
		if (chk->line[i] == ' ')
			data->map[chk->iter][col++] = -1;
		else if (chk->line[i] == '\t')
		{
			tab = -1;
			while (++tab < 4)
				data->map[chk->iter][col++] = -1;
		}
		else
			put_content(data, chk, &col, i);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	set_line_map(t_map *data, t_aux *chk)
{
	if (*chk->line && is_line_map(chk) && !empty_line(chk))
	{
		data->map[chk->iter] = malloc(data->cols * sizeof(char));
		if (!data->map)
			exit (msg_error(MEM, -1, NULL));
		ft_memset(data->map[chk->iter], -1, data->cols);
		set_chr_map(data, chk);
		chk->iter++;
	}
	return (EXIT_SUCCESS);
}

int	get_map(t_aux *chk, char *file, t_map *data)
{
	int	fd;

	fd = -1;
	parse_open(file, &fd);
	ft_bzero(chk, sizeof(t_aux));
	data->map = ft_calloc(data->rows, sizeof(char *));
	if (!data->map)
		exit (msg_error(MEM, -1, NULL));
	chk->line = ft_calloc(1, 1);
	if (!chk->line)
		exit (msg_error(MEM, -1, NULL));
	while (chk->line)
	{
		if (chk->line)
			free (chk->line);
		chk->line = get_next_line(fd);
		if (chk->line)
			set_line_map(data, chk);
	}
	if (fd >= 0)
		close (fd);
	return (EXIT_SUCCESS);
}
