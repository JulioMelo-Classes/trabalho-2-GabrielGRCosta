#ifndef CANALTEXTO_H
#define CANALTEXTO_H
#include <string>
#include <vector>
#include "mensagem.h"
#include "usuario.h"
#include <iostream>
using namespace std;

/*
CP2 Ok
*/
class CanalTexto{
	private:
	string nome;//<! o nome do canal
	vector <Mensagem> mensagens;//<! um vetor contendo todas as mensagens enviadas num canal

	public:
	/*! Retorna uma string com o nome de um canal
				@return uma string contendo o nome do canal
		*/
	string get_namechanel();
	/*! Seta/define o nome de um canal  
				@param name o nome do canal  
		*/
	void set_namechanel(string name);
	/*! Adiciona uma mensagem dentro do vetor mensagens 
				@param mensage uma variavel do tipo Mensagem 
		*/
	void addmensage(Mensagem mensage);
	/*! Imprime a lista de mensagens enviadas em um canal , com o conteudo das mensagens, a hora/data do seu envio, e o nome do usuário que a enviou
				@param usuarios vetor de usuário cadastrados no sistema
				@return Uma string contendo todas as mensagens enviadas em um canal
		*/
	string listm(vector <Usuario> &usuarios);
	/*! Envia a mensagem de um usuário dentro de um canal, de modo a adicionar o conteudo, a hora/data , e o usuário que a enviou dentro de um vetor de mensagens daquele canal
				@param mensagem uma string contendo a mensagem enviada por um usuário
				@param id o id do usuário que enviou a mensagem
		*/
	void sendm(string mensagem, int id);
};

#endif
