#include "Employee.h"

Employee::Employee(const std::string &name, const std::string &position, unsigned int age)
{
	this->name = name;
	this->position = position;
	this->age = age;
}

std::ostream& operator<<(std::ostream& out, const Employee& emp) {
	out << "Employee name: " << emp.name << "\nEmployee position: " << emp.position << "\nEmployee age: " << emp.age << std::endl;
	return out;
}
