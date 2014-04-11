#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <string>
#include <vector>

class Contact
{
	private:
		std::string m_name; 
		std::string m_address;
		std::vector<Contact*> m_contacts;
		//std::vector<Contact*> m_friends; // liste d'amis ?
	
	public:
		Contact(std::string name);
		Contact(std::string name, std::string m_address);
		~Contact();
		
		void SetAddress(std::string address);
		void AddContact(Contact *contact);
		std::string FindContactAddress(const std::string name);
		
		std::string GetName();
		std::string GetAddress();
		void ShowInfo();
};

#endif
