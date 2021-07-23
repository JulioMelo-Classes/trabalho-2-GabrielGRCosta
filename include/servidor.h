#ifndef SERVIDOR_H
#define SERVIDOR_H
#include <string>
#include <vector>
using namespace std;

class Servidor{
	int usuarioDonoId;	
	string nome;
	string descricao;
	string codigoConvite;
	vector <string> CanaisTexto;
	vector <int> participantesIDs; 

};

#endif
