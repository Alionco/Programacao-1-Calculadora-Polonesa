#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "tad_pilha.h"

int main() {

	tad_pilha p;
	inicializa_pilha(&p);

	char entrada[10];
	fgets(entrada, 10, stdin);

	double f, operando1, operando2, resultado, fim;
	int i, eh_numero;

	while(1) {

		eh_numero = 0;
		for(i=0;i<=9;i++){
			if(isdigit(entrada[i])){
				eh_numero = 1;
			}
		}


		if(eh_numero){
			f = atof(entrada);
			empilha(f, &p);
		} else {
		
			switch(entrada[0]) {
				case '+':
					if(pilha_vazia(&p)){
						printf("erro - pilha vazia");
						return 1;
					} else {
						desempilha(&operando2, &p);
					}
					if(pilha_vazia(&p)){
						printf("erro - pilha vazia");
						return 1;
					} else {
						desempilha(&operando1, &p);
					}
					resultado = operando1 + operando2;
					empilha(resultado, &p);
					printf("%f\n", resultado);
					break;

				case '-':
					if(pilha_vazia(&p)){
						printf("erro - pilha vazia");
						return 1;
					} else {
						desempilha(&operando2, &p);
					}
					if(pilha_vazia(&p)){
						printf("erro - pilha vazia");
						return 1;
					} else {
						desempilha(&operando1, &p);
					}
					resultado = operando1 - operando2;
					empilha(resultado, &p);
					printf("%f\n", resultado);

					break;

				case '*':
					if(pilha_vazia(&p)){
						printf("erro - pilha vazia");
						return 1;
					} else {
						desempilha(&operando2, &p);
					}
					if(pilha_vazia(&p)){
						printf("erro - pilha vazia");
						return 1;
					} else {
						desempilha(&operando1, &p);
					}
					resultado = operando1 * operando2;
					empilha(resultado, &p);
					printf("%f\n", resultado);

					break;

				case '/':
					if(pilha_vazia(&p)){
						printf("erro - pilha vazia");
						return 1;
					} else {
						desempilha(&operando2, &p);
					}
					if(pilha_vazia(&p)){
						printf("erro - pilha vazia");
						return 1;
					} else {
						desempilha(&operando1, &p);
					}
					resultado = operando1 / operando2;
					empilha(resultado, &p);
					printf("%f\n", resultado);

					break;
				
				case 'q':
					topo(&fim, &p);
					printf("%f\n", fim);
					return 1;
					break;
			}
		}
		fgets(entrada, 10, stdin);
	}
	return 1;
}