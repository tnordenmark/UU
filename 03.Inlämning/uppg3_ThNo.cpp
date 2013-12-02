/*
================================================================================
Datorer och programmering, DoP, 10 hsp, termin/år: VT/2013

Inlämningsuppgift nr: 3

Namn: Thomas Nordenmark

Personummer: 810427-8257

Fyll i (alt. stryk det som INTE är relevant) av nedanstående:

Den fil som jag lämnar in går att kompilera och
programmet fungerar för alla de testdata som finns för uppgiften: Ja
     Om Nej, beskriv vilka testdata som ger problem: -

Jag har använt kompilator/editor: llvm-gcc 4.2/Sublime Text 2

Jag har använt följande dator: MacBook 3.1
      med operativsystemet: OSX 10.6.8

Jag har arbetat ungefär 4 timmar med denna uppgift

================================================================================
*/
#include <iostream>
using namespace std;

// Deklaration av programmets funktioner.
void skrivInfo();
int lasEttTal();
char lasOp();
void ordna(int &tal1, int &tal2);
long berakna(char op, int tal1, int tal2);
void skrivResultat(long svar);

// Huvudfunktionen som anropar övriga funktioner.
int main()
{
	int tal1, tal2;
	char op;
	long svar;

	// Skriv ut information om programmet.
	skrivInfo();

	// Läs in tal1 och tal2.
	tal1 = lasEttTal();

	tal2 = lasEttTal();

	// Läs in operationen som ska utföras.
	op = lasOp();

	// Sortera talen i stigande ordning.
	ordna(tal1, tal2);

	// Skicka tal1, tal2 samt valet av operation till beräkningsfunktionen.
	svar = berakna(op, tal1, tal2);

	// Skriv ut resultatet av beräkningen.
	skrivResultat(svar);

  return 0;
}

// Funktion för att skriva ut kort information om programmets funktion.
void skrivInfo()
{
	cout << "Programmet läser in två tal, utför vald" << endl;
	cout << "beräkning på samtliga tal i det angivna skåpet" << endl;
	cout << "samt returnerar beräkningens resultat." << endl;
}

// Funktion för att läsa in talen som ska användas i beräkningarna.
int lasEttTal()
{
	int tal;
	
	cout << "Mata in ett heltal: ";
	cin >> tal;

	return tal;
}

// Funktion för att läsa in valet av operation som ska utföras.
char lasOp()
{
	char op;
	
	cout << "Välj operation; (a)ddition, (m)ultiplikation" << endl;
	cout << "eller (k)vadratsummering: ";
	cin >> op;

	return op;
}

// Funktion för att sotera talen i stigande ordning.
void ordna(int &tal1, int &tal2)
{
	// Om tal1 är större än tal2, byt plats på dessa.
	if(tal1 > tal2)
		swap(tal1, tal2);
}

// Funktion som utför de valda beräkningarna.
long berakna(char op, int tal1, int tal2)
{
	int i = 0;
	long svar = 0;

	if(op == 'a')
	{
		for(i = tal1; i <= tal2; i++)
		{
			// Addera svaret med nästa tal i serien tills i = tal2.
			svar += i;
		}
		return svar;
	}
	else if(op == 'k')
	{
		for(i = tal1; i <= tal2; i++)
		{
			// Multiplicera svaret med sig själv tills i = tal2.
			svar += (i * i);
		}
		return svar;
	}
	else if(op == 'm')
	{
		// Lokal variabel för multiplikationsberäkningen.
		long svar = 1;

		for(i = tal1; i <= tal2; i++)
		{
			// Multiplicera svaret med nästa tal i serien tills i = tal2.
			svar *= i;
		}
		return svar;
	}
	else
	{
		// Visa ett felmeddelande om något annat än 'a', 'k' eller 'm' matats in.
		cout << "Du har valt en felaktig operation." << endl;
		return 0;
	}
}

// Funktion som skriver ut det beräknade resultatet.
void skrivResultat(long svar)
{
	cout << "Svaret är: " << svar << endl;
}
/*
================================================================================
Här följer programkörningar för alla testdata:
==============================================

Testdata 1:

$ ./uppg3_ThNo
Programmet läser in två tal, utför vald
beräkning på samtliga tal i det angivna skåpet
samt returnerar beräkningens resultat.
Mata in ett heltal: 3
Mata in ett heltal: 5
Välj operation; (a)ddition, (m)ultiplikation
eller (k)vadratsummering: a
Svaret är: 12

Testdata 2:

$ ./uppg3_ThNo
Programmet läser in två tal, utför vald
beräkning på samtliga tal i det angivna skåpet
samt returnerar beräkningens resultat.
Mata in ett heltal: 3
Mata in ett heltal: 5
Välj operation; (a)ddition, (m)ultiplikation
eller (k)vadratsummering: m
Svaret är: 60

Testdata 3:

$ ./uppg3_ThNo
Programmet läser in två tal, utför vald
beräkning på samtliga tal i det angivna skåpet
samt returnerar beräkningens resultat.
Mata in ett heltal: 3
Mata in ett heltal: 5
Välj operation; (a)ddition, (m)ultiplikation
eller (k)vadratsummering: k
Svaret är: 50

Testdata 4:

./uppg3_ThNo
Programmet läser in två tal, utför vald
beräkning på samtliga tal i det angivna skåpet
samt returnerar beräkningens resultat.
Mata in ett heltal: -3
Mata in ett heltal: 5
Välj operation; (a)ddition, (m)ultiplikation
eller (k)vadratsummering: m
Svaret är: 0

Testdata 5:

$ ./uppg3_ThNo
Programmet läser in två tal, utför vald
beräkning på samtliga tal i det angivna skåpet
samt returnerar beräkningens resultat.
Mata in ett heltal: 5
Mata in ett heltal: 3
Välj operation; (a)ddition, (m)ultiplikation
eller (k)vadratsummering: a
Svaret är: 12

Testdata 6:

$ ./uppg3_ThNo
Programmet läser in två tal, utför vald
beräkning på samtliga tal i det angivna skåpet
samt returnerar beräkningens resultat.
Mata in ett heltal: -3
Mata in ett heltal: -5
Välj operation; (a)ddition, (m)ultiplikation
eller (k)vadratsummering: a
Svaret är: -12

Testdata 7:

$ ./uppg3_ThNo
Programmet läser in två tal, utför vald
beräkning på samtliga tal i det angivna skåpet
samt returnerar beräkningens resultat.
Mata in ett heltal: 1
Mata in ett heltal: 100
Välj operation; (a)ddition, (m)ultiplikation
eller (k)vadratsummering: k
Svaret är: 338350

Testdata 8:

$ ./uppg3_ThNo
Programmet läser in två tal, utför vald
beräkning på samtliga tal i det angivna skåpet
samt returnerar beräkningens resultat.
Mata in ett heltal: 1
Mata in ett heltal: 1000
Välj operation; (a)ddition, (m)ultiplikation
eller (k)vadratsummering: m
Svaret är: 0

Svaret blir 0 eftersom resultatet blir för stort
för att lagra i en enda long int.

================================================================================
Här skriver du en kort rapport om uppgiften:

1) Uppgiften går ut på att skriva ett program som läser in två st tal
och utför addition, kvadratsummering eller multiplikation på samtliga
tal mellan de två inmatade talen beroende på användarens val av operation.

2) De svårigheter jag stött på var i första hand att få FOR-repitionerna
att fungera korrekt för de olika beräkningarna. Ett annat moment som
var något klurigt var den lokala variabeln för multiplikations-
repetitionen.

Uppgiftens frågor:

1) Några fördelar med att dela upp programmet i funktioner är:
	*Enklare att återanvända kod i andra projekt.
	*Enklare att underhålla koden då endast en funktion behöver modifieras
	utan risk för att ändringarna spiller över i andra delar av programmet.
	*Överskådligare kod som är enklare att testköra och har mindre risk för buggar.
	*Bättre struktur för stora projekt med många deltagare.

2) Referensparametrar kan t.ex. inte användas jämt då dessa inte går att modifiera
eftersom de är just referenser eller "alias" till en redan existerande variabel
eller datastruktur. Därför behöver man ibland arbeta med värden som skapar en
kopia av objektet i funktionen.
*/