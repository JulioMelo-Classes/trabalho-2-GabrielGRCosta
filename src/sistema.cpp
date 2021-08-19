#include "../include/sistema.h"
#include <iostream>
#include <sstream>
#include <algorithm>

#include "../include/usuario.h" 
#include "../include/mensagem.h"
#include "../include/canaltexto.h"
//não precisa includir fazendo ../include/ se vc usar cmake o comando include_directories permite você incluir os 
//arquivos "como se" você estivesse no mesmo diretório dos .h, assim fazendo apenas #include "arquivo.h" daria certo

#include <string.h>
#include <string>
using namespace std;

/* COMANDOS */
string Sistema::quit() {
  return "Saindo...";
}

void Sistema::adduser(Usuario a){
	a.set_id(usuarios.size());
  	usuarios.push_back(a);
}

std::vector <Usuario> Sistema::get_usuarios(){
	return usuarios;
}

int Sistema::treatment(string a, string b, string c){
	if(a == "" || b == " " || c == ""){
		return 1;
	}
	return 0;
}

string Sistema::create_user (const string email, const string senha, const string nome) {
	Sistema s;
	if(s.treatment(email,senha,nome) == 1){
		return "Criação de usuário invalida";
	}
	Usuario user(nome,email,senha);
	for(auto &u : usuarios){
		if( u.get_email() == email ){
			return "Usuário já existe";
		} 
	}
  adduser(user);
  return "Usuário criado";
}


string Sistema::login(const string email, const string senha) {
	string x;
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

string Sistema::set_server_desc(int id, const string nome, const string descricao) {
	for(auto &l : servidores){
		if(l.get_nameserver() == nome && l.get_donoid() == id){
			l.set_descri(descricao);
			return "Descrição modificada no servidor " + nome;
		}
		if(l.get_nameserver() == nome && l.get_donoid() != id){
			return "Você não pode alterar a descrição de um servidor que não foi criado por você";
		}
	}
	return "Não existe o servidor " + nome;
}

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
		if (servidores.begin()+count != servidores.end()-1){
			stream<<endl;
		}
		count++;
	}	
	return stream.str();
}

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

/*
A2.7 0,8
É possível entrar mais de uma vez no mesmo servidor, nome do usuário fica duplicado 20% a menos
*/
string Sistema::enter_server(int id, const string nome, const string codigo) {
	if (usuariosLogados.count(id) == 0) {
		return "Usuario não está logado";
	}
	for(auto &b : servidores){
		if(b.get_nameserver() == nome && b.get_convite() == ""){
			b.addpartids(id); //antes de fazer isso vc poderia verificar se o usuário já está no servidor, ou fazer a verificação dentro de b.
			usuariosLogados[id].first = nome;
			return "Entrou no servidor com sucesso";
		}
		else if(b.get_nameserver() == nome && b.get_convite() != ""){
			if(b.get_convite() == codigo || b.get_donoid() == id){
				b.addpartids(id);
				usuariosLogados[id].first = nome;
				return "Entrou no servidor com sucesso";
			}
			return "Servidor requer código de convite";
		}
	}
  return "Servidor Não foi encontrado";
}

/*
A2.8 0,9
Leave-server de usuário não participante não dá erro 10% a menos
*/
string Sistema::leave_server(int id, const string nome) {
	if (usuariosLogados.count(id) == 0) {
		return "Usuario não está logado";
	}
	for(auto &w : servidores){
		if(w.get_nameserver() == nome){ //quando um usuário que não está no servidor faz leave-server id nome-servidor, esse método entra aqui mesmo que o usuário não participe. Vou tirar 10%.
			w.rmpartids(id);
			return "Saindo do servidor " + nome;
		}
		if(w.checkidlist(id) == 0){
			return "Você não está no servidor " + nome;
		}
	}
  return "Você não está em qualquer servidor";
}

/*
A2.9 ok
*/
string Sistema::list_participants(int id) {
	if (usuariosLogados.count(id) == 0) {
		return "Usuario não está logado";
	}
	for(auto &q : servidores){
		if(usuariosLogados[id].first == q.get_nameserver()){
			return q.searchlistid(get_usuarios());
		}
	}
  return "Não há pessoas no servidor procurado";
}

/*
B1.1 ok
*/
string Sistema::list_channels(int id) {
	if(usuariosLogados.count(id) == 0) {
		return "Usuario não está logado";
	}
	for(auto &v : servidores){
		if(usuariosLogados[id].first == v.get_nameserver()){
			return v.searchchanels();
		}
	}
  return "Não existe canais no servidor";
}

/*
B1.2 ok
*/
string Sistema::create_channel(int id, const string nome) {			
  if(usuariosLogados.count(id) == 0){
		return "Usuario não está logado";
    }
  else if(usuariosLogados[id].first == ""){
		return "Usuário não está em um servidor";
	}
  CanalTexto Canal;
  Canal.set_namechanel(nome);	
  for(auto &w : servidores){
	if(w.checknameCH(nome) == 1)
		return "Canal com esse nome já existe";
   }
  for(int v=0; v<servidores.size(); v++){
	if(servidores[v].get_nameserver() == usuariosLogados[id].first ) 
		servidores[v].addChanels(Canal);
		return "Foi criado o canal " + nome;	
  }
  return "Usuário não está em nenhum servidor registrado no sistema  ";
}

/*
B1.3 ok
*/
string Sistema::enter_channel(int id, const string nome) {
  	string usu;	
  	if(usuariosLogados.count(id) == 0) {
		return "Usuario não está logado";
  	}
	if(nome == "") {
		return "Canal Não existe";
  	}
  	Servidor save;
  	for(auto &j :usuarios){
		if(j.get_id() == id)
			usu = j.get_email();
  	}
	if(usuariosLogados[id].second == nome){
	   return "Usuário ja está no canal";
	}
  	for(auto &k : servidores){
  		if(k.checknameCH(nome) == 1 && k.checkidlist(id) == 1){
	    	usuariosLogados[id].second = nome;
			return "Usuário " + usu, "entrou no canal " +nome;	  
		}
		else if(k.checkidlist(id) == 0){
			return "Usuário não está no servidor";
		}
  }	
  return "O canal não existe";
}

/*
B1.4 ok
*/
string Sistema::leave_channel(int id) {
  string usu;
  string nem;
  for(int k=0; k<usuarios.size(); k++){
	if(usuarios[k].get_id() == id){
	   usu = usuarios[k].get_email();
	}
  }	
  if(usuariosLogados.count(id) == 0){
	return "Usuario não está logado";
  }
  else if(usuariosLogados[id].second == ""){
	return "Usuário não está em nenhum canal";
  }
  else if(usuariosLogados[id].second != ""){
	nem = usuariosLogados[id].second;
	usuariosLogados[id].second = "";
	return "Usuário" + usu, "saiu do canal " + nem;  
  }
  return "O canal que o Usuário quer sair não existe";	
}

/*
B2.1 ok
*/
string Sistema::send_message(int id, const string mensagem) {
  if(usuariosLogados.count(id) == 0){
	return "Usuário não está logado";
  }
  if(usuariosLogados[id].first == ""){
	return "Usuário não está em nenhum servidor";
  }
  if(usuariosLogados[id].second == ""){
	return "Usuário não está em nenhum canal para enviar mensagem";
  }
  else{
    for(int i=0; i<servidores.size(); i++){
		if(usuariosLogados[id].first == servidores[i].get_nameserver()){
			servidores[i].requestsendm(usuariosLogados[id].second, mensagem , id);
			return "Mensagem enviada";	
		}
	}
	return "Usuário não está em um servidor registrado no sistema";	  
  }	
}

/*
B2.2 ok
*/
string Sistema::list_messages(int id) {
  string nomecanal;
  if(usuariosLogados.count(id) == 0) {
	return "Usuário não está logado";
  }
  else if(usuariosLogados[id].second == ""){
	return "Usuário não está visualizando nenhum canal";
  }
  else{
	  for(int l=0; l<servidores.size(); l++){ //erro de indentação!
		  if(usuariosLogados[id].first == servidores[l].get_nameserver()){
			nomecanal = usuariosLogados[id].second;
			return servidores[l].requestlistm(usuarios,nomecanal);
		  }
	  }
	return "Usuário não está em nenhum servidor registrado no sistema";
  }	
}



/* IMPLEMENTAR MÉTODOS PARA OS COMANDOS RESTANTES */
