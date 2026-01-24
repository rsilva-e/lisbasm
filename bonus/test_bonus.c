/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e <rsilva-e@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-23 14:53:53 by rsilva-e          #+#    #+#             */
/*   Updated: 2026-01-23 14:53:53 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libasm.h"

int cmp_str(void *data1, void *data2)
{
    return ft_strcmp((char *)data1, (char *)data2);
}

void free_str(void *data)
{
    free(data);
}

void test_ft_atoi_base()
{
    printf("\n-------- FT_ATOI_BASE --------\n\n");
    // Test 1: simple binary with sign and spaces
    printf("%d\n", ft_atoi_base("   -101", "01"));     
    // Expected: -5

    // Test 2: hexadecimal
    printf("%d\n", ft_atoi_base("7F", "0123456789ABCDEF")); 
    // Expected: 127

    // Test 3: decimal
    printf("%d\n", ft_atoi_base("42", "0123456789"));  
    // Expected: 42

    // Test 4: invalid base (1 char)
    printf("%d\n", ft_atoi_base("42", "0"));  
    // Expected: 0

    // Test 5: invalid base (spaces or '+')
    printf("%d\n", ft_atoi_base("42", "  ")); 
    // Expected: 0

    // Test 6: invalid base (contains '-')
    printf("%d\n", ft_atoi_base("42", "  -")); 
    // Expected: 0

    // Test 7: valid base but number not in base
    printf("%d\n", ft_atoi_base("42", "AB")); 
    // Expected: 0

    // Test 8: large base with special symbols
    char *big_base = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!@#$%^&*()";
    printf("%d\n", ft_atoi_base("ZZ!@", big_base)); 
    // Check it doesn't crash

    // Test 9: mixed signs and spaces
    printf("%d\n", ft_atoi_base("   +--+-101", "01")); 
    // Expected: -5

    // Test 10: string ends with invalid characters
    printf("%d\n", ft_atoi_base("101abc", "01")); 
    // Expected: 5

    // Test 11: hexadecimal with uppercase letters
    printf("%d\n", ft_atoi_base("7", "0123456789ABCDEF")); 
    // Expected: 7

    // Test 12: large decimal numbers
    printf("ft_atoi_base: %d\n", ft_atoi_base("111111111111", "0123456789")); 
    printf("atoi: %d\n\n", atoi("111111111111")); 

    printf("ft_atoi_base: %d\n", ft_atoi_base("2147483647", "0123456789")); 
    printf("atoi: %d\n\n", atoi("2147483647")); 

    printf("ft_atoi_base: %d\n", ft_atoi_base("2147483648", "0123456789")); 
    printf("atoi: %d\n\n", atoi("2147483648")); 

    printf("ft_atoi_base: %d\n", ft_atoi_base("-2147483648", "0123456789")); 
    printf("atoi: %d\n\n", atoi("-2147483648")); 


}


void test_ft_list_push_front(t_list **list,t_list **list2,t_list **list3)
{

    printf("\n-------- FT_LIST_PUSH_FRONT --------\n\n");

    ft_list_push_front(list, ft_strdup("Hello"));
    print_list(*list);
    ft_list_push_front(list, ft_strdup("World"));
    print_list(*list);
    ft_list_push_front(list, ft_strdup("Test"));
    print_list(*list);
    ft_list_push_front(list, ft_strdup("World"));
    print_list(*list);
    ft_list_push_front(list, ft_strdup(""));
    print_list(*list);
    ft_list_push_front(list, ft_strdup("    "));
    printf("\nThe First List:\n");
    print_list(*list);

    
    printf("\nThe Second List:\n");
    ft_list_push_front(list2,ft_strdup("World"));
    ft_list_push_front(list2,ft_strdup("Another"));
    ft_list_push_front(list2,ft_strdup("Another"));
    ft_list_push_front(list2,ft_strdup("Other"));
    ft_list_push_front(list2,ft_strdup("Amazing"));
    ft_list_push_front(list2,ft_strdup("Another"));
    ft_list_push_front(list2,ft_strdup("Special"));
    print_list(*list2);


    printf("\nThe Third List:\n");
    ft_list_push_front(list3,ft_strdup("Y"));
    ft_list_push_front(list3,ft_strdup("T"));
    ft_list_push_front(list3,ft_strdup("B"));
    ft_list_push_front(list3,ft_strdup("A"));
    ft_list_push_front(list3,ft_strdup("C"));
    ft_list_push_front(list3,ft_strdup("D"));
    print_list(*list3);

}
void test_ft_list_size(t_list **list,t_list **list2,t_list **list3)
{

    printf("\n-------- FT_LIST_SIZE --------------\n\n");
    
    printf("The first list is of size : %d\n", ft_list_size(*list));
    printf("The second list is of size : %d\n", ft_list_size(*list2));
    printf("The third list is of size : %d\n", ft_list_size(*list3));

}


void test_ft_list_sort(t_list **list,t_list **list2,t_list **list3)
{
    printf("\n-------- FT_LIST_SORT--------------\n\n");

    ft_list_sort(list,cmp_str);
    printf("\nThe First List:\n");
    print_list(*list);

    ft_list_sort(list2,cmp_str);
    printf("\nThe Second List:\n");
    print_list(*list2);

    ft_list_sort(list3,cmp_str);
    printf("\nThe Third List:\n");
    print_list(*list3);

}

void test_ft_list_remove_if(t_list **list,t_list **list2,t_list **list3)
{

    printf("\n-------- FT_LIST_REMOVE_IF --------\n\n");

    printf("First List - remove 'World'...\n");
    ft_list_remove_if(list, "World", cmp_str, free_str);
    print_list(*list);
    printf("Tamanho: %d\n\n", ft_list_size(*list)); 


    printf("Second List - remove 'Another'...\n");
    ft_list_remove_if(list2, "Another", cmp_str, free_str);
    print_list(*list2);
    printf("Tamanho: %d\n\n", ft_list_size(*list2));

    printf("Third List - remove 'Another'...\n");
    ft_list_remove_if(list3, "Another", cmp_str, free_str);
    print_list(*list3);
    printf("Tamanho: %d\n\n", ft_list_size(*list3)); 

}
    