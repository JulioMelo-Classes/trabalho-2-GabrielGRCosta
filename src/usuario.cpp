#include "../include/sistema.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include "../include/usuario.h"
#include <string>
#include <string.h>
using namespace std;


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

void Usuario::set_name(string name){
	nome=name;
}

void Usuario::set_email(string emaill){
	email=emaill;
}

void Usuario::set_senha(string senhaa){
	senha=senhaa;
}

void Usuario::set_id(int a){
	this->id=a;
}