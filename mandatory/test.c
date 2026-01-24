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

    {
    char str1[] = "-AAddd";
    char str2[] = "-A1";
    // Different strings
    printf("ft_strcmp1: %d\n", ft_strcmp(str1, str2));
    printf("strcmp1   : %d\n\n", strcmp(str1, str2));
    }
    
    {
    // 2.Equal strings
    char str1[] = "A";
    char str2[] = "A";
    printf("ft_strcmp3: %d\n", ft_strcmp(str1, str2));
    printf("strcmp3   : %d\n\n", strcmp(str1, str2));
    }
    
    {
    // 3.Empty strings
    char str1[] = "";
    char str2[] = "";
    printf("ft_strcmp4: %d\n", ft_strcmp(str1, str2));
    printf("strcmp4   : %d\n\n", strcmp(str1,str2));
    }
    
    {
    // 4.Empty and non-empty
    char str1[] = "";
    char str2[] = "abc";
    printf("ft_strcmp5: %d\n", ft_strcmp(str1, str2));
    printf("strcmp5   : %d\n\n", strcmp(str1, str2));
    }

    {
    // 5.Non-empty and empty
    char str1[] = "abc";
    char str2[] = "";
    printf("ft_strcmp6: %d\n", ft_strcmp(str1, str2));
    printf("strcmp6   : %d\n\n", strcmp(str1, str2));
    }

    {
    // 6.Numbers inside strings
    char str1[] = "123";
    char str2[] = "124";
    printf("ft_strcmp8: %d\n", ft_strcmp(str1, str2));
    printf("strcmp8   : %d\n\n", strcmp(str1, str2));
    }

    {
    // 7.Special characters
    char str1[] = "!@#";
    char str2[] = "!@!";
    printf("ft_strcmp9: %d\n", ft_strcmp(str1, str2));
    printf("strcmp9   : %d\n\n", strcmp(str1, str2));
    }
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
        printf("equal content: %s\n\n", ft_strcmp(s, str) == 0 ? "OK" : "KO");

        free(str);
    }

    // 3.String with spaces
    {
        char s[] = "hello   world   42";
        char *str = ft_strdup(s);

        printf("3. Original: %s | Duplicate: %s\n", s, str);
        printf("equal content: %s\n\n", ft_strcmp(s, str) == 0 ? "OK" : "KO");

        free(str);
    }

    // 4.Special characters
    {
        char s[] = "!@#$%^&*()_+-={}[]|:;<>,.?/";
        char *str = ft_strdup(s);

        printf("4. Original: %s | Duplicate: %s\n", s, str);
        printf("equal content: %s\n\n", ft_strcmp(s, str) == 0 ? "OK" : "KO");

        free(str);
    }

    // 5.Long string
    {
        char s[1001];
        memset(s, 'A', 1000);
        s[1000] = '\0';

        char *str = ft_strdup(s);

        printf("5. Long string length: %zu\n", strlen(str));
        printf("equal content: %s\n\n", ft_strcmp(s, str) == 0 ? "OK" : "KO");

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

    //1.Normal write
    printf("=== Test 1: Normal write ===\n");
    printf("ft_write:");
    ft_write(1, "Hello World!\n", 13);
    printf("write:");
    write(1, "Hello World!\n", 13);

    //2.Empty string
    printf("\n=== Test 2: Empty string ===\n");
    ft_write(1, "", 0);
    write(1, "", 0);

    //3.Special characters
    ft_write(1, "!@#$%^&*()_+-=[]{}|;:',.<>/?\n", 30);
    write(1, "!@#$%^&*()_+-=[]{}|;:',.<>/?\n", 30);

    //4.Invalid fd
    ssize_t ret1 = ft_write(-1, "Test invalid fd\n", 16);
    ssize_t ret2 = write(-1, "Test invalid fd\n", 16);
    printf("ft_write return: %ld | write return: %ld\n", ret1, ret2);

}


void test_ft_read()
{
    //------- FT_READ --------------- FT_READ--------------- FT_READ --------
    
    printf("\n-------- FT_READ --------\n\n");
    char buffer[100];
    ssize_t n;

    printf("=== Test 1: valid stdin read ===\n");
    ft_write(1, "Write something ->\n", 18);
  
    n = ft_read(0, buffer, sizeof(buffer)); // stdin = fd 0
    if (n >= 0)
    {
        buffer[n] = '\0';
        printf("ft_read read %zd bytes ->%s", n, buffer);
    }
    else
        perror("Error");

    printf("\n=== Test 2: invalid fd ===\n");
    n = ft_read(-1, buffer, sizeof(buffer));
    if (n == -1)
        printf("invalid fd, ft_read returned -1, errno = %d (%s)\n", errno, strerror(errno));
    else
        perror("Error");

    printf("\n=== Test 3: read 0 bytes ===\n");
    n = ft_read(0, buffer, 0);
    if (n >= 0)
        printf("ft_read read %zd bytes (expected 0)\n", n);
    else
        perror("Error");
}