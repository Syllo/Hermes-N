#include <iostream>
#include <fstream>
#include <cctype>

#include "ConfigFile.h"

using namespace std;

ConfigFile::ConfigFile(const char *name):
m_name(name)
{
}

ConfigFile::~ConfigFile()
{
}

bool ConfigFile::Read(vector<Contact*>& contacts)
{
	ifstream file;
	
	file.open(m_name);
	if(!file.is_open())
	{
		cout << "Erreur lors de l'ouverture du fichier." << endl;
		return false;
	}
	
	string str;
	
	while(file >> str)
	{
		contacts.push_back(new Contact(str)); // nom
		
		file >> str;
		if(str.compare(":") != 0)
		{
			cout << "Mauvais format du fichier config." << endl;
			file.close();
			return true;
		}
			
		file >> str;
		if(isdigit(*str.c_str()) || str.compare("?") == 0) // adresse (ex : Benoit : 212.85.150.133,0x20000000,1)
		{
			contacts.back()->SetAddress(str);
		}
		else // liste de contacts (ex : Isaac : Benoit, Jerome)
		{
			unsigned int i;
				
			while(str.find(",") != std::string::npos)
			{
				str.erase(str.end() - 1); // suppression ","
				for(i = 0; i < contacts.size(); i++)
				{
					if(contacts.at(i)->GetName().compare(str) == 0)
						break;
				}
				
				contacts.back()->AddContact(contacts.at(i));
				file >> str;
			}
			
			for(i = 0; i < contacts.size(); i++)
			{
				if(contacts.at(i)->GetName().compare(str) == 0)
					break;
			}
			
			contacts.back()->AddContact(contacts.at(i));
		}
	}
	
	file.close();
	
	return true;
}

bool ConfigFile::Write()
{
	ofstream file;
	
	file.open(m_name);
	if(!file.is_open())
	{
		cout << "Erreur lors de l'ouverture du fichier." << endl;
		return false;
	}
	
	/* ... */
	
	file.close();
	
	return true;
}
