#include "Read_Html.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{

//#ifdef _WIN32
//	//http://m.blog.csdn.net/article/details?id=52789570
//	//控制台显示乱码纠正
// //   system("chcp 65001"); //设置字符集（使用SetConsoleCP(65001)设置无效，原因未知）
//	//SetConsoleOutputCP(65001);
//	//CONSOLE_FONT_INFOEX info = { 0 }; // 以下设置字体来支持中文显示。
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
