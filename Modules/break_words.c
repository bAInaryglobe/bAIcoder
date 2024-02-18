// write me c code that takes a string as argument and prints a list of all the words in that st4ing, one per line. A word is defined as a sequence of non-space characters. You may assume that the input string contains only letters and spaces

#include <stdio.h>
#include <string.h>

void break_words(char *str) {
    int i = 0;
    int j = 0;
    int len = strlen(str);
    while (i < len) {
	if (str[i] == ' ') {
	    str[i] = '\0';
	    printf("%s\n", &str[j]);
	    j = i + 1;
	}
	i++;
    }
    printf("%s\n", &str[j]);
}


// Output:

// modify th3 main function to take input ws runtime argument, e.g ./a "write me code"
//

// only provide the modified main function
//

int main(int argc, char *argv[]) {
    break_words(argv[1]);
    return 0;
}


