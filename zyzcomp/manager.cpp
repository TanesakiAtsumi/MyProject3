#include"Manager.h"
#include<stdlib.h>
#include<unistd.h>

extern int mysql_to_v();
extern int v_to_mysql();
extern int remove_from_mysql(int no);
int countSalary(int jobtype);

void Manager::Display()//查看全部列表
{
	stable_sort(v.begin(), v.end(),less<Staff>());
	vector<Staff>::iterator i = v.begin();
	cout<<"职位代号：1,BOSS 2,经理 3,销售经理 4,技术员 5,销售员"<<endl;
	while(i != v.end())
	{
		cout<<"编号："<<i->m_no<<"  "<<"姓名："<<i->m_name<<"  "<<"职位代号："<<i->m_type<<"  "<<"工资："<<i->m_salary<<endl;
		i++;
	}
}

void Manager::Change(int juri)//修改的方法
{
	int num;
	int i;
	bool b = false;
	vector<Staff>::iterator iter = v.begin();
	cout<<"输入你要修改的员工的编号：";
	cin>>num;
	//选择修改的目标，按编号或者名字查找
	while(iter != v.end())
    {
		if(num == (*iter).m_no)
        {
			if(juri < (*iter).m_type-1 || juri == 1)
			{
				cout<<(*iter).m_type<<endl;
            	b = true;
				break;
			}
			else
			{
				cout<<"权限不足，请重试"<<endl;
				Change(juri);
			}
        }
		++iter;
    }
	if(b == true)
	{
		int loop = 0;
		do{
		system("clear");
		for(i = 0;i<5;i++)
			cout<<endl;
		cout<< "\t\t-------------------------------------------------------"<<endl;
		cout<<"\t\t\t\t"<<"1.修改编号 :"<<(*iter).m_no<<endl;
		cout<<"\t\t\t\t"<<"2.修改姓名 :"<<(*iter).m_name<<endl;
		cout<<"\t\t\t\t"<<"3.修改职位 :"<<(*iter).m_type<<endl;
		cout<<"\t\t\t\t"<<"4.修改月薪 :"<<(*iter).m_salary<<endl;
		cout<<"\t\t\t\t"<<"5.保存"<<endl;
		cout<<"\t\t\t\t"<<"6.不保存并退出"<<endl;
		cout<< "\t\t-------------------------------------------------------"<<endl;
		cout<<"注意：编号为固定值不可修改"<<endl;
		cout<<"输入数字选择操作：";
		cin>>num;
		switch(num)
		{
			case 1:
				cout<<"编号不可修改,正在返回"<<endl;
				sleep(1);
				loop = 1;
				break;
			case 2:
			{
				char newName[20];
				cout<<"修改名字:";
				cin>>newName;
				strcpy((*iter).m_name,newName);
				loop = 1;
				break;
			}
			case 3:
			{
				int newType;
				cout<<"修改职位:";
				cout<<"1,BOSS 2,经理 3,销售经理 4,技术员 5,销售员"<<endl;
				cout<<"输入职位的代号进行修改：";
				cin>>newType;
				(*iter).m_type = newType;
				loop = 1;
				break;
			}
			case 4://修改工资，按照职位决定如何计算
			{
				int newSala;
				newSala = countSalary((*iter).m_type);
				(*iter).m_salary = newSala;
				loop = 1;
				break;
			}
			case 5:
			{
				v_to_mysql();
				cout<<"保存成功"<<endl;
				loop = 0;
				sleep(1);
			}
			case 6:
				loop = 0;
				break;	
		}
		}while(loop == 1);	
	}
	else
	{
		cout<<"查无此人,请重试"<<endl;
		Change(juri);
	}
}

void Manager::Delete(int juri)//删除的方法
{
	bool b = false;
	int num;
	vector<Staff>::iterator iter = v.begin();
	cout<<"输入你要删除的目标编号:";
	cin>>num;
	while(iter != v.end())
    {
		if(num == (*iter).m_no && num != juri)
        {
			if(juri == (*iter).m_type-2 || juri == 1)
			{
				b = true;
				break;	
			}
			else
			{
				cout<<"权限不足，请重试"<<endl;
				Change(juri);
			}
        }
		++iter;
    }
	if(b == true)
	{
		//remove_from_mysql(num);
		//cout<<(*iter).m_no<<endl;
		v.erase(iter);
		v_to_mysql();
		cout<<"删除成功"<<endl;
	}
	else
	{
		cout<<"无法删除,请重试"<<endl;
		Delete(juri);
	}
}

void Manager::Add(int juri)//新增的方法
{
	int num =1;
	char name[50];
	int password;
	int type = 0;
	int salary;
	vector<Staff>::iterator iter = v.begin();
	while(iter != v.end())//生成编号
	{
		num++;
		iter++;
		if((*iter).m_no != num)
			break;
	}
	cout<<"开始新增人员"<<endl;
	cout<<"输入姓名:";
	cin>>name;
	cout<<"输入密码:";
	cin>>password;
	if(1 == juri)
	{
		cout<<"1,BOSS 2,经理 3,销售经理 4,技术员 5,销售员"<<endl;
		cout<<"输入职位代号:";
		cin>>type;
	}
	else if(3 >= juri && 1 < juri)
	{
		type = juri+2;
	}
	cout<<type<<endl;
	salary = countSalary(type);
	//将信息放入容器
	Staff tar(num,name,password,type,salary);
	v.push_back(tar);
	v_to_mysql();//将更新后的容器同步到数据库
}

int countSalary(int jobtype)
{
	int salary;
	int hour;
	int days;
	int sale;
	int award;
	if(jobtype <= 2)
	{
		cout<<"输入工资:";
		cin>>salary;
	}
	else if(jobtype == 3)
	{
		cout<<"输入底薪:";
		cin>>salary;
		cout<<"输入业绩（销售量）:";
		cin>>sale;
		cout<<"输入提成:";
		cin>>award;
		salary=salary+sale*award;
	}
	else if(jobtype == 4)
	{
			cout<<"输入时薪:";
			cin>>salary;
			cout<<"输入日工作时长:";
			cin>>hour;
			cout<<"输入每月工作天数:";
			cin>>days;
			salary = salary*hour*days;
	}
	else if(jobtype == 5)
	{
		cout<<"输入业绩（销售量）:";
		cin>>sale;
		cout<<"输入提成:";
		cin>>award;
		salary=2000+sale*award;
	}
	return salary;
}