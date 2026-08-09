class Solution {
public:
    int n;
    int t[2][101][101]; // person (0 for Bob, 1 for Alice), i, M
    
    int solveForAlice(vector<int>& piles, int person, int i, int M) {
        if(i >= n) // Base case: no more piles
            return 0;
        
        if(t[person][i][M] != -1) // Check if already computed
            return t[person][i][M];
        
        int result;
        if(person == 1) { // Alice's turn (maximizing)
            result = -1;
            int stones = 0;
            for(int x = 1; x <= min(2*M, n-i); x++) {
                stones += piles[i+x-1];
                result = max(result, stones + solveForAlice(piles, 0, i+x, max(M, x)));
            }
        } else { // Bob's turn (minimizing)
            result = INT_MAX;
            int stones = 0;
            for(int x = 1; x <= min(2*M, n-i); x++) {
                stones += piles[i+x-1];
                result = min(result, solveForAlice(piles, 1, i+x, max(M, x)));
            }
        }
        
        return t[person][i][M] = result;
    }
    
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        // Initialize memoization table with -1
        memset(t, -1, sizeof(t));
        return solveForAlice(piles, 1, 0, 1);
    }
};