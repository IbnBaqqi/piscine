#include <unistd.h>

int ft_putchar(char c);
void ft_putstr(char *str);
int ft_strcmp(char *s1, char *s2);
void ft_swapstr(char **a, char **b);
void ft_sort_args(int argc, char *argv[]);

int main(int argc, char *argv[])
{
	if(argc > 1)
	{
		ft_sort_args(argc, argv);
		int i = 1;
		while(i < argc)
		{
			ft_putstr(argv[i]);
			ft_putchar('\n');
			i++;
		}
	}
	return 0;
}

void ft_sort_args(int argc, char *argv[])
{
	int i = 1;
	while(i < argc - 1)
	{
		int j = i + 1;
		while(j < argc)
			{
				if(ft_strcmp(argv[i], argv[j])>0) {
				ft_swapstr(&argv[i], &argv[j]);
				}
			j++;
		}
	i++;
	}
}
