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
        string data_med, hora_med;
    public:
        vector<float> contents;

        Linha(char *linha);

        void setDatetime(string data_hora);
        
        void setDados(float vetor);

        void setData(string data);

        void setHora(string hora);

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


void Linha::setDados(float vetor){
    contents.push_back(vetor);
}


void Linha::setData(string data){
    data_med = data;
}


void Linha::setHora(string hora){
    hora_med = hora;
}


string Linha::getData(){ return data_med;};


string Linha::getHora(){ return hora_med;};


vector<float> Linha::getContents(){ return contents;};


//###########################################################
//                  CLASSE TpProjetoFinal
//###########################################################

class TpProjetoFinal
{
        vector<string> data_hora;
    public:
        vector<string> colunas;
        vector<Linha> dados;

        TpProjetoFinal(string filename);

        void getContents(string filename);

        void percorreDados(auto *func); // está parado
        void percorreColunas(auto *func); // está parado

        void getNRegistros(int num_registro);

        void getRegistrosPorT(string tempo);

		void getRegistrosPorIntervalo(string tempoI, string tempoF); //Geraldo

		void getRegistrosPorDataType(int V); //Geraldo

		int getRegistrosPorDataMax(int V); //Geraldo

		int getRegistrosPorDataMin(int V);  //Geraldo

		void getRegistrosDataMed(string tempoI, string tempoF, int V); //Geraldo

		void getRegistrosDataDP(string tempoI, string tempoF , int V); //Geraldo

        void correlacaoV1V2Pearson(int v1, int v2, string tempoI, string tempoF);

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

    vector<Linha> auxiliar;
    // vector<string>::iterator col;
    vector<Linha>::iterator dado;

    // int *registros = new int(num_registro);
    for(dado = dados.begin(); num_registro > 0; dado++){
        
        auxiliar.push_back(*dado);
        // cout << "\nRegistro " << (*registros-num_registro) << endl;

        // cout <<  left << setw(70) << "\nDia da Medicao: " << dado->getData() << endl;
        // cout << left << setw(70) << "Horario da medicao: " << dado->getHora() << endl;

        // int posicao = 0;
        // for(col = (colunas.begin()+1); col < colunas.end(); col++,posicao++)
        //     cout << left << setw(70) << *col << ": " << dado->getContents().at(posicao) << endl;

        num_registro--;
    }

    dados.clear();
    dados.insert(dados.end(),auxiliar.begin(),auxiliar.end());

    // delete registros;
};


void TpProjetoFinal::getRegistrosPorT(string tempo){

    Linha *auxiliar;

    for(int i = 0; i < dados.size(); i++){

        if (strcmp(dados.at(i).getHora().c_str(),tempo.c_str()) == 0){
            // pega o objeto Linha que está na posicão i do vetor dados
            auxiliar = &(dados.at(i));
            break;
        }
    }
    // quando tiver a opção t, somente uma linha do arquivo é selecionada
    dados.clear();
    dados.push_back(*auxiliar);

    // vector<string>::iterator col;
    // vector<Linha>::iterator dado;

    // cout << "\n\nTamanho: " << dados.size() << endl;
    // for(dado = dados.begin(); dado < dados.end(); dado++){
    //     cout <<  left << setw(70) << "\nDia da Medicao: " << dado->getData() << endl;
    //     cout << left << setw(70) << "Horario da medicao: " << dado->getHora() << endl;

    //     int posicao = 0;
    //     for(col = (colunas.begin()+1); col < colunas.end(); col++,posicao++)
    //         cout << left << setw(70) << *col << ": " << dado->getContents().at(posicao) << endl;
    // }
};


void TpProjetoFinal::getRegistrosPorIntervalo(string tempoI, string tempoF){ //Exibe dados em um intervalo de tempo

    vector<Linha> auxiliar;
    vector<string>::iterator col;
    vector<Linha>::iterator dado;

    // if (dados_modificado.size() == 0) dados_modificado = dados;
    // https://www.cplusplus.com/reference/vector/vector/insert/

    for(dado = dados.begin(); dado < dados.end(); dado++){
        if (strcmp(dado->getHora().c_str(),tempoI.c_str()) == 0){

            while(true){
                if (strcmp(dado->getHora().c_str(),tempoF.c_str()) != 0){ //verifica se o dado está no intervalo de tempo
                    auxiliar.push_back(*dado);
                    dado++;
                }
                else{
                    // para pegar a hr do tempoF
                    auxiliar.push_back(*dado);
                    break;
                }
            }
            break;
        }
    }

    dados.clear();
    dados.insert(dados.end(),auxiliar.begin(),auxiliar.end());
};


void TpProjetoFinal::getRegistrosPorDataType(int V){

    string auxiliar_colunas;
    // vector<string>::iterator col; //aponta para os títulos das colunas
    vector<Linha>::iterator dado; //todas as linhas do csv informado

    auxiliar_colunas = colunas.at(V); //apontando para o rótulo da coluna informada
    float valor_da_coluna;
    int i=0;
    for(dado = dados.begin(); dado < dados.end(); dado++, i++){ //pula as linhas
        
        valor_da_coluna = dado->getContents().at(V-1);
        dados.at(i).contents.clear();
        dados.at(i).setDados(valor_da_coluna);

        // auxiliar_dados.push_back(dado->getContents().at(V-1));
        // dados.at(i).contents.clear();
        // // dado->getContents().clear();
        // dado->setDados(valor_da_coluna);
        // dado->setData(dado->getData());
        // dado->setHora(dado->getHora());

		// cout <<  left << setw(70) << "\nDia da Medicao: " << dado->getData() << endl;
		// cout << left << setw(70) << "Horario da medicao: " << dado->getHora() << endl;
		// cout << left << setw(70) << *col << ": " << dado->getContents().at(V-1) << endl;
    }
    colunas.clear();
    colunas.push_back(auxiliar_colunas);
    // dados.push_back(auxiliar);
};


int TpProjetoFinal::getRegistrosPorDataMax(int V){

    // Linha *auxiliar;
    // vector<string>::iterator col; //aponta para os títulos das colunas
    // vector<Linha>::iterator dado; //todas as linhas do csv informado

	float max;
    int index_max = 0;
	// string dMax, hMax, auxiliar_colunas;

    for(int i=0; i < dados.size(); i++){
    //dado = dados.begin(); dado < dados.end(); dado++){ //pula as linhas
        // cout << "Entrou nesse laço" << endl;
		if (i == 0) //definindo valores iniciais máximos para comparação
		{
			max = dados.at(i).getContents().at(V-1);
            // cout << max << endl;
			// dMax = dado->getData();
			// hMax = dado->getHora();
		} else if (dados.at(i).getContents().at(V-1) > max) //comparação para encontrar o valor máximo
		{
			max = dados.at(i).getContents().at(V-1);
            index_max = i;
			// dMax = dado->getData();
			// hMax = dado->getHora();
		}
	}

    // auxiliar_colunas = colunas.at(V); //apontando para o rótulo da coluna informada
    // dados.clear();
    // auxiliar->setDados(max);
    // auxiliar->setData(dMax);
    // auxiliar->setHora(hMax);
    // dados.push_back(*auxiliar);
    // dados.at(0).setDados(max);
    // dados.at(0).setData(dMax);
    // dados.at(0).setHora(hMax);
    // colunas.clear();
    // colunas.push_back(auxiliar_colunas);
    // cout <<  left << setw(70) << "\nDia da Maior Medicao: " << dados.at(index_max).getData() << endl;
    // cout << left << setw(70) << "Horario da Maior Medicao: " << dados.at(index_max).getHora() << endl;
    // cout << left << setw(70) << colunas.at(V) << ": " << dados.at(index_max).getContents().at(V-1) << endl;
    // cout <<  left << setw(70) << "\nDia da Maior Medicao: " << dMax << endl;
    // cout << left << setw(70) << "Horario da Maior Medicao: " << hMax << endl;
    // cout << left << setw(70) << *col << ": " << max << endl;

    return index_max;
};


int TpProjetoFinal::getRegistrosPorDataMin(int V){

    // vector<string>::iterator col; //aponta para os títulos das colunas
    // vector<Linha>::iterator dado; //todas as linhas do csv informado

	float min;
    int index_min=0;
	// string dMin, hMin;

    for(int i=0; i < dados.size(); i++){ //pula as linhas

		if (i == 0) //definindo valores iniciais mínimos para comparação
		{
			min = dados.at(i).getContents().at(V-1);
			// dMin = dado->getData();
			// hMin = dado->getHora();
		} else if(dados.at(i).getContents().at(V-1) < min) //comparação para encontrar o valor mínimo
		{
			min = dados.at(i).getContents().at(V-1);
            index_min = i;
			// dMin = dado->getData();
			// hMin = dado->getHora();
		}
	}
		// col = (colunas.begin()+V); //apontando para o rótulo da coluna informada

		// cout << left << setw(70) << "\nDia da Menor Medicao: " << dMin << endl;
		// cout << left << setw(70) << "Horario da Menor Medicao: " << hMin << endl;
		// cout << left << setw(70) << *col << ": " << min << endl;

        return index_min;
};


void TpProjetoFinal::getRegistrosDataMed(string tempoI, string tempoF, int V){ //calcula a média no intervalo de tempo dado para uma coluna

    // vector<string>::iterator col;
    vector<Linha>::iterator dado;

	float soma = 0, med;
	int cont = 0;

	// col = (colunas.begin()+V); //apontando para o rótulo da coluna informada

    for(dado = dados.begin(); dado < dados.end(); dado++){ //pula linhas
        if (strcmp(dado->getHora().c_str(),tempoI.c_str()) == 0){

            while(true){
                if (strcmp(dado->getHora().c_str(),tempoF.c_str()) != 0){ //verifica se o dado está no intervalo de tempo
                    soma += dado->getContents().at(V-1); //somatório das medições
                    cont++; //conta a quantidade de medições
                    dado++;
                }
                else{
                    // para pegar a hr do tempoF
                    soma += dado->getContents().at(V-1); //somatório das medições
                    cont++; //conta a quantidade de medições
                    break;
                }
            }
            break;
        }
        // if (dado->getHora() >= tempoI && dado->getHora()<=tempoF){ //verifica se o dado está no intervalo de tempo
        // soma += dado->getContents().at(V-1); //somatório das medições
        // cont++; //conta a quantidade de medições
        // }
    }

	med=(soma/cont); //media das medicoes
    // cout << med << endl;
	// como é a msm data para um arquivo, peguei a primeira data
	cout << left << setw(70) << "\nDia das Medicoes: " << dados.at(0).getData() << endl;
	cout << left << setw(70) << "Intervalo das Medicoes: " << tempoI <<" - " << tempoF << endl;
	cout << left <<"Media das Medicoes de "<< setw(47) << (colunas.at(V)) << ": " << med << endl;

};


void TpProjetoFinal::getRegistrosDataDP(string tempoI, string tempoF , int V){ //calcula a média no intervalo de tempo dado para uma coluna

    vector<string>::iterator col;
    vector<Linha>::iterator dado;

	float soma = 0, med, desvio = 0, dp;
	int cont = 0;

	col = (colunas.begin()+V); //apontando para o rótulo da coluna informada

    for(dado = dados.begin(); dado < dados.end(); dado++){ //pula linhas
        
        if (strcmp(dado->getHora().c_str(),tempoI.c_str()) == 0){

            while(true){
                if (strcmp(dado->getHora().c_str(),tempoF.c_str()) != 0){ //verifica se o dado está no intervalo de tempo
                    soma += dado->getContents().at(V-1); //somatório das medições
                    cont++; //conta a quantidade de medições
                    dado++;
                }
                else{
                    // para pegar a hr do tempoF
                    soma += dado->getContents().at(V-1); //somatório das medições
                    cont++; //conta a quantidade de medições
                    break;
                }
            }
            break;
        }
        // if (dado->getHora() >= tempoI && dado->getHora()<=tempoF){ //verifica se o dado está no intervalo de tempo
		// 	soma += dado->getContents().at(V-1); //somatório das medições
		// 	cont++; //conta a quantidade de medições
        // }
    }

	med=soma/cont; //media das medicoes

	for(dado = dados.begin(); dado < dados.end(); dado++){ //pula linhas
        if (strcmp(dado->getHora().c_str(),tempoI.c_str()) == 0){

            while(true){
                if (strcmp(dado->getHora().c_str(),tempoF.c_str()) != 0){ //verifica se o dado está no intervalo de tempo
                    desvio += pow((dado->getContents().at(V-1)-med),2)/(cont); //desvio
                    dado++;
                }
                else{
                    // para pegar a hr do tempoF
                    soma += dado->getContents().at(V-1); //somatório das medições
                    cont++; //conta a quantidade de medições
                    break;
                }
            }
            break;
        }
        // if (dado->getHora() >= tempoI && dado->getHora()<=tempoF){ //verifica se o dado está no intervalo de tempo
		// 	desvio += pow((dado->getContents().at(V-1)-med),2)/(cont); //desvio
        // }
    }

	dp = sqrt(desvio);

    // showDataHoraMedicao(dado,tempoI,tempoF);

    // como é a msm data para um arquivo, peguei a primeira data
	cout << left << setw(70) << "\nDia das Medicoes: " << dados.at(0).getData() << endl;
	cout << left << setw(70) << "Intervalo das Medicoes: " << tempoI << " - " << tempoF << endl;
	cout << left <<"Desvio Padrao das Medicoes de "<<setw(40)<< colunas.at(V) << ": " << dp << endl;

};


void TpProjetoFinal::correlacaoV1V2Pearson(int v1, int v2, string tempoI, string tempoF){
    // vector<string> auxiliar_colunas;
    // vector<string>::iterator col; //aponta para os títulos das colunas
    vector<Linha>::iterator dado; //todas as linhas do csv informado

    // auxiliar_colunas.push_back(colunas.at(v1)); //apontando para o rótulo da coluna informada
    // auxiliar_colunas.push_back(colunas.at(v2)); //apontando para o rótulo da coluna informada
    float valor_da_coluna, somav1=0, somav2=0,med1,med2;
    int i=0, cont=0;
    cout << "Entrou no primeiro laco media" << endl;
    for(dado = dados.begin(); dado < dados.end(); dado++){ //pula linhas
        if (strcmp(dado->getHora().c_str(),tempoI.c_str()) == 0){

            while(true){
                if (strcmp(dado->getHora().c_str(),tempoF.c_str()) != 0){ //verifica se o dado está no intervalo de tempo
                    somav1 += dado->getContents().at(v1-1); //somatório das medições
                    somav2 += dado->getContents().at(v2-1); //somatório das medições
                    cont++; //conta a quantidade de medições
                    dado++;
                }
                else{
                    // para pegar a hr do tempoF
                    somav1 += dado->getContents().at(v1-1); //somatório das medições
                    somav2 += dado->getContents().at(v2-1); //somatório das medições
                    cont++; //conta a quantidade de medições
                    break;
                }
            }
            break;
        }
    }
    cout << "Saiu do primeiro laco" << endl;

    med1=(somav1/cont);
    med2=(somav2/cont);

    cout << "Entrou no segundo laco variancia" << endl;

    float somavar1=0,somavar2=0;
    for(dado = dados.begin(); dado < dados.end(); dado++){ //pula linhas
        if (strcmp(dado->getHora().c_str(),tempoI.c_str()) == 0){

            while(true){
                if (strcmp(dado->getHora().c_str(),tempoF.c_str()) != 0){ //verifica se o dado está no intervalo de tempo
                    somavar1 += ((dado->getContents().at(v1-1) - med1)*(dado->getContents().at(v1-1) - med1));
                    somavar2 += ((dado->getContents().at(v2-1) - med2)*(dado->getContents().at(v2-1) - med2));
                    dado++;
                }
                else{
                    // para pegar a hr do tempoF
                    somavar1 += ((dado->getContents().at(v1-1) - med1)*(dado->getContents().at(v1-1) - med1));
                    somavar2 += ((dado->getContents().at(v2-1) - med2)*(dado->getContents().at(v2-1) - med2));
                    break;
                }
            }
            break;
        }
    }
    cout << "Saiu do segundo laco" << endl;

    float somacov=0;
    cout << "Entrou no terceiro laco covariancia" << endl;

    for(dado = dados.begin(); dado < dados.end(); dado++){ //pula linhas
        if (strcmp(dado->getHora().c_str(),tempoI.c_str()) == 0){

            while(true){
                if (strcmp(dado->getHora().c_str(),tempoF.c_str()) != 0){ //verifica se o dado está no intervalo de tempo
                    somacov += ((dado->getContents().at(v1-1) - med1)*(dado->getContents().at(v2-1) - med2));
                    dado++;
                }
                else{
                    // para pegar a hr do tempoF
                    somacov += ((dado->getContents().at(v1-1) - med1)*(dado->getContents().at(v2-1) - med2));
                    break;
                }
            }
            break;
        }
    }
    cout << "Saiu do terceiro laco" << endl;

    float coeficiente = (somacov/(sqrt(somavar1*somavar2)));

    cout << left << setw(70) << "\nDia das Medicoes: " << dados.at(0).getData() << endl;
	cout << left << setw(70) << "Intervalo das Medicoes: " << tempoI <<" - " << tempoF << endl;
	cout << left <<"Coeficiente de correlacao de Pearson das colunas " << colunas.at(v1) << " e " << colunas.at(v2) << setw(5) << ": " << coeficiente << endl;

    if (abs(coeficiente) >= 0.9)
        cout << "Correlacao muito forte!" << endl;
    else if (abs(coeficiente) < 0.9 && abs(coeficiente) >= 0.7)
        cout << "Correlacao forte!" << endl;
    else if (abs(coeficiente) < 0.7 && abs(coeficiente) >= 0.5)
        cout << "Correlacao moderada!" << endl;
    else if (abs(coeficiente) < 0.5 && abs(coeficiente) >= 0.3)
        cout << "Correlacao fraca!" << endl;
    else if (abs(coeficiente) < 0.3 && abs(coeficiente) >= 0)
        cout << "Correlacao desprezivel!" << endl;
    else
        cout << "Se chegou ate aqui, muito suspeito! Nao era para isso aocntecer!" << endl;

}



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
#define Vmedia 8
#define Vdesvio 9
#define V1 10
#define V2 11
#define Vcorrelacao 13


int main(int argc, char *argv[])
{
    cout << "inicio";
    int options[14]={0};
    string contents[14];

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
            contents[t] = argv[i+1];
            options[t] = 1;
            i++;
        }
        else if (strcmp(argv[i],"ti") == 0){
            cout << "passou daqui ti";
            contents[ti] = argv[i+1];
            options[ti] = 1;
            i++;
        }
        else if (strcmp(argv[i],"tf") == 0){
            cout << "passou daqui tf";
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
        else if (strcmp(argv[i],"Vmedia") == 0){
            options[Vmedia] = 1;
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
        vector<string> titulo_colunas = Tp.getColunas();
        vector<Linha> dados = Tp.getDados();

        // essa sequência segue uma hierarquia, ou seja, primeiro "filtramos" o intervalo de tempo para depois pegar os registros
        if (options[t]){
            cout << "OPTIONS T - " << contents[t];
            Tp.getRegistrosPorT(contents[t]);

            titulo_colunas = Tp.getColunas();
            dados = Tp.getDados();
            
            if (!options[ti] && !options[tf] && !options[N] && !options[V]){
                vector<string>::iterator col;
                vector<Linha>::iterator dado;

                cout << "\n\nTamanho: " << dados.size() << endl;
                for(dado = dados.begin(); dado < dados.end(); dado++){
                    cout <<  left << setw(70) << "\nDia da Medicao: " << dado->getData() << endl;
                    cout << left << setw(70) << "Horario da medicao: " << dado->getHora() << endl;

                    int posicao = 0;
                    for(col = (titulo_colunas.begin()+1); col < titulo_colunas.end(); col++,posicao++)
                        cout << left << setw(70) << *col << ": " << dado->getContents().at(posicao) << endl;
                }
            }
        }

        if (options[ti] && !options[Vmedia] && !options[Vdesvio] && !options[Vcorrelacao]){

            if (options[tf]){
                // cout << "OPTIONS Ti Tf" << contents[ti] << contents[tf];

                Tp.getRegistrosPorIntervalo(contents[ti],contents[tf]);

                titulo_colunas = Tp.getColunas();
                dados = Tp.getDados();

                if (!options[N] && !options[V] && !options[Vmax] && !options[Vmin]){
                    vector<string>::iterator col;
                    vector<Linha>::iterator dado;

                    cout << "Tamanho: " << dados.size() << endl;
                    for(dado = dados.begin(); dado < dados.end(); dado++){
                        cout <<  left << setw(70) << "\nDia da Medicao: " << dado->getData() << endl;
                        cout << left << setw(70) << "Horario da medicao: " << dado->getHora() << endl;

                        int posicao = 0;
                        for(col = (titulo_colunas.begin()+1); col < titulo_colunas.end(); col++,posicao++)
                            cout << left << setw(70) << *col << ": " << dado->getContents().at(posicao) << endl;
                    }
                }
            }
        }

        if (options[V]){

            if (options[Vmax]){
                int index_max = Tp.getRegistrosPorDataMax(stoi(contents[V])); // preciso converter de string para int, por isso o stoi()
                // cout << "Index max: " << index_max << endl;
                titulo_colunas = Tp.getColunas();
                dados = Tp.getDados();

                cout <<  left << setw(70) << "\nDia da Maior Medicao: " << dados.at(index_max).getData() << endl;
                cout << left << setw(70) << "Horario da Maior Medicao: " << dados.at(index_max).getHora() << endl;
                cout << left << setw(70) << titulo_colunas.at(stoi(contents[V])) << ": " << dados.at(index_max).getContents().at(stoi(contents[V])-1) << endl;

                // cout <<  left << setw(70) << "\nDia da Maior Medicao: " << dados.at(0).getData() << endl;
                // cout << left << setw(70) << "Horario da Maior Medicao: " << dados.at(0).getHora() << endl;
                // cout << left << setw(70) << titulo_colunas.at(0) << ": " << dados.at(0).getContents().at(0) << endl;

                // vector<string>::iterator col;
                // vector<Linha>::iterator dado;

                // cout << "Tamanho: " << dados.size() << endl;
                // for(dado = dados.begin(); dado < dados.end(); dado++){
                //     cout <<  left << setw(70) << "\nDia da Medicao: " << dado->getData() << endl;
                //     cout << left << setw(70) << "Horario da medicao: " << dado->getHora() << endl;

                //     int posicao = 0;
                //     for(col = (titulo_colunas.begin()+1); col < titulo_colunas.end(); col++,posicao++)
                //         cout << left << setw(70) << *col << ": " << dado->getContents().at(posicao) << endl;
                // }
            }

            else if (options[Vmin]){
                int index_min = Tp.getRegistrosPorDataMin(stoi(contents[V])); // preciso converter de string para int, por isso o stoi()

                titulo_colunas = Tp.getColunas();
                dados = Tp.getDados();

                cout <<  left << setw(70) << "\nDia da Maior Medicao: " << dados.at(index_min).getData() << endl;
                cout << left << setw(70) << "Horario da Maior Medicao: " << dados.at(index_min).getHora() << endl;
                cout << left << setw(70) << titulo_colunas.at(stoi(contents[V])) << ": " << dados.at(index_min).getContents().at(stoi(contents[V])-1) << endl;
            }

            else if (options[Vmedia]){
                cout << "Tempo inicial: " << contents[ti] << endl;
                cout << "Tempo final: " << contents[tf] << endl;
                Tp.getRegistrosDataMed(contents[ti],contents[tf],stoi(contents[V])); // preciso converter de string para int, por isso o stoi()

                titulo_colunas = Tp.getColunas();
                dados = Tp.getDados();
            }

            else if (options[Vdesvio]){
                cout << "Tempo inicial: " << contents[ti] << endl;
                cout << "Tempo final: " << contents[tf] << endl;
                Tp.getRegistrosDataDP(contents[ti],contents[tf],stoi(contents[V])); // preciso converter de string para int, por isso o stoi()

                titulo_colunas = Tp.getColunas();
                dados = Tp.getDados();
            }

            else {
                cout << "OPTIONS V - " << contents[V];
                Tp.getRegistrosPorDataType(stoi(contents[V])); // preciso converter de string para int, por isso o stoi()

                titulo_colunas = Tp.getColunas();
                dados = Tp.getDados();
                
                if (!options[N] && !options[t]){
                    vector<string>::iterator col;
                    vector<Linha>::iterator dado;

                    cout << "Tamanho: " << dados.size() << endl;
                    for(dado = dados.begin(); dado < dados.end(); dado++){
                        cout <<  left << setw(70) << "\nDia da Medicao: " << dado->getData() << endl;
                        cout << left << setw(70) << "Horario da medicao: " << dado->getHora() << endl;

                        cout << left << setw(70) << titulo_colunas.at(0) << ": " << dado->getContents().at(0) << endl;
                    }
                }
            }
        }

        if (options[N]){
            cout << "OPTIONS N - " << contents[N];
            Tp.getNRegistros(stoi(contents[N])); // preciso converter de string para int, por isso o stoi()

            titulo_colunas = Tp.getColunas();
            dados = Tp.getDados();

            vector<string>::iterator col;
            vector<Linha>::iterator dado;

            cout << "Tamanho: " << dados.size() << endl;
            for(dado = dados.begin(); dado < dados.end(); dado++){
                cout <<  left << setw(70) << "\nDia da Medicao: " << dado->getData() << endl;
                cout << left << setw(70) << "Horario da medicao: " << dado->getHora() << endl;

                int posicao = 0;
                for(col = (titulo_colunas.begin()+1); col < titulo_colunas.end(); col++,posicao++)
                    cout << left << setw(70) << *col << ": " << dado->getContents().at(posicao) << endl;
            }
        }

        if (options[Vcorrelacao]){
            cout << "Tempo inicial: " << contents[ti] << endl;
            cout << "Tempo final: " << contents[tf] << endl;
            cout << "V1: " << contents[V1] << endl;
            cout << "V2: " << contents[V2] << endl;
            Tp.correlacaoV1V2Pearson(stoi(contents[V1]),stoi(contents[V2]),contents[ti],contents[tf]); // preciso converter de string para int, por isso o stoi()

            titulo_colunas = Tp.getColunas();
            dados = Tp.getDados();
        }

        // vector<string>::iterator col;
        // vector<Linha>::iterator dado;

        // cout << "\n\nTamanho: " << dados.size() << endl;
        // for(dado = dados.begin(); dado < dados.end(); dado++){
        //     cout <<  left << setw(70) << "\nDia da Medicao: " << dado->getData() << endl;
        //     cout << left << setw(70) << "Horario da medicao: " << dado->getHora() << endl;

        //     int posicao = 0;
        //     for(col = (titulo_colunas.begin()+1); col < titulo_colunas.end(); col++,posicao++)
        //         cout << left << setw(70) << *col << ": " << dado->getContents().at(posicao) << endl;
        // }
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