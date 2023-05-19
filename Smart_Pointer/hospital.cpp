#include<iostream>
#include<stdexcept>
#include<map>
#include<vector>
#include<memory>
#include<algorithm>

#include "hcp.h"
#include "illness.h"
#include "patient.h"
#include "hospital.h"


Hospital::Hospital(string name) : name(name) {
    if (name.empty()) {
        throw std::runtime_error("Name cannot be empty.");
    }
}

bool Hospital::sign_hcp(std::shared_ptr<Health_Care_Provider> m) {
    if (hcps.find(m->get_name()) == hcps.end()) {
        hcps[m->get_name()] = m;
        return true;
    }
    return false;
}

bool Hospital::admit_patient(std::shared_ptr<Patient> m) {
    if (patients.find(m->get_name()) == patients.end() || patients[m->get_name()].expired()) {
        patients[m->get_name()] = m;
        return true;
    }
    return false;
}

bool Hospital::dismiss_hcp(string n) {
    auto it = hcps.find(n);
    if (it != hcps.end()) {
        hcps.erase(it);
        return true;
    }
    return false;
}

std::shared_ptr<Health_Care_Provider> Hospital::get_hcp(string n) const {
    auto it = hcps.find(n);
    if (it == hcps.end()) {
        throw std::runtime_error("HCP not found.");
    }
    return it->second;
}

std::shared_ptr<Patient> Hospital::get_patient(string n) const {
    auto it = patients.find(n);
    if (it == patients.end() || it->second.expired()) {
        throw std::runtime_error("Patient not found or expired.");
    }
    return it->second.lock();
}

bool Hospital::dismiss_patient(string n) {
    auto it = patients.find(n);
    if (it != patients.end() && !it->second.expired()) {
        patients.erase(it);
        return true;
    }
    return false;
}

ostream& Hospital:: print(ostream& o)const
{
  o << "[" << name << ", hcps {";
   if (!hcps.empty()) {
        auto it = hcps.begin();
        o << *it->second;
        ++it;
        while (it != hcps.end()) {
            o << ", " << *it->second;
            ++it;
        }
    }
    o << "}, patients {";
    if (!patients.empty()) {
        auto it = patients.begin();
        if (!it->second.expired()) {
            o << *it->second.lock();
        }
        ++it;
        while (it != patients.end()) {
            if (!it->second.expired()) {
                o << ", " << *it->second.lock();
            }
            ++it;
        }
    }
    o << "}]";
    return o;
}

ostream& operator<<(ostream& o,const Hospital& h)
{
  return h.print(o);
}
