class Solution {
public:
    int dayOfYear(string date) {
        vector days{31,28,31,30,31,30,31,31,30,31,30,31};
        int y = stoi(date.substr(0,4));
        if((y%4 == 0 && y%100 != 0) || (y%400 == 0))
            days[1] = 29;
        int month = stoi(date.substr(5,2));
        int ans = stoi(date.substr(8,2));
        for(int i = 0; i < month-1; ++i)
            ans += days[i];
        return ans;
    }
};