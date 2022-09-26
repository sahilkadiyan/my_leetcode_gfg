class Solution {
private:
    int par[26], sz[26];
public:
    int anc(int x) { // Path compression
        if (par[x] == x) return x;
        return par[x] = anc(par[x]);
    }
    void join(int x, int y) { // Union by size
        int anc_x = anc(x), anc_y = anc(y);
        if (sz[anc_x] > sz[anc_y]) swap(anc_x, anc_y);
        par[anc(x)] = anc(y);
        
        return;
    }
    
    bool equationsPossible(vector<string>& equations) {
        for (int i = 0; i < 26; i++) {
            sz[i] = 1;
            par[i] = i;
        }
        for (string& s : equations) {
            int u = s[0] - 'a', v = s[3] - 'a';
            if (s[1] == '=')   
                if (anc(u) != anc(v))
                    join(u, v);   
        }
        for (string& s : equations) {
            int u = s[0] - 'a', v = s[3] - 'a';
            if (s[1] == '!')   
                if (anc(u) == anc(v))
                    return false;                   
        }

        return true;
    }
};