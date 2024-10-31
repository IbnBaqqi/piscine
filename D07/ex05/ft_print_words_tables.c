#include <unistd.h>

int ft_putchar(char c);
void ft_print_words_tables(char **tab);

int ft_putchar(char c)
{
	write(1, &c, 1);
	return 0;
}

void ft_print_words_tables(char **tab)
{
	int i;
	int j;

	i = 0;
	while(tab[i]){
		j = 0;
		while(tab[i][j]){
			ft_putchar(tab[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
