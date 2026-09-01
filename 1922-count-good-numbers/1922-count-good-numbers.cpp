class Solution {
public:

    long long power(long long x, long long n, long long mod) {

        // Base case
        if (n == 0)
            return 1;

        // Calculate half
        long long half = power(x, n / 2, mod);

        // Even power
        if (n % 2 == 0)
            return (half * half) % mod;

        // Odd power
        return (half * half % mod * x) % mod;
    }

    int countGoodNumbers(long long n) {

        long long MOD = 1000000007;

        long long evenPositions = (n + 1) / 2;
        long long oddPositions = n / 2;

        long long evenWays =
            power(5, evenPositions, MOD);

        long long oddWays =
            power(4, oddPositions, MOD);

        return (evenWays * oddWays) % MOD;
    }
};