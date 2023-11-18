/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_type_cs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 19:57:05 by dacortes          #+#    #+#             */
/*   Updated: 2023/07/13 09:57:34 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fd_type_c(int fd, char c, int *i)
{
	if (write(fd, &c, 1) == -1)
		return (-1);
	*i = (*i + 1);
	return (*i);
}

int	fd_type_s(int fd, char *c, int *i)
{
	int	j;

	j = 0;
	if (!c)
		c = "(null)";
	while (c[j] != '\0')
	{
		if (fd_type_c(fd, c[j], i) == -1)
			return (-1);
		j++;
	}
	return (*i);
}
