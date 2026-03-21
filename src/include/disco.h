/// DISCO.H - MODULO DE GERENCIAMENTO DE DISCOS
/// Estruturas e variaveis globais para discos virtuais A e B

#ifndef DISCO_H
#define DISCO_H

#include <string>
using namespace std;

/// ESTRUTURA PARA REPRESENTAR UM DISCO VIRTUAL
struct Disco {
    string arquivo;                    /// ARQUIVO DO DISCO
    string label;                      /// NOME DO DISCO
    string conteudo[20];               /// LISTA DE ARQUIVOS E PASTAS
    string icones[5][3];               /// ICONS PARA VISUALIZACAO
    string tamanhos[20];               /// TAMANHO DOS ARQUIVOS
    int numArquivos;                   /// QUANTIDADE DE ARQUIVOS
    string blocksFree;                 /// ESPACO LIVRE
};

/// VARIAVEIS GLOBAIS DE DISCO
extern Disco DiscoA;
extern Disco DiscoB;

/// VARIAVEIS ANTIGAS (PARA COMPATIBILIDADE - A REFATORAR)
extern string DiscoAFile;       /// ARQUIVO DO DISCO A DO ARQUIVO DE SETTINGS
extern string DiskBFile;        /// ARQUIVO DO DISCO B DO ARQUIVO DE SETTINGS

extern string DiskALabel;       /// NOME DO DISCO A
extern string DiskBLabel;       /// NOME DO DISCO B

extern string DiskAContent[20]; /// LISTA DE ARQUIVOS E PASTAS DO DISCO A
extern string DiskBContent[20]; /// LISTA DE ARQUIVOS E PASTAS DO DISCO B

extern string DiskAIcons[5][3]; /// LISTA DE ARQUIVOS E PASTAS DO DISCO A
extern string DiskBIcons[5][3]; /// LISTA DE ARQUIVOS E PASTAS DO DISCO B

extern string DiskASizes[20];   /// TAMANHO DOS ARQUIVOS DO DISCO A
extern string DiskBSizes[20];   /// TAMANHO DOS ARQUIVOS DO DISCO B

extern string DiskABlocksFree;  /// ESPACO LIVRE NO DISCO A
extern string DiskBBlocksFree;  /// ESPACO LIVRE NO DISCO B

extern short NumArquivosA;      /// NUMERO DE ARQUIVOS POR DISCO
extern short NumArquivosB;      /// NUMERO DE ARQUIVOS DO DISCO B

extern string ModoVisualisar;   /// MODO DE VISUALIZACAO DE ARQUIVOS DOS DISCOS

#endif
