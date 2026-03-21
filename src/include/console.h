/// CONSOLE.H - MODULO DE FUNCOES DE CONSOLE
/// Funcoes para manipulacao de cursor, cores e efeitos de console

#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <windows.h>
#include <fstream>
using namespace std;

/// FUNCAO PARA POSICIONAR CURSOR NA TELA
void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

/// FUNCAO ALTERNATIVA DE POSICIONAMENTO DE CURSOR
void mgotoxy(int x,int y)
{
  COORD p={x,y};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),p);
}

/// FUNCAO PARA MUDAR COR DO CONSOLE
void Cor (int Corconsole)
{
  HANDLE  hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, Corconsole);
}

/// FUNCAO PARA MOSTRAR OU ESCONDER O CURSOR
void ShowConsoleCursor(bool showFlag)
{
  HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_CURSOR_INFO cursorInfo;

  GetConsoleCursorInfo(out, &cursorInfo);
  cursorInfo.bVisible = showFlag;
  SetConsoleCursorInfo(out, &cursorInfo);
}

/// FUNCAO PARA RESETAR A COR PARA PADRAO (BRANCO/PRETO)
void Resetcor ()
{
  Cor (240);
}

/// FUNCAO PARA CRIAR EFEITO VISUAL NA TELA
void Efeito_tela ()
{
  gotoxy (0,0);
  int Count = 0;
  while (Count != 40) {
    cout << " " ;
    Count++;
  }
}

/// FUNCAO PARA VERIFICAR SE UM ARQUIVO EXISTE
bool exist(const char *fileName)
{
  std::ifstream infile(fileName);
  return infile.good();
}

/// FUNCAO PARA CRIAR EFEITO DE PISCADA NA TELA
void PiscaTela ()
{
  system ("cls");
  Sleep (50);
  system ("color");
  Sleep (50);
  system ("color f0");
  Sleep (50);
  system ("color");
  Sleep (50);
  system ("color f0");
}

#endif
