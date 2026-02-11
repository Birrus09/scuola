#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <cmath>
#define Maxv 8192
#include <ctime>

using namespace std;

int FindMin(int V[],int AmpVec){
    int index = 0;
    int temp = 99999999;
    for (int i = 0; i<AmpVec; i++){
        if (V[i] < temp){
            index = i;
            temp = V[i];
        }
    }
    return V[index];
}

int FindMax(int V[],int AmpVec){
    int index = 0;
    int temp = -99999999;
    for (int i = 0; i<AmpVec; i++){
        if (V[i] > temp){
            index = i;
            temp = V[i];
        }
    }
    return V[index];
}

float mediavettore(int V[], int AmpVec){
    int somma = 0;
    for (int i=0; i<AmpVec; i++){    
        somma += V[i];    
    }

    return (float)somma/AmpVec;
}

float devstandard(int V[], int AmpVec){
    float media = mediavettore(V, AmpVec);
    float somma = 0.0;
    for (int i = 0; i < AmpVec; i++) {
        somma += pow((V[i] - media),2);
    }
    return sqrt(somma / AmpVec);
}

int main() {
    int choice;
    float Maxn, Minn, media, Num;
    int opera[Maxv];
    string nomefile;
    clock_t inizio;
  
    cout << "inserisci il nome del file da cui analizzare: ";
    cin >> nomefile;

    ifstream infile(nomefile + ".txt"); 

    int lunghezza = -1;
    string linea;
    int i = 0;
    while (getline(infile, linea)) {
        opera[i] = stoi(linea);
        i++;
        lunghezza++;
    }
    infile.close();


    do {
        cout << endl;
        cout << "\t--Menu--\n";
        cout << " 1 - minimo\n";
        cout << " 2 - massimo\n";
        cout << " 3 - media\n";
        cout << " 4 - deviazione standard\n";
        cout << " 5 - quit\n";
        cin >> choice;

        switch(choice){
            case (1):
                inizio = clock()
                cout << FindMin(opera, lunghezza) << "impiegato " << (inizio-clock())/(CLOCKS_PER_SEC/1000.0);
                break;
            case (2):
                inizio = clock()
                cout << FindMax(opera, lunghezza) << "impiegato " << (inizio-clock())/(CLOCKS_PER_SEC/1000.0);
                break;
            case (3):
                inizio = clock()
                cout << mediavettore(opera, lunghezza) << "impiegato " << (inizio-clock())/(CLOCKS_PER_SEC/1000.0);
                break;
            case (4):
                inizio = clock()
                cout << devstandard(opera, lunghezza) << "impiegato " << (inizio-clock())/(CLOCKS_PER_SEC/1000.0);
                break;
        }


        
    } while (choice != 5);

    infile.close();
    
}
