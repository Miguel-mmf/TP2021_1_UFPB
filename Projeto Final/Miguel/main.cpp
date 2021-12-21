#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cstring>

// a proposta é dividir em arquivos de apoio para facilitar manutenção
// #include "Linha.h"
// #include "TpProjetoFinal.h"

using namespace std;


//###########################################################
//                  CLASSE LINHA
//###########################################################

class Linha
{
    public:
        vector<float> contents;
        string data_med, hora_med;

        Linha(char *linha);

        void setDatetime(string data_hora);

        string getData();

        string getHora();

        vector<float> getContents();
};

Linha::Linha(char *linha){
    int count = 0;
    while(true){

        if (count == 0){
            setDatetime(string(linha));
        }
        else{
            linha = strtok(NULL,",");
            if(linha == NULL) break;
            contents.push_back(stof(linha));
        }
        count++;
    }
    // cout << "Quantidade de dados: " << contents.size() << endl;
}


void Linha::setDatetime(string data_hora){
    data_med = data_hora.substr(0,10);
    hora_med = data_hora.substr(11);
}


string Linha::getData(){ return data_med;};


string Linha::getHora(){ return hora_med;};


vector<float> Linha::getContents(){ return contents;};


//###########################################################
//                  CLASSE TpProjetoFinal
//###########################################################

class TpProjetoFinal
{
    public:
        vector<string> colunas;
        vector<Linha> dados;
        vector<string> data_hora;

        TpProjetoFinal(string filename);

        void getContents(string filename);

        void getNRegistros(int num_registro);
        
        void getRegistrosPorT(string tempo);

        vector<string> getColunas();

        vector<Linha> getDados();
};


TpProjetoFinal::TpProjetoFinal(string filename){
    getContents(filename);
};


vector<string> TpProjetoFinal::getColunas(){return colunas;};


vector<Linha> TpProjetoFinal::getDados(){return dados;};


void TpProjetoFinal::getContents(string filename){

    char *col;
    string row;

    ifstream Entrada;
    Entrada.open(filename);

    if (!Entrada) cout << "O arquivo nao pode ser aberto!";

    // pega as colunas do arquivo .csv e salva no container colunas do
    getline(Entrada,row);
    col = strtok(&row[0],",");
    while(col != NULL){
        colunas.push_back(col);
        col = strtok(NULL,",");
    }

    // pega cada linha do arquivo .csv, transforma num objeto Linha e armazenda dentro do container dados
    while(!Entrada.eof()){
        getline(Entrada,row);

        if (row.length() > 0){
            col = strtok(&row[0],",");

            Linha L(col);
            dados.push_back(L);
        }
    }

    Entrada.close();
};


void TpProjetoFinal::getNRegistros(int num_registro){

    vector<string>::iterator col;
    vector<Linha>::iterator dado;

    int *registros = new int(num_registro);

    for(dado = dados.begin(); num_registro > 0; dado++){

        cout << "\nRegistro " << (*registros-num_registro) << endl;

        cout <<  left << setw(70) << "\nDia da Medicao: " << dado->getData() << endl;
        cout << left << setw(70) << "Horario da medicao: " << dado->getHora() << endl;

        int posicao = 0;
        for(col = (colunas.begin()+1); col < colunas.end(); col++,posicao++)
            cout << left << setw(70) << *col << ": " << dado->getContents().at(posicao) << endl;
        
        num_registro--;
    }

    delete registros;
};


void TpProjetoFinal::getRegistrosPorT(string tempo){

    vector<string>::iterator col;
    vector<Linha>::iterator dado;


    for(dado = dados.begin(); dado < dados.end(); dado++){

        if (dado->getHora() == tempo){

            cout <<  left << setw(70) << "\nDia da Medicao: " << dado->getData() << endl;
            cout << left << setw(70) << "Horario da medicao: " << dado->getHora() << endl;

            int posicao = 0;
            for(col = (colunas.begin()+1); col < colunas.end(); col++,posicao++)
                cout << left << setw(70) << *col << ": " << dado->getContents().at(posicao) << endl;
        }
    }
};


//###########################################################
//                  FUNCAO MAIN
//###########################################################


int main()
{
    TpProjetoFinal teste("../D140193-2021-03-20.csv");

    // mostra colunas do objeto teste da classe TpProjetoFinal
    // for(int i = 0; i < teste.getColunas().size(); i++){
    //     cout << teste.getColunas().at(i) << endl;
    // }

    // valores da primeira linha do arquivo csv
    // auto L = teste.getDados().at(1);
    // cout << L.getData() << " " << L.getHora() << endl;
    // cout << "Quantidade de dados: " << L.getContents().size() << endl;
    // for(int i = 0; i < L.getContents().size(); i++)
    //     cout << L.getContents().at(i) << " - ";

    // N primeiros registros
    // teste.getNRegistros(4);

    //Imprima na tela os dados do arquivo especificado pelo usuário em um determinado tempo t dado pelo usuário no formato HH:MM:SS
    teste.getRegistrosPorT("01:40:00");


    return 0;
}