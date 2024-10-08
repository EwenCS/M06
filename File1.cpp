#include<iostream>
#include<string>
#include"IRClientTCP.h"
using namespace std;

int main()
{
	IRClientTCP client;
	client.SeConnecterAUnServeur("172.20.21.30",80);
	char requete[] = "GET /services/user/devices.xml HTTP/1.1\r\nHost: 172.20.21.30\r\nConnection: keep-alive\r\nAccept: */*\r\n\r\n";
	client.Envoyer(requete,  strlen(requete));
	char rep[1500];
	int nbOctets = client.Recevoir(rep,1500);
	string reponse = string(rep,nbOctets);
	nbOctets = client.Recevoir(rep,1500);
	reponse += string(rep,nbOctets);
	nbOctets = client.Recevoir(rep,1500);
	reponse += string(rep,nbOctets);
	nbOctets = client.Recevoir(rep,1500);
	reponse += string(rep,nbOctets);
	cout<< "NB octets : " <<nbOctets <<endl;
	//cout << "Reponse : " << reponse <<endl;
// cin.get();

	string xml=reponse;
	cout << xml<<endl;
//	 cin.get();
	bool trouve=true;
	int deb,fin=0;
	do
	{   deb=xml.find("<id>", fin);
		if(deb==-1)
		{
			trouve=false;
		}
		else
		{
			fin=xml.find("</id>", deb);
			deb+=4;//longueur balise <id>
			int longueur=fin-deb;
			cout<<xml.substr(deb,longueur)<<endl;
		}
	}while(trouve);
	cin.get();	cin.get();
	return 0;
}
