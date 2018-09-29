/// BIBLIOTECA DE FUNCOES DE I/O PARA O ITADOS GRAPH POR ARUNI AMSTEL, COPYLEFT 2017
///* This Software was written by Aruni Amstel (bioaruni@gmail.com) in may, 2017.
///* This file use the GNU-GPL license available at https://www.gnu.org/licenses/gpl-2.0.txt
///* This library is the main I/O functions for the operating system ITADOS
///* This code is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.

// DEFINE A RESOLUCAO VGA DA TELA PARA 80X24
void setScreenRes() {
     __asm__ __volatile__(
          "int $0x10" : : "a"(0x0003)
     );
}

// LIMPA A TELA
void cls() {
     __asm__ __volatile__ (
          "int $0x10" : : "a"(0x0200), "b"(0x0000), "d"(0x0000)
     );
     __asm__ __volatile__ (
          "int $0x10" : : "a"(0x0920), "b"(0x0007), "c"(0x2000)
     );
}

// DEFINE A POSICAO X E Y DO CURSOR
void gotoxy (uint32_t X, uint32_t Y) { // NAO EXISTEM POSICOES DO CURSOR MENORES QUE 0
     __asm__ __volatile__ (
          "int $0x10" : : "a"(0x0200), "d"((Y <<= 8) | X)
     );
}

// MOSTRA OU ESCONDE O CURSOR
void showConsoleCursor (bool choice) {
     if(choice == false) {
          __asm__ __volatile__(
               "int $0x10" : : "a"(0x0100), "c"(0x3200)
          );
     } else {
          __asm__ __volatile__(
               "int $0x10" : : "a"(0x0100), "c"(0x0007)
          );
     }
}

// FUNCOES DE ENTRADA E SAIDA
// LE UM CARACTERE DO TECLADO, MAS NAO O IMPRIME NA TELA
void getch() {
     __asm__ __volatile__ (
          "xorw %ax, %ax\n"
          "int $0x16\n"
     );
}

// LE DADOS (STRING) ENTRADOS PELO USUARIO ATE QUE ELE PRESSIONE UM ENTER (SEMELHANTE AO SCANF)
string ReadKeyboard () {
	string str;
	int cont = 0;
	while (C != '\r') {
		C = getch ();
		str [cont] = C;
		cont++;
	}
	return str;
}

// SEMELHANTE AO GETCH, MAS RETORNA O VALOR ASCCI CORRESPONDENTE AO CARACTERE DA TECLA PRESSIONADA
short getchar() {
     short ASCIIcode; // CODIGO INTEIRO DA TABELA ASCII

     __asm__ __volatile__(
          "int $0x16" : : "a"(0x1000)
     );

     __asm__ __volatile__(
          "movw %%ax, %0" : "=r"(ASCIIcode)
     );

     return ASCIIcode;
}

// IMPRIME UM CARACTERE NA TELA
void printchar (short chr) {
     __asm__ __volatile__(
          "int $0x10" : : "a"(0x0e00 | (char)chr)
     );
}

// IMRIME UMA STRING NA TELA
void echo (const char* pStr) {
     while(*pStr) {
          __asm__ __volatile__ (
               "int $0x10" : : "a"(0x0e00 | *pStr), "b"(0x0002)
          );
          ++pStr;
     }
}

// DELAY, ESPERA UM DETERMINADO TEMPO
void delay (int seconds) {
     __asm__ __volatile__(
          "int $0x15" : : "a"(0x8600), "c"(0x000f * seconds), "d"(0x4240 * seconds)
     );
}

// PAUSA O CONSOLE
void pause () {
    echo ("Pressione qualquer tecla para continuar... \n");
    getch ();
}
