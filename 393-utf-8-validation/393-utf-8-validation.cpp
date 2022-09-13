class Solution {
public:
  string change(int n) {
		if(n == 0) return "0";
		else if(n == 1) return "1";
		char a = '0' + n % 2;
		return change(n / 2) + a;
	}
	bool validUtf8(vector<int>& data) {
		int i = 0, n = data.size();
		while(i < data.size()) {
			string s = change(data[i]);
			int count = 0;
			if(s.size() == 8 && s[0] != '0') {
				while(count < 4 && s[count] == '1') count ++;
				if(s[count] != '0' || i + count > n || count < 2) return false;
				for(int j = 1; j < count; j ++) {
					string s1 = change(data[i + j]);
					if(s1.size() < 8 || s1[0] != '1' || s1[1] != '0') return false;
				}
			}
			if(count == 0) count ++;
			i += count;
		}
		return true;
	}
};