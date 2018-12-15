#pragma once
#include <string>
#include <iostream>

class Employee
{
public:
    std::string name, position;
	unsigned int age;
    
	Employee(const std::string &name, const std::string & position, unsigned int age);
    Employee(){};
	friend std::ostream& operator<<(std::ostream& out, const Employee& emp);
};

