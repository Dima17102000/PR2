#ifndef ILLNESS_H
#define ILLNESS_H

#include<iostream>
#include<stdexcept>
#include<string>
#include<vector>

using namespace std;

enum class Medical_Specialty{Cardiology,Dermatology,Endocrinology,Gynecology, Neurology, Oncology,Pathology,Pediatrics,Pulmonology,Urology};
ostream& operator<<(ostream& o,const Medical_Specialty&);
class Illness
{
  
 Medical_Specialty med;
 string name;
 public:
 Illness(Medical_Specialty med,string);
 string get_name()const;
 Medical_Specialty get_specialty()const;
 friend bool operator==(const Illness& ill,const Illness& ill1);
 friend bool operator<(const Illness& ill,const Illness& ill1);
 ostream& print(ostream&)const;
};
ostream& operator<<(ostream&,const Illness&);
#endif

