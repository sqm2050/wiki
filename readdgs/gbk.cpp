///
/// @file 	list_column.cpp
/// @brief 	list the assignment column
/// 
#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
#include <string.h>

#define MODULE_MAX_LINES 	1024
// begin with 0.
#define LINE_HEAD_OFFSET	2

#define LINE_MAX_LEN		1024
using namespace std;

// @brief	prt the column to a buffer
//
// @param file		file name
// @param module	moudle name, example:"$$General"
// @param col		the column will be printed
// @param line		reference parameter, will be changed to 
// 			the lines of module
// @param data		will be filled with the col data
//
// @return	on success, return 0
// 		on fail, return -1
int prt_column(char *file, char *module, int col, int &line, char *data[])
{
	char *buffer;
	int i, j, h;
	int start_idx, end_idx, num_idx, buffer_len;
	char tmp[LINE_MAX_LEN] = {0};
	ifstream fin(file);

	if (!fin.is_open()) {
		cout << "\n\t\tOpen the file failed, "
				"the file name is right?\n" <<endl;
		return -1;
	}

	while(!fin.eof()) {	// read the new line until the EOF
		memset(tmp, 0x00, LINE_MAX_LEN);
		fin.getline(tmp, LINE_MAX_LEN);

		if (strncmp(module, tmp, strlen(module))) {
			continue;
		} else {
			// get into the module
			// offset the head lines
			do {
				memset(tmp, 0x00, LINE_MAX_LEN);
				fin.getline(tmp, LINE_MAX_LEN);
			} while (!fin.eof() && tmp[0] == '*');
		}

		while (tmp[0] != '$') {
			// init the temporary variable for every module
			start_idx = LINE_HEAD_OFFSET;
			end_idx = 0;
			num_idx = 0;

			for (i = 0; i < LINE_MAX_LEN; i++) {
				if (tmp[i] == ';') {
					end_idx = i;
					num_idx++;
				}
				if ( num_idx == col) {
				 	buffer_len = end_idx - start_idx + 1;
					buffer = new char[buffer_len];
					memset(buffer, 0x00, buffer_len);
					for (h = 0, j = start_idx; j < end_idx; \
							h++, j++) {
						buffer[h] = tmp[j];
					}
					data[line] = buffer;
					line++;
					if (line == MODULE_MAX_LINES) {
						cout << "Warning: module line"
							" is too long"<< endl;
						return 0;
					}
					break;
				}
				start_idx = LINE_HEAD_OFFSET > end_idx + 1 ? \
					    LINE_HEAD_OFFSET : end_idx + 1;
			}
			memset(tmp, 0, LINE_MAX_LEN);
			fin.getline(tmp, LINE_MAX_LEN);
		}
	}
	fin.close();
	return 0;
}

int main()
{
	int i, ret, line = 0, col = 0;
	char *data[MODULE_MAX_LINES];
	char file[100] ={0};
	char module[100] = {0};

	cout << "Input the file name: ";
	cin >> file;
	cout << "Input the module name: ";
	cin >> module;
	cout << "Input the col num: ";
	cin >> col;
	cout << "文件：" << file << "\t模块：" << module<< "\t 列：" << col << endl;

	if (col <= 0) {
		cout << "\n\t\tWrong column number, "
				"it should be integer\n" << endl;
		return 0;
	}
		
	ret = prt_column(file, module, col, line, data);
	if (ret != 0)
		return -1;

	// print the column
	for (i = 0; i < line; i++) {
		cout <<"line: " << i + 1 <<"\tdata: " << data[i] << endl;
	}
	// free the dynamic memory
	for (i = 0; i < line; i++) {
		delete(data[i]);
		data[i] = NULL;
	}
	return 0;
}
