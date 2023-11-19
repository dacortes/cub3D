/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:57:07 by dacortes          #+#    #+#             */
/*   Updated: 2023/11/19 19:39:55 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	msg_error(int err, int exit_, char *cm)
{
	err == MEM && fd_printf(2, R"Error:"E" trying to allocate memory\n");
	err == ARG && fd_printf(2, R"Error:"E" Need exactly one parameter")
		&& fd_printf(2, " (./cub3D <map>.cub)\n");
	err == OPN && fd_printf(2, R"Error:"E" opening file: %s", cm);
	if (err == PRR)
		perror("mini");
	return (exit_);
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

int	is_space(char c)
{
	return ((c == 32 || (c >= 9 && c <= 13)));
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
		ft_printf("%s\n", (&line[i], "NO", 2))
		// (!ft_strncmp(&line[i], "NO", 2)) && ft_printf("soy 1\n");
		// (!ft_strncmp(&line[i], "S0", 2)) && ft_printf("soy 2\n");
		// (!ft_strncmp(&line[i], "WE", 2)) && ft_printf("soy 3\n");
		// (!ft_strncmp(&line[i], "EA", 2)) && ft_printf("soy 3\n");
		(line[i + 1] && !is_space(line[i + 1])) && (i += 2);
		while (line[i] && is_space(line[i]))
			i++;	
		ft_printf("%s\n", &line[i]);
	}
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_path_text	text;

	int	fd = -1;
	(void)av;
	if (ac != 2)
		exit (msg_error(ARG, -1, NULL));
	parse_open(av[1], &fd);
	char *line = ft_calloc(1, 1);
	if (!line)
		return (EXIT_SUCCESS);
	while (line)
	{
		if (line)
			free (line);
		line = get_next_line(fd);
		if (line)
			get_path_text(line, &text);
	}	
	if (fd >= 0)
		close (fd);
	return (EXIT_SUCCESS);
}
