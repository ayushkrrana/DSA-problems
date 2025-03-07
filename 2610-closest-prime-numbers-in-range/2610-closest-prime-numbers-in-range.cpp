class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> prime(right + 1, 1);
        prime[0] = prime[1] = 0;
        vector<int> ans = {-1, -1};

        // Sieve of Eratosthenes to find prime numbers
        for (int i = 2; i * i <= right; i++) {
            if (prime[i]) {
                for (int j = i * i; j <= right; j += i) {
                    prime[j] = 0;
                }
            }
        }

        vector<int> primes;
        
        // Store prime numbers in range
        for (int i = left; i <= right; i++) {
            if (prime[i]) {
                primes.push_back(i);
            }
        }
        
        // If there are less than 2 primes, return {-1, -1}
        if (primes.size() < 2) return ans;
        
        // Find the closest pair
        int minDiff = INT_MAX;
        for (int i = 1; i < primes.size(); i++) {
            if (primes[i] - primes[i - 1] < minDiff) {
                minDiff = primes[i] - primes[i - 1];
                ans = {primes[i - 1], primes[i]};
            }
        }
        
        return ans;
    }
};
