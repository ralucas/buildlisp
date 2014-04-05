#include <stdio.h>
#include <stdlib.h>

// If we are compiling on Windows
#ifdef _WIN32

#include <string.h>

static char buffer[2048];

// Fake readline function
char* readline(char* prompt) {
    fputs("lispy> ", stdout);
    fgets(buffer, 2048, stdin);
    char* cpy = malloc(stlen(buffer)+1);
    strcpy(cpy, buffer);
    cpy[stlen(cpy)-1] = '\0';
    return cpy;
}

// Fake add_history function
void add_history(char* unused){}

// Otherwise include the editline headers
#else

#include <editline/readline.h>
#include <histedit.h>

#endif

int main(int argc, char** argv) {
    // Print version and exit info
    puts("Lispy Version 0.0.1");
    puts("Press Ctrl+c to Exit\n");

    while (1) {
        
        // Output promt
        //fputs("lispy>", stdout);
        // Read a line of user input, max 2048
        //fgets(input, 12, stdin);

        // Output prompt
        char* input = readline("lispy> ");

        // Add input to history
        add_history(input);

        // Echo input back to user
        printf("You input %s\n", input);

        // Free retrieved input
        free(input);
    }

    return 0;
}