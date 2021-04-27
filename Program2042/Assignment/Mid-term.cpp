#include <iostream>
#include <cmath>
using namespace std;
// Implement the class Number here
class Number
{
public:
    Number(int c)
    {
        answer = c;
    }
    void multiply(int a)
    {
        answer *= a;
    }
    void insert(int b)
    {
        int f = ceil(log10(answer + 0.001));
        int tmp = b * ceil(pow(10, f));
        answer = (tmp += answer);
    }
    int value()
    {
        return answer;
    }

private:
    int answer;
};

int main()
{
    int num;
    cout << "Input a number: ";
    cin >> num;
    Number n(num);
    n.multiply(3);
    cout << "Multiply 3, value = " << n.value() << endl;
    n.insert(999);
    cout << "Insert 999, value = " << n.value() << endl;
    return 0;
}
