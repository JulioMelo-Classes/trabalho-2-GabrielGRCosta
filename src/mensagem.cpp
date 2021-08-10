#include "../include/mensagem.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <string.h>
#include <ctime>
using namespace std;

Mensagem::Mensagem(int enviadaPor,string conteudo){
    this->enviadaPor = enviadaPor;
    this->conteudo = conteudo;
    stringstream stream;
    time_t t = time(0);  
    tm* now = localtime(&t);
    stream << "<" << now->tm_mday  << '/' 
         << (now->tm_mon + 1) << '/'
         <<  (now->tm_year + 1900)
         << " - "
				 << now->tm_hour << ":"  
				 << now->tm_min << ">";
    this->dataHora = stream.str();             
}

string Mensagem::get_datahora(){
    return dataHora;
}

string Mensagem::get_conteudo(){
    return conteudo;
}

int Mensagem::get_enviadaPor(){
    return enviadaPor;
}

string Mensagem::printm(string m){
    stringstream GGEZ;
	GGEZ<< m << get_datahora() << ": " <<get_conteudo() ;
	return GGEZ.str();
}

