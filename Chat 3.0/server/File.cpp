#include"File.h"


File::File() {};
File::~File()=default;

std::vector<Users> File::userFileRead()
{
	std::vector<Users> _user;
	std::fstream user_file = std::fstream("users.txt", std::ios::in | std::ios::out);	
	
	if (user_file) 
	{
		user_file.seekg(0, std::ios_base::beg);

		while (true)
		{
			Users user;
			user_file >> user;
			if (user_file.eof()) 
			{ 
				break; 
			}
			_user.push_back(user);
		}

		return _user;		
	}

	else
	{
		//std::cout << "Could not open file users.txt !" << '\n';
		return _user;
	}
}

std::vector<Messages> File::messageFileRead()
{
	std::vector<Messages> _message;
	std::fstream message_file = std::fstream("message.txt", std::ios::in | std::ios::out);

	if (message_file)
	{		
		message_file.seekg(0, std::ios_base::beg);

		while (true)
		{
			Messages message;
			message_file >> message;
			if (message_file.eof())
			{
				break;
			}
			_message.push_back(message);
		}		
		return _message;
	}

	else
	{
		//std::cout << "Could not open file users.txt !" << '\n';
		return _message;
	}
}

std::vector<Messages> File::messageFileReadAll()
{
	std::vector<Messages> _message;
	std::fstream message_file = std::fstream("messageAll.txt", std::ios::in | std::ios::out);

	if (message_file)
	{		
		message_file.seekg(0, std::ios_base::beg);

		while (true)
		{
			Messages message;
			message_file >> message;
			if (message_file.eof())
			{
				break;
			}
			_message.push_back(message);
		}

		return _message;
	}

	else
	{
		//std::cout << "Could not open file users.txt !" << '\n';
		return _message;
	}
}

void File::userFileWrite(std::vector<Users> _user)
{
	std::fstream user_file = std::fstream("users.txt", std::ios::in | std::ios::out | std::ios::trunc);		

	if (user_file) 
	{		
		for (auto& user : _user) 
		{
			user_file << user << std::endl;
		}			
	}

	else
	{
		std::cout << "Сбой при записи в файл!" << std::endl;
	}
}

void File::messageFileWrite(std::vector<Messages> _message)
{
	std::fstream message_file = std::fstream("message.txt", std::ios::in | std::ios::out | std::ios::trunc);

	
	if (message_file)
	{		
		for (auto& message : _message)
		{
			message_file << message << std::endl;
		}
	}

	else
	{
		std::cout << "Сбой при записи в файл!" << std::endl;
	}
}

void File::messageFileWriteAll(std::vector<Messages> _message)
{
	std::fstream message_file = std::fstream("messageAll.txt", std::ios::in | std::ios::out | std::ios::trunc);

	
	if (message_file)
	{		
		for (auto& message : _message)
		{
			message_file << message << std::endl;
		}
	}

	else
	{
		std::cout << "Сбой при записи в файл!" << std::endl;
	}
}

std::istream& operator >>(std::istream& is, Users& user)
{
	is >> user._name;
	is >> user._login;
	is >> user._password;
	return is;
}

std::ostream& operator <<(std::ostream& os, Users& user)
{
	os << user._name;
	os << ' ';
	os << user._login;
	os << ' ';
	os << user._password;
	return os;
}

std::istream& operator >>(std::istream& is, Messages& message)
{	
	is >> message._from;
	is >> message._to;
	std::getline(is, message._text);
	return is;
}

std::ostream& operator <<(std::ostream& os, Messages& message)
{	
	os << message._from;
	os << ' ';
	os << message._to;
	os << ' ';
	os << message._text;
	
	return os;
}

