#include "Read_Html.h"
//���޵���
Read_Html::Read_Html(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	interface_init();
	creattable();
	//obj_init();

	//ʱ������
	QTimer *timer = new QTimer(this);
	timer->start(10); // ÿ�δ���timeout�ź�ʱ����Ϊ1��
	connect(timer, SIGNAL(timeout()), this, SLOT(timeUpdate()));
	
	//��������
	connect(ui.pushButton, &QPushButton::clicked, this, &Read_Html::Import_push);
	
	//��ѯ����
	//connect(ui.pushButton_3, &QPushButton::clicked, this, &Read_Html::Query_push);
	//��������
	connect(ui.pushButton_2, &QPushButton::clicked, this, &Read_Html::UpData);

	//�رճ���
	connect(ui.pushButton_4, &QPushButton::clicked, [this]() {QApplication *app; app->exit(); });

	//����
	connect(ui.pushButton_5, &QPushButton::clicked, this, &Read_Html::Screen_Clear);
	is_exist = false;

	//connect(ui.radioButton,)
	ui.radioButton->setChecked(true);


}

bool Read_Html::isvalid(string str) {
	for (int i = 0; i < str.size(); ++i) {
		if (!isdigit(str[i]))return false;
	}
	return true;
}

//�������
void Read_Html::creattable() {

	ui.table_header->setRowCount(25);
	ui.table_header->setColumnCount(17);
	//ui.table_header->setFrameShape(QFrame::NoFrame);
	//���ù�����
	ui.table_header->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
	ui.table_header->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
	ui.table_header->setFrameShape(QFrame::NoFrame);
	ui.table_header->setFocusPolicy(Qt::NoFocus);
	ui.table_header->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.table_header->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.table_header->setAlternatingRowColors(true);
	QStringList m_Header;


	m_Header << QString("���ߺ�")  << QString("��������ʶ����") << QString("�������") << QString("���߱��") << QString("����") << QString("����ֱ��")
		<< QString("R�ǰ뾶")
		<< QString("����������ƫ��") << QString("����������ƫ��") << QString("����������ƫ��") << QString("����������ƫ��")
		<< QString("���쳤������ƫ��") << QString("���쳤������ƫ��") << QString("�������ȷ�����ƫ��") << QString("�������ȷ�����ƫ��")
		<< QString("����ֱ��������ƫ��") << QString("����ֱ��������ƫ��");

	ui.table_header->setHorizontalHeaderLabels(m_Header);				//��Ӻ����ͷ
	ui.table_header->verticalHeader()->setVisible(false);				//�����ͷ���ӻ�
	ui.table_header->horizontalHeader()->setVisible(true);				//�����ͷ���ӻ�
	ui.table_header->setSelectionMode(QAbstractItemView::SingleSelection);

	//������
	for (int i = 0; i < ui.table_header->rowCount(); ++i) {
		for (int j = 0; j < ui.table_header->columnCount(); ++j) {

			ui.table_header->setItem(i, j, new QTableWidgetItem(""));
			ui.table_header->item(i, j)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

		}
	}

}



//��ʽ���ʼ��
void Read_Html::interface_init() {
	ui.textEdit->setReadOnly(true);
	QFont ft;
	ft.setPointSize(30);
	//ui.label->setFont(ft);
	//ui.lineEdit->setFont(ft);
	ui.pushButton->setFont(ft);
	ui.pushButton_2->setFont(ft);
	//ui.pushButton_3->setFont(ft);
	ui.pushButton_4->setFont(ft);
	ui.pushButton_5->setFont(ft);
	
	ui.radioButton->setFont(ft);
	ui.radioButton_2->setFont(ft);





}


//���ͷ��biogenic��ͬ��С
void Read_Html::verticalScrollBarHideOrShow(int min, int max) {
	if (min == max)
	{
		verticalScrollBar->setHidden(true);
	}
	else
	{
		verticalScrollBar->setHidden(false);
	}
}


//����ʱ��
void Read_Html::timeUpdate() {
	QRect rec = ui.widget_2->frameGeometry();
	//double wid = ui.widget_2->frameGeometry.width();
	//double wid = ui.widget->frameGeometry().width();
	
	//ui.widget_2->colorCount();
	double tableheader_width = rec.width() / ui.table_header->colorCount();
	for (int i = 0; i < ui.table_header->columnCount(); ++i) {
		ui.table_header->setColumnWidth(i, 150);
	}

	//for (int i = 0; i < ui.widget_2->colorCount(); ++i) {
	//	ui.table_content->setColumnWidth(i, 140);
	//}

	if (ui.radioButton->isChecked()) {
		is_exist = false;

	}
	else if(ui.radioButton_2->isChecked()){
		is_exist = true;
	}
	else {
		
	}


}

//��ȡhtml�ļ�����ʾ��������
void Read_Html::Read_html() {

	QString path = QFileDialog::getOpenFileName(this,
		"open", "../",tr("Excel(*.csv)"));
	if (path.isEmpty()) {
		return;
	}

	string th = path.toLocal8Bit().toStdString();

	//��Ҫ������ļ� 
	ifstream iFile(th);
	string s1;
	QString str;
	string tmp ;
	s_VTM_TOOL_INFO oldtool;
	//���ԭʼ���ݣ�


	OldMess.clear();
	NewMess.clear();
	exist_oldMess.clear();
	exist_newMess.clear();
	//������ݺͱ�ͷ
	//ui.table_header->clear();
	//ֻ������ݣ��������ͷ
	ui.table_header->clearContents();
	if (ui.table_header->rowCount() > 25) {
		for (int row = ui.table_header->rowCount() - 26; row >= 0; row--)
		{
			ui.table_header->removeRow(row);
		}
	}

	switch (is_exist)
	{
	case false:
		/*tmp = "�޵���";
		output_mess(tmp);*/
		while (getline(iFile, s1))
		{
			
			str = QString::fromStdString(s1);
			QStringList list1 = str.split(",");

			//дʱ���ļ�תΪ.toLocal8Bit��ʽ�������д����


			if (list1.size() == 17 && isdigit(list1[5].toStdString()[0])) {//&&isdigit(list1[1].toStdString()[0])
				oldtool.current_tool_num = stod(list1[1].toLocal8Bit().toStdString());
				oldtool.Handle_number = list1[3].toLocal8Bit().toStdString();
				//list1[4].toLocal8Bit().toStdString()
				if (list1[4].toLocal8Bit().toStdString().size() == 0) {
					oldtool.tool_type = "";
				}
				else {
					oldtool.tool_type = list1[4].toLocal8Bit().toStdString();
				}
				if (list1[5].toLocal8Bit().toStdString().size() == 0) {
					oldtool.Over_length = 0;
				}
				else {
					oldtool.Over_length = stod(list1[5].toLocal8Bit().toStdString());
				}


				if (list1[12].toLocal8Bit().toStdString().size() == 0) {
					oldtool.current_tool_theoretical_diameter = 0;
				}
				else {
					oldtool.current_tool_theoretical_diameter = stod(list1[12].toLocal8Bit().toStdString());
				}
				if (list1[13].toLocal8Bit().toStdString().size() == 0) {
					oldtool.value_of_R = 0;
				}
				else {
					oldtool.value_of_R = stod(list1[13].toLocal8Bit().toStdString());
				}

				oldtool.current_tool_type_ID = -1;

				oldtool.tool_length_wear_up_value = 0.03;
				oldtool.tool_length_wear_down_value = -0.03;
				oldtool.tool_diameter_wear_up_value = 0.02;
				oldtool.tool_diameter_wear_down_value = -0.02;
				oldtool.tool_over_length_up_wear = 3;//194         
				oldtool.tool_over_length_down_wear = 0;//195       
				oldtool.tool_holder_diamater_up_wear = 5;//196     
				oldtool.tool_holder_diamater_down_wear = 0;//197   
				oldtool.tool_holder_length_up_wear = 5;//198   

				oldtool.tool_holder_length_down_wear = 0;//199     s[oldtool.current_tool_num] = oldtool;
				//cout << oldtool.current_tool_num;
				OldMess.insert(make_pair(oldtool.current_tool_num, oldtool));
				num++;
			}
		}
		iFile.close();
		break;
	case true:
		/*tmp = "�е���";
		output_mess(tmp);*/

		while (getline(iFile, s1))
		{
			
			str = QString::fromStdString(s1);
			QStringList list1 = str.split(",");

			//дʱ���ļ�תΪ.toLocal8Bit��ʽ�������д����


			if (list1.size() == 17 && isdigit(list1[1].toStdString()[0])) {//&&isdigit(list1[1].toStdString()[0])
				oldtool.current_tool_num = stod(list1[1].toLocal8Bit().toStdString());
				oldtool.Handle_number = list1[3].toLocal8Bit().toStdString();
				//list1[4].toLocal8Bit().toStdString()
				if (list1[4].toLocal8Bit().toStdString().size() == 0) {
					oldtool.tool_type = "";
				}
				else {
					oldtool.tool_type = list1[4].toLocal8Bit().toStdString();
				}
				if (list1[5].toLocal8Bit().toStdString().size() == 0) {
					oldtool.Over_length = 0;
				}
				else {
					oldtool.Over_length = stod(list1[5].toLocal8Bit().toStdString());
				}


				if (list1[12].toLocal8Bit().toStdString().size() == 0) {
					oldtool.current_tool_theoretical_diameter = 0;
				}
				else {
					oldtool.current_tool_theoretical_diameter = stod(list1[12].toLocal8Bit().toStdString());
				}
				if (list1[13].toLocal8Bit().toStdString().size() == 0) {
					oldtool.value_of_R = 0;
				}
				else {
					oldtool.value_of_R = stod(list1[13].toLocal8Bit().toStdString());
				}

				oldtool.current_tool_type_ID = -1;

				oldtool.tool_length_wear_up_value = 0.03;
				oldtool.tool_length_wear_down_value = -0.03;
				oldtool.tool_diameter_wear_up_value = 0.02;
				oldtool.tool_diameter_wear_down_value = -0.02;
				oldtool.tool_over_length_up_wear = 3;//194         
				oldtool.tool_over_length_down_wear = 0;//195       
				oldtool.tool_holder_diamater_up_wear = 5;//196     
				oldtool.tool_holder_diamater_down_wear = 0;//197   
				oldtool.tool_holder_length_up_wear = 5;//198   

				oldtool.tool_holder_length_down_wear = 0;//199     s[oldtool.current_tool_num] = oldtool;
				//cout << oldtool.current_tool_num;
				exist_oldMess.insert(make_pair(oldtool.current_tool_num, oldtool));
				num++;
			}
		}
		iFile.close();
		break;
	default:
		break;
	}

	int k = 0;
	switch (is_exist)
	{
	case false:
		for (auto it = OldMess.begin(); it != OldMess.end(); ++it) {
			int row = ui.table_header->currentRow();
			int row_count = ui.table_header->rowCount();
			int newRow = row + 1;
			if (row == -1) {
				newRow = row_count;
			}
			ui.table_header->insertRow(newRow);
			ui.table_header->setItem(k, 0, new QTableWidgetItem(QString::number(it->second.current_tool_num)));
			ui.table_header->item(k, 0)->setTextAlignment(Qt::AlignCenter);
			ui.table_header->setItem(k, 1, new QTableWidgetItem(QString::number(it->second.current_tool_type_ID)));
			ui.table_header->item(k, 1)->setTextAlignment(Qt::AlignCenter);
			ui.table_header->setItem(k, 2, new QTableWidgetItem(QString::fromLocal8Bit(it->second.Handle_number.data())));
			ui.table_header->item(k, 2)->setTextAlignment(Qt::AlignCenter);
			ui.table_header->setItem(k, 3, new QTableWidgetItem(QString::fromLocal8Bit(it->second.tool_type.data())));
			ui.table_header->item(k, 3)->setTextAlignment(Qt::AlignCenter);

			ui.table_header->setItem(k, 4, new QTableWidgetItem(QString::number(it->second.Over_length, 'f', 4)));
			ui.table_header->item(k, 4)->setTextAlignment(Qt::AlignCenter);
			ui.table_header->setItem(k, 5, new QTableWidgetItem(QString::number(it->second.current_tool_theoretical_diameter, 'f', 4)));
			ui.table_header->item(k, 5)->setTextAlignment(Qt::AlignCenter);
			ui.table_header->setItem(k, 6, new QTableWidgetItem(QString::number(it->second.value_of_R, 'f', 4)));
			ui.table_header->item(k, 6)->setTextAlignment(Qt::AlignCenter);
			ui.table_header->setItem(k, 7, new QTableWidgetItem(QString::number(it->second.tool_length_wear_up_value, 'f', 4)));
			ui.table_header->item(k, 7)->setTextAlignment(Qt::AlignCenter);
			ui.table_header->setItem(k, 8, new QTableWidgetItem(QString::number(it->second.tool_length_wear_down_value, 'f', 4)));
			ui.table_header->item(k, 8)->setTextAlignment(Qt::AlignCenter);
			ui.table_header->setItem(k, 9, new QTableWidgetItem(QString::number(it->second.tool_diameter_wear_up_value, 'f', 4)));
			ui.table_header->item(k, 9)->setTextAlignment(Qt::AlignCenter);
			ui.table_header->setItem(k, 10, new QTableWidgetItem(QString::number(it->second.tool_diameter_wear_down_value, 'f', 4)));
			ui.table_header->item(k, 10)->setTextAlignment(Qt::AlignCenter);
			ui.table_header->setItem(k, 11, new QTableWidgetItem(QString::number(it->second.tool_over_length_up_wear, 'f', 4)));
			ui.table_header->item(k, 11)->setTextAlignment(Qt::AlignCenter);
			ui.table_header->setItem(k, 12, new QTableWidgetItem(QString::number(it->second.tool_over_length_down_wear, 'f', 4)));
			ui.table_header->item(k, 12)->setTextAlignment(Qt::AlignCenter);

			ui.table_header->setItem(k, 13, new QTableWidgetItem(QString::number(it->second.tool_holder_diamater_up_wear, 'f', 4)));
			ui.table_header->item(k, 13)->setTextAlignment(Qt::AlignCenter);
			ui.table_header->setItem(k, 14, new QTableWidgetItem(QString::number(it->second.tool_holder_diamater_down_wear, 'f', 4)));
			ui.table_header->item(k, 14)->setTextAlignment(Qt::AlignCenter);
			ui.table_header->setItem(k, 15, new QTableWidgetItem(QString::number(it->second.tool_holder_length_up_wear, 'f', 4)));
			ui.table_header->item(k, 15)->setTextAlignment(Qt::AlignCenter);
			ui.table_header->setItem(k, 16, new QTableWidgetItem(QString::number(it->second.tool_holder_length_down_wear, 'f', 4)));
			ui.table_header->item(k, 16)->setTextAlignment(Qt::AlignCenter);

			k++;
			//ofstream oFile;
			//oFile.open("haha.csv", ios::out | ios::trunc);    // �����ͺ����׵����һ����Ҫ��excel �ļ�  
			//oFile << it->second.id << "," << it->second.Handle_number << "," << it->second.Tool_number << ","\
			//	<< to_string(it->second.Over_length) << "," << to_string(it->second.D_Arbor) << "," << to_string(it->second.D_Tool) << ","\
			//	<< to_string(it->second.Corner_radius) << "," << to_string(it->second.Blade_length) << "," << to_string(it->second.Tool_length) << endl;
			//ui.table_header->clearContents();
		}
		break;
	case true:
		for (auto it = exist_oldMess.begin(); it != exist_oldMess.end(); ++it) {
			int row = ui.table_header->currentRow();
			int row_count = ui.table_header->rowCount();
			int newRow = row + 1;
			if (row == -1) {
				newRow = row_count;
			}
			ui.table_header->insertRow(newRow);
			ui.table_header->setItem(k, 0, new QTableWidgetItem(QString::number(it->second.current_tool_num)));
			ui.table_header->item(k, 0)->setTextAlignment(Qt::AlignCenter);
			ui.table_header->setItem(k, 1, new QTableWidgetItem(QString::number(it->second.current_tool_type_ID)));
			ui.table_header->item(k, 1)->setTextAlignment(Qt::AlignCenter);
			ui.table_header->setItem(k, 2, new QTableWidgetItem(QString::fromLocal8Bit(it->second.Handle_number.data())));
			ui.table_header->item(k, 2)->setTextAlignment(Qt::AlignCenter);
			ui.table_header->setItem(k, 3, new QTableWidgetItem(QString::fromLocal8Bit(it->second.tool_type.data())));
			ui.table_header->item(k, 3)->setTextAlignment(Qt::AlignCenter);

			ui.table_header->setItem(k, 4, new QTableWidgetItem(QString::number(it->second.Over_length, 'f', 4)));
			ui.table_header->item(k, 4)->setTextAlignment(Qt::AlignCenter);
			ui.table_header->setItem(k, 5, new QTableWidgetItem(QString::number(it->second.current_tool_theoretical_diameter, 'f', 4)));
			ui.table_header->item(k, 5)->setTextAlignment(Qt::AlignCenter);
			ui.table_header->setItem(k, 6, new QTableWidgetItem(QString::number(it->second.value_of_R, 'f', 4)));
			ui.table_header->item(k, 6)->setTextAlignment(Qt::AlignCenter);
			ui.table_header->setItem(k, 7, new QTableWidgetItem(QString::number(it->second.tool_length_wear_up_value, 'f', 4)));
			ui.table_header->item(k, 7)->setTextAlignment(Qt::AlignCenter);
			ui.table_header->setItem(k, 8, new QTableWidgetItem(QString::number(it->second.tool_length_wear_down_value, 'f', 4)));
			ui.table_header->item(k, 8)->setTextAlignment(Qt::AlignCenter);
			ui.table_header->setItem(k, 9, new QTableWidgetItem(QString::number(it->second.tool_diameter_wear_up_value, 'f', 4)));
			ui.table_header->item(k, 9)->setTextAlignment(Qt::AlignCenter);
			ui.table_header->setItem(k, 10, new QTableWidgetItem(QString::number(it->second.tool_diameter_wear_down_value, 'f', 4)));
			ui.table_header->item(k, 10)->setTextAlignment(Qt::AlignCenter);
			ui.table_header->setItem(k, 11, new QTableWidgetItem(QString::number(it->second.tool_over_length_up_wear, 'f', 4)));
			ui.table_header->item(k, 11)->setTextAlignment(Qt::AlignCenter);
			ui.table_header->setItem(k, 12, new QTableWidgetItem(QString::number(it->second.tool_over_length_down_wear, 'f', 4)));
			ui.table_header->item(k, 12)->setTextAlignment(Qt::AlignCenter);

			ui.table_header->setItem(k, 13, new QTableWidgetItem(QString::number(it->second.tool_holder_diamater_up_wear, 'f', 4)));
			ui.table_header->item(k, 13)->setTextAlignment(Qt::AlignCenter);
			ui.table_header->setItem(k, 14, new QTableWidgetItem(QString::number(it->second.tool_holder_diamater_down_wear, 'f', 4)));
			ui.table_header->item(k, 14)->setTextAlignment(Qt::AlignCenter);
			ui.table_header->setItem(k, 15, new QTableWidgetItem(QString::number(it->second.tool_holder_length_up_wear, 'f', 4)));
			ui.table_header->item(k, 15)->setTextAlignment(Qt::AlignCenter);
			ui.table_header->setItem(k, 16, new QTableWidgetItem(QString::number(it->second.tool_holder_length_down_wear, 'f', 4)));
			ui.table_header->item(k, 16)->setTextAlignment(Qt::AlignCenter);

			k++;
			//ofstream oFile;
			//oFile.open("haha.csv", ios::out | ios::trunc);    // �����ͺ����׵����һ����Ҫ��excel �ļ�  
			//oFile << it->second.id << "," << it->second.Handle_number << "," << it->second.Tool_number << ","\
			//	<< to_string(it->second.Over_length) << "," << to_string(it->second.D_Arbor) << "," << to_string(it->second.D_Tool) << ","\
			//	<< to_string(it->second.Corner_radius) << "," << to_string(it->second.Blade_length) << "," << to_string(it->second.Tool_length) << endl;
			//ui.table_header->clearContents();
		}
		break;
	default:
		break;
	}

	
	 tmp = "�����������";
	output_mess(tmp);

	
}


/*


int current_tool_num;                                          //���߱��0
string Handle_number;				                           //�������	1
string	tool_type;														//���߱��2
double Over_length;					                           //����	2
double current_tool_theoretical_diameter;				       //����ֱ��	3
double value_of_R;					                           //����뾶	4

int current_tool_type_ID;                                      //��������ʶ����  5
double tool_length_wear_up_value;//#140                              //����������ƫ��6
double tool_length_wear_down_value; //#141                           //����������ƫ��7
double tool_diameter_wear_up_value; //#142                          //����������ƫ��8
double tool_diameter_wear_down_value; //#143                        //����������ƫ��9
double tool_over_length_up_wear;//194                                //���쳤������ƫ��10
double tool_over_length_down_wear;//195                              //���쳤������ƫ��11
double tool_holder_diamater_up_wear;//196                            //����ֱ��������ƫ��12
double tool_holder_diamater_down_wear;//197                          //����ֱ��������ƫ��13
double tool_holder_length_up_wear;//198                              //�������ȷ�����ƫ��14
double tool_holder_length_down_wear;//199                            //�������ȷ�����ƫ��15

*/
//����exle���ݲ�����
void Read_Html::UpData() {
	NewMess.clear();
	exist_newMess.clear();

	//��Ҫ������ļ� 
	//��������
	ofstream oFile;
	oFile.open("current_tool_data.csv", ios::out | ios::trunc);    // �����ͺ����׵����һ����Ҫ��excel �ļ�  
	int as = ui.table_header->rowCount();

	/*oFile << string("����") << "," << it->second.Handle_number << "," << it->second.Tool_number << ","
		<< to_string(it->second.Over_length) << "," << to_string(it->second.D_Arbor) << "," << to_string(it->second.D_Tool) << ","
		<< to_string(it->second.Corner_radius) << "," << to_string(it->second.Blade_length) << "," << to_string(it->second.Tool_length) << endl;
*/
	oFile << QString("���ߺ�").toLocal8Bit().constData() << ","
		<< QString("��������ʶ����").toLocal8Bit().constData() << ","
		<< QString("�������").toLocal8Bit().constData() << "," 
		<< QString("���߱��").toLocal8Bit().constData() << ","
		<< QString("����").toLocal8Bit().constData() << ","
		<< QString("����ֱ��").toLocal8Bit().constData() << ","
		<< QString("R�ǰ뾶").toLocal8Bit().constData() << "," 
		<< QString("����������ƫ��").toLocal8Bit().constData() << "," 
		<< QString("����������ƫ��").toLocal8Bit().constData() << ","
		<< QString("����������ƫ��").toLocal8Bit().constData() << ","
		<< QString("����������ƫ��").toLocal8Bit().constData() << "," 
		<< QString("���쳤������ƫ��").toLocal8Bit().constData() << "," 
		<< QString("���쳤������ƫ��").toLocal8Bit().constData() << ","
		<< QString("�������ȷ�����ƫ��").toLocal8Bit().constData() << "," 
		<< QString("�������ȷ�����ƫ��").toLocal8Bit().constData() << "," 
		<< QString("����ֱ��������ƫ��").toLocal8Bit().constData() << "," 
		<< QString("����ֱ��������ƫ��").toLocal8Bit().constData() << endl;

	s_VTM_TOOL_INFO newtool;


	bool flag_input = false;
	


	int col = ui.table_header->columnCount();


	switch (is_exist)
	{
	case false:
		for (int i = 0; i < as; ++i) {

			flag_input = false;
			for (int j = 0; j < col; ++j) {
				if ((ui.table_header->item(i, 0) && ui.table_header->item(i, 0)->text() == tr("")) || ui.table_header->item(i, 0) == nullptr) {//ui.table_header->item(i, 0)->text().toLocal8Bit().toStdString().size()==0||
					flag_input = false;
					break;
				}
				else {
					flag_input = true;
				}

				switch (j)
				{
				case 0:
					newtool.current_tool_num = ui.table_header->item(i, j)->text().toLocal8Bit().toInt();
					//cout << "newtool.id:"<<newtool.current_tool_num << endl;
					break;
				case 1:
					if (ui.table_header->item(i, j) == NULL) {
						newtool.current_tool_type_ID = -1;
					}
					else newtool.current_tool_type_ID = ui.table_header->item(i, j)->text().toLocal8Bit().toInt();
					break;
				case 2:
					if (ui.table_header->item(i, j) == NULL) {
						newtool.Handle_number = "";
					}
					else newtool.Handle_number = ui.table_header->item(i, j)->text().toLocal8Bit().toStdString();
					break;
				case 3:
					if (ui.table_header->item(i, j) == NULL) {
						newtool.tool_type = "";
					}
					else newtool.tool_type = ui.table_header->item(i, j)->text().toLocal8Bit().toStdString();
					break;
				case 4:
					if (ui.table_header->item(i, j)->text().toLocal8Bit().toStdString().size() == 0) {
						newtool.Over_length = (double)0;
					}
					else newtool.Over_length = ui.table_header->item(i, j)->text().toLocal8Bit().toDouble();
					break;
				case 5:
					if (ui.table_header->item(i, j)->text().toLocal8Bit().toStdString().size() == 0) {
						newtool.current_tool_theoretical_diameter = (double)0;
					}
					else newtool.current_tool_theoretical_diameter = ui.table_header->item(i, 5)->text().toLocal8Bit().toDouble();
					break;

				case 6:
					if (ui.table_header->item(i, j)->text().toLocal8Bit().toStdString().size() == 0) {
						newtool.value_of_R = (double)0;
					}
					else newtool.value_of_R = ui.table_header->item(i, j)->text().toLocal8Bit().toDouble();
					/*	if (ui.table_header->item(i, j) == NULL) {
							newtool.Corner_radius = (double)-1.0;
						}
						else newtool.Corner_radius = ui.table_header->item(i, 6)->text().toLocal8Bit().toDouble();*/
					break;

				case 7:
					if (ui.table_header->item(i, j)->text().toLocal8Bit().toStdString().size() == 0) {
						newtool.tool_length_wear_up_value = (double)0;

					}
					else newtool.tool_length_wear_up_value = ui.table_header->item(i, j)->text().toLocal8Bit().toDouble();
					break;
				case 8:
					if (ui.table_header->item(i, j)->text().toLocal8Bit().toStdString().size() == 0) {
						newtool.tool_length_wear_down_value = (double)0;

					}
					else newtool.tool_length_wear_down_value = ui.table_header->item(i, j)->text().toLocal8Bit().toDouble();
					break;
				case 9:
					if (ui.table_header->item(i, j)->text().toLocal8Bit().toStdString().size() == 0) {
						newtool.tool_diameter_wear_up_value = (double)0;

					}
					else newtool.tool_diameter_wear_up_value = ui.table_header->item(i, j)->text().toLocal8Bit().toDouble();
					break;
				case 10:
					if (ui.table_header->item(i, j)->text().toLocal8Bit().toStdString().size() == 0) {
						newtool.tool_diameter_wear_down_value = (double)0;

					}
					else newtool.tool_diameter_wear_down_value = ui.table_header->item(i, j)->text().toLocal8Bit().toDouble();
					break;
				case 11:
					if (ui.table_header->item(i, j)->text().toLocal8Bit().toStdString().size() == 0) {
						newtool.tool_over_length_up_wear = (double)0;

					}
					else newtool.tool_over_length_up_wear = ui.table_header->item(i, j)->text().toLocal8Bit().toDouble();
					break;
				case 12:
					if (ui.table_header->item(i, j)->text().toLocal8Bit().toStdString().size() == 0) {
						newtool.tool_over_length_down_wear = (double)0;

					}
					else newtool.tool_over_length_down_wear = ui.table_header->item(i, j)->text().toLocal8Bit().toDouble();
					break;
				case 13:
					if (ui.table_header->item(i, j)->text().toLocal8Bit().toStdString().size() == 0) {
						newtool.tool_holder_diamater_up_wear = (double)0;

					}
					else newtool.tool_holder_diamater_up_wear = ui.table_header->item(i, j)->text().toLocal8Bit().toDouble();
					break;
				case 14:
					if (ui.table_header->item(i, j)->text().toLocal8Bit().toStdString().size() == 0) {
						newtool.tool_holder_diamater_down_wear = (double)0;

					}
					else newtool.tool_holder_diamater_down_wear = ui.table_header->item(i, j)->text().toLocal8Bit().toDouble();
					break;
				case 15:
					if (ui.table_header->item(i, j)->text().toLocal8Bit().toStdString().size() == 0) {
						newtool.tool_holder_length_up_wear = (double)0;

					}
					else newtool.tool_holder_length_up_wear = ui.table_header->item(i, j)->text().toLocal8Bit().toDouble();
					break;
					break;
				case 16:
					if (ui.table_header->item(i, j)->text().toLocal8Bit().toStdString().size() == 0) {
						newtool.tool_holder_length_down_wear = (double)0;

					}
					else newtool.tool_holder_length_down_wear = ui.table_header->item(i, j)->text().toLocal8Bit().toDouble();
					break;
				default:
					break;
				}
			}
			if (flag_input == true) {
				//cout << flag_input;
				//cout << newtool.current_tool_num << endl;
				//NewMess[newtool.current_tool_num] = newtool;
				NewMess.insert(make_pair(newtool.current_tool_num, newtool));
			}

			//NewMess.insert(make_pair(newtool.current_tool_num, newtool));// [newtool.id] = newtool;
		}

		//д��

		for (auto it = NewMess.begin(); it != NewMess.end(); ++it) {
			oFile << to_string(it->second.current_tool_num) << ","
				<< to_string(it->second.current_tool_type_ID) << ","
				<< it->second.Handle_number << ","
				<< it->second.tool_type << ","
				<< to_string(it->second.Over_length) << ","
				<< to_string(it->second.current_tool_theoretical_diameter) << ","
				<< to_string(it->second.value_of_R) << ","
				<< to_string(it->second.tool_length_wear_up_value) << ","
				<< to_string(it->second.tool_length_wear_down_value) << ","
				<< to_string(it->second.tool_diameter_wear_up_value) << ","
				<< to_string(it->second.tool_diameter_wear_down_value) << ","
				<< to_string(it->second.tool_over_length_up_wear) << ","
				<< to_string(it->second.tool_over_length_down_wear) << ","
				<< to_string(it->second.tool_holder_diamater_up_wear) << ","
				<< to_string(it->second.tool_holder_diamater_down_wear) << ","
				<< to_string(it->second.tool_holder_length_up_wear) << ","
				<< to_string(it->second.tool_holder_length_down_wear) << endl;

		}
		break;
	case true:
		for (int i = 0; i < as; ++i) {

			flag_input = false;
			for (int j = 0; j < col; ++j) {
				if ((ui.table_header->item(i, 0) && ui.table_header->item(i, 0)->text() == tr("")) || ui.table_header->item(i, 0) == nullptr) {//ui.table_header->item(i, 0)->text().toLocal8Bit().toStdString().size()==0||
					flag_input = false;
					break;
				}
				else {
					flag_input = true;
				}

				switch (j)
				{
				case 0:
					newtool.current_tool_num = ui.table_header->item(i, j)->text().toLocal8Bit().toInt();
					//cout << "newtool.id:"<<newtool.current_tool_num << endl;
					break;
				case 1:
					if (ui.table_header->item(i, j) == NULL) {
						newtool.current_tool_type_ID = -1;
					}
					else newtool.current_tool_type_ID = ui.table_header->item(i, j)->text().toLocal8Bit().toInt();
					break;
				case 2:
					if (ui.table_header->item(i, j) == NULL) {
						newtool.Handle_number = "";
					}
					else newtool.Handle_number = ui.table_header->item(i, j)->text().toLocal8Bit().toStdString();
					break;
				case 3:
					if (ui.table_header->item(i, j) == NULL) {
						newtool.tool_type = "";
					}
					else newtool.tool_type = ui.table_header->item(i, j)->text().toLocal8Bit().toStdString();
					break;
				case 4:
					if (ui.table_header->item(i, j)->text().toLocal8Bit().toStdString().size() == 0) {
						newtool.Over_length = (double)0;
					}
					else newtool.Over_length = ui.table_header->item(i, j)->text().toLocal8Bit().toDouble();
					break;
				case 5:
					if (ui.table_header->item(i, j)->text().toLocal8Bit().toStdString().size() == 0) {
						newtool.current_tool_theoretical_diameter = (double)0;
					}
					else newtool.current_tool_theoretical_diameter = ui.table_header->item(i, 5)->text().toLocal8Bit().toDouble();
					break;

				case 6:
					if (ui.table_header->item(i, j)->text().toLocal8Bit().toStdString().size() == 0) {
						newtool.value_of_R = (double)0;
					}
					else newtool.value_of_R = ui.table_header->item(i, j)->text().toLocal8Bit().toDouble();
					/*	if (ui.table_header->item(i, j) == NULL) {
							newtool.Corner_radius = (double)-1.0;
						}
						else newtool.Corner_radius = ui.table_header->item(i, 6)->text().toLocal8Bit().toDouble();*/
					break;

				case 7:
					if (ui.table_header->item(i, j)->text().toLocal8Bit().toStdString().size() == 0) {
						newtool.tool_length_wear_up_value = (double)0;

					}
					else newtool.tool_length_wear_up_value = ui.table_header->item(i, j)->text().toLocal8Bit().toDouble();
					break;
				case 8:
					if (ui.table_header->item(i, j)->text().toLocal8Bit().toStdString().size() == 0) {
						newtool.tool_length_wear_down_value = (double)0;

					}
					else newtool.tool_length_wear_down_value = ui.table_header->item(i, j)->text().toLocal8Bit().toDouble();
					break;
				case 9:
					if (ui.table_header->item(i, j)->text().toLocal8Bit().toStdString().size() == 0) {
						newtool.tool_diameter_wear_up_value = (double)0;

					}
					else newtool.tool_diameter_wear_up_value = ui.table_header->item(i, j)->text().toLocal8Bit().toDouble();
					break;
				case 10:
					if (ui.table_header->item(i, j)->text().toLocal8Bit().toStdString().size() == 0) {
						newtool.tool_diameter_wear_down_value = (double)0;

					}
					else newtool.tool_diameter_wear_down_value = ui.table_header->item(i, j)->text().toLocal8Bit().toDouble();
					break;
				case 11:
					if (ui.table_header->item(i, j)->text().toLocal8Bit().toStdString().size() == 0) {
						newtool.tool_over_length_up_wear = (double)0;

					}
					else newtool.tool_over_length_up_wear = ui.table_header->item(i, j)->text().toLocal8Bit().toDouble();
					break;
				case 12:
					if (ui.table_header->item(i, j)->text().toLocal8Bit().toStdString().size() == 0) {
						newtool.tool_over_length_down_wear = (double)0;

					}
					else newtool.tool_over_length_down_wear = ui.table_header->item(i, j)->text().toLocal8Bit().toDouble();
					break;
				case 13:
					if (ui.table_header->item(i, j)->text().toLocal8Bit().toStdString().size() == 0) {
						newtool.tool_holder_diamater_up_wear = (double)0;

					}
					else newtool.tool_holder_diamater_up_wear = ui.table_header->item(i, j)->text().toLocal8Bit().toDouble();
					break;
				case 14:
					if (ui.table_header->item(i, j)->text().toLocal8Bit().toStdString().size() == 0) {
						newtool.tool_holder_diamater_down_wear = (double)0;

					}
					else newtool.tool_holder_diamater_down_wear = ui.table_header->item(i, j)->text().toLocal8Bit().toDouble();
					break;
				case 15:
					if (ui.table_header->item(i, j)->text().toLocal8Bit().toStdString().size() == 0) {
						newtool.tool_holder_length_up_wear = (double)0;

					}
					else newtool.tool_holder_length_up_wear = ui.table_header->item(i, j)->text().toLocal8Bit().toDouble();
					break;
					break;
				case 16:
					if (ui.table_header->item(i, j)->text().toLocal8Bit().toStdString().size() == 0) {
						newtool.tool_holder_length_down_wear = (double)0;

					}
					else newtool.tool_holder_length_down_wear = ui.table_header->item(i, j)->text().toLocal8Bit().toDouble();
					break;
				default:
					break;
				}
			}
			if (flag_input == true) {
				//cout << flag_input;
				//cout << newtool.current_tool_num << endl;
				//NewMess[newtool.current_tool_num] = newtool;
				exist_newMess.insert(make_pair(newtool.current_tool_num, newtool));
			}

			//NewMess.insert(make_pair(newtool.current_tool_num, newtool));// [newtool.id] = newtool;
		}

		//д��

		for (auto it = exist_newMess.begin(); it != exist_newMess.end(); ++it) {
			oFile << to_string(it->second.current_tool_num) << ","
				<< to_string(it->second.current_tool_type_ID) << ","
				<< it->second.Handle_number << ","
				<< it->second.tool_type << ","
				<< to_string(it->second.Over_length) << ","
				<< to_string(it->second.current_tool_theoretical_diameter) << ","
				<< to_string(it->second.value_of_R) << ","							//7
				

				<< to_string(it->second.tool_length_wear_up_value) << ","
				<< to_string(it->second.tool_length_wear_down_value) << ","
				<< to_string(it->second.tool_diameter_wear_up_value) << ","
				<< to_string(it->second.tool_diameter_wear_down_value) << ","
				<< to_string(it->second.tool_over_length_up_wear) << ","
				<< to_string(it->second.tool_over_length_down_wear) << ","
				<< to_string(it->second.tool_holder_diamater_up_wear) << ","
				<< to_string(it->second.tool_holder_diamater_down_wear) << ","
				<< to_string(it->second.tool_holder_length_up_wear) << ","
				<< to_string(it->second.tool_holder_length_down_wear) << endl;      //10
		}
		break;
	default:
		break;
	}

	oFile.close();

	string tmp = "���ݸ������";
	output_mess(tmp);

}

//
//void Read_Html::Query_push() {
//	QString str = ui.lineEdit->text();
//
//	int size = str.toStdString().size();
//	for (int i = 0; i < size; ++i) {
//		if (!isdigit(str.toStdString()[i])) {
//			string tmp = "������������";
//			output_mess(tmp);
//			return;
//		}
//	}
//
//	if(Query_Data(stoi(str.toStdString()))==0)
//	cout << query_tool.current_tool_num << " " << query_tool.Handle_number << endl;
//	
//}
//
//int Read_Html::Query_Data(string str) {
//	obj_init();
//	int k = 0;
//	if (!NewMess.empty()) {
//		auto it = NewMess.find(str);
//		if (it != NewMess.end()) {
//			
//			/*	ui.table_content->setItem(k, 0, new QTableWidgetItem(QString::number(it->second.current_tool_num)));
//				ui.table_content->item(k, 0)->setTextAlignment(Qt::AlignCenter);
//				ui.table_content->setItem(k, 1, new QTableWidgetItem(QString::fromLocal8Bit(it->second.Handle_number.data())));
//				ui.table_content->item(k, 1)->setTextAlignment(Qt::AlignCenter);
//				ui.table_content->setItem(k, 2, new QTableWidgetItem(QString::number(it->second.Over_length, 'f', 4)));
//				ui.table_content->item(k, 2)->setTextAlignment(Qt::AlignCenter);
//				ui.table_content->setItem(k, 3, new QTableWidgetItem(QString::number(it->second.D_Arbor, 'f', 4)));
//				ui.table_content->item(k, 3)->setTextAlignment(Qt::AlignCenter);
//				ui.table_content->setItem(k, 4, new QTableWidgetItem(QString::number(it->second.current_tool_theoretical_diameter, 'f', 4)));
//				ui.table_content->item(k, 4)->setTextAlignment(Qt::AlignCenter);
//				ui.table_content->setItem(k, 5, new QTableWidgetItem(QString::number(it->second.value_of_R, 'f', 4)));
//				ui.table_content->item(k, 5)->setTextAlignment(Qt::AlignCenter);
//				ui.table_content->setItem(k, 6, new QTableWidgetItem(QString::number(it->second.Blade_length, 'f', 4)));
//				ui.table_content->item(k, 6)->setTextAlignment(Qt::AlignCenter);
//				ui.table_content->setItem(k, 7, new QTableWidgetItem(QString::number(it->second.Tool_length, 'f', 4)));
//				ui.table_content->item(k, 7)->setTextAlignment(Qt::AlignCenter);
//				ui.table_content->setItem(k, 8, new QTableWidgetItem(QString::number(it->second.current_tool_type_ID)));
//				ui.table_content->item(k, 8)->setTextAlignment(Qt::AlignCenter);
//				ui.table_content->setItem(k, 9, new QTableWidgetItem(QString::number(it->second.height_of_measure_diameter, 'f', 4)));
//				ui.table_content->item(k, 9)->setTextAlignment(Qt::AlignCenter);
//				ui.table_content->setItem(k, 10, new QTableWidgetItem(QString::number(it->second.tool_diameter_at_lowest_point, 'f', 4)));
//				ui.table_content->item(k, 10)->setTextAlignment(Qt::AlignCenter);
//				ui.table_content->setItem(k, 11, new QTableWidgetItem(QString::number(it->second.num_of_blades)));
//				ui.table_content->item(k, 11)->setTextAlignment(Qt::AlignCenter);
//				ui.table_content->setItem(k, 12, new QTableWidgetItem(QString::number(it->second.tool_length_wear_up_value, 'f', 4)));
//				ui.table_content->item(k, 12)->setTextAlignment(Qt::AlignCenter);
//				ui.table_content->setItem(k, 13, new QTableWidgetItem(QString::number(it->second.tool_length_wear_down_value, 'f', 4)));
//				ui.table_content->item(k, 13)->setTextAlignment(Qt::AlignCenter);
//				ui.table_content->setItem(k, 14, new QTableWidgetItem(QString::number(it->second.tool_diameter_wear_up_value, 'f', 4)));
//				ui.table_content->item(k, 14)->setTextAlignment(Qt::AlignCenter);
//				ui.table_content->setItem(k, 15, new QTableWidgetItem(QString::number(it->second.tool_diameter_wear_down_value, 'f', 4)));
//				ui.table_content->item(k, 15)->setTextAlignment(Qt::AlignCenter);
//				ui.table_content->setItem(k, 16, new QTableWidgetItem(QString::number(it->second.tool_tipping_value, 'f', 4)));
//				ui.table_content->item(k, 16)->setTextAlignment(Qt::AlignCenter);
//				ui.table_content->setItem(k, 17, new QTableWidgetItem(QString::number(it->second.tool_contour_wear_value, 'f', 4)));
//				ui.table_content->item(k, 17)->setTextAlignment(Qt::AlignCenter);
//				ui.table_content->setItem(k, 18, new QTableWidgetItem(QString::number(it->second.measure_frequence, 'f', 4)));
//				ui.table_content->item(k, 18)->setTextAlignment(Qt::AlignCenter);
//				ui.table_content->setItem(k, 19, new QTableWidgetItem(QString::number(it->second.system_length_offset_value, 'f', 4)));
//				ui.table_content->item(k, 19)->setTextAlignment(Qt::AlignCenter);
//				ui.table_content->setItem(k, 20, new QTableWidgetItem(QString::number(it->second.system_diameter_offset_value, 'f', 4)));
//				ui.table_content->item(k, 20)->setTextAlignment(Qt::AlignCenter);*/
//
//			//string tmp = "�ҵ�" + to_string(str) + "�ŵ�����Ϣ";
//			//output_mess(tmp);
//			query_tool = it->second;
//			return 0;
//		}
//		else {
//			//string tmp = "δ�ҵ�" + to_string(str) + "�ŵ�����Ϣ";
//			//output_mess(tmp);
//		}
//	}
//	else if (NewMess.empty()&&(!OldMess.empty())) {
//	string tmp = "��������ݺ��ٲ�ѯ";
//	output_mess(tmp);
//	
//	}
//	else {
//	//string tmp = "δ�ҵ�" + to_string(str) + "�ŵ�����Ϣ";
//	//output_mess(tmp);
//	}
//
//	ui.table_content->setItem(k, 0, new QTableWidgetItem(QString::fromLocal8Bit("")));
//	ui.table_content->item(k, 0)->setTextAlignment(Qt::AlignCenter);
//	ui.table_content->setItem(k, 1, new QTableWidgetItem(QString::fromLocal8Bit("")));
//	ui.table_content->item(k, 1)->setTextAlignment(Qt::AlignCenter);
//	ui.table_content->setItem(k, 2, new QTableWidgetItem(QString::fromLocal8Bit("")));
//	ui.table_content->item(k, 2)->setTextAlignment(Qt::AlignCenter);
//	ui.table_content->setItem(k, 3, new QTableWidgetItem(QString::fromLocal8Bit("")));
//	ui.table_content->item(k, 3)->setTextAlignment(Qt::AlignCenter);
//	ui.table_content->setItem(k, 4, new QTableWidgetItem(QString::fromLocal8Bit("")));
//	ui.table_content->item(k, 4)->setTextAlignment(Qt::AlignCenter);
//	ui.table_content->setItem(k, 5, new QTableWidgetItem(QString::fromLocal8Bit("")));
//	ui.table_content->item(k, 5)->setTextAlignment(Qt::AlignCenter);
//	ui.table_content->setItem(k, 6, new QTableWidgetItem(QString::fromLocal8Bit("")));
//	ui.table_content->item(k, 6)->setTextAlignment(Qt::AlignCenter);
//	ui.table_content->setItem(k, 7, new QTableWidgetItem(QString::fromLocal8Bit("")));
//	ui.table_content->item(k, 7)->setTextAlignment(Qt::AlignCenter);
//	ui.table_content->setItem(k, 8, new QTableWidgetItem(QString::fromLocal8Bit("")));
//	ui.table_content->item(k, 8)->setTextAlignment(Qt::AlignCenter);
//	ui.table_content->setItem(k, 9, new QTableWidgetItem(QString::fromLocal8Bit("")));
//	ui.table_content->item(k, 9)->setTextAlignment(Qt::AlignCenter);
//	ui.table_content->setItem(k, 10, new QTableWidgetItem(QString::fromLocal8Bit("")));
//	ui.table_content->item(k, 10)->setTextAlignment(Qt::AlignCenter);
//	ui.table_content->setItem(k, 11, new QTableWidgetItem(QString::fromLocal8Bit("")));
//	ui.table_content->item(k, 11)->setTextAlignment(Qt::AlignCenter);
//	ui.table_content->setItem(k, 12, new QTableWidgetItem(QString::fromLocal8Bit("")));
//	ui.table_content->item(k, 12)->setTextAlignment(Qt::AlignCenter);
//	ui.table_content->setItem(k, 13, new QTableWidgetItem(QString::fromLocal8Bit("")));
//	ui.table_content->item(k, 13)->setTextAlignment(Qt::AlignCenter);
//	ui.table_content->setItem(k, 14, new QTableWidgetItem(QString::fromLocal8Bit("")));
//	ui.table_content->item(k, 14)->setTextAlignment(Qt::AlignCenter);
//	ui.table_content->setItem(k, 15, new QTableWidgetItem(QString::fromLocal8Bit("")));
//	ui.table_content->item(k, 15)->setTextAlignment(Qt::AlignCenter);
//	ui.table_content->setItem(k, 16, new QTableWidgetItem(QString::fromLocal8Bit("")));
//	ui.table_content->item(k, 16)->setTextAlignment(Qt::AlignCenter);
//	ui.table_content->setItem(k, 17, new QTableWidgetItem(QString::fromLocal8Bit("")));
//	ui.table_content->item(k, 17)->setTextAlignment(Qt::AlignCenter);
//	ui.table_content->setItem(k, 18, new QTableWidgetItem(QString::fromLocal8Bit("")));
//	ui.table_content->item(k, 18)->setTextAlignment(Qt::AlignCenter);
//	ui.table_content->setItem(k, 19, new QTableWidgetItem(QString::fromLocal8Bit("")));
//	ui.table_content->item(k, 19)->setTextAlignment(Qt::AlignCenter);
//	ui.table_content->setItem(k, 20, new QTableWidgetItem(QString::fromLocal8Bit("")));
//	ui.table_content->item(k, 20)->setTextAlignment(Qt::AlignCenter);
//	return -1;
//}
//



//�����ʾ��Ϣ
void Read_Html::output_mess(string tmp) {
	ui.textEdit->append(QString::fromStdString(tmp));

}

//��������
void Read_Html::Import_push() {
	Read_html();

}


Read_Html::~Read_Html() {
	OldMess.clear();
	NewMess.clear();

}

//����Ļ
void Read_Html::Screen_Clear() {
	OldMess.clear();
	NewMess.clear();
	exist_oldMess.clear();
	exist_newMess.clear();
	//������ݺͱ�ͷ
	//ui.table_header->clear();
	//ֻ������ݣ��������ͷ
	ui.table_header->clearContents();
	if (ui.table_header->rowCount() > 25) {
		for (int row = ui.table_header->rowCount() - 26; row >= 0; row--)
		{
			ui.table_header->removeRow(row);
		}
	}


	//NewMess.clear();

	//ui.table_content->clearContents();
	//if (ui.table_content->rowCount() >= 5) {
	//	if (ui.table_header->rowCount() > 26) {
	//		for (int row = ui.table_content->rowCount()-6; row >= 0; row--)
	//		{
	//			ui.table_content->removeRow(row);
	//		}
	//	}
	//}
	//ui.lineEdit->clear();
	string tmp = "�������";
	output_mess(tmp);
}



//
//
//void Read_Html::obj_init() {
//	query_tool.current_tool_num;                                          //���ߺ�0
//	query_tool.Handle_number;				                           //�������	1
//	query_tool.tool_type=-1;														//���߱��2
//	query_tool.Over_length;					                           //����	3
//	query_tool.current_tool_theoretical_diameter;				       //����ֱ��	4
//	query_tool.value_of_R;					                           //����뾶	5
//
//	query_tool.current_tool_type_ID;                                      //��������ʶ����  6
//	query_tool.tool_length_wear_up_value;//#140                              //����������ƫ��7
//	query_tool.tool_length_wear_down_value; //#141                           //����������ƫ��8
//	query_tool.tool_diameter_wear_up_value; //#142                          //����������ƫ��9
//	query_tool.tool_diameter_wear_down_value; //#143                        //����������ƫ��10
//
//	query_tool.tool_over_length_up_wear;//194                                //���쳤������ƫ��11
//	query_tool.tool_over_length_down_wear;//195                              //���쳤������ƫ��12
//	query_tool.tool_holder_diamater_up_wear;//196                            //����ֱ��������ƫ��13
//	query_tool.tool_holder_diamater_down_wear;//197                          //����ֱ��������ƫ��14
//	query_tool.tool_holder_length_up_wear;//198                              //�������ȷ�����ƫ��15
//	query_tool.tool_holder_length_down_wear;//199                            //�������ȷ�����ƫ��16
//	
//	
//	query_tool.current_tool_theoretical_diameter = 0;
//	query_tool.value_of_R = 0;
//	query_tool.Blade_length = 0;
//	query_tool.Tool_length = 0;
//	query_tool.current_tool_type_ID = 0;
//	query_tool.height_of_measure_diameter = 0;
//	query_tool.tool_diameter_at_lowest_point = 0;
//	query_tool.num_of_blades = 0;
//	query_tool.tool_length_wear_up_value = 0;
//	query_tool.tool_length_wear_down_value = 0;
//	query_tool.tool_diameter_wear_up_value = 0;
//	query_tool.tool_diameter_wear_down_value = 0;
//	query_tool.tool_tipping_value = 0;
//	query_tool.tool_contour_wear_value = 0;
//	query_tool.measure_frequence = 0;
//	query_tool.system_length_offset_value = 0;
//	query_tool.system_diameter_offset_value = 0;
//}