# ==================== CONFIGURAÇÕES ====================

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
LDFLAGS = 

# Diretórios
LIB_DIR = binarySearchTree
BUILD_DIR = build
BIN_DIR = bin

# Arquivos da biblioteca
LIB_HEADER = $(LIB_DIR)/binary_search_tree.h
LIB_SOURCE = $(LIB_DIR)/binary_search_tree.c
LIB_OBJECT = $(BUILD_DIR)/binarySearchTree.o

# Arquivos fonte (todos os .c na pasta atual, exceto os da biblioteca)
SOURCES = $(filter-out $(LIB_SOURCE), $(wildcard *.c))
OBJECTS = $(SOURCES:%.c=$(BUILD_DIR)/%.o)
TARGETS = $(SOURCES:%.c=$(BIN_DIR)/%.exe)

# ==================== REGRAS PRINCIPAIS ====================

# Regra padrão: compila tudo
all: dirs $(TARGETS)

# Cria os diretórios necessários
dirs:
	@if not exist "$(BUILD_DIR)" mkdir "$(BUILD_DIR)" 2>nul || echo.
	@if not exist "$(BIN_DIR)" mkdir "$(BIN_DIR)" 2>nul || echo.

# Regra genérica para criar executáveis
$(BIN_DIR)/%.exe: $(BUILD_DIR)/%.o $(LIB_OBJECT)
	@echo Linkando $@...
	$(CC) $^ -o $@ $(LDFLAGS)
	@echo Executavel criado: $@

# Regra genérica para compilar arquivos .c em .o
$(BUILD_DIR)/%.o: %.c $(LIB_HEADER)
	@echo Compilando $<...
	$(CC) $(CFLAGS) -c $< -o $@

# Compila a biblioteca
$(LIB_OBJECT): $(LIB_SOURCE) $(LIB_HEADER)
	@echo Compilando biblioteca...
	$(CC) $(CFLAGS) -c $< -o $@

# ==================== REGRAS ESPECÍFICAS ====================

# Compila apenas q01
q01: dirs $(BIN_DIR)/q01.exe

# Compila apenas q02 (adicione quando criar)
q02: dirs $(BIN_DIR)/q02.exe

q03: dirs $(BIN_DIR)/q03.exe

q04: dirs $(BIN_DIR)/q04.exe

q05: dirs $(BIN_DIR)/q05.exe

q06: dirs $(BIN_DIR)/q06.exe

q08: dirs $(BIN_DIR)/q08.exe

q09: dirs $(BIN_DIR)/q09.exe

# Executa q01
run-q01: dirs $(BIN_DIR)/q01.exe 
	@echo Executando q01...
	@$(BIN_DIR)/q01.exe

# Executa q02
run-q02: dirs $(BIN_DIR)/q02.exe
	@echo Executando q02...
	@$(BIN_DIR)/q02.exe

# Executa q03
run-q03: dirs $(BIN_DIR)/q03.exe
	@echo Executando q03...
	@$(BIN_DIR)/q03.exe

run-q04: dirs $(BIN_DIR)/q04.exe
	@echo Executando q04...
	@$(BIN_DIR)/q04.exe

run-q05: dirs $(BIN_DIR)/q05.exe
	@echo Executando q05...
	@$(BIN_DIR)/q05.exe

run-q06: dirs $(BIN_DIR)/q06.exe
	@echo Executando q06...
	@$(BIN_DIR)/q06.exe

run-q08: dirs $(BIN_DIR)/q08.exe
	@echo Executando q08...
	@$(BIN_DIR)/q08.exe

run-q09: dirs $(BIN_DIR)/q09.exe
	@echo Executando q09...
	@$(BIN_DIR)/q09.exe

# ==================== REGRAS DE LIMPEZA ====================

# Remove arquivos de compilação
clean:
	@echo Limpando arquivos temporarios...
	@if exist "$(BUILD_DIR)" rmdir /S /Q "$(BUILD_DIR)" 2>nul || echo.
	@if exist "$(BIN_DIR)" rmdir /S /Q "$(BIN_DIR)" 2>nul || echo.
	@echo Limpeza concluida.

# Remove tudo e recompila
rebuild: clean all

# ==================== REGRAS DE AJUDA ====================

# Mostra ajuda
help:
	@echo ==================== MAKEFILE HELP ====================
	@echo.
	@echo Comandos disponiveis:
	@echo   make all       - Compila todos os arquivos .c
	@echo   make q01       - Compila apenas q01.c
	@echo   make q02       - Compila apenas q02.c  
	@echo   make run-q01   - Compila e executa q01
	@echo   make run-q02   - Compila e executa q02
	@echo   make clean     - Remove arquivos temporarios
	@echo   make rebuild   - Limpa tudo e recompila
	@echo   make help      - Mostra esta ajuda
	@echo.
	@echo Estrutura de diretorios criada:
	@echo   build/         - Arquivos objeto (.o)
	@echo   bin/           - Executaveis (.exe)
	@echo   binarySearchTree/ - Biblioteca BST
	@echo.
	@echo ====================================================

# ==================== CONFIGURAÇÕES ESPECIAIS ====================

# Evita conflitos com arquivos que tenham o mesmo nome das regras
.PHONY: all clean rebuild help dirs run-q01 run-q02 q01 q02

# Não deleta arquivos intermediários
.PRECIOUS: $(BUILD_DIR)/%.o
