#ifndef HOSPITAL_H
#define HOSPITAL_H

#include<iostream>
#include<stdexcept>
#include<set>
#include<memory>
#include<map>

#include "illness.h"
#include "patient.h"
#include "hcp.h"

class Hospital
{
  string name;
  map<string,shared_ptr<Health_Care_Provider>> hcps;
  map<string,weak_ptr<Patient>> patients;
  
  public:
  Hospital(string);
  bool sign_hcp(shared_ptr<Health_Care_Provider> m);
  bool admit_patient(shared_ptr<Patient> m);
  bool dismiss_hcp(string n);
  shared_ptr<Health_Care_Provider> get_hcp(string n) const;
  shared_ptr<Patient> get_patient(string n) const;
  bool dismiss_patient(string n);
  ostream& print(ostream&)const;
};

ostream& operator<<(ostream&,const Hospital&);
#endif

