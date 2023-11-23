/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getcolor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:04:25 by dacortes          #+#    #+#             */
/*   Updated: 2023/11/23 12:38:32 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

int	is_num()
{
	return (EXIT_SUCCESS)
}

int	ignore_space(char *str, int *iter)
{
	while (str[*iter] && is_space(str[*iter]) && str[*iter] != '\n')
		++(*iter);
	return (EXIT_SUCCESS);
}

int	find_color(t_color *set, t_aux *chk, int *len, int color)
{
	(void)set;
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
		if (color == RED)
			ft_printf("%s\n", cpy);
		free(cpy);
	}
	return (EXIT_SUCCESS);
}

int	get_color(t_color *set, t_aux *chk, char *find, int *stt)
{
	int	len;
	(void)set;
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
			find_color(set, chk, &len, RED);
			return (TRUE);
		}
	}
	return (FALSE);
}
