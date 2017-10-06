// ConsoleApplication48.cpp: 定义控制台应用程序的入口点。
//4.8.cpp联合体保存成绩信息

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

class exam {
public:
	exam(string name, char grade) :name(name), mode(GRADE), grade(grade) {}
	exam(string name, bool pass) : name(name), mode(PASS), pass(pass) {}
	exam(string name, int percent) :name(name), mode(PERCENT), percent(percent) {}
	void show();
private:
	string name;
	enum {
		GRADE, PASS, PERCENT
	}mode;
	union {
		char grade;
		bool pass;
		int percent;
	};
};

void exam::show() {
	cout << name << ":";
	switch (mode)
	{
	case GRADE:cout << grade;	break;
	case PASS:cout << (pass ? "PASS" : "FAIL");	break;
	case PERCENT:cout << percent;	break;
	}
	cout << endl;
}

int main()
{
	exam course1("English", 'B');
	exam course2("Calsulus", true);
	exam course3("C++Programming", 85);
	course1.show();
	course2.show();
	course3.show();
	return 0;
}

