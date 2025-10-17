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

    DIR *d;
    struct dirent *dir;

using namespace std;

char Tecla;

char q = 219;


string ArquivosDir [50]; /// LISTA DE ARQUIVOS EM UM DIRETORIO



ifstream myfile1;
ofstream myfile;




char PASTA [100];


string NOMEBAT = "";


int index = 0;
int numlinhas = 0;

string linhas [1000];
string linha = "";
string linhaBat;


/*string param1;
string param2;
string param3;
string param4;*/

string param [8];

string comandoPrincipal = "";

char ch;


/// VARIAVEIS DO CMD

int Padron1 = 0;

string Padron = "";
string Pastachange = "";
string Pasta = ".";
string AplicacaoRodar = "";
string pin2;

bool sudolock = false;

int X = 0;
int Y = 0;

char Variaveis [40]; ///  PARA FUNCOES DE VARIAVEIS DO CMD
string VariaveisNome [40];
int Vi = 0;
int NovoValor = 0;
string Varname;
char Var = 0;
string ListaStrings [40];
string NomeStrings [40];
int Vs = 0;

string Useread = "";


int LinhaGoto = 0;


bool echoff = false;
bool CMDdireto = false;

bool goTO = false;


///----------------------------------------------------------------------------

void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
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


void Snake () {
    system ("./SNAKE");
}

void Itatexto () {
    system ("./ITATEXTO");
}

void ImprimeComQuebradelinha (string str) {
string verif = "";
  for (int i =0; i < str.length (); i++) {
  cout << str [i];
    if (str [i] == ' ') {
        if (str [i+1] == '\\') {
            if (str [i+2] == 'n') {
                cout << endl;
                i+=2;
            }
        }
    }
  }
  cout << endl;
}




void parse_cmd (string maincmd, string p1, string p2, string p3, string p4, string p5, string p6, string p7) {

    /*if (Padron1 == 0) {
     cout << "ITACHD_/";
    } else {
    cout << Padron;
    } */


if ((maincmd == "cd")||(maincmd == "CD")) {
        cout << endl;
    Pastachange = p1;
    Pasta += ("/" +Pastachange);


}
if ((maincmd == "CLS")||(maincmd == "cls")) { //PNM
     system ("cls");
}


if ((maincmd == "dir")||(maincmd == "DIR")) { //pnm1
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
if (maincmd == "resetterm") { //pnm1
     Sleep (1000);
     system ("exit 1e");
     system ("color 1e");
     system ("cls");
     Padron1 = 0;
}

if ((maincmd == "exit")||(maincmd == "EXIT")) { //pnm2
     system ("color 0a");
     system ("cls");
     Padron1 = 0;
}

if ((maincmd == "copy")||(maincmd == "COPY")) { //ret
     system (("copy " + p1 + " " + p2).c_str());
     cout << "Done" << endl;
}

if ((maincmd == "del")||(maincmd == "DEL")) { //rdb
       cout << "Done" << endl;
}

if ((maincmd == "undel")||(maincmd == "UNDEL")) { //rdb
       cout << "Done" << endl;
}


if ((maincmd == "pause")||(maincmd == "PAUSE")) { //rdb
     system ("pause");
     cout << "\n";
}



if ((maincmd == "path") || (maincmd == "PATH")) {
     cout << "Pasta atual: " << Pasta << endl << endl;

}

if ((maincmd == "create")||(maincmd == "CREATE")) { //rdb

     cout << "(1) - Pasta" << endl;
     cout << "(2) - Arquivo Generico" << endl;
     if (p1 == "1") {
            system (("md "+ p2).c_str ());
            cout << "\n done" << endl;
     } else if (p1 == "2") {
                myfile.open (p2.c_str());
                myfile << "." << endl;
                myfile.close ();
                cout << "\n done" << endl;
     }


}
if ((maincmd == "crd") || (maincmd == "CRD")) { //rdb
    system (("md "+ p1).c_str ());
    cout << "done" << endl;
}

if ((maincmd == "calc.crasp") || (maincmd == "CALC.CRASP")) {
	RUNCALC:
        int Operando = 0;
        int Operador = 0;
        int Operacao = 0;
        int Opt;
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

if  ((maincmd == "calc") || (maincmd == "CALC")) {
        int Operando = 0;
        int Operador = 0;
        char Operacao = 0;
        Operando = atoi (p1.c_str());
        Operacao = p2 [0];
        Operador = atoi (p3.c_str());

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


if ((maincmd == "Itatexto.crasp") || (maincmd == "ITATEXTO.CRASP")) { //rdb

    //PiscaTela ();
    //Itatexto ();
}
if ((maincmd == "ITADOSGRAPH.CRASP") || (maincmd == "Itadosgraph.crasp")) { //rdb

    // goto menu;
    ShowConsoleCursor(false);
    //PiscaTela ();
    gotoxy (10,5);
    cout << "BOOTING ITADOSGRAPH..." << endl;
    gotoxy (0,0);
    //Efeito_tela ();
//    goto ENDCMD;
}

if ((maincmd == "disk") || (maincmd == "DISK")) {
        cout << endl;
        cout << "Unidades de armazenamento disponiveis:" << endl;
        cout << endl;
        cout << "HDD.1: ITACHD/" << endl;
        //cout << "Drive A: " << DiskALabel << endl;
        //cout << "Drive B: " << DiskBLabel << endl;
        cout << "CD ROM: Empty " << endl;
        cout << endl;
}

if ((maincmd == "config") || (maincmd == "CONFIG")) { //rdb //*PNM
          if (p1 == "?") {
        cout << endl;
        cout << "maincmd CONFIG - atributos possiveis:" << endl;
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
     if ((p1 == "settime")||(p1 == "SETTIME")) {
        system ("time");
}
 if ((p1 == "saveconfig")||(p1 == "SAVECONFIG")) {
        cout << "done" << endl;
}


if (p1 == "scrcolor?") {
        system ("color ?");
} //ret
if ((p1 == "scrcolor")||(p1 == "SCRCOLOR")) {

        system (("color " + p2).c_str());
} //ret


if (p1 == "build>setup_v143") {
cout << "Done" << endl;
}
if (p1 == "infosystem") {
cout << "X64 bits System" << endl;
}
if ((p1 == "boot")||(p1=="BOOT")) { // arg param subcommand option propertie attributes

    if (p2 == "/A") {
    cout << endl << "Boot automatico ativado" << endl;
    } else if (p2 == "/L") {

    } else if (p2 == "/D") {
    cout << endl << "Checagem de disco antes do carregamento do sistema ATIVADO" << endl;
    } else if (p2 == "/R") {
    cout << endl << "Todas as configuracoes extras de boot foram removidas com sucesso" << endl;
    }
}

}



if ((maincmd == "var")||(maincmd == "VAR")) { /// CRIA UMA VARIAVEL //////////////////////////////////

if (Vi < 40) {

        if (p2 != "") {
             Var = atoi (p2.c_str());
                  Variaveis [Vi] = Var;
    } else {
        Variaveis [Vi] = 0;
    }

}




     VariaveisNome [Vi] = p1;
     if (Vi < 40) {
        Vi++;
     } else {
        cout << endl << "Erro de execucao! Numero de variaveis por programa excedido! (max 40)" << endl;
     }

}

if ((maincmd == "string")||(maincmd == "STRING")) { /// CRIA UMA VARIAVEL //////////////////////////////////

if (Vs < 40) {

     NomeStrings [Vs] = p1;
     ListaStrings [Vs] = "";

}

     if (Vs < 40) {
        Vs++;
     } else {
        cout << endl << "Erro de execucao! Numero de strings maximo excedido! (max 40)" << endl;
     }

}

if ((maincmd == "PRINTVAR")||(maincmd == "printvar")) { /// IMPRIME O VALOR DE UMA VARIAVEL ////////

     for (int i = 0; i < 40; i++) {
        if (p1 == VariaveisNome [i]) {
            cout << (int) Variaveis [i] << endl;
            break;
        }
     }

}

if ((maincmd == "CHANGEVAR")||(maincmd == "changevar")||(maincmd == "CHVAR")||(maincmd == "chvar")) { /// MUDA O VALOR DE UMA VARIAVEL //////


     NovoValor = atoi (p2.c_str());

    for (int i = 0; i < 40; i++) {
        if (p1 == VariaveisNome [i]) {
            Variaveis [i] = NovoValor;
            break;
        }
     }
}


if ((maincmd == "defstring")||(maincmd == "DEFSTRING")||(maincmd == "stringcontent")||(maincmd == "SETSTR")) { /// MUDA O VALOR DE UMA VARIAVEL //////


    for (int i = 0; i < 40; i++) {
        if (p1 == NomeStrings [i]) {
            ListaStrings [i] = p2;
            break;
        }
     }
}


if ((maincmd == "pchar") || (maincmd == "PCHAR")) {
    NovoValor = atoi (p1.c_str());
    cout << (char) NovoValor;
}


if ((maincmd == "usrin") || (maincmd == "USRIN")) {
    bool found = false;
    //cin >> Useread;
    getline (cin, Useread);

    for (int i = 0; i < 40; i++) { // PESQUISA A LISTA DE STRINGS PRIMEIRO
        if (p1 == NomeStrings [i]) {
            ListaStrings [i] = Useread;
            found = true;
            break;
        }
     }

     if (!found) {
        for (int i = 0; i < 40; i++) { // PESQUISA A LISTA DE VARIAVEIS
        if (p1 == VariaveisNome [i]) {
            NovoValor = atoi (Useread.c_str());
            Variaveis [i] = NovoValor;
            break;
        }
        }
     }


}


if (maincmd == "point") {
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

if ((maincmd == "jump" ) || (maincmd == "JUMP" )) {
        X = atoi( p1.c_str() );
        Y = atoi( p2.c_str() );
    gotoxy (X,Y);

}


if ((maincmd == "scrwrite" )|| (maincmd == "SCRWRITE" )) {
        cout << p1;

}

if ((maincmd == "echo" ) || (maincmd == "ECHO" )) {

        cout << p1 << endl;

}

if ((maincmd == "@echo" ) || (maincmd == "@ECHO" )) {

if (p1 == "off") {
Padron = " ";
Padron1 = 1;
} else if (p1 == "on") {
Padron = "ITACHD_/";
Padron1 = 1;
} else {
Padron = "> ";
Padron1 = 1;
}


}

if ((maincmd == "echo$" ) || (maincmd == "ECHO$" )) {

    for (int i = 0; i < 40; i++) {
        if (p1 == NomeStrings [i]) {
            ImprimeComQuebradelinha (ListaStrings [i]);
            //cout << ListaStrings [i] << endl;
            break;
        }
     }



}


if ((maincmd == "newln" ) || (maincmd == "NEWLN" )) {
    cout << "\n";
}

if ((maincmd == "echo." ) || (maincmd == "ECHO." )) {
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "aaaaaaaaaaa." << endl;
}
if ((maincmd == "Padron" )||(maincmd == "padron" )||(maincmd == "PADRON" )) {
        Padron = p1;
        cout << "O texto padrao foi definido como " << Padron << endl;
        Padron1=1;
  //  goto Comd;
}
if ((maincmd == "Textreset" )||(maincmd == "textreset" )||(maincmd == "TEXTRESET" )) {
        Padron1 = 0;
        cout << "O texto padrao foi redefinido"<< endl;
  //  goto Comd;
}
if ((maincmd == "version" )||(maincmd == "VERSION" )) {
        cout << "Current Version 1.8.3 0000134020180127"<< endl;
  //  goto Comd;
}
if (maincmd == "verify_if_[exist]" ) {
        system (("if exist " + p1 + " echo arquivo existe").c_str());
        //cout << "Arquivo nao encontrado" << endl;
  //  goto Comd;
}
if ((maincmd == "if") || (maincmd == "IF")) { //rdb
        bool found = false;
        bool tipoint = false;
        int valorVar = 0;
        int valorComp = 0;
        string strd = "";

    for (int i = 0; i < 40; i++) { // PESQUISA A LISTA DE STRINGS PRIMEIRO
        if (p1 == NomeStrings [i]) {
            strd  = ListaStrings [i];
            found = true;
            break;
        }
     }

     if (!found) {
        for (int i = 0; i < 40; i++) { // PESQUISA A LISTA DE VARIAVEIS
        if (p1 == VariaveisNome [i]) {
            valorVar = Variaveis [i];
            valorComp = atoi (p3.c_str());
            tipoint = true;
            break;
        }
        }
     }

     if (p2 == "=") {
        if (tipoint) {
            if (valorVar == valorComp) {
                parse_cmd(p4,p5,p6,"","","","","");
            }
        } else {
            if (strd == p3) {
                parse_cmd(p4,p5,p6,"","","","","");
            }
        }

     } else if (p2 == ">") {
            if (valorVar > valorComp) {
                parse_cmd(p4,p5,p6,"","","","","");
            }

     } else if (p2 == "<") {

            if (valorVar < valorComp) {
                parse_cmd(p4,p5,p6,"","","","","");
            }

     } else if (p2 == "<>") {
        if (tipoint) {
            if (valorVar != valorComp) {
                parse_cmd(p4,p5,p6,"","","","","");
            }
        } else {
            if (strd != p3) {
                parse_cmd(p4,p5,p6,"","","","","");
            }
        }
     }

}
if ((maincmd == "for") || (maincmd == "FOR")) { //rdb
    bool found = false;
    int for_i = 0;
    int for_add = 0;
    int for_stop = 0; // countil
    int for_start = 0;




        for (int i = 0; i < 40; i++) { // PESQUISA A LISTA DE VARIAVEIS
        if (p3 == VariaveisNome [i]) {
            for_stop = Variaveis [i];
            found = true;
            break;
        }
        }

        if (!found) {
              for_stop = atoi (p3.c_str());
        }



    for_start = atoi (p2.c_str());

    for_add = atoi (p4.c_str());

    for_i = for_start;

    for (int i = for_start; i < for_stop; i+= for_add) {
        parse_cmd(p5,p6,p7,"","","","","");
        if ((p5 == "printvar") && (p6 == "i")) {
        cout << for_i << endl;
        }
        for_i++;
    }

}



if ((maincmd == "sudo")||(maincmd == "SUDO")) {

     if (p1 == "login") {
        cout << "No server available"<< endl;
}
 if (p1 == "connect_wlan") {
        cout << "done" << endl;
}
 if (p1 == "?") {
        cout << " maincmd SUDO - Parametros Possiveis" << endl << endl;
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
 if (p1 == "get_package") {

}
 if (p1 == "boost") {

}
if (p1 == "config_bootloader") {

} //pnm
if (p1 == "change_password") {
        cin >> pin2;
} //ret
if (p1 == "reboot") {

ShowConsoleCursor(false);
system ("cls");
system ("color 0a");
Sleep (3000);
ShowConsoleCursor(true);

} //rdb
if (p1 == "acess") {

 cout << "done" << endl;
}
if (p1 == "eco_mode") {

        cout << "Modo economico ativado" << endl;
}
if (p1 == "var_mode") {

        cout << "Modo memoria nucleo desativado" << endl;
}
if (p1 == "rundev") {
cout << "Done" << endl;
}
if (p1 == "su") {
    if (sudolock == true) {
    //protecao ();
    } else {
    sudolock = false;
    }
//goto Protecao;
}

}




///  /////////////////////////////////
if ((maincmd == "run") || (maincmd == "RUN")) { //NM
     AplicacaoRodar = p1;
     if ((AplicacaoRodar == "Snake.crasp") || (AplicacaoRodar == "SNAKE.CRASP")) {
        Snake ();
     } else if ((AplicacaoRodar == "itatexto.crasp") || (AplicacaoRodar == "ITATEXTO.CRASP")) {
	//PiscaTela ();
	Itatexto ();
     } else if ((AplicacaoRodar == "unzip") || (AplicacaoRodar == "UNZIP")) {
        cout << "files extracted uscessfully. " << endl;
     } else if ((AplicacaoRodar == "ITADOSGRAPH.CRASP") || (AplicacaoRodar == "itadosgraph.crasp")) {
	ShowConsoleCursor(false);
    	//PiscaTela ();
    	gotoxy (10,5);
    	cout << "BOOTING ITADOSGRAPH..." << endl;
    	gotoxy (0,0);
    	//Efeito_tela ();
//    	goto ENDCMD;
     } else if ((AplicacaoRodar == "calc.crasp") || (AplicacaoRodar == "CALC.CRASP")) {
	goto RUNCALC;
     } else {
     cout << "O sistema nao pode encontrar a aplicacao ou maincmd solicitado " << endl;
     }

}
if ((maincmd == "xrun") || (maincmd == "XRUN")) {
    system (p1.c_str());
}


if ((maincmd == "goto") || (maincmd == "GOTO")) {
    goTO = true;
    LinhaGoto = atoi (p1.c_str());

}



if ((maincmd == "help") || (maincmd == "?") || (maincmd == "HELP")) {
     cout << endl;
     cout << "principais maincmds: " << endl;
     cout << "abr" << endl;
     cout << "calc" << endl;
     cout << "cd" << endl;
     cout << "cls" << endl; //pnm
     cout << "copy" << endl; //ret
     cout << "data" << endl;
     cout << "del" << endl;
     cout << "dir" << endl; //rdb
     cout << "end" << endl;
     cout << "exit" << endl;
     cout << "goto" << endl;
     cout << "end" << endl;
     cout << "pause" << endl;
     cout << endl << " Digite guide para ver uma lista com todos os maincmds do sistema" << endl;
}

if ((maincmd == "guide") || (maincmd == "GUIDE")) { //NM
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
     cout << "cls - Limpa a tela" << endl; //pnm /
     cout << "convert - Converte um parametro ou extensao de arquivo em outro" << endl;
     cout << "config - Define as preferencias do sistema, do PC e da interface" << endl; // novo
     cout << "copy - Copia um arquivo" << endl; //ret /
     cout << "data - Carrega a ultima edicao de dados de um backup externo" << endl;
     cout << "del - Deleta um arquivo (enviando para a lixeira) / apaga defitivamente caso na lixeira" << endl;
     cout << "dir - Mostra os arquivos presentes em uma pasta" << endl; //rdb /lista os diretorios e arquivos de uma pasta
     cout << "disk - Mostra o conteudo do disco" << endl;
     cout << "exit - Fecha todos os aplicativos" << endl;
     cout << "echo - Imprime uma linha de texto (string) ou variavel na tela" << endl; // TDMSC
     cout << "goto - Vai para o ponto de referencia (linha) inserido" << endl;
     cout << "help - Mostra itens de ajuda e instrucoes / guia / lista de maincmds basicos" << endl; // novo
     cout << "info - Exibe informacoes / status do sistema / PC" << endl; // novo
     cout << "end - Finaliza o parametro" << endl;
     cout << "last - carrega o ultimo aplicativo aberto no disco" << endl;
     cout << "path - mostra o endereco da pasta atual" << endl;
     cout << "pause - Pausa qualquer acao do console" << endl;
     cout << "printvar - imprime uma variavel numerica na tela" << endl;
     cout << "pchar - imprime um caractere ASCII na tela" << endl;
     cout << "run - Iniciar um programa, maincmd ou arquivo em BAT" << endl;
     cout << "ret - Retorna um determinado valor a quem chamou / fecha um programa" << endl; // NM
     cout << "scrwrite - imprime uma string ou texto na tela, sem quebra de linha no final" << endl; // NM
     cout << "string - Cria uma string na memoria" << endl; // NM
     cout << "sudo - Efetua comandos, funcoes e programas no modo de superusuario (com todas as permissoes)" << endl; // novo
     cout << "undel - recupera um arquivo enviado para a lixeira" << endl;
     cout << "var - cria uma variavel local / do sistema / reserva um espaco de memoria (/m)" << endl; // novo
     cout << "version - Exibe/ Mostra a versao atual do sistema" << endl;
     cout << "xrun - roda um programa .BAT ou .EXE" << endl;
     cout << endl;
     cout << "Digitar '?' como parametro universal para o comando que deseja saber seu modo de uso, seus subcomandos e seus parametros" << endl;
     cout << "memo* atua como comando de referencia/detino ou gerencia as acoes na memoria RAM do PC" << endl;
     cout << endl;
}

//ENDCMD:
//cout << "\n";

}


/// ---------------------------------------------------------------------------------------


void resetaStrings () {
/*param1 = "";
param2 = "";
param3 = "";
param4 = "";*/

for (int i = 0; i < 8; i ++) {
    param [i] = "";
}

comandoPrincipal = "";
}

void InterpretaLinhaCmd (string Linha) {

int cont = 0;
int lgt = 0;
int continuar = 0;

//const char* comandoPrincipal;

///cout << endl;
char linhachar [Linha.length ()];

for (int i =0; i < Linha.length (); i++) {
linhachar [i] = Linha [i];
}

lgt = Linha.length ();

/*for (int i =0; i < lgt; i++) {
cout << linhachar [i];
}*/
/*
while (ch != 32) { // PEGAR O COMANDO PRINCIPAL
 ch  = linhachar [cont];
 cout << (char) ch;
 comandoPrincipal += ch;
 cont++;
} */

for (int i =0; i < lgt; i++) {
if (linhachar [i] != ' ') {
    comandoPrincipal += linhachar [i];

} else {
continuar = i+1;
break;
}
}

// pre selecao e separacao de parametros dependendo do comando
// comandos de 1 parametro
if ((comandoPrincipal == "echo") || (comandoPrincipal == "ECHO")) {
    for (int i =continuar; i < lgt; i++) {
            param [1] += linhachar [i];
        }

}
if ((comandoPrincipal == "@echo") || (comandoPrincipal == "@ECHO")) {
    for (int i =continuar; i < lgt; i++) {
            param [1] += linhachar [i];
        }


    if ((param [1] == "OFF")||(param [1] == "off")) {
        echoff = true;
    }
}
if ((comandoPrincipal == "goto") || (comandoPrincipal == "GOTO")) {
        for (int i =continuar; i < lgt; i++) {
            param [1] += linhachar [i];
        }
}
if ((comandoPrincipal == "cd") || (comandoPrincipal == "CD")) {
        for (int i =continuar; i < lgt; i++) {
            param [1] += linhachar [i];
        }
}
if ((comandoPrincipal == "crd") || (comandoPrincipal == "CRD")) {
        for (int i =continuar; i < lgt; i++) {
            param [1] += linhachar [i];
        }
}
if ((comandoPrincipal == "pchar") || (comandoPrincipal == "PCHAR")) {
        for (int i =continuar; i < lgt; i++) {
            param [1] += linhachar [i];
        }
}
if ((comandoPrincipal == "run") || (comandoPrincipal == "RUN")) {
        for (int i =continuar; i < lgt; i++) {
            param [1] += linhachar [i];
        }
}
if ((comandoPrincipal == "xrun") || (comandoPrincipal == "XRUN")) {
        for (int i =continuar; i < lgt; i++) {
            param [1] += linhachar [i];
        }
}
if ((comandoPrincipal == "usrin") || (comandoPrincipal == "USRIN")) { // rv readvar rdvar rdv
        for (int i =continuar; i < lgt; i++) {
            param [1] += linhachar [i];
        }
}
if ((comandoPrincipal == "printvar") || (comandoPrincipal == "PRINTVAR")) {
        for (int i =continuar; i < lgt; i++) {
            param [1] += linhachar [i];
        }
}
if ((comandoPrincipal == "padron") || (comandoPrincipal == "PADRON")) {
        for (int i =continuar; i < lgt; i++) {
            param [1] += linhachar [i];
        }
}
if ((comandoPrincipal == "del") || (comandoPrincipal == "DEL")) {
        for (int i =continuar; i < lgt; i++) {
            param [1] += linhachar [i];
        }
}
if ((comandoPrincipal == "undel") || (comandoPrincipal == "UNDEL")) {
        for (int i =continuar; i < lgt; i++) {
            param [1] += linhachar [i];
        }
}
if ((comandoPrincipal == "verify_if_exist") || (comandoPrincipal == "VERIFY_IF_EXIST")) {
        for (int i =continuar; i < lgt; i++) {
            param [1] += linhachar [i];
        }
}
if ((comandoPrincipal == "scrwrite") || (comandoPrincipal == "SCRWRITE")) {
    for (int i =continuar; i < lgt; i++) {
            param [1] += linhachar [i];
        }

}
if ((comandoPrincipal == "string") || (comandoPrincipal == "STRING")) {
        for (int i =continuar; i < lgt; i++) {
            param [1] += linhachar [i];
        }
}
if ((comandoPrincipal == "echo$") || (comandoPrincipal == "ECHO$")) {
        for (int i =continuar; i < lgt; i++) {
            param [1] += linhachar [i];
        }
}


// comandos de 2 parametros

if ((comandoPrincipal == "config") || (comandoPrincipal == "CONFIG")) {

        for (int i =continuar; i < lgt; i++) {
            if (linhachar [i] != ' ') {
            param [1] += linhachar [i];

            } else {
            continuar = i+1;
            break;
            }
            }
        for (int i =continuar; i < lgt; i++) {
            param [2] += linhachar [i];
        }
}
if ((comandoPrincipal == "copy") || (comandoPrincipal == "COPY")) {

        for (int i =continuar; i < lgt; i++) {
            if (linhachar [i] != ' ') {
            param [1] += linhachar [i];

            } else {
            continuar = i+1;
            break;
            }
            }
        for (int i =continuar; i < lgt; i++) {
            param [2] += linhachar [i];
        }
}
if ((comandoPrincipal == "changevar") || (comandoPrincipal == "CHANGEVAR") || (comandoPrincipal == "chvar") || (comandoPrincipal == "CHVAR")) {

        for (int i =continuar; i < lgt; i++) {
            if (linhachar [i] != ' ') {
            param [1] += linhachar [i];

            } else {
            continuar = i+1;
            break;
            }
            }
        for (int i =continuar; i < lgt; i++) {
            param [2] += linhachar [i];
        }
}
if ((comandoPrincipal == "defstring") || (comandoPrincipal == "DEFSTRING") || (comandoPrincipal == "chstr") || (comandoPrincipal == "CHSTR")) {

        for (int i =continuar; i < lgt; i++) {
            if (linhachar [i] != ' ') {
            param [1] += linhachar [i];

            } else {
            continuar = i+1;
            break;
            }
            }
        for (int i =continuar; i < lgt; i++) {
            param [2] += linhachar [i];
        }
}
if ((comandoPrincipal == "var") || (comandoPrincipal == "VAR")) {

        for (int i =continuar; i < lgt; i++) {
            if (linhachar [i] != ' ') {
            param [1] += linhachar [i];

            } else {
            continuar = i+1;
            break;
            }
            }
        for (int i =continuar; i < lgt; i++) {
            param[2] += linhachar [i];
        }
}

if ((comandoPrincipal == "jump") || (comandoPrincipal == "JUMP")) {

        for (int i =continuar; i < lgt; i++) {
            if (linhachar [i] != ' ') {
            param [1] += linhachar [i];

            } else {
            continuar = i+1;
            break;
            }
            }
        for (int i =continuar; i < lgt; i++) {
            param[2] += linhachar [i];
        }
}
if ((comandoPrincipal == "sudo") || (comandoPrincipal == "SUDO")) {

        for (int i =continuar; i < lgt; i++) {
            if (linhachar [i] != ' ') {
            param [1] += linhachar [i];

            } else {
            continuar = i+1;
            break;
            }
            }
        for (int i =continuar; i < lgt; i++) {
            param[2] += linhachar [i];
        }
}
if ((comandoPrincipal == "else") || (comandoPrincipal == "ELSE")) {

        for (int i =continuar; i < lgt; i++) {
            if (linhachar [i] != ' ') {
            param [1] += linhachar [i];

            } else {
            continuar = i+1;
            break;
            }
            }
        for (int i =continuar; i < lgt; i++) {
            param[2] += linhachar [i];
        }
}

// comandos de 4 parametros

if ((comandoPrincipal == "calc") || (comandoPrincipal == "CALC")) {

       for (int d = 1; d < 4; d ++) {
        for (int i =continuar; i < lgt; i++) {
            if (linhachar [i] != ' ') {
            param [d] += linhachar [i];

            } else {
            continuar = i+1;
            break;
            }
            }
           }

}


if ((comandoPrincipal == "if") || (comandoPrincipal == "IF")) {

       for (int d = 1; d < 7; d ++) {
        for (int i =continuar; i < lgt; i++) {
            if (linhachar [i] != ' ') {
            param [d] += linhachar [i];

            } else {
            continuar = i+1;
            break;
            }
            }
           }
        /*for (int i =continuar; i < lgt; i++) {
            param[2] += linhachar [i];
        }*/
}

if ((comandoPrincipal == "for") || (comandoPrincipal == "FOR")) {

       for (int d = 1; d < 8; d ++) {
        for (int i =continuar; i < lgt; i++) {
            if (linhachar [i] != ' ') {
            param [d] += linhachar [i];

            } else {
            continuar = i+1;
            break;
            }
            }
           }

}


//cout << "linha " << comandoPrincipal << " " << param [1]  << " " << param [2] << " " << param [3] << " " << param [4] << " " << param [5] << " corretamente interpretada" << endl;

parse_cmd (comandoPrincipal,param [1], param [2], param [3], param [4], param [5], param [6], param [7]);

if (!echoff) {
cout << "linha " << comandoPrincipal;
for (int i = 1; i < 8; i ++) {
 cout << " " << param [i];
}
cout << " corretamente interpretada" << endl;
}


}

void InterpretaCmd () {

if (!CMDdireto) {
    cout << "BAT CARREGADO COMPLETO PARA A MEMORIA!" << endl;
    cout << "deseja listar o arquivo? s/n" << endl;
    Tecla = getch ();
    if (Tecla == 's') {
    for (int i = 0; i< numlinhas; i++) {
    cout << linhas [i] << endl;
    }
    cout << endl;
    system ("pause");
}

system ("cls");
}

/// INICIO DA INTERPRETACAO DO PROGRAMA QUE FOI CARREGADO NA MEMORIA

for (int i = 0; i < numlinhas ; i++) {
    if (linhas [i] != "end.") {
	InterpretaLinhaCmd (linhas [i]); /// CHAMA O INTERPRETADOR DE COMANDOS PARA EXECUTAR A LINHA
    resetaStrings();
    if (goTO) {
        if (LinhaGoto < numlinhas) {
            i = LinhaGoto;
        }
        LinhaGoto = 0;
        goTO = false;
    }
	} else {
	break;
	}
}

}

void Load (string NOMELOAD) { // CARREGA NA MEMORIA AS LINHAS DO ARQUIVO
ifstream myfileV;

myfileV.open (NOMELOAD.c_str());

    if(myfileV.is_open()){
        while(!myfileV.eof()){
            getline(myfileV,linhaBat);
            numlinhas++;
            linhas [numlinhas] = linhaBat;
        }
        myfile.close();
    }

myfileV.close ();

InterpretaCmd ();
}


int main (int argc, char *argv []) {

system ("cls");
system ("color 0a");
/*
if (argv [0] == NULL ) {
    cout << "Por favor, digite o nome do arquivo / programa que deseja rodar: " << endl;
    getline (cin,NOMEBAT);
} else {
    for (int i =0; i< argv [0].lenght (); i++) {
    NOMEBAT += argv [0] [i];
    }

}*/

if (argc == 1) {
    cout << "Por favor, digite o nome do arquivo / programa que deseja rodar: " << endl;
    getline (cin,NOMEBAT);
    Load (NOMEBAT);
} else if (argc == 2) {
    CMDdireto = true;
    string aux = "";
    int tam = 0;
    tam = strlen(argv[1]) ;

    for (int i =0; i< tam; i++) {
    aux += argv [1] [i];
    }

    Load (aux);

}

/*
string aux = "";
int tam = 0;
tam = strlen(argv[0]) ;

    for (int i =0; i< tam; i++) {
    aux += argv [0] [i];
    }

    cout << aux << endl;

if (aux != "") {
NOMEBAT = aux;
} else {
    cout << "Por favor, digite o nome do arquivo / programa que deseja rodar: " << endl;
    getline (cin,NOMEBAT);
}



Load (NOMEBAT);

*/

getch ();

}
