#include <iomanip>
#include <iostream>
#include <Windows.h>

using namespace std;

int hours = 0;
int minutes = 0;
int seconds = 0;


void displayTimer()
{
	system("cls");
	cout << setfill('0') << setw(2) << hours << " hrs ";
	cout << setfill('0') << setw(2) << minutes << " min ";
	cout << setfill('0') << setw(2) << seconds << " sec " << endl;
}

void timer()
{

	while (true) {

		displayTimer();

		Sleep(1000);

		seconds++;

		if (seconds == 60) {

			minutes++;

			if (minutes == 60) {

				hours++;
				minutes = 0;
			}
			seconds = 0;
		}
	}
}

int main()
{
	timer();
}