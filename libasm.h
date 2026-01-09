/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e <rsilva-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:04:10 by rsilva-e          #+#    #+#             */
/*   Updated: 2026/01/09 16:25:30 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

#ifndef LIBASM_H
#define LIBASM_H

size_t	ft_strlen(const char *s);
char *ft_strcpy(char *dest, const char *src);
int	ft_strcmp(const char *str1, const char *str2);
char	*ft_strdup(const char *str);

ssize_t ft_read(int fd, void *buf, size_t count);
ssize_t ft_write(int fd, const void *buf, size_t count);


#endif