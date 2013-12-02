// Filnamen : .../student.cc
#include<iostream>
#include<string>
#include "person.h"
#include "student.h"
using namespace std;

student::student() : person() {
  education  = "Kinder garten";
  lastCourse = "";
  lastGrade  = 0;
  totPoints  = 0.0;
}

student::student(string fn, string ln, string edu )
  : person(fn, ln) {
  education  = edu;
  lastCourse = "";
  lastGrade  = 0;
  totPoints  = 0.0;
}

student::~student() { }

void student::report() {
  person::report();
  cout << " studerar " << education << endl;
  cout << " har totalt " << totPoints << " poäng" << endl;
}

void student::input() {
  person::input();
  cout << "Ange utbildning för " << fname << " : ";
  getline(cin, education);
  cout << "Ange poäng för " 
       << fname <<  ": ";
  cin >> totPoints;
  cin.get();
  cout << "Ge senaste kurs : ";
  getline(cin, lastCourse);
  cout << " Ange poäng : ";
  cin >> lastGrade;
  cin.get();
}

void student::newCourse( string cName, int grade, double points ) {
  lastCourse = cName;
  lastGrade  = grade;
  totPoints  += points;
}

double student::totalPoints() {
  return totPoints;
}

int student::lastgrade() {
  return lastGrade;
}
