#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip> // manipuladores de stream: setw, left, etc.
#include <locale>

using namespace std;

class Cadastro
{
        string aux[5] = {
            "ID   ",
            "Nome                          ",
            "Matricula   ",
            "Periodo     ",
            "CRA         "
        };
    public:
        void cadastro_novos_estudantes(char[20]);
        void ler_conteudo(char[20]);
};


void Cadastro::cadastro_novos_estudantes(char filename[40])
{
    int sair=0, index=0,periodo;
    long int matricula;
    float cra;
    string nome;

    ofstream Saida;
    Saida.open(filename, ios::app);
    if(!Saida) cout << "O arquivo não pode ser aberto!" << endl;

    // cabeçalho do arquivo .txt
    Saida << left << aux[0] << aux[1] << aux[2] << aux[3] << aux[4] << endl;

    while(!sair){
        
        // quando pressiono Enter a repetição anterior, o getline recebe um char '\n' como entrada no buffer cin
        cin.ignore();
        cout << "Digite o nome do aluno: ";
        getline(cin,nome);
        cout << "Digite o periodo do aluno: ";
        cin >> periodo;
        cout << "Digite o CRA do aluno: ";
        cin >> cra;
        cout << "Digite a matricula do aluno: ";
        cin >> matricula;
        
        Saida << left << setprecision(4) << setw(5) << index++ << setw(30) << nome << setw(12) << matricula << setw(12) << periodo << setw(12) << cra << endl;

        cout << "Nome do aluno: "<< nome << endl;
        cout << "Periodo do Aluno: " << periodo << endl;
        cout << " CRA: " << cra << endl;
        cout  << "Matricula do Aluno: "<< matricula << endl;

        cout << "\nDeseja inserir um novo aluno? (1- sim, 2- nao): ";
        cin >> sair;
        if(sair == 0){sair = 1;} else{break;};
    }

    Saida.close();

};


void Cadastro::ler_conteudo(char filename[20])
{

    ifstream Entrada;
    Entrada.open(filename);
    if(!Entrada) cout << "O arquivo não pode ser aberto!" << endl; 
    string row;

    while(!Entrada.eof()){
        getline(Entrada, row,'\n');
        cout << row << endl;
    }

    Entrada.close();
}


int main()
{
    setlocale(LC_ALL,"Portuguese");

    Cadastro cad;

    char filename[20];
    int sair=0,opcao;

    while(!sair){

        cout<<"\n---------- MENU ----------" << endl;
        cout<<"\nPara criar um arquivo em branco ou editar um existente digite 1\nPara visualizar o conteudo de um arquivo existente digite 2\nPara sair digite 0\n";
        cin>>opcao;

        switch(opcao){

            case 1:
                {
                    cout << "\nDigite o nome do arquivo novo ou existente de ate 20 caracteres: ";
                    cin >> filename;
                    cad.cadastro_novos_estudantes(filename);

                    break;
                }

            case 2:
                {
                    cout << "\n------------------------\n";
                    cout<<"\nDigite o nome do arquivo de ate 20 caracteres que deseja visualizar: ";
                    cin >> filename;
                    cad.ler_conteudo(filename);

                    break;
                }

            default:
                break;
        }

        cout << "\nDeseja inserir acessar o MENU novamente? (1- sim, 2- nao): ";
        cin >> sair;
        if(sair == 1){sair = 0;} else{break;};
    }
    
    return 0;
}