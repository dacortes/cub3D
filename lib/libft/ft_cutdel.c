/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cutdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:44:12 by dacortes          #+#    #+#             */
/*   Updated: 2023/09/12 13:44:35 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_cutdel(char	*str, int start, int del, int *cnt)
{
	char	*cut;
	int		len;
	int		i;

	if (!str || !str[0] || !del)
		return (NULL);
	len = start;
	while (str[len] && str[len] != del)
		len++;
	cut = ft_calloc(len + 1, sizeof(char));
	if (!cut)
		return (NULL);
	len = start;
	i = 0;
	while (str[len] && str[len] != del)
		cut[i++] = str[len++];
	*cnt = len;
	return (cut);
}
