#include<iostream>
#include<stdexcept>
#include<map>
#include<vector>
#include<memory>
#include<algorithm>
#include "hcp.h"
#include "illness.h"
#include "patient.h"



Health_Care_Provider::Health_Care_Provider(string name, const set<Medical_Specialty>& topics, unsigned wealth) : name(name), topics(topics), wealth(wealth) 
{
  if (name.empty()) 
  {
    throw runtime_error("Name cannot be empty.");
  }
}

string Health_Care_Provider:: get_name() const 
{
  return name;
}

Health_Care_Provider:: ~Health_Care_Provider() = default;

void Health_Care_Provider:: increase_wealth(unsigned x) 
{
  wealth += x;
}


//unsigned Health_Care_Provider:: perform_procedure(unsigned, std::shared_ptr<Patient>, Medical_Specialty) = 0;

//string Health_Care_Provider:: hcp_type() const = 0;


bool Health_Care_Provider:: pay_license(unsigned x) 
{
  if (wealth >= x) 
  {
    wealth -= x;
    return true;
  }
  return false;
}

void Health_Care_Provider:: receive_license(Medical_Specialty x) 
{
  topics.insert(x);
}

bool Health_Care_Provider:: eligible_for(Medical_Specialty m) 
{
  return topics.count(m) > 0;
}

ostream& Health_Care_Provider::print(std::ostream& o) const {
    o << "[" << name << ", {";
    if (!topics.empty()) 
    {
        auto it = topics.begin();
        o << *it;
        ++it;
        while (it != topics.end()) {
            o << ", " << *it;
            ++it;
        }
    }
  
    /*for (const auto& topic : topics) {
        o << " " << static_cast<size_t>(topic) << ",";
    }
    */
    o << "}, " << wealth << " moneyz, " << hcp_type() << "]";
    return o;
}

ostream& operator<<(ostream& o, const Health_Care_Provider& h)
{
  return h.print(o);
}


Teaching_Health_Care_Provider::Teaching_Health_Care_Provider(unsigned fee,string name,
                                                             const set<Medical_Specialty>& topics, unsigned wealth)
    : Health_Care_Provider(name, topics, wealth), fee(fee) {
}

unsigned Teaching_Health_Care_Provider::perform_procedure(unsigned x, shared_ptr<Patient> p, Medical_Specialty m) {
  if (eligible_for(m) && p->requires_treatment_in(m) && p->pay_procedure(x)) {
        increase_wealth(x);
        return p->cure(m);
    }
    return 0;
}


string Teaching_Health_Care_Provider::hcp_type() const {
  return "Teacher";
}

bool Teaching_Health_Care_Provider::teach(Medical_Specialty m, shared_ptr<Health_Care_Provider> target) {
  if (target.get() == this || target->eligible_for(m) || !eligible_for(m) || !target->pay_license(fee)) 
  {
        return false;
  }
    increase_wealth(fee);
    target->receive_license(m);
    return true;
}



Smart_Health_Care_Provider::Smart_Health_Care_Provider(unsigned fee,string name,
                                                       const set<Medical_Specialty>& topics, unsigned wealth)
    : Health_Care_Provider(name, topics, wealth), fee(fee) {
}

unsigned Smart_Health_Care_Provider::perform_procedure(unsigned x, shared_ptr<Patient> p, Medical_Specialty m) 
{
  
  if (eligible_for(m) && p->requires_treatment_in(m) && p->pay_procedure(x)) 
  {
        return 1;
  }
  return 0;
}

string Smart_Health_Care_Provider::hcp_type() const {
  return "Smart";
}

void Smart_Health_Care_Provider::receive_license(Medical_Specialty m) {
  Health_Care_Provider::receive_license(m);
  increase_wealth(fee);
}




