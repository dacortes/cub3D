/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 10:42:21 by dacortes          #+#    #+#             */
/*   Updated: 2023/07/13 10:04:20 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			s;
	size_t		c;
	long int	r;

	s = 1;
	c = 0;
	r = 0;
	while (str[c] && (str[c] == ' ' || str[c] == '\n'
			|| str[c] == '\t' || str[c] == '\v' || str[c] == '\f'
			|| str[c] == '\r'))
		c++;
	if (str[c] == '+' || str[c] == '-')
		if (str[c++] == '-')
			s *= -1;
	while (ft_isdigit(str[c]))
	{
		r = (r * 10) + str[c] - 48;
		c++;
	}
	return (s * r);
}
