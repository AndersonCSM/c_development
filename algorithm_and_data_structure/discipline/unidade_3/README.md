# Simulador de Escalonamento Round Robin em C

Este projeto é uma implementação simples do algoritmo de escalonamento de processos Round Robin, desenvolvido em linguagem C para disciplina de Algoritmo e estrutura de dados I do semestre 2025.1. 
O algoritmo simula a execução de um conjunto de processos em uma CPU, onde cada processo recebe uma fatia de tempo (quantum) para executar de forma alternada.

Integrantes:
- Amanda Aparecida Gonçalves Chaves
- Anderson Carlos da Silva Morais
- Marília Fonseca Andrade

## Estrutura do Projeto

O projeto é composto pelos seguintes arquivos:

*   `main.c`: Contém a lógica principal da simulação do Round Robin e a função `main` para iniciar o programa. É aqui que os processos de exemplo são definidos.
*   `queue.h`: Arquivo de cabeçalho que define as estruturas de dados para a Fila (`Queue`) e para os Processos (`Processo`), bem como os protótipos das funções de manipulação da fila.
*   `queue.c`: Implementação das funções da fila (enfileirar, desenfileirar, verificar se está vazia, etc.), que é usada para gerenciar a ordem dos processos prontos para execução.
*   `main.exe`: O arquivo executável gerado após a compilação do código-fonte.

## Como Compilar e Executar

Para compilar o projeto, você precisará de um compilador C, como o GCC. Abra um terminal na pasta do projeto e execute o seguinte comando:

```bash
gcc main.c queue.c -o main.exe
```

Isso irá compilar os arquivos de código-fonte e gerar um executável chamado `main.exe` (ou `main` em sistemas Linux/macOS).

Para executar a simulação, basta rodar o programa gerado:

```bash
./main.exe
```

O programa exibirá o passo a passo da execução dos processos, mostrando as chegadas, a execução de cada processo por um quantum de tempo e a finalização.

## Funcionamento do Algoritmo

O algoritmo implementado em `main.c` segue os seguintes passos:

1.  **Inicialização**: Uma fila de processos prontos é inicializada e o tempo da simulação começa em `0`.
2.  **Loop Principal**: A simulação continua enquanto houver processos que não foram concluídos.
3.  **Verificação de Chegadas**: A cada instante de tempo, o sistema verifica se novos processos chegaram (comparando o `tempo_chegada` do processo com o `tempo_atual` da simulação). Se sim, eles são adicionados ao final da fila de prontos.
4.  **Execução do Processo**:
    *   Se a fila de prontos não estiver vazia, o primeiro processo da fila é removido para ser executado.
    *   O processo executa por um tempo igual ao `quantum` definido ou pelo seu tempo restante, o que for menor.
    *   O tempo da simulação avança.
5.  **Reenfileiramento ou Finalização**:
    *   Se o processo ainda não concluiu sua execução (`tempo_restante > 0`), ele é colocado de volta no final da fila de prontos. Antes disso, o sistema verifica novamente se algum processo chegou enquanto o atual executava.
    *   Se o processo terminou, ele é marcado como concluído.
6.  **CPU Ociosa**: Se a fila de prontos estiver vazia, mas ainda houver processos para chegar, a CPU fica ociosa e o tempo da simulação avança.
7.  **Fim da Simulação**: O loop termina quando todos os processos forem concluídos, e o tempo total da simulação é exibido.

## Como Modificar os Processos ou o Quantum

Para testar a simulação com diferentes processos ou com um valor de quantum diferente, você pode editar a função `main` no arquivo `main.c`:

```c
int main()
{
    // Altere os processos aqui
    Processo processos[] = {
        // {id, tempo_execucao_total, tempo_restante, tempo_chegada}
        {1, 8, 8, 0}, 
        {2, 4, 4, 2},
        {3, 6, 6, 4},
        {4, 2, 2, 7}
    };

    int tot_processos = sizeof(processos) / sizeof(Processo);
    
    // Altere o valor do quantum (timer) aqui
    int timer = 3; 

    round_robin(processos, tot_processos, timer);

    return 0;
}
```

