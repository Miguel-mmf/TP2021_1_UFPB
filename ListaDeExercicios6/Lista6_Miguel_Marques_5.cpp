#include <iostream>
#include <cmath>

using namespace std;

class Aluno
{
    private:
        string name;
        int idade;
        float cre;

    public:
        void cadastro_aluno(string n, int i, float cra){

            name = n;
            // valida caractere por caractere do nome enviado
            for(int i=0; i >= 0;i++){

                if (n[i]=='\0'){break;}

                if ((int(n[i]) > 90) && (int(n[i]) < 97)){
                    cout << "O nome possui caracteres invalidos!" << endl;
                    name = "Nome invalido";
                    break;
                }

                if (int(n[i]) > 122){
                    cout << "O nome possui caracteres invalidos!" << endl;
                    name = "Nome invalido";
                    break;
                }

                if (int(n[i])!=32 && (int(n[i]) < 65)){
                    cout << "O nome possui caracteres invalidos!" << endl;
                    name = "Nome invalido";
                    break;
                }
            }

            idade = i;
            //validação da idade
            if (i < 0 || i > 125){
                cout << "Idade invalida!" << endl;
                idade = 0;
            }

            cre = cra;
            //validação do cre
            if (cra < 0 || cra > 10){
                cout << "CRE invalida!" << endl;

                cre = int(NULL);
            }
        }

        string get_name(){return name;}
        int get_age(){return idade;}
        float get_cre(){return cre;}
};


int main()
{
    bool sair = false;
    string nome1,nome2;
    int idade1,idade2;
    float cre1, cre2;

    while(!sair){
        Aluno aluno1, aluno2;

        cout << "Digite o nome do primeiro aluno:";
        cin >> nome1;
        cout << "Digite a idade do primeiro aluno:";
        cin >> idade1;
        cout << "Digite o CRE do primeiro aluno:";
        cin >> cre1;

        aluno1.cadastro_aluno(nome1,idade1,cre1);

        cout << "\nDigite o nome do segundo aluno:";
        cin >> nome2;
        cout << "Digite a idade do segundo aluno:";
        cin >> idade2;
        cout << "Digite o CRE do segundo aluno:";
        cin >> cre2;

        aluno2.cadastro_aluno(nome2,idade2,cre2);

        cout << "\nNome do aluno 1: " << aluno1.get_name() << endl;
        cout << "Idade do aluno 1: " << aluno1.get_age() << endl;
        cout << "CRE do aluno 1: " << aluno1.get_cre() << endl;

        cout << "\nNome do aluno 2: " << aluno2.get_name() << endl;
        cout << "Idade do aluno 2: " << aluno2.get_age() << endl;
        cout << "CRE do aluno 2: " << aluno2.get_cre() << endl;

        cout << "\nDeseja cadastrar novos alunos (1- sim, 2- nao): ";
        cin >> sair;
        if(sair == true){sair = false;} else{break;};
    }

    return 0;
}