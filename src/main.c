/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:57:07 by dacortes          #+#    #+#             */
/*   Updated: 2023/11/21 08:59:52 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	main(int ac, char **av)
{
	t_get_data	text;
	char *line;
	int	fd;

	fd = -1;
	if (ac != 2)
		exit (msg_error(ARG, -1, NULL));
	parse_open(av[1], &fd);
	parse_data(&line, fd, &text);	
	if (fd >= 0)
		close (fd);
	return (EXIT_SUCCESS);
}
