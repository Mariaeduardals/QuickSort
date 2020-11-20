#include <stdio.h>
#include <stdlib.h>
#include "AlgoritmoQuick.h"
		
		struct produto{
			int codigo;
			float valor;
		};
		

		struct quick{
			Produto ** vetor;
			int n;
			int contador;
		};
		
			
		Produto* novoProduto(int codigo, float valor){
			
			Produto *p = (Produto*)malloc(sizeof(Produto));
			
			if(p!=NULL){
				p->codigo = codigo;
				p->valor = valor;
			}
			
			return p;
			
		}
		
		Quick* create(int n){
			 
			Quick *q = (Quick *) malloc(sizeof(Quick));
				 
			if (q != NULL) {
				q->n = n;
				q->contador = 0;
				q->vetor = (Produto**) malloc(n*sizeof(Produto));
			}
			
			return q;
		}


        void troca(Quick *v ,int i, int j){
		     Produto *temp = v->vetor[i];
		     v->vetor[i] = v->vetor[j];
		     v->vetor[j] = temp;
		  }

		int separa(Quick *v, int esquerda, int direita) {
	
		   Produto* c = v->vetor[direita]; 
		   int i , j = esquerda - 1;
		  
		   for (i = esquerda; i < direita; i++){
		      if (v->vetor[i]->codigo <= c->codigo) {
		          j = j + 1;
		          troca(v,j, i);
		         } 
		     }
		 	 troca(v,j + 1, direita);
		   	return j + 1; 
		}
		
		void quickSort(Quick *v, int esquerda, int direita){
		 
		   if (esquerda < direita) {                  
		      int j = separa (v, esquerda, direita);   
		      quickSort (v, esquerda, j - 1);     
		      quickSort (v, j + 1, direita);      
		   }
		}
 
		 int add(Quick* v, int codigo, float valor){
			
			Produto *p = novoProduto(codigo, valor);
			
			if(p != NULL && v != NULL && v->contador < v->n){
				v->vetor[v->contador] = p;
				v->contador = v->contador + 1;
				return 1; 
			}else
				return 0;
			
		}

		void imprimir(Quick* v){
			
			int i = 0;
			for(i = 0; i < v->contador; i++)
				printf("Produto [%i] = codigo: %i, valor: %.2f \n", i, v->vetor[i]->codigo,v->vetor[i]->valor);
		}

