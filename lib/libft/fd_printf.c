/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:29:42 by dacortes          #+#    #+#             */
/*   Updated: 2023/07/13 09:57:29 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_types(int fd, va_list args, char const type, int *count)
{
	if (type == '%')
		*count = fd_type_c(fd, '%', count);
	if (type == 'c')
		*count = fd_type_c(fd, va_arg(args, int), count);
	if (type == 's')
		*count = fd_type_s(fd, va_arg(args, char *), count);
	if (type == 'd' || type == 'i')
		*count = fd_type_di(fd, va_arg(args, int), count);
	if (type == 'u')
		*count = fd_type_u(fd, va_arg(args, unsigned int), count);
	if (type == 'x')
		*count = fd_type_x(fd, va_arg(args, unsigned int), count);
	if (type == 'X')
		*count = fd_type_xup(fd, va_arg(args, unsigned int), count);
	if (type == 'p')
		*count = fd_type_p(fd, va_arg(args, unsigned long int), count);
	return (*count);
}

static int	ft_checking(int fd, va_list args, char const *str, int *count)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (ft_types(fd, args, str[i + 1], count) == -1)
				return (-1);
			i++;
		}
		else
		{
			if (fd_type_c(fd, str[i], count) == -1)
				return (-1);
		}
		i++;
	}
	return (*count);
}

int	fd_printf(int fd, char const *str, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, str);
	if (ft_checking(fd, args, str, &count) == -1)
		return (-1);
	va_end(args);
	return (count);
}
