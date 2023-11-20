/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpath.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:39:22 by codespace         #+#    #+#             */
/*   Updated: 2023/11/20 17:39:54 by codespace        ###   ########.fr       */
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

int	get_path_text(char *line, t_path_text *text)
{
	(void)text;
	int	i;

	if (!line || !*line)
		return (ERROR);
	i = 0;
	while (line[i] && is_space(line[i]))
		i++;
	if (line[i] && line[i + 1])
	{
		if (!ft_strncmp(&line[i], "WE", 2))
		{
			ft_printf("soy we\n");
			if (line[i + 1] && !is_space(line[i + 1]))
				i += 2;
			ft_printf("len path %d\n", ft_strlen(&line[i]));
		}
		while (line[i] && is_space(line[i]))
			i++;	
		ft_printf("%s\n", &line[i]);
	}
	return (EXIT_SUCCESS);
}
