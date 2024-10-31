#include <stdio.h>
#include <stdlib.h>

int *ft_range(int min, int max);

int main()
{
	int i;
	int min = 7;
	int max = 20;
	int size = max - min;
	int *range = ft_range(min, max);

	if(range != NULL){
	i= 0;
	while(i < size){
		printf("%d", range[i++]);
		printf("\n");
	}
	free(range);
}
	return 0;
}

int *ft_range(int min, int max)
{
	int i;
	int rangesize = max - min;
	int *range;
	if(min >= max)
		return NULL;

	range = (int *)malloc(rangesize * sizeof(int));
	
	if(range == NULL)
		return NULL;
	i = 0;
	while(min < max){
	range[i] = min++;
	i++;
	}
	return range;
}
