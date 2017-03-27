#ifndef __MANAGER_
#define __MANAGER_
#include<iostream>
#include<vector>
#include"employee.h"
using namespace std;
class Manager
{
public:
	vector<Employee> v;
	void Display();
	void Change(){}
	void Delete(){}
	void Add(){}

};
#endif
