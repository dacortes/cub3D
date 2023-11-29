/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 08:40:57 by dacortes          #+#    #+#             */
/*   Updated: 2023/11/29 13:57:35 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	parse_data(t_aux *chk, int fd, t_map *data)
{
	int dta_left;

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
			dta_left -= get_get_data(data, chk) == EXIT_SUCCESS;
	}
	if (chk->line)
		free (chk->line);
	if (chk->no != 1 || chk->so != 1 || chk->we != 1 || chk->ea != 1)
		exit (msg_error(MAP, -1, "no texture"));
	check_access(data);
	return (EXIT_SUCCESS);
}

int	parse_map(t_aux *chk, char *file, t_map *data)
{
	int started = 0;
	int	fd = open(file, O_RDONLY);
	data->col = 0;
	data->row = 0;
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
			get_dimensions(data, chk, &started); //line
	}
	if (chk->line)
		free (chk->line);
	if (chk->player != 1)
		exit (msg_error(MAP, -1, "duplicated player"));
	get_map(chk, file, data);
	ft_printf("row :%d\n", data->row);
	ft_printf("col :%d\n", data->col);
	return (EXIT_SUCCESS);
}