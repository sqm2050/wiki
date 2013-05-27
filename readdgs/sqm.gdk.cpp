///
/// @file 	list_column.cpp
/// @brief 	list the assignment column
/// 
#include <fstream>
#include <iostream>
#include <cstring>
#include <string>

#define FILE_NAME	"GRID_Export1.dgs"
#define IS_MODULE_HEAD(tmp) (tmp[0]=='$' && tmp[1]=='$' \
				&& tmp[2]=='B' && tmp[3]=='l' \
				&& tmp[4]=='k' && tmp[5]=='D' \
				&& tmp[6]=='e' && tmp[7]=='f') 
// begin with 0.
#define LINE_HEAD_OFFSET	2

#define LINE_MAX_LEN	1024
using namespace std;

// @brief	prt the column to a buffer
//
// @param col	the column will be printed
// @return	on success, return 0
// 		on fail, return -1
int prt_column(int col, int &line, char *data[])
{
	char *buffer;
	int i, j, h;
	int start_idx, end_idx, num_idx, buffer_len;
	char tmp[LINE_MAX_LEN] = {0};
	ifstream fin(FILE_NAME);

	if (!fin.is_open()) {
		cout << "Open the file failed" <<endl;
		return -1;
	}

	while(!fin.eof()) {	// read the new line until the EOF
		memset(tmp, 0x00, LINE_MAX_LEN);
		fin.getline(tmp, LINE_MAX_LEN);

		if (!IS_MODULE_HEAD(tmp)) {
			continue;
		} else {
			// get into the module
			// offset the head lines
			for (i = 0; i < 14; i++) {
				memset(tmp, 0x00, LINE_MAX_LEN);
				fin.getline(tmp, LINE_MAX_LEN);
			} 
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
	int i, line, col, ret;
	char *data[LINE_MAX_LEN];

	cout << "Input the col num: ";
	cin >> col;
	ret = prt_column(col, line, data);

	if (ret != 0)
		return -1;

	// print the column
	for (i = 0; i < line; i++) {
		cout << data[i];
		cout << endl;
	}

	// free the dynamic memory
	for (i = 0; i < line; i++) {
		delete(data[i]);
		data[i] = NULL;
	}
	return 0;
} 
