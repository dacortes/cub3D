/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpath.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:39:22 by codespace         #+#    #+#             */
/*   Updated: 2023/11/20 19:41:19 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

char	*ft_strndup(const char *src, size_t n)
{
	size_t	len;
	char	*dst;

	len = ft_strlen(src);
	if (n < len)
		len = n;
	dst = (char *)ft_calloc(len + 1, sizeof(char));
	if (!dst)
		return (NULL);
	if (dst)
		ft_memcpy(dst, src, len);
	return (dst);
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

int search_path_text(char **set, char *line, int i, char *find)
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

int	get_path_text(char *line, t_path_text *text)
{
	int stt;
	int	i;

	if (!line || !*line)
		return (ERROR);
	i = 0;
	stt = 0;
	while (line[i] && is_space(line[i]))
		i++;
	if (line[i] && line[i + 1])
	{
		//search find path text
		stt += search_path_text(&text->we, line, i, "SO");
		stt += search_path_text(&text->we, line, i, "NO");
		stt	+= search_path_text(&text->we, line, i, "WE");
		stt	+= search_path_text(&text->we, line, i, "EA");
		while (line[i] && is_space(line[i]))
			i++;	
		//ft_printf("%s\n", &line[i]);
	}
	return (stt);
}
