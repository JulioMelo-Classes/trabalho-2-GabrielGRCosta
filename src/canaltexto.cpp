#include <iostream>
#include <sstream>
#include <algorithm>
#include "../include/mensagem.h"
#include "../include/canaltexto.h"
#include "../include/usuario.h"
#include "../include/sistema.h"
#include <string>
#include <string.h>
using namespace std;


string CanalTexto::get_namechanel(){
    return nome;
}

void CanalTexto::set_namechanel(string name){
    nome = name;
}

void CanalTexto::addmensage(Mensagem mensage){
    mensagens.push_back(mensage);    
}

string CanalTexto::listm(vector <Usuario> &usuarios){
    string user;
    stringstream stream;
    for(int l=0; l<mensagens.size(); l++){ 
        for(auto &p : usuarios){
            if(p.get_id() == mensagens[l].get_enviadaPor()){
                user = p.get_name();
            }
        }   
        stream<<mensagens[l].printm(user);
	    if(mensagens.begin()+l != mensagens.end()-1){
		    stream<<endl;
	    }
    }
    return stream.str();
}

void CanalTexto::sendm(string mensagem, int id){
    Mensagem fair(id , mensagem);
    mensagens.push_back(fair);
}
