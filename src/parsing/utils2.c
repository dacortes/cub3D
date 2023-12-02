/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:26:56 by dacortes          #+#    #+#             */
/*   Updated: 2023/11/29 15:33:27 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	is_player(int player)
{
	return (player == 'N' || player == 'S' || player == 'E' || player == 'W');
}

int	empty_line(t_aux *chk)
{
	int	i;

	i = 0;
	while (chk->line[i])
	{
		if (!is_space(chk->line[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	is_line_map(t_aux *chk)
{
	int	i;
	int	player_null;

	i = 0;
	player_null = 0;
	while (chk->line[i])
	{
		if (!is_map(chk->line[i++], &player_null))
			return (FALSE);
	}
	return (TRUE);
}

int	is_map(char pos, int *player)
{
	if (pos == 'N' || pos == 'S' || pos == 'E' || pos == 'W')
		(*player)++;
	return (pos == '1' || pos == '0' || is_space(pos) || pos == 'N'
		|| pos == 'S' || pos == 'E' || pos == 'W');
}
