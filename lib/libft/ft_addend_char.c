/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addend_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:18:17 by dacortes          #+#    #+#             */
/*   Updated: 2023/07/13 09:57:43 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_addend_char(const char *str, const char c)
{
	int		i;
	char	*addend;

	if (!str)
		return (NULL);
	addend = ft_calloc(sizeof(char), ft_strlen(str) + 2);
	if (!addend)
		return (NULL);
	i = -1;
	while (str[++i])
		addend[i] = str[i];
	addend[i] = c;
	addend[++i] = '\0';
	return (addend);
}
