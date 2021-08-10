#include "../include/sistema.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include "../include/servidor.h"
#include "../include/canaltexto.h"
#include <string>
#include <string.h>
using namespace std;

void Servidor::set_nameserver(string n){
	nome = n;
}

void Servidor::set_id(int a){
	usuarioDonoId = a;
}

void Servidor::set_descri(string b){
	descricao = b;
}


void Servidor::set_convite(string k){
	codigoConvite=k;
}

string Servidor::get_nameserver(){
	return nome;
}

int Servidor::get_donoid(){
	return usuarioDonoId;
}

string Servidor::get_convite(){
	return codigoConvite;
}

void Servidor::addpartids(int id){
	participantesIDs.push_back(id);
}

void Servidor::rmpartids(int id){
	int count=0;
	for(int i=0; i<participantesIDs.size(); i++){
		if(participantesIDs[i] == id){
			participantesIDs.erase(participantesIDs.begin()+count);
		}
		count++;
	}
}

int Servidor::checkidlist(int id){
	for(int i=0; i<participantesIDs.size(); i++){
		if(participantesIDs[i] == id)
			return 1;
	}
	return 0;		
}

string Servidor::searchlistid(vector<Usuario> usuarios){
	stringstream flaw;
	for(int a=0; a<participantesIDs.size() ; a++){
    for(int b = 0; b < usuarios.size(); b++){
      if(participantesIDs[a] == usuarios[b].get_id()){
        flaw<<usuarios[b].get_name();
				if (participantesIDs.begin()+a != participantesIDs.end()-1) {
				  flaw<<endl;
				}
      }
    }
  }
	return flaw.str();
}//construindo

string Servidor::searchchanels(){
	stringstream sharp;
	for(int i=0; i<CanaisTexto.size(); i++){
		sharp<<CanaisTexto[i].get_namechanel();
		if(CanaisTexto.begin()+i != CanaisTexto.end()-1){
			sharp<<endl;
		}
	}
	return sharp.str();
}

int Servidor::checknameCH(string name){
	for(int b=0; b<CanaisTexto.size(); b++){
		if(CanaisTexto[b].get_namechanel() == name){
			return 1;
		}
	}
	return 0;
}

void Servidor::addChanels(CanalTexto Channel){
	CanaisTexto.push_back(Channel);
}

string Servidor::requestlistm(vector<Usuario> & usuarios,string canal){
	for(auto &p : CanaisTexto){
		if(p.get_namechanel() == canal){
		  return p.listm(usuarios);
		}
	}
	return "Erro";
}

void Servidor::requestsendm(string canal, string mensagem, int id){
	for(auto &k : CanaisTexto){
		if(k.get_namechanel() == canal){
			 k.sendm(mensagem, id);
		}
	}
}