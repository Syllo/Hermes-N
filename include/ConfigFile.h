#ifndef __CONFIGFILE_H__
#define __CONFIGFILE_H__

#include <vector>
#include <string>

#include "Contact.h"

class ConfigFile
{
	private:
		const char *m_name;
	
	public:
		ConfigFile(const char *name);
		~ConfigFile();
		
		/* Lecture */
		
		/* Lire et stocker le contenu du fichier de config dans le vector contacts */
		bool Read(std::vector<Contact*>& contacts);

		/* Ecriture */
		
		/* Ajouter un contact dans le fichier de config avec comme attribut une adresse ou un nom */
		bool AddContact(std::string name, std::string str); // str : adresse ou nom
		
		/* Supprimer un contact du fichier de config */
		bool RemoveContact(std::string name);
		
		/* Ajouter un nom à un contact (ex AddName("Isaac", "Raphael") : Isaac : Benoit, Jerome, Raphael) */
		bool AddName(std::string contact, std::string name);
		
		/* Supprimer un nom d'un contact */
		bool RemoveName(std::string contact, std::string name);
		
		/* Définir l'adresse ou le nom associé à un contact (ex SetAddress("Maxime", "0.0.0.0") : Maxime : 0.0.0.0) */
		bool SetAddress(std::string name, std::string address); // adresse ou nom
};

#endif
