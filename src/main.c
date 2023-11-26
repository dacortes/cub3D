/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:57:07 by dacortes          #+#    #+#             */
/*   Updated: 2023/11/26 15:43:32 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	clear_data(t_map *data)
{
	if (data->no)
		free(data->no);
	if (data->so)
		free(data->so);
	if (data->we)
		free(data->we);
	if (data->ea)
		free(data->ea);
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_map	data;
	t_aux	chk;
	int		fd;

	fd = -1;
	if (ac != 2)
		exit (msg_error(ARG, -1, NULL));
	parse_open(av[1], &fd);
	parse_data(&chk, fd, &data);
	parse_map(&chk, fd, &data);
	// ft_printf("texture no %s\n", data.no);
	// ft_printf("texture so %s\n", data.so);
	// ft_printf("texture we %s\n", data.we);
	// ft_printf("texture ea %s\n", data.ea);
	// ft_printf("floor red %d\n", data.floor.red);
	// ft_printf("floor green %d\n", data.floor.green);
	// ft_printf("floor blur %d\n", data.floor.blue);
	// ft_printf("ceiling red %d\n", data.ceiling.red);
	// ft_printf("ceiling green %d\n", data.ceiling.green);
	// ft_printf("ceiling blue %d\n", data.ceiling.blue);
	ft_printf("numero de filas max:%d\n", data.row);
	ft_printf("numero de columnas:%d\n", data.col);	
	clear_data(&data);
	if (fd >= 0)
		close (fd);
	return (EXIT_SUCCESS);
}
