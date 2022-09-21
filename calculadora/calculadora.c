#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXN 4

float do_soma(float a, float b) {return a + b;}
float do_sub(float a, float b) {return a - b;}
float do_mul(float a, float b) {return a * b;}
float do_div(float a, float b) {return a / b;}

// declare o método que recebe which e retorna uma das funções abaixo ... 
{
    if (strlen(which) != 1) return NULL;
    
    switch(which[0]) {
    case '+':
        return do_soma;
    case '-':
        return do_sub;
    case '/':
        return do_div;
    case '*':
        return do_mul;
    }
    
    return NULL;
}

int main(int argc, char *argv[]) {
    float numeros[MAXN];
    int   npos = 0;

    for(int i = 1; i < argc; i ++) {
        // curr_op = .... 

        if (curr_op != NULL) {
            if (npos < 2) {
                fprintf(stderr, "Preciso pelo menos dois números no stack para operar\n");
                break;
            }
            numeros[npos-2] = curr_op(numeros[npos-2], numeros[npos-1]);
            npos--;

            continue;
        }

        if (npos >= MAXN) {
            fprintf(stderr, "Atingiu o máximo do stack!\n");
            break;
        }
        numeros[npos++] = atof(argv[i]);
    }
    
    if (npos > 1) {
        fprintf(stderr, "Sobrou mais de um elemento no stack!\n");
        return 1;
    }
        
    fprintf(stdout, "resultado = %f\n",numeros[0]);
    
    return 0;
}
