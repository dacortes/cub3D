/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:37:07 by codespace         #+#    #+#             */
/*   Updated: 2023/11/20 17:43:22 by codespace        ###   ########.fr       */
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
		fd_printf(2, "Error: trying to allocate memory\n");
	if (err == ARG)
	{
		fd_printf(2, "Error: Need exactly one parameter");
		fd_printf(2, " (./cub3D <map>.cub)\n");
	}
	if (err == OPN)
		fd_printf(2, "Error: opening file: %s", cm);
	if (err == PRR)
		perror("mini");
	return (exit_);
}
