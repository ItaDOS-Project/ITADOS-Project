/// URSOBASIC POR ARUNI AMSTEL, 2017

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <string>
#include <vector>
#include <fstream>



#include<stdio.h>
#include<conio.h>
#include<time.h>


using namespace std;

string NOME;
string RUN;
int Disco = 0;

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

int Modo = 1;

int NovoValor = 0;
int Variaveis [40];
string VariaveisNome [40];
string CharsNome [40];
int Vi = 0;
int Vc = 0;
int Var = 0;
string Varname;
string DiskFunction;
string ForParam;
string ForCondit;
string ForDo;

int DiskBlock = 0;
int DiskPort = 0;
int ForTimes = 0;

int Line;

char CHR;

char Caracteres [50];

/// ANTIGOS

float var1 =1;
float var2 =2;
float var3 =3;
float var4 =14;
char Tecla =0;

string Padron;

int pin = 0;
int pin2;
int X =0 ;
int Y =0;
//int pinbackup = 000000000000000000;
int pinbackup = 1234;
int Alarme;
int Bloqueiodesim = 0;
string Comando;
string Subcomando;
string Pasta;
string Contatos[100][2] = {{"Ursotel", "*9889"}};
int NumContatos = 1;
string Contatocriar;
int Contnum;
int Brilho;
int LightDuration;
int ModoVibracao;
int EconomiadeBateria;
int Padron1=0;
string Program;
int App = 0;
int Opt;
char chDigitado = 0;
string pinDigitado = "";
string pinbackup3 = "1234";
string pin4 = "3287";

///

void gotoxy( int column, int line )
  {
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    coord
    );
  }

  void mgotoxy(int x,int y)
{	COORD p={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),p);
}

void RunForDo (string Cmdfor, string fparam) {
         if (Cmdfor == "CLEAR") { //PNM
        system ("cls");
            }
            if (Cmdfor == "DISK:" ) {
        cin >> DiskFunction;
        cin >> DiskPort;
        cin >> DiskBlock;
        if (DiskFunction == "COPY") {
        cout << "DONE"<< endl;
        }
        if (DiskFunction == "FORMAT") {
        cout << "DONE"<< endl;
        }
        if (DiskFunction == "OPEN") {
        cout << "DONE"<< endl;
        }
        if (DiskFunction == "ENUM_EDIR") {
        cout << "DONE"<< endl;
        }
        }
         if (Cmdfor == "PAUSE") { //rdb
     system ("pause>nul");
}
if (Cmdfor == "CONSOLE") { //rdb
     system("color?");
}
if (Cmdfor == "COPY") { //ret
     system ("copy");
}
if (Cmdfor == "VAR") { /// CRIA UMA VARIAVEL //////////////////////////////////////////////////
        cin >> Varname;
     cin >> Var;

     Variaveis [Vi] = Var;
     VariaveisNome [Vi] = Varname;
     Vi++;
}
if (Cmdfor == "PRINTVAR") { /// IMPRIME O VALOR DE UMA VARIAVEL //////////////////////////////////////////////////
     cin >> Vi;
     cout << Variaveis [Vi] << endl;
}
// NEW VAR CREATEVAR INT "*MEMO:VAR
if (Cmdfor == "CHANGEVAR") { /// MUDA O VALOR DE UMA VARIAVEL //////////////////////////////////////////////////
     cin >> Vi;
     cin >> NovoValor;
     Variaveis [Vi] = NovoValor;
}

if (Cmdfor == "CHAR*") { /// MUDA O VALOR DE UMA VARIAVEL //////////////////////////////////////////////////
        cin >> Varname;
     cin >> CHR;

     Caracteres [Vc] = CHR;
     CharsNome [Vc] = Varname;
     Vc++;
}

if (Cmdfor == "*MEMO,VAR") { /// MUDA O VALOR DE UMA VARIAVEL //////////////////////////////////////////////////
     cin >> Vi;
     cout << " , ";
     cin >> NovoValor;
     Variaveis [Vi] = NovoValor;
}

if (Cmdfor == "POINT") {
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

if (Cmdfor == "JUMP" ) { //TDMSC
        cin >> X;
        cin >> Y;
    gotoxy (X,Y);
  //  goto Comd;
}
if (Cmdfor == "LIST") { //NM
//cin >> NOME;
system (("type " + NOME).c_str());
cout << "*** END OF PROGRAM ***" << endl;
}
if (Cmdfor == "10") { //rdb
        Itatexto:
     system ("prompt");
     Padron = " ";
     Padron1 = 1;
     App = 1;

}
if (Comando == "PRINT" ) {
        cout << fparam << endl;
  //  goto Comd;
}


}


int main(){



Sleep (5000);
system ("cls");

system ("color 0a"); //ret
cout << "        ***** BEARPC 64 URSOBASIC V2 *****         " << endl;
cout << " 103685983550 BLOCKS FREE MAY THE FORCE BE WITH YOU" << endl;
Cmd:
    if (Padron1 == 0) {
     cout << "REAJA" << endl;
     cin >> Comando;
    } else {
    cout << Padron;
    getline (cin,Comando);
    }

//cin >> Comando;
if (Comando == "OPENDIR") {

    cin >> Pasta;
    system (("cd " + Pasta).c_str());

}
if (Comando == "CLEAR") { //PNM
     system ("cls");
}


if (Comando == "DIR") { //pnm1 //RET

}
if (Comando == "exit") { //pnm2
     system ("exit 1e");
     system ("color 1e");
     system ("cls");
     App = 0;
     //cout << "ITACHD_/";
     Padron1 = 0;
}
if (Comando == "EXIT") { //pnm2
     system ("color 1e");
     system ("cls");
}

if (Comando == "COPY") { //ret
  //  cin >> Pasta;
    // system (("copy" + Pasta).c_str());
}

if (Comando == "RET") { //rdb //RDB
     return 0;
}

if (Comando == "PAUSE") { //rdb
     cout << "PRESS ANY KEY TO PROCEED?" << endl;
	getch ();

}
if (Comando == "DATA") { //rdb
     goto Gerarq;
}
if (Comando == "CONSOLE") { //rdb
 cin >> Pasta;
     system (("color" + Pasta).c_str());
}


if (Comando == "LOAD_CALC") {
        int Operando = 0;
        int Operador = 0;
        int Operacao = 0;
     cout << " Itados Calculator v 3.5.8" << endl;
     cout << " 1 - Soma" << endl; //nmd
     cout << " 2 - Subtracao" << endl;
     cout << " 3 - Multiplicacao" << endl; //tdmdsc
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
    cout << Operando + Operador << endl; //rdb
    cout << "done" << endl;
    break;
case 2:
    Operacao = 2;
    cout << " Inisira o Operando (1 numero)" << endl;
    cin >> Operando;
    cout << " Inisira o Operador (2 numero)" << endl;
    cin >> Operador;
    cout << Operando - Operador << endl; //nmd
    cout << "done" << endl;
    break;
case 3:
    Operacao = 3;
    cout << " Inisira o Operando (1 numero)" << endl;
    cin >> Operando;
    cout << " Inisira o Operador (2 numero)" << endl;
    cin >> Operador;
    cout << Operando * Operador << endl; //pnm
    cout << "done" << endl;
    break;
case 4:
    Operacao = 4;
    cout << " Inisira o Operando (1 numero)" << endl;
    cin >> Operando;
    cout << " Inisira o Operador (2 numero)" << endl;
    cin >> Operador;
    cout << Operando / Operador << endl; //ret
    cout << "done" << endl;
}

}




if (Comando == "10") { //rdb
        Itatexto:
     system ("prompt");
     Padron = " ";
     Padron1 = 1;
     App = 1;

}

if (Comando == "MENU") { //rdb
    // goto menu;
    goto Bloq;
}
if (Comando == "RESET") { //rdb
    // goto menu;
    system ("color 0a");
    system ("cls");
    Padron1 = 0;
}
if (Comando == "CONFIG") { //rdb //*PNM
     cin >> Subcomando;
     if (Subcomando == "SETTIME") {
        system ("time");
}
 if (Subcomando == "SAVECONFIG") {
        cout << "CONFIGURATION SAVED" << endl;
}


}

if (Comando == "VAR") { /// CRIA UMA VARIAVEL //////////////////////////////////////////////////
        cin >> Varname;
     cin >> Var;

     Variaveis [Vi] = Var;
     VariaveisNome [Vi] = Varname;
     Vi++;
}

if (Comando == "PRINT$") { /// IMPRIME O VALOR DE UMA VARIAVEL //////////////////////////////////////////////////
     cin >> Vi;
     cout << Variaveis [Vi] << endl;
}
// NEW VAR CREATEVAR INT "*MEMO:VAR
if (Comando == "SET$") { /// MUDA O VALOR DE UMA VARIAVEL //////////////////////////////////////////////////
     cin >> Vi;
     cin >> NovoValor;
     Variaveis [Vi] = NovoValor;
}

if (Comando == "CHAR*") { /// MUDA O VALOR DE UMA VARIAVEL //////////////////////////////////////////////////
        cin >> Varname;
     cin >> CHR;

     Caracteres [Vc] = CHR;
     CharsNome [Vc] = Varname;
     Vc++;
}

if (Comando == "*MEMO,VAR") { /// MUDA O VALOR DE UMA VARIAVEL //////////////////////////////////////////////////
     cin >> Vi;
     cout << " , ";
     cin >> NovoValor;
     Variaveis [Vi] = NovoValor;
}

if (Comando == "POINT") {
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

if (Comando == "JUMP" ) { //TDMSC
        cin >> X;
        cin >> Y;
    gotoxy (X,Y);

}

if (Comando == "PRINT" ) {
        string Scrwrite;
        cin >> Scrwrite;
        cout << Scrwrite << endl;

}

/// /////////////////////////////////////////

if (Comando == "DISK:" ) {
        cin >> DiskFunction;
        cin >> DiskPort;
        cin >> DiskBlock;

	if (DiskPort < 0 && DiskPort > 5) {
	cout << "DISK PORT UNACESSIBLE ERROR?" << endl;
	}

	if (DiskBlock < 0 && DiskBlock > 64898) {
	cout << "DISK BLOC NOT FOUND?" << endl;
	}

        if (DiskFunction == "COPY") {
        cout << "DONE"<< endl;
        }
        if (DiskFunction == "FORMAT") {
        cout << "DONE"<< endl;
        }
        if (DiskFunction == "OPEN") {
        cout << "DONE"<< endl;
        }
        if (DiskFunction == "ENUM_EDIR") {
        cout << "DONE"<< endl;
        }



  //  goto Comd;
}

/// ///////////////////////////////////////////////////////////////////////////////// !

if (Comando == "FOR" ) {
        cin >> ForTimes;
        cin >> ForCondit;
        cin >> ForDo;
        cin >> ForParam;
        int VezesRealizadas = 0;


	if (ForTimes > 0) {
	while (VezesRealizadas != ForTimes) {
        RunForDo (ForDo,ForParam);
          VezesRealizadas++;
          }

	} else {
	cout << "SYNTAX ERROR?" << endl;
	}



}

if (Comando == "SAVE" ) {
        cout << endl << "INSERT FILENAME:";
        cin >> NOME;

  ofstream myfile;
  myfile.open (NOME.c_str ());
  myfile << Comando;
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



if (Comando == "LOAD") { //NM
cin >> NOME;
}
if (Comando == "LIST") { //NM
system (("type " + NOME).c_str());
cout << "*** END OF PROGRAM ***" << endl;
}

if (Comando == "RUN") { //NM
if (NOME == "SNAKE" ) {
        cout << "PLEASE WAIT..." << endl;
    Sleep (1000);
system("cls");
system("color 00");
Sleep (300);
system("color f0");
Sleep (100);
system("color 40");
     int x,d=2,cx[300]={1,2},cy[300]={7,7},t=1,mx,my;
    char tecla='a';
    //system("MODE con cols=27 lines=20");
    for(x=0;x<18;x++)
    {   mgotoxy(0,x);
        printf("%c",219);
    }
    for(x=0;x<26;x++)
    {   mgotoxy(x,0);
        printf("%c",219);
    }
    for(x=-0;x<18;x++)
    {   mgotoxy(26,x);
        printf("%c",219);
    }
    for(x=-0;x<27;x++)
    {   mgotoxy(x,18);
        printf("%c",219);
    }
    srand(time(NULL));
    mx=(rand()%25)+1;
    my=(rand()%17)+1;
    while(tecla!='q')
    {   while(tecla!='q'&&!(tecla=kbhit()))
        {   for(x=t;x>0;x--)
            {   cx[x]=cx[x-1];
                cy[x]=cy[x-1];
            }
            if(d==0)cx[0]--;
            if(d==1)cy[0]--;
            if(d==2)cx[0]++;
            if(d==3)cy[0]++;
            mgotoxy(cx[t],cy[t]);
            printf(" ");
            if(mx==cx[0]&&my==cy[0])
            {   t++;
                mx=(rand()%25)+1;
                my=(rand()%17)+1;
            }
            mgotoxy(cx[0],cy[0]);
            printf("%c",219);
            mgotoxy(mx,my);
            printf("%c",1);
            Sleep(500);
            for(x=1;x<t;x++)
            {   if(cx[0]==cx[x]&&cy[0]==cy[x])tecla='q';
            }
            if(cy[0]==0||cy[0]==18||cx[0]==0||cx[0]==26)tecla='q';
        }
        if(tecla!='q')tecla=getch();
        if(tecla=='a')d=0;
        if(tecla=='w')d=1;
        if(tecla=='d')d=2;
        if(tecla=='s')d=3;
        if(cy[0]==0||cy[0]==18||cx[0]==0||cx[0]==26)tecla='q';
    }
    getch();
    system ("color 0a");
    system ("cls");

}
if (NOME == "DISKCOPY") {
system ("cls");
Sleep (100);
 cout << "BEM VINDO AO DISCKCOPY V 1.0 PARA BEARPC!" << endl;
 cout << "PARA SELECIONAR O DISCO TECLE A, PARA SELECIONAR O DISCO B TECLE B" << endl;
 cout << "PARA DIRECIONAR PARA DISCO A DIGITE A E PARA DIRECIONAR PARA DISCO B DIGITE B" << endl;
 cout << "C - INICIA A COPIA, PRESSIONE A TECLA S PARA SAIR OU CANCELAR O PROCESSO" << endl;
 string Opcaodc;
 DCOPY:
 cin >> Opcaodc;
 if (Opcaodc == "A") {
cout << "DISCO A SELECIONADO" << endl;
goto DCOPY;
 } else if (Opcaodc == "B") { //PNM
cout << "DISCO B SELECIONADO" << endl;
goto DCOPY;
 } else if (Opcaodc == "DA") { //RET
cout << endl;
cout << "A ";
goto DCOPY;
 } else if (Opcaodc == "EB") {
cout << endl;
cout << "B ";
goto DCOPY;
 } else if (Opcaodc == "S") { //RDB
system ("pause");
cout << endl;
cout << "*** END OF PROGRAM ***" << endl;
goto Cmd;
 } else if (Opcaodc == "C") {
cout << "POR FAVOR ESPERE..." << endl;
Sleep (1000);
cout << "REAJA" << endl;
system ("pause");
system ("diskcopy A: B:");
goto DCOPY;
 } else if (Opcaodc == "F") {
cout << "DESEJA MESMO FORMATAR DISCO ORIGINAL?" << endl;
getch ();
goto DCOPY;
 } else if (Opcaodc == "U") {
cout << "DESEJA MESMO DESFORMATAR O DISCO ORIGINAL?" << endl;
getch ();
goto DCOPY;
 }

}

if (NOME == "DOS34") {
    Sleep (1000);
system ("cls");
 cout << "BEM VINDO AO DOS 34 V 1.3 PARA BEARPC!" << endl;
 cout << "PARA SELECIONAR O DISCO A DIGITE DA, PARA SELECIONAR O DISCO B DIGITE DB" << endl;
 cout << "PARA DIRECIONAR PARA DISCO A DIGITE A E PARA DIRECIONAR PARA DISCO B DIGITE B" << endl;
 cout << "DIGITE A TECLA S PARA SAIR OU CANCELAR ALGUM PROCESSO" << endl;
  cout << "OUTROS COMANDOS: DIR CLS PAUSE COPY FORMAT INDEX CD BASIC" << endl;
 string Opcaodc;
 IDCMD:
 cin >> Opcaodc;
 if (Opcaodc == "A") {
cout << "DISCO A SELECIONADO" << endl;
Disco = 1;
goto IDCMD;
 } else if (Opcaodc == "B") { //PNM
cout << "DISCO B SELECIONADO" << endl;
Disco = 2;
goto IDCMD;
 } else if (Opcaodc == "DA") { //RET
cout << endl;
cout << "A ";
goto IDCMD;
 } else if (Opcaodc == "DB") {
cout << endl;
cout << "B ";
goto IDCMD;
 } else if (Opcaodc == "S") { //RDB
system ("pause");
cout << endl;
cout << "*** END OF PROGRAM ***" << endl;
goto Cmd;
 } else if (Opcaodc == "COPY") {
cout << "POR FAVOR ESPERE..." << endl;
Sleep (1000);
cout << "REAJA" << endl;
system ("pause");
system ("diskcopy a b");
goto IDCMD;
 } else if (Opcaodc == "FORMAT") {
cout << "DESEJA MESMO FORMATAR DISCO ORIGINAL?" << endl;
getch ();
goto IDCMD;
 } else if (Opcaodc == "CLS") { //PNM
system ("cls");
goto IDCMD;
 } else if (Opcaodc == "DIR") { //RET
if (Disco = 1) {
    cout << "CMD34.DIR         11324 BLOCKS / NAT" << endl; //PNM
    cout << "CMDDOS.BAT    00345 BLOCKS" << endl; //RET
    cout << "COPY.CMD         11568 BLOCKS" << endl; //RDB
    cout << "FORMAT.CMD     12557 BLOCKS" << endl; //TDMSC
    cout << "CONFIG.SYS        01568 BLOCKS" << endl;
    cout << "INFO.TXT              08567 BLOCKS" << endl;
    cout << "BOOT.BAT            56780 BLOCKS" << endl;
} else {
cout << "SEM DISCO B OU MEMORIA RAM SELEC." << endl;
}
goto IDCMD;
 } else if (Opcaodc == "CD") {
system ("cd C:");
getch ();
goto IDCMD;
 } else if (Opcaodc == "INDEX") {
cout << "DESEJA MESMO DESFORMATAR O DISCO ORIGINAL?" << endl;
getch ();
goto IDCMD;
 } else if (Opcaodc == "PAUSE") { //RDB
cout << endl << "PRESSIONE ALGUMA TECLA PARA CONTINUAR..." << endl;
getch ();
goto IDCMD;
 }

}






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

else if (Line == 42) {
Comando == L2;
}else if (Line == 43) {
Comando == L2;
}else if (Line == 44) {
Comando == L2;
}else if (Line == 45) {
Comando == L2;
}else if (Line == 46) {
Comando == L2;
}else if (Line == 47) {
Comando == L2;
}else if (Line == 48) {
Comando == L2;
}else if (Line == 49) {
Comando == L2;
}else if (Line == 50) {
Comando == L2;
}else if (Line == 51) {
Comando == L2;
}else if (Line == 52) {
Comando == L2;
}else if (Line == 53) {
Comando == L2;
}else if (Line == 54) {
Comando == L2;
}else if (Line == 55) {
Comando == L2;
}else if (Line == 56) { //
Comando == L2;
}else if (Line == 57) {
Comando == L2;
}else if (Line == 58) {
Comando == L2;
}else if (Line == 59) {
Comando == L2;
}else if (Line == 60) {
Comando == L2;
}else if (Line == 61) { //
Comando == L2;
}else if (Line == 62) {
Comando == L2;
}else if (Line == 63) {
Comando == L2;
}else if (Line == 64) {
Comando == L2;
}else if (Line == 65) {
Comando == L2;
}else if (Line == 66) {
Comando == L2;
}else if (Line == 67) {
Comando == L2;
}else if (Line == 68) {
Comando == L2;
}else if (Line == 69) {
Comando == L2;
}else if (Line == 70) {
Comando == L2;
}else if (Line == 71) {
Comando == L2;
}else if (Line == 72) {
Comando == L2;
}else if (Line == 73) {
Comando == L2;
}else if (Line == 74) {
Comando == L2;
}else if (Line == 75) {
Comando == L2;
}else if (Line == 76) {
Comando == L2;
}else if (Line == 77) {
Comando == L2;
}else if (Line == 78) {
Comando == L2;
}else if (Line == 79) {
Comando == L2;
}else if (Line == 80) {
Comando == L2;
} /*else if (Line == 2) {
Comando == L2;
}else if (Line == 2) {
Comando == L2;
}else if (Line == 2) {
Comando == L2;
}else if (Line == 2) {
Comando == L2;
}else if (Line == 2) {
Comando == L2;
} */
if (App == 1) {
Line++;
}

goto Cmd;
//By ITAC copyleft (c) 2017
 //long int pin;
menu:

cout << "Menu";
cout << endl;
cout << "01-Contatos";
cout << endl;
cout << "02-Configuracoes";
cout << endl;
cout << "03-Acionar Camera";
cout << endl;
cout << "04-Enviar SMS";
cout << endl;
cout << "05-Utilitarios";
cout << endl;
cout << "06-Sair";
cin >> Tecla;
switch (Tecla) {
 case '1' :
     cout << "01-Procurar" << endl;
     cout << "02-Adicionar" << endl;
     cout << "03-copiar para chip" << endl;
     cout << "04-apagar tudo" << endl;
     cout << "05-voltar" << endl;
     cin.ignore();
     //cin >> Tecla;
   //  getline(cin, Tecla);
     if (Tecla == '1') {
        for (int c;c<NumContatos;c++) {
            cout << "Nome: " << Contatos[c][1] << " Numero: " << Contatos[c][2] << endl;
        }
     }
 cout << "Insira o Numero";
 cin >> pin;
 goto menu;
 break;
 case '2' :
 cout << "Criar...";
 cout << endl;
 cout << "Modo Vibratorio";
 cout << endl;
 cout << "Hora e Data";
 cout << endl;
 cout << "Chamadas";
 cout << endl;
 cout << "Chip";
 cout << endl;
 cout << "Visor";
 cout << endl;
 cout << "Redefinir tudo...";
 cout << endl;
 cout << "Bateria";
 cout << endl;
 cout << "Bluetooth";
 cout << endl;
 cin >> Tecla ;
 //break;

  switch (Tecla) {
   case '1' :
       system ("cls");
       pinDigitado = "";
     cout << "Insira PIN" << endl;
    /* cout << 219 << 219 << 219 << 219 << 219 << 219 << 219 << 219 << 219 << 219 << 219 << endl;
     cout << 219 << "                                                         " << 219 << endl;
     cout << 219 << 219 << 219 << 219 << 219 << 219 << 219 << 219 << 219 << 219 << 219 << endl; */
     cout << (char) 219 << (char) 219 << (char) 219 << (char) 219 << (char) 219 << (char) 219 << (char) 219 << (char) 219 << (char) 219 << (char) 219 << (char) 219 << endl;
     cout << (char) 219 << "         " << (char) 219 << endl;
     cout << (char) 219 << (char) 219 << (char) 219 << (char) 219 << (char) 219 << (char) 219 << (char) 219 << (char) 219 << (char) 219 << (char) 219 << (char) 219 << endl;
 //cin >> pin ;
 gotoxy (1,2);
 chDigitado = getch ();
 while (chDigitado != 13) {
 pinDigitado += chDigitado;
 cout << "*" ;
 chDigitado = getch ();
 }
 gotoxy (0,4);
 //pin = funcao(pinDigitado);
 if (pinDigitado == "3287") {
     cout << "Verificando...";
 cout << endl;
 cout << "Carregar (01) / Salvar (02) / Trocar PIN (03) / Sair (04)";
 cin >> Tecla;
 switch (Tecla) {
   case '1' :

    /*cout << "ativar pin?" << endl;
     cin >> Tecla;
     Bloqueiodesim = 1;
     switch (Tecla) {
 case 's' :
goto menu;
    case 'n' :
    cout << "Insira PIN" << endl;
    cin >> pin2;
    goto menu;
    goto menu;
     } // ativar desativar
      } //switch pin */

    cout << "ativar pin?" << endl;
     cin >> Tecla;
     if (Tecla == 's' ) {
            cout << "Insert PIN" << endl;
     cin >> pin;
    Bloqueiodesim = 1;
     }
      if (Tecla == 'n' ) {
    Bloqueiodesim = 0;
     }
    cout << "Insira PIN" << endl;
    cin >> pin2;
    goto menu;
    //Bloqueiodesim = 0;
    goto menu;

    case '3':
        cout << "Inisira PIN" << endl;
        cin >> pin4;
        goto menu;
     } // ativar desativar
 } else {
        gotoxy (0,4);
     cout << "PIN incorreto";
 cout << endl;
 goto Cmd;
 //break;
 }
 case '2':
 cout << "Modo Silencioso Ativado";
 goto menu;

 case '3' :
 cout << "Definir Hora";
 cout << endl;
 cout << "Definir Data";
 cout << endl;
 cout << "Salvar Alteracoes";
 cin >> Tecla;
  break;
 case '4' :
 cout << "Conexao Falhou.Sair?";
 cin >> Tecla ;
 goto menu;


case '5':
 cout << "*-Chip1";
 cout << endl;
 cout << "#-Chip2";
 cin >> Tecla;
 if (Tecla = '*') {
    cout << "Insert SIM" << endl;
    system ("pause");
    goto menu;
 }
 if (Tecla = '#') {
    cout << "Insert SIM" << endl;
    system ("pause");
    goto menu;
 }
 goto menu;
 break;

case '6':
 cout << "Bem vindo ao ITADos.Insira um comando";
 cin >> Tecla;
 break;
 }
case '3':
 cout << "Insira o Numero";
 cin >> pin ;
 long int pin2;
 cin >> pin2;
 cout << pin * pin2;

case '4':
 cout << "Nova...";
 cout << endl;
 cout << "SMS Enviados";
 cout << endl;
 cout << "SMS Recebidos";
 cout << endl;
 cin >> Tecla;
 cin >> pin ;

case '5':
 cout << endl;
 cout << "Alarmes";
 cout << endl;
 cout << "Gerenciador de Arquivos";
 cout << endl;
 cout << "Shell";
 cout << endl;
 cout << "Acessar WAP";
 cout << endl;
 cout << "Redefinir...";
 cout << endl;
 cout << "Gravador de som";
 cout << "Voltar";
 cin >> Tecla;
 if (Tecla == 1) {
    cout << "Vazio";
 system ("pause");
 goto menu;
 }
if (Tecla == '2') {
 cout << "Vazio.Criar?";
 cin >> Tecla ;
    if (Tecla = 's') {
    cout << "Insira a hora do alarme" << endl;
    cin >> Alarme;
    cout << "Salvo" << endl;
    system ("cls");
    goto menu;
 }


  if (Tecla = 'n') {
    goto menu;
 }
} //Alarme

if (Tecla == 3) {
 }
 cout << "Ursaventuras Mini";
 cin >> pin2 ;
 cout << "Carregando...";
 Sleep (3000);
 //cout << pin * pin2;
 cout << "Load (1) / Save (2) / Options (3) / Exit (4)";
 cin >> Tecla;
 if (Tecla == '1') {
    cout << "Bem vindo ao Ursaventuras" << endl;
    system ("pause");
 }
}

if (Tecla == '4') {
     WAP:
 cout << "Conexao Falhou.Sair?";
 cin >> Tecla;
  if (Tecla = 's') {
    goto menu;
 }
  if (Tecla = 'n') {
    cout << "Recarregando..." << endl;
    Sleep (3000);
    goto WAP;
 }
}

 if (Tecla == '5') {
       Gerarq:
 cout << "01-Meus Arquivos";
 cout << endl;
 cout << "02-Aplicativos";
 cout << endl;
 cout << "03-Jogos";
 cout << endl;
 cout << "04-Itac";
 cin >> Tecla;
    switch (Tecla) {
case '1':
    cout << "01-Fotos";
 cout << endl;
 cout << "02-Gravacoes";
 cout << endl;
 cout << "03-Downloads";
 cout << endl;
 cout << "04-Voltar";
    cin >> Tecla;
    goto menu;

    } //gerarq
 }


if (Tecla == '6') {
  cout << "Bem vindo ao ITADos.Insira um comando";
 cin >> Tecla;
 goto Cmd;
}


if (Tecla == 7) {
    cout << "Tchau";
}


if (Tecla == 8) {
  cout << "Tem certeza que deseja resetar todas as configuracoes do celular?(s/n)";
 cin >> Tecla;
}
Bloq:

    if (Bloqueiodesim == 1) {
            pin2=0;
    while (pinDigitado != pin4 && pinDigitado != pinbackup3) {
            system ("cls");
        cout << "Insert PIN" << endl;
     cout << (char) 219 << (char) 219 << (char) 219 << (char) 219 << (char) 219 << (char) 219 << (char) 219 << (char) 219 << (char) 219 << (char) 219 << (char) 219 << endl;
     cout << (char) 219 << "         " << (char) 219 << endl;
     cout << (char) 219 << (char) 219 << (char) 219 << (char) 219 << (char) 219 << (char) 219 << (char) 219 << (char) 219 << (char) 219 << (char) 219 << (char) 219 << endl;
        //cin >> pin2;
         gotoxy (1,2);
 chDigitado = getch ();
 while (chDigitado != 13) {
 pinDigitado += chDigitado;
 cout << "*" ;
 chDigitado = getch ();
 }
// stringstream(pinDigitado) >> pin;
 gotoxy (0,4);
        cout << pin4 << endl;
    }
    goto menu;
    } else {
    goto menu;
    }
//case  '9':
 //cout << "Tchau";

  }







//}


