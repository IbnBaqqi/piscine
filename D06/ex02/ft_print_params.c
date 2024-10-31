#include <unistd.h>

int ft_putchar(char c);
void ft_putstr(char *str);

int main(int argc, char *argv[])
{
	if(argc > 1)
	{
		int i = 1;
	
		while(i < argc)
		{
			ft_putstr(argv[i++]);
			ft_putchar('\n');
		}
	}
	return 0;
}
