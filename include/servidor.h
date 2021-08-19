#ifndef SERVIDOR_H
#define SERVIDOR_H
#include <string>
#include <vector>
#include "canaltexto.h"
using namespace std;

/*
CP2 ok
*/
class Servidor{
	private:
	int usuarioDonoId;//<! Id do dono do servidor	
	string nome;//<! o nome do servidor
	string descricao;//<! a descrição do servidor
	string codigoConvite;//<! o convite/senha para entrar no servidor
	vector <CanalTexto> CanaisTexto;//<! o vector de mensagens contendo os canais do servidor
	vector <int> participantesIDs; //<! o vector de inteiros contendo os ids dos participantes do servidor

  public:
	
	void set_nameserver(string n);
	/*! define o nome de um servidor
				@param uma string contendo o nome escolhido para o servidor
		*/

	void set_id(int a);
	/*! define em um servidor o id de seu dono
				@param um inteiro correspondente ao id do dono do servidor
		*/

	void set_descri(string b);
	/*! define a descrição de um servidor
				@param uma string contendo a descrição escolhida para o servidor
		*/

	void set_convite(string k);
	/*! define o codigo de convite para entrar em um servidor
				@param uma string contendo o codigo escolhido para participar de um servidor
		*/

	string get_nameserver();
	/*! retorna o nome de um servidor
				@return uma string contendo o nome do servidor
		*/

	int get_donoid();
	/*! retorna o id do dono do servidor
				@return um inteiro correspondente ao id do dono do servidor
		*/

	string get_convite();
	/*! retorna o codigo de convite para entrar em um servidor
				@return uma string contendo o codigo para participar de um servidor
		*/

	void addpartids(int id);
	/*! cadastra em um servidor o id de um de seus participantes
				@param um inteiro contendo o id de um dos participantes do servidor
		*/

	void rmpartids(int id);
	/*! remove de um servidor o id de um de seus participantes
				@param um inteiro contendo o id do participante a ser removido
		*/

	int checkidlist(int id);
	/*! confere se determinado id de um participante esta presente em um servidor
				@return 1 caso o id esteja presente
				@return 0 caso o id não esteja presente
		*/

	string searchlistid(vector<Usuario> usuarios);
	/*! retorna uma string contendo o nome de todos os participantes de um servidor
				@param um vetor do tipo Usuario contendo todos os usuarios cadastrados
				@return uma string contendo o nome dos participantes do servidor
		*/

	string searchchanels();
	/*! retorna uma string contendo o nome de todos canais de um servidor
				@return retorna uma string contendo o nome de todos canais de um servidor
		*/

	int checknameCH(string name);
	/*! confere se determinado canal faz parte de um servidor
				@param uma string contendo o nome de um possivel canal do servidor
				@return 1 se o canal estiver presente no servidor
				@return 0 se o canal não estiver presente no servidor
		*/
	void addChanels(CanalTexto Channel);
	/*! adiciona um canal a um servidor
				@param uma variavel do tipo canal texto contendo o nome de um canal e as suas mensagens
		*/
	string requestlistm(vector<Usuario> &usuarios,string canal);
	/*! Auxilia a função listm a imprimir as mensagens de um canal , passando o vetor de usuários cadastrados e o nome do canal  
				@param usuarios vetor de usuários cadastrados no sistema
				@param canal nome de um canal
				@return imprime a lista de mensagens caso o canal passado exista , senão imprime uma mensagem de erro 
		*/
	void requestsendm(string canal, string mensagem, int id);
	/*! Auxilia a função sendm a enviar as mensagens de um canal , adicionando as mensagens dentro do vetor de mensagens   
				@param canal nome do canal 
				@param mensagem conteudo da mensagem
				@param id id do usuário que enviou a mensagem
		*/
};


#endif
