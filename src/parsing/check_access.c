/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:07:55 by dacortes          #+#    #+#             */
/*   Updated: 2023/11/29 15:09:01 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	parse_text(char *path)
{
	if (access(path, R_OK) == ERROR)
		exit (msg_error(PRR, -1, path));
	return (EXIT_SUCCESS);
}

int	check_access(t_map *data)
{
	if (data->no)
		parse_text(data->no);
	if (data->so)
		parse_text(data->so);
	if (data->we)
		parse_text(data->we);
	if (data->ea)
		parse_text(data->ea);
	return (EXIT_SUCCESS);
}

int	parse_open(char *file, int *fd)
{
	if (access(file, R_OK) == ERROR)
		exit (msg_error(PRR, -1, file));
	*fd = open(file, O_RDONLY);
	if (*fd == ERROR)
		exit (msg_error(OPN, -1, file));
	return (EXIT_SUCCESS);
}
