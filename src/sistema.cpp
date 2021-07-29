#include "../include/sistema.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include "../include/usuario.h"
#include <string.h>
#include <string>
using namespace std;

/* COMANDOS */
string Sistema::quit() {
  return "Saindo...";
}
/*
como o unico lugar onde vc vai precisar adicionar usuarios é em create_user, esse método é desnecessário*/
void Sistema::adduser(Usuario a){
	usuarios.push_back(a);
	a.set_id(usuarios.size());
}

/*
A1.2 ok
*/
string Sistema::create_user (const string email, const string senha, const string nome) {
	Usuario user;
	user.set_name(nome);
	user.set_email(email);
	user.set_senha(senha);
	for(auto &u : usuarios){
		if( u.get_email() == email ){
			return "Usuário já existe";
		} 
	}
  adduser(user);
  return "Usuário criado";
}


/*
A1.3 ok
*/
string Sistema::login(const string email, const string senha) {
	string x;
	//for(int i=0; i<usuarios.size() ; i++){
		for(auto &u : usuarios){ 
			if( u.get_email() == email && u.get_senha() == senha && usuariosLogados.count(u.get_id())==0){
				x = email;
				usuariosLogados[u.get_id()] = make_pair("","");
				return "Logado como " +x;
			}
		}
		for(auto &h : usuarios){
			if(usuariosLogados.count(h.get_id())==1){
				return "Usuário já está logado";
			}	
		}	
  return "Senha ou usuário inválidos!";
}

/*
A2.1 ok
*/
string Sistema::disconnect(int id) {
	string m;
	for(auto &y : usuarios){
		if( usuariosLogados.count(id) != 0){
			usuariosLogados.erase(id);
			m = y.get_email();
			return "Desconectando usuário " +m;
		}
	}
  return "O usuário não está conectado";  
}

/*
A2.2 ok
*/
string Sistema::create_server(int id, const string nome) {
	Servidor server;
	server.set_nameserver(nome);
	for(auto &g : servidores){
		if(g.get_nameserver() == nome){
			return "Servidor com esse nome já existe";
		}
	}
	server.set_id(id);
	servidores.push_back(server);
  return "Servidor criado";
}

/*
A2.3 ok
*/
string Sistema::set_server_desc(int id, const string nome, const string descricao) {
	for(auto &l : servidores){
		if(l.get_nameserver() == nome && l.get_donoid() == id){
			l.set_descri(descricao);
			//"Comando precisa ser precedido de um id [" + to_string(id) + "]";
			return "Descrição modificada no servidor " + nome;
		}
		if(l.get_nameserver() == nome && l.get_donoid() != id){
			return "Você não pode alterar a descrição de um servidor que não foi criado por você";
		}
	}
	return "Não existe o servidor " + nome;
}

/*
A2.4 ok
*/
string Sistema::set_server_invite_code(int id, const string nome, const string codigo) {
	for(auto &t : servidores){
		if(t.get_donoid() == id && t.get_nameserver() == nome){
			t.set_convite(codigo);
			if(codigo != ""){
				return "Código de convite modificado do servidor " + nome;
			}
			else{
				return "Código de convite removido do servidor " + nome;
			}
		}
	}
	return "O usuário não é dono do servidor ou o servidor não existe";
}

/*
A2.5 ok
*/
string Sistema::list_servers(int id) {
	stringstream stream;
	for(auto &i : usuarios){
		if(i.get_id() != id ){
			return "Usuário não está cadastrado no sistema";
		}
	}
	if(usuariosLogados.count(id) == 0){
		return "Usuário não está logado";
	}
	int count = 0;
	for(auto &r : servidores){
		stream<<r.get_nameserver();
		if (servidores.begin()+count != servidores.end()-1) {
			stream<<endl;
		}
		count++;
	}	
	return stream.str();
}

/*
A2.6 ok
Faltou atualizar as informações relativas aos usuários da tabela usuarios logados
*/
string Sistema::remove_server(int id, const string nome) {
	string h;
	int count = 0;
	for(auto &q : servidores){
		if (usuariosLogados.count(id) == 0) {
			return "Usuario não está logado";
		}
		if(q.get_nameserver() == nome && q.get_donoid() == id){
			servidores.erase(servidores.begin()+count);
			return "Removido o servidor " +nome;
		}
		if(q.get_nameserver() == nome && q.get_donoid() != id){
			return "Você não é o dono do servidor " +nome;
		}
		++count;
	}
	return "Não foi encontrado o servidor " + nome;
}

string Sistema::enter_server(int id, const string nome, const string codigo) {
  return "enter_server NÃO IMPLEMENTADO";
}

string Sistema::leave_server(int id, const string nome) {
  return "leave_server NÃO IMPLEMENTADO";
}

string Sistema::list_participants(int id) {
  return "list_participants NÃO IMPLEMENTADO";
}

string Sistema::list_channels(int id) {
  return "list_channels NÃO IMPLEMENTADO";
}

string Sistema::create_channel(int id, const string nome) {
  return "create_channel NÃO IMPLEMENTADO";
}

string Sistema::enter_channel(int id, const string nome) {
  return "enter_channel NÃO IMPLEMENTADO";
}

string Sistema::leave_channel(int id) {
  return "leave_channel NÃO IMPLEMENTADO";
}

string Sistema::send_message(int id, const string mensagem) {
  return "send_message NÃO IMPLEMENTADO";
}

string Sistema::list_messages(int id) {
  return "list_messages NÃO IMPLEMENTADO";
}




/* IMPLEMENTAR MÉTODOS PARA OS COMANDOS RESTANTES */
