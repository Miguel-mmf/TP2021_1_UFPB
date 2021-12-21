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
            linha = strtok(NULL,","); // https://www.cplusplus.com/reference/cstring/strtok/
            if(linha == NULL) break;
            contents.push_back(stof(linha)); // https://www.cplusplus.com/reference/string/stof/
        }
        count++;
    }
}


void Linha::setDatetime(string data_hora){
    // https://www.cplusplus.com/reference/string/string/substr/
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

        // void percorreDados(auto *func); // está parado
        // void percorreColunas(auto *func); // está parado

        void getNRegistros(int num_registro);

        void getRegistrosPorT(string tempo);

		void getRegistrosPorIntervalo(string tempoI, string tempoF);

		void getRegistrosPorDataType(int V);

		int getRegistrosPorDataMax(int V);

		int getRegistrosPorDataMin(int V);

		void getRegistrosDataMed(string tempoI, string tempoF, int V);

		void getRegistrosDataDP(string tempoI, string tempoF , int V);

        void correlacaoV1V2Pearson(int v1, int v2, string tempoI, string tempoF);

        vector<string> getColunas();

        vector<Linha> getDados();
};


TpProjetoFinal::TpProjetoFinal(string filename){
    getContents(filename);
};


vector<string> TpProjetoFinal::getColunas(){return colunas;};


vector<Linha> TpProjetoFinal::getDados(){return dados;};


void TpProjetoFinal::getContents(string filename)
{

    char *col;
    string row;

    ifstream Entrada;
    Entrada.open(filename);

    if (!Entrada) cout << "O arquivo nao pode ser aberto!";

    // pega as colunas do arquivo .csv e salva no container colunas do
    getline(Entrada,row);
    //https://www.cplusplus.com/reference/cstring/strtok/
    col = strtok(&row[0],",");
    while(col != NULL){
        colunas.push_back(col);
        col = strtok(NULL,","); // quando acabar a linha, o laço é interrompido
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


void TpProjetoFinal::getNRegistros(int num_registro)
{

    vector<Linha> auxiliar;
    vector<Linha>::iterator dado;

    for(dado = dados.begin(); num_registro > 0; dado++){
        
        auxiliar.push_back(*dado);
        num_registro--;
    }

    dados.clear();
    // eu só preciso dos resgistros no vetor dados.
    // https://www.cplusplus.com/reference/vector/vector/insert/
    dados.insert(
        dados.end(),
        auxiliar.begin(),
        auxiliar.end()
    );
};


void TpProjetoFinal::getRegistrosPorT(string tempo)
{

    Linha *auxiliar;
    vector<Linha>::iterator dado;

    for(dado = dados.begin(); dado != dados.end(); dado++){

        if (strcmp(dado->getHora().c_str(),tempo.c_str()) == 0){
            // pega o objeto Linha que está na posicão i do vetor dados
            auxiliar = &(*dado);
            break;
        }
    }
    // quando tiver a opção t, somente uma linha do arquivo é necessária, ou seja, a linha com o tempo de medição igual ao enviado com t
    dados.clear();
    dados.push_back(*auxiliar);
};


void TpProjetoFinal::getRegistrosPorIntervalo(string tempoI, string tempoF)
{ //Exibe dados em um intervalo de tempo

    vector<Linha> auxiliar;
    vector<Linha>::iterator dado;

    for(dado = dados.begin(); dado < dados.end(); dado++){
        if (strcmp(dado->getHora().c_str(),tempoI.c_str()) == 0){

            while(true){
                //verifica se o dado está no intervalo de tempo
                if (strcmp(dado->getHora().c_str(),tempoF.c_str()) != 0){
                    auxiliar.push_back(*dado);
                    dado++;
                }
                else{
                    // para pegar a hora do tempoF
                    auxiliar.push_back(*dado);
                    break;
                }
            }
            break;
        }
    }

    dados.clear();
    dados.insert(
        dados.end(),
        auxiliar.begin(),
        auxiliar.end()
    );
};


void TpProjetoFinal::getRegistrosPorDataType(int V)
{

    string auxiliar_colunas;
    vector<Linha>::iterator dado; // percorre todas as posicao do container dados

    auxiliar_colunas = colunas.at(V); //apontando para o rótulo da coluna informada
    float valor_da_coluna;
    int i=0;
    for(dado = dados.begin(); dado < dados.end(); dado++, i++){ //pula as linhas
        
        valor_da_coluna = dado->getContents().at(V-1);
        dados.at(i).contents.clear();
        dados.at(i).setDados(valor_da_coluna);
    }
    colunas.clear();
    colunas.push_back(auxiliar_colunas);
};


int TpProjetoFinal::getRegistrosPorDataMax(int V)
{
    vector<Linha>::iterator dado; // percorre todas as posicao do container dados

   	float max;
    int index_max = 0, i=0;

    for(dado = dados.begin(); dado < dados.end(); dado++, i++){
		if (i == 0) //definindo valores iniciais máximos para comparação
		{
			max = dado->getContents().at(V-1);
		} else if (dado->getContents().at(V-1) > max) //comparação para encontrar o valor máximo
		{
			max = dado->getContents().at(V-1);
            index_max = i;
		}
	}

    return index_max;
};


int TpProjetoFinal::getRegistrosPorDataMin(int V)
{
    vector<Linha>::iterator dado; // percorre todas as posicao do container dados

	float min;
    int index_min=0, i = 0;

    for(dado = dados.begin(); dado < dados.end(); dado++, i++){

		if (i == 0) //definindo valores iniciais mínimos para comparação
		{
			min = dado->getContents().at(V-1);
		} else if(dado->getContents().at(V-1) < min) //comparação para encontrar o valor mínimo
		{
			min = dado->getContents().at(V-1);
            index_min = i;
		}
	}

    return index_min;
};


void TpProjetoFinal::getRegistrosDataMed(string tempoI, string tempoF, int V)
{ //calcula a média no intervalo de tempo dado para uma coluna

    vector<Linha>::iterator dado;

	float soma = 0, med;
	int cont = 0;

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
    }

	med=(soma/cont); //media das medicoes

	cout << left << setw(70) << "\nDia da Medicoes: " << dados.at(0).getData() << endl;
	cout << left << setw(70) << "Intervalo das Medicoes: " << tempoI <<" - " << tempoF << endl;
	cout << left <<"Media das Medicoes de "<< setw(47) << (colunas.at(V)) << ": " << med << endl;
};


void TpProjetoFinal::getRegistrosDataDP(string tempoI, string tempoF , int V)
{ //calcula a média no intervalo de tempo dado para uma coluna

    vector<Linha>::iterator dado;

	float soma = 0, med, desvio = 0, dp;
	int cont = 0;

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
    }

	dp = sqrt(desvio);

    // como é a msm data para um arquivo, peguei a primeira data
	cout << left << setw(70) << "\nDia das Medicoes: " << dados.at(0).getData() << endl;
	cout << left << setw(70) << "Intervalo das Medicoes: " << tempoI << " - " << tempoF << endl;
	cout << left <<"Desvio Padrao das Medicoes de "<<setw(40)<< colunas.at(V) << ": " << dp << endl;
};


void TpProjetoFinal::correlacaoV1V2Pearson(int v1, int v2, string tempoI, string tempoF)
{

    vector<Linha>::iterator dado; //todas as linhas do csv informado

    float valor_da_coluna, somav1=0, somav2=0,med1,med2;
    int i=0, cont=0;
    
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

    med1=(somav1/cont);
    med2=(somav2/cont);

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

    float somacov=0;

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
        cout << "Se chegou ate aqui, muito suspeito! Nao era para isso acontecer!" << endl;
}



//###########################################################
//                  FUNCAO MAIN
//###########################################################

// Códigos para testar o programa

// .\programa F ../D140193-2021-03-20.csv N 5
// .\programa F ../D140193-2021-03-20.csv t 20:00:00
// .\programa F ../D140193-2021-03-20.csv ti 00:00:00 tf 02:00:00
// .\programa ti 00:00:00 tf 02:00:00 F ../D140193-2021-03-20.csv
// .\programa F ../D140193-2021-03-20.csv V 14
// .\programa V 14 F ../D140193-2021-03-20.csv
// .\programa F ../D140193-2021-03-20.csv V 14 Vmax
// .\programa F ../D140193-2021-03-20.csv V 14 Vmin
// .\programa F ../D140193-2021-03-20.csv V 14 ti 01:40:00 tf 05:30:00 Vmedia
// .\programa F ../D140193-2021-03-20.csv V 14 ti 01:40:00 tf 05:30:00 Vdesvio
// .\programa F ../D140193-2021-03-20.csv V 14 ti 00:00:00 tf 02:00:00
// .\programa F ../D140193-2021-03-20.csv ti 01:40:00 tf 05:30:00 V1 14 V2 15 Vcorrelacao

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
    int options[14]={0};
    string contents[14];

    // faz a analise dos valores presentes em argv
    for(int i=1; i < argc; i++){

        //D140193-2021-03-20.csv
        if (strcmp(argv[i],"F") == 0){
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

        // essa sequência segue uma hierarquia, ou seja, primeiro "filtramos" o intervalo de tempo para depois pegar os registros, colunas, Vmax, etc
        if (options[t]){
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

        // o erro por está aqui (protásio), tentar depurar depois.
        if (options[V]){

            if (options[Vmax]){
                int index_max = Tp.getRegistrosPorDataMax(stoi(contents[V])); // preciso converter de string para int, por isso o stoi()
                titulo_colunas = Tp.getColunas();
                dados = Tp.getDados();

                cout <<  left << setw(70) << "\nDia da Maior Medicao: " << dados.at(index_max).getData() << endl;
                cout << left << setw(70) << "Horario da Maior Medicao: " << dados.at(index_max).getHora() << endl;
                cout << left << setw(70) << titulo_colunas.at(stoi(contents[V])) << ": " << dados.at(index_max).getContents().at(stoi(contents[V])-1) << endl;
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
                // cout << "Tempo inicial: " << contents[ti] << endl;
                // cout << "Tempo final: " << contents[tf] << endl;
                Tp.getRegistrosDataMed(contents[ti],contents[tf],stoi(contents[V])); // preciso converter de string para int, por isso o stoi()

                titulo_colunas = Tp.getColunas();
                dados = Tp.getDados();
            }

            else if (options[Vdesvio]){
                // cout << "Tempo inicial: " << contents[ti] << endl;
                // cout << "Tempo final: " << contents[tf] << endl;
                Tp.getRegistrosDataDP(contents[ti],contents[tf],stoi(contents[V])); // preciso converter de string para int, por isso o stoi()

                titulo_colunas = Tp.getColunas();
                dados = Tp.getDados();
            }

            else {
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
            // cout << "Tempo inicial: " << contents[ti] << endl;
            // cout << "Tempo final: " << contents[tf] << endl;
            // cout << "V1: " << contents[V1] << endl;
            // cout << "V2: " << contents[V2] << endl;
            Tp.correlacaoV1V2Pearson(stoi(contents[V1]),stoi(contents[V2]),contents[ti],contents[tf]); // preciso converter de string para int, por isso o stoi()

            titulo_colunas = Tp.getColunas();
            dados = Tp.getDados();
        }

    }

    return 0;
}