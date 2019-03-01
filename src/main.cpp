
#include <iostream>

bool Foo() {
	return false;
}

int main() {
	int* a = nullptr;
	*a = 123;
	std::string out;
	out = Foo();
	std::cout << out << std::endl;
	return 0;
}
