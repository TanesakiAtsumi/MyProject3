#include"employee.h"
Employee::Employee(int no,char *name,int passwd,int type)
{
	this->m_no = no;
	strcpy (this->m_name, name);
	this->m_passwd = passwd;
	this->m_type = type;
};
