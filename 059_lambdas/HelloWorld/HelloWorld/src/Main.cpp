#include <iostream>
#include <vector>
#include <functional>

#define LOG(msg) std::cout << msg <<std::endl


//                                           <- function pointer
void ForEach(const std::vector<int>& values, const std::function<void(int)>& func)
{
	for (int value : values)
		func(value);
}


int main()
{
	std::vector<int> values = { 1, 2, 3, 4, 5, 6, 7 };
	// return first match
	//                                                                           <- vector of integers
	auto iterator = std::find_if(values.begin(), values.end(), [](int value) {return value > 3; });
	//         <- gives difference between beginning and required index
	LOG(values[iterator - values.begin()]);
	// same as
	LOG(*iterator);
	
	// lambda
	//       <- capture group (can be = -> everything gets parsed by copy or & -> everything gets parsed by reference)
	//                                                     <- allows captured variables to be changes from within the lambda
	const std::function<void(int)> lambda = [=](int value) mutable { LOG(value); };
	
	ForEach(values, [](int value) { LOG(value); });

	std::cin.get();
}

/*
 * lambdas aren't symbols
 * when a function pointer is necessary, a lambda can be used instead
 */
