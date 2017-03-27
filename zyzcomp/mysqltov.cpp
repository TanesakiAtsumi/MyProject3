#include<iostream>
#include"employee.h"
#include"manager.h"
using namespace std;
#include<stdlib.h>
#include<mysql/mysql.h>
extern Manager m;
int mysql_to_v()
{
	MYSQL * conn = NULL;
	MYSQL_RES * res = NULL;
	MYSQL_ROW  row = NULL;
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
	q = "select * from employee";
	mysql_real_query(conn,q,strlen(q));
	res = mysql_use_result(conn);
	if(res == NULL)
	{
		cout<<"mysql_use_result error!!"<<endl;
		return -1;
	}
	while( (row = mysql_fetch_row(res)) != NULL )
	{
		Employee t(atoi(row[0]),row[1],atoi(row[2]),atoi(row[3]));
		m.v.push_back(t);
	}
	mysql_free_result(res);
	mysql_close(conn);
	return 0;
}
