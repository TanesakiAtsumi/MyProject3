#include"manager.h"
void Manager::Display()
{
	vector<Employee>::iterator i = v.begin();
	while(i != v.end())
	{
		cout<<i->m_name<<" "<<i->m_passwd<<" "<<i->m_type<<endl;
		i++;
	}
};
