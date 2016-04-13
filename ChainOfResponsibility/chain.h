#pragma once
#include<iostream>
#include<string>
using namespace std;
//����
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
	//�������
	string RequestType()
	{
		return requestType;
	}
	//��������
	string RequestContent()
	{
		return requestContent;
	}
	//����
	int Number()
	{
		return number;
	}
};
//������
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
	//���ù����ߵ��ϼ�
	void SetSuperior(Manager * superior)
	{
		this->superior = superior;
	}
	//��������
	virtual void RequestApplications(Request * request) = 0;
};
//����
class CommonManger : public Manager
{
public:
	CommonManger(string name) : Manager(name)
	{}
	void RequestApplications(Request * request)
	{
		if (request->RequestType() == "���" && request->Number() <= 2)
		{
			cout << name << ":" << request->RequestContent() << " ���� " << request->Number()
				<< "  ����׼" << endl;
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
//�ܼ�
class Majordomo : public Manager
{
public:
	Majordomo(string name) : Manager(name)
	{}
	void RequestApplications(Request * request)
	{
		if (request->RequestType() == "���" && request->Number() <= 5)
		{
			cout << name << ":" << request->RequestContent() << " ���� " << request->Number()
				<< "  ����׼" << endl;
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
//�ܾ���
class GeneralManager : public Manager
{
public:
	GeneralManager(string name) : Manager(name)
	{}
	void RequestApplications(Request * request)
	{
		if (request->RequestType() == "���")
		{
			cout << name << ":" << request->RequestContent() << " ���� " << request->Number()
				<< "  ����׼" << endl;
		}
		else if (request->RequestType() == "��н" && request->Number() <= 500)
		{
			cout << name << ":" << request->RequestContent() << " ���� " << request->Number()
				<< "  ����׼" << endl;
		}
		else if (request->RequestType() == "��н" && request->Number() > 500)
		{
			cout << name << ":" << request->RequestContent() << " ���� " << request->Number()
				<< "  ��˵��" << endl;
		}
	}
};