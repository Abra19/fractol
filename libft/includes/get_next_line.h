/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:37:35 by dlaure            #+#    #+#             */
/*   Updated: 2020/04/05 16:37:29 by elena_abrarova   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1000
# define FD_NUM 8192

# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

int		get_next_line(const int fd, char **line);

#endif
