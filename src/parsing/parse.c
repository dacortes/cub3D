/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 08:40:57 by dacortes          #+#    #+#             */
/*   Updated: 2023/11/21 18:53:24 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	parse_data(t_aux *chk, int fd, t_map *data)
{
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
			get_get_data(data, chk);
	}
	if (chk->no != 1 || chk->so != 1 || chk->we != 1 || chk->ea != 1)
		exit (msg_error(MAP, -1, "no texture"));
	check_access(data);
	return (EXIT_SUCCESS);
}
