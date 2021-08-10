#include "../include/sistema.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include "../include/usuario.h"
#include <string>
#include <string.h>
using namespace std;

Usuario::Usuario(string nome, string email , string senha){
	this->nome = nome;
	this->email = email;
	this->senha = senha;
}

string Usuario::get_name(){
	return nome;
}

string Usuario::get_email(){
	return email;
}

string Usuario::get_senha(){
	return senha;
}

int Usuario::get_id(){
	return id;
}

void Usuario::set_id(int a){
	this->id=a;
}