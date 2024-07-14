#pragma once
#include<vector>
#include<map>
#include<cassert>
#include"File.h"
#include"Network.h"

class Chat
{
	std::vector <Messages> _chat_message;
	std::vector <Messages> _chat_message_all;
	std::vector<Users>_data_users;
	
public:
	Chat();
	~Chat();

	void ReadFiles();
	void WriteFiles();
	std::string signUp(int connection);
	std::string entrance(int connection);
	void abonentList(int connection, const std::string &login_from);
	bool correctInputAbonent(int connection, const std::string& login_to);
	void messageInputAll(int connection, const std::string& login_from);
	void messageInputFromTo(int connection, const std::string& login_from);
	void messageReadPersonal(int connection, const std::string& login_from);
	void messageReadAll(int connection);
	void messageWriteRead(int connection, const std::string& login_from);
	Users& operator[](size_t index);
};