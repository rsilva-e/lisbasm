/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e <rsilva-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:04:10 by rsilva-e          #+#    #+#             */
/*   Updated: 2026/01/14 17:21:03 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
#include <errno.h>
#include <string.h>

#ifndef LIBASM_H
#define LIBASM_H


//-------MANDATORY---------------MANDATORY---------------MANDATORY--------
size_t	ft_strlen(const char *s);
char *ft_strcpy(char *dest, const char *src);
int	ft_strcmp(const char *str1, const char *str2);
char	*ft_strdup(const char *str);
ssize_t ft_read(int fd, void *buf, size_t count);
ssize_t ft_write(int fd, const void *buf, size_t count);


//-------BONUS---------------BONUS---------------BONUS--------------------
typedef struct s_list
{
    void *data;
    struct s_list *next;
} t_list;



int cmp_str(void *data1, void *data2)
{
    return ft_strcmp((char *)data1, (char *)data2);
}


void free_str(void *data)
{
    free(data);
}

void ft_list_push_front(t_list **begin_list, void *data);
int ft_list_size(t_list *begin_list);
void ft_list_sort(t_list **begin_list, int (*cmp)());
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));



#endif