#include "libft.h"
#include <assert.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <linux/stat.h>
#include <sys/stat.h>
#include <ctype.h>

/*
	ft_is
*/
void	test_ft_isalpha(void)
{
	// Test cases for alphabetic characters
	assert(ft_isalpha('a') == 1);
	assert(ft_isalpha('A') == 1);
	assert(ft_isalpha('z') == 1);
	assert(ft_isalpha('Z') == 1);
	// Test cases for non-alphabetic characters
	assert(ft_isalpha('0') == 0);
	assert(ft_isalpha('9') == 0);
	assert(ft_isalpha(' ') == 0);
	assert(ft_isalpha('\t') == 0);
	assert(ft_isalpha('\n') == 0);
	assert(ft_isalpha('!') == 0);
	// Test edge cases
	assert(ft_isalpha(0) == 0);
	assert(ft_isalpha(127) == 0);
	assert(ft_isalpha(-1) == 0);
}

void	test_ft_isascii(void)
{
	// Test cases for ASCII characters
	assert(ft_isascii(0) == 1);
	assert(ft_isascii(127) == 1);
	assert(ft_isascii('a') == 1);
	assert(ft_isascii('A') == 1);
	assert(ft_isascii('0') == 1);
	assert(ft_isascii(' ') == 1);
	// Test cases for non-ASCII characters
	assert(ft_isascii(-1) == 0);
	assert(ft_isascii(128) == 0);
	assert(ft_isascii(255) == 0);
}

void	test_ft_isdigit(void)
{
	// Test cases for digit characters
	assert(ft_isdigit('0') == 1);
	assert(ft_isdigit('9') == 1);
	assert(ft_isdigit('5') == 1);
	// Test cases for non-digit characters
	assert(ft_isdigit('a') == 0);
	assert(ft_isdigit('A') == 0);
	assert(ft_isdigit(' ') == 0);
	assert(ft_isdigit('\t') == 0);
	assert(ft_isdigit('\n') == 0);
	assert(ft_isdigit('!') == 0);
	// Test edge cases
	assert(ft_isdigit(0) == 0);
	assert(ft_isdigit(127) == 0);
	assert(ft_isdigit(-1) == 0);
}

void	test_ft_isprint(void)
{
	// Test cases for printable characters
	assert(ft_isprint(' ') == 1);
	assert(ft_isprint('~') == 1);
	assert(ft_isprint('a') == 1);
	assert(ft_isprint('A') == 1);
	assert(ft_isprint('0') == 1);
	assert(ft_isprint('!') == 1);
	// Test cases for non-printable characters
	assert(ft_isprint(0) == 0);
	assert(ft_isprint(31) == 0);
	assert(ft_isprint(127) == 0);
	assert(ft_isprint(-1) == 0);
}

void	test_ft_isalnum(void)
{
	// Test cases for alphanumeric characters
	assert(ft_isalnum('a') == 1);
	assert(ft_isalnum('A') == 1);
	assert(ft_isalnum('z') == 1);
	assert(ft_isalnum('Z') == 1);
	assert(ft_isalnum('0') == 1);
	assert(ft_isalnum('9') == 1);
	// Test cases for non-alphanumeric characters
	assert(ft_isalnum(' ') == 0);
	assert(ft_isalnum('\t') == 0);
	assert(ft_isalnum('\n') == 0);
	assert(ft_isalnum('!') == 0);
	assert(ft_isalnum('@') == 0);
	assert(ft_isalnum('#') == 0);
	assert(ft_isalnum('$') == 0);
	assert(ft_isalnum('%') == 0);
	assert(ft_isalnum('^') == 0);
	assert(ft_isalnum('&') == 0);
	assert(ft_isalnum('*') == 0);
	// Test edge cases
	assert(ft_isalnum(0) == 0);
	assert(ft_isalnum(127) == 0);
	assert(ft_isalnum(-1) == 0);
}

/*
	ft_lst
*/
void	test_ft_lstsize(void)
{
	t_list	*lst;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	// Test case for empty list
	lst = NULL;
	assert(ft_lstsize(lst) == 0);
	// Test case for a list with multiple elements
	node1 = ft_lstnew("node1");
	node2 = ft_lstnew("node2");
	node3 = ft_lstnew("node3");
	node1->next = node2;
	node2->next = node3;
	assert(ft_lstsize(node1) == 3);
	// Free the memory
	free(node1);
	free(node2);
	free(node3);
}

void	test_ft_lstnew(void)
{
	char	*content;
	t_list	*new_node;

	// Test case for creating a new node
	content = "new node";
	new_node = ft_lstnew(content);
	assert(new_node != NULL);
	assert(new_node->content == content);
	assert(new_node->next == NULL);
	// Free the memory
	free(new_node);
}

void	test_ft_lstmap(void)
{
	t_list	*lst;
	t_list	*mapped_lst;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	// Test case for empty list
	lst = NULL;
	mapped_lst = ft_lstmap(lst, &ft_toupper, &free);
	assert(mapped_lst == NULL);
	// Test case for a list with multiple elements
	node1 = ft_lstnew(strdup("abc"));
	node2 = ft_lstnew(strdup("def"));
	node3 = ft_lstnew(strdup("ghi"));
	node1->next = node2;
	node2->next = node3;
	mapped_lst = ft_lstmap(node1, &ft_toupper, &free);
	assert(mapped_lst != NULL);
	assert(strcmp(mapped_lst->content, "ABC") == 0);
	assert(strcmp(mapped_lst->next->content, "DEF") == 0);
	assert(strcmp(mapped_lst->next->next->content, "GHI") == 0);
	assert(mapped_lst->next->next->next == NULL);
	// Free the memory
	ft_lstclear(&node1, &free);
	ft_lstclear(&mapped_lst, &free);
}

void	test_ft_lstlast(void)
{
	t_list	*lst;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	// Test case for empty list
	lst = NULL;
	assert(ft_lstlast(lst) == NULL);
	// Test case for a list with multiple elements
	node1 = ft_lstnew("node1");
	node2 = ft_lstnew("node2");
	node3 = ft_lstnew("node3");
	node1->next = node2;
	node2->next = node3;
	assert(ft_lstlast(node1) == node3);
	// Free the memory
	free(node1);
	free(node2);
	free(node3);
}

void	test_ft_lstiter(void)
{
	t_list	*lst;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	// Test case for empty list
	lst = NULL;
	ft_lstiter(lst, &ft_toupper);
	// Test case for a list with multiple elements
	node1 = ft_lstnew(strdup("abc"));
	node2 = ft_lstnew(strdup("def"));
	node3 = ft_lstnew(strdup("ghi"));
	node1->next = node2;
	node2->next = node3;
	ft_lstiter(node1, &ft_toupper);
	assert(strcmp(node1->content, "ABC") == 0);
	assert(strcmp(node2->content, "DEF") == 0);
	assert(strcmp(node3->content, "GHI") == 0);
	// Free the memory
	ft_lstclear(&node1, &free);
}

void	test_ft_lstdelone(void)
{
	t_list	*node;

	// Test case for deleting a single node
	node = ft_lstnew(strdup("node"));
	ft_lstdelone(node, &free);
	// No assertion needed as the node is deleted
}

void	test_ft_lstclear(void)
{
	t_list	*lst;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	// Test case for empty list
	lst = NULL;
	ft_lstclear(&lst, &free);
	assert(lst == NULL);
	// Test case for a list with multiple elements
	node1 = ft_lstnew(strdup("node1"));
	node2 = ft_lstnew(strdup("node2"));
	node3 = ft_lstnew(strdup("node3"));
	node1->next = node2;
	node2->next = node3;
	ft_lstclear(&node1, &free);
	assert(node1 == NULL);
}

void	test_ft_lstadd_front(void)
{
	t_list	*lst;
	t_list	*new_node;
	t_list	*node1;

	// Test case for adding to an empty list
	lst = NULL;
	new_node = ft_lstnew("new node");
	ft_lstadd_front(&lst, new_node);
	assert(lst == new_node);
	assert(lst->next == NULL);
	// Test case for adding to a non-empty list
	node1 = ft_lstnew("node1");
	ft_lstadd_front(&lst, node1);
	assert(lst == node1);
	assert(lst->next == new_node);
	assert(lst->next->next == NULL);
	// Free the memory
	free(node1);
	free(new_node);
}

void	test_ft_lstadd_back(void)
{
	t_list	*lst;
	t_list	*new_node;
	t_list	*node1;

	// Test case for adding to an empty list
	lst = NULL;
	new_node = ft_lstnew("new node");
	ft_lstadd_back(&lst, new_node);
	assert(lst == new_node);
	assert(lst->next == NULL);
	// Test case for adding to a non-empty list
	node1 = ft_lstnew("node1");
	ft_lstadd_back(&lst, node1);
	assert(lst == new_node);
	assert(lst->next == node1);
	assert(lst->next->next == NULL);
	// Free the memory
	free(new_node);
	free(node1);
}

/*
	ft_mem
*/
void test_ft_bzero() {
    char str1[10] = "Hello";
    char str2[10] = "Hello";

    ft_bzero(str1, 3);
    bzero(str2, 3);

    assert(memcmp(str1, str2, 10) == 0);
}

void test_ft_calloc() {
    int *ptr1 = (int *)ft_calloc(5, sizeof(int));
    int *ptr2 = (int *)calloc(5, sizeof(int));

    assert(memcmp(ptr1, ptr2, 5 * sizeof(int)) == 0);

    free(ptr1);
    free(ptr2);
}

void test_ft_memchr() {
    char str[] = "Hello, world!";

    assert(ft_memchr(str, 'o', strlen(str)) == memchr(str, 'o', strlen(str)));
    assert(ft_memchr(str, 'x', strlen(str)) == memchr(str, 'x', strlen(str)));
}

void test_ft_memcmp() {
    char str1[] = "Hello";
    char str2[] = "Hello";
    char str3[] = "World";

    assert(ft_memcmp(str1, str2, strlen(str1)) == memcmp(str1, str2, strlen(str1)));
    assert(ft_memcmp(str1, str3, strlen(str1)) == memcmp(str1, str3, strlen(str1)));
}

void test_ft_memcpy() {
    char str1[10] = "Hello";
    char str2[10] = "World";

    ft_memcpy(str1, str2, 5);
    assert(memcmp(str1, str2, 5) == 0);
}

void test_ft_memmove() {
    char str1[10] = "Hello";
    char str2[10] = "World";

    ft_memmove(str1, str2, 5);
    assert(memcmp(str1, str2, 5) == 0);

    char str3[10] = "Hello";
    ft_memmove(str3 + 2, str3, 5);
    assert(memcmp(str3, "HeHello", 7) == 0);
}

void test_ft_memset() {
    char str1[10] = "Hello";
    char str2[10] = "Hello";

    ft_memset(str1, 'x', 3);
    memset(str2, 'x', 3);

    assert(memcmp(str1, str2, 10) == 0);
}

/*
	ft_put
*/
void test_ft_putchar_fd() {
    int fd = open("test_putchar.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    ft_putchar_fd('A', fd);
    close(fd);

    char buffer[2];
    fd = open("test_putchar.txt", O_RDONLY);
    read(fd, buffer, 1);
    close(fd);
    buffer[1] = '\0';

    assert(strcmp(buffer, "A") == 0);
    remove("test_putchar.txt");
}

void test_ft_putendl_fd() {
    int fd = open("test_putendl.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    ft_putendl_fd("Hello, world!", fd);
    close(fd);

    char buffer[15];
    fd = open("test_putendl.txt", O_RDONLY);
    read(fd, buffer, 14);
    close(fd);
    buffer[14] = '\0';

    assert(strcmp(buffer, "Hello, world!\n") == 0);
    remove("test_putendl.txt");
}

void test_ft_putnbr_fd() {
    int fd = open("test_putnbr.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    ft_putnbr_fd(42, fd);
    ft_putnbr_fd(-2147483648, fd);
    ft_putnbr_fd(0, fd);
    close(fd);

    char buffer[20];
    fd = open("test_putnbr.txt", O_RDONLY);
    read(fd, buffer, 19);
    close(fd);
    buffer[19] = '\0';

    assert(strcmp(buffer, "42-21474836480") == 0);
    remove("test_putnbr.txt");
}

void test_ft_putstr_fd() {
    int fd = open("test_putstr.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    ft_putstr_fd("Hello, world!", fd);
    close(fd);

    char buffer[15];
    fd = open("test_putstr.txt", O_RDONLY);
    read(fd, buffer, 13);
    close(fd);
    buffer[13] = '\0';

    assert(strcmp(buffer, "Hello, world!") == 0);
    remove("test_putstr.txt");
}

void test_ft_toupper() {
    assert(ft_toupper('a') == 'A');
    assert(ft_toupper('z') == 'Z');
    assert(ft_toupper('A') == 'A');
    assert(ft_toupper('Z') == 'Z');
    assert(ft_toupper('5') == '5');
    assert(ft_toupper('@') == '@');
}

void test_ft_tolower() {
    assert(ft_tolower('A') == 'a');
    assert(ft_tolower('Z') == 'z');
    assert(ft_tolower('a') == 'a');
    assert(ft_tolower('z') == 'z');
    assert(ft_tolower('5') == '5');
    assert(ft_tolower('@') == '@');
}

void test_ft_substr() {
    char *str = "Hello, world!";
    char *sub1 = ft_substr(str, 0, 5);
    assert(strcmp(sub1, "Hello") == 0);
    free(sub1);

    char *sub2 = ft_substr(str, 7, 5);
    assert(strcmp(sub2, "world") == 0);
    free(sub2);

    char *sub3 = ft_substr(str, 20, 5);
    assert(strcmp(sub3, "") == 0);
    free(sub3);
}

void test_ft_strrchr() {
    char *str = "Hello, world!";
    assert(ft_strrchr(str, 'o') == strrchr(str, 'o'));
    assert(ft_strrchr(str, 'x') == strrchr(str, 'x'));
    assert(ft_strrchr(str, '\0') == strrchr(str, '\0'));
}

void test_ft_strnstr() {
    char *str = "Hello, world!";
    assert(ft_strnstr(str, "world", strlen(str)) == strnstr(str, "world", strlen(str)));
    assert(ft_strnstr(str, "world", 5) == strnstr(str, "world", 5));
    assert(ft_strnstr(str, "", strlen(str)) == strnstr(str, "", strlen(str)));
    assert(ft_strnstr(str, "world!", strlen(str)) == strnstr(str, "world!", strlen(str)));
}

void test_ft_strncmp() {
    assert(ft_strncmp("Hello", "Hello", 5) == strncmp("Hello", "Hello", 5));
    assert(ft_strncmp("Hello", "Hello, world!", 5) == strncmp("Hello", "Hello, world!", 5));
    assert(ft_strncmp("Hello", "Hello, world!", 10) == strncmp("Hello", "Hello, world!", 10));
}

void test_ft_strmapi() {
    char *str = "hello";
    char *mapped = ft_strmapi(str, &toupper);
    assert(strcmp(mapped, "HELLO") == 0);
    free(mapped);
}

void test_ft_strlen() {
    assert(ft_strlen("") == strlen(""));
    assert(ft_strlen("Hello") == strlen("Hello"));
    assert(ft_strlen("Hello, world!") == strlen("Hello, world!"));
}

void test_ft_strlcpy() {
    char dst1[10];
    char dst2[10];
    assert(ft_strlcpy(dst1, "Hello", sizeof(dst1)) == strlcpy(dst2, "Hello", sizeof(dst2)));
    assert(strcmp(dst1, dst2) == 0);

    assert(ft_strlcpy(dst1, "Hello, world!", 5) == strlcpy(dst2, "Hello, world!", 5));
    assert(strcmp(dst1, dst2) == 0);
}

void test_ft_strlcat() {
    char dst1[20] = "Hello";
    char dst2[20] = "Hello";
    assert(ft_strlcat(dst1, ", world!", sizeof(dst1)) == strlcat(dst2, ", world!", sizeof(dst2)));
    assert(strcmp(dst1, dst2) == 0);

    char dst3[5] = "Hello";
    char dst4[5] = "Hello";
    assert(ft_strlcat(dst3, ", world!", sizeof(dst3)) == strlcat(dst4, ", world!", sizeof(dst4)));
    assert(strcmp(dst3, dst4) == 0);
}

void test_ft_strjoin() {
    char *s1 = "Hello";
    char *s2 = ", world!";
    char *joined = ft_strjoin(s1, s2);
    assert(strcmp(joined, "Hello, world!") == 0);
    free(joined);
}

void test_ft_strdup() {
    char *str = "Hello, world!";
    char *dup = ft_strdup(str);
    assert(strcmp(dup, str) == 0);
    free(dup);
}

void test_ft_strchr() {
    char *str = "Hello, world!";
    assert(ft_strchr(str, 'o') == strchr(str, 'o'));
    assert(ft_strchr(str, 'x') == strchr(str, 'x'));
    assert(ft_strchr(str, '\0') == strchr(str, '\0'));
}

void test_ft_strtrim() {
    // Test case 1: Trim characters from the beginning
    char *s1 = "  hello world";
    char *set1 = " ";
    char *trimmed1 = ft_strtrim(s1, set1);
    assert(strcmp(trimmed1, "hello world") == 0);
    free(trimmed1);

    // Test case 2: Trim characters from the end
    char *s2 = "hello world  ";
    char *set2 = " ";
    char *trimmed2 = ft_strtrim(s2, set2);
    assert(strcmp(trimmed2, "hello world") == 0);
    free(trimmed2);

    // Test case 3: Trim characters from both ends
    char *s3 = "  hello world  ";
    char *set3 = " ";
    char *trimmed3 = ft_strtrim(s3, set3);
    assert(strcmp(trimmed3, "hello world") == 0);
    free(trimmed3);

    // Test case 4: Trim multiple characters
    char *s4 = "abchello worldabc";
    char *set4 = "abc";
    char *trimmed4 = ft_strtrim(s4, set4);
    assert(strcmp(trimmed4, "hello world") == 0);
    free(trimmed4);

    // Test case 5: No trimming needed
    char *s5 = "hello world";
    char *set5 = "abc";
    char *trimmed5 = ft_strtrim(s5, set5);
    assert(strcmp(trimmed5, "hello world") == 0);
    free(trimmed5);

    // Test case 6: Empty string
    char *s6 = "";
    char *set6 = "abc";
    char *trimmed6 = ft_strtrim(s6, set6);
    assert(strcmp(trimmed6, "") == 0);
    free(trimmed6);

    // Test case 7: Trim all characters
    char *s7 = "abcabc";
    char *set7 = "abc";
    char *trimmed7 = ft_strtrim(s7, set7);
    assert(strcmp(trimmed7, "") == 0);
    free(trimmed7);

    // Test case 8: NULL input string
    char *s8 = NULL;
    char *set8 = "abc";
    char *trimmed8 = ft_strtrim(s8, set8);
    assert(trimmed8 == NULL);

    // Test case 9: NULL set string
    char *s9 = "hello world";
    char *set9 = NULL;
    char *trimmed9 = ft_strtrim(s9, set9);
    assert(trimmed9 == NULL);
}

void test_ft_split() {
    // Test case 1: Split a string with a single delimiter
    char *s1 = "hello world";
    char c1 = ' ';
    char **result1 = ft_split(s1, c1);
    assert(result1 != NULL);
    assert(strcmp(result1[0], "hello") == 0);
    assert(strcmp(result1[1], "world") == 0);
    assert(result1[2] == NULL);
    free_strs(result1, 2);

    // Test case 2: Split a string with multiple delimiters
    char *s2 = "  hello   world  ";
    char c2 = ' ';
    char **result2 = ft_split(s2, c2);
    assert(result2 != NULL);
    assert(strcmp(result2[0], "hello") == 0);
    assert(strcmp(result2[1], "world") == 0);
    assert(result2[2] == NULL);
    free_strs(result2, 2);

    // Test case 3: Split a string with a delimiter at the beginning
    char *s3 = "  hello world";
    char c3 = ' ';
    char **result3 = ft_split(s3, c3);
    assert(result3 != NULL);
    assert(strcmp(result3[0], "hello") == 0);
    assert(strcmp(result3[1], "world") == 0);
    assert(result3[2] == NULL);
    free_strs(result3, 2);

    // Test case 4: Split a string with a delimiter at the end
    char *s4 = "hello world  ";
    char c4 = ' ';
    char **result4 = ft_split(s4, c4);
    assert(result4 != NULL);
    assert(strcmp(result4[0], "hello") == 0);
    assert(strcmp(result4[1], "world") == 0);
    assert(result4[2] == NULL);
    free_strs(result4, 2);

    // Test case 5: Split a string with no delimiters
    char *s5 = "helloworld";
    char c5 = ' ';
    char **result5 = ft_split(s5, c5);
    assert(result5 != NULL);
    assert(strcmp(result5[0], "helloworld") == 0);
    assert(result5[1] == NULL);
    free_strs(result5, 1);

    // Test case 6: Split an empty string
    char *s6 = "";
    char c6 = ' ';
    char **result6 = ft_split(s6, c6);
    assert(result6 != NULL);
    assert(result6[0] == NULL);
    free_strs(result6, 0);

    // Test case 7: Split a string with only delimiters
    char *s7 = "   ";
    char c7 = ' ';
    char **result7 = ft_split(s7, c7);
    assert(result7 != NULL);
    assert(result7[0] == NULL);
    free_strs(result7, 0);
}

void test_ft_atoi() {
    // Test case 1: Positive number
    char *str1 = "42";
    assert(ft_atoi(str1) == atoi(str1));

    // Test case 2: Negative number
    char *str2 = "-42";
    assert(ft_atoi(str2) == atoi(str2));

    // Test case 3: Zero
    char *str3 = "0";
    assert(ft_atoi(str3) == atoi(str3));

    // Test case 4: Positive number with leading whitespace
    char *str4 = "   +42";
    assert(ft_atoi(str4) == atoi(str4));

    // Test case 5: Negative number with leading whitespace
    char *str5 = "\t\n-42";
    assert(ft_atoi(str5) == atoi(str5));

    // Test case 6: Number with leading non-digit characters
    char *str6 = "abc123";
    assert(ft_atoi(str6) == atoi(str6));

    // Test case 7: Number with trailing non-digit characters
    char *str7 = "123abc";
    assert(ft_atoi(str7) == atoi(str7));

    // Test case 8: Empty string
    char *str8 = "";
    assert(ft_atoi(str8) == atoi(str8));

    // Test case 9: String with only whitespace
    char *str9 = "   \t\n";
    assert(ft_atoi(str9) == atoi(str9));

    // Test case 10: Large positive number
    char *str10 = "2147483647";
    assert(ft_atoi(str10) == atoi(str10));

    // Test case 11: Large negative number
    char *str11 = "-2147483648";
    assert(ft_atoi(str11) == atoi(str11));

    // Test case 12: Number with leading plus sign
    char *str12 = "+42";
    assert(ft_atoi(str12) == atoi(str12));

    // Test case 13: Number with leading minus sign followed by whitespace
    char *str13 = "-   42";
    assert(ft_atoi(str13) == atoi(str13));
}


int	main(void)
{
	// ft_is functions
	test_ft_isalpha();
	test_ft_isascii();
	test_ft_isdigit();
	test_ft_isprint();
	test_ft_isalnum();
	printf("[ft_is] All tests passed!\n");

	// ft_lst functions
	test_ft_lstsize();
	test_ft_lstnew();
	test_ft_lstmap();
	test_ft_lstlast();
	test_ft_lstiter();
	test_ft_lstdelone();
	test_ft_lstclear();
	test_ft_lstadd_front();
	test_ft_lstadd_back();
	printf("[ft_lst] All tests passed!\n");

	// ft_mem functions
	test_ft_bzero();
  test_ft_calloc();
  test_ft_memchr();
  test_ft_memcmp();
  test_ft_memcpy();
  test_ft_memmove();
  test_ft_memset();
  printf("[ft_mem] All tests passed!\n");

	// ft_put functions
	test_ft_putchar_fd();
  test_ft_putendl_fd();
  test_ft_putnbr_fd();
  test_ft_putstr_fd();
  printf("[ft_put]All tests passed!\n");

	// ft_str
	test_ft_toupper();
  test_ft_tolower();
  test_ft_substr();
  test_ft_strrchr();
  test_ft_strnstr();
  test_ft_strncmp();
  test_ft_strmapi();
  test_ft_strlen();
  test_ft_strlcpy();
  test_ft_strlcat();
  test_ft_strjoin();
  test_ft_striteri();
  test_ft_strdup();
  test_ft_strchr();
	printf("[ft_str] All tests passed!\n");

	test_ft_strtrim();
  printf("[ft_strtrim] All ft_strtrim tests passed!\n");

	test_ft_split();
  printf("[ft_split] All ft_split tests passed!\n");

	test_ft_atoi();
  printf("[ft_atoi] All ft_atoi tests passed!\n");

	test_ft_itoa();
  printf("[ft_itoa] All ft_itoa tests passed!\n");

	return (0);
}
