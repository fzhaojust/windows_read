#include "Read_Html.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{

//#ifdef _WIN32
//	//http://m.blog.csdn.net/article/details?id=52789570
//	//����̨��ʾ�������
// //   system("chcp 65001"); //�����ַ�����ʹ��SetConsoleCP(65001)������Ч��ԭ��δ֪��
//	//SetConsoleOutputCP(65001);
//	//CONSOLE_FONT_INFOEX info = { 0 }; // ��������������֧��������ʾ��
//	//info.cbSize = sizeof(info);
//	//info.dwFontSize.Y = 16; // leave X as zero
//	//info.FontWeight = FW_NORMAL;
//	//wcscpy(info.FaceName, L"Consolas");
//	//SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), NULL, &info);
//
//#endif


	QApplication a(argc, argv);
	
	Read_Html w;
	//w.show();
	w.showMaximized();
	return a.exec();
}
