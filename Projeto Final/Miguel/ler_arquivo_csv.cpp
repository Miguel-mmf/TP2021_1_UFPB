#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <iterator>

using namespace std;

class Linha
{
        vector<float> contents;
        string data_med, hora_med;
    public:
        Linha(char *linha){
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

        void setDatetime(string data_hora){
            data_med = data_hora.substr(0,10);
            hora_med = data_hora.substr(11);
        }

        string getData(){ return data_med; };
        string getHora(){ return hora_med; };
        vector<float> getContents(){ return contents; };
};


class TpProjetoFinal
{
        vector<string> colunas;
        vector<Linha> dados;
        vector<string> data_hora;
    public:
        TpProjetoFinal(string filename)
        {
            getContents(filename);
        }

        void getContents(string filename)
        {
            
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
        }

        vector<string> getColunas(){return colunas;}
        vector<Linha> getDados(){return dados;}
};



int main()
{
    TpProjetoFinal teste("../D140193-2021-03-20.csv");

    // mostra colunas do objeto teste da classe TpProjetoFinal
    // for(int i = 0; i < teste.getColunas().size(); i++){
    //     cout << teste.getColunas().at(i) << endl;
    // }

    // valores da primeira linha do arquivo csv
    auto L = teste.getDados().at(1);
    cout << L.getData() << " " << L.getHora() << endl;
    cout << "Quantidade de dados: " << L.getContents().size() << endl;
    for(int i = 0; i < L.getContents().size(); i++)
        cout << L.getContents().at(i) << " - ";
    
    return 0;
}