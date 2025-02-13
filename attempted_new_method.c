#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){

    FILE *srcfile;
    if (argv[1]==NULL) {
        char temp[32];
        scanf("%s", temp);
        srcfile = fopen(temp, "r");
        }
    else {
        srcfile = fopen(argv[1], "r");
        }
    
    char line[99] ={0};        
    char most_recent[99] ={0};

    while (fgets(line, 99, srcfile) != NULL){
            char j = 0;
            while (line[j]!='\n'){ 
                j++;   
            }

            line[j+=2] = '\0';

        if (strcmp(most_recent, line)) { //condition not working!!!
            int i = 0;
            while (line[i]!='\n'){ 
                most_recent[i] = line[i];
                i++;   
            }
            most_recent[i++] = '\n';//assigns all chars in mostrecent to line's
            most_recent[i++] = '\0';//assigns all chars in mostrecent to line's
            printf("Updated line: %s\n", most_recent);
        }
    }
    fclose(srcfile);    
}

