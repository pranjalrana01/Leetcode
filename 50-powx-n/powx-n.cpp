class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1.0;

        long long absN = abs(static_cast<long long>(n));
        double result = myPowHelper(x, absN, 1.0);
        return (n < 0) ? 1.0 / result : result;
    }

private:
    double myPowHelper(double x, long long n, double acc) {
        if (n == 0)
            return acc;
        if (n % 2 == 1)
            return myPowHelper(x * x, n / 2, acc * x);
        else
            return myPowHelper(x * x, n / 2, acc);
    }
};