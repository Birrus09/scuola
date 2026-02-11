#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <ctime>

using namespace std;

int main() {
    int Maxn, Minn, N, range;
    clock_t inizio = clock()
    string nomefile;

    cout << " inserisci minimo, massimo e numeri da generare (max 8192): ";
    cin >> Minn;
    cin >> Maxn;
    cin >> N;
    range = Maxn-Minn;
    cout << "inserisci il nome del file su cui scrivere: ";
    cin >> nomefile;


    ofstream outfile(nomefile + ".txt"); 
    for(int i = 0; i <N; i++){
        outfile << rand() % range + Minn << endl;
    }
    cout << "impiegato " << (inizio-clock())/(CLOCKS_PER_SEC*1000.0)
    outfile.close();
}
