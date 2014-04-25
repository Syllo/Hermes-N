#include <iostream>
#include <vector>

#include "../include/ConfigFile.h"
#include "../include/Contact.h"

using namespace std;

int main(int argc, char *argv[])
{	
	ConfigFile *cfg = new ConfigFile("config.cfg");
	vector<Contact*> contacts;
	
	if(!cfg->Read(contacts))
	{
		return 1;
	}
		
	for(int i = 0; i < (int)contacts.size(); i++)
	{
		contacts.at(i)->ShowInfo();
		if(i != (int)contacts.size() - 1)
			cout << endl;
	}
	
	delete cfg;
	
	return 0;
}
