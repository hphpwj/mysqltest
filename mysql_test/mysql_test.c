#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    char server[] = "localhost";
    char user[] = "root";
    char password[] = "123456";
    char database[] = "mysql";

    conn = mysql_init(NULL);

    if (!mysql_real_connect(conn,server,user,password,database,0,NULL,0))
    {
        printf("yyang test mysql failed!\n");
        exit(1);

    }
    
    if (mysql_query(conn,"show tables"))
    {
	
        printf("yyang test mysql show tables failed!\n");
	exit(1);
    }

    res = mysql_use_result(conn);

    printf("MySQL Tables in mysql database\n");

    while ((row = mysql_fetch_row(res)) !=NULL)
    {
        printf("%s \n",row[0]);
    }

    mysql_free_result(res);
    mysql_close(conn);
    printf("finished!\n");
    return 0;

}