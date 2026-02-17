class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;
        for(int h = 0;h<12;h++){
            for(int m=0;m<60;m++){
                int total = __builtin_popcount(h) + __builtin_popcount(m); 
                // #1's in Binary Representation of an integer like 5 --> 101 so it's "two" 1's 
                
                if(total == turnedOn){
                    string time = to_string(h) + ":"; //number to string conversion
                    if(m<10)
                    time += "0"; // 11:09 , 9:04 , ...