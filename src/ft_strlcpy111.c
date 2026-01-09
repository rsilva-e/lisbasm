/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e <rsilva-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:15:31 by rsilva-e          #+#    #+#             */
/*   Updated: 2026/01/08 16:04:34 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcpy(char *dest, const char *src)
{
	size_t	i;
	size_t	nsrc;

	i = 0;
	nsrc = ft_strlen(src);

	while (src[i] != '\0')
	{	
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (nsrc);
}
/*
int main (void)
{
	char dest[] = "12345676";
	char src[] = "S55faff";
	
	int size = 6;
	printf("O numero de carateres é : %zu\n",ft_strlcpy(dest,src,size));
	printf("String destino:%s\n",dest);
	printf("String Source: %s\n",src);
	
}*/
