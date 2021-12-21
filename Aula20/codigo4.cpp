#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

int main()
{
    vector<string> colunas;
    vector<float> dados;
    vector<string> data, hora;
    string aux1;
    char *aux;
    char aux2[1000];
    int i=0;
    // char colunas[1][100];

    ifstream entrada;
    entrada.open("D140193-2021-03-20.csv");

    if (!entrada){
        cout << "O arquivo nao pode ser aberto!";
        return 1;
    }

    getline(entrada,aux1);
    aux = strtok(&aux1[0],",");
    while(aux != NULL){

        colunas.push_back(aux);
        aux = strtok(NULL,",");
        // cout << aux << endl;
    }

    cout << "Terminou de pegar as colunas" << endl;

    for(int i = 0; i < colunas.size(); i++){
        cout << colunas.at(i) << endl;
    }

    while(!entrada.eof()){
        
        getline(entrada,aux1);
        if (aux1.length() > 0){
            cout << "\nLinha " << i << endl;
            aux = strtok(&aux1[0],",");
            data.push_back(string(aux).substr(0,10)); // o primeiro é o datetime
            while(true){

                aux = strtok(NULL,",");
                if(aux == NULL) break;
                dados.push_back(stof(aux));
                // else break;
                cout << aux << endl;
            }
            i++;
        }
    }

    // cout << "Terminou de pegar a primeira linha" << endl;

    // cout << data.front() << endl;
    // for(int i = 0; i < dados.size(); i++){
    //     cout << dados.at(i) << endl;
    // }

    // while(!entrada.eof()){
    //     getline(entrada,aux1);

    //     // cout << aux1 << endl;
    //     aux = strtok(&aux1[0],",");
    //     cout << aux << endl;
    //     while(aux != NULL){

    //         aux = strtok(NULL,",");
    //         // titulos[i] = aux;
    //         i++;
    //         cout << aux << endl;
    //     }
    // }

    // while((92 - i) >= 0){
    //     cout << titulos[(92 - i)] << endl;
    //     i--;
    // } 

    // entrada >> aux2;
    // cout << aux2 << endl;

    // como é um .csv, o separador padrão é o ;
    // int i=0, j=0, aux_ant;
    // while(i){
    //     entrada >> aux;
    //     if (aux)
    //     cout << aux << endl;
    //     i--;
    // }

    entrada.close();
    
    return 0;
}