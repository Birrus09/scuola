
#include <iostream>
#include <fstream>
#include <string>
#define MAXN 256


using namespace std;


int menu(){
    int opt = 0;
    cout << "0) save&quit, 1) aggiungi squadra, 2) visualizza classifica, 3) visualizza tabellone, 4) scrivi su file, 5) leggi file, 6) %vittorie di una squadra" << endl;
    cin >> opt;
    return opt;
}

struct squadra{
    string nome;
    int vinte;
    int perse;
    int nulle;
    int goal_f;
    int goal_s;
};



void CreaSquadra(squadra destinazione[], string nome, int vinte, int perse, int nulle, int goal_f, int goal_s, int &N){
    squadra sq;
    sq.nome = nome;
    sq.vinte = vinte;
    sq.perse = perse;
    sq.nulle = nulle;
    sq.goal_f = goal_f;
    sq.goal_s = goal_s;
    destinazione[N++] = sq;
}
/*
void Sort(squadra vettore[], int N){
    for (int i = 0; i<N; i++){
        (vettore[i].vinte * 3 + vettore[i].nulle)
    }
}
*/







int main(){

    int opt, vintet, perset, nullet, goalft, goalst, N = 0;
    squadra torneo[MAXN];
    string nomet, filename = "default.txt";
    

    do {
        opt = menu();

        if(opt==1){
            cout << "inserisci nome (_ e non spazio), vinte, perse, nulle, goal fatti e subiti" << endl;
            cin >> nomet >> vintet >> perset >> nullet >> goalft >> goalst;
            CreaSquadra(torneo, nomet, vintet, perset, nullet, goalft, goalst, N);
        }
        if (opt == 2){
            //Sort(torneo, N);
            for (int i = 0; i<N; i++){
                cout << torneo[i].nome << ": " << (torneo[i].vinte * 3 + torneo[i].nulle) << " punti" << endl;
            }
        }
        if(opt==3){

            cout << "nome\t\tvinte\tperse\tnulle\tg_fat\tg_sub" << endl;

            for (int i = 0; i<N; i++){
                cout << torneo[i].nome << "\t\t" << torneo[i].vinte << "\t" << torneo[i].perse << "\t" << torneo[i].nulle << "\t" << torneo[i].goal_f << "\t" << torneo[i].goal_s << endl;
            }

        }
        if(opt==4){
            cout << "inserisci nome file: ";
            cin >> filename;
            ofstream outfile(filename);
            for (int i = 0; i<N; i++){
                outfile << torneo[i].nome << " " << torneo[i].vinte << " " << torneo[i].perse << " " << torneo[i].nulle << " " << torneo[i].goal_f << " " << torneo[i].goal_s << endl;
            }
            outfile.close();
        }
        if(opt==5){
            cout << "inserisci nome file" << endl;
            cin >> filename;
            ifstream filein(filename);
            while(filein >> nomet >> vintet >> perset >> nullet >> goalft >> goalst){
                CreaSquadra(torneo, nomet, vintet, perset, nullet, goalft, goalst, N);
            }
            filein.close();
        }
        if (opt == 6){
            cout << "inserisci nome squadra" << endl;
            cin >> nomet;
            for (int i = 0; i<N; i++){
                if (torneo[i].nome == nomet){
                    if(torneo[i].vinte + torneo[i].perse + torneo[i].nulle == 0){
                        cout << "la squadra non ha giocato nessuna partita" << endl;
                        continue;
                    }
                    cout << torneo[i].nome << " ha vinto il " << torneo[i].vinte / (torneo[i].vinte + torneo[i].perse + torneo[i].nulle) << "% delle partite giocate" << endl;
                } 
            }
        }
        



    } while (opt!=0);

}
