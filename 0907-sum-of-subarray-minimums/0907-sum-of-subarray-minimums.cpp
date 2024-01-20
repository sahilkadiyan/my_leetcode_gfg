class Solution {
public:
  int sumSubarrayMins(vector<int> &A) {
    stack<pair<int, int>> in_stk_p, in_stk_n;
    // left is for the distance to previous less element
    // right is for the distance to next less element
    vector<long> left(A.size()), right(A.size());

    // initialize
    /*
When in_stk_p is empty, which means there is no previous less element for A[i], in this case, we set left[i] = i+1 by default.
For example [7 8 4 3], there is no PLE for element 4, so left[2] = 2+1 =3.
How many subarrays with 4(A[2]) being its minimum value?
It's left[2]*right[2]=3*1.
So the default value i+1 for left[i] and the default value n-i for right[i] are for counting the subarrays conveniently.
*/
    for (int i = 0; i < A.size(); i++) {
      left[i] = i + 1;
      right[i] = A.size() - i;
    }

    for (int i = 0; i < A.size(); i++) {
      // for previous less
      while (!in_stk_p.empty() && in_stk_p.top().first > A[i]) {
        in_stk_p.pop();
      }
      left[i] = in_stk_p.empty() ? i + 1 : i - in_stk_p.top().second;
      in_stk_p.push({A[i], i});

      // for next less
      while (!in_stk_n.empty() && in_stk_n.top().first > A[i]) {
        auto x = in_stk_n.top();
        in_stk_n.pop();
        right[x.second] = i - x.second;
      }
      in_stk_n.push({A[i], i});
    }

    constexpr int mod = 1e9 + 7;
    long res = 0;
    for (int i = 0; i < A.size(); i++) {
      res = (res + A[i] * left[i] * right[i]) % mod;
    }
    return res;
  }
};