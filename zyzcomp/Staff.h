#ifndef _STAFF_H_
#define _STAFF_H_

#include <algorithm>
#include <string.h>
class Staff//员工类
{
public:
	Staff();
	Staff(int no,char *name,int passwd,int type,int salary);
	int m_no;//个人编号
	char m_name[50];//姓名
	int m_passwd;//登陆密码
	int m_type;//职位
	int m_salary;//工资
	bool operator < (const Staff& rhs)const//重载<操作符用于排序
	{
		return m_no < rhs.m_no;
	}

};
#endif