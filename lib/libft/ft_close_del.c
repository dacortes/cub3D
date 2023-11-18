/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:59:49 by dacortes          #+#    #+#             */
/*   Updated: 2023/07/13 17:00:13 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	close_del(char *str, char delimiter)
{
	int	del;
	int	i;

	del = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == delimiter)
			del++;
		else if (str[i] == delimiter && del % 2 == 0)
		{
			while (str[i])
			{
				i++;
				if (str[i] == delimiter)
				{
					del++;
					break ;
				}
			}
		}
		i++;
	}
	return (del % 2 == 0);
}
