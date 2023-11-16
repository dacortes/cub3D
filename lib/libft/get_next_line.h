/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacortes <dacortes@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:56:44 by dacortes          #+#    #+#             */
/*   Updated: 2023/07/13 10:06:15 by dacortes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

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
