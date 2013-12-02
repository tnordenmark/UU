#include <iostream>

using namespace std;

int calcSec(int, int, int);
int calcTime(int, int);

int main()
{
	const int day = 24 * 60 * 60;
	const int hour = 60 * 60;
	const int minute = 60;

	int startnr;				//contestants number
	int s_hour;					//start time, hours
	int s_min;					//start time, minutes
	int s_sec;					//start time secondss
	int s_seconds;				//variable to hold start time in seconds
	int m_hour;					//end time, hours
	int m_min;					//end time, minutes
	int m_sec;					//end time, seconds
	int m_seconds;				//variable to hold end time in seconds
	int r_hour;					//result in hours
	int r_min;					//result in minutes
	int r_sec;					//result in seconds
	int totalseconds = 0;		//start time subtracted from end time in seconds
	int best_time = day + 1;	//variable to hold the best time
	int contestants = 0;		//number of contestants
	int nr_winner = 0;			//number of the winning contestant

	// start of main loop
	do
	{
		//ask for contestants number
		cout << "Startnummer? ";
		cin >> startnr;
		
		//check if contestants number is larger than 0
		if(startnr >= 0)
		{
			//update the number of contestans counter
			contestants++;

			//ask for start and end time
			cout << "Starttid (HH MM SS)? ";
			cin >> s_hour >> s_min >> s_sec;
			//call function to convert time to seconds
			s_seconds = calcSec(s_hour, s_min, s_sec);

			cout << "Måltid (HH MM SS)? ";
			cin >> m_hour >> m_min >> m_sec;
			//call function to convert time to sedonds
			m_seconds = calcSec(m_hour, m_min, m_sec);

			//check if end time is smaller than start time in seconds
			if(m_seconds < s_seconds)
			{
				//append 1 day to handle end times the following day
				totalseconds = calcTime(s_seconds, m_seconds) + day;

			}
			else
			{
				//else do a normal calculation
				totalseconds = calcTime(s_seconds, m_seconds);
			}

			//if a new time is the best time yet
			if(totalseconds < best_time)
			{
				//assign current time to best_time
				best_time = totalseconds;
				//and assign contestants number to current winner
				nr_winner = startnr;
			}
		}
		else
		{
			//convert total seconds to hours, minutes and seconds
			r_hour = best_time / hour;
			r_sec = best_time % hour;
			r_min = r_sec / minute;
			r_sec %= minute;

			//if there are no contestans entered yet
			if(contestants < 1)
			{
				cout << "Inga tävlande." << endl;
			}
			else
			{
				//print the results
				cout << "Vinnare är startnr: " << nr_winner << endl;
				cout << r_hour <<  " tim, " << r_min << " min och "
					<< r_sec << " sek." << endl;
				cout << "Antal tävlande: " << contestants << endl;
			}
		}
	}
	//run loop as long as contestants number isn't negative
	while(startnr >= 0);

	cout << "Programmet avslutas." << endl;

	return 0;
}

//function to calculate total number of seconds
int calcSec(int s_hour, int s_min, int s_sec)
{
	int hour = s_hour * 3600;
	int min = s_min * 60;
	int totalseconds = hour + min + s_sec;

	return totalseconds;
}

//function to calculate differense between start and end time
int calcTime(int s_seconds, int m_seconds)
{
	int timediff = m_seconds - s_seconds;
	return timediff;
}