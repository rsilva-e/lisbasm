/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e <rsilva-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:02:37 by rsilva-e          #+#    #+#             */
/*   Updated: 2026/01/08 17:00:13 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libasm.h"
# include <string.h>

int main()
{

    char *sequence = "O meu mundo";


    printf("----------- TEST - LANGUAGE C ------\n");
    printf("A frase tem %lu letras\n" , strlen(sequence));

    printf("----------- TEST - LANGUAGE ASSEMBLY ------\n");
    printf("A frase tem %lu letras\n" , ft_strlen(sequence));


    char dest[] = "12345676";
	char src[] = "S55faff";


    ft_strcpy(dest,src);
    printf("\n----------- FT_STRCPY ------\n");
	printf("String destino: %s\n",dest);
	printf("String Source : %s\n",src);
    

}