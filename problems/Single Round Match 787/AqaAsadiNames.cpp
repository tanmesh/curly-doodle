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

class AqaAsadiNames {
public:
    string getName(string Dad, string Mom, string FirstChild, string Gender) {
        string dadFN, dadLN, momFN, momLN, fcFN, fcLN;

        int i = Dad.find(" ");
        dadFN = Dad.substr(0, i);
        dadLN = Dad.substr(i + 1);

        i = Mom.find(" ");
        momFN = Mom.substr(0, i);
        momLN = Mom.substr(i + 1);

        i = FirstChild.find(" ");
        fcFN = FirstChild.substr(0, i);
        fcLN = FirstChild.substr(i + 1);

        string fcGender = "Boy";
        if (fcFN[0] == 'A' || fcFN[0] == 'E' || fcFN[0] == 'I' || fcFN[0] == 'O' || fcFN[0] == 'U' || fcFN[0] == 'Y') {
            fcGender = "Girl";
        }

        string ans;
        if (fcGender == Gender) {
            if (Gender == "Boy") {
                ans = dadFN + ' ' + fcLN;
            } else {
                ans = momFN + ' ' + fcLN;
            }
        } else {
            if (Gender == "Boy") {
                ans = dadLN + ' ' + dadFN;
            } else {
                ans = momLN + ' ' + momFN;
            }
        }
        return ans;
    }
};

// CUT begin
ifstream data("AqaAsadiNames.sample");

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

bool do_test(string Dad, string Mom, string FirstChild, string Gender, string __expected) {
    time_t startClock = clock();
    AqaAsadiNames *instance = new AqaAsadiNames();
    string __result = instance->getName(Dad, Mom, FirstChild, Gender);
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
        string Dad;
        from_stream(Dad);
        string Mom;
        from_stream(Mom);
        string FirstChild;
        from_stream(FirstChild);
        string Gender;
        from_stream(Gender);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(Dad, Mom, FirstChild, Gender, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1592755502;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "AqaAsadiNames (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
