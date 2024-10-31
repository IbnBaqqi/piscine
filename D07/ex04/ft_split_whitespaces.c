#include <stdio.h>
#include <stdlib.h>

int is_whitespace(char c);
int count_words(char *str);
char *copy_words(char *start, char *end);
char **ft_split_whitespaces(char *str);
void ft_print_words_tables(char **tab);
void free_split(char **split);

int main()
{
	char str[] = "Abdul \n will be \t consistent";
	char **words = ft_split_whitespaces(str);
	//comment to compile with ft_print_words_tables.c in ex05
	/*int i = 0;
	while(words[i]){
		printf("%s, ", words[i]);
		i++;
	}*/
	ft_print_words_tables(words);
	free_split(words);
	return 0;
}

int is_whitespace(char c)
{
	return(c == ' ' || c == '\t' || c == '\n');
}

int count_words(char *str)
{
	//printf("Input string: %s\n", str);

	int count = 0;
	int in_word = 0;
	while(*str){
		if(is_whitespace(*str)){
		in_word = 0;
	}else{
		if(!in_word){
			count++;
			in_word = 1;
		}
	}
	str++;
	}

	//printf("Word count: %d\n", count);

	return count;
}

char *copy_words(char *start, char *end)
{
	int length = end - start;
	char *word = (char *)malloc((length + 1) * sizeof(char));
	char *dest = word;
	while(start < end){
		*dest++ = *start++;
	}
	*dest = '\0';
	//printf("Copied word: %s\n", word);
return word;
}

char **ft_split_whitespaces(char *str)
{
	int i = 0;
	char *start;
	char **result; 
	int words = count_words(str);

	result = (char **)malloc((words + 1) * sizeof(char *));	

	while(*str){
		if(!is_whitespace(*str)){
			start = str;
			while(*str && !is_whitespace(*str)){
				str++;
			}
			result[i] = copy_words(start, str);
			i++;
		}else{
			str++;
		}
	}
	result[i] = 0;
	/* Debug
	printf("Result array:\n");
    for (int j = 0; j < i; j++) {
        printf("%s\n", result[j]);
    }*/

	return result;
}

void free_split(char **split)
{
	int i = 0;

	while(split[i]){
		free(split[i]);
		i++;
	}
	free(split);
}
