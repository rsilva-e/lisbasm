/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e <rsilva-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:02:37 by rsilva-e          #+#    #+#             */
/*   Updated: 2026/01/15 22:47:18 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libasm.h"
#include <string.h>

void print_list(t_list *list)
{
    while (list)
    {
        printf("%s->", (char *)list->data);
        list = list->next;
    }
    printf("NULL\n");
}

void free_list(t_list *list)
{
    t_list *temp;

    while(list)
    { 
        temp = list->next;
        free(list->data);
        free(list);

        list = temp;
    }
}


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



/*     ft_read(-1, buffer, 99); // ler até 99 bytes do stdin
    

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

 */




    //------- BONUS --------------- BONUS --------------- BONUS --------
    
    
    printf("\n-------- BONUS ---------------- BONUS ---------------- BONUS -------------\n");

    //printf("\n========== FT_LIST_PUSH_FRONT ================\n");


    printf("\n-------- FT_ATOI_BASE --------\n\n");

    
    printf("%d",ft_atoi_base("   -101", "01"));        // -5 binary
    ft_atoi_base("7F", "0123456789ABCDEF"); // 127 Hexadecimal 
    ft_atoi_base("42", "0123456789");     // 42 decimal
    ft_atoi_base("42", "0");              // 0 (base inválida)

    
    
   
    printf("\n-------- FT_LIST_PUSH_FRONT --------\n\n");

    t_list *list = NULL;
    t_list *list2 = NULL;
    t_list *list3 = NULL;


    ft_list_push_front(&list, ft_strdup("Hello"));
    print_list(list);
    ft_list_push_front(&list, ft_strdup("World"));
    print_list(list);
    ft_list_push_front(&list, ft_strdup("Test"));
    print_list(list);
    ft_list_push_front(&list, ft_strdup("World"));
    print_list(list);
    ft_list_push_front(&list, ft_strdup(""));
    print_list(list);
    ft_list_push_front(&list, ft_strdup("    "));
    printf("\nThe first List:\n");
    print_list(list);

    
    printf("\nThe Second List:\n");
    ft_list_push_front(&list2,ft_strdup("World"));
    ft_list_push_front(&list2,ft_strdup("Another"));
    ft_list_push_front(&list2,ft_strdup("Another"));
    ft_list_push_front(&list2,ft_strdup("Other"));
    ft_list_push_front(&list2,ft_strdup("Amazing"));
    ft_list_push_front(&list2,ft_strdup("Another"));
    ft_list_push_front(&list2,ft_strdup("Special"));
    print_list(list2);


    printf("\nThe Thrid List:\n");
    ft_list_push_front(&list3,ft_strdup("Y"));
    ft_list_push_front(&list3,ft_strdup("T"));
    ft_list_push_front(&list3,ft_strdup("B"));
    ft_list_push_front(&list3,ft_strdup("A"));
    ft_list_push_front(&list3,ft_strdup("C"));
    ft_list_push_front(&list3,ft_strdup("D"));
    print_list(list3);


    //printf("\n========== FT_LIST_SIZE ================\n");

    printf("\n-------- FT_LIST_SIZE --------------\n\n");
    printf("The first list is of size : %d\n", ft_list_size(list));
    printf("The second list is of size : %d\n", ft_list_size(list2));



    printf("\n-------- FT_LIST_SORT--------------\n\n");

    ft_list_sort(&list,cmp_str);
    printf("\nThe first List:\n");
    print_list(list);

    ft_list_sort(&list2,cmp_str);
    printf("\nThe Second List:\n");
    print_list(list2);

    ft_list_sort(&list3,cmp_str);
    printf("\nThe Thrid List:\n");
    print_list(list3);
    



    
    //printf("\n========== FT_LIST_REMOVE_IF ================\n");
    printf("\n-------- FT_LIST_REMOVE_IF --------\n\n");

    printf("First List - remove 'World'...\n");
    ft_list_remove_if(&list, "World", cmp_str, free_str);
    print_list(list);
    printf("Tamanho: %d\n\n", ft_list_size(list)); 


    printf("Second List - remove 'Another'...\n");
    ft_list_remove_if(&list2, "Another", cmp_str, free_str);
    print_list(list2);
    printf("Tamanho: %d\n\n", ft_list_size(list2)); 


    free_list(list);
    free_list(list2);
   


    printf("\n-------- LISBASM ---------------- LISBASM ---------------- LISBASM --------\n");

}