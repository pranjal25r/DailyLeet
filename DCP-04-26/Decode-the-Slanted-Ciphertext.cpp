1class Solution {
2public:
3    string decodeCiphertext(string encodedText, int rows) {
4        if (rows == 0) return "";
5
6        int n = encodedText.size();
7        int cols = n / rows;
8
9        // Step 1: Fill matrix row-wise
10        vector<vector<char>> mat(rows, vector<char>(cols));
11        int idx = 0;
12
13        for (int i = 0; i < rows; i++) {
14            for (int j = 0; j < cols; j++) {
15                mat[i][j] = encodedText[idx++];
16            }
17        }
18
19        // Step 2: Traverse diagonals
20        string result = "";
21
22        for (int startCol = 0; startCol < cols; startCol++) {
23            int i = 0, j = startCol;
24
25            while (i < rows && j < cols) {
26                result.push_back(mat[i][j]);
27                i++;
28                j++;
29            }
30        }
31
32        // Step 3: Remove trailing spaces
33        while (!result.empty() && result.back() == ' ') {
34            result.pop_back();
35        }
36
37        return result;
38    }
39};