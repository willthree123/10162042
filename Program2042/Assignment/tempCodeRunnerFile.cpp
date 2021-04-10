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