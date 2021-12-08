#include <iostream>

using namespace std;
void imprime_array(int [][8]);
void valid_barco_destruido_completo(int , int ,int [][8]);
int valid_tamanho_barco(int,int,int [6],int);
// batalha naval
    // tabuleiro de 8x8 com 5 embarcações
    // o usuário diz onde ele quer atacar e ele pode distruir o navio
    // se ele acertar na água, avisar que ele errou e avisa quantos navios próximos tem perto da embarcação
    // embarcações de tamanho diferente de 1 até 5 casas
    // 0 para agua, 1 para o barco e 2 para o barco destruido

int tabuleiro[8][8]={
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,0,0}, // navio 1
    {0,0,0,1,1,1,1,1}, // navio 5
    {0,0,0,0,0,0,0,0},
    {0,1,1,0,0,0,0,0}, // navio 2
    {0,0,0,0,0,0,0,0},
    {0,0,0,1,1,1,0,0}, // navio 3
    {0,1,1,1,1,0,0,0}, // navio 4
};

// coordendas{linha,cols}
int coordnavio1[2] = {1,5};
int coordnavio2[3] = {5,1,2};
int coordnavio3[4] = {6,3,4,5};
int coordnavio4[5] = {7,1,2,3,4};
int coordnavio5[6] = {2,3,4,5,6,7};


int main()
{
    int col=0,linha=0;
    int tentativas=30, pontos=0;
    int navio1=1, navio2=2, navio3=3, navio4=4, navio5=5;

    while(tentativas){
        cout << "\nDigite uma posicao x e y para o tabuleiro:" << endl;
        cout << "Coluna: ";
        cin >> col;
        cout << "Linha: ";
        cin >> linha;

        if(tabuleiro[linha-1][col-1]){
            pontos++;
            cout << "Tem um navio ai! Ele foi destruido!" << endl;
            tabuleiro[linha-1][col-1] = 2;

            navio1 = valid_tamanho_barco(col-1, linha-1, coordnavio1, navio1);
            navio2 = valid_tamanho_barco(col-1, linha-1, coordnavio2, navio2);
            navio3 = valid_tamanho_barco(col-1, linha-1, coordnavio3, navio3);
            navio4 = valid_tamanho_barco(col-1, linha-1, coordnavio4, navio4);
            navio5 = valid_tamanho_barco(col-1, linha-1, coordnavio5, navio5);

            cout << "Tamanho dos navios: " << navio2 << endl;
            valid_barco_destruido_completo(col-1, linha-1, tabuleiro);
        }
        imprime_array(tabuleiro);
    }

    return 0;
}


void valid_barco_destruido_completo(int col, int linha,int array[8][8]){
    int navios_proximos=0;

    if (array[linha-1+1][col-1])
        navios_proximos++;
    if (array[linha-1-1][col-1])
        navios_proximos++;
    if (array[linha-1][col-1+1])
        navios_proximos++;
    if (array[linha-1][col-1-1])
        navios_proximos++;

    cout << "O ponto destruido possui " << navios_proximos << " pedaco de navio proximo!" << endl;
}

int valid_tamanho_barco(int col, int linha, int coord_navio[5], int tamanho){
    if (linha == coord_navio[0]){
        for (int i = 0; i < tamanho; i++){
            if(col == coord_navio[i])
                tamanho--;
        }
    }
    
    return tamanho;
}


void imprime_array(int array[8][8]){

    cout << "[";

    for(int i=0; i < 8; i++){
        cout << "[";
        for(int j=0; j < 8; j++){
            cout << array[i][j];
            if (j!=7){cout << ", ";}
        }
        cout << "]";
        if (i!=7){cout << "\n";}
    }
    cout << "]";
}