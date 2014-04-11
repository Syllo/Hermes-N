#include <iostream>
#include <vector>

#include "ConfigFile.h"
#include "Contact.h"

using namespace std;

int main(int argc, char *argv[])
{	
	ConfigFile *cfg = new ConfigFile("config.cfg");
	vector<Contact*> contacts;
	
	if(!cfg->Read(contacts))
	{
		return 1;
	}
	
	for(unsigned int i = 0; i < contacts.size(); i++)
	{
		contacts.at(i)->ShowInfo();
		if(i != contacts.size() - 1)
			cout << endl;
	}
	
	cout << "\nAdresse de Benoit que possede Isaac : " << contacts.back()->FindContactAddress("Benoit") << endl;
	
	delete cfg;
	
	return 0;
}
