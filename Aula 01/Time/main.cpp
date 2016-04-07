#include <iostream>

#include "Time.h"

using namespace std;

int main() {

	int h, m, s;
	
	cout << "Hour: ";
	cin >> h;
	cout << "Minute: ";
	cin >> m;
	cout << "Second: ";
	cin >> s;
	
	Time t1 = Time(h, m , s);
	
	//cout << endl << t1.getHour() << " : " << t1.getMinute() << " : " << t1.getSecond() << endl;
	
	int i = 0;
	while(i < 60) {
		cout << endl << t1.getHour() << " : " << t1.getMinute() << " : " << t1.getSecond() << endl;
		t1.nextSecond();
		i++;
	}

	return 0;

}