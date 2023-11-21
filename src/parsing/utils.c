/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:37:07 by codespace         #+#    #+#             */
/*   Updated: 2023/11/21 10:15:10 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	is_space(char c)
{
	return ((c == 32 || (c >= 9 && c <= 13)));
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
	if (err == PRR)
		perror("Error\n");
	return (exit_);
}
