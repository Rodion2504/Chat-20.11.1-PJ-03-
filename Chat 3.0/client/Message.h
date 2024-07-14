#pragma once
#include"Users.h"

class Messages
{
	std::string _from;
	std::string _to;
	std::string _text;

public:
	Messages();
	Messages(const std::string& from, const std::string& to, const std::string& text);
	~Messages();

	std::string getFrom() const;
	std::string getTo() const;
	std::string getText() const;
	
};