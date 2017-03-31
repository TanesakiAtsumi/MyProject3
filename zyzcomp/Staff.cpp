#include"Staff.h"

Staff::Staff(int no,char *name,int passwd,int type,int salary)
{
	this->m_no = no;
	strcpy (this->m_name, name);
	this->m_passwd = passwd;
	this->m_type = type;
	this->m_salary = salary;
}

