#include "chain.h"
int main()
{
	CommonManger * jinli = new CommonManger("����");
	Majordomo * zongjian = new Majordomo("�ڽ�");
	GeneralManager * zongjinli = new GeneralManager("�Ӿ���");
	jinli->SetSuperior(zongjian);						//�����ϼ�
	zongjian->SetSuperior(zongjinli);

	Request * request = new Request("���", "С�����", 1);
	jinli->RequestApplications(request);

	Request * request1 = new Request("���", "С�����", 4);
	jinli->RequestApplications(request1);

	Request * request2 = new Request("��н", "С�������н", 500);
	jinli->RequestApplications(request2);

	Request * request3 = new Request("��н", "С�������н", 1000);
	jinli->RequestApplications(request3);
	return 0;
}