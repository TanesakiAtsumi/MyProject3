//create table employee(no int,name char(40),passwd int,type int)default charset = utf8;
//insert into employee values(1,'zyz',123,1),(2,'www',321,2);
#include<iostream>
#include<stdio.h>
#include <unistd.h>
#include"Staff.h"
#include"Manager.h"
//#include"login.h"
#include"UI.h"
using namespace std;

extern int mysql_to_v();
extern int v_to_mysql();
int Login();
Manager m;//声明类对象

int main()
{
	int juri = 0;//操作权限变量
	int menu;
	int quit = 0;
	int loop = 0;
	int count = 0;
	juri = Login();
	//juri 的值对应的权限：1,BOSS 2,经理 3,销售经理 4,技术员 5,销售员
	//mysql_to_v();//将全部数据放入容器待用
	do
	{
		UI();//显示菜单
		//选择功能
		cout<<"\t\t"<<"输入数字选择功能：";
		cin>>menu;
		if(menu > 0 && menu < 6)
		{
			switch(menu)
			{
				case 1://1,查询
					m.Display();//访问容器获得表单
					cout<<endl;
					cout<<"按任意键返回上级"<<endl;
					getchar();
					getchar();
					loop = 1;
					break;
				case 2://2,新增
					if(0 < juri && juri <= 3)
					{
						m.Add(juri);
					}
					else
					{
						cout<<"您不是管理层用户，无法添加新员工的注册信息"<<endl;
						sleep(1);
					}
					cout<<"按任意键返回上级"<<endl;
					getchar();
					getchar();
					loop = 1;
					break;
				case 3://修改 只有经理级别以上的可以进行修改
					if(0 < juri && juri <= 3)
					{
						m.Change(juri);
					}
					else
					{
						cout<<"您不是管理层用户，无法修改"<<endl;
					}
					cout<<"按任意键返回上级"<<endl;
					getchar();
					getchar();
					loop = 1;
					break;
				case 4://删除
					if(0 < juri && juri <= 3)
					{
						m.Delete(juri);
					}
					else
					{
						cout<<"您不是管理层用户，无法删除"<<endl;
					}
					cout<<"按任意键返回上级"<<endl;
					getchar();
					getchar();
					loop = 1;					
					break;
				case 5:
					//system("clear");
					loop = 0;
					break;
			}
		}
		else
		{
			cout<<"指令非法，请重试"<<endl;
		}
	}while(loop == 1);	
	return 0;
}