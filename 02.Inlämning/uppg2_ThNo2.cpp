/*
================================================================================
Datorer och programmering, DoP, 10 hsp, termin/år: VT/2013

Inlämningsuppgift nr:

Namn: Thomas Nordenmark

Personummer: 810427-8257

Fyll i (alt. stryk det som INTE är relevant) av nedanstående:

Den fil som jag lämnar in går att kompilera och
programmet fungerar för alla de testdata som finns för uppgiften: Ja/Nej
     Om Nej, beskriv vilka testdata som ger problem:

Jag har använt kompilator/editor:

Jag har använt följande dator:
      med operativsystemet:

Jag har arbetat ungefär <X> timmar med denna uppgift

================================================================================
*/
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

	do
	{
		cout << "Startnummer? ";
		cin >> startnr;
		
		if(startnr >= 0)
		{
			contestants++;

			cout << "Starttid (HH MM SS)? ";
			cin >> s_hour >> s_min >> s_sec;
			s_seconds = calcSec(s_hour, s_min, s_sec);

			cout << "Måltid (HH MM SS)? ";
			cin >> m_hour >> m_min >> m_sec;
			m_seconds = calcSec(m_hour, m_min, m_sec);

			if(m_seconds < s_seconds)
			{
				totalseconds = calcTime(s_seconds, m_seconds) + day;

			}
			else
			{
				totalseconds = calcTime(s_seconds, m_seconds);
			}

			if(totalseconds < best_time)
			{
				best_time = totalseconds;
				nr_winner = startnr;
			}
		}
		else
		{
			r_hour = best_time / hour;
			r_sec = best_time % hour;
			r_min = r_sec / minute;
			r_sec %= minute;

			cout << "Vinnare är startnr: " << nr_winner << endl;
			cout << r_hour <<  " tim, " << r_min << " min och "
				<< r_sec << " sek." << endl;
			cout << "Antal tävlande: " << contestants << endl;
		}
	}
	while(startnr >= 0);

	cout << "Programmet avslutas." << endl;

	return 0;
}


int calcSec(int s_hour, int s_min, int s_sec)
{
	int hour = s_hour * 3600;
	int min = s_min * 60;
	int totalseconds = hour + min + s_sec;

	return totalseconds;
}


int calcTime(int s_seconds, int m_seconds)
{
	int timediff = m_seconds - s_seconds;
	return timediff;
}
/*
================================================================================
Här följer programkörningar för alla testdata:
==============================================

...

================================================================================
Här skriver du en kort rapport om uppgiften:
- ett eller ett par stycken om vad uppgiften gick ut på,
- vilka svårigheter som fanns,
- vad du tyckte var besvärligt
- och hur du löste problemen.

Om det finns frågor att besvara i uppgiften ska det göras här.


Vad händer i ditt program (testa om du vill) om du rapporterar in två tävlande med olika nummer som har samma totaltid? Är det den första eller den andra som vinner? Varför?
Varför har vi så många testdata? Är det för att det är kul att köra programmet många gånger?
Ibland vid programmering börjar man med att skriva sina testdata, sedan gör man programmet. Finns det några fördelar med det?

*/
