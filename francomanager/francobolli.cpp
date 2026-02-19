#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#define MAXF 8096

struct francobollo {
	string nome;
	string stato;
	int anno;
	float valore;
	string valuta;
};


void mostra(francobollo francobolli[MAXF], int N){
    for (int i = 0; i < N; i++){
        cout << i + 1 << ") " << francobolli[i].nome << ", " << francobolli[i].stato << ", " << francobolli[i].anno << ", " << francobolli[i].valore << ", " << francobolli[i].valuta << endl;
    }
}
int menu(){
    int opt = 0;
    cout << "0) quit, 1) crea francobollo, 2) visualizza francobolli, 3) leggi da file, 4) scrivi su file, 5) modifica francobollo" << endl;

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

string encryptDecrypt(string &data, string &key) {
    string result = data;
    int keyLength = key.length();
    for (size_t i = 0; i < data.length(); ++i) {
        result[i] ^= key[i % keyLength];
    }
    return result;
}

int main() {
    int N = 0;
    string nomefile;
    int opt = 0, operatore;
    string nomet, statot, valutat;
    int annot;
    float valoret;
    francobollo francobolli[MAXF];
    string password;
    string check;
    string secretkey = "xf3r2m4d3s3rum";
    do {
        opt = menu();

        if (opt == 1){
            if (N >= MAXF) {
                cout << "hai già abbastanza francobolli" << endl;
                continue;
            }
            cout << "inserisci nome, stato, anno, valore e valuta" << endl;
            cin >> nomet >> statot >> annot >> valoret >> valutat;
            francobolli[N] = CreaFrancobollo(nomet, statot, annot, valoret, valutat);
            N++;

        }

        if (opt == 2){
            mostra(francobolli, N);
        }

        if (opt == 3){
            cout << "inserisci nome file" << endl;
            cin >> nomefile;
            ifstream filein(nomefile);

            cout << "questi sono i tuoi francobolli? inserisci la password!" << endl;
            cin >> password;
            password = encryptDecrypt(password, secretkey);

            filein >> check;

            if (check == password){
                while(filein >> nomet >> statot >> annot >> valoret >> valutat){
                    filein >> nomet >> statot >> annot >> valoret >> valutat;
                    nomet = encryptDecrypt(nomet, secretkey);
                    statot = encryptDecrypt(statot, secretkey);
                    valutat = encryptDecrypt(valutat, secretkey);
                    francobolli[N] = CreaFrancobollo(nomet, statot, annot, valoret, valutat);
                    N++;
                }

                filein.close();
            }
            else{
                cout << "ladro di francobolli!" << endl;
            }
            
        }

        if (opt == 4){
            cout << "inserisci nome file" << endl; 
            cin >> nomefile;
            ofstream fileout(nomefile);

            cout << "scegli la password." << endl;
            cin >> password;
            password = encryptDecrypt(password, secretkey);

            fileout << password << endl;
            for (int i = 0; i < N; i++) {
                fileout << encryptDecrypt(francobolli[i].nome, secretkey) << " "
                        << encryptDecrypt(francobolli[i].stato, secretkey) << " "
                        << francobolli[i].anno << " "
                        << francobolli[i].valore << " "
                        << encryptDecrypt(francobolli[i].valuta, secretkey) << endl;
            }
            fileout.close();
        }

        if (opt == 5){
            mostra(francobolli, N);
            cout << "inserisci il numero del francobollo da modificare" << endl;
            cin >> operatore;
                cout << "inserisci nome, stato, anno, valore e valuta" << endl;
            cin >> nomet >> statot >> annot >> valoret >> valutat;
            francobolli[operatore - 1] = CreaFrancobollo(nomet, statot, annot, valoret, valutat);
        }


    } while (opt!=0);


	return 0;
}
