#include"Message.h"

Messages::Messages() = default;
Messages::Messages(const std::string& from, const std::string& to, const std::string& text) : _from(from), _to(to), _text(text) {};
Messages::~Messages() = default;

std::string Messages::getFrom() const { return _from; }
std::string Messages::getTo() const { return _to; }
std::string Messages::getText() const { return _text; }