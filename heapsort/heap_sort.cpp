#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

void heapify(int ord[], int tamanho, int i)
{
    int maior = i;
    int esqFilho = 2*i + 1;
    int dirFilho = 2*i + 2;
    int aux;

    if (esqFilho < tamanho && ord[esqFilho] > ord[maior])
        maior = esqFilho;

    if (dirFilho < tamanho && ord[dirFilho] > ord[maior])
        maior = dirFilho;

    if (maior != i)
    {
        aux = ord[i];
        ord[i] = ord[maior];
        ord[maior] = aux;
        heapify(ord, tamanho, maior);
    }
}

void heap_sort(int ord[], int tamanho)
{
    for (int i = tamanho / 2 - 1; i >= 0; i--){
        heapify(ord, tamanho, i);
    }

    int aux;
    for (int i=tamanho-1; i>=0; i--)
    {
        aux = ord[0];
        ord[0] = ord[i];
        ord[i] = aux;
        heapify(ord, i, 0);
    }
}

void print(int *num, int tamanho ){
      for (int i = 0; i < tamanho; i++)
      {
           cout << num[i] << "\t";
      }
      cout << endl;
 }

int main()
{
    int ord[100000];
    string file;
    cout << "Digite o nome do arquivo a ser ordenado: ";
    cin >> file;
    ifstream in(file);
    char numero[10];
    int tamanho = 0;
    while(!in.eof()){

        in >> numero;
        ord[tamanho] = atoi(numero);
        tamanho++;
    }

    heap_sort(ord, tamanho-1);

    print(ord, tamanho-1);
}
