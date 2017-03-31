//菜单界面
#include <iostream>
#include <stdlib.h>

using namespace std;

void UI()
{
    int i;
    system("clear");
    for(i = 0;i<5;i++)
	    cout<<endl;
	cout<<"\t\t---------------------公司管理系统--------------------"<<endl;
	cout<<"\t\t\t\t\t"<<"1.查询"<<endl;
	cout<<"\t\t\t\t\t"<<"2.新增"<<endl;
	cout<<"\t\t\t\t\t"<<"3.修改"<<endl;
	cout<<"\t\t\t\t\t"<<"4.删除"<<endl;									
	cout<<"\t\t\t\t\t"<<"5.退出"<<endl;									
	cout<<"\t\t---------------------------------------------------"<<endl;  
}