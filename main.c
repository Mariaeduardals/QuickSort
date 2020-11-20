#include <stdio.h>
#include <stdlib.h>
#include "AlgoritmoQuick.h"

int main() {
	
	Quick *q = create(5);
	
	add(q, 10, 500.9);
	add(q, 99, 340.0);
	add(q, 1, 310.0);
	add(q, 12, 400.0);
	add(q, 0, 830.0);
	
	imprimir(q);
	
	printf("\nOrdenando com o algoritmo QuickSort .. \n\n");
	quickSort(q, 0, 4); 
	
	imprimir(q);
	
	
	
	return 0;
}
