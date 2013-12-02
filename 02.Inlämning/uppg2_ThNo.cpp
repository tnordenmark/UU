/*
================================================================================
Datorer och programmering, DoP, 10 hsp, termin/år: VT/2013

Inlämningsuppgift nr: 2

Namn: Thomas Nordenmark

Personummer: 810427-8257

Fyll i (alt. stryk det som INTE är relevant) av nedanstående:

Den fil som jag lämnar in går att kompilera och
programmet fungerar för alla de testdata som finns för uppgiften: Ja
     Om Nej, beskriv vilka testdata som ger problem: -

Jag har använt kompilator/editor: gcc 4.7.2/Sublime Text 2

Jag har använt följande dator: PC
      med operativsystemet: Arch Linux x86_64

Jag har arbetat ungefär 3 timmar med denna uppgift

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
			

			//if there are no contestans entered yet
			if(contestants < 1)
			{
				cout << "Inga tävlande." << endl;
			}
			else
			{
				//convert total seconds to hours, minutes and seconds
				r_hour = best_time / hour;
				r_sec = best_time % hour;
				r_min = r_sec / minute;
				r_sec %= minute;
				
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

//function to calculate difference between start and end time
int calcTime(int s_seconds, int m_seconds)
{
	int timediff = m_seconds - s_seconds;
	return timediff;
}
/*
================================================================================
Här följer programkörningar för alla testdata:
==============================================

Testdata 1:

./uppg2_ThNo 
Startnummer? 33
Starttid (HH MM SS)? 17 30 15
Måltid (HH MM SS)? 18 22 35
Startnummer? -1
Vinnare är startnr: 33
0 tim, 52 min och 20 sek.
Antal tävlande: 1
Programmet avslutas.

Testdata 2:

./uppg2_ThNo
Startnummer? 33
Starttid (HH MM SS)? 00 30 15
Måltid (HH MM SS)? 19 22 35
Startnummer? -1
Vinnare är startnr: 33
18 tim, 52 min och 20 sek.
Antal tävlande: 1
Programmet avslutas.

Testdata 3:

./uppg2_ThNo
Startnummer? 33
Starttid (HH MM SS)? 17 30 15
Måltid (HH MM SS)? 18 22 35
Startnummer? 14
Starttid (HH MM SS)? 23 35 00
Måltid (HH MM SS)? 0 12 24
Startnummer? 26
Starttid (HH MM SS)? 10 11 12
Måltid (HH MM SS)? 20 21 22
Startnummer? -1
Vinnare är startnr: 14
0 tim, 37 min och 24 sek.
Antal tävlande: 3
Programmet avslutas.

Testdata 4:

./uppg2_ThNo
Startnummer? 14
Starttid (HH MM SS)? 23 35 00
Måltid (HH MM SS)? 0 12 24
Startnummer? 26
Starttid (HH MM SS)? 10 11 12
Måltid (HH MM SS)? 20 21 22
Startnummer? 33
Starttid (HH MM SS)? 17 30 15
Måltid (HH MM SS)? 18 22 35
Startnummer? -1
Vinnare är startnr: 14
0 tim, 37 min och 24 sek.
Antal tävlande: 3
Programmet avslutas.

Testdata 5:

./uppg2_ThNo
Startnummer? 26
Starttid (HH MM SS)? 10 11 12
Måltid (HH MM SS)? 20 21 22
Startnummer? 33
Starttid (HH MM SS)? 17 30 15
Måltid (HH MM SS)? 18 22 35
Startnummer? 14
Starttid (HH MM SS)? 23 25 00
Måltid (HH MM SS)? 0 12 24
Startnummer? -1
Vinnare är startnr: 14
0 tim, 47 min och 24 sek.
Antal tävlande: 3
Programmet avslutas.

Testdata 6:

./uppg2_ThNo
Startnummer? 17
Starttid (HH MM SS)? 00 00 50
Måltid (HH MM SS)? 00 00 30
Startnummer? -1
Vinnare är startnr: 17
23 tim, 59 min och 40 sek.
Antal tävlande: 1
Programmet avslutas.

Testdata 7:

./uppg2_ThNo
Startnummer? -1
Inga tävlande.
Programmet avslutas.

Testdata 8:

./uppg2_ThNo
Startnummer? 15
Starttid (HH MM SS)? 10 00 00
Måltid (HH MM SS)? 11 00 00
Startnummer? 12
Starttid (HH MM SS)? 11 00 00
Måltid (HH MM SS)? 10 00 10
Startnummer? -1
Vinnare är startnr: 15
1 tim, 0 min och 0 sek.
Antal tävlande: 2
Programmet avslutas.

Testdata 9:

./uppg2_ThNo
Startnummer? 8
Starttid (HH MM SS)? 00 00 10
Måltid (HH MM SS)? 00 00 20
Startnummer? -1
Vinnare är startnr: 8
0 tim, 0 min och 10 sek.
Antal tävlande: 1
Programmet avslutas.

================================================================================

Kort om uppgiften:

Uppgiften går ut på att skriva ett program som hanterar data för tävlande
i en idrottstävling, inkl. statistik om vinnare och antal tävlande.

Eventuella svårigheter:

De svårigheter jag ser är att hantera statistiken på ett korrekt sätt. D.v.s.
uppdatera och lagra den i rätt ordning och vid rätt tillfälle.

Frågor tillhörande uppgiften:

1) Vad händer i ditt program (testa om du vill) om du rapporterar in två
tävlande med olika nummer som har samma totaltid? Är det den första eller
den andra som vinner? Varför?

Den första deltagaren visas som vinnare eftersom mina variabler inte
tar hänsyn till identiska resultat och därför inte uppdateras.

2) Varför har vi så många testdata? Är det för att det är kul att köra
programmet många gånger?

För att täcka upp en stor del av de scenarion som kan tänkas inträffa vid
körning i en skarp miljö.

3) Ibland vid programmering börjar man med att skriva sina testdata,
sedan gör man programmet. Finns det några fördelar med det?

Fördelen är att man på förhand kan upptäcka logiska fel samt har ett
"facit" att jämföra programmets utskrifter med.

*/