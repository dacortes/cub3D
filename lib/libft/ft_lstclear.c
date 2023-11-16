/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:02:40 by dacortes          #+#    #+#             */
/*   Updated: 2023/07/13 09:59:23 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*c_temp;

	if (!lst)
		return ;
	else
	{
		while (*lst)
		{
			c_temp = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = c_temp;
		}
	}
}
