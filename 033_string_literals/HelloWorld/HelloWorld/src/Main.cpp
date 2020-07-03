#include <iostream>
#include <string>

#include <stdlib.h>

#define LOG(msg) std::cout << msg <<std::endl


int main()
{
	// string literal with length 7 (with NULL)
	"Cherno";

	// const char array
	// can only be changed later without "const"
	const char name[7] = "Cherno";
	// const char pointer
	const char* name2 = "Cherno";
	
	const char* name3 = u8"Cherno";
	// white character
	const wchar_t* name4 = L"Cherno";
	const char16_t* name5 = u"Cherno";
	const char32_t* name6 = U"Cherno";

	using namespace std::string_literals;

	// s after string literal allows another string to be added to its end
	std::string name7 = "Cherno"s + " hello";
	std::u32string name8 = U"Cherno"s + U" hello";

	//                    <- stands for raw
	const char* example = R"(STUFF1
	Line2
	Lin3)";

	std::cin.get();
}

/*
 * string literals are always in read only memory
 */
