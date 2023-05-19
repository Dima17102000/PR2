#include<iostream>
#include<stdexcept>
#include<set>
#include<algorithm>
#include "patient.h"
#include "illness.h"
Patient::Patient(const string& name, int age, const set<Illness>&illnesses,unsigned wealth): name{name},age{age},illnesses{illnesses},wealth{wealth}
{
 if (name.empty()) 
 {
      throw runtime_error("Name cannot be empty.");
    }
    if (age < 0) {
      throw runtime_error("Age cannot be negative.");
    }
    if (illnesses.empty()) {
      throw runtime_error("Patient must have at least one illness.");
    }
}
 void Patient:: increase_wealth(unsigned x)
 {
  wealth += x;
 }
 bool Patient:: pay_procedure(unsigned x)
 {
  if (wealth >= x) 
  {
      wealth -= x;
      return true;
  } 
   return false;
 }
string Patient:: get_name() const
{
   return name;
}
 void Patient:: catch_disease(const Illness& x)
 {
  illnesses.insert(x);
 }
 
 bool Patient:: requires_treatment_in(Medical_Specialty x) const
 {
  for (const auto& illness : illnesses) {
      if (illness.get_specialty() == x) {
        return true;
      }
    }
    return false;
 }
 
 bool Patient:: healthy() const
 {
  return illnesses.empty();
 }
 
 unsigned Patient:: cure(Medical_Specialty x)
 {
  unsigned count = 0;
    auto it = illnesses.begin();
    while (it != illnesses.end()) {
      if (it->get_specialty() == x) {
        it = illnesses.erase(it);
        ++count;
      } else {
        ++it;
      }
    }
    return count;
 }
 
 bool operator==(const Patient& p,const Patient& p1)
 {
   return ((p.name == p1.name) && (p.age == p1.age) &&(p.illnesses == p1.illnesses) && (p.wealth == p1.wealth));
 }
 
 ostream& Patient:: print(ostream& o)const
 {
  o << "[" << name << ", " << age << " years, {";
    if (!illnesses.empty()) {
        auto it = illnesses.begin();
        o << *it;
        ++it;
        while (it != illnesses.end()) {
            o << ", " << *it;
            ++it;
        }
    }
    o << "}, " << wealth << " moneyz]";
   return o;
 }
ostream& operator<<(ostream& o,const Patient& p)
{
 return p.print(o);
}
