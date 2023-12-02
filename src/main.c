/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:57:07 by dacortes          #+#    #+#             */
/*   Updated: 2023/12/02 17:29:21 by dacortes         ###   ########.fr       */
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
	while (i < data->row)
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
	int	j;


	i = 0;
	while (i < data.row)
	{
		j = 0;
		while (j < data.col)
		{
			printf("% d", data.map[i][j++]);
		}
		printf("\n");
		i++;
	}
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
	parse_map(&chk, av[1], &data);
	// ft_printf("texture no %s\n", data.no);
	// ft_printf("texture ea %s\n", data.ea);
	// ft_printf("texture so %s\n", data.so);
	// ft_printf("texture we %s\n", data.we);
	// ft_printf("--------------->Color");
	// ft_printf("--->floor\n");
	ft_printf("red :%d\n", data.floor.red);
	ft_printf("green :%d\n", data.floor.green);
	ft_printf("blue :%d\n", data.floor.blue);
	ft_printf("--->ceiling\n");
	ft_printf("red :%d\n", data.ceiling.red);
	ft_printf("green :%d\n", data.ceiling.green);
	ft_printf("blue :%d\n", data.ceiling.blue);
	// printf_map(data);
	clear_data(&data);
	if (fd >= 0)
		close (fd);
	return (EXIT_SUCCESS);
}
