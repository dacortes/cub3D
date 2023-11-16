/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addstart_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:28:48 by dacortes          #+#    #+#             */
/*   Updated: 2023/07/13 09:57:47 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_addstart_char(const char *str, const char c)
{
	int		i;
	char	*addend;

	if (!str)
		return (NULL);
	addend = ft_calloc(sizeof(char), ft_strlen(str) + 2);
	if (!addend)
		return (NULL);
	i = -1;
	addend[++i] = c;
	while (str[i++])
		addend[i] = str[i - 1];
	return (addend);
}
