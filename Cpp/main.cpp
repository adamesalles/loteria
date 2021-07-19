#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <set>
 
using namespace std;

set<int> cria_jogo(int numeros){
    set<int> jogo; 
    while (jogo.size() < numeros){
        int r =  rand() % 60 + 1;
        jogo.insert(r);
    }
    return jogo;
}

void print_set(set<int> st){
    set<int, greater<int> >::iterator itr;
    for (itr = st.begin(); itr != st.end(); itr++)
    {
        cout << *itr<<" ";
    }
}

bool aposta(set<int> sorteio, int numeros){
    set<int> jogo_principal = cria_jogo(numeros);
    if (includes(jogo_principal.begin(), jogo_principal.end(),
                  sorteio.begin(), sorteio.end())){
        return true;
    } else {
        return false;
    }
}

int main(){
    time_t init_time = time(NULL);
    srand(init_time);
    set<int> sorteio = cria_jogo(6);
    int tentativas = 0;
    bool ganhou = false;
    while (ganhou == false){
        tentativas++;
        ganhou = aposta(sorteio,6);
        cout << tentativas << endl;
    }
    cout << "O jogo era: " << endl;
    print_set(sorteio);
    cout << endl;
    time_t end_time = time(NULL);
    cout << "E levou " << double(end_time - init_time) << " segundos." << endl;
    cout << tentativas << " tentativas" << endl;
}


