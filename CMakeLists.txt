cmake_minimum_required(VERSION 3.5)
project(concordo VERSION 0.1 LANGUAGES CXX )


### Executável
# Diretório contendo os .hpp
include_directories( include )

# Cria um executável com nome "concordo", adiciona neste executável os arquivos src1/concordo.cpp src1/sistema.cpp src1/executor.cpp
add_executable( concordo
                src1/concordo.cpp
                src1/sistema.cpp 
								src1/executor.cpp
								src1/usuario.cpp
								src1/servidor.cpp )

# The end
