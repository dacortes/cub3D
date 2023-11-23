/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getcolor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:04:25 by dacortes          #+#    #+#             */
/*   Updated: 2023/11/23 15:03:04 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	is_num(char *str)
{
	int	iter;

	iter = 0;
	while (str[iter])
	{
		if (!ft_isdigit(str[iter]))
			return (FALSE);
		iter++;
	}
	return (TRUE);
}

int	ignore_space(char *str, int *iter)
{
	while (str[*iter] && is_space(str[*iter]))
		++(*iter);
	return (EXIT_SUCCESS);
}

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
		if (*set > 255)
			exit (msg_error(MAP, -1, "invalid color: out of range"));
		ft_printf("set color: %d\n", *set);
		if (cpy)
			free(cpy);
		*len += (iter - *len);
	}
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
		if (chk->line[chk->iter + 1] && !is_space(chk->line[chk->iter + 1]))
			++chk->iter;
		if (chk->line[chk->iter])
		{
			len = chk->iter;
			while (chk->line[len] && !is_space(chk->line[len])
				&& chk->line[len] != '\n')
				++len;
			find_color(&set->red, chk, &len);
			check_comma(chk, &len, 0);
			find_color(&set->green, chk, &len);
			check_comma(chk, &len, 0);
			find_color(&set->blue, chk, &len);
			check_comma(chk, &len, 1);
			return (TRUE);
		}
	}
	return (FALSE);
}
