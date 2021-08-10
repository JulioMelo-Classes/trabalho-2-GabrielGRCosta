#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>
#include <string>
using namespace std;

class Usuario{
	private:
		int id=0;//<! um inteiro representado o id de um usuário
		string nome;//<! uma string que representa o nome do usuário
		string email;//<! uma string que representa o email do usuário
		string senha;//<! uma string que representa a senha do usuário

	public:
		/*! Construtor padrão que serve para inicializar objetos de seu tipo de classe.
				@param email o email do usuário 
				@param senha a senha do usuário
				@param nome o nome do usuário 
		*/
		Usuario(string nome, string email , string senha);

		/*! retorna o nome de um usuário
				@return uma string contendo o nome do usuário
		*/
		string get_name();
		/*! retorna o email de um usuário
				@return uma string contendo o email do usuário
		*/
		string get_email();
		/*! retorna a senha de um usuário
				@return uma string contendo a senha do usuário
		*/
		string get_senha();
		/*! retorna o id de um usuário
				@return um inteiro contendo o id do usuário
		*/
		int get_id();
		/*! seta/defini o id de um usuário
				@param a id do usuário
				@return um inteiro representando o id do usuário
		*/
		void set_id(int a);


};

#endif
