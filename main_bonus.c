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

    test_ft_strlen();
    test_ft_strcpy();
    test_ft_strcmp();
    test_ft_strdup();
    test_ft_write();
    test_ft_read();
    
    printf("\n-------- BONUS ---------------- BONUS ---------------- BONUS -------------\n");
    
    t_list *list = NULL;
    t_list *list2 = NULL;
    t_list *list3 = NULL;

    test_ft_atoi_base();
    test_ft_list_push_front(&list,&list2,&list3);
    test_ft_list_size(&list,&list2,&list3);
    test_ft_list_sort(&list,&list2,&list3);
    test_ft_list_remove_if(&list,&list2,&list3);

    free_list(list);
    free_list(list2);
    free_list(list3);

    printf("\n-------- LISBASM ---------------- LISBASM ---------------- LISBASM --------\n");

}