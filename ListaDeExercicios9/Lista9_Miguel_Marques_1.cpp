#include <iostream>
#include <fstream>
#include <iomanip> // manipuladores de stream: setw, left, etc.
#include <string>
#include <cctype>
#include <locale>

using namespace std;

char gera_opcoes();
string separa_linha(string, int, int);
string converte_para_minusculo(string);

// eu poderia usar o resize para ajustar cada elemento do array...
string aux[5] = {
    "ID   ",
    "Nome                          ",
    "Nota 1  ",
    "Nota 2  ",
    "Nota 3  "
};

int main()
{
    setlocale(LC_ALL,"Portuguese"); // habilita a acentuação

    int index=1, continuar=0;
    string nome;
    float nota1 = 0, nota2 = 0, nota3 = 0;

    cout << "Deseja salvar os dados dos alunos? 1 - sim   0 - nao e abrir o ultimo arquivo salvo." << endl;
    cin >> continuar;

    if (continuar){

        ofstream Saida;
        Saida.open("dados_alunos.txt");

        if(!Saida){ cout << "O arquivo não pode ser aberto!" << endl; return 1;}

        cout << "Digite abaixo os dados dos alunos (para sair, digite 0 para o nome do aluno): " << endl;

        // cabeçalho do arquivo .txt
        Saida << left << aux[0] << aux[1] << aux[2] << aux[3] << aux[4] << endl;

        while(1){
            cout << "\n----------------- Aluno " << index << " -----------------" << endl;
            // quando pressiono Enter a repetição anterior, o getline recebe um char '\n' como entrada no buffer cin
            cin.ignore(nome.length(),'\n');
            cout << "Nome do aluno:" << endl;
            getline(cin,nome);

            if (nome == "0"){
                cout << "\n\nAlunos cadastrados!!!" << endl;
                break;
            }

            cout << "Nota 1: ";
            cin >> nota1;
            cout << "Nota 2: ";
            cin >> nota2;
            cout << "Nota 3: ";
            cin >> nota3;

            //http://atl.clicrbs.com.br/mundobom/2011/01/20/nome-proprio-mais-comprido-do-mundo-tem-29-palavras-e-197-letras/
            nome.resize(30,' ');

            Saida << left << setprecision(4) << setw(5) << index++ << setw(30) << nome << setw(8) << nota1 << setw(8) << nota2 << setw(8) << nota3 << endl;
        }

        Saida.close();
    }

    else{
        fstream Entrada;
        Entrada.open("dados_alunos.txt");
        if(!Entrada){ cout << "O arquivo não pode ser aberto!" << endl; return 1;}  

        int opcao_menu = gera_opcoes();
        cout << "Opcao menu: " << (char)opcao_menu << endl;
        
        switch(opcao_menu){

            case 'A':
                {
                    cout << "Alunos cadastrados:" << endl;
                    int posicao = 1; // começa da 1 para pular o header
                    string nome, row, aux;
                    float nota1, nota2, nota3;

                    Entrada.seekg(0);
                    while(true){

                        Entrada.seekg(posicao*(5 + 30 + 8 + 8 + 8 + 2) + 5);
                        getline(Entrada, row,'\n');

                        // cout << row << endl;
                        nome = separa_linha(row,0, 30);
                        aux = separa_linha(row,30,8);
                        nota1 = stof(aux); // converte uma string para um float
                        aux = separa_linha(row,38,8);
                        nota2 = stof(aux);
                        aux = separa_linha(row,46,8);
                        nota3 = stof(aux);

                        cout << "Nome: " << nome << " - Media das notas: " << (nota1+nota2+nota3)/3 << endl;

                        if (Entrada.eof())
                            break;
                        else
                            posicao++;
                    }

                    Entrada.close();

                    break;
                };

            case 'B':
                {
                    int posicao = 1; // começa da 1 para pular o header
                    string nome, row, aux;
                    float nota1, nota2, nota3, media=0;

                    Entrada.seekg(0);
                    while(true){

                        Entrada.seekg(posicao*(5 + 30 + 8 + 8 + 8 + 2) + 5);
                        getline(Entrada, row,'\n');

                        aux = separa_linha(row,30,8);
                        nota1 = stof(aux); // converte uma string para um float
                        aux = separa_linha(row,38,8);
                        nota2 = stof(aux);
                        aux = separa_linha(row,46,8);
                        nota3 = stof(aux);

                        media += (nota1+nota2+nota3)/3;

                        if (Entrada.eof())
                            break;
                        else
                            posicao++;
                    }

                    cout << "A media de todos os alunos eh: " << media/posicao << endl;

                    Entrada.close();

                    break;
                };

            case 'C':
                {
                    cout << "Alunos cadastrados:" << endl;
                    int posicao = 1; // começa da 1 para pular o header
                    string nome, row, aux;
                    float nota1=0, nota2=0, nota3=0, media=0;

                    Entrada.seekg(0);
                    while(true){

                        Entrada.seekg(posicao*(5 + 30 + 8 + 8 + 8 + 2) + 5);
                        getline(Entrada, row,'\n');

                        aux = separa_linha(row,30,8);
                        nota1 += stof(aux); // converte uma string para um float
                        aux = separa_linha(row,38,8);
                        nota2 += stof(aux);
                        aux = separa_linha(row,46,8);
                        nota3 += stof(aux);

                        if (Entrada.eof())
                            break;
                        else
                            posicao++;
                    }

                    cout << "A media de todos os alunos na nota 1: " << nota1/posicao << endl;
                    cout << "A media de todos os alunos na nota 2: " << nota2/posicao << endl;
                    cout << "A media de todos os alunos na nota 3: " << nota3/posicao << endl;

                    Entrada.close();

                    break;
                };

            case 'D':
                {
                    cout << "Alunos Reprovados:" << endl;
                    int posicao = 1; // começa da 1 para pular o header
                    string nome, row, aux;
                    float nota1, nota2, nota3;

                    Entrada.seekg(0);
                    while(true){

                        Entrada.seekg(posicao*(5 + 30 + 8 + 8 + 8 + 2) + 5);
                        getline(Entrada, row,'\n');

                        nome = separa_linha(row,0, 30);
                        aux = separa_linha(row,30,8);
                        nota1 = stof(aux); // converte uma string para um float
                        aux = separa_linha(row,38,8);
                        nota2 = stof(aux);
                        aux = separa_linha(row,46,8);
                        nota3 = stof(aux);

                        if (((nota1+nota2+nota3)/3) < 7)
                            cout << "Nome: " << nome << " - Situacao: Repovado!" << endl;

                        if (Entrada.eof())
                            break;
                        else
                            posicao++;
                    }

                    Entrada.close();

                    break;
                };

            case 'E':
                {
                    cout << "Alunos Aprovados:" << endl;
                    int posicao = 1; // começa da 1 para pular o header
                    string nome, row, aux;
                    float nota1, nota2, nota3;

                    Entrada.seekg(0);
                    while(true){

                        Entrada.seekg(posicao*(5 + 30 + 8 + 8 + 8 + 2) + 5);
                        getline(Entrada, row,'\n');

                        nome = separa_linha(row,0, 30);
                        aux = separa_linha(row,30,8);
                        nota1 = stof(aux); // converte uma string para um float
                        aux = separa_linha(row,38,8);
                        nota2 = stof(aux);
                        aux = separa_linha(row,46,8);
                        nota3 = stof(aux);

                        if (((nota1+nota2+nota3)/3) > 7)
                            cout << "Nome: " << nome << " - Situacao: Aprovado!" << endl;

                        if (Entrada.eof())
                            break;
                        else
                            posicao++;
                    }

                    Entrada.close();
                    break;
                };

            case 'F':
                {
                    cout << "Alunos com nota minima:" << endl;
                    int posicao = 1; // começa da 1 para pular o header
                    string nome, nome_menor_nota, row, aux;
                    float nota1, nota2, nota3, media_min = 10;

                    Entrada.seekg(0);
                    while(true){

                        Entrada.seekg(posicao*(5 + 30 + 8 + 8 + 8 + 2) + 5);
                        getline(Entrada, row,'\n');

                        nome = separa_linha(row,0, 30);
                        aux = separa_linha(row,30,8);
                        nota1 = stof(aux); // converte uma string para um float
                        aux = separa_linha(row,38,8);
                        nota2 = stof(aux);
                        aux = separa_linha(row,46,8);
                        nota3 = stof(aux);

                        if (((nota1+nota2+nota3)/3) < media_min){
                            media_min = (nota1+nota2+nota3)/3;
                            nome_menor_nota = nome;
                        }

                        if (Entrada.eof())
                            break;
                        else
                            posicao++;
                    }

                    cout << "Aluno com menor nota media: " << nome_menor_nota << " - Media: " << media_min << endl;
                    Entrada.close();

                    break;
                };
            
            case 'G':
                {
                    cout << "Aluno com nota maxima:" << endl;
                    int posicao = 1; // começa da 1 para pular o header
                    string nome, nome_max_nota, row, aux;
                    float nota1, nota2, nota3, media_max = 0;

                    Entrada.seekg(0);
                    while(true){

                        Entrada.seekg(posicao*(5 + 30 + 8 + 8 + 8 + 2) + 5);
                        getline(Entrada, row,'\n');

                        nome = separa_linha(row,0, 30);
                        aux = separa_linha(row,30,8);
                        nota1 = stof(aux); // converte uma string para um float
                        aux = separa_linha(row,38,8);
                        nota2 = stof(aux);
                        aux = separa_linha(row,46,8);
                        nota3 = stof(aux);

                        if (((nota1+nota2+nota3)/3) > media_max){
                            media_max = (nota1+nota2+nota3)/3;
                            nome_max_nota = nome;
                        }

                        if (Entrada.eof())
                            break;
                        else
                            posicao++;
                    }

                    cout << "Aluno com maior nota media: " << nome_max_nota << " - Media: " << media_max << endl;
                    Entrada.close();

                    break;
                }
            
            case 'H':
                {
                    cout << "Busca por Alunos:" << endl;
                    int posicao = 1; // começa da 1 para pular o header
                    string nome, nome_busca, row;

                    cout << "Digite o nome completo do aluno que voce deseja encontra na lista de alunos cadastrados: ";
                    cin.ignore();
                    getline(cin,nome_busca);

                    Entrada.seekg(0);
                    while(true){

                        Entrada.seekg(posicao*(5 + 30 + 8 + 8 + 8 + 2) + 5);
                        getline(Entrada, row,'\n');

                        nome = separa_linha(row,0, 30);
                        // elimina a possibilidade do nome ter sido cadastrado com letras em maiusculo
                        nome = converte_para_minusculo(nome);
                        // nome_busca = converte_para_minusculo(nome_busca);

                        if (nome == converte_para_minusculo(nome_busca))
                            cout << "O nome " << nome_busca << " se encontra na lista de alunos cadastrados!" << endl;

                        if (Entrada.eof())
                            break;
                        else
                            posicao++;
                    }
                    
                    Entrada.close();

                    break;
                }

            default:
                cout << "Opção invalida!" << endl;
                return 0;
        };
    }
    
    return 0;
}


char gera_opcoes()
{
    char opcao;
    cout << "\n----------------- Opcoes: " << endl;

    cout << "Opcao A" << endl;
    cout << "Opcao B" << endl;
    cout << "Opcao C" << endl;
    cout << "Opcao D" << endl;
    cout << "Opcao E" << endl;
    cout << "Opcao F" << endl;
    cout << "Opcao G" << endl;
    cout << "Opcao H" << endl;

    cin >> opcao;
    return toupper(opcao);
}


string separa_linha(string row, int inicio, int tamanho)
{
    string aux;
    for (int i=inicio; i < (inicio+tamanho); i++){
        if (row[i] == ' ')
            if (row[i+1] == ' ')
                break;

        aux += row[i];
    }
    
    return aux;
}


string converte_para_minusculo(string nome)
{
    string aux;
    for(int i = 0; i < nome.length(); i++){
        if (nome[i] != ' ')
            aux += tolower(nome[i]);
        else
            aux += tolower(nome[i]);
    }

    return aux;
}