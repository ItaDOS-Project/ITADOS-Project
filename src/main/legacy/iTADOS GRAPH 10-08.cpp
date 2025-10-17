/// ITADOS GRAPH WRITTEN BY ARUNI AMSTEL, COPYRIGHT (c) ARUNI VAN AMSTEL 2017
///* This Software was written by Aruni Amstel (bioaruni@gmail.com) in november, 2017.
///* This file use the GNU-GPL license available at https://www.gnu.org/licenses/gpl-2.0.txt
///* This program is the main GUI of the operating system ITADOS
///* It countains many mouse functions that can be easily compiled and runned in Windows and Linux,
/// and also is bootable in Virtual Machines (Pentium/Intel architecture)
///* This code is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.

#define _WIN32_WINNT 0x0500

#include<windows.h>
#include <process.h>
#include<conio.h>
#include<iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <ITADOS.h>
#include <ItadosKernel.h>
#include <stdin.h>

#define SYSTEM 16 // DEFININDO A ARQUITETURA DE BITS DO SISTEMA
#define FSYSTEM FAT_32 // DEFINE O SISTEMA DE ARQUIVOS PARA FAT32
#define EL "\n" // QUEBRA DE LINHA

using namespace std;

int Parte = 0;
int CDX;
int CDY;

void gotoxy(int x, int y) // POSICIONA O CURSOR EM UMA POSICAO X E Y
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

bool Itatexto () { // APLICATIVO EDITOR DE TEXTO DO ITADOS
system ("cls");
ShowConsoleCursor(true);
int Line = 1;
bool editar = false;
cout<<"---------------------------------- ITATEXTO V 1.4.5 FOR ITADOS ------------------------------------"<<EL;
cout<<"- ITATEXTO ---- SALVAR ------- EDITAR -------- FORMATAR ---------- CARREGAR ------- DESFAZER ------"<<EL;
cout<<"---------------------------------------------------------------------------------------------------"<<EL;
cout<<"-                                                                                                 -"<<EL;
cout<<"-                                                                                                 -"<<EL;
cout<<"-                                                                                                 -"<<EL;
cout<<"-                                                                                                 -"<<EL;
cout<<"-                                                                                                 -"<<EL;
cout<<"-                                                                                                 -"<<EL;
cout<<"-                                                                                                 -"<<EL;
cout<<"-                                                                                                 -"<<EL;
cout<<"-                                                                                                 -"<<EL;
cout<<"-                                                                                                 -"<<EL;
cout<<"-                                                                                                 -"<<EL;
cout<<"-                                                                                                 -"<<EL;
cout<<"-                                                                                                 -"<<EL;
cout<<"-                                                                                                 -"<<EL;
cout<<"-                                                                                                 -"<<EL;
cout<<"-                                                                                                 -"<<EL;
cout<<"-                                                                                                 -"<<EL;
cout<<"-                                                                                                 -"<<EL;
cout<<"-                                                                                                 -"<<EL;
cout<<"-                                                                                                 -"<<EL;
cout<<"---------------------------------------------------------------------------------------------------"<<EL;
gotoxy (2,4);

if (ArqAbrirItatexto == "Readme.txt") { // VERIFICA SE O CARREGAMENTO AUTOMATICO DO README.TXT ESTA ATIVADO
    NOME = "Readme.txt";
    goto AutoCarregar;
}

Texto:
//cin >> Comando;
getline (cin,Comando);
if (Comando == "[salvar]"){
        cout << "INSIRA UM NOME PARA O ARQUIVO QUE DESEJA SALVAR -> ";
        cin >> NOMETEXTO;

  myfile.open (NOMETEXTO.c_str ()); // SALVA O ARQUIVO QUE ESTA SENDO ESCRITO OU EDITADO
  //myfile << Comando;
  myfile << L1 << EL;
  myfile << L2 << EL;
  myfile << L3 << EL;
  myfile << L4 << EL;
  myfile << L5 << EL; //
  myfile << L6 << EL;
  myfile << L7 << EL;
  myfile << L8 << EL;
  myfile << L9 << EL;
  myfile << L10 << EL;
  myfile << L11 << EL;
  myfile << L12 << EL;
  myfile << L13 << EL;
  myfile << L14 << EL;
  myfile << L15 << EL;
  myfile << L16 << EL;
  myfile << L17 << EL;
  myfile << L18 << EL;
  myfile << L19 << EL;
  myfile << L20 << EL;
  myfile << L21 << EL;
  myfile << L22 << EL;
  myfile << L23 << EL;
  myfile << L24 << EL;
  myfile << L26 << EL;
  myfile << L27 << EL;
  myfile << L28 << EL;
  myfile << L29 << EL;
  myfile << L30 << EL;
  myfile << L31 << EL;
  myfile << L32 << EL;
  myfile << L33 << EL;
  myfile << L34 << EL;
  myfile << L35 << EL;
  myfile << L36 << EL;
  myfile << L37 << EL;
  myfile << L38 << EL;
  myfile << L39 << EL;
  myfile << L40 << EL;

  myfile.close();
}
if (Comando == "[sair]"){ // SAI DO PROGRAMA
//MouseInputHandler::polling_function(void*p);
Efeito_tela();
system ("cls");

goto End;
}

if (Comando == "[editar]"){ // ATIVA A EDICAO DE UM ARQUIVO ABERTO
//MouseInputHandler::polling_function(void*p);
gotoxy (2,4);
editar = true;

}

if (Comando == "[carregar]"){ // CARREGA O ARQUIVO SOLICITADO PELO USUARIO E O IMPRIME NA TELA
//MouseInputHandler::polling_function(void*p);
cout << "INSIRA O NOME DO ARQUIVO -> ";
cin >> NOME;
//gotoxy (2,4);
AutoCarregar:
Sleep (300);
//Itatexto ();
system ("cls");
cout<<"-------------------- ITATEXTO V 1.4.5 FOR ITADOS - " << NOME << " ---------------------------------"<<EL;
cout<<"- ITATEXTO ---- SALVAR ------- CARREGAR ------ SAIR -------------- INSERIR -------- DESFAZER ------"<<EL;
cout<<"---------------------------------------------------------------------------------------------------"<<EL;
cout<<"-                                                                                                 -"<<EL;
cout<<"-                                                                                                 -"<<EL;
cout<<"-                                                                                                 -"<<EL;
cout<<"-                                                                                                 -"<<EL;
cout<<"-                                                                                                 -"<<EL;
cout<<"-                                                                                                 -"<<EL;
cout<<"-                                                                                                 -"<<EL;
cout<<"-                                                                                                 -"<<EL;
cout<<"-                                                                                                 -"<<EL;
cout<<"-                                                                                                 -"<<EL;
cout<<"-                                                                                                 -"<<EL;
cout<<"-                                                                                                 -"<<EL;
cout<<"-                                                                                                 -"<<EL;
cout<<"-                                                                                                 -"<<EL;
cout<<"-                                                                                                 -"<<EL;
cout<<"-                                                                                                 -"<<EL;
cout<<"-                                                                                                 -"<<EL;
cout<<"-                                                                                                 -"<<EL;
cout<<"-                                                                                                 -"<<EL;
cout<<"-                                                                                                 -"<<EL;
cout<<"---------------------------------------------------------------------------------------------------"<<EL;
gotoxy (2,4);
//system (("type " + NOME + ".txt").c_str());
myfile1.open (NOME.c_str());
while (! myfile1.eof ()) {
    getline (myfile1,Comando);
    cout << Comando << EL;
    Sleep (50);
}
myfile1.close ();
}

if (Line == 1) {
L1 = Comando;
}else if (Line == 2) {
L2 = Comando;
}else if (Line == 3) {
L3 = Comando;
}else if (Line == 4) {
L4 = Comando;
}else if (Line == 5) {
L5 = Comando;
}else if (Line == 6) {
L6 = Comando;
}else if (Line == 7) {
L7 = Comando;
}else if (Line == 8) {
L8 = Comando;
}else if (Line == 10) {
L9 = Comando;
}else if (Line == 11) {
L10 = Comando;
}else if (Line == 12) {
L11 = Comando;
}else if (Line == 13) {
L12 = Comando;
}else if (Line == 14) {
L13 = Comando;
}else if (Line == 15) {
L14 = Comando;
}else if (Line == 16) {
L15 = Comando;
}else if (Line == 17) {
L16 = Comando; //
}else if (Line == 18) {
L17 = Comando;
}else if (Line == 19) {
L18 = Comando;
}else if (Line == 20) {
L19 = Comando;
}else if (Line == 21) {
L20 = Comando; //
}else if (Line == 22) {
L21 = Comando;
}else if (Line == 23) {
L22 = Comando; //
}else if (Line == 24) {
L23 = Comando;
}else if (Line == 25) {
L24 = Comando;
}else if (Line == 26) {
L25 = Comando;
}else if (Line == 27) {
L26 = Comando; //
}else if (Line == 28) {
L27 = Comando;
}else if (Line == 29) {
L28 = Comando;
}else if (Line == 30) {
L29 = Comando;
}else if (Line == 31) {
L30 = Comando;
}else if (Line == 32) {
L31 = Comando;
}else if (Line == 33) {
L32 = Comando;
}else if (Line == 34) {
L33 = Comando;
}else if (Line == 35) {
L34 = Comando;
}else if (Line == 36) {
L35 = Comando;
}else if (Line == 37) {
L36 = Comando;
}else if (Line == 38) {
L37 = Comando;
}else if (Line == 39) {
L38 = Comando;
}else if (Line == 40) {
L39 = Comando;
}else if (Line == 41) {
L40 = Comando;
}

Line++;
goto Texto;

End:
Sleep (1000);
return true;
}

void MouseInputHandler::polling_function(void*p)
{
     MouseInputHandler * m=(MouseInputHandler*)p;

     m->input.quit=false;

     HWND window=GetConsoleWindow();
     RECT wpos;
     POINT cpos;


     m->input.cleft=m->input.pleft=m->input.cright=m->input.pright=false;
     int x,y;
     int tl, tr,t;


     while (!m->input.quit)
     {
           GetWindowRect(window,&wpos);
           GetCursorPos(&cpos);

           cpos.x-=wpos.left;
           cpos.y-=wpos.top;

           //transform screen to console coords
           x=(cpos.x-5)/8;
           y=(cpos.y-25)/12;

           m->input.cleft=is_pressed(VK_LBUTTON);
           m->input.cright=is_pressed(VK_RBUTTON);

           //mouse down event: it was up and now is down
           if (m->input.cleft && !m->input.pleft)
           {
               float clock = 0;
               int CLOCKS_PER_SEC = 0;
          //    tl=(clock()*1000)/CLOCKS_PER_SEC;
              m->lbdcb(x,y,m->lbdcbp);
           }

           //mouse up event: it was down and now is up
           if (!m->input.cleft && m->input.pleft)
           {
               float clock = 0;
               int CLOCKS_PER_SEC = 0;
          //    t=(clock()*1000)/CLOCKS_PER_SEC;
              m->lbucb(x,y,m->lbucbp);

              //mouse click event:
              //down->up in less than 100 ms
              if (t-tl<=100)
              m->lbccb(x,y,m->lbccbp);
           }

           //...more stuff here

           m->input.pleft=m->input.cleft;
           //m->input.pright=m->input.cright;

REBOOT:
           gotoxy(x,y);
           cout << M;
           gotoxy (x,y+1);
           //cout << "|";
           cout << MB;
            if (Parte == 25) {
                if ((x < 27) || (x > 47)) { /// FECHA O MENU DISCO
                    if ((y < 0) || (y > 7)) {
                        Parte = 1;
                    }

                }
            }

           gotoxy(x,y);
           cout << "^";
           gotoxy(0,0);
           Sleep(25);
           system("cls");
	   Load ("MouseDRV.SYS") // SETUP DA INTERFACE GRAFICA
	   Set ("CD=ITADOSHD/");
           Load ("SystemEnvironment.SYS");
	   Run ("DESKTOP.CRASP"); // INCIO DA INTERFACE GRAFICA
	   Res (14,0);
          /* cout<<" _________________________________________________________________________________________________ "<<EL;
cout<<"| Itados | Arquivo | Editar | Disco     | Visualizar   | Configuracoes |                          |"<<EL;
cout<<"|_________________________________________________________________________________________________|"<<EL;
cout<<"|                                                                                                 |"<<EL;
cout<<"|                                                                                        ____     |"<<EL;
cout<<"|  _______                                                                              |>   |    |"<<EL;
cout<<"|  |o   =|                _______________________________________________               |    |    |"<<EL;
cout<<"|  |_____|               | c:> DOS                                 |-|O|X|              |____|    |"<<EL;
cout<<"|  v     v               |-----------------------------------------+-+-+-|                        |"<<EL;
cout<<"|  Itac HD               | c:>                                           |               Dos      |"<<EL;
cout<<"|                        |                                               |                        |"<<EL;
cout<<"|   ____                 |                                               |               ___=_    |"<<EL;
cout<<"|  |   |_                |                                               |              |    |    |"<<EL;
cout<<"|  | O  |                |                                               |              |____|    |"<<EL;
cout<<"|  |___A|                |                                               |              ______    |"<<EL;
cout<<"|                        |                                               |          Meus Arquivos |"<<EL;
cout<<"|    A:                  |                                               |                        |"<<EL;
cout<<"|                        |                                               |                        |"<<EL;
cout<<"|   ____     __=__       |                                               |                        |"<<EL;
cout<<"|  |   |_    |   |       |                                               |                        |"<<EL;
cout<<"|  | O  |    |   |       |                                               |                        |"<<EL;
cout<<"|  |___B|    |___|       |                                               |                        |"<<EL;
cout<<"|                        |_______________________________________________|                        |"<<EL;
cout<<"|    B:      Lixo                                                                                 |"<<EL;
cout<<"|                                                                                                 |"<<EL;
cout<<"|                                                                                                 |"<<EL;
cout<<"|                                                                                                 |"<<EL;
cout<<"__________________________________________________________________________________________________"<<EL; */
int ClickDos = 0;


    //; }
}
     m->polling=false;
}

////////////////////////////////////////////////////////////////////////////////

void left_down(int x, int y, void*p)
{
     printf("left button down at (%d,%d)\n",x,y);
     CDX = x;
     CDY = y;
}

void left_up(int x, int y, void*p)
{
     printf("left button up at (%d,%d)\n",x,y);
     CDX = x;
     CDY = y;
}

void left_click(int x, int y, void*p)
{
     printf("left click at (%d,%d)\n",x,y);
}

void left_downDos(int x = 90, int y = 7, void*p = 0)
{
    int ClickDos = 1;
   cout<<" _________________________________________________________________________________________________ "<<EL;
cout<<"| Itados | Arquivo | Editar | Disco     | Visualizar   | Configuracoes |                          |"<<EL;
cout<<"|_________________________________________________________________________________________________|"<<EL;
cout<<"|                                                                                                 |"<<EL;
cout<<"|                                                                                        ____     |"<<EL;
cout<<"|  _______                                                                              |>   |    |"<<EL;
cout<<"|  |o   =|                _______________________________________________               |    |    |"<<EL;
cout<<"|  |_____|               | c:> DOS                                 |-|O|X|              |____|    |"<<EL;
cout<<"|  v     v               |-----------------------------------------+-+-+-|                        |"<<EL;
cout<<"|  Itac HD               | c:>                                           |               Dos      |"<<EL;
cout<<"|                        |                                               |                        |"<<EL;
cout<<"|   ____                 |                                               |               ___=_    |"<<EL;
cout<<"|  |   |_                |                                               |              |    |    |"<<EL;
cout<<"|  | O  |                |                                               |              |____|    |"<<EL;
cout<<"|  |___A|                |                                               |              ______    |"<<EL;
cout<<"|                        |                                               |          Meus Arquivos |"<<EL;
cout<<"|    A:                  |                                               |                        |"<<EL;
cout<<"|                        |                                               |                        |"<<EL;
cout<<"|   ____     __=__       |                                               |                        |"<<EL;
cout<<"|  |   |_    |   |       |                                               |                        |"<<EL;
cout<<"|  | O  |    |   |       |                                               |                        |"<<EL;
cout<<"|  |___B|    |___|       |                                               |                        |"<<EL;
cout<<"|                        |_______________________________________________|                        |"<<EL;
cout<<"|    B:      Lixo                                                                                 |"<<EL;
cout<<"|                                                                                                 |"<<EL;
cout<<"|                                                                                                 |"<<EL;
cout<<"|                                                                                                 |"<<EL;
cout<<"__________________________________________________________________________________________________"<<EL;
}

int main(void)
{
    Parte = 1;
    MouseInputHandler mouse;
    mouse.set_lbdcb(left_down);
    mouse.set_lbucb(left_up);
    mouse.set_lbccb(left_click);
    POINT pt_Coords;
cout<<"__________________________________________________________________________________________________ "<<EL;
cout<<"| Itados | Arquivo | Editar | Disco     | Visualizar   | Configuracoes |                         | "<<EL;
cout<<"_________________________________________________________________________________________________  "<<EL;
cout<<"|                                                                                                 |"<<EL;
cout<<"|                                                                                       ______    |"<<EL;
cout<<"|  _______                                                                              |>   |    |"<<EL;
cout<<"|  |o    |                                                                              |    |    |"<<EL;
cout<<"|  _______                                                                              |    |    |"<<EL;
cout<<"|  v     v                                                                              ______    |"<<EL;
cout<<"|  Itac HD                                                                               Dos      |"<<EL;
cout<<"|                                                                                                 |"<<EL;
cout<<"|  ______                                                                               ____-_    |"<<EL;
cout<<"|  |   |                                                                                |    |    |"<<EL;
cout<<"|  | O  |                                                                               |    |    |"<<EL;
cout<<"|  |   E|                                                                               ______    |"<<EL;
cout<<"|  ______                                                                           Meus Arquivos |"<<EL;
cout<<"|    A:                                                                                           |"<<EL;
cout<<"|                                                                                                 |"<<EL;
cout<<"|  ______    __o__                                                                                |"<<EL;
cout<<"|  |   |     |   |                                                                                |"<<EL;
cout<<"|  | O  |    |   |                                                                                |"<<EL;
cout<<"|  |   E|    |   |                                                                                |"<<EL;
cout<<"|  ______    _____                                                                                |"<<EL;
cout<<"|    B:      Lixo                                                                                 |"<<EL;
cout<<"|                                                                                                 |"<<EL;
cout<<"|                                                                                                 |"<<EL;
cout<<"|                                                                                                 |"<<EL;
cout<<"__________________________________________________________________________________________________"<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;
cout<<"                                                                                                   "<<EL;


    cout<<"Pressione alguma tecla para sair...";

    mouse.start_polling();

    system("color f0");

    int ClickDos = 0;

    while(!_kbhit());
    {
         mouse.stop_polling();
         system("cls");
         //SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){0,3});
         GetCursorPos(&pt_Coords);
         int px = pt_Coords.x;
         int py = pt_Coords.y;
             mouse.set_lbccb(left_click);
         cout<<"x : "<<px<<"    \ny : "<<py<<"    \n";
         cout<<"__________________________________________________________________________________________________ "<<EL;
cout<<"| Itados | Arquivo | Editar | Disco     | Visualizar   | Configuracoes |                         | "<<EL;
cout<<"_________________________________________________________________________________________________  "<<EL;
cout<<"|                                                                                                 |"<<EL;
cout<<"|                                                                                       ______    |"<<EL;
cout<<"|  _______                                                                              |>   |    |"<<EL;
cout<<"|  |o    |                                                                              |    |    |"<<EL;
cout<<"|  _______                                                                              |    |    |"<<EL;
cout<<"|  v     v                                                                              ______    |"<<EL;
cout<<"|  Itac HD                                                                               Dos      |"<<EL;
cout<<"|                                                                                                 |"<<EL;
cout<<"|  ______                                                                               ____-_    |"<<EL;
cout<<"|  |   |                                                                                |    |    |"<<EL;
cout<<"|  | O  |                                                                               |    |    |"<<EL;
cout<<"|  |   E|                                                                               ______    |"<<EL;
cout<<"|  ______                                                                           Meus Arquivos |"<<EL;
cout<<"|    A:                                                                                           |"<<EL;
cout<<"|                                                                                                 |"<<EL;
cout<<"|  ______    __o__                                                                                |"<<EL;
cout<<"|  |   |     |   |                                                                                |"<<EL;
cout<<"|  | O  |    |   |                                                                                |"<<EL;
cout<<"|  |   E|    |   |                                                                                |"<<EL;
cout<<"|  ______    _____                                                                                |"<<EL;
cout<<"|    B:      Lixo                                                                                 |"<<EL;
cout<<"|                                                                                                 |"<<EL;
cout<<"|                                                                                                 |"<<EL;
cout<<"|                                                                                                 |"<<EL;
cout<<"__________________________________________________________________________________________________"<<EL;
     //  mouse.start_polling();

   // while (!(GetAsyncKeyState(VK_ESCAPE)>>15));

 //   mouse.stop_polling();
       if (ClickDos == 1) {
        system ("cls");
cout<<" _________________________________________________________________________________________________ "<<EL;
cout<<"| Itados | Arquivo | Editar | Disco     | Visualizar   | Configuracoes |                          |"<<EL;
cout<<"|_________________________________________________________________________________________________|"<<EL;
cout<<"|                                                                                                 |"<<EL;
cout<<"|                                                                                        ____     |"<<EL;
cout<<"|  _______                                                                              |>   |    |"<<EL;
cout<<"|  |o   =|                _______________________________________________               |    |    |"<<EL;
cout<<"|  |_____|               | c:> DOS                                 |-|O|X|              |____|    |"<<EL;
cout<<"|  v     v               |-----------------------------------------+-+-+-|                        |"<<EL;
cout<<"|  Itac HD               | c:>                                           |               Dos      |"<<EL;
cout<<"|                        |                                               |                        |"<<EL;
cout<<"|   ____                 |                                               |               ___=_    |"<<EL;
cout<<"|  |   |_                |                                               |              |    |    |"<<EL;
cout<<"|  | O  |                |                                               |              |____|    |"<<EL;
cout<<"|  |___A|                |                                               |              ______    |"<<EL;
cout<<"|                        |                                               |          Meus Arquivos |"<<EL;
cout<<"|    A:                  |                                               |                        |"<<EL;
cout<<"|                        |                                               |                        |"<<EL;
cout<<"|   ____     __=__       |                                               |                        |"<<EL;
cout<<"|  |   |_    |   |       |                                               |                        |"<<EL;
cout<<"|  | O  |    |   |       |                                               |                        |"<<EL;
cout<<"|  |___B|    |___|       |                                               |                        |"<<EL;
cout<<"|                        |_______________________________________________|                        |"<<EL;
cout<<"|    B:      Lixo                                                                                 |"<<EL;
cout<<"|                                                                                                 |"<<EL;
cout<<"|                                                                                                 |"<<EL;
cout<<"|                                                                                                 |"<<EL;
cout<<"__________________________________________________________________________________________________"<<EL;
       }
         gotoxy(px/8,py/12);
         printf("^");
         gotoxy(0,0);
         _sleep(100);
         system("cls");
    }
    return 0;

}



