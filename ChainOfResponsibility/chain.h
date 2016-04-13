#pragma once
#include<iostream>
#include<string>
using namespace std;
//申请
class Request
{
private:
	string requestType;
	string requestContent;
	int number;
public:
	Request(string type, string content, int num)
	{
		requestType = type;
		requestContent = content;
		number = num;
	}
	//申请类别
	string RequestType()
	{
		return requestType;
	}
	//申请内容
	string RequestContent()
	{
		return requestContent;
	}
	//数量
	int Number()
	{
		return number;
	}
};
//管理者
class Manager
{
protected:
	string name;
	Manager * superior;
public:
	Manager(string name)
	{
		this->name = name;
	}
	//设置管理者的上级
	void SetSuperior(Manager * superior)
	{
		this->superior = superior;
	}
	//申请请求
	virtual void RequestApplications(Request * request) = 0;
};
//经理
class CommonManger : public Manager
{
public:
	CommonManger(string name) : Manager(name)
	{}
	void RequestApplications(Request * request)
	{
		if (request->RequestType() == "请假" && request->Number() <= 2)
		{
			cout << name << ":" << request->RequestContent() << " 数量 " << request->Number()
				<< "  被批准" << endl;
		}
		else
		{
			if (superior != NULL)
			{
				superior->RequestApplications(request);
			}
		}

	}
};
//总监
class Majordomo : public Manager
{
public:
	Majordomo(string name) : Manager(name)
	{}
	void RequestApplications(Request * request)
	{
		if (request->RequestType() == "请假" && request->Number() <= 5)
		{
			cout << name << ":" << request->RequestContent() << " 数量 " << request->Number()
				<< "  被批准" << endl;
		}
		else
		{
			if (superior != NULL)
			{
				superior->RequestApplications(request);
			}
		}

	}
};
//总经理
class GeneralManager : public Manager
{
public:
	GeneralManager(string name) : Manager(name)
	{}
	void RequestApplications(Request * request)
	{
		if (request->RequestType() == "请假")
		{
			cout << name << ":" << request->RequestContent() << " 数量 " << request->Number()
				<< "  被批准" << endl;
		}
		else if (request->RequestType() == "加薪" && request->Number() <= 500)
		{
			cout << name << ":" << request->RequestContent() << " 数量 " << request->Number()
				<< "  被批准" << endl;
		}
		else if (request->RequestType() == "加薪" && request->Number() > 500)
		{
			cout << name << ":" << request->RequestContent() << " 数量 " << request->Number()
				<< "  再说吧" << endl;
		}
	}
};