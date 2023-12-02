/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 08:40:57 by dacortes          #+#    #+#             */
/*   Updated: 2023/12/02 17:33:20 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	parse_data(t_aux *chk, int fd, t_map *data)
{
	int	dta_left;

	ft_bzero(chk, sizeof(t_aux));
	chk->line = ft_calloc(1, 1);
	if (!chk->line)
		exit (msg_error(MEM, -1, NULL));
	dta_left = 6;
	while (chk->line && dta_left > 0)
	{
		if (chk->line)
			free (chk->line);
		chk->line = get_next_line(fd);
		if (chk->line)
			dta_left -= get_data(data, chk) == EXIT_SUCCESS;
	}
	if (chk->line)
		free (chk->line);
	if (chk->no != 1 || chk->so != 1 || chk->we != 1 || chk->ea != 1)
		exit (msg_error(MAP, -1, "no texture"));
	check_access(data);
	return (EXIT_SUCCESS);
}

int	check_map(t_map *data, int x, int y)
{
	while (++y < data->rows)
	{
		x = -1;
		while (++x < data->cols)
		{
			if (x > 0 && ((data->map[y][x] == 2 && data->map[y][x - 1]
				&& data->map[y][x - 1] == -1) || (x < data->cols - 1
				&& (data->map[y][x] == 2 && data->map[y][x + 1]
				&& data->map[y][x + 1] == -1)) || data->map[y][0] == 2))
				exit (msg_error(MAP, -1, "Player out of place"));
			if ((x > 0 && x < data->cols && !data->map[y][x]
				&& ((data->map[y][x + 1] && data->map[y][x + 1] == -1)
				|| (data->map[y][x - 1] && data->map[y][x - 1] == -1)))
				|| (y > 0 && y < data->cols && !data->map[y][x]
				&& ((data->map[y + 1][x] && data->map[y + 1][x] == -1)
				|| (data->map[y - 1][x] && data->map[y - 1][x] == -1))))
				exit (msg_error(MAP, -1, "unclosed map"));
		}
	}
	return (EXIT_SUCCESS);
}

int	parse_map(t_aux *chk, char *file, t_map *data)
{
	int	started;
	int	fd;

	started = 0;
	data->cols = 0;
	data->rows = 0;
	parse_open(file, &fd);
	ft_bzero(chk, sizeof(t_aux));
	chk->line = ft_calloc(1, 1);
	if (!chk->line)
		exit (msg_error(MEM, -1, NULL));
	while (chk->line)
	{
		if (chk->line)
			free (chk->line);
		chk->line = get_next_line(fd);
		if (chk->line)
			get_dimensions(data, chk, &started);
	}
	if (chk->line)
		free (chk->line);
	if (chk->player != 1)
		exit (msg_error(MAP, -1, "duplicated player"));
	started = get_map(chk, file, data) + close (fd) + check_map(data, -1, -1);
	return (EXIT_SUCCESS);
}
