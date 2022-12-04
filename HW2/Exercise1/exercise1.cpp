// exercise1.cpp
// James Wu
// MTH9815 HW2 EX1

#include <boost/interprocess/managed_shared_memory.hpp>
#include <iostream>

using namespace boost::interprocess;

// shared information between programs
void testProgram1() {
	managed_shared_memory managedSharedMemory(open_only, "testSharedMemory");
	std::pair<double*, std::size_t> _pair = managedSharedMemory.find<double>("testObject");
	if (_pair.first) {
		*_pair.first = 3.14159;
		std::cout << "\nProgram 1 is called.\n";

	}
}

void testProgram2() {
	managed_shared_memory managedSharedMemory(open_only, "testSharedMemory");
	std::pair<double*, std::size_t> _pair = managedSharedMemory.find<double>("testObject");
	if (_pair.first) {
		*_pair.first = 2.71828;
		std::cout << "\nProgram 2 is called.\n";

	}
}

int main() {
	// testing the program
	// remove if any duplicates
	shared_memory_object::remove("testSharedMemory");

	// create memory and target varibale
	managed_shared_memory managedSharedMemory(open_or_create, "testSharedMemory", 65536);
	double* data = managedSharedMemory.construct<double>("testObject")(1.414);
	std::cout << "Original data: " << *data << std::endl;


	testProgram1();
	std::cout << "After calling program 1:\n";
	std::cout << "The vlaue is now " << *data << std::endl;

	testProgram2();
	std::cout << *data << std::endl;
	std::cout << "After calling program 2:\n";
	std::cout << "The vlaue is now " << *data << std::endl;
}
