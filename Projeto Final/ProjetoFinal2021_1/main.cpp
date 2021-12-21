#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cstring>
#include <cmath>

// a proposta é dividir em arquivos de apoio para facilitar manutenção
// #include "Linha.h"
// #include "TpProjetoFinal.h"

using namespace std;


//###########################################################
//                  CLASSE LINHA
//###########################################################

class Linha
{
        vector<float> contents;
        string data_med, hora_med;
    public:

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
        vector<string> colunas;
        vector<Linha> dados;
        vector<string> data_hora;
    public:

        TpProjetoFinal(string filename);

        void getContents(string filename);

        void percorreDados(auto *func); // está parado
        void percorreColunas(auto *func); // está parado

        void getNRegistros(int num_registro);
        
        void getRegistrosPorT(string tempo);

		void getRegistrosPorIntervalo(string tempoI, string tempoF); //Geraldo
		
		void getRegistrosPorDataType(int V); //Geraldo
		
		void getRegistrosPorDataMax(int V); //Geraldo
		
		void getRegistrosPorDataMin(int V);  //Geraldo
		
		void getRegistrosDataMed(string tempoI, string tempoF, int V); //Geraldo
		
		void getRegistrosDataDP(string tempoI, string tempoF , int V); //Geraldo

        void showDataHoraMedicao(auto p, string tempoI="", string tempoF=""); // está parado

        vector<string> getColunas();

        vector<Linha> getDados();
};

// void TpProjetoFinal::percorreDados(auto *func){

//     vector<Linha>::iterator dado;

//     for(dado = dados.begin(); dado < dados.end(); dado++){
//         (*func)();
//     }
// };

// void TpProjetoFinal::percorreColunas(auto *func){

//     vector<string>::iterator col;
//     int posicao = 0;

//     for(col = (colunas.begin()+1); col < colunas.end(); col++,posicao++){
//         (*func)();
//     }
// };


TpProjetoFinal::TpProjetoFinal(string filename){
    getContents(filename);
};


vector<string> TpProjetoFinal::getColunas(){return colunas;};


vector<Linha> TpProjetoFinal::getDados(){return dados;};


void TpProjetoFinal::showDataHoraMedicao(auto p, string tempoI, string tempoF){
    cout << left << setw(70) << "\nDia das Medicoes: " << p->getData() << endl;

    if (tempoI != "" && tempoF != "")
	    cout << left << setw(70) << "Intervalo das Medicoes: " << tempoI<< " - " << tempoF << endl;
    else
        cout << left << setw(70) << "Horario da medicao: " << p->getHora() << endl;
};


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


void TpProjetoFinal::getRegistrosPorIntervalo(string tempoI, string tempoF){ //Exibe dados em um intervalo de tempo 

    vector<string>::iterator col;
    vector<Linha>::iterator dado;


    for(dado = dados.begin(); dado < dados.end(); dado++){

        if (dado->getHora() >= tempoI && dado->getHora()<=tempoF){ //verifica se o dado está no intervalo de tempo 

            cout <<  left << setw(70) << "\nDia da Medicao: " << dado->getData() << endl;
            cout << left << setw(70) << "Horario da medicao: " << dado->getHora() << endl;

            int posicao = 0;
            for(col = (colunas.begin()+1); col < colunas.end(); col++,posicao++)
                cout << left << setw(70) << *col << ": " << dado->getContents().at(posicao) << endl;
        }
    }
};


void TpProjetoFinal::getRegistrosPorDataType(int V){ 

    vector<string>::iterator col; //aponta para os títulos das colunas
    vector<Linha>::iterator dado; //todas as linhas do csv informado


    for(dado = dados.begin(); dado < dados.end(); dado++){ //pula as linhas
		
		col = (colunas.begin()+V); //apontando para o rótulo da coluna informada
		
		cout <<  left << setw(70) << "\nDia da Medicao: " << dado->getData() << endl;
		cout << left << setw(70) << "Horario da medicao: " << dado->getHora() << endl;
		cout << left << setw(70) << *col << ": " << dado->getContents().at(V-1) << endl;
    }
	
};

void TpProjetoFinal::getRegistrosPorDataMax(int V){ 

    vector<string>::iterator col; //aponta para os títulos das colunas
    vector<Linha>::iterator dado; //todas as linhas do csv informado

	float max;
	string dMax, hMax;
	
    for(dado = dados.begin(); dado < dados.end(); dado++){ //pula as linhas
		
		if (dado==dados.begin()) //definindo valores iniciais máximos para comparação
		{
			max = dado->getContents().at(V-1);
			dMax = dado->getData();
			hMax = dado->getHora();
		}else if(dado->getContents().at(V-1) > max) //comparação para encontrar o valor máximo
		{
			max = dado->getContents().at(V-1);
			dMax = dado->getData();
			hMax = dado->getHora();
		}
	}
		col = (colunas.begin()+V); //apontando para o rótulo da coluna informada
		
		cout <<  left << setw(70) << "\nDia da Maior Medicao: " << dMax << endl;
		cout << left << setw(70) << "Horario da Maior Medicao: " << hMax << endl;
		cout << left << setw(70) << *col << ": " << max << endl;
};


void TpProjetoFinal::getRegistrosPorDataMin(int V){ 

    vector<string>::iterator col; //aponta para os títulos das colunas
    vector<Linha>::iterator dado; //todas as linhas do csv informado

	float min;
	string dMin, hMin;
	
    for(dado = dados.begin(); dado < dados.end(); dado++){ //pula as linhas
		
		if (dado==dados.begin()) //definindo valores iniciais mínimos para comparação
		{
			min = dado->getContents().at(V-1);
			dMin = dado->getData();
			hMin = dado->getHora();
		}else if(dado->getContents().at(V-1) < min) //comparação para encontrar o valor mínimo
		{
			min = dado->getContents().at(V-1);
			dMin = dado->getData();
			hMin = dado->getHora();
		}
	}
		col = (colunas.begin()+V); //apontando para o rótulo da coluna informada
		
		cout << left << setw(70) << "\nDia da Menor Medicao: " << dMin << endl;
		cout << left << setw(70) << "Horario da Menor Medicao: " << hMin << endl;
		cout << left << setw(70) << *col << ": " << min << endl;
};


void TpProjetoFinal::getRegistrosDataMed(string tempoI, string tempoF , int V){ //calcula a média no intervalo de tempo dado para uma coluna

    vector<string>::iterator col;
    vector<Linha>::iterator dado;
	
	float soma = 0, med;
	int cont = 0;

	col = (colunas.begin()+V); //apontando para o rótulo da coluna informada

    for(dado = dados.begin(); dado < dados.end(); dado++){ //pula linhas
        if (dado->getHora() >= tempoI && dado->getHora()<=tempoF){ //verifica se o dado está no intervalo de tempo 
			soma += dado->getContents().at(V-1); //somatório das medições
			cont++; //conta a quantidade de medições
        }
    }
	
	med=soma/cont; //media das medicoes
	
	// como é a msm data para um arquivo, peguei a primeira data
	cout << left << setw(70) << "\nDia das Medicoes: " << dados.at(0).getData() << endl;
	cout << left << setw(70) << "Intervalo das Medicoes: " << tempoI<< " - " << tempoF << endl;
	cout << left <<"Media das Medicoes de "<< setw(47)<< *col << ": " << med << endl;
	
};


void TpProjetoFinal::getRegistrosDataDP(string tempoI, string tempoF , int V){ //calcula a média no intervalo de tempo dado para uma coluna

    vector<string>::iterator col;
    vector<Linha>::iterator dado;
	
	float soma = 0, med, desvio = 0, dp;
	int cont = 0;

	col = (colunas.begin()+V); //apontando para o rótulo da coluna informada

    for(dado = dados.begin(); dado < dados.end(); dado++){ //pula linhas
        if (dado->getHora() >= tempoI && dado->getHora()<=tempoF){ //verifica se o dado está no intervalo de tempo 
			soma += dado->getContents().at(V-1); //somatório das medições
			cont++; //conta a quantidade de medições
        }
    }
	
	med=soma/cont; //media das medicoes
	
	for(dado = dados.begin(); dado < dados.end(); dado++){ //pula linhas
        if (dado->getHora() >= tempoI && dado->getHora()<=tempoF){ //verifica se o dado está no intervalo de tempo 
			desvio += pow((dado->getContents().at(V-1)-med),2)/(cont); //desvio
        }
    }
	
	dp = sqrt(desvio);

    // showDataHoraMedicao(dado,tempoI,tempoF);
	
    // como é a msm data para um arquivo, peguei a primeira data
	cout << left << setw(70) << "\nDia das Medicoes: " << dados.at(0).getData() << endl;
	cout << left << setw(70) << "Intervalo das Medicoes: " << tempoI<< " - " << tempoF << endl;
	cout << left <<"Desvio Padrao das Medicoes de "<<setw(40)<< *col << ": " << dp << endl;
	
};



//###########################################################
//                  FUNCAO MAIN
//###########################################################
#define F 0
#define N 1
#define t 2
#define ti 3
#define tf 4
#define V 5
#define Vmax 6
#define Vmin 7
#define Vmed 8
#define Vdesvio 9
#define V1 10
#define V2 11
#define Vcorrelacao 13


int main(int argc, char *argv[])
{
    bool options[13]={false};
    string contents[7];
    
    // faz a analise dos valores presentes em argv
    for(int i=1; i < argc; i++){
        cout << argv[i] << endl;

        //D140193-2021-03-20.csv
        if (strcmp(argv[i],"F") == 0){
            cout << "passou daqui";

            contents[F] = argv[i+1];
            options[F] = 1;
            i++;
        }
        else if (strcmp(argv[i],"N") == 0){
            contents[N] = argv[i+1];
            options[N] = 1;
            i++;
        }
        else if (strcmp(argv[i],"t") == 0){
            cout << "passou daqui";

            contents[t] = argv[i+1];
            options[t] = 1;
            i++;
        }
        else if (strcmp(argv[i],"ti") == 0){
            contents[ti] = argv[i+1];
            options[ti] = 1;
            i++;
        }
        else if (strcmp(argv[i],"tf") == 0){
            contents[tf] = argv[i+1];
            options[tf] = 1;
            i++;
        }
        else if (strcmp(argv[i],"V") == 0){
            contents[V] = argv[i+1];
            options[V] = 1;
            i++;
        }
        else if (strcmp(argv[i],"Vmax") == 0){
            options[Vmax] = 1;
            i++;
        }
        else if (strcmp(argv[i],"Vmin") == 0){
            options[Vmin] = 1;
            i++;
        }
        else if (strcmp(argv[i],"Vmed") == 0){
            options[Vmed] = 1;
            i++;
        }
        else if (strcmp(argv[i],"Vdesvio") == 0){
            options[Vdesvio] = 1;
            i++;
        }
        else if (strcmp(argv[i],"V1") == 0){
            contents[V1] = argv[i+1];
            options[V1] = 1;
            i++;
        }
        else if (strcmp(argv[i],"V2") == 0){
            contents[V2] = argv[i+1];
            options[V2] = 1;
            i++;
        }
        else if (strcmp(argv[i],"Vcorrelacao") == 0){
            options[Vcorrelacao] = 1;
            i++;
        }
    }

    // Faz o gerenciamento de qual função chamar
    if (options[F]){
        TpProjetoFinal Tp(contents[F]);

        cout << "OPTIONS T - " << contents[t];
        if (options[N] && !options[V] && !options[t] && !options[ti]){
            Tp.getNRegistros(stof(contents[N]));
        }
        else if (!options[N] && !options[V] && options[t] && !options[ti]){
            
        }
    }


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
    // teste.getRegistrosPorDataType(1);
    // teste.getRegistrosPorDataMax(1);
    // teste.getRegistrosPorDataMin(1);
    // teste.getRegistrosDataMed("00:00:00","20:00:00",1);
    // teste.getRegistrosDataDP("00:00:00","20:00:00",1);
    // teste.getRegistrosDataDP("00:00:00","23:50:00",3);


    return 0;
}