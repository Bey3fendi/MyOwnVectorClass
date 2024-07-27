
#include "vector_class.h"
#include <vector>
#include <string>

int main() {

	VectorClass<std::string> vec{};

	vec.push_back("a");
	vec.push_back("b");
	vec.push_back("c");
	vec.push_back("d");
	vec.push_back("e");
	





	vec.print();
	size_t size = vec.size();
	size_t capacity = vec.getcapacity();
	std::string value_ = vec.get(4);
	std::cout << "value: " << value_ << " " << "size: " << size << " " << "capacity: " << capacity << std::endl;

	vec.pop();
	vec.pop();
	size_t size_ = vec.size();
	size_t capacity_ = vec.getcapacity();
	std::string value_2 = vec.get(4);
	std::cout << "value: " << value_2 << " " << "size: " << size_ << " " << "capacity: " << capacity_ << std::endl;
	

	return 0;
}