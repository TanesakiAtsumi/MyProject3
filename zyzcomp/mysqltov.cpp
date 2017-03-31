#include<iostream>
#include"Staff.h"
#include"Manager.h"
using namespace std;
#include <stdlib.h>
#include <mysql/mysql.h>
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
	const char *pwd = "FLOFLO";      //用户密码
	const char *db = "Company"; //数据库名称
	conn = mysql_real_connect(conn,host,user,pwd,db,0,NULL,0);  //连接
	mysql_set_character_set(conn,"utf8");
	if(conn == NULL)//抛出异常
	{
		cout<< cout<<mysql_error(conn)<<endl;
		return -1;
	}
	const char *q = "use Company";
    mysql_real_query(conn, q, strlen(q));
	q = "select * from Staff";
	mysql_real_query(conn,q,strlen(q));
	res = mysql_use_result(conn);
	if(res == NULL)
	{
		cout<<"mysql_use_result error!!"<<endl;
		return -1;
	}
	while( (row = mysql_fetch_row(res)) != NULL )
	{
		Staff t(atoi(row[0]),row[1],atoi(row[2]),atoi(row[3]),atoi (row[4]));
		m.v.push_back(t);
	}
	mysql_free_result(res);
	mysql_close(conn);
	return 0;
}
