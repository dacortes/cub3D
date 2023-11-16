/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:45:02 by dacortes          #+#    #+#             */
/*   Updated: 2023/07/13 09:58:24 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	asig;
	void	*res;

	asig = size * count;
	res = malloc(asig);
	if (!res)
		return (0);
	ft_memset(res, 0, asig);
	return (res);
}
