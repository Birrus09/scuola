#include <iostream>
#include <fstream>
using namespace std;
#define MAXF 8096

struct francobollo {
	string nome;
	string stato;
	int anno;
	float valore;
	string valuta;
};

int menu(){
    int opt = 0;
    cout << "0) quit, 1) crea francobollo, 2) visualizza francobolli, 3)leggi da file, 4)scrivi su file" << endl;

    cin >> opt;
    return opt;
}

francobollo CreaFrancobollo(string nome, string stato, int anno, float valore, string valuta){
    francobollo f;
    f.nome = nome;
    f.stato = stato;
    f.anno = anno;
    f.valore = valore;
    f.valuta = valuta;
    return f;

}


int main() {
    int N = 0;
    string nomefile;
    int opt = 0;
    string nomet, statot, valutat;
    int annot;
    float valoret;
    francobollo francobolli[MAXF];
    do {
        opt = menu();

        if (opt == 1){
            cout << "inserisci nome, stato, anno, valore e valuta" << endl;
            cin >> nomet >> statot >> annot >> valoret >> valutat;
            francobolli[N] = CreaFrancobollo(nomet, statot, annot, valoret, valutat);
            N++;

        }

        if (opt == 2){
            for(int i = 0; i<N; i++){
                cout << "francobollo " << i+1 << endl;
                cout << "nome: " << francobolli[i].nome << endl;
                cout << "stato: " << francobolli[i].stato << endl;
                cout << "anno: " << francobolli[i].anno << endl;
                cout << "valore: " << francobolli[i].valore << endl;
                cout << "valuta: " << francobolli[i].valuta << endl << endl;
                }

        }

        if (opt == 3){
            cout << "inserisci nome file" << endl;
            cin >> nomefile;
            ifstream file(nomefile);
                while(!file.eof()){
                    file >> nomet >> statot >> annot >> valoret >> valutat;
                    francobolli[N] = CreaFrancobollo(nomet, statot, annot, valoret, valutat);
                    N++;
                }
                file.close();
        }

        if (opt == 4){
            cout << "inserisci nome file" << endl; 
            cin >> nomefile;
            ofstream fileout(nomefile);
                for(int i = 0; i<N; i++){
                    fileout << francobolli[i].nome << " " << francobolli[i].stato << " " << francobolli[i].anno << " " << francobolli[i].valore << " " << francobolli[i].valuta << endl;
                }
                fileout.close();
        }
    } while (opt!=0);


	return 0;
}
