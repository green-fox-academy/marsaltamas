#include <iostream>

using namespace std;

// Create a Class named Integer. It should have one int member variable.
// Create add() methods to it. They should take Integer& parameters.
// Make variations of add() method 1, 2, 3, 4 and 5 arguments respectively.
// All methods should add the value of the parameters to the member variable of this.
//
// Try them out. Write code that demonstrates how they work.

class Integer {

    public:
        Integer(int a)
        {
            mNum = a;
        };
        int get_mnum()
        {
            return mNum;
        };
        int add(Integer& _integer1)
        {
            return mNum + _integer1.get_mnum();
        };
        int add(Integer& _integer1, Integer& _integer2)
        {
            return mNum + _integer1.get_mnum() + _integer2.get_mnum();
        };
        int add(Integer& _integer1, Integer& _integer2, Integer& _integer3)
        {
        return mNum + _integer1.get_mnum() + _integer2.get_mnum() + _integer3.get_mnum();
        };
        int add(Integer& _integer1, Integer& _integer2, Integer& _integer3, Integer& _integer4)
        {
            return mNum + _integer1.get_mnum() + _integer2.get_mnum() + _integer3.get_mnum() + _integer4.get_mnum();
        };
        int add(Integer& _integer1, Integer& _integer2, Integer& _integer3, Integer& _integer4, Integer& _integer5)
        {
            return mNum + _integer1.get_mnum() + _integer2.get_mnum() + _integer3.get_mnum() + _integer4.get_mnum() + _integer5.get_mnum();
        };
    private:
        int mNum;

};

int main()
{
    Integer a(1);

    cout << "Integer a.mNum before adders: " << a.get_mnum() << endl;

    cout << "Adder 1: " << a.add(a) << endl;
    cout << "Adder 2: " << a.add(a, a) << endl;
    cout << "Adder 3: " << a.add(a, a, a) << endl;
    cout << "Adder 4: " << a.add(a, a, a, a) << endl;
    cout << "Adder 5: " << a.add(a, a, a, a, a) << endl;

    cout << "Integer a.mNum after adders: " << a.get_mnum() << endl;

	return 0;
}
