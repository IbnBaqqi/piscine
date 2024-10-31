#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_putchar(char c);
int ft_strlen(char *str);
int ft_is_base_valid(char *base);
int ft_get_base_value(int a, char *base);
int ft_atoi_base(char *str, char *base);
char *ft_itoa_base(int nbr, char *base);
char *ft_convert_base(char *nbr, char *base_from, char *base_to);

/*int ft_putchar(char c)
{
	write(1, &c, 1);
	return 0;
}

int ft_strlen(char *str)
{
	int i = 0;
	while(str[i]){
		i++;
	}
	return i;
}*/

int ft_is_base_valid(char *base)
{
	int i;
	int j;
	int len;
	len = ft_strlen(base);
	if(len < 2)
		return 0;
	i = 0;
	j = 0;
	while(base[i]){
		if(base[i] == '+' || base[i] == '-')
			return 0;
		j = i + 1;
		while(j < len){
		if(base[i] == base[j])
			return 0;
			j++;
		}
		i++;
	}
	return 1;
}

int ft_get_base_value(int a, char *base)
{
	int i = 0;
	while(base[i]){
		if(base[i] == a)
			return i;
		i++;
	}
	return -1;
}

int ft_atoi_base(char *str, char *base)
{
	int sign = 1;
	int len = ft_strlen(base);
	int num = 0;
	int value;
	if(!str || !ft_is_base_valid(base))
		return 0;
	while(*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if(*str == '-'){
		sign = -1;
		str++;
	}
	if(*str =='+')
		str++;

	while(*str){
		value = ft_get_base_value(*str, base);
		if(num == -1)
			break;
		num = num * len + value;
		str++;
	}
	return num * sign;
}

char *ft_itoa_base(int nbr, char *base)
{
	char *result;
	int size = 0;
	int temp = nbr;
	int len = ft_strlen(base);
	if(nbr < 0)
		size = 1;
	while(temp){
		temp /= len;
		size++;
	}
	if(!ft_is_base_valid(base))
		return 0;

	result = (char*)malloc(size + 1);
		if(!result)
			return NULL;

	result[size] = '\0';

	if(nbr == 0)
		result[0] = base[0];
	if(nbr < 0){
		result[0] = '-';
		nbr = -nbr;
	}
	
	while(nbr){
		result[--size] = base[nbr % len];
		nbr /= len;
	}
	return result;
}

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	if(!ft_is_base_valid(base_from) || !ft_is_base_valid(base_to))
		return NULL;
	int dec_num = ft_atoi_base(nbr, base_from);
	char *final = ft_itoa_base(dec_num, base_to);
	return final;
}

int main()
{
	char *result = ft_convert_base("101", "01", "0123456789");
	printf("%s", result);

	free(result);
}
