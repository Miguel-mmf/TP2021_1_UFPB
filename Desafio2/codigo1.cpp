#include <iostream>
#include <ctime>

using namespace std;

class Relogio
{
    //funções
    // variavel global como a hora
    //default: inicializar com a hr de agora
    // define hora
    // coletar a hora
    // avançar em min, seg ou h
        int fuso=0;
        //time_t timer;
    public:
        int hora, min, seg;

        Relogio(){
            time_t timer;
            struct tm*horarioLocal;

            time(&timer); // Obtem informações de data e hora
            horarioLocal = localtime(&timer); //
            hora = horarioLocal->tm_hour;
            min  = horarioLocal->tm_min;
            seg  = horarioLocal->tm_sec;
            //hora = h; min = m; seg = s;
        };

        void coleta_hora_atual(){
            cout << "Horario local: " << hora << "h" << min << "min" << seg << "s" << endl;
        };

        void define_hora(int h){
            fuso = h - hora;
            hora = h;
            cout << "Novo horario local: " << hora << "h" << min << "min" << seg << "s" << endl;
            cout << "Fuso horario: " << fuso << "h" << endl;
        };

        void avancar_hms(int h=0, int m=0, int s=0){
            hora += h;
            min += m;
            seg += s;
            cout << "Horario com avanco: " << hora << "h" << min << "min" << seg << "s" << endl;
        };
};


int main()
{
    Relogio Reg;

    Reg.coleta_hora_atual();

    Reg.define_hora(14);

    Reg.avancar_hms(2); // avanca 2h
    Reg.avancar_hms(0,2); // avanca 2min
    Reg.avancar_hms(0,0,20); // avanca 20s

    return 0;
}