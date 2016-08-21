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

