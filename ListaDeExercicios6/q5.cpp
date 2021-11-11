#include <iostream>
#include <cmath>

using namespace std;

string validate_name(string n);
int validate_idade(int i);
float validate_cre(float cre);

class Aluno
{
    private:
        string name;
        int idade;
        float cre;


    public:
        void cadastro_aluno(string n, int i, float cra);//{
        //     name = Aluno::validate_name(n);
        //     idade = Aluno::validate_idade(i);
        //     cre = Aluno::validate_cre(cra);
        // }

        // string validate_name(string n){
        //     // valida caracter por caracter do nome enviado
        //     for(int i=0; i > 0;i++){
        //         if ((char(n[i])!=32) || ((char(n[i]) < 64) && (char(n[i]) > 90)) || ((char(n[i]) < 97) && (char(n[i]) > 122))){
        //             string nome_aluno;
        //             cout << "O nome possui caracteres invalidos" << endl;
        //             cout << "Digite o nome do aluno: ";
        //             cin >> nome_aluno;

        //             return Aluno::validate_name(nome_aluno);
        //         }
        //     }
        //     return n;
        // }

        // int validate_idade(int i){
        //     //validação da idade
        //     if (idade < 0 && idade > 125){
        //         int idade_aluno;
        //         cout << "Idade invalida!" << endl;
        //         cout << "Digite uma idade valida:";
        //         cin >> idade_aluno;

        //         return Aluno::validate_idade(idade_aluno);
        //     }
        //     return i;
        // }

        // float validate_cre(float cre){
        //     //validação do cre
        //     if (idade < 0 && idade > 10){
        //         float cre_aluno;
        //         cout << "CRE invalida!" << endl;
        //         cout << "Digite um CRE valido:";
        //         cin >> cre_aluno;

        //         return Aluno::validate_idade(cre_aluno);
        //     }
        //     return cre;
        // }

        string get_name(){return name;}
        int get_age(){return idade;}
        float get_cre(){return cre;}
};

void Aluno::cadastro_aluno(string n, int i, float cra){
    name = validate_name(n);
    idade = validate_idade(i);
    cre = validate_cre(cra);
}


int main()
{
    bool sair = false;
    string nome1,nome2;
    int idade1,idade2;
    float cre1, cre2;

    while(!sair){
        cout << "Digite o nome do primeiro aluno:";
        cin >> nome1;
        cout << "Digite a idade do primeiro aluno:";
        cin >> idade1;
        cout << "Digite o CRE do primeiro aluno:";
        cin >> cre1;

        Aluno aluno1;
        aluno1.cadastro_aluno(nome1,idade1,cre1);

        cout << "\nDigite o nome do segundo aluno:";
        cin >> nome2;
        cout << "Digite a idade do segundo aluno:";
        cin >> idade2;
        cout << "Digite o CRE do segundo aluno:";
        cin >> cre2;

        Aluno aluno2; //(nome2,idade2,cre2);
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

string validate_name(string n){
    // valida caracter por caracter do nome enviado
    for(int i=0; i > 0;i++){
        if ((char(n[i])!=32) || ((char(n[i]) < 64) && (char(n[i]) > 90)) || ((char(n[i]) < 97) && (char(n[i]) > 122))){
            string nome_aluno;
            cout << "O nome possui caracteres invalidos" << endl;
            cout << "Digite o nome do aluno: ";
            cin >> nome_aluno;

            return validate_name(nome_aluno);
        }
    }
    return n;
}

int validate_idade(int i){
    //validação da idade
    if (i < 0 && i > 125){
        int idade_aluno;
        cout << "Idade invalida!" << endl;
        cout << "Digite uma idade valida:";
        cin >> idade_aluno;

        return validate_idade(idade_aluno);
    }
    return i;
}

float validate_cre(float cre){
    //validação do cre
    if (cre < 0 && cre > 10){
        float cre_aluno;
        cout << "CRE invalida!" << endl;
        cout << "Digite um CRE valido:";
        cin >> cre_aluno;

        return validate_idade(cre_aluno);
    }
    return cre;
}