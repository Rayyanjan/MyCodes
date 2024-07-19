#include <iostream>
using namespace std;

class Tool{
    protected:
    int strength;
    char type;
    public:
    Tool(int n, char t) : strength(n), type(t) {}

    void setStrength(int s) {   
        strength = s;
    }
    int getstrength(){
        return strength;
    }
    char getType() const {
        return type;
    }
};
class Rock : public Tool{
    public:
    Rock(int s) : Tool (s,'r'){}
    bool fight(Tool opponent){
        int tempStrength = getstrength();
        if (opponent.getType() == 's') {
            tempStrength *= 2; 
        } else if (opponent.getType() == 'p') {
            tempStrength /= 2; 
        }
        return tempStrength > opponent.getstrength();}
};
class Paper : public Tool{
    public:
    Paper(int s) : Tool (s,'p'){}
    bool fight(Tool opponent){
        int tempStrength = getstrength();
        if (opponent.getType() == 'r') {
            tempStrength *= 2; 
        } else if (opponent.getType() == 's') {
            tempStrength /= 2; 
        }
        return tempStrength > opponent.getstrength();}
};
class Scissor : public Tool{
    public:
    Scissor(int s) : Tool (s,'s'){}
    bool fight(Tool opponent){
        int tempStrength = getstrength();
        if (opponent.getType() == 'p') {
            tempStrength *= 2; 
        } else if (opponent.getType() == 'r') {
            tempStrength /= 2; 
        }
        return tempStrength > opponent.getstrength();}
};
int main() {
// Example main function
// You may add your own testing code if you like
Scissor s1(5);
Paper p1(7);
Rock r1(10);
cout << s1.fight(p1) << p1.fight(s1) << endl;
cout << p1.fight(r1) << r1.fight(p1) << endl;
cout << r1.fight(s1) << s1.fight(r1) << endl;
return 0;
}
