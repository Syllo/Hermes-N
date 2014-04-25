#include <iostream>

#include "../include/Contact.h"

Contact::Contact(std::string name):
m_name(name)
{
}

Contact::Contact(std::string name, std::string address):
m_name(name),
m_address(address)
{
}

Contact::~Contact()
{
}

void Contact::SetAddress(std::string address)
{
	m_address = address;
}

void Contact::AddContact(Contact *contact)
{
	m_contacts.push_back(contact);
}

std::string Contact::FindContactAddress(const std::string name)
{
	for(int i = 0; i < (int)m_contacts.size(); i++)
	{
		if(m_contacts.at(i)->GetName().compare(name) == 0)
			return m_contacts.at(i)->GetAddress();
	}
	
	return "";
}

std::string Contact::GetName()
{
	return m_name;
}

std::string Contact::GetAddress()
{
	return m_address;
}

void Contact::ShowInfo()
{
	std::cout << "Nom : " << m_name << std::endl;
	if(!m_address.empty())
		std::cout << "Adresse : " << m_address << std::endl;
	
	if(m_contacts.size() > 0)
		std::cout << "Liste : " << std::endl;
	for(int i = 0; i < (int)m_contacts.size(); i++)
	{
		std::cout << m_contacts.at(i)->GetName() << std::endl;
	}
}
