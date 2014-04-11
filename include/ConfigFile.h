#ifndef __CONFIGFILE_H__
#define __CONFIGFILE_H__

#include <vector>

#include "Contact.h"

class ConfigFile
{
	private:
		const char *m_name;
	
	public:
		ConfigFile(const char *name);
		~ConfigFile();
		
		bool Read(std::vector<Contact*>& contacts);
		bool Write();
};

#endif
