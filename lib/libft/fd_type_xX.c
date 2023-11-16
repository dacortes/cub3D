/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_type_xX.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 20:07:53 by dacortes          #+#    #+#             */
/*   Updated: 2023/07/13 09:57:41 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fd_type_u(int fd, unsigned int n, int *i)
{
	char	*base;

	base = "0123456789";
	if (n >= 10)
	{
		if (fd_type_u(fd, n / 10, i) == -1)
			return (-1);
	}
	if (fd_type_c(fd, base[n % 10], i) == -1)
		return (-1);
	return (*i);
}

int	fd_type_x(int fd, unsigned int n, int *i)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
	{
		if (fd_type_x(fd, n / 16, i) == -1)
			return (-1);
	}
	if (fd_type_c(fd, base[n % 16], i) == -1)
		return (-1);
	return (*i);
}

int	fd_type_xup(int fd, unsigned int n, int *i)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (n >= 16)
	{
		if (fd_type_xup(fd, n / 16, i) == -1)
			return (-1);
	}
	if (fd_type_c(fd, base[n % 16], i) == -1)
		return (-1);
	return (*i);
}
