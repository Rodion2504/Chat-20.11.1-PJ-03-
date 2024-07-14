#pragma once
#include"Func.h"

class Users
{
	std::string _name;
	std::string _login;
	std::string _password;

public:

	Users();
	Users(const std::string& name, const std::string& login, const std::string& password);
	~Users();

	std::string getName() const;
	std::string getLogin() const;
	std::string getPassword() const;
	void setName(const std::string& name);
	void setPassword(const std::string& pass);
	friend std::istream &operator>>(std::istream &is, Users &user);
	friend std::ostream &operator<<(std::ostream &os, Users &user);

};