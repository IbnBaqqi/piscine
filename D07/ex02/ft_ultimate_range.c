*ptr = (int *)malloc(sizeof(int))#include <stdio.h>
#include <stdlib.h>

int ft_ultimate_range(int **range, int min, int max);

int main()
{
	int i;
	int min = 5;
	int max = 22;
	int *range;
	int size;
	size = ft_ultimate_range(&range, min, max);

	if(size == 0){
		printf("Error or empty strings");
	}else{

	for(i = 0; i < size; i++){
		printf("%d ", range[i]);
	}
	}
	return 0;
}

int ft_ultimate_range(int **range, int min, int max)
{
	int size;
	int i;

	if(min >= max){
		*range = NULL;
		return 0;
	}
	
	size = max - min;

	*range = (int *)malloc(sizeof(int) * size);

	if(*range == NULL)
	return 0;
	
	i = 0;
	while(i < size){
		(*range)[i] = min + i;
		i++;
	}
	return size;
}
