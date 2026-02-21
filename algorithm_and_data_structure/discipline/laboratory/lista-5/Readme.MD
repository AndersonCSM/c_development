# Análise de Performance de Algoritmos de Ordenação e Busca

**Autor:** Anderson Carlos da Silva Morais  
**Disciplina:** Algoritmos e estrutura de dados I

Este projeto em C realiza uma análise comparativa de performance entre diferentes algoritmos de ordenação e busca. Os testes são executados em arrays de inteiros, arrays de caracteres e listas de palavras, com os resultados sendo salvos em arquivos de texto formatados.

## Funcionalidades

- **Comparação de Algoritmos de Ordenação**:
  - BubbleSort
  - InsertionSort
  - MergeSort
  - QuickSort
- **Comparação de Algoritmos de Busca**:
  - Busca Linear
  - Busca Binária
- **Testes em Múltiplos Cenários**:
  - Arrays de inteiros com tamanhos variados (1.000, 100.000, 1.000.000).
  - Arrays de caracteres aleatórios.
  - Busca de palavras em um texto pré-definido.
- **Geração de Relatórios**:
  - Os resultados dos testes de ordenação são salvos em `data/q1.txt`.
  - Os resultados dos testes de busca são salvos em `data/q2.txt`.
  - Os relatórios incluem tabelas formatadas com os tempos de execução em segundos.

## Estrutura do Projeto

```
.
├── Makefile
├── bin/
│   └── main.exe
├── data/
│   ├── q1.txt
│   └── q2.txt
├── include/
│   ├── auxiliar.h
│   ├── search-algorithms.h
│   └── sorting-algorithms.h
└── src/
    ├── auxiliar.c
    ├── main.c
    ├── search-algorithms.c
    └── sorting-algorithms.c
```

## Como Compilar e Executar

Este projeto utiliza um `Makefile` para facilitar a compilação e execução. Certifique-se de ter o `gcc` e o `mingw32-make` (ou `make`) instalados.

### Comandos

- **Compilar o projeto:**
  ```sh
  mingw32-make
  ```
- **Compilar e executar todos os testes:**
  ```sh
  mingw32-make run
  ```
  *Observação: No arquivo `src/main.c`, a variável `test` controla qual bateria de testes é executada (`1` para ordenação, `2` para busca).*

- **Limpar os arquivos gerados (executável e diretório `bin`):**
  ```sh
  mingw32-make clean
  ```

## Resultados

Após a execução, os resultados detalhados podem ser encontrados na pasta `data/`.

### Exemplo de Saída (`data/q1.txt`)

```plaintext
Algoritmos de Ordenacao
Tamanho do Array: 100000
+-----------------+-----------------------+
| Metodo          | Tempo (s)             |
+-----------------+-----------------------+
| BubbleSort      | 22,236999999999998000 |
| InsertionSort   | 7,296999999999999700  |
| MergeSort       | 0,000000000000000000  |
| QuickSort       | 0,016000000000000000  |
+-----------------+-----------------------+
```

### Exemplo de Saída (`data/q2.txt`)

```plaintext
Algoritmos de Busca
Cenario: Array de 1000000 inteiros
+-----------------+-----------------------+
| Metodo          | Tempo (s)             |
+-----------------+-----------------------+
| linear          | 0,687999999999999940  |
| binaria         | 0,002000000000000000  |
+-----------------+-----------------------+
```