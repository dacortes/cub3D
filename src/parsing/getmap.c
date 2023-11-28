/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:03:44 by dacortes          #+#    #+#             */
/*   Updated: 2023/11/28 15:56:13 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	is_map(char pos, int *player)
{
	if (pos == 'N' || pos == 'S' || pos == 'E' || pos == 'W')
		(*player)++;
	return (pos == '1' || pos == '0' || is_space(pos) || pos == 'N'
		|| pos == 'S' || pos == 'E' || pos == 'W');
}

int	check_line_map(t_map *data, t_aux *chk)
{
	int	current;

	current = 0;
	chk->iter = 0;
	while (chk->line[chk->iter] && is_map(chk->line[chk->iter++], &chk->player))
		current++;
	if (data->row < current)
		data->row = current; 
	return (EXIT_SUCCESS);
}

int is_map_closed(t_map *data) {
    int i, j;

    for (i = 0; i < data->row; i++) {
        if (data->map[i][0] != '1' || data->map[i][data->col - 1] != '1') {
            return 0;
        }
    }

    for (j = 0; j < data->col; j++) {
        if (data->map[0][j] != '1' || data->map[data->row - 1][j] != '1') {
            return 0;
        }
    }

    return 1;
}

int	get_map_dimensions(t_map *data, t_aux *chk)
{
	if (chk->line[0] && (ft_strchr(chk->line, '1')
		|| ft_strchr(chk->line, '0')))
	{
		check_line_map(data, chk);
		data->col++;
	}
	return  (EXIT_SUCCESS);
}

int	is_line_map(t_aux *chk)
{
	int	i;

	i = 0;
	while (chk->line[i])
	{
		if (!is_map(chk->line[i++], &chk->player))
			return (FALSE);
	}
	return (TRUE);
}

int	set_char_map(t_aux *chk, t_map *data)
{
	int	tb;
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (chk->line && chk->line[i] && chk->line[i] != '\n')
	{
		if (chk->line[i] == ' ')
			data->map[chk->iter][i] = 'V';
		else if (chk->line[i] == '\t')
		{
			tb = 0;
			while (tb < 4)
			{
				data->map[chk->iter][j++] = 'V';
				tb++;
			}
		}
		else
			data->map[chk->iter][j++] = chk->line[i];
		i++;
	}
	while ((int)ft_strlen(data->map[chk->iter]) < data->row)
		data->map[chk->iter][j++] = 'V';
	return (EXIT_SUCCESS);
}



int	set_line_map(t_map *data, t_aux *chk)
{
	if (chk->line[0] && is_line_map(chk))
	{
		data->map[chk->iter] = ft_calloc(data->row + 1, sizeof(char));
		if (!data->map)
			exit (msg_error(MEM, -1, NULL));
		set_char_map(chk, data);
		chk->iter++;
	}
	return (EXIT_SUCCESS);
}

int	get_map(t_aux *chk, char *file, t_map *data)
{
	int fd = open(file, O_RDONLY);
	ft_bzero(chk, sizeof(t_aux));
	data->map = ft_calloc(data->col + 1, sizeof(char *));
	if (!data->map)
		exit (msg_error(MEM, -1, NULL));
	chk->line = ft_calloc(1, 1);
	if (!chk->line)
		exit (msg_error(MEM, -1, NULL));	
	while (chk->line)
	{
		if (chk->line)
			free (chk->line);
		chk->line = get_next_line(fd);
		if (chk->line)
			set_line_map(data, chk);
	}
	close (fd);
	return (EXIT_SUCCESS);
}