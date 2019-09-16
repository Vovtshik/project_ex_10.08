// Программа принимает на вход имена двух файлов и создает новый файл, 
// в котором за содержимым первого файла следует содержимое второго.
#include "../std_lib_facilities.h"

void in_file(vector<int>& vr, string& name);     // Функция для считывания данных из файла
void out_file(vector<int>& vr, string& name);    // Функция для вывода данных в файл
void loop_read_excess();                         // Функция для отбрасывания ошибочных данных

int main()
{
	setlocale(LC_ALL, "Rus");
	vector<int>vi;
	cout << "Введите имя первого входного файла с данными:\n";
	string name{};
	cin >> name;
	in_file(vi, name);
	cout << "Введите имя второго входного файла с данными:\n";
	cin >> name;
	in_file(vi, name);
	cout << "Введите имя выходного файла для записи объединенных данных:\n";
	cin >> name;
	out_file(vi, name);
	return 0;
}

void in_file(vector<int>& vr, string& name)
{
	ifstream ist{ name };
	if (!ist) error("Невозможно открыть входной файл", name);
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
	if (!ost) error("Невозможно открыть выходной файл ", name);
	for (int r : vr)
		ost << r << " ";
}

void loop_read_excess()
{
	char ch;
	while (cin.get(ch) && !isdigit(ch))
		continue;
}