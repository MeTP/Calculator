#include <string>

class Check
{
private:
	Check();
	~Check();
public:
	static bool DoCheck(const char elem, const std::string str);
	static bool IsNumber(char elem);
	static bool IsOperator(char elem);

};

