#include <iostream>
#include <cctype>
#include <fstream>

#include "../include/ConfigFile.h"

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
	
	if(!contacts.empty())
		contacts.clear();
	
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
		if(isdigit(*str.c_str()) || str.compare("?") == 0) // adresse (ex : Benoit : 212.85.150.133)
		{
			contacts.back()->SetAddress(str);
		}
		else // liste de contacts (ex : Isaac : Benoit, Jerome)
		{
			int i;
				
			while(str.find(",") != std::string::npos)
			{
				str.erase(str.end() - 1); // suppression ","
				for(i = 0; i < (int)contacts.size(); i++)
				{
					if(contacts.at(i)->GetName().compare(str) == 0)
						break;
				}
				
				contacts.back()->AddContact(contacts.at(i));
				file >> str;
			}
			
			for(i = 0; i < (int)contacts.size(); i++)
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

bool ConfigFile::AddContact(string name, string str)
{
	ofstream file;
	
	file.open(m_name, ofstream::app);
	if(!file.is_open())
	{
		cout << "Erreur lors de l'ouverture du fichier." << endl;
		return false;
	}
	
	file << name << " : " << str;
	
	file.close();
	
	return true;
}

bool ConfigFile::RemoveContact(string name)
{
	ifstream oldfile;
	ofstream file;
	
	oldfile.open(m_name);
	if(!oldfile.is_open())
	{
		cout << "Erreur lors de l'ouverture du fichier." << endl;
		return false;
	}
	
	file.open("temp.cfg");
	if(!file.is_open())
	{
		cout << "Erreur lors de l'ouverture du fichier." << endl;
		return false;
	}
	
	string line;
	int size = name.size();
	
	while(getline(oldfile, line))
	{
		string sub = line.substr(0, size);
		if(sub.compare(name) != 0)
			file << line << endl;
	}
	
	oldfile.close();
	file.close();
	
	rename("temp.cfg", "config.cfg");
	
	return true;
}

bool ConfigFile::AddName(std::string contact, std::string name)
{
	ifstream oldfile;
	ofstream file;
	
	oldfile.open(m_name);
	if(!oldfile.is_open())
	{
		cout << "Erreur lors de l'ouverture du fichier." << endl;
		return false;
	}
	
	file.open("temp.cfg");
	if(!file.is_open())
	{
		cout << "Erreur lors de l'ouverture du fichier." << endl;
		return false;
	}
	
	string line;
	int size = contact.size();
	
	while(getline(oldfile, line))
	{
		file << line;
		string sub = line.substr(0, size);
		if(sub.compare(contact) == 0)
		{
			file << ", " << name;
		}
		file << endl;
	}
	
	oldfile.close();
	file.close();
	
	rename("temp.cfg", "config.cfg");
	
	return true;
}

bool ConfigFile::RemoveName(std::string contact, std::string name)
{
	ifstream oldfile;
	ofstream file;
	
	oldfile.open(m_name);
	if(!oldfile.is_open())
	{
		cout << "Erreur lors de l'ouverture du fichier." << endl;
		return false;
	}
	
	file.open("temp.cfg");
	if(!file.is_open())
	{
		cout << "Erreur lors de l'ouverture du fichier." << endl;
		return false;
	}
	
	string line;
	int size = contact.size();
	
	while(getline(oldfile, line))
	{
		string sub = line.substr(0, size);
		if(sub.compare(contact) == 0)
		{
			unsigned int pos = line.find(name);
			if(pos != string::npos)
			{
				if(line.substr(pos+name.size(), 1).compare(",") == 0)
					line.replace(pos, name.size()+2, "");
				else if(line.substr(pos-2, 1).compare(",") == 0)
					line.replace(pos-2, name.size()+2, "");
			}
		}

		file << line << endl;
	}
	
	oldfile.close();
	file.close();
	
	rename("temp.cfg", "config.cfg");
	
	return true;
}

bool ConfigFile::SetAddress(std::string name, std::string address)
{
	ifstream oldfile;
	ofstream file;
	
	oldfile.open(m_name);
	if(!oldfile.is_open())
	{
		cout << "Erreur lors de l'ouverture du fichier." << endl;
		return false;
	}
	
	file.open("temp.cfg");
	if(!file.is_open())
	{
		cout << "Erreur lors de l'ouverture du fichier." << endl;
		return false;
	}
	
	string line;
	int size = name.size();
	
	while(getline(oldfile, line))
	{
		string sub = line.substr(0, size);
		if(sub.compare(name) != 0)
		{
			file << line << endl;
		}
		else
		{
			file << name << " : " << address << endl;
		}
	}
	
	oldfile.close();
	file.close();
	
	rename("temp.cfg", "config.cfg");
	
	return true;
}
