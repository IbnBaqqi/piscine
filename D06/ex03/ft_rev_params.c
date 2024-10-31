#include <unistd.h>

int ft_putchar(char c);
void ft_putstr(char *str);

int main(int argc, char *argv[])
{
	int i;
	if(argc > 1)
	{
		i = argc - 1;
		while(i > 0)
		{
			ft_putstr(argv[i--]);
			ft_putchar('\n');
		}
	}
        return 0;
}
