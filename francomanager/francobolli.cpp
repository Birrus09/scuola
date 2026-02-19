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

int menu(){
    int opt = 0;
    cout << "0) quit, 1) crea francobollo, 2) visualizza francobolli, 3) leggi da file, 4) scrivi su file" << endl;

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

string encryptDecrypt(const string &data, const string &key) {
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
    int opt = 0;
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

        // Modifica nella sezione di lettura da file
        if (opt == 3){
            cout << "inserisci nome file" << endl;
            cin >> nomefile;
            ifstream filein(nomefile);

            cout << "questi sono i tuoi francobolli? inserisci la password!" << endl;
            cin >> password;
            password = encryptDecrypt(password, secretkey);

            filein >> check;

            if (check == password){
                while(!filein.eof()){
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
                cout << "al ladro!" << endl;
            }
            
        }

        // Modifica nella sezione di scrittura su file
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
    } while (opt!=0);


	return 0;
}
