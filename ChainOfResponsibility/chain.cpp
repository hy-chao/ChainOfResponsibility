#include "chain.h"
int main()
{
	CommonManger * jinli = new CommonManger("金利");
	Majordomo * zongjian = new Majordomo("宗剑");
	GeneralManager * zongjinli = new GeneralManager("钟精励");
	jinli->SetSuperior(zongjian);						//设置上级
	zongjian->SetSuperior(zongjinli);

	Request * request = new Request("请假", "小菜请假", 1);
	jinli->RequestApplications(request);

	Request * request1 = new Request("请假", "小菜请假", 4);
	jinli->RequestApplications(request1);

	Request * request2 = new Request("加薪", "小菜请求加薪", 500);
	jinli->RequestApplications(request2);

	Request * request3 = new Request("加薪", "小菜请求加薪", 1000);
	jinli->RequestApplications(request3);
	return 0;
}