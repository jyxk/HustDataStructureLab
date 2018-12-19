#include <stdio.h>
#include <string.h>

int main(void) {

    char buffer[300] = {0};

    for (int i = 0;(buffer[i] = getchar()) != EOF; i++)
        ;

    printf("printf(\"");
    
    for (int i = 0; i < strlen(buffer)-1; i++) {
        if (buffer[i] == '\n')
            printf("\\n");
        else    
            printf("%c", buffer[i]);
    }
    printf("\");");

    return 0;
}