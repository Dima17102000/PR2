#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
class Player{
 private:
  std::string name;
 public:
  Player(std::string name): name(name){}
  const std::string get_name() const{
   return this->name;
  }
};
std::ostream& operator<<(std::ostream& os, const Player& p){
 os << p.get_name();
 return os;
}

int main(){
 /*
 std::string s = "Jimmy";
 std::for_each(s.begin(), s.end(), [](auto c){std::cout << c;});
 std::cout << std::endl;
*/
/*
 std::vector<std::string> v = {"Carl", "Bob", "Pedro"};
 std::for_each(v[1].begin(), v[1].end(), [](auto c){std::cout << c;});
 std::cout << std::endl;
*/
 /*std::vector<Player>v{{"Bob"}, {"Carl"}, {"Sally"}, {"Frank"}, {"Jesus"}, {"Leroy"}, {"Bob"}};
  std::for_each(v[2].get_name().begin(), v[2].get_name().end(), [](auto& c){std::cout << c;});
 std::cout << std::endl;
*/
/*
 std::string s = "Jimmy";
 std::string s1 = s;
 //std:: cout << s1 << '\n';
 std::for_each(s1.begin(), s1.end(), [](auto c){std::cout << c;});
 std::cout << std::endl;
 */
 
 Player p = {"Jimmy"};
 std::string s1 = p.get_name();
 std::for_each(s1.begin(), s1.end(), [](auto c){std::cout << c;});
 std::cout << std::endl;
 
 /*Player p = {"Carl"};
 std::cout << &p.get_name() << std::endl;
 std::cout << &p.get_name() << std::endl;
 */
 return 0;
}
