# Escalonamento de processos interativos - Round-Robin

Projeto desenvolvido em linguagem C para simular um escalonamento de processos - interativos, utilizando por padrão o processo Roud-Robin, o desenvolvimento tem como objetivo de ler um arquivo de entrada padrão (stdin) e fornecer as saídas do programa em outro arquivo padrão (stdout).

### 📋 Pré-requisitos

De que coisas você precisa para instalar o software e como instalá-lo?

```
Um editor de códigos,
um compilador de C e 
acesso ao terminal.
```
## 🚀 Executando

<ol>
  <li>Clique em **code** e copie um dos links disponíveis </li>
  <li>Na sua máquina use <code>git clone <link copiado></code></li>
  <li>verifique se o arquivo de entrada está na mesma pasta que o arquivo main.c</li>
  <li>Agora basta executar <code>g++ -o meuprograma main.c</code> para gerar um executável</li>
  <li>E por fim, estando no mesmo diretório do arquivo meuprograma.exe, só execute .\meuprograma.exe no terminal</li>
</ol> 
Após esse processo seu arquivo de saída já vai ter sido gerado. 

**obs:** Para executar novamente, deletar o arquivo de saída existente na mesma pasta.

## 📝 Padrão de arquivos de entrada

Cada linha da entrada corresponde a um processo, com os seguintes dados fornecidos como inteiros separados por
um espaço em branco.
Onde a primeira coluna (colada a esquerda do arquivo) corresponde a data de criação,
A segunda, corresponde a duração em segundos e
A terceira, corresponde a prioridade estática (escala de prioridades positivas) do processo. 

Ex:

0 5 4<br>
1 3 2<br>
2 5 8<br>

## ✒️ Autores

* **Alyson Henrique** - *Desenvolvimento* - [alysondv](https://github.com/alysondv)
* **Mariana Tonini** - *Desenvolvimento* - [maritonini](https://github.com/maritonini)
* **Nonato Jr.** - *Desenvolvimento* - [NonatoJr](https://github.com/NonatoJr)

