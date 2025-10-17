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
#include <time.h>
#include <dos.h>
#include <ITADOS.h>
#include <ItadosKernel.h> // BIBLIOTECA DE API DO ITADOS
#include <stdin.h>

#define SYSTEM 16 // DEFININDO A ARQUITETURA DE BITS DO SISTEMA
#define FSYSTEM FAT_32 // DEFINE O SISTEMA DE ARQUIVOS PARA FAT32
#define EL "\n" // QUEBRA DE LINHA

#define EQ if (ax || eax) return !!ax

using namespace std;

short Parte = 0;
int CDX;
int CDY;

/// VARIAVEIS DO EMULADOR

  char DW [16]; // CACHE DA CPU
  char WR [16];
  char RD [16];

  char AX; // REGISTRADORES DA CPU
  char AL;
  char EAX;
  char EBX;
  char ECX;
  char EBP;
  char LD;

char MEMO [500] [1000]; // MEMORIA DE 500 KYLOBYTES

/// -------------------- ///

int OperandoOperad = 1; /// VARIAVEIS DA CALCULADORA
string Operacao;
string Operando;
string Operador;
int Resultado = 0;

short Disco = 0; /// MISCELANEOS
string Aplicacao;
string NOME;
char LinhaDraw [20];
int Teladesenho [100] [100];
char q = 219;
char m = 30;
char qd = 223;

char Tecla;

short Corselec = 0; /// COR SELECIONADA NO ITADRAW

short InputPort = 0;

short Largura = 0; /// LARGURA DO QUADRADO

short Altura = 0; /// ALTURA DO QUADRADO

short ColunasVGA = 0; short LinhasVGA = 0; /// RESOLUCAO VGA DO MONITOR

string ArquivosDir [50]; /// LISTA DE ARQUIVOS EM UM DIRETORIO

bool SelecCopiando = false;
bool SelecApagando = false;
bool SelecMovendo = false;
bool SelecRenomeando = false;

bool JanelaCopiar = false;
bool JanelaDeletar = false;
bool JanelaMover = false;

bool SelecDestino = false;

bool DiskcopySelect = false;
bool FormatSelect = false;
bool InfoSelect = false;
bool Unformat = false;

char M = 30;//30;
char MB = 179;//220;//186;
char qs = 178; /// TIPOS DE PINCEIS DO ITADRAW

ifstream myfile1;
ofstream myfile;

string L1;
string L2;
string L3;
string L4;
string L5;
string L6;
string L7;
string L8;
string L9;
string L10;
string L11;
string L12;
string L13;
string L14;
string L15;
string L16;
string L17;
string L18;
string L19;
string L20;
string L21;
string L22;
string L23;
string L24;
string L25;
string L26; //
string L27; //
string L28;
string L29; //
string L30;
string L31;
string L32;
string L33;
string L34;
string L35;
string L36;
string L37;
string L38;
string L39;
string L40;
string Texto;
string Comando;

string ArquivoCopiar = " ";
string DestinoCopia = " ";

string DiscoFormatar;
string DiscoRecuperar;
string DiscoInfo;

string ArquivoDeletar;
string ArquivoRecuperar;

string Autoboot;

string ArqAbrirItatexto = ""; /// ARQUIVO QUE SERA ABERTO COMO PARAMETRO PARA O ITATEXTO (ABRIR AUTOMATICO)

string Pincel = ""; /// PINCEL DO ITADRAW

string varImprimir; // NOME DA VARIAVEL A SER IMPRESSA PELO CMD

string DiscoSelec; // PARA QUALQUER ACAO EM ALGUM DISCO

///

string Arquivoaprocurar;

string Condicao;

string AplicacaoRodar;

string NOMETEXTO;

string ModoItadraw;

///

string CDPASTA;

string Corsys;

string arg1;

string LinhaSet [25]; /// LINHA DO ARQUIVO DE SETTINGS

string LinhaDisk [30]; /// LINHA DO ARQUIVO DE DISCO

string Boot; /// INFO DE BOOT DO ARQUIVO DE SETTINGS

bool Hdd = true; /// INFO DE HDD DO ARQUIVO DE SETTINGS

string DiscoA [50]; /// LISTA DE ARQUIVOS DO DISCO A DO ARQUIVO DE SETTINGS
string DiscoB [50]; /// LISTA DE ARQUIVOS DO DISCO B DO ARQUIVO DE SETTINGS

string RAMstatus; /// INFO DE RAM DO ARQUIVO DE SETTINGS

string InfoSettings; /// DEFINE QUAL TIPO DE INFORMACAO ESTA SENDO LIDA DO ARQUIVO DE CONFIG

string DiskAFile; /// ARQUIVO DO DISCO A DO ARQUIVO DE SETTINGS
string DiskBFile; /// ARQUIVO DO DISCO B DO ARQUIVO DE SETTINGS

string DiskALabel; /// NOME DO DISCO A
string DiskBLabel; /// NOME DO DISCO B

/// --------------------------------

void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

  void mgotoxy(int x,int y)
{	COORD p={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),p);
}

void Cor (int Corconsole) {
      HANDLE  hConsole;
      hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
      // you can loop k higher to see more color choices

        // pick the colorattribute k you want
        SetConsoleTextAttribute(hConsole, Corconsole);

}

  void ShowConsoleCursor(bool showFlag) // ESCONDE O CURSOR
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

void Resetcor () {
Cor (240);
}

void Efeito_tela () {
gotoxy (0,0);
int Count = 0;
while (Count != 40) {
cout<<"                                                                                                   "<<endl;
Sleep (100);
Count++;
}
}

void PiscaTela () {
     system ("cls");
     Sleep (50  );
     system ("color");// 
     Sleep (50);
     system ("color f0");
     Sleep (50); // ret
     system ("color");
     Sleep (50); // 
     //system ("color 34");
     //Sleep (50);
     system ("color f0");
}

void LoadSys (string BOOT) {
    myfile.open ("ITADOSGRAPH.CRASP");
    myfile.close ();
}

/// APLICATIVOS

bool Itatexto () {
int linhaT = 0; int colunaT = 0;
system ("cls");
ShowConsoleCursor(true);
int Line = 1;
cout<<"---------------------------------- ITATEXTO V 1.4.5 FOR ITADOS ------------------------------------"<<endl;
cout<<"- ITATEXTO ---- SALVAR ------- EDITAR -------- FORMATAR ---------- CARREGAR ------- DESFAZER ------"<<endl;
cout<<"---------------------------------------------------------------------------------------------------"<<endl;
cout<<"-                                                                                                 -"<<endl;
cout<<"-                                                                                                 -"<<endl;
cout<<"-                                                                                                 -"<<endl;
cout<<"-                                                                                                 -"<<endl;
cout<<"-                                                                                                 -"<<endl;
cout<<"-                                                                                                 -"<<endl;
cout<<"-                                                                                                 -"<<endl;
cout<<"-                                                                                                 -"<<endl;
cout<<"-                                                                                                 -"<<endl;
cout<<"-                                                                                                 -"<<endl;
cout<<"-                                                                                                 -"<<endl;
cout<<"-                                                                                                 -"<<endl;
cout<<"-                                                                                                 -"<<endl;
cout<<"-                                                                                                 -"<<endl;
cout<<"-                                                                                                 -"<<endl;
cout<<"-                                                                                                 -"<<endl;
cout<<"-                                                                                                 -"<<endl;
cout<<"-                                                                                                 -"<<endl;
cout<<"-                                                                                                 -"<<endl;
cout<<"-                                                                                                 -"<<endl;
cout<<"---------------------------------------------------------------------------------------------------"<<endl;
gotoxy (2,4);

if (ArqAbrirItatexto == "Readme.txt") {
    NOME = "Readme.txt";
    goto AutoCarregar;
}

Texto:
//cin >> Comando;
getline (cin,Comando);
if ((Comando == "[salvar]") || (Comando == "[SAVE]") || (Comando == "[save]")|| (Comando == "[SALVAR]")) {
        cout << "INSIRA UM NOME PARA O ARQUIVO QUE DESEJA SALVAR -> ";
        cin >> NOMETEXTO;

  myfile.open (NOMETEXTO.c_str ());
  //myfile << Comando;
  myfile << L1 << endl;
  myfile << L2 << endl;
  myfile << L3 << endl;
  myfile << L4 << endl;
  myfile << L5 << endl; //
  myfile << L6 << endl;
  myfile << L7 << endl;
  myfile << L8 << endl;
  myfile << L9 << endl;
  myfile << L10 << endl;
  myfile << L11 << endl;
  myfile << L12 << endl;
  myfile << L13 << endl;
  myfile << L14 << endl;
  myfile << L15 << endl;
  myfile << L16 << endl;
  myfile << L17 << endl;
  myfile << L18 << endl;
  myfile << L19 << endl;
  myfile << L20 << endl;
  myfile << L21 << endl;
  myfile << L22 << endl;
  myfile << L23 << endl;
  myfile << L24 << endl;
  myfile << L26 << endl;
  myfile << L27 << endl;
  myfile << L28 << endl;
  myfile << L29 << endl;
  myfile << L30 << endl;
  myfile << L31 << endl;
  myfile << L32 << endl;
  myfile << L33 << endl;
  myfile << L34 << endl;
  myfile << L35 << endl;
  myfile << L36 << endl;
  myfile << L37 << endl;
  myfile << L38 << endl;
  myfile << L39 << endl;
  myfile << L40 << endl;

  myfile.close();
}
if ((Comando == "[sair]") || (Comando == "[exit]" ) || (Comando == "[EXIT]" )) {
//MouseInputHandler::polling_function(void*p);
Efeito_tela();
system ("cls");
goto End;
}

if (Comando == "[editar]"){
//MouseInputHandler::polling_function(void*p);
gotoxy (2,4);


}

if (Comando == "[inserir]") {
    cout << "\n POS. LINHA: ";
    cin >> linhaT ;
    cout << "\n POS. COLUNA: ";
    cin >> colunaT ;
    gotoxy (linhaT, colunaT);
}

if ((Comando == "[desfazer]") || (Comando == "[undo]")) {

}

if (Comando == "[carregar]"){
//MouseInputHandler::polling_function(void*p);
cout << "INSIRA O NOME DO ARQUIVO -> ";
cin >> NOME;
//gotoxy (2,4);
AutoCarregar:
Sleep (300);
//Itatexto ();
system ("cls");
cout<<"-------------------- ITATEXTO V 1.4.5 FOR ITADOS - " << NOME << " ---------------------------------"<<endl;
cout<<"- ITATEXTO ---- SALVAR ------- CARREGAR ------ SAIR -------------- INSERIR -------- DESFAZER ------"<<endl;
cout<<"---------------------------------------------------------------------------------------------------"<<endl;
cout<<"-                                                                                                 -"<<endl;
cout<<"-                                                                                                 -"<<endl;
cout<<"-                                                                                                 -"<<endl;
cout<<"-                                                                                                 -"<<endl;
cout<<"-                                                                                                 -"<<endl;
cout<<"-                                                                                                 -"<<endl;
cout<<"-                                                                                                 -"<<endl;
cout<<"-                                                                                                 -"<<endl;
cout<<"-                                                                                                 -"<<endl;
cout<<"-                                                                                                 -"<<endl;
cout<<"-                                                                                                 -"<<endl;
cout<<"-                                                                                                 -"<<endl;
cout<<"-                                                                                                 -"<<endl;
cout<<"-                                                                                                 -"<<endl;
cout<<"-                                                                                                 -"<<endl;
cout<<"-                                                                                                 -"<<endl;
cout<<"-                                                                                                 -"<<endl;
cout<<"-                                                                                                 -"<<endl;
cout<<"-                                                                                                 -"<<endl;
cout<<"-                                                                                                 -"<<endl;
cout<<"---------------------------------------------------------------------------------------------------"<<endl;
cout << "LINHA : " << linhaT << "COLUNA : " << colunaT;
gotoxy (2,4);

myfile1.open (NOME.c_str());
while (! myfile1.eof ()) {
    getline (myfile1,Comando);
    cout << Comando << endl;
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

End: /// PARA FECHAR O PROGRAMA
Sleep (1000);
return true;
}

void MsgErrCopiarInv () { /// EXIBE NA TELA UMA MENSAGEM DE ERRO CASO O USUARIO TENTAR COPIAR UM ARQUIVO PARA UMA UNIDADE OU CAMINHO INEXISTENTE
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

void ConfirmSaveDraw () { /// JANELA DE COFIRMACAO DE SALVAMENTO DE UMA PINTURA DO APLICATIVO ITADRAW
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

void SelecArquivoLoad () { /// JANELA DE DIGITACAO (SELECAO MANUAL) DE CARREGAMENTO DE ALGUM ARQUIVO ("LOAD" GENERICO PARA QUALQUER APLICACAO)
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
              // int CLOCKS_PER_SEC = 0;
          //    tl=(clock()*1000)/CLOCKS_PER_SEC;
              m->lbdcb(x,y,m->lbdcbp);
           }

           //mouse up event: it was down and now is up
           if (!m->input.cleft && m->input.pleft)
           {
               float clock = 0;
           //    int CLOCKS_PER_SEC = 0;
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

	   Load ("MouseDRV.SYS") // SETUP DA INTERFACE GRAFICA (DRIVER DO MOUSE)
	   Set ("CD=ITADOSHD/");
           Load ("SystemEnvironment.SYS");
	   Run ("DESKTOP.CRASP"); // INCIO DA INTERFACE GRAFICA
	   Res (14,0);

           gotoxy(0,0);
           Sleep(25);
           system("cls");
          /* cout<<" _________________________________________________________________________________________________ "<<endl;
cout<<"| Itac   | Arquivo | Editar | Disco     | Visualizar   | Configuracoes |                          |"<<endl;
cout<<"|_________________________________________________________________________________________________|"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                        ____     |"<<endl;
cout<<"|  _______                                                                              |>   |    |"<<endl;
cout<<"|  |o   =|                _______________________________________________               |    |    |"<<endl;
cout<<"|  |_____|               | c:> DOS                                 |-|O|X|              |____|    |"<<endl;
cout<<"|  v     v               |-----------------------------------------+-+-+-|                        |"<<endl;
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
cout<<"__________________________________________________________________________________________________"<<endl; */
int ClickDos = 0;
if (Parte == 2) {
    cout<<" _________________________________________________________________________________________________ "<<endl;
cout<<"| Itac   | Arquivo | Editar | Disco     | Visualizar   | Configuracoes |                          |"<<endl;
cout<<"|_________________________________________________________________________________________________|"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                        ____     |"<<endl;
cout<<"|  _______                                                                              |>   |    |"<<endl;
cout<<"|  |o   =|                _______________________________________________               |    |    |"<<endl;
cout<<"|  |_____|               | c:> DOS                                 |-|O|X|              |____|    |"<<endl;
cout<<"|  v     v               |-----------------------------------------+-+-+-|                        |"<<endl;
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
}else if (Parte == 1){
cout<<"__________________________________________________________________________________________________ "<<endl;
cout<<"| Itac   | Arquivo | Editar | Disco     | Visualizar   | Configuracoes |                         | "<<endl;
cout<<"_________________________________________________________________________________________________  "<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                       ______    |"<<endl;
cout<<"|  _______                                                                              |>   |    |"<<endl;
cout<<"|  |o    |                                                                              |    |    |"<<endl;
cout<<"|  _______                                                                              |    |    |"<<endl;
cout<<"|  v     v                                                                              ______    |"<<endl;
cout<<"|  Itac HD                                                                               Dos      |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|  _____                                                                                ____-_    |"<<endl;
cout<<"|  |   |                                                                                |    |    |"<<endl;
cout<<"|  | O  |                                                                               |    |    |"<<endl;
cout<<"|  |   E|                                                                               ______    |"<<endl;
cout<<"|  ______                                                                           Meus Arquivos |"<<endl;
cout<<"|    A:                                                                                           |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|  _____     __o__                                                                                |"<<endl;
cout<<"|  |   |     |   |                                                                                |"<<endl;
cout<<"|  | O  |    |   |                                                                                |"<<endl;
cout<<"|  |   E|    |   |                                                                                |"<<endl;
cout<<"|  ______    _____                                                                                |"<<endl;
cout<<"|    B:      Lixo                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"__________________________________________________________________________________________________"<<endl;
} else if (Parte == 4) {
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
cout<<"|  | O  |                      |       DELETADOS            |                           |    |    |"<<endl;
cout<<"|  |   E|                      |   ________                 |                           ______    |"<<endl;
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
} else if (Parte == 5) {
    if ( ! ((DiskAFile == "NONE") || (DiskAFile == "none"))) {
cout<<" _________________________________________________________________________________________________ "<<endl;
cout<<"| Itac   | Arquivo | Editar | Disco     | Visualizar   | Configuracoes |                          |"<<endl;
cout<<"|_________________________________________________________________________________________________|"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                        ____     |"<<endl;
cout<<"|  _______                                                                              |>   |    |"<<endl;
cout<<"|  |o   =|                _______________________________________________               |    |    |"<<endl;
cout<<"|  |_____|               | B:                                      |-|O|X|              |____|    |"<<endl;
cout<<"|  v     v               |-----------------------------------------------|                        |"<<endl;
cout<<"|  Itac HD               |                                               |               Dos      |"<<endl;
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
gotoxy (30,7);
cout << DiskBLabel;

PrintDiskFiles ('B'); /// IMPRIME UMA LISTA DOS ARQUIVOS DO DISCO B

    } else {
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

} else if (Parte == 6) {
cout<<"__________________________________________________________________________________________________ "<<endl;
cout<<"||Itac|||| Arquivo | Editar | Disco     | Visualizar   | Configuracoes |                          | "<<endl;
cout<<"||||||||||_______________________________________________________________________________________ | "<<endl;
cout<<"|ITAC Info    PNM   |                                                                             |"<<endl;
cout<<"|ITADOS Info  RET   |                                                                   ______    |"<<endl;
cout<<"|Select Imput ALT+N |                                                                   |>   |    |"<<endl;
cout<<"|Select Printer     |                                                                   |    |    |"<<endl;
cout<<"|Load...            |                                                                   |    |    |"<<endl;
cout<<"|Pad Color mgr 3.0  |                                                                   ______    |"<<endl;
cout<<"|Echo cmd           |                                                                    Dos      |"<<endl;
cout<<"|_====EXIT====______|                                                                             |"<<endl;
cout<<"|  _____                                                                                ____-_    |"<<endl;
cout<<"|  |   |                                                                                |    |    |"<<endl;
cout<<"|  | O  |                                                                               |    |    |"<<endl;
cout<<"|  |   E|                                                                               ______    |"<<endl;
cout<<"|  ______                                                                           Meus Arquivos |"<<endl;
cout<<"|    A:                                                                                           |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|  _____     __o__                                                                                |"<<endl;
cout<<"|  |   |     |   |                                                                                |"<<endl;
cout<<"|  | O  |    |   |                                                                                |"<<endl;
cout<<"|  |   E|    |   |                                                                                |"<<endl;
cout<<"|  ______    _____                                                                                |"<<endl;
cout<<"|    B:      Lixo                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"__________________________________________________________________________________________________"<<endl;
} else if (Parte == 7) {
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
} else if (Parte == 8) {
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
cout<<"|  | O  |                                                                               |    |    |"<<endl;
cout<<"|  |   E|                                                                               ______    |"<<endl;
cout<<"|  ______                                                                           Meus Arquivos |"<<endl;
cout<<"|    A:                                                                                           |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|  _____     __o__                                                                                |"<<endl;
cout<<"|  |   |     |   |                                                                                |"<<endl;
cout<<"|  | O  |    |   |                                                                                |"<<endl;
cout<<"|  |   E|    |   |                                                                                |"<<endl;
cout<<"|  ______    _____                                                                                |"<<endl;
cout<<"|    B:      Lixo                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"__________________________________________________________________________________________________"<<endl;
}
else if (Parte == 9) {
        if ( ! ((DiskAFile == "DEFAULT") || (DiskAFile == "DEFAULT"))) {
cout<<" _________________________________________________________________________________________________ "<<endl;
cout<<"| Itac   | Arquivo | Editar | Disco     | Visualizar   | Configuracoes |                          |"<<endl;
cout<<"|_________________________________________________________________________________________________|"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                        ____     |"<<endl;
cout<<"|  _______                                                                              |>   |    |"<<endl;
cout<<"|  |o   =|                _______________________________________________               |    |    |"<<endl;
cout<<"|  |_____|               | A:                                      |-|O|X|              |____|    |"<<endl;
cout<<"|  v     v               |-----------------------------------------------|                        |"<<endl;
cout<<"|  Itac HD               |                                               |               Dos      |"<<endl;
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
gotoxy (30,7);
cout << DiskALabel;
PrintDiskFiles ('A'); /// IMPRIME UMA LISTA DOS ARQUIVOS DO DISCO A

        } else {
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
cout<<"|  |___A|                | |APP|                                         |              ______    |"<<endl;
cout<<"|                        | |||||                                         |          Meus Arquivos |"<<endl;
cout<<"|    A:                  | ITATEXTO.CRASP                                |                        |"<<endl;
cout<<"|                        | |||||           |||||                         |                        |"<<endl;
cout<<"|   ____     __=__       | |APP|           |   |                         |                        |"<<endl;
cout<<"|  |   |_    |   |       | |||||           |||||                         |                        |"<<endl;
cout<<"|  | O  |    |   |       | ITADRAW       CALC.AUTO                       |                        |"<<endl;
cout<<"|  |___B|    |___|       |                                               |                        |"<<endl;
cout<<"|                        |_______________________________________________|                        |"<<endl;
cout<<"|    B:      Lixo                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"__________________________________________________________________________________________________"<<endl;
gotoxy (30,7);
cout << DiskALabel;

        }


} else if (Parte == 13) { // APLICACAO ITADRAW
    //Aplicacao = "Itadraw";
    //system ("cls");
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
//cout << Comando;
//int Teladesenho [100] [100];
for (int i = 0; i < 100; i++) {
    for (int d = 0; d < 100; d++) {
if (Teladesenho [i] [d] == 1) {
    gotoxy (i,d);
    Resetcor ();
    cout << q;
} else if (Teladesenho [i] [d] == 2) {
        gotoxy (i,d);
    Cor (241);
    cout << q;
} else if (Teladesenho [i] [d] == 3) {
        gotoxy (i,d);
    Cor (242);
    cout << q;
} else if (Teladesenho [i] [d] == 4) {
        gotoxy (i,d);
    Cor (243);
    cout << q;
} else if (Teladesenho [i] [d] == 5) {
        gotoxy (i,d);
    Cor (244);
    cout << q;
} else if (Teladesenho [i] [d] == 6) {
        gotoxy (i,d);
    Cor (245);
    cout << q;
} else if (Teladesenho [i] [d] == 7) {
        gotoxy (i,d);
    Cor (246);
    cout << q;
} else if (Teladesenho [i] [d] == 8) {
        gotoxy (i,d);
    Cor (247);
    cout << q;
} else if (Teladesenho [i] [d] == 9) {
        gotoxy (i,d);
    Cor (248);
    cout << q;
} else if (Teladesenho [i] [d] == 10) {
        gotoxy (i,d);
    Cor (249);
    cout << q;
} else if (Teladesenho [i] [d] == 11) {
        gotoxy (i,d);
    Cor (250);
    cout << q;
} else if (Teladesenho [i] [d] == 12) {
        gotoxy (i,d);
    Cor (251);
    cout << q;
} else if (Teladesenho [i] [d] == 13) {
        gotoxy (i,d);
    Cor (252);
    cout << q;
} else if (Teladesenho [i] [d] == 14) {
        gotoxy (i,d);
    Cor (253);
    cout << q;
} else if (Teladesenho [i] [d] == 15) {
        gotoxy (i,d);
    Cor (254);
    cout << q;
} /// PINCEL QS
else if (Teladesenho [i] [d] == 111) {
        gotoxy (i,d);
    Resetcor ();
    cout << qs;
} else if (Teladesenho [i] [d] == 112) {
        gotoxy (i,d);
    Cor (241);
    cout << qs;
} else if (Teladesenho [i] [d] == 113) {
        gotoxy (i,d);
    Cor (242);
    cout << qs;
} else if (Teladesenho [i] [d] == 114) {
        gotoxy (i,d);
    Cor (243);
    cout << qs;
} else if (Teladesenho [i] [d] == 115) {
        gotoxy (i,d);
    Cor (244);
    cout << qs;
} else if (Teladesenho [i] [d] == 116) {
        gotoxy (i,d);
    Cor (255);
    cout << qs;
} else if (Teladesenho [i] [d] == 117) {
        gotoxy (i,d);
    Cor (256);
    cout << qs;
} else if (Teladesenho [i] [d] == 118) {
        gotoxy (i,d);
    Cor (257);
    cout << qs;
} else if (Teladesenho [i] [d] == 119) {
        gotoxy (i,d);
    Cor (258);
    cout << qs;
} else if (Teladesenho [i] [d] == 120) {
        gotoxy (i,d);
    Cor (259);
    cout << qs;
} else if (Teladesenho [i] [d] == 121) {
        gotoxy (i,d);
    Cor (254);
    cout << qs;
} else if (Teladesenho [i] [d] == 122) {
        gotoxy (i,d);
    Cor (255);
    cout << qs;
}
/// PINCEL QMS
else if (Teladesenho [i] [d] == 411) {
        gotoxy (i,d);
    Resetcor ();
    cout << qms;
} else if (Teladesenho [i] [d] == 412) {
        gotoxy (i,d);
    Cor (241);
    cout << qms;
} else if (Teladesenho [i] [d] == 413) {
        gotoxy (i,d);
    Cor (242);
    cout << qms;
} else if (Teladesenho [i] [d] == 414) {
        gotoxy (i,d);
    Cor (243);
    cout << qms;
} else if (Teladesenho [i] [d] == 415) {
        gotoxy (i,d);
    Cor (244);
    cout << qms;
} else if (Teladesenho [i] [d] == 416) {
        gotoxy (i,d);
    Cor (255);
    cout << qms;
} else if (Teladesenho [i] [d] == 417) {
        gotoxy (i,d);
    Cor (256);
    cout << qms;
} else if (Teladesenho [i] [d] == 418) {
        gotoxy (i,d);
    Cor (257);
    cout << qms;
} else if (Teladesenho [i] [d] == 419) {
        gotoxy (i,d);
    Cor (258);
    cout << qms;
} else if (Teladesenho [i] [d] == 420) {
        gotoxy (i,d);
    Cor (259);
    cout << qms;
} else if (Teladesenho [i] [d] == 421) {
        gotoxy (i,d);
    Cor (254);
    cout << qms;
} else if (Teladesenho [i] [d] == 422) {
        gotoxy (i,d);
    Cor (255);
    cout << qms;
}

    }

}
Resetcor ();
gotoxy (16,25);
Cor (252);
cout << "X";
Resetcor();
gotoxy (17,25);
for (int i = 240; i < 255; i++) {
Cor (i);
cout << q;
}
Resetcor ();

} else if (Parte == 14) {
cout<<"|_________|||CANCELAR|||__________________________________________________________________________| "<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                       ______    |"<<endl;
cout<<"|  _______                                                                              |>   |    |"<<endl;
cout<<"|  |o    |                                                                              |    |    |"<<endl;
cout<<"|  _______                                                                              |    |    |"<<endl;
cout<<"|  v     v                                                                              ______    |"<<endl;
cout<<"|  Itac HD                      ___________________________                             Dos      |"<<endl;
cout<<"|                              |                            |                                     |"<<endl;
cout<<"|  _____                       |  COPIAR DE : _SELEC.ARQ._  |                           ____-_    |"<<endl;
cout<<"|  |   |                       |                            |                           |    |    |"<<endl;
cout<<"|  | O  |                      |  PARA : " << DestinoCopia << "   _SELEC.DEST_  |                           |    |    |"<<endl;
cout<<"|  |   E|                      |   ________     ________    |                           ______    |"<<endl;
cout<<"|  ______                      |  | CANCEL |   | COPIAR |   |                       Meus Arquivos |"<<endl;
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
} else if (Parte == 16) {
cout<<"|_________|||CANCELAR|||____|||OK!|||_____________________________________________________________| "<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                       ______    |"<<endl;
cout<<"|  _______                                                                              |>   |    |"<<endl;
cout<<"|  |o    |                                                                              |    |    |"<<endl;
cout<<"|  _______                                                                              |    |    |"<<endl;
cout<<"|  v     v                                                                              ______    |"<<endl;
cout<<"|  Itac HD                                                                              Dos      |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|  _____                                                                                ____-_    |"<<endl;
cout<<"|  |   |                                                                                |    |    |"<<endl;
cout<<"|  | O  |                                                                               |    |    |"<<endl;
cout<<"|  |   E|                                                                               ______    |"<<endl;
cout<<"|  ______                                                                           Meus Arquivos |"<<endl;
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
} else if (Parte == 18) {
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

} else if (Parte == 20) {
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
cout<<"|  |   E|                                                                               ______    |"<<endl;
cout<<"|  ______                                                                           Meus Arquivos |"<<endl;
cout<<"|    A:                                                                                           |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|  _____     __o__                                                                                |"<<endl;
cout<<"|  |   |     |   |                                                                                |"<<endl;
cout<<"|  | O  |    |   |                                                                                |"<<endl;
cout<<"|  |   E|    |   |                                                                                |"<<endl;
cout<<"|  ______    _____                                                                                |"<<endl;
cout<<"|    B:      Lixo                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"__________________________________________________________________________________________________"<<endl;
} else if (Parte == 21) {
cout<<"__________________________________________________________________________________________________ "<<endl;
cout<<"| Itac   | Arquivo | Editar | Disco     | Visualizar   | Configuracoes |                         | "<<endl;
cout<<"_________________________________________________________________________________________________  "<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                       ______    |"<<endl;
cout<<"|  _______               ________________________________________________               |>   |    |"<<endl;
cout<<"|  |o    |              |                                                |              |    |    |"<<endl;
cout<<"|  _______              |  SELECT / SET INPUT:                           |              |    |    |"<<endl;
cout<<"|  v     v              |   __________________________________________   |              ______    |"<<endl;
cout<<"|  Itac HD              |  | 1.3                                      |  |               Dos      |"<<endl;
cout<<"|                       |  | 1.2                                      |  |                        |"<<endl;
cout<<"|  _____                |  | 2.5                                      |  |              ____-_    |"<<endl;
cout<<"|  |   |                |  | 3.8                                      |  |              |    |    |"<<endl;
cout<<"|  | O  |               |  | HDD                                      |  |              |    |    |"<<endl;
cout<<"|  |   E|               |  | RST                                      |  |              ______    |"<<endl;
cout<<"|  ______               |  | SRL                                      |  |          Meus Arquivos |"<<endl;
cout<<"|    A:                 |  |                                          |  |                        |"<<endl;
cout<<"|                       |  |__________________________________________|  |                        |"<<endl;
cout<<"|  _____     __o__      |               _______   _________   _______    |                        |"<<endl;
cout<<"|  |   |     |   |      |              |  SET  | | CANCEL  | | DONE  |   |                        |"<<endl;
cout<<"|  | O  |    |   |      |________________________________________________|                        |"<<endl;
cout<<"|  |   E|    |   |                                                                                |"<<endl;
cout<<"|  ______    _____                                                                                |"<<endl;
cout<<"|    B:      Lixo                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"__________________________________________________________________________________________________"<<endl;
} else if (Parte == 22) {
cout<<"__________________________________________________________________________________________________ "<<endl;
cout<<"| Itac   | Arquivo | Editar | Disco     | Visualizar   | Configuracoes |                         | "<<endl;
cout<<"_________________________________________________________________________________________________  "<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                       ______    |"<<endl;
cout<<"|  _______               ________________________________________________               |>   |    |"<<endl;
cout<<"|  |o    |              |                                                |              |    |    |"<<endl;
cout<<"|  _______              |  SET " << InputPort << "   * INPUT *                          |              |    |    |"<<endl;
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
} else if (Parte == 23) {
    cout<<" _________________________________________________________________________________________________ "<<endl;
cout<<"| Itac   | Arquivo | Editar | Disco     | Visualizar   | Configuracoes |                          |"<<endl;
cout<<"|_________________________________________________________________________________________________|"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                        ____     |"<<endl;
cout<<"|  _______                                                                              |>   |    |"<<endl;
cout<<"|  |o   =|                _______________________________________________               |    |    |"<<endl;
cout<<"|  |_____|               | ITAC HD_/TOOLS                          |<|O|X|              |____|    |"<<endl;
cout<<"|  v     v               |-----------------------------------------+-+-+-|                        |"<<endl;
cout<<"|  Itac HD               | |||||    |||||  |||||   |||||                 |               Dos      |"<<endl;
cout<<"|                        | |CMD|    |CMD|  |CMD|   |BAT|                 |                        |"<<endl;
cout<<"|   ____                 | |||||    |||||  |||||   |||||                 |               ___=_    |"<<endl;
cout<<"|  |   |_                | DISKCOPY FORMAT  REPAIR  INFO.BAT             |              |    |    |"<<endl;
cout<<"|  | O  |                | |||||    |||||                                |              |____|    |"<<endl;
cout<<"|  |___A|                | |CMD|    |RUN|                                |              ______    |"<<endl;
cout<<"|                        | |||||    |||||                                |          Meus Arquivos |"<<endl;
cout<<"|    A:                  | UNFORMAT MEMOALLOC.CRASP                      |                        |"<<endl;
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
} else if (Parte == 24) {
cout<<"|______________________________________________________|||||||||||||||||_________________________ |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                       ______    |"<<endl;
cout<<"|  _______               ________________________________________________               |>   |    |"<<endl;
cout<<"|  |o    |              |                                                |              |    |    |"<<endl;
cout<<"|  _______              |          *** SYSTEM PREFERENCES ***            |              |    |    |"<<endl;
cout<<"|  v     v              |   ___________                    ________      |              ______    |"<<endl;
cout<<"|  Itac HD              |  | SET CLOCK |     MOUSE DELAY  |  " << MouseDelay << "S  |     |               Dos      |"<<endl;
cout<<"|                       |   -----------                    --------      |                        |"<<endl;
cout<<"|  _____                |   ___________                    ________      |              ____-_    |"<<endl;
cout<<"|  |   |                |  | DESK COLOR|     KEYBOARD SCT | " << KBSct << /*ENABLED*/"|     |              |    |    |"<<endl;
cout<<"|  | O  |               |   -----------                    --------      |              |    |    |"<<endl;
cout<<"|  |   E|               |   ___________                    ________      |              ______    |"<<endl;
cout<<"|  ______               |  | CONSOLE   |     FILE CONFIRM |  OFF   |     |          Meus Arquivos |"<<endl;
cout<<"|    A:                 |   -----------                    --------      |                        |"<<endl;
cout<<"|                       |   ___________                                  |                        |"<<endl;
cout<<"|  _____     __o__      |  |  OTHER... |  ______  _________   _______    |                        |"<<endl;
cout<<"|  |   |     |   |      |   -----------  |RESET || CANCEL  | | SAVE  |   |                        |"<<endl;
cout<<"|  | O  |    |   |      |________________________________________________|                        |"<<endl;
cout<<"|  |   E|    |   |                                                                                |"<<endl;
cout<<"|  ______    _____                                                                                |"<<endl;
cout<<"|    B:      Lixo                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"__________________________________________________________________________________________________"<<endl;
} else if (Parte == 25) {
cout<<"|_______________________________________||||||||||||||||_________________________________________ | "<<endl;
cout<<"|                                       |  VIEW AS ICONS  |                                       |"<<endl;
cout<<"|                                       |  VIEW AS LIST   |                             ______    |"<<endl;
cout<<"|                                       |  VIEW AS BLOCKS |                             |>   |    |"<<endl;
cout<<"|                                       |* WINDOW         |                             |    |    |"<<endl;
cout<<"|                                       |  FULLSCREEN     |                             |    |    |"<<endl;
cout<<"|                                       |_______EXIT______|                             ______    |"<<endl;
cout<<"|                                                                                        Dos      |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|  _____                                                                                ____-_    |"<<endl;
cout<<"|  |   |                                                                                |    |    |"<<endl;
cout<<"|  | O  |                                                                               |    |    |"<<endl;
cout<<"|  |   E|                                                                               ______    |"<<endl;
cout<<"|  ______                                                                           Meus Arquivos |"<<endl;
cout<<"|    A:                                                                                           |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|  _____     __o__                                                                                |"<<endl;
cout<<"|  |   |     |   |                                                                                |"<<endl;
cout<<"|  | O  |    |   |                                                                                |"<<endl;
cout<<"|  |   E|    |   |                                                                                |"<<endl;
cout<<"|  ______    _____                                                                                |"<<endl;
cout<<"|    B:      Lixo                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"__________________________________________________________________________________________________"<<endl;
    if (ModoVisualisar == "Icons") {
        gotoxy (41,1);
        cout << "*";
    } else if (ModoVisualisar == "Text") {
        gotoxy (41,2);
        cout << "*";
    }
} else if (Parte == 26) {
cout<<"|______________________________________________________|||||||||||||||||_________________________ |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                       ______    |"<<endl;
cout<<"|  _______               ________________________________________________               |>   |    |"<<endl;
cout<<"|  |o    |              |                                                |              |    |    |"<<endl;
cout<<"|  _______              |           *** SET DESKTOP COLOR ***            |              |    |    |"<<endl;
cout<<"|  v     v              |           __                      __           |              ______    |"<<endl;
cout<<"|  Itac HD              |  FONTE : |  | BRANCO     FUNDO : |  | BRANCO   |               Dos      |"<<endl;
cout<<"|                       |           --                      --           |                        |"<<endl;
cout<<"|  _____                |           __                      __           |              ____-_    |"<<endl;
cout<<"|  |   |                |          |  | PRETO              |  | AZUL CL  |              |    |    |"<<endl;
cout<<"|  | O  |               |           --                      --           |              |    |    |"<<endl;
cout<<"|  |   E|               |           __                      __           |              ______    |"<<endl;
cout<<"|  ______               |          |  | VERDE              |  | AMARELO  |          Meus Arquivos |"<<endl;
cout<<"|    A:                 |           --                      --           |                        |"<<endl;
cout<<"|                       |           __                      __           |                        |"<<endl;
cout<<"|  _____     __o__      |          |  | VERMELHO           |  | VERDE    |                        |"<<endl;
cout<<"|  |   |     |   |      |           --                      --           |                        |"<<endl;
cout<<"|  | O  |    |   |      |                         _________   _______    |                        |"<<endl;
cout<<"|  |   E|    |   |      |                        | CANCEL  | | SAVE  |   |                        |"<<endl;
cout<<"|  ______    _____      |________________________________________________|                        |"<<endl;
cout<<"|    B:      Lixo                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"__________________________________________________________________________________________________"<<endl;
} else if (Parte == 28) {
cout<<"|_________________________________________________________________________________________________| "<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                       ______    |"<<endl;
cout<<"|  _______                                                                              |>   |    |"<<endl;
cout<<"|  |o    |                                                                              |    |    |"<<endl;
cout<<"|  _______                                                                              |    |    |"<<endl;
cout<<"|  v     v                                                                              ______    |"<<endl;
cout<<"|  Itac HD                      ____________________________                             Dos      |"<<endl;
cout<<"|                              |                            |                                     |"<<endl;
cout<<"|  _____                       |  RESOLUCAO VGA 160X60      |                           ____-_    |"<<endl;
cout<<"|  |   |                       |    NAO SUPORTA MODO DE     |                           |    |    |"<<endl;
cout<<"|  | O  |                      |    TELA CHEIA (FULSCREEN)  |                           |    |    |"<<endl;
cout<<"|  |   E|                      |   ________                 |                           ______    |"<<endl;
cout<<"|  ______                      |  ||||OK||||                |                       Meus Arquivos |"<<endl;
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
} else if (Parte == 29) {
cout<<"|_________________________________________________________________________________________________| "<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                       ______    |"<<endl;
cout<<"|  _______                                                                              |>   |    |"<<endl;
cout<<"|  |o    |                                                                              |    |    |"<<endl;
cout<<"|  _______                                                                              |    |    |"<<endl;
cout<<"|  v     v                                                                              ______    |"<<endl;
cout<<"|  Itac HD                      ____________________________                             Dos      |"<<endl;
cout<<"|                              |                            |                                     |"<<endl;
cout<<"|  _____                       |  DISCO " << DiscoSelec <<" " << DiskBLabel << "   |                 ____-_    |"<<endl;
cout<<"|  |   |                       |  " << DiskBBlocksFree << " BLOCKS FREE OF           |                           |    |    |"<<endl;
cout<<"|  | O  |                      |  " << "1582000" << " BLOCKS                   |                           |    |    |"<<endl;
cout<<"|  |   E|                      |   ________                 |                           ______    |"<<endl;
cout<<"|  ______                      |  ||||OK||||                |                       Meus Arquivos |"<<endl;
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

if (Parte == 3) {
    cout<<" _________________________________________________________________________________________________ "<<endl;
cout<<"| Itac   | Arquivo | Editar | Disco     | Visualizar   | Configuracoes |                          |"<<endl;
cout<<"|_________________________________________________________________________________________________|"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                        ____     |"<<endl;
cout<<"|  _______                                                                              |>   |    |"<<endl;
cout<<"|  |o   =|                _______________________________________________               |    |    |"<<endl;
cout<<"|  |_____|               | ITAC HD_/                               |-|O|X|              |____|    |"<<endl;
cout<<"|  v     v               |-----------------------------------------------|                        |"<<endl;
cout<<"|  Itac HD               |  ___=_   ___=_   ___=_  |||||                 |               Dos      |"<<endl;
cout<<"|                        | |    |  |    |  |    |  |TXT|                 |                        |"<<endl;
cout<<"|   ____                 | |____|  |____|  |____|  |||||                 |               ___=_    |"<<endl;
cout<<"|  |   |_                |  ITAC    TOOLS   ADMIN  README.TXT            |              |    |    |"<<endl;
cout<<"|  | O  |                | |||||                                         |              |____|    |"<<endl;
cout<<"|  |___A|                | |BAT|                                         |              ______    |"<<endl;
cout<<"|                        | |||||                                         |          Meus Arquivos |"<<endl;
cout<<"|    A:                  | ITADOS.BAT                                    |                        |"<<endl;
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
} /*else{
cout<<"__________________________________________________________________________________________________ "<<endl;
cout<<"| Itac   | Arquivo | Editar | Disco     | Visualizar   | Configuracoes |                         | "<<endl;
cout<<"_________________________________________________________________________________________________  "<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                       ______    |"<<endl;
cout<<"|  _______                                                                              |>   |    |"<<endl;
cout<<"|  |o    |                                                                              |    |    |"<<endl;
cout<<"|  _______                                                                              |    |    |"<<endl;
cout<<"|  v     v                                                                              ______    |"<<endl;
cout<<"|  Itac HD                                                                               Dos      |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|  ______                                                                               ____-_    |"<<endl;
cout<<"|  |   |                                                                                |    |    |"<<endl;
cout<<"|  | O  |                                                                               |    |    |"<<endl;
cout<<"|  |   E|                                                                               ______    |"<<endl;
cout<<"|  ______                                                                           Meus Arquivos |"<<endl;
cout<<"|    A:                                                                                           |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|  ______    __o__                                                                                |"<<endl;
cout<<"|  |   |     |   |                                                                                |"<<endl;
cout<<"|  | O  |    |   |                                                                                |"<<endl;
cout<<"|  |   E|    |   |                                                                                |"<<endl;
cout<<"|  ______    _____                                                                                |"<<endl;
cout<<"|    B:      Lixo                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"__________________________________________________________________________________________________"<<endl;
} */ ///
    /*     cout<<"__________________________________________________________________________________________________ "<<endl;
cout<<"| Itac   | Arquivo | Editar | Disco     | Visualizar   | Configuracoes |                         | "<<endl;
cout<<"_________________________________________________________________________________________________  "<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                       ______    |"<<endl;
cout<<"|  _______                                                                              |>   |    |"<<endl;
cout<<"|  |o    |                                                                              |    |    |"<<endl;
cout<<"|  _______                                                                              |    |    |"<<endl;
cout<<"|  v     v                                                                              ______    |"<<endl;
cout<<"|  Itac HD                                                                               Dos      |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|  ______                                                                               ____-_    |"<<endl;
cout<<"|  |   |                                                                                |    |    |"<<endl;
cout<<"|  | O  |                                                                               |    |    |"<<endl;
cout<<"|  |   E|                                                                               ______    |"<<endl;
cout<<"|  ______                                                                           Meus Arquivos |"<<endl;
cout<<"|    A:                                                                                           |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|  ______    __o__                                                                                |"<<endl;
cout<<"|  |   |     |   |                                                                                |"<<endl;
cout<<"|  | O  |    |   |                                                                                |"<<endl;
cout<<"|  |   E|    |   |                                                                                |"<<endl;
cout<<"|  ______    _____                                                                                |"<<endl;
cout<<"|    B:      Lixo                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"__________________________________________________________________________________________________"<<endl; */
}
    m->polling=false;
}

////////////////////////////////////////////////////////////////////////////////

void left_down(int x, int y, void*p) // CLIQUE DO BOTAO ESQUERDO
{
          if (Aplicacao != "Itadraw") {
     printf("left button down at (%d,%d)\n",x,y);
     }

     CDX = x;
     CDY = y;
          if (Aplicacao == "Itadraw") {
                      if (Corselec == 1) {
          Teladesenho [CDX] [CDY] = 1;
          } else if (Corselec == 2) {
          Teladesenho [CDX] [CDY] = 2;

          } else if (Corselec == 3) {
          Teladesenho [CDX] [CDY] = 3;

          } else if (Corselec == 4) {
          Teladesenho [CDX] [CDY] = 4;

          } else if (Corselec == 5) {
          Teladesenho [CDX] [CDY] = 5;

          } else if (Corselec == 6) {
          Teladesenho [CDX] [CDY] = 6;

          } else if (Corselec == 7) {
          Teladesenho [CDX] [CDY] = 7;

          } else if (Corselec == 8) {
          Teladesenho [CDX] [CDY] = 8;

          } else if (Corselec == 9) {
          Teladesenho [CDX] [CDY] = 9;

          } else if (Corselec == 10) {
          Teladesenho [CDX] [CDY] = 10;

          } else if (Corselec == 11) {
          Teladesenho [CDX] [CDY] = 11;

          } else if (Corselec == 12) {
          Teladesenho [CDX] [CDY] = 12;

          } else if (Corselec == 13) {
          Teladesenho [CDX] [CDY] = 13;

          } else if (Corselec == 14) {
          Teladesenho [CDX] [CDY] = 14;

          } else if (Corselec == 15) {
          Teladesenho [CDX] [CDY] = 15;

          } else if (Corselec == 800) {
          Teladesenho [CDX] [CDY] = 0;

          } else {
          Teladesenho [CDX] [CDY] = 1;
          }

     }
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
   cout<<" _________________________________________________________________________________________________ "<<endl;
cout<<"| Itac   | Arquivo | Editar | Disco     | Visualizar   | Configuracoes |                          |"<<endl;
cout<<"|_________________________________________________________________________________________________|"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                        ____     |"<<endl;
cout<<"|  _______                                                                              |>   |    |"<<endl;
cout<<"|  |o   =|                _______________________________________________               |    |    |"<<endl;
cout<<"|  |_____|               | c:> DOS                                 |-|O|X|              |____|    |"<<endl;
cout<<"|  v     v               |-----------------------------------------+-+-+-|                        |"<<endl;
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

int main(void)
{
ShowConsoleCursor(false);
        bool reset = false;
        system ("mode con:cols=160 lines=60"); /// UTILIZADO PARA AUMENTAR O TAMANHO DA JANELA DO TERMINAL
        system ("title ITADOS 1150 PLUS EMULATOR");

        RESET:
        LoadSettings (); // CARREGA AS CONFIGURACOES DE BOOT
        if ( ! ((DiskAFile == "DEFAULT") || (DiskAFile == "default"))) { /// CARREGA O DISKETE A
            LoadDisk ('A');
        } else {
        DiskALabel = "APPS";
        }
        if ( ! ((DiskBFile == "NONE") || (DiskBFile == "none"))) { /// CARREGA O DISKETE A
            LoadDisk ('B');
        }
        if ((Boot == "Itados.sys") || (Boot == "ITADOS.SYS")) {
        Cmd ();
        } /// BOOT
    ShowConsoleCursor(false);

    LoadSys (Boot); /// CARREGA O SISTEMA

    Parte = 1;
    MouseInputHandler mouse;
    mouse.set_lbdcb(left_down);
    mouse.set_lbucb(left_up);
    mouse.set_lbccb(left_click);
    POINT pt_Coords;
cout<<"__________________________________________________________________________________________________ "<<endl;
cout<<"| Itac   | Arquivo | Editar | Disco     | Visualizar   | Configuracoes |                         | "<<endl;
cout<<"_________________________________________________________________________________________________  "<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                       ______    |"<<endl;
cout<<"|  _______                                                                              |>   |    |"<<endl;
cout<<"|  |o    |                                                                              |    |    |"<<endl;
cout<<"|  _______                                                                              |    |    |"<<endl;
cout<<"|  v     v                                                                              ______    |"<<endl;
cout<<"|  Itac HD                                                                               Dos      |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|  ______                                                                               ____-_    |"<<endl;
cout<<"|  |   |                                                                                |    |    |"<<endl;
cout<<"|  | O  |                                                                               |    |    |"<<endl;
cout<<"|  |   E|                                                                               ______    |"<<endl;
cout<<"|  ______                                                                           Meus Arquivos |"<<endl;
cout<<"|    A:                                                                                           |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|  ______    __o__                                                                                |"<<endl;
cout<<"|  |   |     |   |                                                                                |"<<endl;
cout<<"|  | O  |    |   |                                                                                |"<<endl;
cout<<"|  |   E|    |   |                                                                                |"<<endl;
cout<<"|  ______    _____                                                                                |"<<endl;
cout<<"|    B:      Lixo                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"__________________________________________________________________________________________________"<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;
cout<<"                                                                                                   "<<endl;


    cout<<"Pressione alguma tecla para sair...";

    mouse.start_polling();

    system("color f0");

    int ClickDos = 0;

    while(GetAsyncKeyState(VK_ESCAPE) == 0); ///!_kbhit() /// RESET DO CONSOLE
    {
        if ((GetAsyncKeyState(VK_F11) != 0)&&(GetAsyncKeyState(VK_CONTROL) != 0)) {
            system ("color");
            system ("cls");
            //reset = true;
            goto RESET;

        }
         mouse.stop_polling();
         system("cls");
         //SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){0,3});
         GetCursorPos(&pt_Coords);
         int px = pt_Coords.x;
         int py = pt_Coords.y;
             mouse.set_lbccb(left_click);
         cout<<"x : "<<px<<"    \ny : "<<py<<"    \n";
         /*
         cout<<"__________________________________________________________________________________________________ "<<endl;
cout<<"| Itac   | Arquivo | Editar | Disco     | Visualizar   | Configuracoes |                         | "<<endl;
cout<<"_________________________________________________________________________________________________  "<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                       ______    |"<<endl;
cout<<"|  _______                                                                              |>   |    |"<<endl;
cout<<"|  |o    |                                                                              |    |    |"<<endl;
cout<<"|  _______                                                                              |    |    |"<<endl;
cout<<"|  v     v                                                                              ______    |"<<endl;
cout<<"|  Itac HD                                                                               Dos      |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|  ______                                                                               ____-_    |"<<endl;
cout<<"|  |   |                                                                                |    |    |"<<endl;
cout<<"|  | O  |                                                                               |    |    |"<<endl;
cout<<"|  |   E|                                                                               ______    |"<<endl;
cout<<"|  ______                                                                           Meus Arquivos |"<<endl;
cout<<"|    A:                                                                                           |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|  ______    __o__                                                                                |"<<endl;
cout<<"|  |   |     |   |                                                                                |"<<endl;
cout<<"|  | O  |    |   |                                                                                |"<<endl;
cout<<"|  |   E|    |   |                                                                                |"<<endl;
cout<<"|  ______    _____                                                                                |"<<endl;
cout<<"|    B:      Lixo                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"__________________________________________________________________________________________________"<<endl; */
     //  mouse.start_polling();

   // while (!(GetAsyncKeyState(VK_ESCAPE)>>15));

 //   mouse.stop_polling();
       if (ClickDos == 1) {
        system ("cls");
cout<<" _________________________________________________________________________________________________ "<<endl;
cout<<"| Itac   | Arquivo | Editar | Disco     | Visualizar   | Configuracoes |                          |"<<endl;
cout<<"|_________________________________________________________________________________________________|"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                        ____     |"<<endl;
cout<<"|  _______                                                                              |>   |    |"<<endl;
cout<<"|  |o   =|                _______________________________________________               |    |    |"<<endl;
cout<<"|  |_____|               | c:> DOS                                 |-|O|X|              |____|    |"<<endl;
cout<<"|  v     v               |-----------------------------------------+-+-+-|                        |"<<endl;
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
         gotoxy(px/8,py/12);
         //printf("^");
         cout << M;
         gotoxy (px/8,(py/12)+1);
         //cout << "|";
         cout << MB;
         gotoxy(0,0);
         _sleep(100);
         system("cls");
    }
    return 0;

}
