class Solution {
public:
    int totalFruit(vector<int>& fruits) {
         int n = fruits.size();
        int basket[] = {fruits[n - 1], -1};
        int count[] = {1, 0};
        int score = 1;
        int fin = n - 1;
        for (int k = n - 2; k >= 0; k--) {            
            // New element found
            if (fruits[k] != basket[0] && fruits[k] != basket[1]) {
                // Score will only decrease at this step
                if (score < fin - k) {
                    score = fin - k;
                }
                // Decrement end of sliding window
                while (count[1] && count[0]) {
                    count[fruits[fin] == basket[0] ? 0 : 1]--;
                    fin--;
                }
                // Replace emptied basket
                int state = !count[0] ? 0 : 1;
                basket[state] = fruits[k];
                count[state] = 1;
            }
            // Increment existing element
            else {
                count[fruits[k] == basket[0] ? 0 : 1]++;
            }

        }
        return score < fin + 1 ? fin + 1 : score;
    }
};