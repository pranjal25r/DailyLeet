1class Solution {
2public:
3    string makeLargestSpecial(string s) {
4      vector<string> special;
5      int start = 0, count = 0;
6
7      for(int i = 0;i<s.size();i++){
8        if(s[i] == '1') 
9        count++;
10
11        else
12        count--;
13
14        if(count == 0){
15            string inn = s.substr(start + 1, i - start - 1);
16            string processed = "1" + makeLargestSpecial(inn) + "0";
17            special.push_back(processed);
18            start = i+1;
19        }
20      }
21
22      sort(special.begin(), special.end(),greater<string>());
23
24      string result = "";
25      for(string &str : special)
26      result += str;
27
28      return result;
29
30    }
31};