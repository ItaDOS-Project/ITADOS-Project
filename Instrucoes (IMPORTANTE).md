## Instruções para Instalação, execução e Compilação

# 1. Clone o repositório
git clone https://github.com/ItaDOS-Project/ITADOS-Project.git
cd ITADOS-Project
Para baixar o repositório e instala-lo no seu ambiente local, clique no botão "clone", copie o link
fornecido e cole no terminal do seu sistema seguido do comando "git clone" e pressione ENTER.
é necessário possuir o git bash ou ferramentas semelhantes instaladas na sua máquina.

# Estrutura do projeto
O código fonte está dividido nos seguintes principais arquivos:
Interface CLI: ITADOS.cpp
Interface "Gráfica": iTADOS GRAPH.cpp
Command Parser: CMD_ITADOS.cpp

# Compilação local
make all

# Ou compile passo a passo:
make kernel    # Compila o kernel
make shell     # Compila o shell  
make apps      # Compila as aplicações
make iso       # Cria imagem bootável

# Instruções de Uso

Uma vez compilado, para executar a interface do sistema, você deve abrir o executável
"ITADOS". Você será introduzido a uma interface de linha de comando com a seguinte mensagem:
"Bem vido ao ITADOS!
ITAC_HD/>
"
Isso significa que o sistema foi compilado, pode encontrar todas as dependências necessárias e inicializou corretamente

# Principais Comandos

Uma vez executando, o ITADOS fornece essa lista de comandos:

abr - Abre um arquivo ou / com aplicacao
calc - Calculadora
cd - Muda a pasta atual
crd - Cria uma pasta
create - Cria um arquivo ou pasta novos
changevar - Altera o valor de uma variavel
cls - Limpa a tela
config - Define as preferencias do sistema, do PC e da interface
copy - Copia um arquivo
del - Deleta um arquivo
dir - Mostra os arquivos presentes em uma pasta
disk - Lista as unidades de disco do computador
exit - Fecha todos os aplicativos / Sai do ITADOS
echo - Imprime uma linha de texto (string) ou variavel na tela
end - Finaliza o parametro
goto - Vai para o ponto de referencia (linha) inserido, usado em scripts batch
help - Mostra itens de ajuda e instrucoes / consulta o modo de uso de um comando
info - Exibe informacoes / status do sistema / PC
jump - Posiciona o cursor em uma determinada posicao x e y
last - carrega o ultimo aplicativo aberto no disco
path - mostra o endereco da pasta atual
pause - Pausa qualquer acao do console
printvar - imprime uma variavel numerica na tela
pchar - imprime um caractere ASCII na tela
run - Iniciar um programa, comando ou arquivo em BAT
ret - Retorna um determinado valor a quem chamou / fecha um programa
scrwrite - imprime uma string ou texto na tela, sem quebra de linha no final
string - Cria uma string na memoria
sudo - Efetua comandos, funcoes e programas no modo de superusuario (com todas as permissoes)
textreset - Reseta o texto padr├úo do prompt de comando
undel - recupera um arquivo enviado para a lixeira
var - cria uma variavel local / do sistema / reserva um espaco de memoria (/m)
version - Exibe/ Mostra a versao atual do sistema
verify - verifica a existencia do arquivo especificado
xrun - faz uma chamada externa a programas DOS/Windows .BAT ou .EXE

Digite '?' como parametro universal para o comando que deseja saber seu modo de uso, seus subcomandos e seus parametros


