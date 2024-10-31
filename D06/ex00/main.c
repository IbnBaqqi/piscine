#include <stdio.h>

void ft_putchar(char c);
void ft_swap(int *a, int *b);
void ft_putstr(char *str);
int ft_strlen(char *str);
int ft_strcmp(char *s1, char *s2);

int main() {
    char str[] = "Hello, World!";
    ft_putstr(str);
    printf("\nLength: %d\n", ft_strlen(str));

    int a = 1, b = 2;
    ft_swap(&a, &b);
    printf("Swapped: a = %d, b = %d\n", a, b);

    printf("Comparison: %d\n", ft_strcmp("abc", "abd"));

    return 0;
}

