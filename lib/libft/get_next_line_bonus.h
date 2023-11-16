/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:45:10 by dacortes          #+#    #+#             */
/*   Updated: 2023/07/13 10:06:00 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include "libft.h"
# include <limits.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 600
# endif

char	*ft_free(char **buff, char **buff2);

char	*get_next_line(int fd);
char	*ft_next_buff(char *buf);
char	*ft_next_line(char *buf, char *line);
char	*ft_read_fd(int fd, char *buf, int bytes);

char	*ft_protec_join(char *buffer, char *reader);
#endif
