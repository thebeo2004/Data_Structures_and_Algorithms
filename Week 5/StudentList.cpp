#include <bits/stdc++.h>

using namespace std;

#define ff(i, a, b) for(int i = a; i <= b; i++)
#define Rep(i,a, b) for(int i = a; i >= b; i--)
#define MP make_pair
typedef long long ll;
typedef pair<int, int> pi;
const ll MAXN = 1e3 + 7;
const ll base = 311;
const ll INF = 1e9 + 7;

struct Student {
    int Id;
    string Name;
    string Class;

    Student(int Id, string Name, string Class) {
        this->Id = Id;
        this->Name = Name;
        this->Class = Class;
    }

    Student() {

    }

    int getId() {
        return Id;
    }

    void getInfor() {

        cout << Name << "," << Class << "\n";
    }
};

class StudentList {

    private:
        map<int, Student> storage;
    public:
        void insert(int Id, string Name, string Class) {
            if (!storage.count(Id)) {
                Student newStudent(Id, Name, Class);
                storage.insert(MP(Id, newStudent));
            }
        }

        void deleteElement(int Id) {
            storage.erase(Id);
        }

        void getInfor(int Id) {
            if (storage.count(Id)) {
                storage[Id].getInfor();
            } else {
                cout << "NA,NA\n";
            }
        }
};

StudentList OwO;

int convert(string number) {
    int ans = 0;

    for(auto i : number) {
        ans = ans * 10 + (int)i - 48;
    }

    return ans;
}

void readInsert(string txt) {

    string Id;
    string Name;
    string Class;

    int pos = 7;

    while(txt[pos] != ',') {
        Id += txt[pos];
        pos++;
    }

    pos++;

    while(txt[pos] != ',') {
        Name += txt[pos];
        pos++;
    }

    pos++;

    while(txt[pos] != ')') {
        Class += txt[pos];
        pos++;
    }

    OwO.insert(convert(Id), Name, Class);
}

void readDelete(string txt) {
    int pos = 7;

    string Id;

    while(txt[pos] != ')') {
        Id += txt[pos];
        pos++;
    }

    OwO.deleteElement(convert(Id));
}

void readInfor(string txt) {

    int pos = 6;

    string Id;

    while(txt[pos] != ')') {
        Id += txt[pos];
        pos++;
    }

    OwO.getInfor(convert(Id));
}

void solve() {
    
    string txt;

    while(cin >> txt) {
        if (txt[2] == 's') {
            readInsert(txt);
        } else if (txt[2] == 'f') {
            readInfor(txt);
        } else {
            readDelete(txt);
        }
    }
    
}

int main() {

    ios_base::sync_with_stdio(0); cin.tie(0);

    // freopen("X.inp", "r", stdin);
    // freopen("Y.out", "w", stdout);
    
    solve();

    return 0;
}
