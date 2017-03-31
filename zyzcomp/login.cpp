#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <vector>
#include "Staff.h"
#include "Manager.h"
using namespace std;

extern int mysql_to_v();
extern int v_to_mysql();
extern Manager m;

int Login()//登陆功能函数（输入值为登陆类型）
{   
    int i;
    system("clear");
    for(i = 0;i<5;i++)
	cout<<endl;
    cout<<"\t\t---------------------欢迎--------------------"<<endl;
    int staffType = 0;
    int b = 0;//定义判断
    int count = 0;
    char username[20];
    int password;
    mysql_to_v();
    vector<Staff>::iterator iter = m.v.begin();
    //定义迭代器访问容器
    //输入用户名密码
    cout<<"\t\t请输入姓名:";
    cin>>username;
    cout<<"\t\t请输入密码:";
    cin>>password;
    //与数据库中的用户名密码进行比较
    while(iter != m.v.end())
    {
        if(0 == strcmp((*iter).m_name,username))
        {
            if(password == (*iter).m_passwd)
            {
                //cout<<(*iter).m_type<<endl;
                b = 1;
                staffType = (*iter).m_type;
            }
        }
        iter++;
    }
    if(b == 0)
    {
        if(count<3)
        {
            count++;
            cout<<"用户名或密码输入错误，请重试"<<endl;
            getchar();
            getchar();
            Login();
        }
        /*else if(count == 3)
        {
            cout<<"尝试次数过多，系统自动关闭"<<endl;
            system("exit");
            //结束程序
        }*/
        
    }
    else if(b == 1)//比对结果正确
    {
        cout<<"登陆成功！"<<endl;
        sleep(1);
    }
    return staffType;
}
    
