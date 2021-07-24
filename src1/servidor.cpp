#include "../include/sistema.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include "../include/servidor.h"
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