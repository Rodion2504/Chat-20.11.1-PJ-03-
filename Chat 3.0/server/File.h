#pragma once
#include <fstream>
#include<vector>
#include<string>
#include<filesystem>
#include"Message.h"


class File {
	
public:
	File();
	~File();
	std::vector<Users> userFileRead();
	std::vector<Messages> messageFileRead();
	std::vector<Messages> messageFileReadAll();
	void userFileWrite(std::vector<Users> _user);	
	void messageFileWrite(std::vector<Messages> _message);
	void messageFileWriteAll(std::vector<Messages> _message);	
};

