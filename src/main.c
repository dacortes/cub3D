/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:57:07 by dacortes          #+#    #+#             */
/*   Updated: 2023/11/20 19:40:59 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	main(int ac, char **av)
{
	t_path_text	text;

	int	fd = -1;
	int stt = 0;
	(void)av;
	if (ac != 2)
		exit (msg_error(ARG, -1, NULL));
	parse_open(av[1], &fd);
	char *line = ft_calloc(1, 1);
	if (!line)
		return (EXIT_SUCCESS);
	while (line)
	{
		if (line)
			free (line);
		line = get_next_line(fd);
		if (line)
		{
			stt += get_path_text(line, &text);
		}
	}
	if (stt != 4)
		exit (msg_error(MAP, -1, "no texture"));	
	if (fd >= 0)
		close (fd);
	return (EXIT_SUCCESS);
}
