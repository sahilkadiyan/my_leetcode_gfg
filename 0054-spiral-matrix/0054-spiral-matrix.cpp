class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>arr(n,vector<int>(m));
        int dir = 1,tot = n*m;
        int ct = 0,i = 0,j = 0;
        vector<int>ans;
        while(ct < tot){
            if(dir == 1){
                while(j < m && arr[i][j] == 0){
                    ans.push_back(matrix[i][j]);
                    arr[i][j] = 1;
                    j++;
                    ct++;
                }
                j--;
                i++;
                dir = 2;
            }
            else if(dir == 2){
                while(i < n && arr[i][j] == 0){
                    ans.push_back(matrix[i][j]);
                    arr[i][j] = 1;
                    i++;
                    ct++;
                }
                i--;
                j--;
                dir = 3;
            }
            else if(dir == 3){
                while(j >= 0 && arr[i][j] == 0){
                    ans.push_back(matrix[i][j]);
                    arr[i][j] = 1;
                    j--;
                    ct++;
                }
                j++;
                i--;
                dir = 4;
            }
            else if(dir == 4){
                while(i >= 0 && arr[i][j] == 0){
                    ans.push_back(matrix[i][j]);
                    arr[i][j] = 1;
                    i--;
                    ct++;
                }
                i++;
                j++;
                dir = 1;
            }
        }
        return ans;
    }
};