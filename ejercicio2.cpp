#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    const int n = 100000; // Numero de articulos a simular
    int defectuosos = 0, t1_def = 0, t2_def = 0, t3_def = 0;

    for (int i = 0; i < n; ++i) {
        // Generar un numero aleatorio para determinar el turno
        int turno = rand() % 100 + 1; // Genera un numero entre 1 y 100

        // Determinar si el articulo es defectuoso
        bool es_defectuoso = false;
        if (turno <= 40) { // 40% turno T1
            es_defectuoso = (rand() % 100) < 1; // 1% de defectuosos en T1
            t1_def += es_defectuoso ? 1 : 0;
        } else if (turno <= 75) { // 35% turno T2
            es_defectuoso = (rand() % 100) < 2; // 2% de defectuosos en T2
            t2_def += es_defectuoso ? 1 : 0;
        } else { // 25% turno T3
            es_defectuoso = (rand() % 100) < 3; // 3% de defectuosos en T3
            t3_def += es_defectuoso ? 1 : 0;
        }

        // Contar los articulos defectuosos
        defectuosos += es_defectuoso ? 1 : 0;
    }

    // Calcular probabilidades empiricas
    double prob_defectuoso_empirica = static_cast<double>(defectuosos) / n;
    double prob_t2_defectuoso_empirica = static_cast<double>(t2_def) / defectuosos;
    double prob_t3_defectuoso_empirica = static_cast<double>(t3_def) / defectuosos;

    // Mostrar resultados
    cout << "\n ------------------------------------ Resultados ------------------------------------" << endl;
    cout << "\n Probabilidad empirica de ser defectuoso: " << prob_defectuoso_empirica << endl;
    cout << "\n Probabilidad empirica de ser del turno T2 dado que es defectuoso: " << prob_t2_defectuoso_empirica << endl;
    cout << "\n Probabilidad empirica de ser del turno T3 dado que es defectuoso: " << prob_t3_defectuoso_empirica << endl << endl;

    return 0;
}
