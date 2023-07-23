class Solution {
    const int MOD = 1e9 + 7;

    bool isPrime(int num) {
        if (num < 2)
            return false;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0)
                return false;
        }
        return true;
    }

public:
    int numPrimeArrangements(int n) {
        int primeCount = 0;
        for (int i = 1; i <= n; i++) {
            if (isPrime(i)) {
                primeCount++;
            }
        }

        int nonPrimeCount = n - primeCount;

        long long result = 1;
        for (int i = 2; i <= primeCount; i++) {
            result = (result * i) % MOD;
        }
        for (int i = 2; i <= nonPrimeCount; i++) {
            result = (result * i) % MOD;
        }

        return result;
    }
};
