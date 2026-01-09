/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e <rsilva-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 21:55:14 by rsilva-e          #+#    #+#             */
/*   Updated: 2023/04/14 21:55:14 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	size_t	i;

	i = 0;
	while ((str1[i] != 0 || str2[i] != 0))
	{
		if (str1[i] != str2[i])
		{
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		}
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char str[] = "-AAS##ddd998";
	char str1[] = "-A1S5#ddd998";


	printf("ft_strncmp: %d\n",ft_strncmp(str,str1,6));

	printf("strncmp: %d\n",strncmp(str,str1,6));


	return(0);
}*/
