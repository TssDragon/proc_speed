#include <iostream>
#include <ctime>

using namespace std;

int main() {
	clock_t t1,t2;
	clock_t t3,t4;
	
	t1 = clock();
	for(int i=0; i<100000000; ++i) {
		_asm {
			sub ax,bx;
		}
	}
	t2 = clock();
	cout << "sub ax,bx = " <<(double)(t2-t1)/CLOCKS_PER_SEC <<endl;
	
	t3 = t2-t1;

	t1 = clock();
	for(int i=0; i<100000000; ++i) {
	}
	t2 = clock();
	cout << "empty cycle = " <<(double)(t2-t1)/CLOCKS_PER_SEC <<endl;
	
	t4 = t2-t1;

	t3-=t4;
	cout <<"res = " <<(double)t3/CLOCKS_PER_SEC <<endl;

	system("pause");
}