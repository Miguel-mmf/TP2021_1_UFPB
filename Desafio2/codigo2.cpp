#include <iostream>

using namespace std;

// questao2
    // classe televisao
    // controle da televisao para o volume +-, canal +- e alterar a entrada de vídeo que a televisao está conectada (HDMI 1 e 2 e antena)
    // quando estiver no HDMI 1 ou 2, não pode trocar de canal, mas pode aumentar ou diminuir o volume
    // ligar ou desligar a qualquer momento
    // volume aumentando 1 unidade por vez
    // 

class Televisao
{   
        bool ligado;
        int volume, canal, conexao;
        // conexao 1 = hdmi1
        // conexao 2 = hdmi2
        // conexao 3 = antena
    public:

        //configurações para ligada ou desligada
        Televisao(){
            ligado=false;
            volume=50;
            canal=1;
            conexao = 3;
        };

        void ligar_tv(){ligado=true;};
        void desligar_tv(){ligado=false;};

        void aumentar_canal(){
            if (ligado){
                if (conexao == 3) canal++;
            }
        };
        void diminuir_canal(){
            if (ligado){
                if (conexao == 3) canal--;
            }
        };
        void aumentar_volume(){
            if (ligado){
                if (volume < 100) volume++;
            }
        };
        void diminuir_volume(){
            if (ligado){
                if (volume > 0) volume--;
            }
        };
        void conexao_hdm1(){
            if (ligado) conexao=1;
        };
        void conexao_hdm2(){
            if (ligado) conexao=2;
        };
        void conexao_antena(){
            if (ligado) conexao=3;
        };

        void estado_tv(){
            if (ligado)
                cout << "TV ligada!"<< endl;
            else
                cout << "TV desligada!"<< endl;

            cout << "Canal: " << canal << endl;
            cout << "Volume atual: " << volume << endl;
            if (conexao == 1){
                cout << "Conexao: HDMI 1" << endl;
            } else if (conexao == 2){
                cout << "Conexao: HDMI 2" << endl;
            } else {
                cout << "Conexao: Antena" << endl;
            }
        }


};


int main()
{
    Televisao Tv;

    Tv.estado_tv();

    //conectar o hdmi1
    Tv.ligar_tv();
    Tv.conexao_hdm1();
    Tv.estado_tv();

    // aumentar canal no hdmi 1 impossivel
    Tv.aumentar_canal();
    Tv.estado_tv();

    // trocando para Antena
    Tv.conexao_antena();
    Tv.estado_tv();
    Tv.aumentar_canal();
    Tv.estado_tv();
    Tv.diminuir_volume();
    Tv.diminuir_canal();
    Tv.estado_tv();

    // volume no maximo
    for (int i = 0; i <= 50; i++){
        Tv.aumentar_volume();
    }
    Tv.estado_tv();

    Tv.aumentar_volume();
    Tv.estado_tv();

    return 0;
}