#include "Income.h"
#define _T(x) x

cashData::cashData()//현재 가계부 정보, 유저 정보 생성자로 넘겨받아야함
{
	isDataSetting = false;
	isSharedCashBook = false;
	//current_cashbook = CashBook
	//current_user = User
}

void cashData::menu(bool isSharedCashBook)
{
	int select;
	if (!isSharedCashBook) { // false - 개인 가계부
		while (1)
		{
			//user_id 출력
			//cashbook_name 출력
			isDataSetting = false;
			cout << "1. 소비" << endl;
			cout << "2. 수입" << endl;
			cout << "3. 조회" << endl;
			cout << "4. 뒤로가기" << endl;
			cin >> select;
			if (select == 1)
				Pay* pay = new Pay();//user.id 생성자로 넘겨줘야함
			else if (select == 2)
				Income* income = new Income();
			else if (select == 3)
				cout << "3 조회";
			else if (select == 4)
				break;
			else
			{
				cout << "다시 입력해주세요" << endl;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
		}
	}
	else { // true - 공용 가계부
		while (1)
		{
			//user_id 출력
			//cashbook_name 출력
			cout << "0.관리자 설정" << endl;
			cout << "1. 소비" << endl;
			cout << "2. 수입" << endl;
			cout << "3. 조회" << endl;
			cout << "4.가계부 삭제" << endl;
			cout << "5. 뒤로가기" << endl;
			cin >> select;
			//오류처리 필요 "a"
			if (select == 1)
				Pay* pay = new Pay();
			else if (select == 2)
				Income* income = new Income();
			else if (select == 3) {
				cout << "3 조회";
			}
			else if (select == 4) {
				cout << "4 가계부 삭제";
			}
			else if (select == 5) {
				break;
			}
			else
			{
				cout << "예외처리" << endl;
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
				slash++;        //새로 추가
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
			trimString(first[i], chars_to_trim5);//새로추가
		for (int i = 0; i < first.size(); i++)
			trimString(first[i], chars_to_trim6);//새로추가
		// 각각 앞 뒤 모든 공백 자르기
		if (first.size() == 3) {
			for (int i = 0; i < first.size(); i++)
				second[i] = first[i];
			second[3] = "";
		}
		else if (first.size() == 4) {
			for (int i = 0; i < first.size(); i++)
				second[i] = first[i];
		}                                          //second에 first복사                                                 

		for (int i = 0; i < second.size(); i++)
			third[i] = second[i];
		//third에 second의 문자 내 공백 삭제 전 데이터를 저장
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

		//second에있는 데이터 사이의 공백 없애기

		for (int i = 0; i < second.size() - 1; i++) {
			if (third[i] != second[i]) {
				count = i;
				break;
			}
		}



	//	for (int i = 0; i < second.size(); i++) {
			if (second[0] == "" || second[1] == "" || second[2] == "")
			{
				printf("데이터 개수 오류입니다.\n");
				break;
			}
			if (slash == 3 && first.size() == 3)
			{
				printf("마지막 슬래쉬는 필요없음");
				break;
			}//새로추가
			if (count >= 0) {
				if (count == 0) {
					printf("날짜 공백 허용 안함\n");
					break;
				}
				if (count == 1) {
					printf("금액  공백 허용 안함\n");
					break;
				}
				if (count == 2) {
					printf("카테고리 공백 허용 안함\n");
					break;
				}
			}



			//else if (i == 0) {
			//	cout << "날짜: " + second[0] + "'" << "\n";
				result.push_back(second[0]);
			//}
			//else if (i == 1) {
			//	cout << "금액: " + second[1] + "'" << "\n";
				result.push_back(second[1]);
			//}
			//else if (i == 2) {
			//	cout << "카테고리: " + second[2] + "'" << "\n";
				result.push_back(second[2]);
			//}
			//else if (i == 3) {
			//	if (second[3] == "") {
			//		cout << "내용: 없음" << "\n";
			//		second[3] = '*';

			//	}
			//	else
			//		cout << "내용: " + second[3] + "'" << "\n";
				result.push_back(second[3]);

			//}

		//}//for문 끝
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
				slash++;        //새로 추가
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
			trimString(first[i], chars_to_trim5);//새로추가
		for (int i = 0; i < first.size(); i++)
			trimString(first[i], chars_to_trim6);//새로추가
		// 각각 앞 뒤 모든 공백 자르기
		if (first.size() == 3) {
			for (int i = 0; i < first.size(); i++)
				second[i] = first[i];

		}                                         //second에 first복사                                                 


		for (int i = 0; i < second.size(); i++)
			third[i] = second[i];

		//third에 second의 문자 내 공백 삭제 전 데이터를 저장
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

		//second에있는 데이터 사이의 공백 없애기

		for (int i = 0; i < second.size() - 1; i++) {
			if (third[i] != second[i]) {
				count = i;
				break;
			}
		}



		//for (int i = 0; i < second.size(); i++) {
			if (second[0] == "" || second[1] == "" || second[2] == "")
			{
				printf("데이터 개수 오류입니다.\n");
				break;
			}

			if (count >= 0) {
				if (count == 0) {
					printf("시작날짜 공백 허용 안함\n");
					break;
				}
				if (count == 1) {
					printf("종료날짜  공백 허용 안함\n");
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
	int matched_index[10]; //최대 검색 결과 개수 지정 필요 (기획서 수정요망)
	int s_sub, e_sub;
	s_sub = stoi(startdate.substr(0, 4) + startdate.substr(5, 2) + startdate.substr(8, 2));
	e_sub = stoi(enddate.substr(0, 4) + enddate.substr(5, 2) + enddate.substr(8, 2));
	string chars_to_trim1 = " ";
	string chars_to_trim2 = "\n";
	string chars_to_trim3 = "\t";
	string chars_to_trim4 = "\v";
	string chars_to_trim5 = "\f";
	string chars_to_trim6 = "\r";
	// 각각 앞 뒤 모든 공백 자르기

		for (int i = 0; i < data.size(); i++)
			trimString(data, chars_to_trim1);
		for (int i = 0; i < data.size(); i++)
			trimString(data, chars_to_trim2);
		for (int i = 0; i < data.size(); i++)
			trimString(data, chars_to_trim3);
		for (int i = 0; i < data.size(); i++)
			trimString(data, chars_to_trim4);
		for (int i = 0; i < data.size(); i++)
			trimString(data, chars_to_trim5);//새로추가
		for (int i = 0; i < data.size(); i++)
			trimString(data, chars_to_trim6);//새로추가

		if (data == "") {
			cout << "공백만으로는 검색 불가능" << endl;
			return false;
		}
		else
		{
			cout << endl << "<검색 결과>" << endl;
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
				cout << "데이터가 없습니다. " << endl;
				return false;
			}
			else {
				int select;
				cout << ">>> ";
				cin >> select;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "삭제 하시겠습니까? ";
				if (yesorno()) {
					//yes
					file_data[matched_index[select - 1]].clear();
					reWriteTextFile("test.txt");
					cout << "삭제가 완료되었습니다." << endl;
				}
				else {
					cout << "삭제하지 않습니다." << endl;
				}
				//y라면 rewrite 
				//n이라면 그냥 리턴
				//y라면 인덱스 찾아 삭제 진행
				//file_data[select - 1].clear();
				//n이라면 그냥 리턴
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
	//테스트용 매개변수 대체
	regex ex1("(\\d{2})-(\\d{2})-(\\d{2})");
	regex ex2("(\\d{4})-(\\d{2})-(\\d{2})");
	smatch matches;

	if (regex_match(data, matches, ex1)) {
		//연도 2자리 매칭
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
		//연도 4자리 매칭
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

	//기본 날짜 검사
	if (month <= 0 || month > 12) {
		printdate_err();
		return false;
	}
	if (day <= 0 || day > 31) {
		printdate_err();
		return false;
	}

	//정규식 통과 후 윤년검사
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
			if (isLeapyear(year)) {//윤년이면
				if (day == 30 || day == 31) {
					printdate_err();
					return false;
				}
			}
			else {//윤년이 아니면 
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
	//테스트용 매개변수로 대체
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
	//string data = "a하b kkk ㅎcㅏ";
	//매개변수 data
	cout << "memo testing "<<endl;
	//string result;
	char* sub_str = new char[10]{ "" };
	int k = 0;
	int count = 0;
	for (int i = 0; i < (int)(data.size()); i++) {
		if (data[i] & 0x80) {
		//	han_index[k] = i;//추출을 위한 인덱스 저장
			i++;  // 한글은 2바이트이기 때문에 1바이트 더 증가시킴
		//	cout <<"한글 분리"<<data.substr(han_index[k],2) << "|";
		//	k++;
			count++;
		}
		else {
			 //cout << "영문 분리" << data[i] << "|";
			sub_str[k] = data[i];
			k++;
			count++;
		}
		sub_str[k] = '\0';
	}
	if (count > 10) {
		//cout << "오류: "<<count << endl;
		printmemo_err();
		return false;
	}
	if (data == "") return true;
	string nohanguel = sub_str;
	//영문만 이루어진 문자열 정규식 검사
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
		cout << "금액 형식 오류"<<endl;
}
void cashData::printdate_err()
{
	cout << "날짜 형식 오류 " << endl;
}
void cashData::printmemo_err()
{
	cout << "내용 형식 오류" << endl;
}


void cashData::readTextFile(string txt_name)
{
	file_data.clear();//file_data 초기화
	char readline[66];//한 줄 최대 2020-02-02/999999999/5*2/10*2/user_id = 10+9+10+20+12+4+\n = 66

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
	//file_data.push_back("2022-10-01/1000/기타/*/ooozzz"); 테스트용
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
		SetFileAttributes(_T(result), FILE_ATTRIBUTE_READONLY); //파일 외부수정 금지
	}
	else {
		cout << "file not open" << endl;
	}
	writeFile.close();
	file_data.clear(); //내부 데이터 파일 초기화
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
		SetFileAttributes(_T(result), FILE_ATTRIBUTE_READONLY); //파일 외부수정 금지
	}
	else {
		cout << "file not open" << endl;
	}
	writeFile.close();
	file_data.clear(); //내부 데이터 파일 초기화
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
			cout << "잘못된 형식입니다.\n" << endl;
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
