#include <unistd.h>

int ft_putchar(char c);
int ft_strlen(char *str);
void ft_putstr(char *str);
void ft_hex_digit(int c);
void ft_print_chars(unsigned char *str,  unsigned int size);
void ft_hex_content(unsigned char *str, unsigned int size);
void ft_hex_address(unsigned int str);
void *ft_print_memory(void *addr, unsigned int size);

int main()
{
	char str[] = "Abdulbaki Salaudeen will improve on his deen and life";
	ft_print_memory(str, ft_strlen(str));
	return 0;
}

int ft_putchar(char c)
{
	write(1, &c, 1);
	return 0;
}

int ft_strlen(char *str)
{
	int strlen = 0;
	while(str[strlen] != '\0')
	{
		strlen++;
	}
	return strlen; 
} 

void ft_putstr(char *str)
{
	int i = 0;
	while(str[i] != '\0')
	{
		ft_putchar(str[i++]);
	}
}

void ft_hex_digit(int c)
{
	if(c < 10)
		ft_putchar(c + '0');
	else
		ft_putchar(c - 10 + 'a');
}

void ft_hex_address(unsigned int str)
{
	int Hex[16];
	int i = 0;
	while(i < 16)
	{
		Hex[15 - i++] = "0123456789abcdef"[str % 16];
		str /= 16;
	}

	i = 0;
	while(i < 16)
	{
		ft_putchar(Hex[i++]);
	}
	ft_putstr(": ");
}

void ft_hex_content(unsigned char *str, unsigned int size)
{
	int i = 0;
	while(i < 16)
	{
		if(i < size)
		{
			ft_hex_digit(str[i] / 16);
			ft_hex_digit(str[i] % 16);
		}
		else
			ft_putstr("   ");

		if(i % 2)
			ft_putchar(' ');
		i++;
	}	
}

void ft_print_chars(unsigned char *str, unsigned int size)
{
	int i = 0;
	while(i < size)
	{
		if(str[i] >= 32 && str[i] <= 126)
			ft_putchar(str[i]);
		else
			ft_putchar('.');
		i++;
	}
}

void *ft_print_memory(void *addr, unsigned int size)
{
	unsigned char *ptr = (unsigned char *)addr;
	unsigned int byte = 0;
	unsigned int byte_print;
	while(byte < size)
	{
		ft_hex_address((unsigned long)ptr + byte);
		if(size - byte > 16)
			byte_print = 16;
		else
			byte_print = (size - byte);

		ft_hex_content(ptr + byte, byte_print);

		ft_print_chars(ptr + byte, byte_print);
		
		ft_putchar('\n');
	
		byte += 16;
	}
	return addr;
}
