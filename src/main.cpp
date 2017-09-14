#include "kernel/Kernel.hpp"

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	cout << "Bootloader: launching moose..." << endl;
	Moose::Kernel::kmain();
}
