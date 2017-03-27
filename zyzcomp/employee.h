#ifndef _EMPLOYEE_
#define _EMPLOYEE_
#include <string.h>
class Employee
{
public:
	Employee();
	Employee(int no,char *name,int passwd,int type);
	int m_no;//个人编号
	char m_name[20];
	int m_passwd;
	int m_type;
};
#endif
