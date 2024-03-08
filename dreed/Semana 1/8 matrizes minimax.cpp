/*
Questão 8: Matrizes - Minimax
Na teoria de sistemas define-se como elemento minimax de uma matriz o menor elemento da linha onde se encontra o maior elemento da matriz. Escreva um programa que receba uma matriz quadrada de inteiros, 10x10, e retorne seu elemento minimax, seguido de sua posição. Em caso de números iguais considere o que aparece primeiro.
Entradas:
Um matriz de inteiros de tamanho 10x10.
Saídas:
O menor elemento da linha que tem o maior elemento da matriz.
A linha e a coluna onde está o elemento do item anterior.
Exemplo de entrada:
1  2  3  4  5  6  7 8  9  0
11  4 32  5  6  8  9 2  3  1
 2  3  5  6  7  8  1 0  3  1
 1  3 45  2  6  8  9 0  2  0
 4 30  4  2  6 18  5 0  1  0
 2  3 40  2  6  8 19 0 45  9
 3  2  5  7  7  8 10 0  2  2
 1  3 22  2 13  6  9 1  1  0
 4 30  4  2  6 18  5 0  9 10
 2  3 34  2  6  8 19 0  0  0
Exemplo de saída:
0
3 7
*/

#include <iostream>
using namespace std;

int main() {
    int matriz[10][10];

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> matriz[i][j];
        }
    }

    int maior = matriz[0][0];

    // encontra a linha com o maior elemento
    int linha = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (matriz[i][j] > maior) {
                maior = matriz[i][j];
                linha = i;
            }
        }
    }

    int menor = matriz[linha][0];
    int coluna = 0;

    // encontra o menor elemento da linha com o maior elemento
    for (int j = 0; j < 10; j++) {
        if (matriz[linha][j] < menor) {
            menor = matriz[linha][j];
            coluna = j;
        }
    }

    cout << menor << endl;
    cout << linha << " " << coluna << endl;
    
    return 0;
}
