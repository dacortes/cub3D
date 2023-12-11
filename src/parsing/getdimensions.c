/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getdimensions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:57:58 by dacortes          #+#    #+#             */
/*   Updated: 2023/12/11 12:32:26 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	get_column(t_map *data, t_aux *chk)
{
	int	current;

	current = 0;
	chk->iter = 0;
	while (chk->line[chk->iter] && is_map(chk->line[chk->iter], &chk->player))
	{
		if (chk->line[chk->iter] == '\t')
			current += 4;
		current++;
		chk->iter++;
	}
	if (data->cols < current)
		data->cols = (current - 1);
	return (EXIT_SUCCESS);
}

int	get_dimensions(t_map *data, t_aux *chk, int	*started)
{
	if (*chk->line && is_line_map(chk) && !empty_line(chk))
	{
		if (*started == 2)
			exit (msg_error(MAP, -1, "empty line"));
		*started = 1;
		get_column(data, chk);
		data->rows++;
	}
	else if (*chk->line && (empty_line(chk) || !is_line_map(chk))
		&& *started)
		*started = 2;
	return (EXIT_SUCCESS);
}
