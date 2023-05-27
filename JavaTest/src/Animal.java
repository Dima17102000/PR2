public class Animal {
    private String name;

    // constructors, same as C++
    Animal() {name = "N/A";}
    Animal(String name_) {name = name_;}

    public String getName() {return name;}
    public void setName(String new_name) {name = new_name;}

    public String toString() {
        return "My name is [" + name + "]";
    }
}