// ��������� ��������� �� ���� ����� ���� ������ � ������� ����� ����, 
// � ������� �� ���������� ������� ����� ������� ���������� �������.
#include "../std_lib_facilities.h"

void in_file(vector<int>& vr, string& name);     // ������� ��� ���������� ������ �� �����
void out_file(vector<int>& vr, string& name);    // ������� ��� ������ ������ � ����
void loop_read_excess();                         // ������� ��� ������������ ��������� ������

int main()
{
	setlocale(LC_ALL, "Rus");
	vector<int>vi;
	cout << "������� ��� ������� �������� ����� � �������:\n";
	string name{};
	cin >> name;
	in_file(vi, name);
	cout << "������� ��� ������� �������� ����� � �������:\n";
	cin >> name;
	in_file(vi, name);
	cout << "������� ��� ��������� ����� ��� ������ ������������ ������:\n";
	cin >> name;
	out_file(vi, name);
	return 0;
}

void in_file(vector<int>& vr, string& name)
{
	ifstream ist{ name };
	if (!ist) error("���������� ������� ������� ����", name);
	int n;
	while (true)
	{
		ist >> n;
		if (ist.fail())
			loop_read_excess();
		vr.push_back(n);
		if (ist.eof())
			return;
	}
}

void out_file(vector<int>& vr, string& name)
{
	ofstream ost{ name };
	if (!ost) error("���������� ������� �������� ���� ", name);
	for (int r : vr)
		ost << r << " ";
}

void loop_read_excess()
{
	char ch;
	while (cin.get(ch) && !isdigit(ch))
		continue;
}