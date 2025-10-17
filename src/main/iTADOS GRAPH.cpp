/// ITADOS GRAPH POR ARUNI AMSTEL, COPYLEFT 2017
///* This Software was written by Aruni Amstel between may, 2017 and october 2025.
///* This file use the GNU-GPL license available at https://www.gnu.org/licenses/gpl-2.0.txt
///* This program is the main GUI of the operating system ITADOS
///* It countains many mouse functions that can be easily compiled and runned in Windows and Linux,
///* This code is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.

#define _WIN32_WINNT 0x0500

#define WIDTH  100 // LARGURA DA TELA
#define HEIGHT 25 // ALTURA DA TELA

#include<windows.h>
#include <process.h>
#include<conio.h>
#include<iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <dirent.h>
#include <time.h>
#include <dos.h>



    DIR *d;
    struct dirent *dir;

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

bool OperandoOperad = true; /// VARIAVEIS DA CALCULADORA
string Operacao;
string Operando;
string Operador;
int Resultado = 0;

short Disco = 0;
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
char qss = 177;
char qms = 176;

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

/// VARIAVEIS DO CMD

int pin = 0;
int pin2;
short X =0 ;
short Y =0;
short pinbackup = 1234;
short Alarme;
short Bloqueiodesim = 0;
string Subcomando;
string Pasta;
string Contatos[100][2] = {{"Ursotel", "*9889"}};
short NumContatos = 1;
string Contatocriar;
short Contnum;
short Brilho;
short LightDuration;
short ModoVibracao;
short EconomiadeBateria;
short Padron1=0;
string Program;
short App = 0;
short Opt;
char chDigitado = 0;
string pinDigitado = "";
string pinbackup3 = "1234";
string pin4 = "3287";

string Arquivoaprocurar;

string Condicao;

string AplicacaoRodar;

string NOMETEXTO;

string ModoItadraw;

//string ArquivoCopiar;

//string DestinoCopia;

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

string DiskAContent [20]; /// LISTA DE ARQUIVOS E PASTAS DO DISCO A
string DiskBContent [20]; /// LISTA DE ARQUIVOS E PASTAS DO DISCO B

string DiskAIcons [5] [3]; /// LISTA DE ARQUIVOS E PASTAS DO DISCO A
string DiskBIcons [5] [3]; /// LISTA DE ARQUIVOS E PASTAS DO DISCO B

string DiskASizes [20]; /// TAMANHO DOS ARQUIVOS DO DISCO A
string DiskBSizes [20]; /// TAMANHO DOS ARQUIVOS DO DISCO B

string CorFonte; /// UTILIZADO PARA CHAMAR A FUNCAO DE COR DO DESKCOLOR
string CorFundo; /// UTILIZADO PARA CHAMAR A FUNCAO DE COR DO DESKCOLOR

string DiskABlocksFree; /// ESPACO LIVRE NO DISCO A
string DiskBBlocksFree = "182550"; /// ESPACO LIVRE NO DISCO B

string ModoVisualisar = "Text" ; /// MODO DE VISUALIZACAO DE ARQUIVOS DOS DISCOS

short NumArquivosA = 0; /// NUMERO DE ARQUIVOS POR DISCO
short NumArquivosB = 0; /// NUMERO DE ARQUIVOS DO DISCO B

float MouseDelay = 0.5; /// DELAY DO MOUSE
string KBSct = "ENABLED"; /// VARIAVEL DE VERIFICACAO SE ESTA ATIVADO ATALHOS DE TECLADO

//string PASTA;
char PASTA [100];

char Variaveis [40]; ///  PARA FUNCOES DE VARIAVEIS DO CMD
string VariaveisNome [40];
int Vi = 0;
int NovoValor = 0;
string Varname;
char Var = 0;

bool sudolock = true; // SENHA ATIVADA OU DESATIVADA DE PROTECAO DO USUARIO ROOT


int operand = 0; int operatord = 0; // VARIAVEIS DA CALC

string Padron;

string Pastachange = "";

bool atualizarTela = false;
bool mostrarTime = false;


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
/*
system ("color 0a");
cout << "              ITAC 1100 PLUS READY - INSERT DISK OR CARTRIDGE                   " << endl;
cin >> Comando;
if (Comando == "A") {
    system ("start iTADOS_GRAPH_10-08.exe");
} */
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
           cout << m;
           //cout <<"I"
}


End:
Sleep (1000);
return true;
}

void MemoAlloc () {
system ("cls");
system ("color 1f");
while (GetAsyncKeyState(VK_END) == 0) {

}
End:
Sleep (1000);
}



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
gotoxy (33  ,13);
cout << "                         "; // 37.7 a 56.7
gotoxy (33  ,14);
cout << "                         ";
gotoxy (33  ,15);
cout << "                         ";
gotoxy (33  ,16);
cout << "                         ";
gotoxy (33  ,17);
cout << "                         ";
gotoxy (33  ,18);
cout << "                         ";
gotoxy (33  ,19);
cout << "                         ";
gotoxy (33  ,20);
cout << "                         ";
gotoxy (33  ,21);
cout << "                         ";
Cor (240); /// RESETA A COR BRANCO/PRETO
}

void SalvarDesenho () {
myfile.open ("Desenho1.GRP"); /// CRIA UM ARQUIVO COM O DESENHO
for (int i = 0; i < 100; i++) { ///X
for (int d = 0; d < 100; d++) { /// Y
myfile << Teladesenho [i] [d] << endl;
}
}
myfile.close ();
}

void LoadDesenho () {
ifstream myfileD;
gotoxy (37,13);
cin >> NOME;
Efeito_tela ();
myfileD.open (NOME.c_str ()); /// CARREGA O ARQUIVO SELECIONADO
if (myfileD.is_open ()) {

for (int i = 0; i < 100; i++) { ///X
for (int d = 0; d < 100; d++) { /// Y
if (!myfileD.eof()) {
///getline (myfileD, LinhaDraw);
myfileD >> LinhaDraw;
}
Teladesenho [i] [d] = atoi (LinhaDraw);
}
}

/*
int i = 0;
int d = 0;
while ( !myfile.eof()) {
getline (myfile,LinhaN);
HOFNomes [Index] = LinhaN;
i++;

        } */

}

myfileD.close ();
}

void LoadSettings () {
ifstream myfileS;
Efeito_tela ();
myfileS.open ("./ADMIN/Settings.inf"); /// CARREGA O ARQUIVO SELECIONADO
if (myfileS.is_open ()) {

for (int i = 0; i < 23; i++) { ///X
if (!myfileS.eof()) {
///getline (myfileD, LinhaDraw);
myfileS >> LinhaSet [i];
}

} /// for

}

myfileS.close ();

Boot = LinhaSet [1];
DiskAFile = LinhaSet [3];
DiskBFile = LinhaSet [5];
RAMstatus = LinhaSet [9] ;
/*
cout << Boot << endl;
cout <<DiskAFile << endl;
cout << DiskBFile << endl;
cout << RAMstatus << endl;
system ("pause");
*/
}

void LoadDisk (char Disk) {
ifstream myfileS;
if ((Disk == 'A') || (Disk == 'a')) {
myfileS.open (("./ADMIN/" + DiskAFile).c_str()); /// CARREGA O ARQUIVO SELECIONADO
} else if ((Disk == 'B') || (Disk == 'b')) {
 myfileS.open (("./ADMIN/" + DiskBFile).c_str()); /// CARREGA O ARQUIVO SELECIONADO
} else {
myfileS.open (("./ADMIN/" + DiskAFile).c_str()); /// CARREGA O ARQUIVO SELECIONADO
}

if (myfileS.is_open ()) {

for (int i = 0; i < 23; i++) { ///X
if (!myfileS.eof()) {
///getline (myfileD, LinhaDraw);
myfileS >> LinhaDisk [i];
}

} /// for

}


myfileS.close ();

if ((Disk == 'A') || (Disk == 'a')) {
DiskALabel = LinhaDisk [0];
} else if ((Disk == 'B') || (Disk == 'b')) {
DiskBLabel = LinhaDisk [0];
} else {
DiskALabel = LinhaDisk [0];
}

if ((Disk == 'A') || (Disk == 'a')) {
NumArquivosA = atoi ((LinhaDisk [1]).c_str());
} else if ((Disk == 'B') || (Disk == 'b')) {
NumArquivosB = atoi ((LinhaDisk [1]).c_str());
} else {
NumArquivosA = atoi ((LinhaDisk [1]).c_str());
}

if ((Disk == 'A') || (Disk == 'a')) {

int d = 0;
for (int i = 2; i < 12 ; i++) {
    DiskAContent [d] = LinhaDisk [i];
    if (d < 13) {
         d++;
    }

}

} else if ((Disk == 'B') || (Disk == 'b')) {

int d = 0;
for (int i = 2; i < 12 ; i++) {
    DiskBContent [d] = LinhaDisk [i];
    if (d < 13) {
         d++;
    }

}

}

///

if ((Disk == 'A') || (Disk == 'a')) {

int d = 0;
for (int i = 14; i < 24 ; i++) {
    DiskASizes [d] = LinhaSet [i];
    if (d < 10) {
         d++;
    }

}

} else if ((Disk == 'B') || (Disk == 'b')) {

int d = 0;
for (int i = 14; i < 24 ; i++) {
    DiskBSizes [d] = LinhaSet [i];
    if (d < 10) {
         d++;
    }

}

}


/*
cout << Boot << endl;
cout <<DiskAFile << endl;
cout << DiskBFile << endl;
cout << RAMstatus << endl;
system ("pause");
*/
}

void ConvertDiskIcons (char Disk) {
if ((Disk == 'A') || (Disk == 'a')) {
        int Idx = 0;
       /* for(int row = 0 ; row<4; row++)
        {
            for(int col = 0; col<6; col++)
            {
                DiskAIcons[row][col] = DiskAContent[Idx];
                if (Idx <= NumArquivosA) {
                Idx++;
                }
                //Idx++;
            }
        } */
        DiskAIcons [0] [0] = DiskAContent[0];
        DiskAIcons [1] [0] = DiskAContent[1];
        DiskAIcons [2] [0] = DiskAContent[3];
        DiskAIcons [3] [0] = DiskAContent[4];
        DiskAIcons [4] [0] = DiskAContent[5];
        DiskAIcons [0] [1] = DiskAContent[6];
        DiskAIcons [1] [1] = DiskAContent[7];
        DiskAIcons [2] [1] = DiskAContent[8];
        DiskAIcons [3] [1] = DiskAContent[9];
        DiskAIcons [4] [1] = DiskAContent[10];
        DiskAIcons [0] [2] = DiskAContent[11];
        DiskAIcons [1] [2] = DiskAContent[12];
        DiskAIcons [2] [2] = DiskAContent[13];
        DiskAIcons [3] [2] = DiskAContent[14];
        DiskAIcons [4] [2] = DiskAContent[15];

} else {
        //int Idx = 0;
       /* for(int row = 0 ; row<4; row++)
        {
            for(int col = 0; col<6; col++)
            {
                DiskBIcons[row][col] = DiskBContent[Idx];
                if (Idx < NumArquivosA) {
                Idx++;
                }
                //Idx++;
            }
        } */
        DiskBIcons [0] [0] = DiskBContent[0];
        DiskBIcons [1] [0] = DiskBContent[1];
        DiskBIcons [2] [0] = DiskBContent[3];
        DiskBIcons [3] [0] = DiskBContent[4];
        DiskBIcons [4] [0] = DiskBContent[5];
        DiskBIcons [0] [1] = DiskBContent[6];
        DiskBIcons [1] [1] = DiskBContent[7];
        DiskBIcons [2] [1] = DiskBContent[8];
        DiskBIcons [3] [1] = DiskBContent[9];
        DiskBIcons [4] [1] = DiskBContent[10];
        DiskBIcons [0] [2] = DiskBContent[11];
        DiskBIcons [1] [2] = DiskBContent[12];
        DiskBIcons [2] [2] = DiskBContent[13];
        DiskBIcons [3] [2] = DiskBContent[14];
        DiskBIcons [4] [2] = DiskBContent[15];
}

}

void PrintDiskFiles (char Disk) {
gotoxy (27,10);
if ((Disk == 'A') || (Disk == 'a')) {
        for (int i = 0; i < 10; i++) {
        gotoxy (27,10+i);
        cout << qd << " " << DiskAContent [i] << " " << DiskASizes [i];
}

} else {
    for (int i = 0; i < 10; i++) {
        gotoxy (27,10+i);
        cout << qd << " " << DiskBContent [i] << " " << DiskBSizes [i];
}

}

}

void PrintaIcone (string NomeArquivo, int Linha, int Coluna) {
if (Linha == 0) {
if (Coluna == 0) {
gotoxy (27,9);
cout << "|||||";
gotoxy (27,10);
cout << "|   |";
gotoxy (27,11);
cout << "|||||";
gotoxy (27,12);
cout << NomeArquivo;

} else if (Coluna == 1) {
gotoxy (36,9);
cout << "|||||";
gotoxy (36,10);
cout << "|   |";
gotoxy (36,11);
cout << "|||||";
gotoxy (36,12);
cout << NomeArquivo;

} else if (Coluna == 2) {
gotoxy (45,9);
cout << "|||||";
gotoxy (45,10);
cout << "|   |";
gotoxy (45,11);
cout << "|||||";
gotoxy (45,12);
cout << NomeArquivo;

} else if (Coluna == 3) {
gotoxy (54,9);
cout << "|||||";
gotoxy (54,10);
cout << "|   |";
gotoxy (54,11);
cout << "|||||";
gotoxy (54,12);
cout << NomeArquivo;

} else if (Coluna == 4) {
gotoxy (64,9);
cout << "|||||";
gotoxy (64,10);
cout << "|   |";
gotoxy (64,11);
cout << "|||||";
gotoxy (64,12);
cout << NomeArquivo;

}

} else if (Linha == 1) {
if (Coluna == 0) {
gotoxy (27,13);
cout << "|||||";
gotoxy (27,14);
cout << "|   |";
gotoxy (27,15);
cout << "|||||";
gotoxy (27,16);
cout << NomeArquivo;

} else if (Coluna == 1) {
gotoxy (36,13);
cout << "|||||";
gotoxy (36,14);
cout << "|   |";
gotoxy (36,15);
cout << "|||||";
gotoxy (36,16);
cout << NomeArquivo;

} else if (Coluna == 2) {
gotoxy (45,13);
cout << "|||||";
gotoxy (45,14);
cout << "|   |";
gotoxy (45,15);
cout << "|||||";
gotoxy (45,16);
cout << NomeArquivo;

} else if (Coluna == 3) {
gotoxy (54,13);
cout << "|||||";
gotoxy (54,14);
cout << "|   |";
gotoxy (54,15);
cout << "|||||";
gotoxy (54,16);
cout << NomeArquivo;

} else if (Coluna == 4) {
gotoxy (64,13);
cout << "|||||";
gotoxy (64,14);
cout << "|   |";
gotoxy (64,15);
cout << "|||||";
gotoxy (64,16);
cout << NomeArquivo;

}

} else if (Linha == 2) {
if (Coluna == 0) {
gotoxy (27,17);
cout << "|||||";
gotoxy (27,18);
cout << "|   |";
gotoxy (27,19);
cout << "|||||";
gotoxy (27,20);
cout << NomeArquivo;

} else if (Coluna == 1) {
gotoxy (36,17);
cout << "|||||";
gotoxy (36,18);
cout << "|   |";
gotoxy (36,19);
cout << "|||||";
gotoxy (36,20);
cout << NomeArquivo;

} else if (Coluna == 2) {
gotoxy (45,17);
cout << "|||||";
gotoxy (45,18);
cout << "|   |";
gotoxy (45,19);
cout << "|||||";
gotoxy (45,20);
cout << NomeArquivo;

} else if (Coluna == 3) {
gotoxy (54,17);
cout << "|||||";
gotoxy (54,18);
cout << "|   |";
gotoxy (54,19);
cout << "|||||";
gotoxy (54,20);
cout << NomeArquivo;

} else if (Coluna == 4) {
gotoxy (64,17);
cout << "|||||";
gotoxy (64,18);
cout << "|   |";
gotoxy (64,19);
cout << "|||||";
gotoxy (64,20);
cout << NomeArquivo;

}

} /// LINHAS

}

void PrintDiskIcons (char Disk) {
  //  gotoxy (27,10);
  //  int linha = 0;
   // int col = 0;

   //gotoxy (0,3);
  // cout << NumArquivosA;
   //gotoxy (0,4);
  // cout << NumArquivosB;
   int File = 0;
if ((Disk == 'A') || (Disk == 'a')) { /// 5 COLUNAS X 3 LINHAS
        File = 0;
        for (int i = 1; i < 4; i++) { /// Y LINHAS
        //gotoxy (27,10+i);
        for (int d = 1; d < 6;d++) { /// X COLUNAS
            if (File < NumArquivosA) {
            PrintaIcone (DiskAIcons [d] [i],i,d);
            File++;
            }
        }

        //col++;
}

} else {
        File = 0;
        for (int i = 1; i < 4; i++) { /// Y LINHAS
        //gotoxy (27,10+i);
        for (int d = 1; d < 6;d++) { /// X COLUNAS
        if (File < NumArquivosB) {
        PrintaIcone (DiskBIcons [i] [d],i,d);
        File++;
        }

        }
        //col++;
}

}

}

void PrintaTime () {
  time_t rawtime;
  struct tm * timeinfo;

  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  gotoxy (74,1); //gotoxy (79,1);
  printf ( asctime (timeinfo) );
}


void Snake () {
    system ("./SNAKE.exe");
}

void protecao () {

}


bool Cmd () {
Inic:

ShowConsoleCursor(true);

Sleep (3500);
system ("cls");
system ("color 0a"); //  1e original

Pasta = ".";
//system (("cd " + Pasta).c_str());

cout << "Bem vindo ao Ita Dos copyleft (c) ITAC Inc 2017!" << endl;
Cmd:
    if (Padron1 == 0) {
     cout << "ITACHD_/";
    } else {
    cout << Padron;
    }


if (Autoboot == "ITADOSGRAPH.CRASP") {
    cout << "ITADOSGRAPH.CRASP" << endl;
    Sleep (1000);
    ShowConsoleCursor(false);
    PiscaTela ();
    gotoxy (10,5);
    cout << "BOOTING ITADOSGRAPH..." << endl;
    gotoxy (0,0);
    Efeito_tela ();
    goto ENDCMD;
}
cin >> Comando;
//getline (cin, Comando);
if ((Comando == "cd")||(Comando == "CD")) {
        cout << endl;
    cin >> Pastachange;
    Pasta += ("/" +Pastachange);


}
if ((Comando == "CLS")||(Comando == "cls")) { // 
     system ("cls");
}

if (Comando == "esc") {
     goto ENDCMD;
}
if ((Comando == "dir")||(Comando == "DIR")) { // 1
int TempNumOne=Pasta.size();
for (int a=0;a<=TempNumOne;a++)
        {
            PASTA[a]=Pasta[a];
        }

     d = opendir(PASTA);
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            printf("%s\n", dir->d_name);
        }
        closedir(d);
    }
    cout << endl;
    cout << "Done" << endl;
}
if (Comando == "resetterm") { // 1
     Sleep (1000);
     system ("exit 1e");
     system ("color 1e");
     system ("cls");
     App = 0;
     Padron1 = 0;
}

if (Comando == "exit") { // 
     system ("color 0a");
     system ("cls");
     App = 0;
     //cout << "ITACHD_/";
     Padron1 = 0;
}
if (Comando == "EXIT") { // 
     system ("color 0a");
     system ("cls");
}
if ((Comando == "copy")||(Comando == "COPY")) { // 
        cin >> ArquivoCopiar;
        cin >> DestinoCopia;
     system (("copy " + ArquivoCopiar + " " + DestinoCopia).c_str());
     cout << "Done" << endl;
}

if ((Comando == "del")||(Comando == "DEL")) { // 
       cin >> ArquivoDeletar;
       cout << "Done" << endl;
}

if ((Comando == "undel")||(Comando == "UNDEL")) { // 
       cin >> ArquivoRecuperar;
       cout << "Done" << endl;
}

if ((Comando == "ret")||(Comando == "RET")) { // 
     goto ENDCMD;
}

if (Comando == "pause") { // 
     system ("pause");
     cout << "\n";
}
if (Comando == "PAUSE") { // 
     system ("pause");
}

if (Comando == "test") { // 
     system("color?");
}
if ((Comando == "path") || (Comando == "PATH")) {
     cout << "Pasta atual: " << Pasta << endl << endl;

}

if ((Comando == "create")||(Comando == "CREATE")) { // 
        //int Opt;
     cout << "(1) - Pasta" << endl;
     cout << "(2) - Arquivo Generico" << endl;
     cin >> Opt;
switch (Opt ) {
case 1:
    cin >> ArquivoCopiar;
    system (("md "+ ArquivoCopiar).c_str ());
    cout << "\n done" << endl;
case 2:
    cin >> ArquivoCopiar;
    myfile.open (ArquivoCopiar.c_str());
    myfile.close ();
    cout << "\n done" << endl;
}

}
if ((Comando == "crd") || (Comando == "CRD")) { // 
     cin >> ArquivoCopiar;
    system (("md "+ ArquivoCopiar).c_str ());
    cout << "done" << endl;
}

if ((Comando == "calc.crasp") || (Comando == "CALC.CRASP")) {
	RUNCALC:
        int Operando = 0;
        int Operador = 0;
        int Operacao = 0;
     cout << " Itados Calculator v 3.5.8" << endl;
     cout << " 1 - Soma" << endl; // 
     cout << " 2 - Subtracao" << endl;
     cout << " 3 - Multiplicacao" << endl; // 
     cout << " 4 - Divisao" << endl; // nm
     cout << " 0 - Cancelar" << endl; // nm
     cin >> Opt;
     switch (Opt ) {
case 1:
    Operacao = 1;
    cout << " Inisira o Operando (1 numero)" << endl;
    cin >> Operando;
    cout << " Inisira o Operador (2 numero)" << endl;
    cin >> Operador;
    cout << Operando + Operador << endl; // 
    cout << "done" << endl;
    break;
case 2:
    Operacao = 2;
    cout << " Inisira o Operando (1 numero)" << endl;
    cin >> Operando;
    cout << " Inisira o Operador (2 numero)" << endl;
    cin >> Operador;
    cout << Operando - Operador << endl; // 
    cout << "done" << endl;
    break;
case 3:
    Operacao = 3;
    cout << " Inisira o Operando (1 numero)" << endl;
    cin >> Operando;
    cout << " Inisira o Operador (2 numero)" << endl;
    cin >> Operador;
    cout << Operando * Operador << endl; // 
    cout << "done" << endl;
    break;
case 4:
    Operacao = 4;
    cout << " Inisira o Operando (1 numero)" << endl;
    cin >> Operando;
    cout << " Inisira o Operador (2 numero)" << endl;
    cin >> Operador;
    cout << Operando / Operador << endl; // 
    cout << "done" << endl;
}

}

if  ((Comando == "calc") || (Comando == "CALC")) {
        int Operando = 0;
        int Operador = 0;
        char Operacao = 0;
        cin >> Operando;
        cin >> Operacao;
        cin >> Operador;

        switch (Operacao) {
        case '+':
        cout << endl << "Resultado: " << Operando + Operador << endl;
        break;
        case '-':
        cout << endl << "Resultado: " << Operando - Operador << endl;
        break;
        case '*':
        cout << endl << "Resultado: " << Operando * Operador << endl;
        break;
        case '/':
        if (Operador != 0) {
            cout << endl << "Resultado: " << Operando / Operador << endl;
        } else {
            cout << endl << "Erro! Divisao por zero eh impossivel!" << endl;
        }

        break;
        default:
        cout << endl <<"Operacao nao reconhecida" << endl;
        }
}

if (Comando == "\n") {
goto Cmd;
}

if ((Comando == "Itatexto.crasp") || (Comando == "ITATEXTO.CRASP")) { // 
    // goto menu;
    PiscaTela ();
    Itatexto ();
}
if ((Comando == "ITADOSGRAPH.CRASP") || (Comando == "Itadosgraph.crasp")) { // 

    // goto menu;
    ShowConsoleCursor(false);
    PiscaTela ();
    gotoxy (10,5);
    cout << "BOOTING ITADOSGRAPH..." << endl;
    gotoxy (0,0);
    Efeito_tela ();
    goto ENDCMD;
}

if ((Comando == "disk") || (Comando == "DISK")) {
        cout << endl;
        cout << "Unidades de armazenamento disponiveis:" << endl;
        cout << endl;
        cout << "HDD.1: ITACHD/" << endl;
        cout << "Drive A: " << DiskALabel << endl;
        cout << "Drive B: " << DiskBLabel << endl;
        cout << "CD ROM: Empty " << endl;
        cout << endl;
}

if ((Comando == "config") || (Comando == "CONFIG")) { //  //*PNM
     cin >> Subcomando;
          if (Subcomando == "?") {
        cout << endl;
        cout << "Comando CONFIG - atributos possiveis:" << endl;
        cout << endl;
        cout << "SAVECONFIG - Salva todas as configuracoes" << endl;
        cout << "LOADCONFIG - Carrega config. pre definidas a partir de um arquivo" << endl;
        cout << "SETTIME - Define a hora e data" << endl;
        cout << "SCRCOLOR - Define a combinacao de cores do console" << endl;
        cout << "SYSTEM - Configura parametros de funcionamento do sistema e boot" << endl;
        cout << "PROMPT - Configura padroes e layouts do cmd" << endl;
        cout << "ECO - Altera o modo de uso da luz do monitor" << endl;
        cout << "RES - Altera o modo de exibicao / resolucao da tela" << endl;
        cout << "FILEATR - Liga ou desliga avisos de operacoes, exclusao, sobrescrevemento e copia de arquivos" << endl;
        cout << "LANGUAGE - Importa uma linguagem / idioma para o cmd a partir de um arquivo" << endl;
        cout << "SUDO - Determina parametros de usuario / administrador" << endl;
        cout << "INFOSYSTEM - Informa o tipo de arquitetura do sistema" << endl;
        cout << "GENERAL / PREFERENCES - Carrega um programa de definicoes setup / altera modo de funcionamento dos discos" << endl;
        cout << "VIDEOMEMO / MEMORYTEST / DEBUG - Roda um teste de memoria, procura erros e exibe os registradores da CPU" << endl;
        cout << "BOOT - Configura os parametros de boot do sistema" << endl;
        cout << endl;
}
     if ((Subcomando == "settime")||(Subcomando == "SETTIME")) {
        system ("time");
}
 if ((Subcomando == "saveconfig")||(Subcomando == "SAVECONFIG")) {
        cout << "done" << endl;
}
 if (Subcomando == "scrbht-") {
        Brilho--;
        cout << Brilho << endl;
}
 if (Subcomando == "scrbht+") {
        Brilho++;
        cout << Brilho << endl;
}
if (Subcomando == "scrld") {
        cin >> LightDuration;
        cout << LightDuration << endl;
} // 
if (Subcomando == "scrcolor?") {
        system ("color ?");
} // 
if ((Subcomando == "scrcolor")||(Subcomando == "SCRCOLOR")) {
cin >> Corsys;
        system (("color " + Corsys).c_str());
} // 
if (Subcomando == "vbon") {
        ModoVibracao = 1;
        cout << "Modo vibratorio ativado" << endl;
} // 
if (Subcomando == "vboff") {
        ModoVibracao = 0;
        cout << "Modo vibratorio desativado" << endl;
}
if (Subcomando == "btrecoon ") {
        EconomiadeBateria = 1;
        cout << "Modo economico ativado" << endl;
}
if (Subcomando == "btrecooff") {
        EconomiadeBateria = 0;
        cout << "Modo economico desativado" << endl;
}
if (Subcomando == "build>setup_v143") {
cout << "Done" << endl;
}
if (Subcomando == "infosystem") {
cout << "X64 bits System" << endl;
}
if ((Subcomando == "boot")||(Subcomando=="BOOT")) { // arg param subcommand option propertie attributes
cin >> arg1;
    if (arg1 == "/A") { // auto mode
    cout << endl << "Boot automatico ativado" << endl;
    } else if (arg1 == "/L") {

    } else if (arg1 == "/D") {
    cout << endl << "Checagem de disco antes do carregamento do sistema ATIVADO" << endl;
    } else if (arg1 == "/R") {
    cout << endl << "Todas as configuracoes extras de boot foram removidas com sucesso" << endl;
    }
}

}



if ((Comando == "var")||(Comando == "VAR")) { /// CRIA UMA VARIAVEL //////////////////////////////////
        cin >> Varname;
     cin >> Var;

     Variaveis [Vi] = Var;
     VariaveisNome [Vi] = Varname;
     Vi++;
}
if ((Comando == "PRINTVAR")||(Comando == "printvar")) { /// IMPRIME O VALOR DE UMA VARIAVEL ////////
     cin >> varImprimir;
     for (int i = 0; i < 40; i++) {
        if (varImprimir == VariaveisNome [i]) {
            cout << (int) Variaveis [i] << endl;
            break;
        }
     }

}
// NEW VAR CREATEVAR INT "*MEMO:VAR
if ((Comando == "CHANGEVAR")||(Comando == "changevar")||(Comando == "CHVAR")||(Comando == "chvar")) { /// MUDA O VALOR DE UMA VARIAVEL //////
     //cin >> Vi;
     cin >> varImprimir;

     cin >> NovoValor;
    // Variaveis [Vi] = NovoValor;
    for (int i = 0; i < 40; i++) {
        if (varImprimir == VariaveisNome [i]) {
            Variaveis [i] = NovoValor;
            break;
        }
     }
}
if (Comando == "CRTARR") { /// CRIA UM ARRAY //////////////////////////////////////////////////
     cin >> Vi;
     cin >> NovoValor;
     Variaveis [Vi] = NovoValor;
}
if (Comando == "MALLOC") { /// MEMO ALLOC //////////////////////////////////////////////////
     cin >> Vi;
     cin >> NovoValor;
     Variaveis [Vi] = NovoValor;
}
if (Comando == "REGBIT") { /// RESERVA BITS //////////////////////////////////////////////////
     cin >> Vi;
     cin >> NovoValor;
     Variaveis [Vi] = NovoValor;
}

if ((Comando == "pchar") || (Comando == "PCHAR")) {
    cin >> NovoValor;
    cout << (char) NovoValor;
}

if (Comando == "point") {
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "Line found, on <35> up, <4> left" << endl;
}

if ((Comando == "jump" ) || (Comando == "JUMP" )) {
        cin >> X;
        cin >> Y;
    gotoxy (X,Y);
  //  goto Comd;
}


if ((Comando == "scrwrite" )|| (Comando == "SCRWRITE" )) {
        string Scrwrite;
        cin >> Scrwrite;
        cout << Scrwrite;
  //  goto Comd;
}

if ((Comando == "echo" ) || (Comando == "ECHO" )) {
        string Scrwrite;
        getline (cin, Scrwrite);
        cout << Scrwrite << endl;
  //  goto Comd;
}

if ((Comando == "@echo" ) || (Comando == "@ECHO" )) {
cin >> arg1;
if (arg1 == "off") {
Padron = " ";
Padron1 = 1;
} else if (arg1 == "on") {
Padron = "ITACHD_/";
Padron1 = 1;
} else {
Padron = "> ";
Padron1 = 1;
}

if ((Comando == "newln" ) || (Comando == "NEWLN" ) || (Comando == "echo." ) || (Comando == "ECHO." )) {
    cout << endl;
    cout << endl;
}

  //  goto Comd;
}
if ((Comando == "Padron" )||(Comando == "padron" )||(Comando == "PADRON" )) {
        cin >> Padron;
        cout << "O texto padrao foi definido como " << Padron << endl;
        Padron1=1;
  //  goto Comd;
}
if ((Comando == "Textreset" )||(Comando == "textreset" )||(Comando == "TEXTRESET" )) {
        Padron1 = 0;
        cout << "O texto padrao foi redefinido"<< endl;
  //  goto Comd;
}
if ((Comando == "version" )||(Comando == "VERSION" )) {
        cout << "Current Version 1.8.3 0000134020180127"<< endl;
  //  goto Comd;
}
if (Comando == "verify" ) {
        cin >> Arquivoaprocurar;
        system (("if exist " + Arquivoaprocurar + " echo arquivo existe").c_str());
        system (("if not exist " + Arquivoaprocurar + " echo o arquivo nao foi encontrado").c_str());

}
if ((Comando == "if") || (Comando == "IF")) { // 
    cin >> Condicao;
    cout << " [";
    cin >> Subcomando;
    cout << " ]" << endl;
}
if ((Comando == "for") || (Comando == "FOR")) { // 
    cin >> Condicao;
    cout << " [";
    cin >> Subcomando;
    cout << " ]" << endl;
}



if ((Comando == "sudo")||(Comando == "SUDO")) {
    cin >> Subcomando;
     if (Subcomando == "login") {
        cout << "No server available"<< endl;
}
 if (Subcomando == "connect_wlan") {
        cout << "done" << endl;
}
 if (Subcomando == "?") {
        cout << " Comando SUDO - Parametros Possiveis" << endl << endl;
        cout << " SU - Entra no modo de superusuario" << endl;
        cout << " LOGIN - Conecta no servidor principal definido nas definicoes" << endl;
        cout << " GET_PACKAGE - Procura por um pacote de instalador de bibliotecas/aplicativos online" << endl;
        cout << " BOOST - Reseta e atualiza todas a conexoes locais" << endl;
        cout << " CONFIG_BOOTLOADER - Muda o modo de uso / config padrao de boot / sistema a ser bootado" << endl;
        cout << " CHANGE_PASSWORD - Altera a senha do usuario" << endl;
        cout << " REBOOT - Reseta o Terminal" << endl;
        cout << " ACESS - Acessa servidor especifico ou banco de dados" << endl;
        cout << " RUNDEV - Inicializa verificacao automatica do sistema" << endl;
        cout << " TOOLS - Disponibiliza todas as possibilidades do toolkit SUDO" << endl << endl;
}
 if (Subcomando == "get_package") {
        Brilho--;
        cout << Brilho << endl;
}
 if (Subcomando == "boost") {
        Brilho++;
        cout << Brilho << endl;
}
if (Subcomando == "config_bootloader") {
        cin >> LightDuration;
        cout << LightDuration << endl;
} // 
if (Subcomando == "change_password") {
        cin >> pin2;
} // 
if (Subcomando == "reboot") {
//ShowConsoleCursor(false);
ShowConsoleCursor(false);
system ("cls");
system ("color 0a");
Sleep (3000);
ShowConsoleCursor(true);
goto Inic;
} // 
if (Subcomando == "acess") {
        ModoVibracao = 0;
 cout << "done" << endl;
}
if (Subcomando == "eco_mode") {
        EconomiadeBateria = 1;
        cout << "Modo economico ativado" << endl;
}
if (Subcomando == "var_mode") {
        EconomiadeBateria = 0;
        cout << "Modo memoria nucleo desativado" << endl;
}
if (Subcomando == "rundev") {
cout << "Done" << endl;
}
if (Subcomando == "su") {
    if (sudolock == true) {
    protecao ();
    } else {
    sudolock = false;
    }
//goto Protecao;
}

}

if (Comando == "Program" ) {
        cin >> Program;
        cout << "Funcao Programada para o CLI"<< endl;
  //  goto Comd;
}
if (Comando == "RunProgram" ) {
        cout << Program << endl;
        cout << "Funcao retornada para o CLI"<< endl;
  //  goto Comd;
}

if (Comando == "ConversordeDiabanos" ) {
        int Diabanos;
        cin >> Diabanos;
        cout << Program << endl;
        cout << Diabanos * (23548680 / 540000)<< endl;
  //  goto Comd;
}

if (Comando == "layout") { //NM
     cout << endl;
     system ("color"); // mod
}
if (Comando == "reload_ls") { // CARREGA A ULTIMA SESSAO LOGADA NO SUDO
     cout << endl;
     system ("color"); // mod
}
///  /////////////////////////////////
if ((Comando == "run") || (Comando == "RUN")) { //NM
     cin >> AplicacaoRodar;
     if ((AplicacaoRodar == "Snake.crasp") || (AplicacaoRodar == "SNAKE.CRASP")) {
        Snake ();
     } else if ((AplicacaoRodar == "itatexto.crasp") || (AplicacaoRodar == "ITATEXTO.CRASP")) {
	PiscaTela ();
	Itatexto ();
     } else if ((AplicacaoRodar == "unzip") || (AplicacaoRodar == "UNZIP")) {
        cout << "files extracted uscessfully. " << endl;
     } else if ((AplicacaoRodar == "ITADOSGRAPH.CRASP") || (AplicacaoRodar == "itadosgraph.crasp")) {
	ShowConsoleCursor(false);
    	PiscaTela ();
    	gotoxy (10,5);
    	cout << "BOOTING ITADOSGRAPH..." << endl;
    	gotoxy (0,0);
    	Efeito_tela ();
    	goto ENDCMD;
     } else if ((AplicacaoRodar == "calc.crasp") || (AplicacaoRodar == "CALC.CRASP")) {
	goto RUNCALC;
     } else {
     //cout << "O sistema nao pode encontrar a aplicacao ou comando solicitado " << endl;
     string avx = "";
     avx = "CMD " + AplicacaoRodar;
     system (avx.c_str());
     }

}

if ((Comando == "abr") || (Comando == "ABR")) {
    string arqAbr = "";
    string axx = "";
    cin >> arqAbr;
     cin >> AplicacaoRodar;
     if ((AplicacaoRodar == "itatexto") || (AplicacaoRodar == "ITATEXTO")) {
	PiscaTela ();
	axx = "./ITATEXTO " + arqAbr;
	system (axx.c_str());
     }

}

if ((Comando == "xrun") || (Comando == "XRUN")) {
    cin >> arg1;
    system (arg1.c_str());
}
if (Comando == "conscolor" ) {
    int coraux = 0;
    cin >> coraux;
    Cor (coraux);
}
if (Comando == "VGA_testcolor" ) {
      HANDLE  hConsole;
    	int k;

      hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
      // you can loop k higher to see more color choices
      for(k = 1; k < 255; k++)
      {
        // pick the colorattribute k you want
        SetConsoleTextAttribute(hConsole, k);
        cout << k << " Como o mundo eh mais bonito se colorido!!! " << endl;
      }

      cin.get();
}





if ((Comando == "help") || (Comando == "?") || (Comando == "HELP")) {
     //getline (cin, Subcomando);
     cin >> Subcomando;
     if (Subcomando == "?") {
     cout << endl;
     cout << "principais comandos: " << endl; // comandos mais relevantes do sistema
     cout << "cd" << endl; // comandos de navegacao de diretorios miscelaneous
     cout << "dir" << endl;
     cout << "copy" << endl;
     cout << "cls" << endl; // 
     cout << "crd" << endl; // 
     cout << "echo" << endl;
     cout << "del" << endl;
     cout << "dir" << endl; // 
     cout << "config" << endl;
     cout << "exit" << endl;
     cout << "sudo" << endl;
     cout << "run" << endl;
     cout << "pause" << endl;
     cout<< endl << endl << "Digite 'help + nome do comando' para consultar a sintaxe e o modo de uso de um comando" << endl << endl; // saber obter mostrar, conhecer os parametros
     cout << endl << " Digite guide para ver uma lista com todos os comandos do sistema" << endl; // dados indisponiveis instrucoes informacoes sequencia de caracteres
     } else if (Subcomando == "cd") {
     cout << endl;
     cout << "Comando CD: modo de uso" << endl;
	cout << "CD + nome do diretorio" << endl;

     } else if (Subcomando == "copy") {
     cout << endl;
     cout << "Comando COPY: modo de uso" << endl;
	cout << "copy + nome do arquivo a copiar + destino da copia" << endl;

     } else if (Subcomando == "crd") {
     cout << endl;
     cout << "Comando CRD: modo de uso" << endl;
	cout << "CRD + nome da pasta a criar" << endl;

     } else if (Subcomando == "run") {
     cout << endl;
     cout << "Comando RUN: modo de uso" << endl;
	cout << "RUN + nome do programa ou batch a executar" << endl;

     } else if (Subcomando == "abr"){
     cout << endl;
     cout << "Comando ABR: modo de uso" << endl;
	cout << "ABR + nome do arquivo que deseja abrir + nome do programa" << endl;

     } else if (Subcomando == "echo") {
     cout << endl;
     cout << "Comando ECHO: modo de uso" << endl;
	cout << "USO GERAL: imprime uma linha de texto na tela, uma string já declarada ou uma variavel do sistema" << endl;
	cout << "Possiveis usos e parametros:" << endl;
	cout << "echo$ - imprime uma string na tela sem quebra de linha no final. Sintaxe: echo$ string" << endl;
	cout << "echo$! - imprime uma string na tela com quebra de linha no final. Sintaxe: echo$! string" << endl;
	cout << "echo - imprime uma linha de texto simples na tela, com quebra de linha. Sintaxe: echo + texto" << endl;
	cout << "Parametros adicionais: " << endl;
	cout << "# - imprime o texto ou string na tela em uma cor especificada. Ex: echo$#0a! string1; imprimira a string 1 com a cor de texto verde claro e fundo preto" << endl;
	cout << "! - imprime quebra de linha no final" << endl << endl << endl;

     } else {
     cout << endl;
     cout << "outros comandos: consulte o guia [guide] para mais informacoes" << endl;

     }

}

if ((Comando == "guide") || (Comando == "GUIDE")) { //NM
     cout << endl;
     cout << "Ita DOS Command Guide" << endl;
     cout << endl;
     cout << "abr - Abre um arquivo ou / com aplicacao" << endl;
     cout << "calc - Calculadora" << endl;
     cout << "cd - Muda a pasta atual" << endl;
     cout << "cdr - Muda a o destino do arquivo" << endl;
     cout << "crd - Cria uma pasta" << endl;
     cout << "create - Cria um arquivo ou pasta novos" << endl;
     cout << "changevar - Altera o valor de uma variavel" << endl; // novo
     cout << "cls - Limpa a tela" << endl; //  /
     cout << "convert - Converte um parametro ou extensao de arquivo em outro" << endl;
     cout << "config - Define as preferencias do sistema, do PC e da interface" << endl; // novo
     cout << "copy - Copia um arquivo" << endl; //  /
     cout << "data - Carrega a ultima edicao de dados de um backup externo" << endl;
     cout << "del - Deleta um arquivo (enviando para a lixeira) / apaga defitivamente caso na lixeira" << endl;
     cout << "dir - Mostra os arquivos presentes em uma pasta" << endl; //  /lista os diretorios e arquivos de uma pasta
     cout << "disk - Lista as unidades de disco do computador" << endl;
     cout << "exit - Fecha todos os aplicativos" << endl;
     cout << "echo - Imprime uma linha de texto (string) ou variavel na tela" << endl; // TDMSC
     cout << "end - Finaliza o parametro" << endl;
     cout << "goto - Vai para o ponto de referencia (linha) inserido" << endl;
     cout << "help - Mostra itens de ajuda e instrucoes / consulta o modo de uso de um comando" << endl; // novo
     cout << "info - Exibe informacoes / status do sistema / PC" << endl; // novo
     cout << "jump - Posiciona o cursor em uma determinada posicao x e y" << endl; // novo
     cout << "last - carrega o ultimo aplicativo aberto no disco" << endl;
     cout << "path - mostra o endereco da pasta atual" << endl;
     cout << "pause - Pausa qualquer acao do console" << endl;
     cout << "printvar - imprime uma variavel numerica na tela" << endl;
     cout << "pchar - imprime um caractere ASCII na tela" << endl;
     cout << "run - Iniciar um programa, comando ou arquivo em BAT" << endl;
     cout << "ret - Retorna um determinado valor a quem chamou / fecha um programa" << endl; // NM
     cout << "scrwrite - imprime uma string ou texto na tela, sem quebra de linha no final" << endl; // NM
     cout << "string - Cria uma string na memoria" << endl; // NM
     cout << "sudo - Efetua comandos, funcoes e programas no modo de superusuario (com todas as permissoes)" << endl; // novo
     cout << "textreset - Reseta o texto padrão do prompt de comando" << endl; // novo
     cout << "undel - recupera um arquivo enviado para a lixeira" << endl;
     cout << "var - cria uma variavel local / do sistema / reserva um espaco de memoria (/m)" << endl; // novo
     cout << "version - Exibe/ Mostra a versao atual do sistema" << endl;
     cout << "verify - verifica a existencia do arquivo especificado" << endl;
     cout << "xrun - roda um programa .BAT ou .EXE" << endl;
     cout << endl;
     cout << "Digitar '?' como parametro universal para o comando que deseja saber seu modo de uso, seus subcomandos e seus parametros" << endl;
     cout << "memo* atua como comando de referencia/detino ou gerencia as acoes na memoria RAM do PC" << endl;
     cout << endl;
}
goto Cmd;
ENDCMD:
    CDX = 0;
    CDY = 0;
    Autoboot = "";
    return false;
}

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

// FUNCOES DE IMPRESSAO DAS TELAS

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
cout<<"|  |_____|               | A:                                      |-|O|X|              |____|    |"<<endl;
cout<<"|  v     v               |-----------------------------------------------|                        |"<<endl;
cout<<"|  Itac HD               |                                               |               Dos      |"<<endl;
cout<<"|                        |                                               |                        |"<<endl;
cout<<"|   ____                 |                                               |               ___=_    |"<<endl;
cout<<"|  |   |_                |                                               |              |    |    |"<<endl;
cout<<"|  | O  |                |                                               |              |____|    |"<<endl;
cout<<"|  |___A|                |                                               |                        |"<<endl;
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

void Tela_DiscoB () {
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
cout<<"|  |___A|                |                                               |                        |"<<endl;
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

void Tela_SelecionarDisco () {
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
}

void Tela_PastaTools () {
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
cout<<"|  |___A|                | |CMD|    |RUN|                                |                        |"<<endl;
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
}

void Tela_DeskColor () {
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
cout<<"|  |   |                |          |  | PRETO              |  | PRETO    |              |    |    |"<<endl;
cout<<"|  | O  |               |           --                      --           |              |    |    |"<<endl;
cout<<"|  |___E|               |           __                      __           |              ______    |"<<endl;
cout<<"|                       |          |  | VERDE              |  | AMARELO  |          Meus Arquivos |"<<endl;
cout<<"|    A:                 |           --                      --           |                        |"<<endl;
cout<<"|                       |           __                      __           |                        |"<<endl;
cout<<"|  _____     __o__      |          |  | VERMELHO           |  | VERDE    |                        |"<<endl;
cout<<"|  |   |     |   |      |           --                      --           |                        |"<<endl;
cout<<"|  | O  |    |   |      |                         _________   _______    |                        |"<<endl;
cout<<"|  |___E|    |___|      |                        | CANCEL  | | SAVE  |   |                        |"<<endl;
cout<<"|                       |________________________________________________|                        |"<<endl;
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
cout<<"|  _____                       |  RESOLUCAO VGA 160X60      |                           ____-_    |"<<endl;
cout<<"|  |   |                       |    NAO SUPORTA MODO DE     |                           |    |    |"<<endl;
cout<<"|  | O  |                      |    TELA CHEIA (FULSCREEN)  |                           |____|    |"<<endl;
cout<<"|  |   E|                      |   ________                 |                                     |"<<endl;
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

void Tela_SelectInput () {
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
}

void Tela_ConfirmaFormatar () {
/*cout<<"|_________|||CANCELAR|||____|||OK!|||_____________________________________________________________| "<<endl;
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
*/
gotoxy (32,8);
cout << "_________________________" ;
gotoxy (32,9);
cout << "| TEM CERTEZA QUE DESEJA|" ;
gotoxy (32,10);
cout << "|  FORMATAR O DISCO ?   |" ;
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

///

class MouseInputHandler
{
      //mouse input handler callback function pointer
      typedef void (*MIHCB)(int,int,void*);

      public:
      MouseInputHandler(){}
      ~MouseInputHandler(){}
      void init();

      inline void start_polling()
      {
             _beginthread(polling_function,0,this);
             polling=true;
      }

      inline void stop_polling()
      {
             input.quit=true;
             while (polling);
      }

      int getx();
      int gety();
      void getxy(int & x, int & y);

      //setting the callbacks
      inline void set_lbdcb(MIHCB f){lbdcb=f;}
      inline void set_lbucb(MIHCB f){lbucb=f;}
      inline void set_lbccb(MIHCB f){lbccb=f;}
      inline void set_rbdcb(MIHCB f){}
      inline void set_rbucb(MIHCB f){}
      inline void set_rbccb(MIHCB f){}

      //setting the params for the callbacks
      inline void set_lbdcbp(void*p){lbdcbp=p;}
      inline void set_lbucbp(void*p){lbucbp=p;}
      inline void set_lbccbp(void*p){lbccbp=p;}
      inline void set_rbdcbp(void*p){}
      inline void set_rbucbp(void*p){}
      inline void set_rbccbp(void*p){}

      private:
      struct MouseInput
      {
             //current and previous mouse button status
             bool cleft, pleft;
             bool cright, pright;

             bool quit;
             int x,y;

      } input;

      bool polling;

      static void polling_function(void*);
      static inline bool is_pressed(int key)
      {
             return (GetAsyncKeyState(key)>>15);
      }

      MIHCB lbdcb;
      MIHCB lbucb;
      MIHCB lbccb;
      MIHCB rbdcb;
      MIHCB rbucb;
      MIHCB rbccb;

      void* lbdcbp;
      void* lbucbp;
      void* lbccbp;
      void* rbdcbp;
      void* rbucbp;
      void* rbccbp;

};

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

	  if ((x < 100) && (y < 30)) {
           gotoxy(x,y);
           cout << M;
           gotoxy (x,y+1);
           //cout << "|";
           cout << MB;
	    }
            if (Parte == 25) {
                if ((x < 27) || (x > 47)) { /// FECHA O MENU DISCO
                    if ((y < 0) || (y > 7)) {
                        Parte = 1;
                    }

                }
            }

           gotoxy(0,0);
           //Sleep(25);
           if (atualizarTela) {
           system("cls");
           }

int ClickDos = 0;
if (Parte == 2) {
Tela_DOS();
}else if (Parte == 1){
    TelaPrincipal();
} else if (Parte == 4) {
Tela_Lixeira();
} else if (Parte == 5) {
    if ( ! ((DiskAFile == "NONE") || (DiskAFile == "none"))) {
Tela_DiscoB ();
gotoxy (30,7);
cout << DiskBLabel;
if (ModoVisualisar == "Icons") {
PrintDiskIcons ('B');
} else {
PrintDiskFiles ('B');
}
    } else {
Tela_NaoHaDiscos ();
    }

} else if (Parte == 6) {
Tela_MenuPrincipal ();
} else if (Parte == 7) {
Tela_Info ();
} else if (Parte == 8) {
Tela_MenuArquivo();
}
else if (Parte == 9) {
        if ( ! ((DiskAFile == "DEFAULT") || (DiskAFile == "DEFAULT"))) {
Tela_DiscoAVazio ();
gotoxy (30,7);
cout << DiskALabel;
if (ModoVisualisar == "Icons") {
PrintDiskIcons ('A');
} else {
PrintDiskFiles ('A');
}
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
gotoxy (30,7);
cout << DiskALabel;

        }


} else if (Parte == 13) {
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
cout<<"|  _____                       | COPIAR DE :" << ArquivoCopiar << " _SELEC.ARQ._  |                           ____-_    |"<<endl;
cout<<"|  |   |                       |                            |                           |    |    |"<<endl;
cout<<"|  | O  |                      |  PARA : " << DestinoCopia << "   _SELEC.DEST_  |                           |    |    |"<<endl;
cout<<"|  |___E|                      |   ________     ________    |                           ______    |"<<endl;
cout<<"|                              |  | CANCEL |   | COPIAR |   |                       Meus Arquivos |"<<endl;
cout<<"|    A:                        |____________________________|                                     |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|  _____     __o__                                                                                |"<<endl;
cout<<"|  |   |     |||||                                                                                |"<<endl;
cout<<"|  | O  |    |||||                                                                                |"<<endl;
cout<<"|  |___E|    |||||                                                                                |"<<endl;
cout<<"|            Lixo                                                                                 |"<<endl;
cout<<"|    B:                                                                                           |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"__________________________________________________________________________________________________"<<endl;
} else if (Parte == 15) {
cout<<"|_________|||CANCELAR|||_______________COPIA_DE_DISCO_____________________________________________| "<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                       ______    |"<<endl;
cout<<"|  _______                                                                              |>   |    |"<<endl;
cout<<"|  |o    |                                                                              |    |    |"<<endl;
cout<<"|  _______                                                                              |    |    |"<<endl;
cout<<"|  v     v                                                                              ______    |"<<endl;
cout<<"|  Itac HD                      ___________________________                             Dos      |"<<endl;
cout<<"|                              |                            |                                     |"<<endl;
cout<<"|  _____                       |  COPIAR DE : _SELEC.DISC._ |                           ____-_    |"<<endl;
cout<<"|  |   |                       |                            |                           |    |    |"<<endl;
cout<<"|  | O  |                      |  PARA : " << DestinoCopia << "   _SELEC.DEST_  |                           |    |    |"<<endl;
cout<<"|  |___E|                      |   ________     ________    |                           ______    |"<<endl;
cout<<"|                              |  | CANCEL |   | COPIAR |   |                       Meus Arquivos |"<<endl;
cout<<"|    A:                        |____________________________|                                     |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|  _____     __o__                                                                                |"<<endl;
cout<<"|  |   |     |||||                                                                                |"<<endl;
cout<<"|  | O  |    |||||                                                                                |"<<endl;
cout<<"|  |___E|    |||||                                                                                |"<<endl;
cout<<"|            Lixo                                                                                 |"<<endl;
cout<<"|    B:                                                                                           |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"|                                                                                                 |"<<endl;
cout<<"__________________________________________________________________________________________________"<<endl;
} else if (Parte == 16) {
    Tela_SelecionarDisco ();
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
Tela_MenuDisco ();
} else if (Parte == 21) {
Tela_SelectInput ();
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
    Tela_PastaTools ();
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
cout<<"|   ___                 |   ___________                    ________      |              ____-_    |"<<endl;
cout<<"|  |   |                |  | DESK COLOR|     KEYBOARD SCT | " << KBSct << /*ENABLED*/"|     |              |    |    |"<<endl;
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
} else if (Parte == 25) {
Tela_MenuView ();
    if (ModoVisualisar == "Icons") {
        gotoxy (41,1);
        cout << "*";
    } else if (ModoVisualisar == "Text") {
        gotoxy (41,2);
        cout << "*";
    }
} else if (Parte == 26) {
    Tela_DeskColor ();
} else if (Parte == 28) {
    Tela_NaoSuportaVGA ();
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
Tela_ITACHD ();
}


if (CDX == 90 /*& CY == 6*/) { /// DOS
    if (SelecDestino == true) {
        MsgErrCopiarInv ();
    } else {
    if ((Aplicacao != "Calc") && (Aplicacao != "Itadraw")) { Parte = 2 ; }
        //Parte = 2;
}

}
if ((CDX >= 3 /*& CY == 7*/) && (CDX < 9)) { /// ITAC HD
        if ((CDY >= 6) && (CDY < 8)) {
          Parte = 3;
        }

}
if ((CDX >= 10 /*& CY == 7*/) && (CDX < 18)) { /// MENU ARQUIV0
      if  ((CDY >= 1) && (CDY < 3)) {
          if ((Parte == 1) || (Parte == 3) || (Parte == 23) || (Parte == 9)) {
                    CDX = 0;
          CDY = 0;
          Parte = 8;
          }

        }

}
if ((CDX >= 29 /*& CY == 7*/) && (CDX < 39)) { /// MENU DISCO
      if  ((CDY >= 1) && (CDY < 3)) {
          Parte = 20;
        }

}
if ((CDX >= 56 /*& CY == 7*/) && (CDX < 70)) { /// MENU CONFIG
      if  ((CDY >= 1) && (CDY < 3)) {
          Parte = 24;
        }

}
if ((CDX >= 41 /*& CY == 7*/) && (CDX < 54)) { /// MENU VISUALIZAR
      if  ((CDY >= 1) && (CDY < 3)) {
          Parte = 25;
        }

}
if ((CDX >= 3 /*& CY == 7*/) && (CDX < 8)) { /// DISCO B 2 4
    if ((CDY >= 19) && (CDY < 22)) {
        if (DiskcopySelect == true) {
          if (SelecDestino == false) {
          ArquivoCopiar = "B:";
          SelecDestino = true;
          } else {
          DestinoCopia = "B:";
          }
    } else if (FormatSelect == true) {
        Tela_ConfirmaFormatar ();
        Tecla = getch ();
        if (Tecla = 's') cout << "FORMATANDO DISCO...";
        else if ((Tecla = 'N') || (Tecla = 'n')) {
            FormatSelect = false;
        }
    } else {
    Parte = 5;
    }

    }
}

if ((CDX >= 3  ) && (CDX < 8)) { /// DISCO A (DRIVER 0)
    if ((CDY >= 12) && (CDY < 15)) {
    if (DiskcopySelect == true) {
        if (SelecDestino == false) {
          ArquivoCopiar = "A:";
          SelecDestino = true;
          } else {
          DestinoCopia = "A:";
          }
    } else if (FormatSelect == true) {
        Tela_ConfirmaFormatar ();
        Tecla = getch ();
        if (Tecla = 's') cout << "FORMATANDO DISCO...";
        else if ((Tecla = 'N') || (Tecla = 'n')) {
            FormatSelect = false;
        }
    }else {
    Parte = 9;
    }
        //Parte = 9;
    }
}

// X DE FECHAR AS JANELAS
if ((CDX == 72 ) && (CDY == 7)) {
    Parte = 1 ;
}
if (CDX == 29 /*& CY == 7*/) { ///  ICONE DE PASTA (ITAC)
        if ((CDY == 11) || (CDY == 10)) {
            if (Parte == 3) {
            Efeito_tela ();
            Autoboot = "ITADOSGRAPH.CRASP";
            Cmd ();
            CDX = 0;
            CDY = 0;
            }

        }

}
if (CDX == 37 /*& CY == 7*/) { ///  PASTA TOOLS (ITAC HD)
        if ((CDY == 11) || (CDY == 10)) {
            if (Parte == 3) {
            Parte = 23;

            }

        }

}
if ((CDX >= 52 /*& CY == 7*/) && (CDX < 54)) { ///  README (ITAC HD)
        if ((CDY == 10) || (CDY == 11)) {
            if (Parte == 3) {
                  Parte = 12;
                    Efeito_tela (); ///ITATEXTO
                    ArqAbrirItatexto = "Readme.txt";
                    Itatexto ();
                    Parte = 1;
                    CDX = 0;
                    CDY = 0;
                    PiscaTela ();
                    ArqAbrirItatexto = "";
                    system (("color " + CorFundo + CorFonte).c_str ());
            //Parte = 7;
            }
        }
}

if ((CDX >= 37 /*& CY == 7*/) && (CDX < 40)) { ///  MEMO ALLOC (ITAC HD/TOOLS)
        if ((CDY == 14) || (CDY == 13)) {
            if (Parte == 23) {
                  Parte = 12;
                    Efeito_tela (); ///ITATEXTO
                    MemoAlloc ();
                    Parte = 1;
                    CDX = 0;
                    CDY = 0;
                    system (("color " + CorFundo + CorFonte).c_str ());
            //Parte = 7;
            }
        }
}

if (CDX == 68 /*& CY == 7*/) { ///  VOLTAR PARA PASTA RAIZ
        if (CDY == 7) {
            if (Parte == 23) {
            Parte = 3;
            //Parte = 7;
            }

        }

}
if ((CDX >= 13 /*& CY == 7*/) && (CDX < 17)) { /// CAIXA DE TEXTO MESAGEM DA LIXEIRA
        if ((CDY >= 19) && (CDY < 21)) {
    if (SelecDestino == true) {
        MsgErrCopiarInv ();
    } else {
    if ((Aplicacao != "Calc") && (Aplicacao != "Itadraw")) { Parte = 4 ; }

    }
        }

}
if ((CDX >= 34 /*& CY == 7*/) && (CDX < 43)) { /// CAIXA DE TEXTO MESAGEM DA LIXEIRA (FECHAR) 35 a 42
    if ((CDY == 15) || (CDY == 13)) {
    if ((Aplicacao != "Calc") && (Aplicacao != "Itadraw") && (Parte != 3)) {

    Parte = 5;
//Sleep (300);
    Parte = 1 ;

     }
    }

}
if ((CDX >= 1 /*& CY == 7*/) && (CDX < 9)) { /// MENU PRINCIPAL (ITAC)
if ((CDY >= 1) && (CDY < 3)) {
Parte = 6;
}

}

if (CDX == 6) { /// SAI DO MENU ITAC
        if (CDY == 10) {
 Parte = 1;
 Aplicacao = "";
        }


}
if (CDX == 18 /*& CY == 7*/) { /// FECHA O MENU ARQUIVO
        if (CDY == 6) {
            if (Parte == 8) {
            Parte = 1;
            }

        }

}
if (CDX == 48 /*& CY == 7*/) { /// FECHA O MENU VISUALIZAR
        if (CDY == 6) {
            if (Parte == 20) {
            Parte = 1;
            }

        }

}
/*if ((x < 27) || (x > 47)) { /// FECHA O MENU DISCO
        if ((y < 0) || (y > 7)) {
            if (Parte == 25) {
            Parte = 1;
            }

        }

}*/
if (CDX == 41 /*& CY == 7*/) { ///  OPCAO DE VISUALIZAR COMO ICONES
        if (CDY == 1) {
            if (Parte == 25) {
            ModoVisualisar = "Icons";
            }

        }

}
if (CDX == 41 /*& CY == 7*/) { ///  OPCAO DE VISUALIZAR COMO LISTA DE ARQUIVOS
        if (CDY == 2) {
            if (Parte == 25) {
            ModoVisualisar = "Text";
            }

        }

}
if (CDX == 41 /*& CY == 7*/) { ///  OPCAO DE VISUALIZAR JANELAS COMO FULSCREEN (TELA CHEIA)
        if (CDY == 5) {
            if (Parte == 25) {
             if ((ColunasVGA < 160 ) && (LinhasVGA < 60)) { /// SE A RESOLUCAO VGA FOR INFERIOR A ISSO, NAO E POSSIVEL MODO FULSCREEN
                Parte = 28;
             }
            }

        }

}

/// MENU PRINCIPAL

if ((CDX >= 6) && (CDX < 18)) { /// MOSTRA A INFO DO SISTEMA
        if (CDY == 3) {
            if (Parte == 6)
            Parte = 7;
        }

}
if ((CDX >= 1) && (CDX < 18)) { /// CARREGA O CMD
        if (CDY == 9) {
            if (Parte == 6) {
            Efeito_tela ();
            Cmd ();

            }

        }

}
if ((CDX >= 1) && (CDX < 18)) { /// ABRE A JANELA DE SELECAO DE INPUTS/OUTPUTS
        if (CDY == 5) {
            if (Parte == 6) {
            //Efeito_tela ();
            Parte = 21;

            }

        }

}

if ((CDX >= 1) && (CDX < 18)) { /// ABRE CONFIGURACAO DE IMPRESSORA
        if (CDY == 6) {
            if (Parte == 6) {
            cout << "PARA CONFIGURAR A IMPRESSORA E NECESSARIO IMPORTAR OS DRIVES ANTES";

            }

        }
}

if ((CDX >= 1) && (CDX < 18)) { /// CARREGA UM PROGRAMA
        if (CDY == 7) {
            if (Parte == 6) {
            SelectProgramaExec ();
            gotoxy (38,13);
            getline (cin, AplicacaoRodar);
            if (AplicacaoRodar != "\n") {
                string avx = "";
                avx = "CMD " + AplicacaoRodar;
                system (avx.c_str());
            }
            system ("color f0");
            }

        }
}

//------


if ((CDX >= 63 /*& CY == 7*/) && (CDX < 68)) { /// BOTAO DONE JANELA DE INPUTS/OUTPUTS
        if (CDY == 19) {
            if ((Parte == 21) || (Parte == 22)) {
            //Efeito_tela ();
            Parte = 1;

            }

        }

}
if ((CDX >= 50 /*& CY == 7*/) && (CDX < 58)) { /// BOTAO CANCEL JANELA DE INPUTS/OUTPUTS
        if (CDY == 19) {
            if ((Parte == 21) || (Parte == 22)) {
            //Efeito_tela ();
            Parte = 1;
            //Parte = 7;
            }

        }

}
if (CDX == 42 /*& CY == 7*/) { /// BOTAO SET JANELA DE INPUTS/OUTPUTS
        if (CDY == 19) {
            if (Parte == 21) {
            //Efeito_tela ();
            Parte = 22;
            //Parte = 7;
            }

        }

}

if ((CDX >= 28 /*& CY == 7*/) && (CDX < 38)) { /// BOTAO SET PRINTER DA JANELA DE OPCOES DO SET
        if (CDY == 9) {
            if (Parte == 22) {
            //Efeito_tela ();
            //Parte = 22;
            //Parte = 7;
            cout << "PRINTER SET";
            }

        }

}

if ((CDX >= 28 /*& CY == 7*/) && (CDX < 38)) { /// BOTAO JOYSTICK DA JANELA DE OPCOES DO SET
        if (CDY == 12) {
            if (Parte == 22) {
            //Efeito_tela ();
            //Parte = 22;
            //Parte = 7;
            cout << "DISKDRIVE SET";
            }

        }

}

if ((CDX >= 28 /*& CY == 7*/) && (CDX < 38)) { /// BOTAO KEYBOARD DA JANELA DE OPCOES DO SET
        if (CDY == 15) {
            if (Parte == 22) {
            //Efeito_tela ();
            //Parte = 22;
            //Parte = 7;
            cout << "JOYSTICK SET";
            }

        }

}

if ((CDX >= 28 /*& CY == 7*/) && (CDX < 38)) { /// BOTAO OTHER PRINTER DA JANELA DE OPCOES DO SET
        if (CDY == 18) {
            if (Parte == 22) {
            //Efeito_tela ();
            //Parte = 22;
            //Parte = 7;
            cout << "SELECT THE PROPER CONFIGURATION FOR DRIVE";
            }

        }

}

///

if ((CDX >= 50 /*& CY == 7*/) && (CDX < 58)) { /// BOTAO CANCEL JANELA DE CONFIG
        if (CDY == 17) {
            if (Parte == 24) {
            //Efeito_tela ();
            Parte = 1;
            //Parte = 7;
            }

        } else if (CDY == 19) {
            if (Parte == 26) {
            Parte = 1;
            }
        }

}
if ((CDX >= 62 /*& CY == 7*/) && (CDX < 68)) { /// BOTAO SAVE JANELA DE CONFIG
        if (CDY == 17) {
            if (Parte == 24) {
            //Efeito_tela ();
            if (CorFundo != CorFonte)
                system (("color " + CorFundo + CorFonte).c_str ());
            else {
                gotoxy (0,HEIGHT+1);
                cout<< "AVISO: A COR DA FONTE NAO PODE SER A MESMA COR QUE A DE FUNDO";
                system ("pause>nul");
            }
            Parte = 1;
            //Parte = 7;
            }

        } else if (CDY == 19) {
            if (Parte == 26) {
            //Efeito_tela ();
            if (CorFundo != CorFonte)
                system (("color " + CorFundo + CorFonte).c_str ());
            else {
                gotoxy (0,HEIGHT+1);
                cout<< "AVISO: A COR DA FONTE NAO PODE SER A MESMA COR QUE A DE FUNDO";
                system ("pause>nul");
            }
            Parte = 1;
            //Parte = 7;
            }
        }

}
if ((CDX >= 42 /*& CY == 7*/) && (CDX < 47)) { /// BOTAO RESET JANELA DE CONFIG
        if (CDY == 17) {
            if (Parte == 24) {
            //Efeito_tela ();
            system ("color f0");
            MouseDelay = 0.5;
            KBSct = "ENABLED";
            //Parte = 7;
            }

        }

}
if ((CDX >= 59 /*& CY == 7*/) && (CDX < 66)) { /// BOTAO MOUSE DELAY JANELA DE CONFIG
        if (CDY == 7) {
            if (Parte == 24) {
            //Efeito_tela ();
                if (MouseDelay == 0.5) {
                    MouseDelay = 1.0;
                } else if (MouseDelay == 1.0) {
                    MouseDelay = 1.5;
                } else if (MouseDelay > 1.5) {
                    MouseDelay = 0.5;
                }
            //Parte = 7;
            }

        }

}
if ((CDX >= 59 /*& CY == 7*/) && (CDX < 66)) { /// BOTAO KBSCT JANELA DE CONFIG
        if (CDY == 10) {
            if (Parte == 24) {
            //Efeito_tela ();
                if (KBSct == "ENABLED") {
                    KBSct = "DISABL.";
                    CDX = 0;
                    CDY = 0;
                    x=0; y=0;
                }
                if (KBSct == "DISABL.") {
                    KBSct = "ENABLED";
                    CDX = 0;
                    CDY = 0;
                    x=0; y=0;
                }
            }

        }

}
if ((CDX >= 28 /*& CY == 7*/) && (CDX < 38)) { /// BOTAO SETCLOCK JANELA DE CONFIG
        if (CDY == 7) {
            if (Parte == 24) {
            //Efeito_tela ();
            SetTimeScreen();
            gotoxy (34,12);
            system ("time");
            //system ("cls");
            CDX = 0;
            CDY = 0;
            x = 0;
            y = 0;
            Parte = 24;
            //Parte = 7;
            }

        }

}
if ((CDX >= 28 /*& CY == 7*/) && (CDX < 38)) { /// BOTAO DESKCOLOR JANELA DE CONFIG
        if (CDY == 10) {
            if (Parte == 24) {
            //Efeito_tela ();
            Parte = 26;
            //Parte = 7;
            }

        }

}
///
if ((CDX >= 36 /*& CY == 7*/) && (CDX < 38)) { /// BOTAO COR DESKCOLOR
        if (CDY == 7) {
            if (Parte == 26) {
            CorFonte = "7";
            //Parte = 7;
            }

        }

}
if ((CDX >= 36 /*& CY == 7*/) && (CDX < 38)) { /// BOTAO COR DESKCOLOR
        if (CDY == 10) {
            if (Parte == 26) {
            CorFonte = "0";
            //Parte = 7;
            }

        }

}
if ((CDX >= 36) && (CDX < 38)) { /// BOTAO COR DESKCOLOR
        if (CDY == 13) {
            if (Parte == 26) {
            CorFonte = "a";
            //Parte = 7;
            }

        }

}
if ((CDX >= 36 /*& CY == 7*/) && (CDX < 38)) { /// BOTAO COR DESKCOLOR
        if (CDY == 16) {
            if (Parte == 26) {
            CorFonte = "c";
            //Parte = 7;
            }

        }

}
///---
if ((CDX >= 60 /*& CY == 7*/) && (CDX < 62)) { /// BOTAO COR FUNDO DESKCOLOR
        if (CDY == 7) {
            if (Parte == 26) {
            CorFundo = "f";
            //Parte = 7;
            }

        }

}
if ((CDX >= 60 /*& CY == 7*/) && (CDX < 62)) { /// BOTAO COR FUNDO DESKCOLOR
        if (CDY == 10) {
            if (Parte == 26) {
            CorFundo = "0";
            //Parte = 7;
            }

        }

}
if ((CDX >= 60 /*& CY == 7*/) && (CDX < 62)) { /// BOTAO COR FUNDO DESKCOLOR
        if (CDY == 13) {
            if (Parte == 26) {
            CorFundo = "e";
            //Parte = 7;
            }

        }

}
if ((CDX >= 60 /*& CY == 7*/) && (CDX < 62)) { /// BOTAO COR FUNDO DESKCOLOR
        if (CDY == 16) {
            if (Parte == 26) {
            CorFundo = "a";
            //Parte = 7;
            }

        }

}
/// MENU DO DISCO

if (CDX == 29 /*& CY == 7*/) { /// OPCAO DO MENU DISCO - COPIAR
        if (CDY == 1) {
        if (Parte == 20) {
        Parte = 15;
        DiskcopySelect = true;
        }

        }

}
if (CDX == 29 /*& CY == 7*/) { /// OPCAO DO MENU DISCO - RECUPERAR
        if (CDY == 3) {
        if (Parte == 20) {
        Parte = 16;
        //DiskcopySelect = true;
        }

        }

}
if (CDX == 29 /*& CY == 7*/) { /// OPCAO DO MENU DISCO - FORMATAR
        if (CDY == 4) {
        if (Parte == 20) {
        Parte = 16;
        FormatSelect = true;
        }

        }

}
if (CDX == 29 /*& CY == 7*/) { /// OPCAO DO MENU DISCO - INFO
        if (CDY == 5) {
        if (Parte == 20) {
        Parte = 29;
        //InfoSelect = true;
        }

        }

}

/// MENU ARQUIVO

if ((CDX >= 11 ) && (CDX < 27)) { /// OPCAO DO MENU ARQUIVO - COPIAR
        if (CDY == 1) {
        if (Parte == 8) {
        Parte = 14;
        JanelaCopiar = true;
        }

        }

}
if ((CDX >= 28 /*& CY == 7*/) && (CDX < 37)) { /// OPCAO OK DA SELECAO DE COPIA
        if (CDY == 0) {
        if (Parte == 16) {
        Parte = 14;
        JanelaCopiar = true;
        DiskcopySelect = false;
        }

        }

}
if ((CDX >= 11 ) && (CDX < 27)) { /// OPCAO DO MENU ARQUIVO - MOVER
        if (CDY == 2) {
        if (Parte == 8) {
        Parte = 7;
        }

        }

}
if ((CDX >= 11 ) && (CDX < 27)) { /// OPCAO DO MENU ARQUIVO - DELETAR
        if (CDY == 3) {
        if (Parte == 8) {
        Parte = 7;
        }

        }

}
if ((CDX >= 11 ) && (CDX < 27)) { /// OPCAO DO MENU ARQUIVO - INFO
        if (CDY == 5) {
        if (Parte == 8) {
        InfoSelect = true;
        Parte = 29;
        }

        }

}
if ((CDX >= 10 /*& CY == 7*/) && (CDX < 23)) { /// CANCELA A JANELA DE COPIA
        if (CDY == 0) {
        if (JanelaCopiar == true) {
        JanelaCopiar = false;
        DiskcopySelect = false;
        Parte = 1;
        }

        }

}
if ((CDX >= 48 /*& CY == 7*/) && (CDX < 55)) { /// CONFIRMA A COPIA (JANELA DE COPIA)
        if (CDY == 13) {
        if (JanelaCopiar == true) {
        system (("copy " + ArquivoCopiar + DestinoCopia).c_str());
        Parte = 1;
        }

        }

}
if ((CDX >= 46 /*& CY == 7*/) && (CDX < 57)) { /// HABILITA A SELECAO DE ARQUIVO PARA COPIAR
        if (CDY == 9) {
        if (JanelaCopiar == true) {
        SelecDestino = false;
        //SelecCopiando = true;
        DiskcopySelect = true;
        Parte = 16;
        }

        }

}
if ((CDX >= 46 /*& CY == 7*/) && (CDX < 57)) { /// HABILITA A SELECAO DO DESTINO DO ARQUIVO A SER COPIADO
        if (CDY == 11) {
        if (JanelaCopiar == true) {
        //SelecCopiando = false;
        SelecDestino = true;
        DiskcopySelect = true;
        Parte = 16;
        }

        }

}

/// FUNCOES DA CALCULADORA

if (CDX == 36 /*& CY == 7*/) { /// 1
        if (CDY == 9) {
  if (Aplicacao == "Calc") {
    if (OperandoOperad) {
    Operando += '1';
    CDX = 0;
    CDY = 0;
    } else  {
    Operador += '1';
    CDX = 0;
    CDY = 0;
    }

  }
 }

}

if (CDX == 41 /*& CY == 7*/) { /// 2
        if (CDY == 9) {
  if (Aplicacao == "Calc") {
    if (OperandoOperad) {
    Operando += '2';
    CDX = 0;
    CDY = 0;
    } else  {
    Operador += '2';
    CDX = 0;
    CDY = 0;
    }

  }
 }

}

if (CDX == 47 /*& CY == 7*/) { /// 3
        if (CDY == 9) {
  if (Aplicacao == "Calc") {
    if (OperandoOperad) {
    Operando += '3';
    CDX = 0;
    CDY = 0;
    } else  {
    Operador += '3';
    CDX = 0;
    CDY = 0;
    }

  }
 }

}

if (CDX == 36 /*& CY == 7*/) { /// 4
        if (CDY == 12) {
  if (Aplicacao == "Calc") {
    if (OperandoOperad) {
    Operando += '4';
    CDX = 0;
    CDY = 0;

    } else  {
    Operador += '4';
    CDX = 0;
    CDY = 0;
    }

  }
 }

}

if (CDX == 41 /*& CY == 7*/) { /// 5
        if (CDY == 12) {
  if (Aplicacao == "Calc") {
    if (OperandoOperad) {
    Operando += '5';
    CDX = 0;
    CDY = 0;
    } else  {
    Operador += '5';
    CDX = 0;
    CDY = 0;
    }

  }
 }

}

if (CDX == 47 /*& CY == 7*/) { /// 6
        if (CDY == 12) {
  if (Aplicacao == "Calc") {
    if (OperandoOperad) {
    Operando += '6';
    CDX = 0;
    CDY = 0;
    } else  {
    Operador += '6';
    CDX = 0;
    CDY = 0;
    }

  }
 }

}

if (CDX == 36 /*& CY == 7*/) { /// 7
        if (CDY == 15) {
  if (Aplicacao == "Calc") {
    if (OperandoOperad) {
    Operando += '7';
    CDX = 0;
    CDY = 0;
    } else {
    Operador += '7';
    CDX = 0;
    CDY = 0;
    }

  }
 }

}

if (CDX == 41 /*& CY == 7*/) { /// 8
        if (CDY == 15) {
  if (Aplicacao == "Calc") {
    if (OperandoOperad) {
    Operando += '8';
    CDX = 0;
    CDY = 0;
    } else {
    Operador += '8';
    CDX = 0;
    CDY = 0;
    }

  }
 }

}

if (CDX == 47 /*& CY == 7*/) { /// 9
        if (CDY == 15) {
  if (Aplicacao == "Calc") {
    if (OperandoOperad) {
    Operando += '9';
    CDX = 0;
    CDY = 0;
    } else {
    Operador += '9';
    CDX = 0;
    CDY = 0;
    }

  }
 }

}

if (CDX == 41 /*& CY == 7*/) { /// 0
        if (CDY == 18) {
  if (Aplicacao == "Calc") {
    if (OperandoOperad) {
    Operando += '0';
    CDX = 0;
    CDY = 0;
    } else {
    Operador += '0';
    CDX = 0;
    CDY = 0;
    }

  }
 }

}

if (CDX == 53 /*& CY == 7*/) { /// +
        if (CDY == 9) {
  if (Aplicacao == "Calc") {
       Operacao = "+";
       OperandoOperad = false;
           CDX = 0;
    CDY = 0;
  }
 }

}

if (CDX == 53 /*& CY == 7*/) { /// -
        if (CDY == 12) {
  if (Aplicacao == "Calc") {
       Operacao = "-";
       OperandoOperad = false;
           CDX = 0;
    CDY = 0;
  }
 }

}

if (CDX == 53 /*& CY == 7*/) { /// X
        if (CDY == 15) {
  if (Aplicacao == "Calc") {
       Operacao = "*";
       OperandoOperad = false;
           CDX = 0;
    CDY = 0;
  }
 }

}

if (CDX == 53 /*& CY == 7*/) { /// /
        if (CDY == 18) {
  if (Aplicacao == "Calc") {
       Operacao = "/";
       OperandoOperad = false;
           CDX = 0;
    CDY = 0;
  }
 }

}

//gotoxy (3,4);
//cout << Operando << " " << Operador;

operand = atoi (Operando.c_str());
operatord = atoi (Operador.c_str());
if (Aplicacao == "Calc") {
    gotoxy (3,5);
cout << operand << " " << operatord;
     gotoxy (36,6);
     cout << Resultado;
}


if (CDX == 47 /*& CY == 7*/) { /// =
        if (CDY == 18) {
  if (Aplicacao == "Calc") {
    //Resultado = 0;

     if (Operacao == "+") {
     //Resultado = atoi (Operando.c_str()) + atoi (Operador.c_str());
     Resultado = operand + operatord;
     gotoxy (36,6);
     cout << Resultado;
     getch();
     OperandoOperad = 1;
     Operando = "";
     Operador = "";
         CDX = 0;
    CDY = 0;

     }
          if (Operacao == "-") {
     //Resultado = atoi (Operando.c_str()) - atoi (Operador.c_str());
     Resultado = operand - operatord;
     gotoxy (36,6);
     cout << Resultado;
     getch();
     OperandoOperad = 1;
     Operando = "";
     Operador = "";
         CDX = 0;
    CDY = 0;

     }
          if (Operacao == "*") {
    // Resultado = atoi (Operando.c_str()) * atoi (Operador.c_str());
    Resultado = operand * operatord;
     gotoxy (36,6);
     cout << Resultado;
     getch();
     OperandoOperad = 1;
     Operando = "";
     Operador = "";
    CDX = 0;
    CDY = 0;

     }
          if (Operacao == "/") {
     //Resultado = atoi (Operando.c_str()) / atoi (Operador.c_str());
     if (operatord > 0) {
        Resultado = operand / operatord;
     }
     gotoxy (36,6);
     cout << Resultado;
     getch();
     OperandoOperad = 1;
     Operando = "";
     Operador = "";
    CDX = 0;
    CDY = 0;

     }
  }
 }

}

/// OPCAOES DO ITADRAW

if (CDX == 16 /*& CY == 7*/) { /// NENHUMA COR SELECIONADA NULO VAZIO BRANCO
        if (CDY == 25) {
  if (Aplicacao == "Itadraw") {
     Corselec = 800;
  }
 }

}

if (CDX == 17 /*& CY == 7*/) { /// COR 1
        if (CDY == 25) {
  if (Aplicacao == "Itadraw") {
     Corselec = 1;
  }
 }

}

if (CDX == 18 /*& CY == 7*/) { /// COR 1
        if (CDY == 25) {
  if (Aplicacao == "Itadraw") {
     Corselec = 2;
  }
 }

}

if (CDX == 19 /*& CY == 7*/) { /// COR 1
        if (CDY == 25) {
  if (Aplicacao == "Itadraw") {
     Corselec = 3;
  }
 }

}

if (CDX == 20 /*& CY == 7*/) { /// COR 1
        if (CDY == 25) {
  if (Aplicacao == "Itadraw") {
     Corselec = 4;
  }
 }

}

if (CDX == 21 /*& CY == 7*/) { /// COR 1
        if (CDY == 25) {
  if (Aplicacao == "Itadraw") {
     Corselec = 5;
  }
 }

}

if (CDX == 22 /*& CY == 7*/) { /// COR 1
        if (CDY == 25) {
  if (Aplicacao == "Itadraw") {
     Corselec = 6;
  }
 }

}

if (CDX == 23 /*& CY == 7*/) { /// COR 1
        if (CDY == 25) {
  if (Aplicacao == "Itadraw") {
     Corselec = 7;
  }
 }

}

if (CDX == 24 /*& CY == 7*/) { /// COR 1
        if (CDY == 25) {
  if (Aplicacao == "Itadraw") {
     Corselec = 8;
  }
 }

}

if (CDX == 25 /*& CY == 7*/) { /// COR 1
        if (CDY == 25) {
  if (Aplicacao == "Itadraw") {
     Corselec = 9;
  }
 }

}

if (CDX == 26 /*& CY == 7*/) { /// COR 1
        if (CDY == 25) {
  if (Aplicacao == "Itadraw") {
     Corselec = 10;
  }
 }

}

if (CDX == 27 /*& CY == 7*/) { /// COR 1
        if (CDY == 25) {
  if (Aplicacao == "Itadraw") {
     Corselec = 11;
  }
 }

}

if (CDX == 28 /*& CY == 7*/) { /// COR 1
        if (CDY == 25) {
  if (Aplicacao == "Itadraw") {
     Corselec = 12;
  }
 }

}

if (CDX == 29 /*& CY == 7*/) { /// COR 1
        if (CDY == 25) {
  if (Aplicacao == "Itadraw") {
     Corselec = 13;
  }
 }

}

if (CDX == 30 /*& CY == 7*/) { /// COR 1
        if (CDY == 25) {
  if (Aplicacao == "Itadraw") {
     Corselec = 14;
  }
 }

}

if (CDX == 31 /*& CY == 7*/) { /// COR 1
        if (CDY == 25) {
  if (Aplicacao == "Itadraw") {
     Corselec = 15;
  }
 }

}



/// OUTRAS FUNCOES DO SISTEMA

if (CDX == 1 /*& CY == 7*/) { /// OU MOSTRA A INFO DO SISTEMA
        if (CDY == 3) {
  Parte = 7;
        }

}

if (CDX == 31 /*& CY == 7*/) { /// OU MOSTRA A INFO DO SISTEMA
        if (CDY == 0) {
  if (Aplicacao == "Calc") {
  PiscaTela ();
  Parte = 1;
  OperandoOperad = 1;
  Aplicacao = "";
  }
        }

}

if ((CDX >= 28 /*& CY == 7*/) && (CDX < 30)) { // SO ABRE O ITATEXTO SE TIVER NO DISKETE A
    if (CDY == 14) {
        if (Parte == 9) {
            Parte = 12;
            Efeito_tela (); ///ITATEXTO
            Itatexto ();
            Parte = 1;
            CDX = 0;
            CDY = 0;
            PiscaTela ();
            system (("color " + CorFundo + CorFonte).c_str ());
        }


    }
}

if ((CDX >= 28) && (CDX < 30)) {
        if (CDY == 18) {
  Parte = 13;
 /* Efeito_tela ();
  Itadraw ();
  Parte = 1;
  CDX = 0;
  CDY = 0;
  PiscaTela ();*/
  Aplicacao = "Itadraw";
        }

//Sleep (300);
/// ITADRAW
    //Parte = 1 ;
}
if ((CDX >= 44) && (CDX < 46)) { /// CALCULADORA
        if (CDY == 18) {
  Parte = 18;
  //PrintaCalc ();
 // PiscaTela ();
  Aplicacao = "Calc";
  OperandoOperad = 1;
        }

//Sleep (300);

    //Parte = 1 ;
}
if (CDX == 63 /*& CY == 7*/) { /// ASSEMBLER
        if (CDY == 10) {
        if (Parte == 9) {
        if ((Aplicacao != "Calc") && (Aplicacao != "Itadraw")) {
        Parte = 18;
  Efeito_tela ();
  system ("color");
  Sleep (3000);
  Parte = 1;
  CDX = 0;
  CDY = 0;
  PiscaTela ();
  //Aplicacao = "ASMX86";

         }
        }
        }

}
/// APLICACAOES DE DISKETES
if ((CDX >= 37 /*& CY == 7*/) && (CDX < 39)) {
        if (CDY == 18) {
            if (Parte == 5) {
                if (DiskBLabel == "DOCUMENTS.APG") {
                    Parte = 12;
                    Sleep (600);
                    Efeito_tela (); ///SNAKE
                    Snake ();
                    Parte = 1;
                    CDX = 0;
                    CDY = 0;
                    PiscaTela ();
                }
            }


        }

}


if (Parte == 5) {
    if (ModoVisualisar == "Text") {
        if ((CDX > 26)&&(CDX < 40)) {
            if (DiskBLabel == "DOCUMENTS.APG") {
                if ((CDY > 10) && (CDY < 20)) {
                    if (DiskBContent [CDY-10] == "DOSNAKE.BAT") {
                        gotoxy (26,CDY);
                        for (int i = 0; i < 30; i++) cout << q;
                        Sleep (100);
                        Parte = 12;
                        Sleep (600);
                        Efeito_tela (); ///SNAKE
                        Snake ();
                        Parte = 1;
                        CDX = 0;
                        CDY = 0;
                        PiscaTela ();
                    }
                }
            }
        }
    }

}




///
if (GetAsyncKeyState (VK_END) != 0) {
if ((Aplicacao == "Itadraw") || (Aplicacao == "Calc") || (Parte == 20)) {
Efeito_tela() ;
Parte = 1;
CDX = 0;
CDY = 0;
Resultado = 0;
Aplicacao = "";
}
}
if (GetAsyncKeyState (VK_F1) != 0) {
if (Aplicacao == "Itadraw") {
SalvarDesenho ();
gotoxy (4,25);
cout << "Salvo com sucesso";
Sleep (1500);

}
}
if (GetAsyncKeyState (VK_F2) != 0) {
if (Aplicacao == "Itadraw") {
ConfirmSaveDraw ();
Tecla = getch ();
if  ((Tecla == 'S') || (Tecla == 's')) {
SalvarDesenho ();
gotoxy (4,25);
cout << "Salvo com sucesso";
Sleep (1500);
} else if  ((Tecla == 'N') || (Tecla == 'n')) {
SelecArquivoLoad ();
LoadDesenho ();
}

}
}

if (GetAsyncKeyState (VK_HOME) != 0) {
if (Aplicacao == "Itadraw") {
ModoItadraw = "Pixel";

}
}
if (GetAsyncKeyState ('A') != 0) {
if (Aplicacao == "Itadraw") {
ModoItadraw = "Pincel";

}
}
if (GetAsyncKeyState ('S') != 0) {
if (Aplicacao == "Itadraw") {
ModoItadraw = "Linha"; /// FAIXA HORIZONTAL

}
}
 /// --- RESET DO SISTEM A(EMULADOR)--- ///
        if ((GetAsyncKeyState(VK_F11) != 0)&&(GetAsyncKeyState(VK_CONTROL) != 0)) {
            system ("color 08");
            system ("cls");
            Sleep (1500);
            CDX = 0;
            CDY = 0;
            Parte = 1;
            ShowConsoleCursor(false);

            gotoxy (0,0);
            system ("color 0a");
            for (int i = 0; i < 9000; i++) {
                cout << (char) i;
            }

            Beep (523,500);
            Sleep (1500);

           // reset ();
           system ("color f0");
           system ("cls");

        }

/// ---------------- ///
if (Aplicacao == "Itadraw") { /// PINCEL
/*if (ModoItadraw == "Pincel") { */
if (GetAsyncKeyState (VK_SPACE) != 0) {

          if (Corselec == 1) {
          Teladesenho [x] [y] = 1;
          } else if (Corselec == 2) {
          Teladesenho [x] [y] = 2;

          } else if (Corselec == 3) {
          Teladesenho [x] [y] = 3;

          } else if (Corselec == 4) {
          Teladesenho [x] [y] = 4;

          } else if (Corselec == 5) {
          Teladesenho [x] [y] = 5;

          } else if (Corselec == 6) {
          Teladesenho [x] [y] = 6;

          } else if (Corselec == 7) {
          Teladesenho [x] [y] = 7;

          } else if (Corselec == 8) {
          Teladesenho [x] [y] = 8;

          } else if (Corselec == 9) {
          Teladesenho [x] [y] = 9;

          } else if (Corselec == 10) {
          Teladesenho [x] [y] = 10;

          } else if (Corselec == 11) {
          Teladesenho [x] [y] = 11;

          } else if (Corselec == 12) {
          Teladesenho [x] [y] = 12;

          } else if (Corselec == 13) {
          Teladesenho [x] [y] = 13;

          } else if (Corselec == 14) {
          Teladesenho [x] [y] = 14;

          } else if (Corselec == 15) {
          Teladesenho [x] [y] = 15;

          } else if (Corselec == 800) {
          Teladesenho [x] [y] = 0;

          } else {
          Teladesenho [x] [y] = 1;
          }
}
/*}*/
} /// FIM DA PARTE DE PINCEL

if (Aplicacao == "Itadraw") { /// PINCEL
/*if (ModoItadraw == "Pincel") { */
if (GetAsyncKeyState ('S') != 0) {
        for (int i = 0; i < 95; i++) {
                 if (Corselec == 1) {
          Teladesenho [i] [CDY] = 1;
          } else if (Corselec == 2) {
          Teladesenho [i] [CDY] = 2;

          } else if (Corselec == 3) {
          Teladesenho [i] [CDY] = 3;

          } else if (Corselec == 4) {
          Teladesenho [i] [CDY] = 4;

          } else if (Corselec == 5) {
          Teladesenho [i] [CDY] = 5;

          } else if (Corselec == 6) {
          Teladesenho [i] [CDY] = 6;

          } else if (Corselec == 7) {
          Teladesenho [i] [CDY] = 7;

          } else if (Corselec == 8) {
          Teladesenho [i] [CDY] = 8;

          } else if (Corselec == 9) {
          Teladesenho [i] [CDY] = 9;

          } else if (Corselec == 10) {
          Teladesenho [i] [CDY] = 10;

          } else if (Corselec == 11) {
          Teladesenho [i] [CDY] = 11;

          } else if (Corselec == 12) {
          Teladesenho [i] [CDY] = 12;

          } else if (Corselec == 13) {
          Teladesenho [i] [CDY] = 13;

          } else if (Corselec == 14) {
          Teladesenho [i] [CDY] = 14;

          } else if (Corselec == 15) {
          Teladesenho [i] [CDY] = 15;

          } else if (Corselec == 800) {
          Teladesenho [i] [CDY] = 0;

          } else {
          Teladesenho [i] [CDY] = 1;
          }

        }


}
/*}*/
} /// FIM DA PARTE DE LINHAS

if (Aplicacao == "Itadraw") { /// PINCEL
/*if (ModoItadraw == "Pincel") { */
if (GetAsyncKeyState (VK_F5) != 0) {
        cout << " CDX: ";
        cin >> CDX;
        cout << " CDY: ";
        cin >> CDY;
        cout << " L> ";
        cin >> Largura;
        cout << " A> ";
        cin >> Altura;
        for (int i = CDX; i < CDX+Largura; i++) { /// X
            for (int d = CDY; d < CDY+Altura; d++) {
                                    if (Corselec == 1) {
          Teladesenho [i] [d] = 1;
          } else if (Corselec == 2) {
          Teladesenho [i] [d] = 2;

          } else if (Corselec == 3) {
          Teladesenho [i] [d] = 3;

          } else if (Corselec == 4) {
          Teladesenho [i] [d] = 4;

          } else if (Corselec == 5) {
          Teladesenho [i] [d] = 5;

          } else if (Corselec == 6) {
          Teladesenho [i] [d] = 6;

          } else if (Corselec == 7) {
          Teladesenho [i] [d] = 7;

          } else if (Corselec == 8) {
          Teladesenho [i] [d] = 8;

          } else if (Corselec == 9) {
          Teladesenho [i] [d] = 9;

          } else if (Corselec == 10) {
          Teladesenho [i] [d] = 10;

          } else if (Corselec == 11) {
          Teladesenho [i] [d] = 11;

          } else if (Corselec == 12) {
          Teladesenho [i] [d] = 12;

          } else if (Corselec == 13) {
          Teladesenho [i] [d] = 13;

          } else if (Corselec == 14) {
          Teladesenho [i] [d] = 14;

          } else if (Corselec == 15) {
          Teladesenho [i] [d] = 15;

          } else if (Corselec == 800) {
          Teladesenho [i] [d] = 0;

          } else {
          Teladesenho [i] [d] = 1;
          }
                    }/// Y
        }


}
/*}*/
} /// FIM DA PARTE DE QUADRADOS RETANGULOS RET64

if ((Aplicacao != "Itadraw")  && (Aplicacao != "Calc")) { /// IMPRIME O TEMPO (HORA) NO CANTO SUPERIOR DIREITO DA TELA DESKTOP
if (mostrarTime) {
    PrintaTime ();
}
}

/*if ((Boot == "Itados.sys") || (Boot == "ITADOS.SYS")) {
    Cmd ();
} /// BOOT */

    //; }
}
     m->polling=false;
}

////////////////////////////////////////////////////////////////////////////////

void left_down(int x, int y, void*p)
{
          if (Aplicacao != "Itadraw") {
     //printf("left button down at (%d,%d)\n",x,y);
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
     //printf("left button up at (%d,%d)\n",x,y);
     CDX = x;
     CDY = y;
}

void left_click(int x, int y, void*p)
{
     //printf("left click at (%d,%d)\n",x,y);
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
        system ("title ITAC 1150 PLUS EMULATOR");

        RESET:
        LoadSettings ();
        if ( ! ((DiskAFile == "DEFAULT") || (DiskAFile == "default"))) {
            LoadDisk ('A');
            ConvertDiskIcons ('A');
        } else {
        DiskALabel = "APPS";
        }
        if ( ! ((DiskBFile == "NONE") || (DiskBFile == "none"))) {
            LoadDisk ('B');
            ConvertDiskIcons ('B');
        }
        if ((Boot == "Itados.sys") || (Boot == "ITADOS.SYS")) {
        Cmd ();
        } /// BOOT
    ShowConsoleCursor(false);
    Parte = 1;
    LoadSys (Boot);
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
cout<<" sem cls                                                                                           "<<endl;
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


    cout<<"Aperte alguma tecla para sair...";

    mouse.start_polling();

    system("color f0");

    int ClickDos = 0;

    while(GetAsyncKeyState(VK_ESCAPE) == 0); ///!_kbhit()
    {
        if ((GetAsyncKeyState(VK_F11) != 0)&&(GetAsyncKeyState(VK_CONTROL) != 0)) {
            system ("color");
            system ("cls");
            //reset = true;
            goto RESET;

        }
         mouse.stop_polling();
	if (atualizarTela) {
         system("cls");
	}
         //SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){0,3});
         GetCursorPos(&pt_Coords);
         int px = pt_Coords.x;
         int py = pt_Coords.y;
             mouse.set_lbccb(left_click);
         cout<<"x : "<<px<<"    \ny : "<<py<<"    \n";

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
        
         cout << M;
         gotoxy (px/8,(py/12)+1);
        
         cout << MB;
         gotoxy(0,0);
         _sleep(100);
         if (atualizarTela)
         system("cls");
    }
    return 0;

}



