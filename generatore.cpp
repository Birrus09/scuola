#include <iostream>
#include <fstream>
#include <random>

using namespace std;
int main() {
    ofstream out("output.txt");
    int N = 256;
    float arr[N];
    for (int i = 0; i < N; i++){
        arr[i] = rand() / (float)RAND_MAX;
        out << arr[i] << endl;
    }
    out.close();
    return 0;
}


