#ifndef HPC_H
#define HPC_H

#include<iostream>
#include<stdexcept>
#include<set>
#include<vector>
#include<memory>
#include<string>

#include "illness.h"
#include "patient.h"

using namespace std;

class Health_Care_Provider
{
  string name;
  set<Medical_Specialty> topics;
  unsigned wealth;
  public:
  Health_Care_Provider(string,const set<Medical_Specialty>&,unsigned wealth=500);
  string get_name() const;
  virtual ~Health_Care_Provider();
  void increase_wealth(unsigned x);
  virtual unsigned perform_procedure(unsigned,shared_ptr<Patient>, Medical_Specialty) = 0;
  virtual string hcp_type() const = 0;
  bool pay_license(unsigned x);
  virtual void receive_license(Medical_Specialty x);
  bool eligible_for(Medical_Specialty m);
  ostream& print(ostream&)const;
};
ostream& operator<<(ostream&,const Health_Care_Provider&);

class Teaching_Health_Care_Provider : public Health_Care_Provider 
{
  unsigned fee;
  public:
  Teaching_Health_Care_Provider(unsigned fee,string, const set<Medical_Specialty>&, unsigned wealth = 500);
  unsigned perform_procedure(unsigned x, std::shared_ptr<Patient> p, Medical_Specialty m) override;
  std::string hcp_type() const override;
  bool teach(Medical_Specialty m, std::shared_ptr<Health_Care_Provider> target);
};

class Smart_Health_Care_Provider : public Health_Care_Provider 
{
  unsigned fee;
  public:
  Smart_Health_Care_Provider(unsigned fee,string, const set<Medical_Specialty>& t, unsigned wealth = 500);
  unsigned perform_procedure(unsigned x, std::shared_ptr<Patient> p, Medical_Specialty m) override;
  string hcp_type() const override;
  void receive_license(Medical_Specialty m) override;
};


#endif

