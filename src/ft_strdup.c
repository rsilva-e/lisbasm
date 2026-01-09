/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e <rsilva-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:03:46 by rsilva-e          #+#    #+#             */
/*   Updated: 2023/04/19 14:03:46 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*str1;
	size_t	len_str;

	len_str = ft_strlen(str) + 1;
	str1 = (char *)malloc(len_str * sizeof(char));
	if (str1 == NULL)
		return (NULL);
	ft_strlcpy(str1, str, len_str);
	return (str1);
}
/*
int main (void)
{
	char dest[] = "";
	char *p;
	
	p = ft_strdup(dest);
	printf("A string foi copiada: %s\n" ,p );
	
}*/
