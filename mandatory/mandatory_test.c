/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e <rsilva-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 12:41:01 by rsilva-e          #+#    #+#             */
/*   Updated: 2026/01/22 12:49:02 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libasm.h"

void test_ft_strlen()
{
    //------- FT_STRLEN --------------- FT_STRLEN --------------- FT_STRLEN --------
    printf("\n-------- FT_STRLEN --------\n\n");
    char str1[] = "Hello world";
    char str2[] = "";
    char str3[] = "1234567";
    char str4[] = "!@#$%^&*()";
    
    

    printf("The sentence:[%s]\n", str1);
    printf("ft_strlen: %lu\n", ft_strlen(str1));
    printf("strlen   : %lu\n\n", strlen(str1));

    printf("The sentence:[%s]\n", str2);
    printf("ft_strlen: %lu\n", ft_strlen(str2));
    printf("strlen   : %lu\n\n", strlen(str2));

    printf("The sentence:[%s]\n", str3);
    printf("ft_strlen: %lu\n", ft_strlen(str3));
    printf("strlen   : %lu\n\n", strlen(str3));

    printf("The sentence:[%s]\n", str4);
    printf("ft_strlen: %lu\n", ft_strlen(str4));
    printf("strlen   : %lu\n\n", strlen(str4));
}


void test_ft_strcpy()
{
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

    
}


void test_ft_strcmp()
{
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
    
     
}


void test_ft_strdup()
{
    
    //------- FT_STRDUP --------------- FT_STRDUP--------------- FT_STRDUP --------
    printf("\n-------- FT_STRDUP --------\n\n");

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
}

void test_ft_write()
{
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

}


void test_ft_read()
{
    //------- FT_READ --------------- FT_READ--------------- FT_READ --------
    /*printf("\n-------- FT_WRITE --------\n\n");
    char buffer[100];
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
}
