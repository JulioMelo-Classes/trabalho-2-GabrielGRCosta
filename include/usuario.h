#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>
#include <string>

/*
CP1 classe usuário ok
*/
class Usuario{
	private:
		int id=0;
		std::string nome;
		std::string email;
		std::string senha;

	public:
		int contador=0;

		std::string get_name();

		std::string get_email();

		std::string get_senha();

		int get_id();

		void set_id(int a);

		void set_name(std::string name);

		void set_email(std::string email);

		void set_senha(std::string senha);

};

#endif
