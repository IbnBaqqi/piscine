#include <stdlib.h>
#include <stdio.h>

char *ft_strdup(char *src);

int main()
{
	char *dup;
	char str[] = "Abdul";
	dup = ft_strdup(str);
	printf("Duplicated string: %s", dup);
}

char *ft_strdup(char *src)
{
	int i;
	char *dup;

	i = 0;
	while(src[i] != '\0'){
	i++;
	}

	dup = (char *)malloc(i + 1);

	if(dup == NULL)
		return NULL;

	i = 0;
	while(src[i] != '\0'){
	dup[i] = src[i];
	i++;
	}
	dup[i] = '\0';

	return dup;
}
