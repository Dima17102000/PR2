#include "illness.h"
#include<vector>
#include<string>
#include<iostream>


const std::vector<std::string>medical_names{"Cardiology","Dermatology","Endocrinology","Gynecology", "Neurology","Oncology","Pathology","Pediatrics","Pulmonology","Urology"};

ostream& operator<<(ostream& o,const Medical_Specialty& med)
{
   o << medical_names.at(static_cast<int>(med));
  return o;
}
Illness:: Illness(Medical_Specialty med,string name): med{med},name{name}
{
 if(name.empty())
 throw runtime_error("Name is empty");
}
string Illness:: get_name()const
{
 return name;
}
 Medical_Specialty Illness:: get_specialty()const
 {
  return med;
 }
 bool operator==(const Illness& ill,const Illness& ill1)
 {
  return((ill.name == ill1.name)&&(ill.med == ill1.med));
 }
 bool operator<(const Illness& ill,const Illness& ill1)
 {
  if(ill.med < ill1.med)
  {
    return true;
  }
  if(ill.med == ill1.med)
  {
    return lexicographical_compare(ill.name.begin(),ill.name.end(),ill1.name.begin(),ill1.name.end());
  }
   return false;
 }
 ostream& Illness::print(ostream& o)const
 {
  o << "[" << medical_names.at(static_cast<size_t>(med)) << ", " << name << "]";
  return o;
 }
 
 ostream& operator<<(ostream& o, const Illness& ill)
 {
   return ill.print(o);
 }
