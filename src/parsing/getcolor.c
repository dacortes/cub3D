/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getcolor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:04:25 by dacortes          #+#    #+#             */
/*   Updated: 2023/12/02 16:35:26 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	check_comma(t_aux *chk, int *len, int flag)
{
	int	comma;

	comma = 0;
	while (chk->line[*len] && chk->line[*len] == ',')
	{
		++comma;
		++(*len);
	}
	if (!flag && comma != 1)
		exit (msg_error(MAP, -1, "invalid color"));
	if (flag)
	{
		if (comma != 0)
			exit (msg_error(MAP, -1, "invalid syntax"));
		ignore_space(chk->line, len);
		if (chk->line[*len] && (chk->line[*len] != '\n'
				|| chk->line[*len] != '\0'))
			exit (msg_error(MAP, -1, "invalid color"));
	}
	return (EXIT_SUCCESS);
}

int	find_color(int *set, t_aux *chk, int *len)
{
	char	*cpy;
	int		iter;

	ignore_space(chk->line, len);
	iter = *len;
	if (chk->line[*len])
	{
		while (chk->line[iter] && !is_space(chk->line[iter])
			&& chk->line[iter] != '\n' && chk->line[iter] != ',')
			++iter;
		cpy = ft_strndup(&chk->line[*len], (iter - *len));
		if (!cpy)
			exit (msg_error(MEM, -1, NULL));
		if (!is_num(cpy) || !*cpy)
			exit (msg_error(MAP, -1, "invalid color"));
		*set = ft_atoi(cpy);
		if (*set > 255 || *set < 0)
			exit (msg_error(MAP, -1, "invalid color: out of range"));
		if (cpy)
			free(cpy);
		*len += (iter - *len);
	}
	else
		exit (msg_error(MAP, -1, "invalid color"));
	return (EXIT_SUCCESS);
}

int	check_colors(t_color *set, t_aux *chk, int *len)
{
	find_color(&set->red, chk, len);
	check_comma(chk, len, 0);
	find_color(&set->green, chk, len);
	check_comma(chk, len, 0);
	find_color(&set->blue, chk, len);
	check_comma(chk, len, 1);
	return (EXIT_SUCCESS);
}

int	get_color(t_color *set, t_aux *chk, char *find, int *stt)
{
	int	len;

	if (!ft_strncmp(&chk->line[chk->iter], find, 1))
	{
		(*stt)++;
		if (*stt > 1)
			exit (msg_error(MAP, -1, "duplicate color"));
		if (chk->line[chk->iter] && !is_space(chk->line[chk->iter]))
			++chk->iter;
		if (chk->line[chk->iter] && !is_space(chk->line[chk->iter]))
			exit (msg_error(MAP, -1, "invalid name variable"));
		if (chk->line[chk->iter])
		{
			len = chk->iter;
			while (chk->line[len] && !is_space(chk->line[len])
				&& chk->line[len] != '\n')
				++len;
			check_colors(set, chk, &len);
			return (EXIT_SUCCESS);
		}
	}
	return (ERROR);
}
