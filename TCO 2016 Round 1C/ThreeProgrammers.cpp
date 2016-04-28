#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>

using namespace std;

class ThreeProgrammers {
    public:
    string validCodeHistory(string code) {
        int a=0,b=0,c=0,l=code.length();
        bool fl=false;
        for(int i=0;i<l;i++)
        {
            if(code.at(i)=='A')
                a++;
            else if(code.at(i)=='B'){
                b++;
                if(i>0&&code.at(i-1)=='B') fl=true;
            }
            else{
                c++;
                if((i>0&&code.at(i-1)=='C')||(i>1&&code.at(i-2)=='C')) fl=true;
            }
        }
        int na=a,nb=b,nc=c,flb=0,flc=0;
        string s=code;
        if(fl){
            if(2*(b-1)==l-1){
                s="B";nb--;flb++;
                for(int i=0;i<l-1;i++){
                    if(flb<=0&&nb>0){
                        s+="B";
                        nb--;flb=2;
                    }
                    else if(flc<=0&&nc>0){
                        s+="C";
                        nc--;flc=3;
                    }
                    else if(na>0){
                        s+="A";
                        na--;
                    }
                    else{
                        s="impossible";
                        break;
                    }
                    flb--;flc--;
                }
            }
            else{
                s="";
                for(int i=0;i<l;i++){
                    if(flc<=0&&nc>0){
                        s+="C";
                        nc--;flc=3;
                    }
                    else if(flb<=0&&nb>0){
                        s+="B";
                        nb--;flb=2;
                    }
                    else if(na>0){
                        s+="A";
                        na--;
                    }
                    else{
                        s="impossible";
                        break;
                    }
                    flb--;flc--;
                }
            }
        }
        return s;
    }
};

// CUT begin
ifstream data("ThreeProgrammers.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(string code, string __expected) {
    time_t startClock = clock();
    ThreeProgrammers *instance = new ThreeProgrammers();
    string __result = instance->validCodeHistory(code);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        string code;
        from_stream(code);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(code, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1461773363;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "ThreeProgrammers (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
