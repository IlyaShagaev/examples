#include <iostream>
#include <thread>
#include <unistd.h>
#include <mutex>

using namespace std;

mutex mut;

void my_thread(int thread? , int &i)
{
	while (1)
	{
		mut.lock();
		i++;
		mut.unlock();
		usleep(100000);
	}
}

int main(){

	int num = 0;
	thread thread1(my_thread,NULL,ref(num));
	thread1.detach();

	while (1)
	{
		mut.lock();
		cout<<k<<endl;
		mut.unlock();
		usleep(100000);
	}

	return 0;
}