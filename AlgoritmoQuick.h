
typedef struct produto Produto;

typedef struct quick Quick;

Quick* create(int);

void quickSort(Quick*, int, int);

int add(Quick*, int, float);

void imprimir(Quick*);
