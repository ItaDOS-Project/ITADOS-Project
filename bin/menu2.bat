@ECHO OFF
callib doslib.bat

cls
string com
string pasta
string ajd
string prog

defstring ajd "LIMPATELA - limpa a tela "\n" LPASTA - imprime lista de arquivos da pasta \n MUDARPASTA - muda a pasta ABRIRPASTA - Entra numa pasta \n SAIR - sai do programa'
config scrcolor 0e
echo URSODOS versão 1.0
echo escreva ajuda para ver a lista de comandos
echo$ ajd
newln
vcolor 314, 12
scrwrite COMANDO>
usrin com
if com = LIMPATELA cls
if com = LPASTA dir
if com = MUDARPASTA usrin pasta
if com = ABRIRPASTA cd pasta
if com = NOVOARQ path
if com = ajuda echo$ ajd
if com = run :
usrin prog
callfn prog_exec %prog
;
if com = load :
usrin prog
callfn disk.open %"prog",$!
if com = SAIR goto 21
goto 9
newln
pause

