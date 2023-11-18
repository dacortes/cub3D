/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:40:44 by dacortes          #+#    #+#             */
/*   Updated: 2023/07/13 10:01:28 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cp;

	cp = (char *)malloc(ft_strlen(s1) + 1);
	if (!cp)
		return (0);
	ft_memcpy(cp, s1, ft_strlen(s1) + 1);
	return (cp);
}
