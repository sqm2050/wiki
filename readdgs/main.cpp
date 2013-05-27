#include <fstream>
#include <iostream>
#include <cstring>
#include <string>

//模块判断条件
#define IS_MODULE_HEAD(tmp) (tmp[0]=='$' && tmp[1]=='$' \
				&& tmp[2]=='B' && tmp[3]=='l' \
				&& tmp[4]=='k' && tmp[5]=='D' \
				&& tmp[6]=='e'&&tmp[7]=='f') 
using namespace std;

int main()
{ 
	char *content;
	ifstream fin;//定义输入流
	fin.open("GRID_Export1.dgs");//文件名
	char tmp[1000] = {0}; //存储当前行字符串
	int i=0;
	int j=0;
	int startindex;//字符串起始点
	int endindex;//字符串终止点
	int numindex;//第几个分号
	while ( !fin.eof())//若未读到文件尾，则。。。
	{	
		memset(tmp,0,1000);              //将tmp清零
		fin.getline(tmp,1000);           //读取一行数据
		if (IS_MODULE_HEAD(tmp))
		{
			for(j=0;j<14;j++)//跳过模块头的说明部分，循环体长度=模块头的行数+1
			{
				memset(tmp,0,1000);  
				fin.getline(tmp,1000);
			}
			while(tmp[0]!='$')//读本模块的终止条件==读到下一模块头的第一个字符
			{
				startindex=2;
				endindex=0;
				numindex=0;
				for(int i=0;i<1000;i++)//读内容
				{
					if(tmp[i]==';')
					{
						endindex=i;
						numindex++;
						if(numindex==3)//以需要第三列内容为例
						{
							content=new char[endindex-startindex-1];//需要的内容暂存在content中
							int mm=0;
							for(j=startindex+1;j<endindex;j++)//给content赋值并显示content内容
							{
								content[mm]=tmp[j];
								cout<<content[mm];
								mm++;
							}
							cout<<endl;
						}
						startindex=endindex;
					}
				}
				memset(tmp,0,1000);              //将tmp清零
				fin.getline(tmp,1000);           //读下一行数据
			}
		}
	}
	fin.close();
	delete(content);
//	cin.get();
}
