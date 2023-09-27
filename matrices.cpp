/******************************************************************************\
 * Curso de Programación 1. Tema 9
 * Autores: Simona Bernardi y Miguel Ángel Latre
 * Última revisión: 9 de noviembre de 2022
 * Resumen: Soluciones a los problemas planteados en la clase de problemas
 *          del tema 9 sobre matrices.
 * Nota: El programa completo está contenido en este fichero, por lo que puede 
 *       compilarse y ejecutarse con la extensión Code Runner de Visual Studio
 *       Code.
 *       También puede compilarse desde la terminal través de la orden
 *           g++ -Wall -Wextra matrices.cpp -o matrices
 *       y ejecutarse en Windows a través de la orden
 *           .\matrices.exe
 *       o en Linux y macOS
 *           ./matrices
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
 * Post: Solicita al usuario el número de filas «nf» y de columnas «nc» y los
 *       lee del teclado hasta que 0 < nf ≤ DIM y 0 < nc ≤ DIM. A continuación,
 *       solicita la introducción por el teclado de nf × nc datos enteros y los
 *       copia en las primeras nf × nc componentes de «mat», de menor a mayor
 *       índice.
 */
void leerMatriz(int mat[][DIM], unsigned& nf, unsigned& nc) {
    // Petición de las dimensiones hasta que 0 < nf ≤ DIM y 0 < nc ≤ DIM
    do {
        cout << "Introduzca el número de filas y columnas (>0): ";
        cin >> nf >> nc;
    } while (nf <= 0 || nc <= 0 || nf > DIM || nc > DIM);
    
    // Lectura de los datos de la matriz:
    for (unsigned i = 0; i < nf; i++){
        // Para cada una de las filas «i», con «i» entre 0 y «nf» - 1,
        // se piden los datos de esa fila:
        cout << "Fila " << i + 1 << ": Introduzca " << nc << " enteros: ";
        for(unsigned j = 0;  j < nc; j++){
            // Y se leen los datos de cada columna «j», con «j» entre 0 y «nc» - 1,
            // de la fila «i».
            cin >> mat[i][j];
        }
    }
}


/*
 * Pre:  La matriz «mat» de dimensiones máximas DIM × DIM tiene las primeras 
 *       «nf» × «nc» componentes inicializadas, con 0 < nf ≤ DIM y 0 < nc ≤ DIM.
 * Post: Escribe los valores de las «nf» × «nc» primeras componentes de la
 *       matriz «mat» desde la de menor índice a la de mayor.
 */
void escribirMatriz(const int mat[][DIM],
                    const unsigned nf, const unsigned nc) {
    for (unsigned i = 0; i < nf; i++){
        // Para cada una de las filas «i», con «i» entre 0 y «nf» - 1, ...
        for (unsigned j = 0; j < nc; j++){
            // ... Se escriben los datos de cada columna «j», con «j» entre 0 y
            // «nc» - 1, de la fila «i» ...
            cout << setw(ANCHO) << mat[i][j];
        }
        // ... y, tras escribir todos los datos de la fila «i», terminamos la línea.
        cout << endl;
    }
}


/* 
 * Pre:  La matriz «mat» es una matriz de dimensiones máximas DIM × DIM
 *       y «nf» y «nc» están comprendidos entre 1 y DIM (inclusive).
 * Post: Escribe la transpuesta de la matriz «mat» en la pantalla.
 */
void escribirTraspuesta(const int mat[][DIM],
                        const unsigned nf, const unsigned nc) {
    // En lugar de recorrer la matriz por filas y, dentro de cada fila, por columnas,
    // lo hacemos al revés: primero por columnas y luego por filas. De este modo, lo
    // que se escribe en la pantalla es la traspuesta dela matriz «mat».
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
 * Post: Devuelve el valor «true» si y solo si «mat» es simétrica.
 */
bool esSimetrica(const int mat[][DIM], const unsigned n) {
    // Planteamiento como un problema de búsqueda de un par de componentes (i, j)
    // tales que mat[i][j] ≠ m[j][i]. Si se encuentra alguno, NO es simétrica.
    // Si no se encuentra ninguno, es simétrica.

    // La variable «deMomentoEsSimetrica» va a valer «true» mientras no se haya
    // encontrado un par de componentes (i, j) tales que mat[i][j] ≠ m[j][i].
    bool deMomentoEsSimetrica = true;

    // Recorrido de la matriz «mat» por filas mientras no se haya encontrado un
    // par de componentes (i, j) tales que mat[i][j] ≠ m[j][i] y mientras el
    // índice «i» es menor que la dimensión «n»:
    unsigned i = 0;
    while (deMomentoEsSimetrica && i < n) {
        // Recorrido de las componentes por encima de la diagonal principal por
        // columnas mientras no se haya encontrado un par de componentes (i, j)
        // tales que mat[i][j] ≠ m[j][i] y mientras el índice «j» sea menor que
        // la dimensión «n»:
        unsigned j = i + 1;
        while (deMomentoEsSimetrica && j < n) {
            // Si mat[i][j] ≠ m[j][i], sabemos con certeza que la matriz NO es
            // simétrica:
            if (mat[i][j] != mat[j][i]) {
                deMomentoEsSimetrica = false;            
            }
            j++;
        }
        i++;
    } 
    // Se sale de los bucles por una de estas dos causas:
    //  - Se ha encontrado par de componentes (i, j) tales que mat[i][j] ≠ m[j][i].
    //    En este caso, la matriz no es simétrica y «deMomentoEsSimetrica» tiene
    //    que valer «false».
    //  - Se han recorrido todas las filas y columnas y no sin encontrar ningún
    //    par de componentes (i, j) tales que mat[i][j] ≠ m[j][i]. En este caso, 
    //    la matriz es simétrica y «deMomentoEsSimetrica» tiene que valer «true».
    return deMomentoEsSimetrica;
}


/*
 * Pre:  Las matrices «A», «B» y «C» son cuadradas de DIM × DIM
 *       y «nfa», «nca» y «ncb» están comprendidos entre 0 y DIM (inclusive).
 *       «nfa» representa el número de filas de «A»;
 *       «nca», el número de columnas de «A» y el número de filas de «B»;
 *       «ncb», el número de columnas de «B»;
 *	     Como «nca» representa el número de columnas de «A» y el número de filas de
 *       «B», se cumplen las condiciones para la multiplicación de las dos matrices
 *       «A» y «B»: el número de columnas de «A» es igual al número de filas de «B».
 * Post: La matriz «C» es la matriz producto de la multiplicación A × B.
 */
void multiplicar(const int A[][DIM], const int B[][DIM],
         const unsigned nfa, const unsigned nca, const unsigned ncb,
         int C[][DIM]) {            
    // Para cada una de las filas «i», con «i» entre 0 y «nfa» - 1, de la matriz «C» ...
    for (unsigned i = 0; i < nfa; i++) {
        // Para cada una de las filas «k», con «k» entre 0 y «ncb» - 1, de la matriz «C» ...
        for (unsigned k = 0; k < ncb; k++) {
            // Se calcula el valor de la componente C[i][k] de la matriz producto
            // aplicando la definición del producto de matrices: cᵢₖ = ∑ aᵢⱼ·bⱼₖ
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
 * A continuación, solicita al usuario que introduzca los datos dos matrices «a»
 * y «b» (también tanto las dimensiones entre 1 y DIM como los valores de sus 
 * componentes). Comprueba si se puede calcular el producto de las dos matrices:
 * en caso afirmativo, calcula la matriz producto y la escribe en la pantalla.
 * En caso negativo avisa al usuario con un mensaje.
 */
int main() {
    // Paso 1: pedir al usuario una matriz M de dimensión n × m
    //         y escribir su matriz traspuesta
    cout << "TRASPUESTA DE UNA MATRIZ:" << endl;
    cout << endl;
    
    int M[DIM][DIM];
    unsigned n, m;
    leerMatriz(M, n, m);

    cout << "La matriz traspuesta es:" << endl;
    escribirTraspuesta(M, n, m);
    
    // Paso 2: verificar si la matriz es cuadrada y es simétrica 
    //         y escribir el mensaje correspondiente
    if (n == m) {
        cout << "La matriz ";
        if (esSimetrica(M, n)) {
        } else {
            cout << "no ";
        }
        cout << "es simétrica" << endl;
    }

    // Paso 3: pedir al usuario dos matrices A (dimensión: nfa × nca) 
    //         y B (dimensión: nfb × ncb)
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

    // Paso 4: comprobar si se puede calcular el producto: 
    // 		   en caso positivo, escribir la matriz producto
    // 		   en caso negativo, avisar al usuario con un mensaje
    if (nca == nfb){
        int C[DIM][DIM];
        multiplicar(A, B, nfa, nca, ncb, C);
        cout << "El producto es:" << endl;
        escribirMatriz(C, nfa, ncb);
    }
    else{
        cout << "No se puede calcular el producto A × B:" << endl;
        cout << "el nº de columnas de A no es igual al nº de filas de B."
             << endl;
    }
    
    return 0;
}
