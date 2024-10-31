#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int ft_separator(char c, char *charset);
int ft_count_string(char *str, char *charset);
char *ft_copy_string(char *start, char *end);
char **ft_split(char *str, char *charset);

int ft_separator(char c, char *charset)
{
	while(*charset){
		if(c == *charset)
			return 1;
		charset++;
	}
	return 0;
}

int ft_count_string(char *str, char *charset)
{
	int count = 0;
	int in_string = 0;

	while(*str){
	if(ft_separator(*str, charset)){
		in_string = 0;
		}else{
			if(!in_string){
				count++;
				in_string = 1;
			}
		}
		
		str++;
	}
	return count;
}

char *ft_copy_string(char *start, char *end)
{
	int length = end - start;
	char *string = (char *)malloc((length + 1) * sizeof(char));
	char *dest = string;
	while(start < end){
		*dest++ = *start++;
	}
	*dest = '\0';
	return string;
}

char **ft_split(char *str, char *charset)
{
	int i;
	int count;
	char *start;
	char **words;
	
	count = ft_count_string(str,charset );
	words = (char**)malloc((count + 1) * sizeof(char *));
	i = 0;
	while(*str){
		if(!ft_separator(*str, charset)){
			start = str;

			while(*str && !ft_separator(*str, charset)){
				str++;
			}
			words[i++] = ft_copy_string(start, str);
		}else{
			str++;
		}
	}
	words[i] = 0;
	return words;
}

int main()
{
	char str[] = "Abdul, is working/on&his deen?";
	char charset[] = ",/&?";
	char **strings = ft_split(str, charset);
	char **temp = strings;

	while(*strings){
		printf("%s ", *strings);
		free(*strings);
		strings++;
	}

	free(temp);
	
	return 0;
}

