/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpath.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:39:22 by codespace         #+#    #+#             */
/*   Updated: 2023/11/21 09:16:47 by dacortes         ###   ########.fr       */
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
	int	space;
	int	len;

	if (!ft_strncmp(&line[i], find, 2))
	{
		if (line[i + 1] && !is_space(line[i + 1]))
			i += 2;
		if (line[i])
		{
			space = i;
			while (line[space] && !is_space(line[space]) && line[space] != '\n')
				space++;
			len = ft_strlen(&line[i]) - space;
			*set = ft_strndup(&line[i], len);
			if (!set[0])
				exit (msg_error(MEM, -1, NULL));
			ft_printf("valor de %s=%s\n", find, *set);
			ft_printf("*%s*\n", &line[1]);
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
