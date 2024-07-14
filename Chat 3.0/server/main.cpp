#include"Chat.h"
#include"File.h"

int main()
{
	
	std::string login;
	char choice_menu;
	std::string str;
	Chat chat;

	chat.ReadFiles();

	Network netConnect;
	auto connectNet = netConnect.connectServerOpen();
	std::cout << "CONNECTION:  " << connectNet << std::endl;
	if (connectNet == -1)
	{
		std::cout << "Сбой сети!" << std::endl;
		exit(-1);
	}
	
	do
	{
		str = netConnect.reseiveMessage(connectNet);
		
		if(strncmp("1", str.c_str(), 1) == 0) 
		{
			choice_menu = '1';
		}	
		if(strncmp("2", str.c_str(), 1) == 0) 
		{
			choice_menu = '2';
		}	
		if(strncmp("3", str.c_str(), 1) == 0) 
		{
			choice_menu = '3';
		}		
		
		if (choice_menu == '1')
		{
			login = chat.signUp(connectNet);
			
			if (login != "error")
			{
				chat.messageWriteRead(connectNet, login);
			}
		}
		if (choice_menu == '2')
		{
			auto loginIn = chat.entrance(connectNet);
			
			if (loginIn != "error")
			{
				chat.messageWriteRead(connectNet, loginIn);
			}
		}
	} while (choice_menu != '3');
	
	chat.WriteFiles();
	netConnect.connectClose(connectNet);

	return 0;
}


