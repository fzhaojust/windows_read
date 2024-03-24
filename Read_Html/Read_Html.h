#pragma once
//#if _MSC_VER >= 1600
//#pragma execution_character_set("GB2312")
//#endif
#pragma execution_character_set("utf-8")
#include <QtWidgets/QMainWindow>

#include "ui_Read_Html.h"
#include<stdio.h>
#include<stdlib.h>
#include<wchar.h>


#include<iostream>
#include<qdatetime.h>
#include<qtimer.h>
#include<qtablewidget.h>
#include<qscrollbar.h>
#include<qfont.h>
#include<qstring.h>
#include<qlist.h>
#include<fstream>
#include<sstream>
#include<string>

#include<qfile.h>
#include<qfiledialog.h>

/*
错误类型：-1  数据读取错误。

*/
#ifdef _WIN32
#include <Windows.h>
#endif

using namespace std;


struct s_VTM_TOOL_INFO
{

	int current_tool_num;                                          //刀具号0
	string Handle_number;				                           //刀柄编号	1
	string	tool_type;														//刀具编号2
	double Over_length;					                           //悬长	3
	double current_tool_theoretical_diameter;				       //刀具直径	4
	double value_of_R;					                           //角落半径	5

	int current_tool_type_ID;                                      //刀具类型识别码  6
	double tool_length_wear_up_value;//#140                              //刀长防错上偏差7
	double tool_length_wear_down_value; //#141                           //刀长防错下偏差8
	double tool_diameter_wear_up_value; //#142                          //刀径防错上偏差9
	double tool_diameter_wear_down_value; //#143                        //刀径防错下偏差10

	double tool_over_length_up_wear;//194                                //悬伸长防错上偏差11
	double tool_over_length_down_wear;//195                              //悬伸长防错下偏差12
	double tool_holder_diamater_up_wear;//196                            //刀柄直径防错上偏差13
	double tool_holder_diamater_down_wear;//197                          //刀柄直径防错下偏差14
	double tool_holder_length_up_wear;//198                              //刀柄长度防错上偏差15
	double tool_holder_length_down_wear;//199                            //刀柄长度防错下偏差16





};



class Read_Html : public QMainWindow
{
	Q_OBJECT

public:
	Read_Html(QWidget *parent = Q_NULLPTR);
	//创建表格
	void creattable();
	//样式表初始化
	void interface_init();
	//读取html文件，显示，并保存
	void Read_html();
	//查询数据函数
	//int Query_Data(string str);
	//显示提示信息
	void output_mess(string tmp);
	//析构
	~Read_Html();

	bool isvalid(string str);

signals:

public slots:
	//保持两表格宽度一致
	void verticalScrollBarHideOrShow(int min, int max);
	//更新时间
	void timeUpdate();
	//导入数据
	void Import_push();
	//更新exle数据并保存
	void UpData();
	//查询数据
	//void Query_push();
	//清屏幕
	void Screen_Clear();
public:

private:

	//void obj_init();  //对象初始化

private:
	Ui::Read_HtmlClass ui;
	//s_VTM_TOOL_INFO query_tool;						//查询结果
	int num;											//数据个数
	QScrollBar* verticalScrollBar = nullptr;			//滚动条对象
	//无刀库使用
	//map<string, s_VTM_TOOL_INFO>OldMess;			//原始数据
	//map<string, s_VTM_TOOL_INFO>NewMess;			//更新数据
	map<int, s_VTM_TOOL_INFO>OldMess;			//原始数据
	map<int, s_VTM_TOOL_INFO>NewMess;			//更新数据
	//有刀库使用后
	map<int, s_VTM_TOOL_INFO>exist_oldMess;          //原始数据
	map<int, s_VTM_TOOL_INFO>exist_newMess;			 //更新数据
	bool is_exist;

};
