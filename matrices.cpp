/******************************************************************************\
 * Curso de Programación 1. Tema 9
 * Autores: Simona Bernardi y Miguel Ángel Latre
 * Última revisión: 11 de noviembre de 2020
 * Resumen: Soluciones a los problemas planteados en la clase de problemas
 *          del tema 9 sobre matrices.
\******************************************************************************/
#include <iostream>
#include <iomanip>

using namespace std;

/*
 * Dimensión máxima de las matrices con las que se va a trabajar.
 */
const unsigned DIM = 10;

/*
 * Anchura mínima de cada componente de una matriz cuando se escribe en la
 * pantalla.
 */
const unsigned ANCHO = 4;


/*
 * Pre:  La matriz «mat» tiene unas dimensiones máximas de DIM × DIM.
 * Post: Se ha solicitado al usuario y el número de filas «nf» y de columnas 
 *       «nf» y se ha leído del teclado hasta que 0 < nf ≤ DIM y 0 < nc ≤ DIM.
 *       A continuación, se ha solicitado la introducción por el teclado de
 *       nf x nc datos enteros y se han copiado en las primeras nf x nc
 *       componentes de «mat», de menor a mayor índice.
 */
void leerMatriz(int mat[][DIM], unsigned& nf, unsigned& nc) {
    do {
        cout << "Introduzca el número de filas y columnas (>0): ";
        cin >> nf >> nc;
    } while (nf <= 0 || nc <= 0 || nf > DIM || nc > DIM);
    
    for (unsigned i = 0; i < nf; i++){
        cout << "Fila " << i + 1 << ": Introduzca " << nc << " enteros: ";
        for(unsigned j = 0;  j < nc; j++){
            cin >> mat[i][j];
        }
    }
}


/*
 * Pre:  La matriz «mat» de dimensiones máximas DIM × DIM tiene las primeras 
 *       «nf» × «nc» componentes inicializadas, con 0 < nf ≤ DIM y 0 < nc ≤ DIM.
 * Post: Ha escrito los valores de las «nf» × «nc» primeras componentes de la
 *       matriz «mat» desde la de menor índice a la de mayor.
 */
void escribirMatriz(const int mat[][DIM],
                    const unsigned nf, const unsigned nc) {
    for (unsigned i = 0; i < nf; i++){
        for (unsigned j = 0; j < nc; j++){
            cout << setw(ANCHO) << mat[i][j];
        }
        cout << endl;
    }
}


/* 
 * Pre:  La matriz «mat» es una matriz de dimensiones máximas DIM × DIM
 *       y «nf» y «nc» están comprendidos entre 1 y DIM (inclusive).
 * Post: Ha escrito la transpuesta de la matriz «mat» en la pantalla.
 */
void escribirTraspuesta(const int mat[][DIM],
                        const unsigned nf, const unsigned nc){
    for (unsigned j = 0; j < nc; j++){
        for(unsigned i = 0; i < nf; i++){
            cout << setw(ANCHO) << mat[i][j];
        }
        cout << endl;
    }
}


/*
 * Pre:  La matriz «mat» es una matriz de dimensiones máximas DIM × DIM y
 *       0 < n ≤ DIM.
 * Post: Ha devuelto el valor «true» si y solo si «mat» es simétrica.
 */
bool esSimetrica(const int mat[][DIM], const unsigned n){
    bool deMomentoEsSimetrica = true;
    unsigned i = 0;
    while (deMomentoEsSimetrica && i < n) {
        unsigned j = i + 1;
        while( deMomentoEsSimetrica && j < n) {
            if( mat[i][j] != mat[j][i]) {
                deMomentoEsSimetrica = false;            
            }
            j++;
        }
        i++;
    } 
    return deMomentoEsSimetrica;
}


/*
 * Pre:  Las matrices «A», «B» y «C» son cuadradas de DIM × DIM y «nfa», «nca», 
 *       «nfb» y «ncb» están comprendidos entre 1 y DIM (inclusive).
 *	     Se cumplen las condiciones para la multiplicación de las dos matrices
 *       «A» y «B»: nca = nfb.
 * Post: La matriz «C» es la matriz producto de la multiplicación A × B.
 */
void multiplicar(const int A[][DIM], const int B[][DIM],
         const unsigned nfa, const unsigned nca, const unsigned ncb,
         int C[][DIM]) {
    for (unsigned i = 0; i < nfa; i++) {
        for (unsigned k = 0; k < ncb; k++) {
            int suma=0;
            for (unsigned j = 0; j < nca; j++){
                suma += A[i][j] * B[j][k];
            }
            C[i][k] = suma;
        }
    }
}


/*
 * Programa que solicita al usuario que introduzca los datos de una matriz «M»
 * (tanto las dimensiones entre 1 y DIM como valores de todas sus componentes) 
 * y escribe en la pantalla la matriz traspuesta de «M». Si «M» es cuadrada y es
 * simétrica, escribe un mensaje en la pantalla indicándolo.
 * 
 * A continuación, solicita al usuario que introduzca los datos dos matrices «a» y
 * «b» (también tanto las dimensiones entre 1 y DIM como los valores de sus 
 * componentes). Comprueba si se puede calcular el producto de las dos matrices: en
 * caso afirmativo, calcula la matriz producto y la escribe en la pantalla. En
 * caso negativo avisa al usuario con un mensaje.
 */

int main() {
    // Paso 1: pedir al usuario una matriz M de dimensión n x m y escribir la matriz traspuesta
    cout << "TRASPUESTA DE UNA MATRIZ:" << endl;
    cout << endl;
    
    int M[DIM][DIM];
    unsigned n, m;
    leerMatriz(M,n,m);

    cout << "La matriz traspuesta es:" << endl;
    escribirTraspuesta(M,n,m);
    
    // Paso 2: verificar si la matriz es cuadrada y es simétrica y escribir el mensaje correspondiente
    if (n == m) {
        cout << "La matriz ";
        if (esSimetrica(M, n)) {
        }
        else {
            cout << "no ";
        }
        cout << "es simétrica" << endl;
    }

    // Paso 3: pedir al usuario dos matrices A (dimensión: nfa x nca) y B (dimensión: nfb x ncb)
    cout << endl;
    cout << endl;
    cout << "MULTIPLICACIÓN DE DOS MATRICES:" << endl;
    cout << endl;
    
    int A[DIM][DIM];
    unsigned nfa, nca;
    leerMatriz(A, nfa, nca);
    cout << endl;

    int B[DIM][DIM];
    unsigned nfb, ncb;
    leerMatriz(B, nfb, ncb);
    cout << endl;

    // Paso 4: controlar si se puede calcular el producto: 
    // 		   en caso positivo, escribir la matriz producto
    // 		   en caso negativo, avisar al usuario con un mensaje
    
    if (nca == nfb){
        int C[DIM][DIM];
        multiplicar(A, B, nfa, nca, ncb, C);
        cout << "El producto es:" << endl;
        escribirMatriz(C, nfa, ncb);
    }
    else{
        cout << "No se puede calcular el producto A x B:" << endl;
        cout << "el n.º de columnas de A no es igual al n.º de filas de B."
             << endl;
    }
    
    return 0;
}
