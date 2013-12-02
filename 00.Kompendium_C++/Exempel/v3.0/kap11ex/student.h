// Filnamn : .../student.h
#ifndef __student__
#define __student__
#include "person.h"

class student : public person {
 public:
  student();                        // Defaultkonstruktor
  student( string fn, string ln, 
	   string edu );            // Överlagrad konstruktor 
  ~student();                       // Destructor

  void report();                    // Skriv ut data
  void input();                     // Läs in
  void newCourse( string cName, int grade, 
		  double points );  // Lägg till ny kurs
  double totalPoints();             // Returnera totalpoäng
  int lastgrade();                  // Returnera senaste betyg

 protected:
  double totPoints;
  int lastGrade;
  string education; 
  string lastCourse; 
};
#endif
