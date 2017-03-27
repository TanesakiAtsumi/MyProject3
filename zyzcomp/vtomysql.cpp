#include<iostream>
#include"employee.h"
#include"manager.h"
using namespace std;
#include<stdlib.h>
#include<stdio.h>
#include<mysql/mysql.h>
extern Manager m;
int v_to_mysql()
{
	MYSQL * conn = NULL;	
	conn = mysql_init(NULL); //初始化句柄
	if(conn == NULL)
	{
		cout<<"mysql_init error!!"<<endl;
		return -1;
	}
	const char *host = "localhost";  //主机
	const char *user = "root";       //用户名
	const char *pwd = "123456";      //用户密码
	const char *db = "company"; //数据库名称
	conn = mysql_real_connect(conn,host,user,pwd,db,0,NULL,0);  //连接
	if(conn == NULL)
	{
		cout<< cout<<mysql_error(conn)<<endl;
		return -1;
	}
	const char *q = "use company";
    	mysql_real_query(conn, q, strlen(q));
	q = "delete from employee";
	mysql_query(conn, q);
	char buff[1024] = {'\0'};
	char buf[100] = "insert into employee values(";
	vector<Employee>::iterator i = m.v.begin();
	while(i != m.v.end())
	{
		sprintf(buff,"%s%d,'%s',%d,%d)",buf,
				(*i).m_no,
				(*i).m_name,
				(*i).m_passwd,
				(*i).m_type
			   );
		mysql_query(conn,buff);
		i++;
	}
	mysql_close(conn);
	return 0;
}

