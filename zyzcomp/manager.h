#ifndef _MANAGER_H_
#define _MANAGER_H_

#include<iostream>
#include<vector>
#include"Staff.h"

using namespace std;

class Manager
{
public:
	vector<Staff> v;//容器，包含员工类的全部属性
	void Display();//查看
	void Change(int juri);//修改
	void Delete(int juri);//删除
	void Add(int juri);//新增

};
#endif