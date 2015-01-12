#include <iostream>
#include <string>
#include <vector>
#include <iterator>

//Notations:
// T: Given Text [0...n]
// P: Pattern [0...m]
// n: Text length - 1
// m: Pattern length - 1
// F: Finite automata states (a.k.a Table) Pi in CLRS
// F spans from [0,m]. final state (m) is the acceptance state
// q: current state in Automata
// k: a value < q and Pk =] Pq. (Pk is a proper suffix of Pq)
// i.e Pk is the longest prefix of P that is a strict suffix of Pq
// The algorithm goes in two steps.
// First step build the F Table (Finite Automata table for the pattern)
//
// Building the automata states:
// F[q] contains the the longest prefix of P that is a proper suffix of Pq
// P[0] has only one character and thus, can not be a proper suffix of any Pk
// So, Start with F[0] = -1 and k = -1
// While filling F[q] k value will represent F[q-1]. Thus, k will tell what was the longest prefix of P that was
// proper suffix of Pq-1.
// So, as long as P[q] is not matching P[k+1], we can not have a bigger prefixes ending at P[q]
// thus, try F[k] as the new k
// when P[q] is same as P[k+1], increment k
// store F[q] = k
using namespace std;
void build(vector<int> &F, string &P) {
    int k = -1;
    F[0] = -1;
    for (int q = 1; q < F.size(); q++) {
        while(k > -1 && P[q] != P[k+1]) {
            k = F[k];
        }
        if (P[q] == P[k+1]) {
            k++;
        }
        F[q] = k;
    }
}

//Rules for text matching.
//Start with state (q) as -1. When q reaches m, we have matched pattern
//During text traversal q represents the current state FSA is in
//if T[i] is not matching P[q+1] then go back in FSA to previous states until a valid state can be reached
//if T[i] is matching P[q+1] then, we can move to next state by increment q++
//if q has reached mth state declare the pattern match
int main() {
    string T,P;
    cin >> T >> P;
    cout << T << endl << P << endl;

    vector<int> F(P.size(),-1);
    build(F,P);

    copy(F.begin(),F.end(),ostream_iterator<int>(cout," "));
    cout << endl;

    int q = -1;
    int m = P.size()-1;
    for (int i = 0; i < T.size(); i++) {
        while (q > -1 && T[i] != P[q+1]) {
            q = F[q];
        }
        if (T[i] == P[q+1]) {
            q++;
        }
        if (q == m) {
            cout << "Matched at " << i-q << endl;
            q = -1;
        }
    }
}
