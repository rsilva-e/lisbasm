/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e <rsilva-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:02:37 by rsilva-e          #+#    #+#             */
/*   Updated: 2026/01/09 16:48:30 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libasm.h"
# include <string.h>



int main()
{
    printf("\n-------- LISBASM ---------------- LISBASM ---------------- LISBASM --------\n");
    //------- FT_STRLEN --------------- FT_STRLEN --------------- FT_STRLEN --------
    char *sequence = "O meu mundo";
    
    printf("\n-------- FT_STRLEN --------\n");
    printf("strlen: A frase tem %lu letras\n" , strlen(sequence));
    printf("ft_strlen: A frase tem %lu letras\n" , ft_strlen(sequence));



    //------- FT_STRCPY --------------- FT_STRCPY --------------- FT_STRCPY --------
    char dest[] = "12345676";
	char src[] = "S55faff";


    ft_strcpy(dest,src);
    printf("\n-------- FT_STRCPY --------\n");
	printf("String destino: %s\n",dest);
	printf("String Source : %s\n",src);



    //------- FT_STRCMP --------------- FT_STRCMP--------------- FT_STRCMP --------
    char str[] = "-AAS##ddd998";
	char str1[] = "-A1S5#ddd998";

    printf("\n-------- FT_STRCMP --------\n");
	printf("ft_strcmp: %d\n",ft_strcmp(str,str1));
	printf("strcmp: %d\n",strcmp(str,str1));


    //------- FT_STRDUP --------------- FT_STRDUP--------------- FT_STRDUP --------
    char dest1[] = "555555";
	char *p;
	

    printf("\n-------- FT_STRDUP --------\n");
	p = ft_strdup(dest1);
	printf("A string foi copiada: %s\n" ,p );


    free(p);






    //------- FT_WRITE --------------- FT_WRITE--------------- FT_WRITE --------
    printf("\n-------- FT_WRITE --------\n");
    ft_write(1, "Hello World!\n", 12);



    //------- FT_READ --------------- FT_READ--------------- FT_READ --------

    char buffer[100];
    ssize_t n;

    printf("\n-------- FT_READ --------\n");
    ft_write(1, "Digita Algo: \n", 13);
    
    n = ft_read(0, buffer, 99); // ler até 99 bytes do stdin
    if (n < 0) {
       buffer[n] = '\0'; // termina a string
    printf("Você digitou: %s\n", buffer);
    printf("Bytes lidos: %zd\n", n);     perror("Erro ao ler");
        return 1;
    }

    buffer[n] = '\0'; // termina a string
    printf("Você digitou: %s\n", buffer);
    printf("Bytes lidos: %zd\n", n);




    //------- BONUS --------------- BONUS --------------- BONUS --------
    printf("\n-------- BONUS --------\n");
    

    t_list *ola = malloc(sizeof(t_list));
    t_list *mundo = malloc(sizeof(t_list));

 
    if (!ola && !mundo)
        return (1);

    ola->data = "ola mundo";
    ola->next = mundo;

    

    ola->data = "Another world";
    mundo->next = NULL;


    

    printf("\n-------- FT_LIST_SIZE --------\n");
    printf("A lista tem : %d\n", ft_list_size(ola));
   

    free(ola);
    free(mundo);

    printf("\n-------- LISBASM ---------------- LISBASM ---------------- LISBASM --------\n");

}