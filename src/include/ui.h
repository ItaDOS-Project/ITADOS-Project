/// UI.H - MODULO DE INTERFACE DO USUARIO
/// Todas as funcoes de impressao de telas e interface grafica

#ifndef UI_H
#define UI_H

#include <iostream>
#include <string>
#include <windows.h>
#include "console.h"
using namespace std;

char q = 219;

/// FUNCOES DE IMPRESSAO DE MENSAGENS

void MsgErrCopiarInv () {
    gotoxy (32,8);
    cout << "_________________________" ;
    gotoxy (32,9);
    cout << "|                       |" ;
    gotoxy (32,10);
    cout << "|   /\\   O ARQUIVO NAO  |" ;
    gotoxy (32,11);
    cout << "|  /! \\     PODE SER    |" ;
    gotoxy (32,12);
    cout << "| /____\\ COPIADO PARA   |" ;
    gotoxy (32,13);
    cout << "|        ESTE DESTINO   |" ;
    gotoxy (32,14);
    cout << "|                       |" ;
    gotoxy (32,15);
    cout << "|_______________________|" ;
    Sleep (2500);
    system ("cls");
}

void ConfirmSaveDraw () {
    gotoxy (32,8);
    cout << "_________________________" ;
    gotoxy (32,9);
    cout << "|        SALVAR PINTURA |" ;
    gotoxy (32,10);
    cout << "|        ATUAL?         |" ;
    gotoxy (32,11);
    cout << "| ( ? )  (TECLAR S/N)   |" ;
    gotoxy (32,12);
    cout << "|   _______   ______    |" ;
    gotoxy (32,13);
    cout << "|   | SIM  |  | NAO |   |" ;
    gotoxy (32,14);
    cout << "|   |______|  |_____|   |" ;
    gotoxy (32,15);
    cout << "|_______________________|" ;
}

void SelecArquivoLoad () {
    gotoxy (32,8);
    cout << "_________________________" ;
    gotoxy (32,9);
    cout << "|  POR FAVOR, DIGITE O  |" ;
    gotoxy (32,10);
    cout << "|  NOME DO ARQUIVO QUE  |" ;
    gotoxy (32,11);
    cout << "| DESEJA ABRIR          |" ;
    gotoxy (32,12);
    cout << "|   ________________    |" ;
    gotoxy (32,13);
    cout << "|   |               |   |" ;
    gotoxy (32,14);
    cout << "|   |_______________|   |" ;
    gotoxy (32,15);
    cout << "|_______________________|" ;
}

void SelectProgramaExec () {
    gotoxy (32,8);
    cout << "_________________________" ;
    gotoxy (32,9);
    cout << "|  POR FAVOR, DIGITE O  |" ;
    gotoxy (32,10);
    cout << "|  NOME DO PROGRAMA QUE |" ;
    gotoxy (32,11);
    cout << "| DESEJA EXECUTAR       |" ;
    gotoxy (32,12);
    cout << "|   ________________    |" ;
    gotoxy (32,13);
    cout << "|   |               |   |" ;
    gotoxy (32,14);
    cout << "|   |_______________|   |" ;
    gotoxy (32,15);
    cout << "|_______________________|" ;
}

void PrintaCalc () {
    extern char q;
    gotoxy (33,5);
    Cor (105);
    cout << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q ;
    gotoxy (33,6);

    cout << "                         ";
    gotoxy (33,7);
    cout << "    "; Cor (240); cout << "                  "; Cor (105); cout << " ";
    gotoxy (33,8);
    cout << "                         ";
    gotoxy (33,9);
    cout << "                         ";
    gotoxy (33,10);
    cout << "                         ";
    gotoxy (33,11);
    cout << "                         ";
    gotoxy (33,12);
    cout << "                         ";
    gotoxy (33,13);
    cout << "                         "; // 37.7 a 56.7
    gotoxy (33,14);
    cout << "                         ";
    gotoxy (33,15);
    cout << "                         ";
    gotoxy (33,16);
    cout << "                         ";
    gotoxy (33,17);
    cout << "                         ";
    gotoxy (33,18);
    cout << "                         ";
    gotoxy (33,19);
    cout << "                         ";
    gotoxy (33,20);
    cout << "                         ";
    gotoxy (33,21);
    cout << "                         ";
    Cor (240); /// RESETA A COR BRANCO/PRETO
}

/// FUNCOES DE TELAS PRINCIPAIS

void SetTimeScreen () {
    system ("cls");
    cout<<"|______________________________________________________|||||||||||||||||_________________________ |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                       ______    |"<<endl;
    cout<<"|                                                                                       |>   |    |"<<endl;
    cout<<"|                                                                                       |    |    |"<<endl;
    cout<<"|                                                                                       |    |    |"<<endl;
    cout<<"|                                                                                       ______    |"<<endl;
    cout<<"|                                                                                        Dos      |"<<endl;
    cout<<"|                                _______________________________                                  |"<<endl;
    cout<<"|                               | SET TIME/DATE                 |                       ____-_    |"<<endl;
    cout<<"|                               |                               |                       |    |    |"<<endl;
    cout<<"|                               |                               |                       |    |    |"<<endl;
    cout<<"|                               |                               |                       ______    |"<<endl;
    cout<<"|                               |                               |                   Meus Arquivos |"<<endl;
    cout<<"|                               |_______________________________|                                 |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|            __o__                                                                                |"<<endl;
    cout<<"|            |   |                                                                                |"<<endl;
    cout<<"|            |   |                                                                                |"<<endl;
    cout<<"|            |   |                                                                                |"<<endl;
    cout<<"|            |___|                                                                                |"<<endl;
    cout<<"|            Lixo                                                                                 |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"__________________________________________________________________________________________________"<<endl;
}

void TelaPrincipal () {
    cout<<"__________________________________________________________________________________________________ "<<endl;
    cout<<"| Itac   | Arquivo | Editar | Disco     | Visualizar   | Configuracoes |                         | "<<endl;
    cout<<"_________________________________________________________________________________________________  "<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                       ______    |"<<endl;
    cout<<"|  _______                                                                              |>   |    |"<<endl;
    cout<<"|  |o    |                                                                              |    |    |"<<endl;
    cout<<"|  |_____|                                                                              |    |    |"<<endl;
    cout<<"|  v     v                                                                              |____|    |"<<endl;
    cout<<"|  Itac HD                                                                               Dos      |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|  _____                                                                                ____-_    |"<<endl;
    cout<<"|  |   |                                                                                |    |    |"<<endl;
    cout<<"|  | O  |                                                                               |____|    |"<<endl;
    cout<<"|  |___E|                                                                                         |"<<endl;
    cout<<"|                                                                                   Meus Arquivos |"<<endl;
    cout<<"|    A:                                                                                           |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|  _____     __o__                                                                                |"<<endl;
    cout<<"|  |   |     |   |                                                                                |"<<endl;
    cout<<"|  | O  |    |   |                                                                                |"<<endl;
    cout<<"|  |___E|    |___|                                                                                |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|    B:      Lixo                                                                                 |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"__________________________________________________________________________________________________"<<endl;
}

void Tela_MenuPrincipal () {
    cout<<"__________________________________________________________________________________________________ "<<endl;
    cout<<"||Itac|||| Arquivo | Editar | Disco     | Visualizar   | Configuracoes |                          | "<<endl;
    cout<<"||||||||||_______________________________________________________________________________________ | "<<endl;
    cout<<"|ITAC Info    PNM   |                                                                             |"<<endl;
    cout<<"|ITADOS Info  RET   |                                                                   ______    |"<<endl;
    cout<<"|Select Imput ALT+N |                                                                   |>   |    |"<<endl;
    cout<<"|Select Printer     |                                                                   |    |    |"<<endl;
    cout<<"|Load...            |                                                                   |____|    |"<<endl;
    cout<<"|Pad Color mgr 3.0  |                                                                             |"<<endl;
    cout<<"|Echo cmd           |                                                                    Dos      |"<<endl;
    cout<<"|_====EXIT====______|                                                                             |"<<endl;
    cout<<"|   ___                                                                                 ____-_    |"<<endl;
    cout<<"|  |   |                                                                                |    |    |"<<endl;
    cout<<"|  | O  |                                                                               |____|    |"<<endl;
    cout<<"|  |___E|                                                                                         |"<<endl;
    cout<<"|                                                                                   Meus Arquivos |"<<endl;
    cout<<"|    A:                                                                                           |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|   ___      __o__                                                                                |"<<endl;
    cout<<"|  |   |     |   |                                                                                |"<<endl;
    cout<<"|  | O  |    |   |                                                                                |"<<endl;
    cout<<"|  |___E|    |___|                                                                                |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|    B:      Lixo                                                                                 |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"__________________________________________________________________________________________________"<<endl;
}

void Tela_Info () {
    cout<<"|_________________________________________________________________________________________________| "<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                       ______    |"<<endl;
    cout<<"|  _______                                                                              |>   |    |"<<endl;
    cout<<"|  |o    |                                                                              |    |    |"<<endl;
    cout<<"|  _______                                                                              |    |    |"<<endl;
    cout<<"|  v     v                                                                              ______    |"<<endl;
    cout<<"|  Itac HD                      ____________________________                             Dos      |"<<endl;
    cout<<"|                              |                            |                                     |"<<endl;
    cout<<"|  _____                       |  ITADOS V 1.3 BY ARUNI     |                           ____-_    |"<<endl;
    cout<<"|  |   |                       |    AMSTEL COPYLEFT (C)     |                           |    |    |"<<endl;
    cout<<"|  | O  |                      |     ITAC INC. 2017         |                           |    |    |"<<endl;
    cout<<"|  |   E|                      |   ________                 |                           ______    |"<<endl;
    cout<<"|  ______                      |  ||CLOSE|||                |                       Meus Arquivos |"<<endl;
    cout<<"|    A:                        |____________________________|                                     |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|  _____     __o__                                                                                |"<<endl;
    cout<<"|  |   |     |||||                                                                                |"<<endl;
    cout<<"|  | O  |    |||||                                                                                |"<<endl;
    cout<<"|  |   E|    |||||                                                                                |"<<endl;
    cout<<"|  ______    Lixo                                                                                 |"<<endl;
    cout<<"|    B:                                                                                           |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"__________________________________________________________________________________________________"<<endl;
}

void Tela_DOS () {
    cout<<" _________________________________________________________________________________________________ "<<endl;
    cout<<"| Itac   | Arquivo | Editar | Disco     | Visualizar   | Configuracoes |                          |"<<endl;
    cout<<"|_________________________________________________________________________________________________|"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                        ____     |"<<endl;
    cout<<"|  _______                                                                              |>   |    |"<<endl;
    cout<<"|  |o   =|                _______________________________________________               |    |    |"<<endl;
    cout<<"|  |_____|               | c:> DOS                                     |X|              |____|    |"<<endl;
    cout<<"|  v     v               |-----------------------------------------------|                        |"<<endl;
    cout<<"|  Itac HD               | c:>                                           |               Dos      |"<<endl;
    cout<<"|                        |                                               |                        |"<<endl;
    cout<<"|   ____                 |                                               |               ___=_    |"<<endl;
    cout<<"|  |   |_                |                                               |              |    |    |"<<endl;
    cout<<"|  | O  |                |                                               |              |____|    |"<<endl;
    cout<<"|  |___A|                |                                               |              ______    |"<<endl;
    cout<<"|                        |                                               |          Meus Arquivos |"<<endl;
    cout<<"|    A:                  |                                               |                        |"<<endl;
    cout<<"|                        |                                               |                        |"<<endl;
    cout<<"|   ____     __=__       |                                               |                        |"<<endl;
    cout<<"|  |   |_    |   |       |                                               |                        |"<<endl;
    cout<<"|  | O  |    |   |       |                                               |                        |"<<endl;
    cout<<"|  |___B|    |___|       |                                               |                        |"<<endl;
    cout<<"|                        |_______________________________________________|                        |"<<endl;
    cout<<"|    B:      Lixo                                                                                 |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"__________________________________________________________________________________________________"<<endl;
}

void Tela_Lixeira () {
    cout<<"__________________________________________________________________________________________________ "<<endl;
    cout<<"| Itac   | Arquivo | Editar | Disco     | Visualizar   | Configuracoes |                          | "<<endl;
    cout<<"|_________________________________________________________________________________________________| "<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                       ______    |"<<endl;
    cout<<"|  _______                                                                              |>   |    |"<<endl;
    cout<<"|  |o    |                                                                              |    |    |"<<endl;
    cout<<"|  _______                                                                              |    |    |"<<endl;
    cout<<"|  v     v                                                                              ______    |"<<endl;
    cout<<"|  Itac HD                      ____________________________                             Dos      |"<<endl;
    cout<<"|                              |                            |                                     |"<<endl;
    cout<<"|  ______                      |  A LIXEIRA SO ABRE         |                           ____-_    |"<<endl;
    cout<<"|  |   |                       |    QUANDO HA ARQUIVOS      |                           |    |    |"<<endl;
    cout<<"|  | O  |                      |       DELETADOS            |                           |____|    |"<<endl;
    cout<<"|  |   E|                      |   ________                 |                                     |"<<endl;
    cout<<"|  ______                      |  |_CLOSE__|                |                       Meus Arquivos |"<<endl;
    cout<<"|    A:                        |____________________________|                                     |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|  ______    __o__                                                                                |"<<endl;
    cout<<"|  |   |     |||||                                                                                |"<<endl;
    cout<<"|  | O  |    |||||                                                                                |"<<endl;
    cout<<"|  |   E|    |||||                                                                                |"<<endl;
    cout<<"|  ______    Lixo                                                                                 |"<<endl;
    cout<<"|    B:                                                                                           |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"__________________________________________________________________________________________________"<<endl;
}

void Tela_MenuDisco () {
    cout<<"|___________________________|||||||||||||||______________________________________________________ | "<<endl;
    cout<<"|                           |DISKCOPY  ALT+C  |                                                   |"<<endl;
    cout<<"|                           |DUPLICATE        |                                         ______    |"<<endl;
    cout<<"|                           |COPY TO RAM/UNF. |                                         |>   |    |"<<endl;
    cout<<"|                           |FORMAT    ALT+F  |                                         |    |    |"<<endl;
    cout<<"|                           |INFO...          |                                         |    |    |"<<endl;
    cout<<"|                           |_______EXIT______|                                         ______    |"<<endl;
    cout<<"|                                                                                        Dos      |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|  _____                                                                                ____-_    |"<<endl;
    cout<<"|  |   |                                                                                |    |    |"<<endl;
    cout<<"|  | O  |                                                                               |    |    |"<<endl;
    cout<<"|  |___E|                                                                               ______    |"<<endl;
    cout<<"|                                                                                   Meus Arquivos |"<<endl;
    cout<<"|    A:                                                                                           |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|  _____     __o__                                                                                |"<<endl;
    cout<<"|  |   |     |   |                                                                                |"<<endl;
    cout<<"|  | O  |    |   |                                                                                |"<<endl;
    cout<<"|  |___E|    |___|                                                                                |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|    B:      Lixo                                                                                 |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"__________________________________________________________________________________________________"<<endl;
}

void Tela_MenuArquivo () {
    cout<<"|_________|||||||||||____________________________________________________________________________ | "<<endl;
    cout<<"|         |COPIAR ALT+C     |                                                                     |"<<endl;
    cout<<"|         |MOVER ALT+PNM    |                                                         ______    |"<<endl;
    cout<<"|         |DELETAR DEL      |                                                           |>   |    |"<<endl;
    cout<<"|         |RENOMERAR ALT+RET|                                                           |    |    |"<<endl;
    cout<<"|         |INFO...          |                                                           |    |    |"<<endl;
    cout<<"|         |_______EXIT______|                                                           ______    |"<<endl;
    cout<<"|                                                                                        Dos      |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|  _____                                                                                ____-_    |"<<endl;
    cout<<"|  |   |                                                                                |    |    |"<<endl;
    cout<<"|  | O  |                                                                               |____|    |"<<endl;
    cout<<"|  |___E|                                                                                         |"<<endl;
    cout<<"|                                                                                   Meus Arquivos |"<<endl;
    cout<<"|    A:                                                                                           |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|  _____     __o__                                                                                |"<<endl;
    cout<<"|  |   |     |   |                                                                                |"<<endl;
    cout<<"|  | O  |    |   |                                                                                |"<<endl;
    cout<<"|  |___E|    |___|                                                                                |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|    B:      Lixo                                                                                 |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"__________________________________________________________________________________________________"<<endl;
}

void Tela_MenuView () {
    cout<<"|_______________________________________||||||||||||||||_________________________________________ | "<<endl;
    cout<<"|                                       |  VIEW AS ICONS  |                                       |"<<endl;
    cout<<"|                                       |  VIEW AS LIST   |                             ______    |"<<endl;
    cout<<"|                                       |  VIEW AS BLOCKS |                             |>   |    |"<<endl;
    cout<<"|                                       |* WINDOW         |                             |    |    |"<<endl;
    cout<<"|                                       |  FULLSCREEN     |                             |    |    |"<<endl;
    cout<<"|                                       |_______EXIT______|                             ______    |"<<endl;
    cout<<"|                                                                                        Dos      |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|   ___                                                                                 ____-_    |"<<endl;
    cout<<"|  |   |                                                                                |    |    |"<<endl;
    cout<<"|  | O  |                                                                               |    |    |"<<endl;
    cout<<"|  |___E|                                                                               ______    |"<<endl;
    cout<<"|                                                                                   Meus Arquivos |"<<endl;
    cout<<"|    A:                                                                                           |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|   ___      __o__                                                                                |"<<endl;
    cout<<"|  |   |     |   |                                                                                |"<<endl;
    cout<<"|  | O  |    |   |                                                                                |"<<endl;
    cout<<"|  |___E|    |___|                                                                                |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|    B:      Lixo                                                                                 |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"__________________________________________________________________________________________________"<<endl;
}

void Tela_ITACHD () {
    cout<<" _________________________________________________________________________________________________ "<<endl;
    cout<<"| Itac   | Arquivo | Editar | Disco     | Visualizar   | Configuracoes |                          |"<<endl;
    cout<<"|_________________________________________________________________________________________________|"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                        ____     |"<<endl;
    cout<<"|  _______                                                                              |>   |    |"<<endl;
    cout<<"|  |o   =|                _______________________________________________               |    |    |"<<endl;
    cout<<"|  |_____|               | ITAC HD_/                               |-|O|X|              |____|    |"<<endl;
    cout<<"|  v     v               |-----------------------------------------------|                        |"<<endl;
    cout<<"|  Itac HD               |  ___=_   ___=_   ___=_  |||||      |||||      |               Dos      |"<<endl;
    cout<<"|                        | |    |  |    |  |    |  |TXT|      |   |      |                        |"<<endl;
    cout<<"|   ____                 | |____|  |____|  |____|  |||||      |||||      |               ___=_    |"<<endl;
    cout<<"|  |   |_                |  ITAC    TOOLS   ADMIN  README.TXT ITADOSGRAPH|              |    |    |"<<endl;
    cout<<"|  | O  |                | |||||                                         |              |____|    |"<<endl;
    cout<<"|  |___A|                | |SYS|                                         |                        |"<<endl;
    cout<<"|                        | |||||                                         |          Meus Arquivos |"<<endl;
    cout<<"|    A:                  | ITADOS.SYS                                    |                        |"<<endl;
    cout<<"|                        |                                               |                        |"<<endl;
    cout<<"|   ____     __=__       |                                               |                        |"<<endl;
    cout<<"|  |   |_    |   |       |                                               |                        |"<<endl;
    cout<<"|  | O  |    |   |       |                                               |                        |"<<endl;
    cout<<"|  |___B|    |___|       |                                               |                        |"<<endl;
    cout<<"|                        |_______________________________________________|                        |"<<endl;
    cout<<"|    B:      Lixo                                                                                 |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"__________________________________________________________________________________________________"<<endl;
}

void Tela_NaoHaDiscos () {
    cout<<"|_________________________________________________________________________________________________| "<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                       ______    |"<<endl;
    cout<<"|  _______                                                                              |>   |    |"<<endl;
    cout<<"|  |o    |                                                                              |    |    |"<<endl;
    cout<<"|  _______                                                                              |    |    |"<<endl;
    cout<<"|  v     v                                                                              ______    |"<<endl;
    cout<<"|  Itac HD                      ____________________________                             Dos      |"<<endl;
    cout<<"|                              |                            |                                     |"<<endl;
    cout<<"|  _____                       |  NENHUMA UNIDADE DE        |                           ____-_    |"<<endl;
    cout<<"|  |   |                       |    DISKETE INSERIDO NO     |                           |    |    |"<<endl;
    cout<<"|  | O  |                      |       DRIVE B:             |                           |    |    |"<<endl;
    cout<<"|  |   E|                      |   ________                 |                           ______    |"<<endl;
    cout<<"|  ______                      |  ||CLOSE|||                |                       Meus Arquivos |"<<endl;
    cout<<"|    A:                        |____________________________|                                     |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|  _____     __o__                                                                                |"<<endl;
    cout<<"|  |   |     |||||                                                                                |"<<endl;
    cout<<"|  | O  |    |||||                                                                                |"<<endl;
    cout<<"|  |   E|    |||||                                                                                |"<<endl;
    cout<<"|  ______    Lixo                                                                                 |"<<endl;
    cout<<"|    B:                                                                                           |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"__________________________________________________________________________________________________"<<endl;
}

void Tela_DiscoAVazio () {
    cout<<" _________________________________________________________________________________________________ "<<endl;
    cout<<"| Itac   | Arquivo | Editar | Disco     | Visualizar   | Configuracoes |                          |"<<endl;
    cout<<"|_________________________________________________________________________________________________|"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                        ____     |"<<endl;
    cout<<"|  _______                                                                              |>   |    |"<<endl;
    cout<<"|  |o   =|                _______________________________________________               |    |    |"<<endl;
    cout<<"|  |_____|               | DISCO A VAZIO                           |-|O|X|              |____|    |"<<endl;
    cout<<"|  v     v               |-----------------------------------------------|                        |"<<endl;
    cout<<"|  Itac HD               |                                           |               Dos      |"<<endl;
    cout<<"|                        |                                           |                        |"<<endl;
    cout<<"|   ____                 |                                           |               ___=_    |"<<endl;
    cout<<"|  |   |_                |                                           |              |    |    |"<<endl;
    cout<<"|  | O  |                |                                           |              |____|    |"<<endl;
    cout<<"|  |___A|                |                                           |              ______    |"<<endl;
    cout<<"|                        |                                           |          Meus Arquivos |"<<endl;
    cout<<"|    A:                  |                                           |                        |"<<endl;
    cout<<"|                        |                                           |                        |"<<endl;
    cout<<"|   ____     __=__       |                                           |                        |"<<endl;
    cout<<"|  |   |_    |   |       |                                           |                        |"<<endl;
    cout<<"|  | O  |    |   |       |                                           |                        |"<<endl;
    cout<<"|  |___B|    |___|       |                                           |                        |"<<endl;
    cout<<"|                        |_______________________________________________|                        |"<<endl;
    cout<<"|    B:      Lixo                                                                                 |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"__________________________________________________________________________________________________"<<endl;
}

void Tela_DiscoA_Default () {
    cout<<" _________________________________________________________________________________________________ "<<endl;
cout<<"| Itac   | Arquivo | Editar | Disco     | Visualizar   | Configuracoes |                          |"<<endl;
cout<<"|_________________________________________________________________________________________________|"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                        ____     |"<<endl;
cout<<"|  _______                                                                              |>   |    |"<<endl;
cout<<"|  |o   =|                _______________________________________________               |    |    |"<<endl;
cout<<"|  |_____|               | A:                                      |-|O|X|              |____|    |"<<endl;
cout<<"|  v     v               |-----------------------------------------------|                        |"<<endl;
cout<<"|  Itac HD               |  ___=_   ___=_   ___=_  |||||       ___=_     |               Dos      |"<<endl;
cout<<"|                        | |    |  |    |  |    |  |TXT|      |    |     |                        |"<<endl;
cout<<"|   ____                 | |____|  |____|  |____|  |||||      |____|     |               ___=_    |"<<endl;
cout<<"|  |   |_                |DOS APPS  DK VOL  DOCS   DISK.TXT   ASM X86    |              |    |    |"<<endl;
cout<<"|  | O  |                | |||||                                         |              |____|    |"<<endl;
cout<<"|  |___A|                | |APP|                                         |                        |"<<endl;
cout<<"|                        | |||||                                         |          Meus Arquivos |"<<endl;
cout<<"|    A:                  | ITATEXTO                                      |                        |"<<endl;
cout<<"|                        | |||||           |||||                         |                        |"<<endl;
cout<<"|   ____     __=__       | |APP|           |   |                         |                        |"<<endl;
cout<<"|  |   |_    |   |       | |||||           |||||                         |                        |"<<endl;
cout<<"|  | O  |    |   |       | ITADRAW       CALCULADORA                     |                        |"<<endl;
cout<<"|  |___B|    |___|       |                                               |                        |"<<endl;
cout<<"|                        |_______________________________________________|                        |"<<endl;
cout<<"|    B:      Lixo                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"__________________________________________________________________________________________________"<<endl;
}

void Tela_DiscoB () {
    cout<<" _________________________________________________________________________________________________ "<<endl;
    cout<<"| Itac   | Arquivo | Editar | Disco     | Visualizar   | Configuracoes |                          |"<<endl;
    cout<<"|_________________________________________________________________________________________________|"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                        ____     |"<<endl;
    cout<<"|  _______                                                                              |>   |    |"<<endl;
    cout<<"|  |o   =|                _______________________________________________               |    |    |"<<endl;
    cout<<"|  |_____|               | DISCO B (FLOPPY)                    |-|O|X|              |____|    |"<<endl;
    cout<<"|  v     v               |-----------------------------------------------|                        |"<<endl;
    cout<<"|  Itac HD               |                                           |               Dos      |"<<endl;
    cout<<"|                        |                                           |                        |"<<endl;
    cout<<"|   ____                 |                                           |               ___=_    |"<<endl;
    cout<<"|  |   |_                |                                           |              |    |    |"<<endl;
    cout<<"|  | O  |                |                                           |              |____|    |"<<endl;
    cout<<"|  |___A|                |                                           |              ______    |"<<endl;
    cout<<"|                        |                                           |          Meus Arquivos |"<<endl;
    cout<<"|    A:                  |                                           |                        |"<<endl;
    cout<<"|                        |                                           |                        |"<<endl;
    cout<<"|   ____     __=__       |                                           |                        |"<<endl;
    cout<<"|  |   |_    |   |       |                                           |                        |"<<endl;
    cout<<"|  | O  |    |   |       |                                           |                        |"<<endl;
    cout<<"|  |___B|    |___|       |                                           |                        |"<<endl;
    cout<<"|                        |_______________________________________________|                        |"<<endl;
    cout<<"|    B:      Lixo                                                                                 |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"__________________________________________________________________________________________________"<<endl;
}

void Tela_SelecionarDisco () {
    cout<<"|_________________________________________________________________________________________________| "<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                       ______    |"<<endl;
    cout<<"|  _______                                                                              |>   |    |"<<endl;
    cout<<"|  |o    |                                                                              |    |    |"<<endl;
    cout<<"|  _______                                                                              |    |    |"<<endl;
    cout<<"|  v     v                                                                              ______    |"<<endl;
    cout<<"|  Itac HD                      ____________________________                             Dos      |"<<endl;
    cout<<"|                              |                            |                                     |"<<endl;
    cout<<"|  _____                       |  SELECIONE UM DISCO:       |                           ____-_    |"<<endl;
    cout<<"|  |   |                       |  A                         |                           |    |    |"<<endl;
    cout<<"|  | O  |                      |  B                         |                           |____|    |"<<endl;
    cout<<"|  |   E|                      |   ________                 |                                     |"<<endl;
    cout<<"|  ______                      |  ||CANCEL||                |                       Meus Arquivos |"<<endl;
    cout<<"|    A:                        |____________________________|                                     |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|  _____     __o__                                                                                |"<<endl;
    cout<<"|  |   |     |||||                                                                                |"<<endl;
    cout<<"|  | O  |    |||||                                                                                |"<<endl;
    cout<<"|  |   E|    |||||                                                                                |"<<endl;
    cout<<"|  ______    Lixo                                                                                 |"<<endl;
    cout<<"|    B:                                                                                           |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"__________________________________________________________________________________________________"<<endl;
}

void Tela_Itadraw () {
     cout<<"__________________________________________________________________________________________________ "<<endl;
cout<<"| ITADRAW | ARQUIVO | EDITAR | FERRAMENTAS | VISUALIZAR  | CONFIGURACOES | DESFAZER | SAIR | SAVE | "<<endl;
cout<<"_________________________________________________________________________________________________  "<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|_________________________________________________________________________________________________|"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"__________________________________________________________________________________________________"<<endl;
}

void Tela_PastaTools () {
    cout<<"|_________________________________________________________________________________________________| "<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                       ______    |"<<endl;
    cout<<"|  _______                                                                              |>   |    |"<<endl;
    cout<<"|  |o    |                                                                              |    |    |"<<endl;
    cout<<"|  _______                                                                              |    |    |"<<endl;
    cout<<"|  v     v                                                                              ______    |"<<endl;
    cout<<"|  Itac HD                      ____________________________                             Dos      |"<<endl;
    cout<<"|                              |                            |                                     |"<<endl;
    cout<<"|  _____                       |  FERRAMENTAS DO SISTEMA    |                           ____-_    |"<<endl;
    cout<<"|  |   |                       |                            |                           |    |    |"<<endl;
    cout<<"|  | O  |                      |  [1] MOUSE SETTINGS        |                           |____|    |"<<endl;
    cout<<"|  |   E|                      |  [2] SOUND                 |                                     |"<<endl;
    cout<<"|  ______                      |  ||BACK||                  |                       Meus Arquivos |"<<endl;
    cout<<"|    A:                        |____________________________|                                     |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|  _____     __o__                                                                                |"<<endl;
    cout<<"|  |   |     |||||                                                                                |"<<endl;
    cout<<"|  | O  |    |||||                                                                                |"<<endl;
    cout<<"|  |   E|    |||||                                                                                |"<<endl;
    cout<<"|  ______    Lixo                                                                                 |"<<endl;
    cout<<"|    B:                                                                                           |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"__________________________________________________________________________________________________"<<endl;
}

void Tela_DeskColor () {
    cout<<"|_________________________________________________________________________________________________| "<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                       ______    |"<<endl;
    cout<<"|  _______                                                                              |>   |    |"<<endl;
    cout<<"|  |o    |                                                                              |    |    |"<<endl;
    cout<<"|  _______                                                                              |    |    |"<<endl;
    cout<<"|  v     v                                                                              ______    |"<<endl;
    cout<<"|  Itac HD                      ____________________________                             Dos      |"<<endl;
    cout<<"|                              |                            |                                     |"<<endl;
    cout<<"|  _____                       |  DESK COLOR MANAGER 3.0    |                           ____-_    |"<<endl;
    cout<<"|  |   |                       |                            |                           |    |    |"<<endl;
    cout<<"|  | O  |                      |  FONTE: [          ]       |                           |____|    |"<<endl;
    cout<<"|  |   E|                      |  FUNDO: [          ]       |                                     |"<<endl;
    cout<<"|  ______                      |  ||APPLY|| ||CANCEL||      |                       Meus Arquivos |"<<endl;
    cout<<"|    A:                        |____________________________|                                     |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|  _____     __o__                                                                                |"<<endl;
    cout<<"|  |   |     |||||                                                                                |"<<endl;
    cout<<"|  | O  |    |||||                                                                                |"<<endl;
    cout<<"|  |   E|    |||||                                                                                |"<<endl;
    cout<<"|  ______    Lixo                                                                                 |"<<endl;
    cout<<"|    B:                                                                                           |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"__________________________________________________________________________________________________"<<endl;
}

void Tela_Configuracoes_Input () {
cout<<"__________________________________________________________________________________________________ "<<endl;
cout<<"| Itac   | Arquivo | Editar | Disco     | Visualizar   | Configuracoes |                         | "<<endl;
cout<<"_________________________________________________________________________________________________  "<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                       ______    |"<<endl;
cout<<"|  _______               ________________________________________________               |>   |    |"<<endl;
cout<<"|  |o    |              |                                                |              |    |    |"<<endl;
cout<<"|  _______              |  SET        * INPUT *                          |              |    |    |"<<endl;
cout<<"|  v     v              |   ___________                    ________      |              ______    |"<<endl;
cout<<"|  Itac HD              |  | PRINTER   |     SERIAL PRL   |  13.5  |     |               Dos      |"<<endl;
cout<<"|                       |   -----------                    --------      |                        |"<<endl;
cout<<"|  _____                |   ___________                    ________      |              ____-_    |"<<endl;
cout<<"|  |   |                |  | DISKDRIVE |     ACS / MODE   |  FAST  |     |              |    |    |"<<endl;
cout<<"|  | O  |               |   -----------                    --------      |              |    |    |"<<endl;
cout<<"|  |   E|               |   ___________                    ________      |              ______    |"<<endl;
cout<<"|  ______               |  | JOYSTICK  |     DRV CLCK     |  OFF   |     |          Meus Arquivos |"<<endl;
cout<<"|    A:                 |   -----------                    --------      |                        |"<<endl;
cout<<"|                       |   ___________                                  |                        |"<<endl;
cout<<"|  _____     __o__      |  |  OTHER... |          _________   _______    |                        |"<<endl;
cout<<"|  |   |     |   |      |   -----------          | CANCEL  | | DONE  |   |                        |"<<endl;
cout<<"|  | O  |    |   |      |________________________________________________|                        |"<<endl;
cout<<"|  |   E|    |   |                                                                                |"<<endl;
cout<<"|  ______    _____                                                                                |"<<endl;
cout<<"|    B:      Lixo                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"__________________________________________________________________________________________________"<<endl;
}

void Tela_Preferencias () {
    cout<<"|______________________________________________________|||||||||||||||||_________________________ |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                       ______    |"<<endl;
cout<<"|  _______               ________________________________________________               |>   |    |"<<endl;
cout<<"|  |o    |              |                                                |              |    |    |"<<endl;
cout<<"|  _______              |          *** SYSTEM PREFERENCES ***            |              |    |    |"<<endl;
cout<<"|  v     v              |   ___________                    ________      |              ______    |"<<endl;
cout<<"|  Itac HD              |  | SET CLOCK |     MOUSE DELAY  |     S  |     |               Dos      |"<<endl;
cout<<"|                       |   -----------                    --------      |                        |"<<endl;
cout<<"|   ___                 |   ___________                    ________      |              ____-_    |"<<endl;
cout<<"|  |   |                |  | DESK COLOR|     KEYBOARD SCT |        |     |              |    |    |"<<endl;
cout<<"|  | O  |               |   -----------                    --------      |              |    |    |"<<endl;
cout<<"|  |___E|               |   ___________                    ________      |              ______    |"<<endl;
cout<<"|                       |  | CONSOLE   |     FILE CONFIRM |  OFF   |     |          Meus Arquivos |"<<endl;
cout<<"|    A:                 |   -----------                    --------      |                        |"<<endl;
cout<<"|                       |   ___________                                  |                        |"<<endl;
cout<<"|   ___      __o__      |  |  OTHER... |  ______  _________   _______    |                        |"<<endl;
cout<<"|  |   |     |   |      |   -----------  |RESET || CANCEL  | | SAVE  |   |                        |"<<endl;
cout<<"|  | O  |    |   |      |________________________________________________|                        |"<<endl;
cout<<"|  |___E|    |___|                                                                                |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|    B:      Lixo                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"__________________________________________________________________________________________________"<<endl;
}

void Tela_NaoSuportaVGA () {
    cout<<"|_________________________________________________________________________________________________| "<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                       ______    |"<<endl;
    cout<<"|  _______                                                                              |>   |    |"<<endl;
    cout<<"|  |o    |                                                                              |    |    |"<<endl;
    cout<<"|  _______                                                                              |    |    |"<<endl;
    cout<<"|  v     v                                                                              ______    |"<<endl;
    cout<<"|  Itac HD                      ____________________________                             Dos      |"<<endl;
    cout<<"|                              |                            |                                     |"<<endl;
    cout<<"|  _____                       |  VGA NAO SUPORTADO         |                           ____-_    |"<<endl;
    cout<<"|  |   |                       |  Use CGA, EGA, VGA         |                           |    |    |"<<endl;
    cout<<"|  | O  |                      |                            |                           |____|    |"<<endl;
    cout<<"|  |   E|                      |   ________                 |                                     |"<<endl;
    cout<<"|  ______                      |  ||CLOSE|||                |                       Meus Arquivos |"<<endl;
    cout<<"|    A:                        |____________________________|                                     |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|  _____     __o__                                                                                |"<<endl;
    cout<<"|  |   |     |||||                                                                                |"<<endl;
    cout<<"|  | O  |    |||||                                                                                |"<<endl;
    cout<<"|  |   E|    |||||                                                                                |"<<endl;
    cout<<"|  ______    Lixo                                                                                 |"<<endl;
    cout<<"|    B:                                                                                           |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"__________________________________________________________________________________________________"<<endl;
}

void Tela_SelectInput () {
    cout<<"|_________________________________________________________________________________________________| "<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                       ______    |"<<endl;
    cout<<"|  _______                                                                              |>   |    |"<<endl;
    cout<<"|  |o    |                                                                              |    |    |"<<endl;
    cout<<"|  _______                                                                              |    |    |"<<endl;
    cout<<"|  v     v                                                                              ______    |"<<endl;
    cout<<"|  Itac HD                      ____________________________                             Dos      |"<<endl;
    cout<<"|                              |                            |                                     |"<<endl;
    cout<<"|  _____                       |  SELECIONE ENTRADA:        |                           ____-_    |"<<endl;
    cout<<"|  |   |                       |  [1] TECLADO               |                           |    |    |"<<endl;
    cout<<"|  | O  |                      |  [2] MOUSE                 |                           |____|    |"<<endl;
    cout<<"|  |   E|                      |  ||EXIT||                  |                                     |"<<endl;
    cout<<"|  ______                      |____________________________|                       Meus Arquivos |"<<endl;
    cout<<"|    A:                                                                                           |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|  _____     __o__                                                                                |"<<endl;
    cout<<"|  |   |     |||||                                                                                |"<<endl;
    cout<<"|  | O  |    |||||                                                                                |"<<endl;
    cout<<"|  |   E|    |||||                                                                                |"<<endl;
    cout<<"|  ______    Lixo                                                                                 |"<<endl;
    cout<<"|    B:                                                                                           |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"__________________________________________________________________________________________________"<<endl;
}

void Tela_ConfirmaFormatar () {
    cout<<"|_________________________________________________________________________________________________| "<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                       ______    |"<<endl;
    cout<<"|  _______                                                                              |>   |    |"<<endl;
    cout<<"|  |o    |                                                                              |    |    |"<<endl;
    cout<<"|  _______                                                                              |    |    |"<<endl;
    cout<<"|  v     v                                                                              ______    |"<<endl;
    cout<<"|  Itac HD                      ____________________________                             Dos      |"<<endl;
    cout<<"|                              |                            |                                     |"<<endl;
    cout<<"|  _____                       |  FORMATAR DISCO?           |                           ____-_    |"<<endl;
    cout<<"|  |   |                       |  TODOS OS ARQUIVOS SERAO   |                           |    |    |"<<endl;
    cout<<"|  | O  |                      |  PERDIDOS!!! CONTINUAR?    |                           |____|    |"<<endl;
    cout<<"|  |   E|                      |   _______   ______         |                                     |"<<endl;
    cout<<"|  ______                      |   | SIM |  | NAO |         |                       Meus Arquivos |"<<endl;
    cout<<"|    A:                        |   |_____| |_____|         |"<<endl;
    cout<<"|                              |   |_______|                |"<<endl;
    cout<<"|  _____     __o__             |____________________________|"<<endl;
    cout<<"|  |   |     |||||                                                                                |"<<endl;
    cout<<"|  | O  |    |||||                                                                                |"<<endl;
    cout<<"|  |   E|    |||||                                                                                |"<<endl;
    cout<<"|  ______    Lixo                                                                                 |"<<endl;
    cout<<"|    B:                                                                                           |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"__________________________________________________________________________________________________"<<endl;
}

void Tela_Calculadora () {
    cout<<"|_________|||INFO|||________|||SAIR|||____________________________________________________________| "<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                _________________________                                        |"<<endl;
cout<<"|                               |CALCULADORA 1.3          |                                       |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                               |_________________________|                                       |"<<endl;
cout<<"|                               |                         |                                       |"<<endl;
cout<<"|                               |   1    2     3     +    |                                       |"<<endl;
cout<<"|                               |                         |                                       |"<<endl;
cout<<"|                               |                         |                                       |"<<endl;
cout<<"|                               |   4    5     6     -    |                                       |"<<endl;
cout<<"|                               |                         |                                       |"<<endl;
cout<<"|                               |                         |                                       |"<<endl;
cout<<"|                               |   7    8     9     *    |                                       |"<<endl;
cout<<"|                               |                         |                                       |"<<endl;
cout<<"|                               |                         |                                       |"<<endl;
cout<<"|                               |   C    0     =     /    |                                       |"<<endl;
cout<<"|                               |                         |                                       |"<<endl;
cout<<"|                               |                         |                                       |"<<endl;
cout<<"|                               |_________________________|                                       |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"__________________________________________________________________________________________________"<<endl;
}

bool Itadraw () {
    system ("cls");
    int Line = 1;
    cout << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q <<  q << q << q ;
    cout << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q <<  q << q << q <<  q << q <<  q << q << q <<   q << q << q << endl;
    cout << q <<  "          ITADRAW V 1.8 FOR ITADOS COPYLEFT (C) ITAC INC 2017 - END TO EXIT" <<  q << endl;
    cout << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q <<  q << q << q ;
    cout << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q <<  q << q << q <<  q << q <<  q << q << q <<   q << q << q << endl;
    cout << q <<  "                                                                           " <<  q << endl;
    cout << q  << "                                                                           " << q  << endl;
    cout << q  << "                                                                           " << q << endl;
    cout << q  << "                                                                           " << q << endl;
    cout << q  << "                                                                           "  << q << endl;
    cout << q  << "                                                                           " << q << endl;
    cout << q <<  "                                                                           "  << q << endl;
    cout << q <<  "                                                                           "  << q << endl;
    cout << q <<  "                                                                           " <<  q << endl;
    cout << q <<  "                                                                           " <<  q << endl;
    cout << q  << "                                                                           " << q  << endl;
    cout << q  << "                                                                           " << q << endl;
    cout << q  << "                                                                           " << q << endl;
    cout << q  << "                                                                           "  << q << endl;
    cout << q  << "                                                                           " << q << endl;
    cout << q <<  "                                                                           "  << q << endl;
    cout << q <<  "                                                                           "  << q << endl;
    cout << q  << "                                                                           " << q << endl;
    cout << q  << "                                                                           "  << q << endl;
    cout << q  << "                                                                           " << q << endl;
    cout << q <<  "                                                                           "  << q << endl;
    cout << q <<  "                                                                           "  << q << endl;
    cout << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q <<  q << q << q ;
    cout << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q << q <<  q << q << q << q << q <<  q << q << q <<  q << q << q << endl;

    while (GetAsyncKeyState(VK_END) == 0) {
            gotoxy(10,10);
            //cout << m;
            //cout <<"I"
    }


    End:
    Sleep (1000);
    return true;
}

#endif
