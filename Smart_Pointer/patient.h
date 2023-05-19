#ifndef PATIENT_H
#define PATIENT_H

#include<iostream>
#include<stdexcept>
#include<set>

#include "illness.h"

class Patient
{
 string name;
 int age;
 set<Illness> illnesses;
 unsigned wealth;
 public:
 Patient(const string& name, int, const set<Illness>&,unsigned wealth = 20);
 void increase_wealth(unsigned x);
 bool pay_procedure(unsigned x);
 void catch_disease(const Illness& x);
 bool requires_treatment_in(Medical_Specialty x) const;
 bool healthy() const;
 unsigned cure(Medical_Specialty x);
 string get_name() const;
 friend bool operator==(const Patient& p,const Patient& p1);
 ostream& print(ostream&)const;
};
ostream& operator<<(ostream&,const Patient&);
#endif


