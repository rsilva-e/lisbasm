/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e <rsilva-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:02:37 by rsilva-e          #+#    #+#             */
/*   Updated: 2026/01/16 17:54:07 by rsilva-e         ###   ########.fr       */
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
    //------- FT_STRLEN --------------- FT_STRLEN --------------- FT_STRLEN --------
    
    char str1[] = "Hello world";
    char str2[] = "";
    char str3[] = "1234567";
    char str4[] = "!@#$%^&*()";
    
    printf("\n-------- FT_STRLEN --------\n\n");

    printf("The sentence:[%s]\n", str1);
    printf("ft_strlen: %lu\n", ft_strlen(str1));
    printf("strlen   : %lu\n\n", strlen(str1));

    printf("The sentence:[%s]\n", str2);
    printf("ft_strlen: %lu\n", ft_strlen(str2));
    printf("strlen   : %lu\n\n", strlen(str2)); // empty

    printf("The sentence:[%s]\n", str3);
    printf("ft_strlen: %lu\n", ft_strlen(str3));
    printf("strlen   : %lu\n\n", strlen(str3));

    printf("The sentence:[%s]\n", str4);
    printf("ft_strlen: %lu\n", ft_strlen(str4));
    printf("strlen   : %lu\n\n", strlen(str4));


    
    //------- FT_STRCPY --------------- FT_STRCPY --------------- FT_STRCPY --------
   
    printf("\n-------- FT_STRCPY --------\n\n");
    
    char dest[50];

    // 1. Normal string
    ft_strcpy(dest, "S55faff");
    printf("ft_strcpy: [%s]\n", dest);
    strcpy(dest, "S55faff");
    printf("strcpy   : [%s]\n\n", dest);

    // 2. Longer string
    ft_strcpy(dest, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
    printf("ft_strcpy: [%s]\n", dest);
    strcpy(dest, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
    printf("strcpy   : [%s]\n\n", dest);

    // 3. Empty string
    ft_strcpy(dest, "");
    printf("ft_strcpy (empty): [%s]\n", dest);
    strcpy(dest, "");
    printf("strcpy    (empty): [%s]\n\n", dest);

    // 4. String with spaces
    ft_strcpy(dest, "hello   world");
    printf("ft_strcpy: [%s]\n", dest);
    strcpy(dest, "hello   world");
    printf("strcpy   : [%s]\n\n", dest);

    // 5. String with special characters
    ft_strcpy(dest, "!@#$%^&*()");
    printf("ft_strcpy: [%s]\n", dest);
    strcpy(dest, "!@#$%^&*()");
    printf("strcpy   : [%s]\n\n", dest);


    //------- FT_STRCMP --------------- FT_STRCMP--------------- FT_STRCMP --------


    printf("\n-------- FT_STRCMP --------\n\n");
/* 	printf("ft_strcmp1: %d\n",ft_strcmp("-AA","-A1"));
	printf("strcmp1: %d\n",strcmp("-AA","-A1"));


    printf("ft_strcmp2: %d\n",ft_strcmp("A","AB"));
	printf("strcmp2: %d\n",strcmp("A","AB"));

    printf("ft_strcmp3: %d\n",ft_strcmp("A","A"));
	printf("strcmp3: %d\n",strcmp("A","A"));
 */

    

    // Different strings
    printf("ft_strcmp1: %d\n", ft_strcmp("-AAddd", "-A1"));
    printf("strcmp1   : %d\n", strcmp("-AAdddd", "-A1"));

    // 2.Equal strings
    printf("ft_strcmp3: %d\n", ft_strcmp("A", "A"));
    printf("strcmp3   : %d\n", strcmp("A", "A"));

    // 3.Empty strings
    printf("ft_strcmp4: %d\n", ft_strcmp("", ""));
    printf("strcmp4   : %d\n", strcmp("", ""));

    // 4.Empty and non-empty
    printf("ft_strcmp5: %d\n", ft_strcmp("", "abc"));
    printf("strcmp5   : %d\n", strcmp("", "abc"));

    // 5.Non-empty and empty
    printf("ft_strcmp6: %d\n", ft_strcmp("abc", ""));
    printf("strcmp6   : %d\n", strcmp("abc", ""));

    // 6.Numbers inside strings
    printf("ft_strcmp8: %d\n", ft_strcmp("123", "124"));
    printf("strcmp8   : %d\n", strcmp("123", "124"));

    // 7.Special characters
    printf("ft_strcmp9: %d\n", ft_strcmp("!@#", "!@!"));
    printf("strcmp9   : %d\n", strcmp("!@#", "!@!"));

 



    //------- FT_STRDUP --------------- FT_STRDUP--------------- FT_STRDUP --------


    // 1.Normal string
    {
        char s[] = "555555";
        char *str = ft_strdup(s);

        printf("1. Original: %s | Duplicate: %s\n", s, str);
        printf("equal content: %s\n", ft_strcmp(s, str) == 0 ? "OK" : "KO");

        free(str);
    }

    // 2.Empty string
    {
        char s[] = "";
        char *str = ft_strdup(s);

        printf("2. Original (empty): \"%s\" | Duplicate: \"%s\"\n", s, str);
        printf("equal content: %s\n", ft_strcmp(s, str) == 0 ? "OK" : "KO");

        free(str);
    }

    // 3.String with spaces
    {
        char s[] = "hello   world   42";
        char *str = ft_strdup(s);

        printf("3. Original: %s | Duplicate: %s\n", s, str);
        printf("equal content: %s\n", ft_strcmp(s, str) == 0 ? "OK" : "KO");

        free(str);
    }

    // 4.Special characters
    {
        char s[] = "!@#$%^&*()_+-={}[]|:;<>,.?/";
        char *str = ft_strdup(s);

        printf("4. Original: %s | Duplicate: %s\n", s, str);
        printf("equal content: %s\n", ft_strcmp(s, str) == 0 ? "OK" : "KO");

        free(str);
    }

    // 5.Long string
    {
        char s[1001];
        memset(s, 'A', 1000);
        s[1000] = '\0';

        char *str = ft_strdup(s);

        printf("5. Long string length: %zu\n", strlen(str));
        printf("equal content: %s\n", ft_strcmp(s, str) == 0 ? "OK" : "KO");

        free(str);
    }

    // 6.Independence test (modify original)
    {
        char s[] = "independent";
        char *str = ft_strdup(s);

        s[0] = 'X';

        printf("6. After modifying original: %s | Duplicate: %s\n", s, str);
        printf("independent memory: %s\n",
            ft_strcmp("independent", str) == 0 ? "OK" : "KO");

        free(str);
    }


    //------- FT_WRITE --------------- FT_WRITE--------------- FT_WRITE --------
   
    printf("\n-------- FT_WRITE --------\n\n");

    //ft_write(1, "Hello World!\n\n", 13);
    //write(1, "Hello World!\n\n", 13);


        char big[1024];
    for (int i = 0; i < 1023; i++)
        big[i] = 'A' + (i % 26);
    big[1023] = '\0';


        // 1️⃣ Normal write
    ft_write(1, "Hello World!\n", 13);
    write(1, "Hello World!\n", 13);

    // 2️⃣ Empty string
    ft_write(1, "", 0);
    write(1, "", 0);

    // 3️⃣ Special characters
    ft_write(1, "!@#$%^&*()_+-=[]{}|;:',.<>/?\n", 30);
    write(1, "!@#$%^&*()_+-=[]{}|;:',.<>/?\n", 30);

    // 4️⃣ Large string
    ft_write(1, big, strlen(big));
    write(1, big, strlen(big));

    // 5️⃣ Multiple consecutive writes
    ft_write(1, "Line 1\n", 7);
    ft_write(1, "Line 2\n", 7);
    ft_write(1, "Line 3\n", 7);
    write(1, "Line 1\nLine 2\nLine 3\n", 21);

    // 6️⃣ Invalid fd
    ssize_t ret1 = ft_write(-1, "Test invalid fd\n", 16);
    ssize_t ret2 = write(-1, "Test invalid fd\n", 16);
    printf("ft_write return: %ld | write return: %ld\n", ret1, ret2);

/*     // 7️⃣ Binary data (non-printable)
    char bin[5] = {0x00, 0x01, 0xFF, 0x7F, '\n'};
    ft_write(1, bin, 5);
    write(1, bin, 5); */




    //------- FT_READ --------------- FT_READ--------------- FT_READ --------

  /*   char buffer[100];
    ssize_t n;

    printf("\n-------- FT_READ --------\n\n");
    ft_write(1, "Digita Algo->\n", 13);
    
    n = ft_read(0, buffer, 99); // ler até 99 bytes do stdin
    if (n < 0) 
    {
        buffer[n] = '\0'; // termina a string
        printf("Você digitou:%s\n", buffer);
        printf("Bytes lidos:%zd\n", n);     
        perror("Erro ao ler");
        return 1;
    }

    buffer[n] = '\0'; // termina a string
    printf("Você digitou->%s", buffer);
    printf("Bytes lidos->%zd\n", n); */



/*ft_read(-1, buffer, 99); // ler até 99 bytes do stdin
    

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
    
    

    printf("\n-------- FT_ATOI_BASE --------\n\n");


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