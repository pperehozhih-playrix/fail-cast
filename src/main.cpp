
#include <iostream>

bool Foo() {
	return false;
}

int main() {
	std::string out;
	out = Foo();
	std::cout << out << std::endl;
	return 0;
}
