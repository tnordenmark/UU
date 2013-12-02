// Filnamn : .../virtual/person.h
#ifndef __person__
#define __person__
#include<string>
using namespace std;

class person {
 public:
  person();              
  person(string fn, string ln); 
  ~person();              

  virtual void report(); 
  virtual void writeName();
  virtual void input();    

 protected:
  string fname; 
  string lname; 
};
#endif
