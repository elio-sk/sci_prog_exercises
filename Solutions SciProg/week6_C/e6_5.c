#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int checkOccurrence(char* string, char character) {
    int k = 0,i;
    character = tolower(character); 
    for (i = 0; i < strlen(string); i++) {
        if (string[i] == character || string[i] == character - 32){
            k++;
        }
    }
    return k;
 }


 int main() {
    char s[50];
    char c;
    printf("Input string: ");
    scanf("%s", s);
    printf("Input character: ");
    scanf(" %c", &c);
    printf("The character %c occurs %d times in the string.", c, checkOccurrence(s, c));
    return 0;
 }
