#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_

#include <exception>
#include <string>

class Exception : public std::exception
{
public:
	Exception(std:: string what);
	~Exception() throw();
	virtual const char* what() const throw();
private:
	std::string _what;
};

#endif