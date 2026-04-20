#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, int> votes;
    string name;

    // Count votes
    for (int i = 0; i < n; i++) {
        cin >> name;
        votes[name]++;
    }

    string winner;
    int maxVotes = 0;

    // Find winner
    for (auto it : votes) {
        if (it.second > maxVotes) {
            maxVotes = it.second;
            winner = it.first;
        }
    }

    cout << winner << " " << maxVotes << endl;

    return 0;
}