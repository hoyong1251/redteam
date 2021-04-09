#include "Income.h"
#define _T(x) x

cashData::cashData()//���� ����� ����, ���� ���� �����ڷ� �Ѱܹ޾ƾ���
{
	isDataSetting = false;
	isSharedCashBook = false;
	//current_cashbook = CashBook
	//current_user = User
}

void cashData::menu(bool isSharedCashBook)
{
	int select;
	if (!isSharedCashBook) { // false - ���� �����
		while (1)
		{
			//user_id ���
			//cashbook_name ���
			isDataSetting = false;
			cout << "1. �Һ�" << endl;
			cout << "2. ����" << endl;
			cout << "3. ��ȸ" << endl;
			cout << "4. �ڷΰ���" << endl;
			cin >> select;
			if (select == 1)
				Pay* pay = new Pay();//user.id �����ڷ� �Ѱ������
			else if (select == 2)
				Income* income = new Income();
			else if (select == 3)
				cout << "3 ��ȸ";
			else if (select == 4)
				break;
			else
			{
				cout << "�ٽ� �Է����ּ���" << endl;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
		}
	}
	else { // true - ���� �����
		while (1)
		{
			//user_id ���
			//cashbook_name ���
			cout << "0.������ ����" << endl;
			cout << "1. �Һ�" << endl;
			cout << "2. ����" << endl;
			cout << "3. ��ȸ" << endl;
			cout << "4.����� ����" << endl;
			cout << "5. �ڷΰ���" << endl;
			cin >> select;
			//����ó�� �ʿ� "a"
			if (select == 1)
				Pay* pay = new Pay();
			else if (select == 2)
				Income* income = new Income();
			else if (select == 3) {
				cout << "3 ��ȸ";
			}
			else if (select == 4) {
				cout << "4 ����� ����";
			}
			else if (select == 5) {
				break;
			}
			else
			{
				cout << "����ó��" << endl;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
		}
	}
}
vector<string> cashData::data_split1()
{
	vector<string> result;
	while (1) {
		string str;
		cout << ">>> ";
		getline(cin, str);
		if (isquit(str)) break;
		int count = -1;
		int slash = 0;
		for (int i = 0; i < str.size(); i++)
			if (str[i] == '/')
				slash++;        //���� �߰�
		vector<string> first = split(str, '/');
		vector<string>second(4);
		vector<string>third(4);
		string chars_to_trim1 = " ";
		string chars_to_trim2 = "\n";
		string chars_to_trim3 = "\t";
		string chars_to_trim4 = "\v";
		string chars_to_trim5 = "\f";
		string chars_to_trim6 = "\r";
		for (int i = 0; i < first.size(); i++)
			trimString(first[i], chars_to_trim1);
		for (int i = 0; i < first.size(); i++)
			trimString(first[i], chars_to_trim2);
		for (int i = 0; i < first.size(); i++)
			trimString(first[i], chars_to_trim3);
		for (int i = 0; i < first.size(); i++)
			trimString(first[i], chars_to_trim4);
		for (int i = 0; i < first.size(); i++)
			trimString(first[i], chars_to_trim5);//�����߰�
		for (int i = 0; i < first.size(); i++)
			trimString(first[i], chars_to_trim6);//�����߰�
		// ���� �� �� ��� ���� �ڸ���
		if (first.size() == 3) {
			for (int i = 0; i < first.size(); i++)
				second[i] = first[i];
			second[3] = "";
		}
		else if (first.size() == 4) {
			for (int i = 0; i < first.size(); i++)
				second[i] = first[i];
		}                                          //second�� first����                                                 

		for (int i = 0; i < second.size(); i++)
			third[i] = second[i];
		//third�� second�� ���� �� ���� ���� �� �����͸� ����
		for (int i = 0; i < second.size() - 1; i++)
			second[i].erase(std::remove(second[i].begin(), second[i].end(), ' '), second[i].end());
		for (int i = 0; i < second.size() - 1; i++)
			second[i].erase(std::remove(second[i].begin(), second[i].end(), '\n'), second[i].end());
		for (int i = 0; i < second.size() - 1; i++)
			second[i].erase(std::remove(second[i].begin(), second[i].end(), '\t'), second[i].end());
		for (int i = 0; i < second.size() - 1; i++)
			second[i].erase(std::remove(second[i].begin(), second[i].end(), '\v'), second[i].end());
		for (int i = 0; i < second.size() - 1; i++)
			second[i].erase(std::remove(second[i].begin(), second[i].end(), '\f'), second[i].end());
		for (int i = 0; i < second.size() - 1; i++)
			second[i].erase(std::remove(second[i].begin(), second[i].end(), '\r'), second[i].end());

		//second���ִ� ������ ������ ���� ���ֱ�

		for (int i = 0; i < second.size() - 1; i++) {
			if (third[i] != second[i]) {
				count = i;
				break;
			}
		}



	//	for (int i = 0; i < second.size(); i++) {
			if (second[0] == "" || second[1] == "" || second[2] == "")
			{
				printf("������ ���� �����Դϴ�.\n");
				break;
			}
			if (slash == 3 && first.size() == 3)
			{
				printf("������ �������� �ʿ����");
				break;
			}//�����߰�
			if (count >= 0) {
				if (count == 0) {
					printf("��¥ ���� ��� ����\n");
					break;
				}
				if (count == 1) {
					printf("�ݾ�  ���� ��� ����\n");
					break;
				}
				if (count == 2) {
					printf("ī�װ��� ���� ��� ����\n");
					break;
				}
			}



			//else if (i == 0) {
			//	cout << "��¥: " + second[0] + "'" << "\n";
				result.push_back(second[0]);
			//}
			//else if (i == 1) {
			//	cout << "�ݾ�: " + second[1] + "'" << "\n";
				result.push_back(second[1]);
			//}
			//else if (i == 2) {
			//	cout << "ī�װ���: " + second[2] + "'" << "\n";
				result.push_back(second[2]);
			//}
			//else if (i == 3) {
			//	if (second[3] == "") {
			//		cout << "����: ����" << "\n";
			//		second[3] = '*';

			//	}
			//	else
			//		cout << "����: " + second[3] + "'" << "\n";
				result.push_back(second[3]);

			//}

		//}//for�� ��
				break;

		if (second[0] != "" && second[1] != "" && second[2] != "" && second[3] != "" && second[0] == third[0] && second[1] == third[1] && second[2] == third[2])
			break;
	}
	return result;

}

vector<string> cashData::data_split2()
{
	vector<string>result;

	while (1) {
		string str;
		getline(cin, str);
		if (isquit(str)) break;
		int count = -1;
		int slash = 0;

		for (int i = 0; i < str.size(); i++)
			if (str[i] == '/')
				slash++;        //���� �߰�
		vector<string> first = split(str, '/');
		vector<string>second(3);
		vector<string>third(3);
		string chars_to_trim1 = " ";
		string chars_to_trim2 = "\n";
		string chars_to_trim3 = "\t";
		string chars_to_trim4 = "\v";
		string chars_to_trim5 = "\f";
		string chars_to_trim6 = "\r";
		for (int i = 0; i < first.size(); i++)
			trimString(first[i], chars_to_trim1);
		for (int i = 0; i < first.size(); i++)
			trimString(first[i], chars_to_trim2);
		for (int i = 0; i < first.size(); i++)
			trimString(first[i], chars_to_trim3);
		for (int i = 0; i < first.size(); i++)
			trimString(first[i], chars_to_trim4);
		for (int i = 0; i < first.size(); i++)
			trimString(first[i], chars_to_trim5);//�����߰�
		for (int i = 0; i < first.size(); i++)
			trimString(first[i], chars_to_trim6);//�����߰�
		// ���� �� �� ��� ���� �ڸ���
		if (first.size() == 3) {
			for (int i = 0; i < first.size(); i++)
				second[i] = first[i];

		}                                         //second�� first����                                                 


		for (int i = 0; i < second.size(); i++)
			third[i] = second[i];

		//third�� second�� ���� �� ���� ���� �� �����͸� ����
		for (int i = 0; i < second.size() - 1; i++)
			second[i].erase(std::remove(second[i].begin(), second[i].end(), ' '), second[i].end());
		for (int i = 0; i < second.size() - 1; i++)
			second[i].erase(std::remove(second[i].begin(), second[i].end(), '\n'), second[i].end());
		for (int i = 0; i < second.size() - 1; i++)
			second[i].erase(std::remove(second[i].begin(), second[i].end(), '\t'), second[i].end());
		for (int i = 0; i < second.size() - 1; i++)
			second[i].erase(std::remove(second[i].begin(), second[i].end(), '\v'), second[i].end());
		for (int i = 0; i < second.size() - 1; i++)
			second[i].erase(std::remove(second[i].begin(), second[i].end(), '\f'), second[i].end());
		for (int i = 0; i < second.size() - 1; i++)
			second[i].erase(std::remove(second[i].begin(), second[i].end(), '\r'), second[i].end());

		//second���ִ� ������ ������ ���� ���ֱ�

		for (int i = 0; i < second.size() - 1; i++) {
			if (third[i] != second[i]) {
				count = i;
				break;
			}
		}



		//for (int i = 0; i < second.size(); i++) {
			if (second[0] == "" || second[1] == "" || second[2] == "")
			{
				printf("������ ���� �����Դϴ�.\n");
				break;
			}

			if (count >= 0) {
				if (count == 0) {
					printf("���۳�¥ ���� ��� ����\n");
					break;
				}
				if (count == 1) {
					printf("���ᳯ¥  ���� ��� ����\n");
					break;
				}

			}
			result.push_back(second[0]);
			result.push_back(second[1]);
			result.push_back(second[2]);

		//}
		//cout << second[2] << "\n";
		break;


	}
	return result;
}



bool cashData::keyword_search(string startdate, string enddate, string data)
{
	int matching_count = 0, matching_sub = 0;
	int matched_index[10]; //�ִ� �˻� ��� ���� ���� �ʿ� (��ȹ�� �������)
	int s_sub, e_sub;
	s_sub = stoi(startdate.substr(0, 4) + startdate.substr(5, 2) + startdate.substr(8, 2));
	e_sub = stoi(enddate.substr(0, 4) + enddate.substr(5, 2) + enddate.substr(8, 2));
	string chars_to_trim1 = " ";
	string chars_to_trim2 = "\n";
	string chars_to_trim3 = "\t";
	string chars_to_trim4 = "\v";
	string chars_to_trim5 = "\f";
	string chars_to_trim6 = "\r";
	// ���� �� �� ��� ���� �ڸ���

		for (int i = 0; i < data.size(); i++)
			trimString(data, chars_to_trim1);
		for (int i = 0; i < data.size(); i++)
			trimString(data, chars_to_trim2);
		for (int i = 0; i < data.size(); i++)
			trimString(data, chars_to_trim3);
		for (int i = 0; i < data.size(); i++)
			trimString(data, chars_to_trim4);
		for (int i = 0; i < data.size(); i++)
			trimString(data, chars_to_trim5);//�����߰�
		for (int i = 0; i < data.size(); i++)
			trimString(data, chars_to_trim6);//�����߰�

		if (data == "") {
			cout << "���鸸���δ� �˻� �Ұ���" << endl;
			return false;
		}
		else
		{
			cout << endl << "<�˻� ���>" << endl;
			for (int k = 0; k < file_data.size(); k++) {
				if (file_data[k].find(data) >= 0 && file_data[k].find(data) < file_data[k].size())
				{
					matching_sub = stoi(file_data[k].substr(0, 4) + file_data[k].substr(5, 2) + file_data[k].substr(8, 2));
					if (matching_sub >= s_sub && matching_sub <= e_sub) {
						matched_index[matching_count++]=k;
						cout << matching_count << ". " << file_data[k] << endl;
					}
				}
			}
			
			if (matching_count == 0) {
				cout << "�����Ͱ� �����ϴ�. " << endl;
				return false;
			}
			else {
				int select;
				cout << ">>> ";
				cin >> select;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "���� �Ͻðڽ��ϱ�? ";
				if (yesorno()) {
					//yes
					file_data[matched_index[select - 1]].clear();
					reWriteTextFile("test.txt");
					cout << "������ �Ϸ�Ǿ����ϴ�." << endl;
				}
				else {
					cout << "�������� �ʽ��ϴ�." << endl;
				}
				//y��� rewrite 
				//n�̶�� �׳� ����
				//y��� �ε��� ã�� ���� ����
				//file_data[select - 1].clear();
				//n�̶�� �׳� ����
				return true;
			}
			
		}

	
}

bool isLeapyear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return true;
	return false;
}

bool cashData::date_test(string& data)
{
	int year=0,month=0,day=0;
	cout << "date testing ";
//	cin >> data;
	//�׽�Ʈ�� �Ű����� ��ü
	regex ex1("(\\d{2})-(\\d{2})-(\\d{2})");
	regex ex2("(\\d{4})-(\\d{2})-(\\d{2})");
	smatch matches;

	if (regex_match(data, matches, ex1)) {
		//���� 2�ڸ� ��Ī
		year = stoi(matches[1]);
		month = stoi(matches[2]);
		day = stoi(matches[3]);
		if (year <= 99 && year >= 70)
			year += 1900;
		else if (year <= 69 && year >= 0)
			year += 2000;
		else {
			printdate_err();
			return false;
		}
		data = to_string(year) + "-" + (string)matches[2] + "-" + (string)matches[3];
	}
	else if (regex_match(data, matches, ex2)) {
		//���� 4�ڸ� ��Ī
		year = stoi(matches[1]);
		if (year == 0){
			printdate_err();
			return false;
		}
		else if (year < 1900 || year > 2100) {
			printdate_err();
			return false;
		}
		month = stoi(matches[2]);
		day = stoi(matches[3]);
	}
	else {
		cout << "date matching fail" << endl;
		printdate_err();
		return false;
	}

	//�⺻ ��¥ �˻�
	if (month <= 0 || month > 12) {
		printdate_err();
		return false;
	}
	if (day <= 0 || day > 31) {
		printdate_err();
		return false;
	}

	//���Խ� ��� �� ����˻�
		switch (month)
		{
		case 4:
		case 6:
		case 9:
		case 11:
			if (day == 31) {
				printdate_err();
				return false;
			}
			break;
		case 2:
			if (isLeapyear(year)) {//�����̸�
				if (day == 30 || day == 31) {
					printdate_err();
					return false;
				}
			}
			else {//������ �ƴϸ� 
				if (day == 29 || day == 30 || day == 31) {
					printdate_err();
					return false;
				}
			}
			break;
		default:
			break;
		}
	
	//result = to_string(year) + "-" + (string)matches[2] + "-" + (string)matches[3];
	//cout << "result " << result << endl;
	return true;
}

bool cashData::price_test(string& data)
{
	//string data;
	//string result;
	//�׽�Ʈ�� �Ű������� ��ü
	cout << "price testing ";
	//cin >> data;
	regex ex1("([1-9]{1})(\\d{0,2})([,]?)(\\d{0,3})([,]?)(\\d{0,3})");
	smatch matches;

	if (regex_match(data, matches, ex1)) {
	

		if (matches[3] == "," && matches[5] == ",") {
			if (is3digit(matches[4]) && is3digit(matches[6]))
				data = (string)matches[1] + (string)matches[2] + (string)matches[4] + (string)matches[6];
			else {
				printprice_err();
				return false;
			}
		}
		else if (matches[3] == "," && !(matches[5]==",")) {
			if (is3digit(matches[4]) && matches[6]=="")
				data = (string)matches[1] + (string)matches[2] + (string)matches[4];
			else {
				printprice_err();
				return false;
			}
		}
		else if (!(matches[3] == ",") && matches[5] == ",") {
			if (matches[4] == "" && is3digit(matches[6]))
				data = (string)matches[1] + (string)matches[2] + (string)matches[6];
			else {
				printprice_err();
				return false;
			}
		}
		else {
			if (matches[4] == "" && matches[6] == "") {
				int num = stoi((string)matches[1] + (string)matches[2]);
				if (num < 100) {
					printprice_err();
					return false;
				}
				data = (string)matches[1] + (string)matches[2];
			}
			else {
				printprice_err();
				return false;
			}
		}
	}
	else {
		printprice_err();
		cout << "price matching fail" << endl;
		return false;
	}
	//cout << result << endl;
	return true;
}

bool cashData::memo_test(string data)
{
	//string data = "a��b kkk ��c��";
	//�Ű����� data
	cout << "memo testing "<<endl;
	//string result;
	char* sub_str = new char[10]{ "" };
	int k = 0;
	int count = 0;
	for (int i = 0; i < (int)(data.size()); i++) {
		if (data[i] & 0x80) {
		//	han_index[k] = i;//������ ���� �ε��� ����
			i++;  // �ѱ��� 2����Ʈ�̱� ������ 1����Ʈ �� ������Ŵ
		//	cout <<"�ѱ� �и�"<<data.substr(han_index[k],2) << "|";
		//	k++;
			count++;
		}
		else {
			 //cout << "���� �и�" << data[i] << "|";
			sub_str[k] = data[i];
			k++;
			count++;
		}
		sub_str[k] = '\0';
	}
	if (count > 10) {
		//cout << "����: "<<count << endl;
		printmemo_err();
		return false;
	}
	if (data == "") return true;
	string nohanguel = sub_str;
	//������ �̷���� ���ڿ� ���Խ� �˻�
	regex ex("[a-zA-Z0-9\\s]*");
	smatch matches;
	if (regex_match(nohanguel,matches,ex))
	{
	//	result = data;
	//	cout << "result :" << result<<endl;
		return true;
	}
	else {
		cout << "memo matching fail" << endl;
		printmemo_err();
		return false;
	}
}



bool cashData::date_validation(string& startdate, string& enddate)
{
	if (date_test(startdate) && date_test(enddate))
	{
		int s_sub,e_sub;
		s_sub= stoi(startdate.substr(0, 4) + startdate.substr(5, 2) + startdate.substr(8, 2));
		e_sub= stoi(enddate.substr(0, 4) + enddate.substr(5, 2) + enddate.substr(8, 2));
		if (s_sub <= e_sub)
			return true;
		else
			return false;
	}
	else {
		printdate_err();
		return false;
	}
}

bool cashData::is3digit(string data)
{
	regex ex1("(\\d{3})");
	smatch matches;
	if (regex_match(data, matches, ex1))
		return true;
	else
		return false;
}
void cashData::printprice_err()
{
		cout << "�ݾ� ���� ����"<<endl;
}
void cashData::printdate_err()
{
	cout << "��¥ ���� ���� " << endl;
}
void cashData::printmemo_err()
{
	cout << "���� ���� ����" << endl;
}


void cashData::readTextFile(string txt_name)
{
	file_data.clear();//file_data �ʱ�ȭ
	char readline[66];//�� �� �ִ� 2020-02-02/999999999/5*2/10*2/user_id = 10+9+10+20+12+4+\n = 66

	ifstream readFile;
	readFile.open(txt_name);
	if (readFile.is_open()) {

		while (!readFile.eof()) {
			readFile.getline(readline, 66);
			if (!readFile.eof())
				file_data.push_back(readline);
		}
	}
	else {
		cout << "file not open" << endl;
	}
	//for(int i=0; i<file_data.size(); i++)
	//	cout << file_data[i] << endl;
	//file_data.push_back("2022-10-01/1000/��Ÿ/*/ooozzz"); �׽�Ʈ��
	readFile.close();
}
wstring s2ws(const string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}
void cashData::writeTextFile(string txt_name,string data)
{
	wstring stemp = s2ws(txt_name);
	LPCWSTR result = stemp.c_str();
	ofstream writeFile;
	file_data.push_back(data);
	SetFileAttributes(_T(result), FILE_ATTRIBUTE_NORMAL);
	writeFile.open(txt_name, ofstream::out);
	if (writeFile.is_open()) {
		for (int i = 0; i < file_data.size(); i++)
		{
			file_data[i] = file_data[i] + "\n";
			writeFile.write(file_data[i].c_str(), file_data[i].size());
		}
		SetFileAttributes(_T(result), FILE_ATTRIBUTE_READONLY); //���� �ܺμ��� ����
	}
	else {
		cout << "file not open" << endl;
	}
	writeFile.close();
	file_data.clear(); //���� ������ ���� �ʱ�ȭ
}
void cashData::reWriteTextFile(string txt_name)
{
	wstring stemp = s2ws(txt_name);
	LPCWSTR result = stemp.c_str();
	ofstream writeFile;
	SetFileAttributes(_T(result), FILE_ATTRIBUTE_NORMAL);
	writeFile.open(txt_name, ofstream::out);
	if (writeFile.is_open()) {
		for (int i = 0; i < file_data.size(); i++)
		{
			if (file_data[i].empty()) {
				continue;
			}
			file_data[i] = file_data[i] + "\n";
			writeFile.write(file_data[i].c_str(), file_data[i].size());
		}
		SetFileAttributes(_T(result), FILE_ATTRIBUTE_READONLY); //���� �ܺμ��� ����
	}
	else {
		cout << "file not open" << endl;
	}
	writeFile.close();
	file_data.clear(); //���� ������ ���� �ʱ�ȭ
}


bool cashData::isquit(string& str) {
	if (str == "q")
		return true;
	else
		return false;
}
bool cashData::yesorno()
{		//true = y ,false = n
	string c = "";
	while (true) {
		cout << " Y(y) or N(n) : ";
		getline(cin, c);

		if (c == "Y" || c == "y") {
			return true;
		}
		else if (c == "N" || c == "n")
			return false;
		else
			cout << "�߸��� �����Դϴ�.\n" << endl;
	}
	return false;
}
vector<string> cashData::split(string input, char delimiter)
{
	vector<string> answer;
	stringstream ss(input);
	string temp;

	while (getline(ss, temp, delimiter)) {
		answer.push_back(temp);
	}

	return answer;
}
string& cashData::trimString(string& str, string& chars)
{
	return leftTrim(rightTrim(str, chars), chars);
}
string& cashData::rightTrim(string& str, string& chars)
{
	str.erase(str.find_last_not_of(chars) + 1);
	return str;
}
string& cashData::leftTrim(string& str, string& chars)
{
	str.erase(0, str.find_first_not_of(chars));
	return str;
}