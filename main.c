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



    ft_read(-1, buffer, 99); // ler até 99 bytes do stdin
    

    ssize_t ret;

    printf("=== Teste 1: leitura valida de stdin ===\n");
    printf("Digite algo: ");
    ret = ft_read(0, buffer, sizeof(buffer) - 1); // stdin = fd 0
    if (ret >= 0)
    {
        buffer[ret] = '\0';
        printf("ft_read leu %zd bytes: '%s'\n", ret, buffer);
    }
    else
    {
        printf("ft_read erro! errno = %d (%s)\n", errno, strerror(errno));
    }

    printf("\n=== Teste 2: fd invalido ===\n");
    ret = ft_read(-1, buffer, sizeof(buffer));
    if (ret == -1)
        printf("fd invalido, ft_read retornou -1, errno = %d (%s)\n", errno, strerror(errno));
    else
        printf("ERRO: fd invalido retornou %zd\n", ret);

    printf("\n=== Teste 3: ler 0 bytes ===\n");
    ret = ft_read(0, buffer, 0);
    if (ret >= 0)
        printf("ft_read leu %zd bytes (esperado 0)\n", ret);
    else
        printf("ft_read erro inesperado! errno = %d (%s)\n", errno, strerror(errno));






    //------- BONUS --------------- BONUS --------------- BONUS --------
    printf("\n-------- BONUS --------\n");
    

    t_list *ola = malloc(sizeof(t_list));
    t_list *mundo = malloc(sizeof(t_list));

 
    if (!ola || !mundo)
        return (1);

    ola->data = "ola mundo1";
    ola->next = mundo;

    mundo->data = "Another world1";
    mundo->next = NULL;

    char *data2 = "world2";
    
    t_list *worlds = ola;       // ponteiro para o primeiro nó
    t_list **worlds_ptr = &worlds; // ponteiro para ponteiro


    printf("\n-------- FT_LIST_SIZE --------\n");
    printf("A lista tem : %d\n", ft_list_size(ola));



    printf("\n-------- FT_LIST_PUSH_FRONT --------\n");

             

   
    ft_list_push_front(worlds_ptr,data2);
    printf("Size Worlds was : %d\n", ft_list_size(worlds));

    t_list *list = NULL;

    ft_list_push_front(&list, "Hello");
    printf("List size was : %d\n", ft_list_size(list));
    ft_list_push_front(&list, "World");
    printf("List size was : %d\n", ft_list_size(list));

    while(list)
    {
        t_list *temp;


        temp = list->next;

        free(list);

        list = temp;
    }


    while(worlds)
    {
        t_list *temp;


        temp = worlds->next;

        free(worlds);

        worlds = temp;
    }
   

    

    printf("\n-------- LISBASM ---------------- LISBASM ---------------- LISBASM --------\n");

}