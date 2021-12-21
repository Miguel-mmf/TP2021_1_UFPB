// #include "TpProjetoFinal.h"
// #include "Linha.h"
// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <cstring>

// using namespace std;


// TpProjetoFinal::TpProjetoFinal(string filename){
//     getContents(filename);
// };


// vector<string> TpProjetoFinal::getColunas(){return colunas;};


// vector<Linha> TpProjetoFinal::getDados(){return dados;};


// void TpProjetoFinal::getContents(string filename){
            
//     char *col;
//     string row;
    
//     ifstream Entrada;
//     Entrada.open(filename);

//     if (!Entrada) cout << "O arquivo nao pode ser aberto!";

//     // pega as colunas do arquivo .csv e salva no container colunas do
//     getline(Entrada,row);
//     col = strtok(&row[0],",");
//     while(col != NULL){
//         colunas.push_back(col);
//         col = strtok(NULL,",");
//     }

//     // pega cada linha do arquivo .csv, transforma num objeto Linha e armazenda dentro do container dados
//     while(!Entrada.eof()){
//         getline(Entrada,row);

//         if (row.length() > 0){
//             col = strtok(&row[0],",");

//             Linha L(col);
//             dados.push_back(L);
//         }
//     }

//     Entrada.close();
// };