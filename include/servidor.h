#ifndef SERVIDOR_H
#define SERVIDOR_H
#include <string>
#include <vector>
using namespace std;

class Servidor{
	private:
	int usuarioDonoId;	
	string nome;
	string descricao;
	string codigoConvite;
	vector <string> CanaisTexto;
	vector <int> participantesIDs; 

  public:
	
	void set_nameserver(string n);

	void set_id(int a);

	void set_descri(string b);

	void set_convite(string k);

	string get_nameserver();

	int get_donoid();


};


#endif
