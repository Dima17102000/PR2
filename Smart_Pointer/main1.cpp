#include "Patient.h"
#include "illness.h"

using namespace std;


int main ()
{
  Patient alice("Alice", 30, { flu });
  Patient bob("Bob", 45, { cancer, heart_disease }, 1000);
  Patient carol("Carol", 25, {}, 500); // throws exception: patient must have at least one illness
  Patient dave("", 50, { flu }, 200); // throws exception: name cannot be empty
  Patient eve("Eve", -10, { flu }, 300); // throws exception: age cannot be negative
  alice.increase_wealth(500);
  std::cout << "Alice's wealth: " << alice.wealth() << std::endl;
  bool success = alice.pay_procedure(300);
  std::cout << "Alice paid for procedure: " << success << std::endl;
  std::cout << "Alice's wealth: " << alice.wealth() << std::endl;
 alice.catch_disease(cancer);
  bob.catch_disease(flu);
  
  std::cout << "Bob requires oncology treatment: " << bob.requires_treatment_in(Medical_Specialty::Oncology) << std::endl;
  bob.cure(Medical_Specialty::Oncology);
  std::cout << "Bob requires oncology treatment: " << bob.requires_treatment_in(Medical_Specialty::Oncology) << std::endl;
 
 std::cout << alice.name << " is " << (alice.healthy() ? "healthy" : "not healthy") << std::endl;
  std::cout << bob.name << " is " << (bob.healthy() ? "healthy" : "not healthy") << std::endl;

  // remove all illnesses of a patient
  alice.cure(Medical_Specialty::General_Medicine);

  // check if patient is healthy again
  
  std::cout << alice.name << " is " << (alice.healthy() ? "healthy" : "not healthy") << std::endl;
  
  cout << alice == bob << endl;
  cout << alice << endl;
  cout << bob << endl;
 return 0;
}
