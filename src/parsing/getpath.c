/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpath.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:39:22 by codespace         #+#    #+#             */
/*   Updated: 2023/11/26 09:30:37 by dacortes         ###   ########.fr       */
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

int	search_get_data(char **set, t_aux *chk, char *find, int *stt)
{
	int	len;
	len = 0;
	if (!ft_strncmp(&chk->line[chk->iter], find, 2))
	{
		(*stt)++;
		if (*stt > 1)
			exit (msg_error(MAP, -1, "duplicate texture"));
		while (chk->line[chk->iter] && !is_space(chk->line[chk->iter])
			&& (len < 2))
		{
			++len;
			++chk->iter;
		}
		if (chk->line[chk->iter] && !is_space(chk->line[chk->iter]))
			exit (msg_error(MAP, -1, "invalid name variable"));
		ignore_space(chk->line, &chk->iter);
		if (chk->line[chk->iter])
		{
			len = chk->iter;
			while (chk->line[len] && !is_space(chk->line[len])
				&& chk->line[len] != '\n')
				++len;
			*set = ft_strndup(&chk->line[chk->iter], (len - chk->iter));
			error_get_data(set, find);
			ignore_space(chk->line, &len);
			if (chk->line[len] && (chk->line[len] != '\n' ||
				chk->line[len] != '\0'))
				exit (msg_error(MAP, -1, "invalid texture"));
			return (EXIT_SUCCESS);
		}
	}
	return (ERROR);
}

int	get_get_data(t_map *data, t_aux *chk)
{
	int	done;

	if (!chk->line || !*chk->line)
		return (ERROR);
	chk->iter = 0;
	while (chk->line[chk->iter] && is_space(chk->line[chk->iter]))
		chk->iter++;
	if (chk->line[chk->iter] == '\n' || !chk->line[chk->iter])
		return (ERROR);
	done = 0;
	if (chk->line[chk->iter] && chk->line[chk->iter + 1])
	{
		done = done || !search_get_data(&data->no, chk, "NO", &chk->no);
		done = done || !search_get_data(&data->so, chk, "SO", &chk->so);
		done = done || !search_get_data(&data->we, chk, "WE", &chk->we);
		done = done || !search_get_data(&data->ea, chk, "EA", &chk->ea);
		done = done || !get_color(&data->floor, chk, "F", &chk->floor);
		done = done || !get_color(&data->ceiling, chk, "C", &chk->ceiling);
	}
	if (!done)
		exit (msg_error(MAP, -1, NULL));
	return (EXIT_SUCCESS);
}
