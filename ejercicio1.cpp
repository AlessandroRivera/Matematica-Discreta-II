#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Prototipos de funciones
int contarProductosPositivos(const int *numeros, int n_total, int n_repeticiones);
int contarProductosNulos(const int *numeros, int n_total, int n_repeticiones);

int main()
{
    srand(time(NULL)); // Inicializacion de la funcion para generar numeros aleatorios

    int n_positivos = 6; // Numero de elementos positivos en el conjunto
    int n_negativos = 8; // Numero de elementos negativos en el conjunto
    int n_total = n_positivos + n_negativos; // Numero total de elementos en el conjunto
    const int n_repeticiones = 100000; // Numero de repeticiones para realizar el conteo
    int opcion;

    do
    {
        // Menu de opciones
        cout << "\n ----------------------- MENU -----------------------" << endl;
        cout << "\n 1. Literal a)" << endl;
        cout << "\n 2. Literal b)" << endl;
        cout << "\n 3. Salir" << endl;
        cout << "\n Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            int contador_positivos = 0;
            // Bucle para realizar el conteo de productos positivos
            for (int j = 0; j < n_repeticiones; j++)
            {
                int numeros[n_total]; // Arreglo para almacenar los numeros aleatorios
                // Generacion de numeros aleatorios positivos y negativos en el conjunto
                for (int i = 0; i < n_total; i++)
                {
                    numeros[i] = (i < n_positivos) ? rand() % n_total + 1 : -(rand() % n_total + 1);
                }
                // Llamada a la funcion para contar productos positivos
                contador_positivos += contarProductosPositivos(numeros, n_total, 1);
            }

            // Mostrar resultados
            cout << "\n El total de elementos con producto positivo son: " << contador_positivos << endl;
            cout << "\n La probabilidad empírica es: " << (double)contador_positivos / n_repeticiones << endl;
            break;
        }

        case 2:
        {
            int contador_nulos = 0;
            // Bucle para realizar el conteo de productos nulos
            for (int j = 0; j < n_repeticiones; j++)
            {
                int numeros[n_total]; // Arreglo para almacenar los numeros aleatorios
                // Generación de numeros aleatorios con características para productos nulos
                for (int i = 0; i < n_positivos; i++)
                {
                    numeros[i] = (i == n_positivos - 1) ? 0 : rand() % (n_positivos - 1) + 1;
                }
                // Generacion de numeros aleatorios negativos en el conjunto
                for (int i = n_positivos; i < n_total; i++)
                {
                    numeros[i] = -(rand() % n_total + 1);
                }
                // Llamada a la función para contar productos nulos
                contador_nulos += contarProductosNulos(numeros, n_total, 1);
            }
            // Mostrar resultados
            cout << "\n El total de elementos con producto nulo son: " << contador_nulos << endl;
            cout << "\n La probabilidad empírica es: " << (double)contador_nulos / n_repeticiones << endl;
            break;
        }

        case 3:
            cout << "\n Saliendo del programa." << endl;
            break;

        default:
            cout << "\n Opción no válida. Por favor, elija nuevamente." << endl;
            break;
        }
    } while (opcion != 3);

    return 0;
}

// Funcion para contar la cantidad de veces que el producto de 4 números aleatorios es positivo
int contarProductosPositivos(const int *numeros, int n_total, int n_repeticiones)
{
    int contador_positivos = 0;

    // Bucle para verificar productos positivos
    for (int i = 0; i < n_repeticiones; i++)
    {
        int a = numeros[rand() % n_total];
        int b = numeros[rand() % n_total];
        int c = numeros[rand() % n_total];
        int d = numeros[rand() % n_total];

        int producto = a * b * c * d;

        if (producto > 0)
        {
            contador_positivos++;
        }
    }

    return contador_positivos;
}

// Funcion para contar la cantidad de veces que el producto de 4 numeros aleatorios es nulo
int contarProductosNulos(const int *numeros, int n_total, int n_repeticiones)
{
    int contador_nulos = 0;

    // Bucle para verificar productos nulos
    for (int i = 0; i < n_repeticiones; i++)
    {
        int a = numeros[rand() % n_total];
        int b = numeros[rand() % n_total];
        int c = numeros[rand() % n_total];
        int d = numeros[rand() % n_total];

        int producto = a * b * c * d;

        if (producto == 0)
        {
            contador_nulos++;
        }
    }

    return contador_nulos;
}
