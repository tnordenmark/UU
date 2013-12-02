#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	double totaltime;
	time_t s_time, m_time;

	cout << "Starttid: ";
	cin >> s_time;
	cout << "Sluttid: ";
	cin >> m_time;
	
	cout << &m_time;

	totaltime = difftime(m_time, s_time);
	cout << totaltime;

}