#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#define NUM 10

class Day
{

	string name[NUM];
	string present[NUM];
	int cnt;
public:
	Day()
	{
		for(int i = 0; i < NUM; i++)
		{
			name[i] = "biba";
			present[i] = "+";
		}
		cnt = 0;
		
	}
	void add(string n, string pr)
	{
		name[cnt] = n;
		present[cnt] = pr;
		cnt++;
	}
	void show()
	{
		for(int i = 0; i < cnt; i++)
		{
			cout << name[i] << ' ' << present[i] << endl;
			
		}
	}

	void load(string fname)
	{
		int i, k = 1;
		string line;
		string imya;
		string pr;
		ifstream file(fname);

		if(file.is_open())
		{
			while(!file.eof())
			{
				file >> line;
				if(k % 2 == 1)
				{
					imya = line;
				}
				else
				{
					pr = line;
					add(imya, pr);
				}
				k++;
			}	
		}
	}
};

int main()
{
	Day a;
	a.load("file.txt");
	a.show();
	return 0;
}