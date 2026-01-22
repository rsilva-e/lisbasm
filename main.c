/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e <rsilva-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:02:37 by rsilva-e          #+#    #+#             */
/*   Updated: 2026/01/22 12:45:13 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libasm.h"

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
    //------- MANDATORY --------------- MANDATORY --------------- MANDATORY --------
   
    test_ft_strlen();
    test_ft_strcpy();
    test_ft_strcmp();
    test_ft_strdup();
    test_ft_write();
    test_ft_read();
    
    //------- BONUS --------------- BONUS --------------- BONUS --------
    
    printf("\n-------- BONUS ---------------- BONUS ---------------- BONUS -------------\n");
    
    printf("\n-------- FT_ATOI_BASE --------\n\n");


    //test_ft_atoi_base();
    //test_ft_list_base();
    //test_ft_atoi_base();
    //test_ft_atoi_base();


    // Teste 1: binário simples com sinal e espaços
    printf("%d\n", ft_atoi_base("   -101", "01"));     
    // Expected output: -5

    // Teste 2: hexadecimal
    printf("%d\n", ft_atoi_base("7F", "0123456789ABCDEF")); 
    // Expected output: 127

    // Teste 3: decimal simples
    printf("%d\n", ft_atoi_base("42", "0123456789"));  
    // Expected output: 42

    // Teste 4: base inválida (apenas 1 caractere)
    printf("%d\n", ft_atoi_base("42", "0"));  
    // Expected output: 0

    // Teste 5: base inválida (contém espaço e '+')
    printf("%d\n", ft_atoi_base("42", "  ")); 
    // Expected output: 0

    // Teste 6: base inválida (contém '-')
    printf("%d\n", ft_atoi_base("42", "  -")); 
    // Expected output: 0

    // Teste 7: base válida mas 42 nao existe na base → inválida
    printf("%d\n", ft_atoi_base("42", "AB")); 
    // Expected output: 0

    // Teste 8: base grande com símbolos especiais
    char *big_base = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!@#$%^&*()";
    printf("%d\n", ft_atoi_base("ZZ!@", big_base)); 
    // Expected output: 61*62*62 + 61*62 + 62 ??? depende do cálculo correto
    // Vamos simplificar: apenas valida se não crasha e retorna >0

    // Teste 9: sinais misturados e espaços
    printf("%d\n", ft_atoi_base("   +--+-101", "01")); 
    // Expected output: -5

    // Teste 10: string termina com caracteres inválidos
    printf("%d\n", ft_atoi_base("101abc", "01")); 
    // Expected output: 5

    // Teste 11: base hexadecimal com letras minúsculas (case sensitive)
    printf("%d\n", ft_atoi_base("7", "0123456789ABCDEF")); 
    
    // Teste 12: Numero decimal grande
    printf("ft_atoi_base:%d\n", ft_atoi_base("111111111111", "0123456789")); 
    printf("atoi::%d\n\n", atoi("111111111111")); 

    printf("ft_atoi_base:%d\n", ft_atoi_base("2147483647", "0123456789")); 
    printf("atoi::%d\n\n", atoi("2147483647")); 

    printf("ft_atoi_base:%d\n", ft_atoi_base("2147483648", "0123456789")); 
    printf("atoi::%d\n\n", atoi("2147483648")); 

    printf("ft_atoi_base:%d\n", ft_atoi_base("-2147483648", "0123456789")); 
    printf("atoi::%d\n\n", atoi("-2147483648")); 

   
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
    free_list(list3);


    printf("\n-------- LISBASM ---------------- LISBASM ---------------- LISBASM --------\n");

}