// Find valid time points between starting time and ending time. A valid time point is one which involves at most two digits.
// Time is given in HH:MM:SS format
// For eg:  22:12:21 is a valid time point
//          23:32:11 isn't a valid time point

#include <bits/stdc++.h>
using namespace std;

bool isValidTimePoint(string str)
{
    set<char> s(str.begin(), str.end());
    return (s.size() <= 3);
}

int hr_to_sec(string s)
{
    int hrs = (s[0] - '0') * 10 + (s[1] - '0');
    int mins = (s[3] - '0') * 10 + (s[4] - '0');
    int secs = (s[6] - '0') * 10 + (s[7] - '0');
    
    return hrs * 3600 + mins * 60 + secs;
}

string sec_to_hr(int secs)
{
    int mins = secs / 60;
    int hrs = mins / 60;

    mins = mins % 60;
    secs = secs % 60;
    
    string h = (hrs < 10) ? "0" + to_string(hrs) : to_string(hrs);
    string m = (mins < 10) ? "0" + to_string(mins) : to_string(mins);
    string s = (secs < 10) ? "0" + to_string(secs) : to_string(secs);

    return h + ":" + m + ":" + s;
}

int solution(string &s, string &t)
{
    int t1 = hr_to_sec(s), t2 = hr_to_sec(t), cnt = 0;

    for(int i = t1; i <= t2; i++)
        if(isValidTimePoint( sec_to_hr(i) ))
          cnt++;
    
    return cnt;
}

int main() {
    
    string s1 = "00:00:00", s2 = "23:23:59";
    cout << solution(s1, s2);
    return 0;
}
