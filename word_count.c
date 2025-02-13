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

    char read;

    int w_count = 0;
    int s_count = 0;
    int c_count = 0;

    int control = 0;

    while ((read = fgetc(srcfile)) != EOF){
        c_count++;
        
        while (!(isspace(read) || read=='\n')){
            if (!control){
                control = 1;
                w_count++;
            }   
            read = fgetc(srcfile);
            c_count++;

        } 
        control = 0;
        if (read =='\n') s_count++;

    }
    
    fclose(srcfile);
    printf("Chars: %i\n", c_count);
    printf("Words: %i\n", w_count);
    printf("Lines: %i\n", s_count);

    /*    
    read = fgetc(srcfile);
    while ((read) != '\n'){
            while (!(isspace(read) || read=='\n')){
                if (!control){
                    control = 1;
                    i++;
                }   
                read = fgetc(srcfile);
            }
            control = 0;    
            read = fgetc(srcfile);         
            printf("inf"); 
        }
        fclose(srcfile);
        printf("%i", i);
    */

}