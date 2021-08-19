 #ifndef MENSAGEM_H
#define MENSAGEM_H
#include <string>
#include <vector>
#include <iostream>
#include <string.h>
using namespace std;

/*
CP2 Ok
*/
class Mensagem{
	private:
	int enviadaPor;//<! um inteiro com o id do usuário que enviou a mensagem
	string conteudo;//<! uma string com o conteudo da mensagem 
	string dataHora;//<! uma string com a datahora do envio da mensagem

	public:
	/*! Construtor padrão que serve para inicializar objetos de seu tipo de classe.
				@param enviadaPor o id do usuário 
				@param senha a mensagem enviada pelo usuário
		*/
	Mensagem(int enviadaPor, string conteudo);
	/*! retorna a data/hora de uma mensagem enviada 
				@return a data/hora do envido da mensagem
		*/
	string get_datahora();
	/*! retorna o conteudo de uma mensagem
				@return uma string contendo o conteudo da mensagem
		*/
	string get_conteudo();
	/*! retorna o id do usuário que enviou a mensagem
				@return um inteiro contendo o id do usuário
		*/
	int get_enviadaPor();
	/*! imprime a mensagem enviada por um usuário no formato nome/datahora/conteudo
				@return uma string contendo a mensagem formatada
		*/
	string printm(string m);
};

#endif