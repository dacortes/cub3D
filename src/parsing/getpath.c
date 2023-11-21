/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpath.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:39:22 by codespace         #+#    #+#             */
/*   Updated: 2023/11/21 10:49:11 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	parse_open(char *file, int *fd)
{
	if (access(file, R_OK) == ERROR)
			exit (msg_error(PRR, -1, file));
	*fd = open(file, O_RDONLY);
	if (*fd == ERROR)
		exit (msg_error(OPN, -1, file));
	return (EXIT_SUCCESS);
}

int search_get_data(char **set, char *line, int i, char *find)
{
	int	len;

	if (!ft_strncmp(&line[i], find, 2))
	{
		if (line[i + 1] && !is_space(line[i + 1]))
			i += 2;
		if (line[i] == ' ')
			++i;
		if (line[i])
		{
			len = i;
			while (line[len] && !is_space(line[len]) && line[len] != '\n')
				++len;
			*set = ft_strndup(&line[i], (len - i));
			if (!set[0])
				exit (msg_error(MEM, -1, NULL));
			if (!*set[0] || (*set[0] == '\n'))
				exit (msg_error(MAP, -1, "path not found"));
			ft_printf("*%s*\n", *set);
			if (!*set[0])
				exit (msg_error(MAP, -1, find));
			free(*set);
			return (1);
		}
	}
	return (0);
}

int	get_get_data(char *line, t_get_data *data, t_aux *chk)
{
	int	i;

	if (!line || !*line)
		return (ERROR);
	i = 0;
	while (line[i] && is_space(line[i]))
		i++;
	if (line[i] && line[i + 1])
	{
		chk->no += search_get_data(&data->we, line, i, "NO");
		chk->so += search_get_data(&data->we, line, i, "SO");
		chk->we	+= search_get_data(&data->we, line, i, "WE");
		chk->ea	+= search_get_data(&data->we, line, i, "EA");
		if (chk->no > 1 || chk->so > 1 || chk->we > 1 || chk->ea > 1)
			exit (msg_error(MAP, -1, "many textures"));
		while (line[i] && is_space(line[i]))
			i++;	
	}
	return (EXIT_SUCCESS);
}
