/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 08:40:57 by dacortes          #+#    #+#             */
/*   Updated: 2023/11/21 09:15:35 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	parse_data(char **line, int fd, t_get_data *data)
{
	t_aux	chk;

	ft_bzero(&chk, sizeof(t_aux));
	*line = ft_calloc(1, 1);
	if (!*line)
		exit (msg_error(MEM, -1, NULL));
	while (*line)
	{
		if (*line)
			free (*line);
		*line = get_next_line(fd);
		if (*line)
			get_get_data(*line, data, &chk);
	}
	if (chk.no != 1 || chk.so != 1 || chk.we != 1 || chk.ea != 1)
		exit (msg_error(MAP, -1, "no texture"));
	return (EXIT_SUCCESS);
}
