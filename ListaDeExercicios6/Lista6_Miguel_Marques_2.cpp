#include <iostream>
#include <cstdlib>

using namespace std;

class Globo
{
    int n1,n2,n3,n4,n5,n6;

    public:
        Globo(){
            n1,n2,n3,n4,n5,n6 = -1,-1,-1,-1,-1,-1;
        }
        void gera_num_sorteados()
        {
            n1 = rand()%60;
            n2 = rand()%60;
            n3 = rand()%60;
            n4 = rand()%60;
            n5 = rand()%60;
            n6 = rand()%60;
        }
        // int getN1(){return n1;}
        // int getN2(){return n2;}
        // int getN3(){return n3;}
        // int getN4(){return n4;}
        // int getN5(){return n5;}
        // int getN6(){return n6;}
        
        void sorteio(int rodadas)
        {
            int rodada=1;
            while(rodadas!=0){
                gera_num_sorteados();
                cout << "Rodada " << rodada << ": ";
                cout << "[" << n1 << " - " << n2 << " - " << n3 << " - " << n4 << " - " << n5 << " - " << n6 << "]" << endl;;
                rodadas-=1;
                rodada+=1;
            }
        }
};


int main()
{
    bool sair = false;
    int rodadas,rodada=0;

    Globo G;

    while(!sair){
        //Globo G;

        cout << "Quantas rodadas devem ser executadas: ";
        cin >> rodadas;

        G.sorteio(rodadas);

        cout << "\nDeseja inserir sortear novamente (1- sim, 2- nao): ";
        cin >> sair;
        if(sair == true){sair = false;} else{break;};
    }

    return 0;
}