/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_type_idup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 20:00:08 by dacortes          #+#    #+#             */
/*   Updated: 2023/07/13 09:57:37 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	fd_put_di(int fd, unsigned int n, int *i)
{
	char	*base;

	base = "0123456789";
	if (n >= 10)
	{
		if (fd_put_di(fd, (n / 10), i) == -1)
			return (-1);
	}
	if (fd_type_c(fd, base[n % 10], i) == -1)
		return (-1);
	return (*i);
}

int	fd_type_di(int fd, int n, int *i)
{
	if (n == -2147483647)
	{
		if (fd_type_s(fd, "-2147483647", i) == -1)
			return (-1);
	}
	else
	{
		if (n < 0)
		{
			if (fd_type_c(fd, '-', i) == -1)
				return (-1);
			n *= -1;
		}
		if (fd_put_di(fd, n, i) == -1)
			return (-1);
	}
	return (*i);
}

static int	putptr(int fd, unsigned long n, int *i)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
	{
		if (putptr(fd, n / 16, i) == -1)
			return (-1);
	}
	if (fd_type_c(fd, base[n % 16], i) == -1)
		return (-1);
	return (*i);
}

int	fd_type_p(int fd, unsigned long n, int *i)
{
	if (fd_type_s(fd, "0x", i) == -1)
		return (-1);
	if (putptr(fd, n, i) == -1)
		return (-1);
	return (*i);
}
