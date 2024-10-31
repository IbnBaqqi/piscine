#include <stdio.h>
#include <stdlib.h>

int ft_strlen( char *str);
char *ft_strcat(char *dest, char *str);
char *ft_concat_params(int argc, char **argv);

int main(int argc, char *argv[])
{
	char *concatparams;
	//if(argc > 1){
		concatparams = ft_concat_params(argc, argv);
		printf("Params in strings: %s", concatparams);
		free(concatparams);
	//}
	return 0;
}


int ft_strlen( char *str)
{
	int i = 0;
	while(str[i]){
		i++;
	}
	return i;
}

char *ft_strcat(char *dest, char *str)
{
	while(*dest != '\0'){
		dest++;
	}
	while(*str != '\0'){
		*dest++ = *str++;
	}
	*dest = '\0';
	return dest;
}

char *ft_concat_params(int argc, char **argv)
{
	int i;
	int j;
	char *params;
	int paramsize = 0;

	i = 0;
	while(i < argc){
		paramsize += ft_strlen(argv[i++]) + 1;
	}
	params = (char *)malloc(sizeof(char) * paramsize);

	if(params == NULL)
		return 0;

	j = 1;
	while(j < argc){
		ft_strcat(params, argv[j]);
	if(j < argc - 1)
		ft_strcat(params, "\n");
	j++;
	}
	return params;
}
