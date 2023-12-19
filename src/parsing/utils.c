/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:37:07 by codespace         #+#    #+#             */
/*   Updated: 2023/12/19 09:13:16 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	is_space(char c)
{
	return ((c == 32 || (c >= 9 && c <= 13)));
}

int	is_num(char *str)
{
	int	iter;

	iter = 0;
	while (str[iter])
	{
		if (!ft_isdigit(str[iter]))
			return (FALSE);
		iter++;
	}
	return (TRUE);
}

int	ignore_space(char *str, int *iter)
{
	while (str[*iter] && is_space(str[*iter]))
		++(*iter);
	return (EXIT_SUCCESS);
}

int	error_get_data(char **set, char *find)
{
	if (!set[0])
		exit (msg_error(MEM, -1, NULL));
	if (!*set[0] || (*set[0] == '\n'))
		exit (msg_error(MAP, -1, "path not found: texture"));
	if (!*set[0])
		exit (msg_error(MAP, -1, find));
	return (EXIT_SUCCESS);
}

int	msg_error(int err, int exit_, char *cm)
{
	if (err == MEM)
		fd_printf(2, "Error\ntrying to allocate memory\n");
	if (err == ARG)
	{
		fd_printf(2, "Error\nNeed exactly one parameter");
		fd_printf(2, " (./cub3D <map>.cub)\n");
	}
	if (err == OPN)
		fd_printf(2, "Error\nopening file: %s\n", cm);
	if (err == MAP)
		fd_printf(2, "Error\nwrong map: %s\n", cm);
	if (err == FRM)
		fd_printf(2, "Error\ninvalid format: %s\n", cm);
	if (err == PRR)
		perror("Error\n");
	return (exit_);
}
