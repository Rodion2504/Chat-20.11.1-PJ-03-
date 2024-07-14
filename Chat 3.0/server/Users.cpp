#include"Users.h"



Users::Users() = default;
Users::Users(const std::string& name, const std::string& login, const std::string& password)
	: _name(name), _login(login), _password(password) {};
Users::~Users() = default;

std::string Users::getName() const { return _name; }
std::string Users::getLogin() const { return _login; }
std::string Users::getPassword() const { return _password; }
void Users::setName(const std::string& name) { _name = name; }
void Users::setPassword(const std::string& pass) { _password = pass; }