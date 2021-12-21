// #include <iostream>
// #include <vector>
// #include <cstring>

// #include "Linha.h"

// using namespace std;

// Linha::Linha(char *linha){
//     int count = 0;
//     while(true){
        
//         if (count == 0){
//             setDatetime(string(linha));
//         }
//         else{
//             linha = strtok(NULL,",");
//             if(linha == NULL) break;
//             contents.push_back(stof(linha));
//         }
//         count++;
//     }
//     // cout << "Quantidade de dados: " << contents.size() << endl;
// }


// void Linha::setDatetime(string data_hora){
//     data_med = data_hora.substr(0,10);
//     hora_med = data_hora.substr(11);
// }


// string Linha::getData(){ return data_med;};


// string Linha::getHora(){ return hora_med;};


// vector<float> Linha::getContents(){ return contents;};