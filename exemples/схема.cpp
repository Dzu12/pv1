#include <stdio.h> 
#include <sqlite3.h>  
#include <string> 
#include <iostream> 
#include <vector> 
#include <exception>
#include "../sqlite3orm.h" 
#include "../Sql3_scheme.h"

using namespace std;

int main()
{
	Sql3_scheme* new_scheme = new Sql3_scheme;
	string sql = new_scheme->table("chello") // ��������� ��� �������
		->addField("age", "INTEGER") // ��������� ���� ���� INTEGER
		->addField("name", "TEXT") // ��������� ���� ���� TEXT
		->addField("sgz", "BLOB") //��������� ���� ���� BLOB
		->addField("wgds", "REAL") // ��������� ���� ���� REAL
		->addField("fgdfg", "NUMERIC") //��������� ���� ���� NUMERIC
		->create(true); // ���� ���, ������� �� ��� ������

	const char* sqll = sql.data();
	cout << sqll << '\n';
	sqlite3orm::getInstance()->execAndPrint(sqll);

	Sql3_scheme* new_scheme4 = new Sql3_scheme;
	string Sql2 = new_scheme4->table("chello")
		->rename("Hello");//�������� �������� �������
	const char* sqll3 = Sql2.data();
	cout << sqll3 << '\n';
	sqlite3orm::getInstance()->execAndPrint(sqll3);

	Sql3_scheme* new_scheme5 = new Sql3_scheme;
	string Sql3 = new_scheme5->table("Hello")
		->addColumn("sdada", "TEXT");//�������� ����� �������
	const char* sqll4 = Sql3.data();
	cout << sqll4 << '\n';
	sqlite3orm::getInstance()->execAndPrint(sqll4);

	Sql3_scheme* new_scheme6 = new Sql3_scheme;
	string Sql4 = new_scheme6->table("Hello")
		->renameColumn("sdada", "Text"); //������������� �������
	const char* sqll5 = Sql4.data();
	cout << sqll5 << '\n';
	sqlite3orm::getInstance()->execAndPrint(sqll5);

	Sql3_scheme* new_scheme2 = new Sql3_scheme;
	string Sql = new_scheme2->table("Hello")
		->dropColumn("age"); //������� ������� age
	const char* sqll1 = Sql.data();
	cout << sqll1 << '\n';
	sqlite3orm::getInstance()->execAndPrint(sqll1);

	//Sql3_scheme* new_scheme3 = new Sql3_scheme;
	//string Sql1 = new_scheme3->table("Hello")
	//	->drop();// �������� �������
	//const char* sqll2 = Sql1.data();
	//cout << sqll2 << '\n';
	//sqlite3orm::getInstance()->execAndPrint(sqll2);
}