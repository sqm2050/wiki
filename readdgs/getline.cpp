#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main()
{
	ifstream file("test.txt");
	char tmp[10000] = {0};
	file.getline(tmp, 1000, 'a');
	cout << tmp;
	file.getline(tmp, 1000, 'a');
	cout << tmp;
	file.getline(tmp, 1000, 'a');
	cout << tmp;
}
