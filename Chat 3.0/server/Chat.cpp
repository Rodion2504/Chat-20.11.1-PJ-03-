#include"Chat.h"

Chat::Chat() = default;
Chat::~Chat() = default;

std::string Chat::signUp(int connection)
{
	std::string name;
	std::string login;
	std::string password;

	Network netConnect;
	
	name = netConnect.reseiveMessage(connection);
	login = netConnect.reseiveMessage(connection);
	password = netConnect.reseiveMessage(connection);
	
	Users user(name, login, password);
	auto count = 0;
	if (_data_users.size())
	{
		for (auto& _data_user : _data_users)
		{
			if (login == _data_user.getLogin())
			{
				count++;
				netConnect.sendMessage(connection, "error");
				return "error";
			}
		}
		if (!count)
		{
			_data_users.push_back(user);
			netConnect.sendMessage(connection, "Поздравляем, вы успешно зарегистрированы.");
			return  user.getLogin();
		}
	}
	else
	{
		_data_users.push_back(user);
		netConnect.sendMessage(connection, "Поздравляем, вы успешно зарегистрированы.");
		return  user.getLogin();
	}
	return  user.getLogin();
}

std::string Chat::entrance(int connection)
{
	Network netConnect;
	auto count = 0;
	std::string login = netConnect.reseiveMessage(connection);
	std::string password = netConnect.reseiveMessage(connection);
	if (!_data_users.empty())
	{
		for (auto& _data_user : _data_users)
		{
			if (login == _data_user.getLogin() && password == _data_user.getPassword())
			{
				count++;
			}
		}
		if (count)
		{			
			netConnect.sendMessage(connection, "Вход выполнен успешно.");
			return login;
		}
		else
		{			
			netConnect.sendMessage(connection, "Такого логина/пароля нет.");
			return "error";
		}
	}
	else
	{		
		netConnect.sendMessage(connection, "Сначала зарегистрируйтесь.");
		return "error";
	}
}

void Chat::abonentList(int connection, const std::string &login_from)
{
	Network netConnect;
	std::string str;
	
	for (auto& _data_user : _data_users)
	{
		if (login_from != _data_user.getLogin())
		{			
			str = str + _data_user.getLogin() + "  /  ";			
		}
	}
	netConnect.sendMessage(connection, str);	
}

bool Chat::correctInputAbonent(int connection, const std::string& login_to)
{
	Network netConnect;
	for (auto& _data_user : _data_users)
	{
		if (login_to == _data_user.getLogin())
		{	
			netConnect.sendMessage(connection, "true");
			return true;
		}
	}
	netConnect.sendMessage(connection, "false");
	return false;
}

void Chat::messageInputAll(int connection, const std::string& login_from)
{
	Network netConnect;
	std::string text = netConnect.reseiveMessage(connection);
	_chat_message_all.push_back({ "всем", login_from, text });
}

void Chat::messageInputFromTo(int connection, const std::string& login_from) {
	std::string text;
	std::string login_to;
	Network netConnect;

	abonentList(connection, login_from);
	login_to = netConnect.reseiveMessage(connection);
	if (login_to == "всем")
	{
		messageInputAll(connection, login_from);
	}
	else
	{
		if (correctInputAbonent(connection, login_to))
		{
			text = netConnect.reseiveMessage(connection);
			_chat_message.push_back({ login_from, login_to, text });
		}		
	}
}

void Chat::messageReadPersonal(int connection, const std::string& login_from) 
{
	auto count = 0;
	std::string str;
	Network netConnect;
	if (_chat_message.size())
	{		
		//std::cout << "Личные сообщения:     " << std::endl;
		for (auto& message : _chat_message)
		{			
			if (login_from == message.getTo())
			{
				str = str + "От кого:     " + message.getFrom() + "     >>  " + message.getText() + '\n';
				count++;
			}
			
		}
		if (count) {netConnect.sendMessage(connection, str);}
		else { netConnect.sendMessage(connection, "error" );}
	}
	else
	{
		netConnect.sendMessage(connection, "error" );
	}
}

void Chat::messageReadAll(int connection)
{
	std::string str;
	Network netConnect;
	if (_chat_message_all.size())
	{
		//std::cout << "Сообщения из общего чата:     " << std::endl;		
		for (auto& message_all : _chat_message_all)
		{
			str = str + "От кого:  " + message_all.getTo()
			+"           >>  " + message_all.getText()+ '\n';			
		}
		netConnect.sendMessage(connection, str);
	}
	else
	{
		netConnect.sendMessage(connection, "error");		
	}
}

void Chat::messageWriteRead(int connection, const std::string& login_from)
{
	Network netConnect;
	char choice;
	std::string str;
	do
	{		
		str = netConnect.reseiveMessage(connection);
		std::cout << str; std::cout << std::endl;
		if(strncmp("1", str.c_str(), 1) == 0) 
		{
			choice = '1';
		}	
		if(strncmp("2", str.c_str(), 1) == 0) 
		{
			choice = '2';
		}	
		if(strncmp("3", str.c_str(), 1) == 0) 
		{
			choice = '3';
		}
		if(strncmp("4", str.c_str(), 1) == 0) 
		{
			choice = '4';
		}				
		
		switch (choice)
		{
		case '1':
			messageReadAll(connection);
			break;

		case '2':
			messageReadPersonal(connection, login_from);
			break;

		case '3':
			messageInputFromTo(connection, login_from);
			break;

		case '4':
			break;

		default:
			incorrectInputMenuMessage();
			break;
		}
	} while (choice != '4');

}

Users& Chat::operator[](size_t index)
{
	assert(index > 0 && index > _data_users.size());
	return _data_users[index];
}

void Chat::ReadFiles() 
{
	File file;
	_data_users = file.userFileRead();
	_chat_message = file.messageFileRead();
	_chat_message_all = file.messageFileReadAll();
}

void Chat::WriteFiles()
{
	File file;
	file.userFileWrite(_data_users);
	file.messageFileWrite(_chat_message);
	file.messageFileWriteAll(_chat_message_all);
}