/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:57:07 by dacortes          #+#    #+#             */
/*   Updated: 2023/11/28 10:10: by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	clear_data(t_map *data)
{
	int	i;

	if (data->no)
		free(data->no);
	if (data->so)
		free(data->so);
	if (data->we)
		free(data->we);
	if (data->ea)
		free(data->ea);
	i = 0;
	while (data->map && data->map[i])
	{
		free (data->map[i]);
		data->map[i] = NULL;
		++i;
	}
	if (data->map)
	{
		free (data->map);
		data->map = NULL;
	}
	return (EXIT_SUCCESS);
}

int	printf_map(t_map data)
{
	int	i;

	i = 0;
	while (data.map && data.map[i])
		ft_printf("%s\n", data.map[i++]);
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	(void)av;
	t_map	data;
	t_aux	chk;
	int		fd;

	fd = -1;
	if (ac != 2)
		exit (msg_error(ARG, -1, NULL));
	parse_open(av[1], &fd);
	parse_data(&chk, fd, &data);
	parse_map(&chk, av[1], &data);
	printf_map(data);
	clear_data(&data);
	if (fd >= 0)
		close (fd);
	return (EXIT_SUCCESS);
}
