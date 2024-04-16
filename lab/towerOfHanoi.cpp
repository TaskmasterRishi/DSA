#include <bits/stdc++.h>
using namespace std;

void moveDisk(vector<int> &source, vector<int> &destination)
{
    destination.push_back(source.back());
    source.pop_back();
}

void towerOfHanoi(int n, vector<int> &from_rod, vector<int> &to_rod, vector<int> &aux_rod, int from, int to)
{
    if (n == 1)
    {
        moveDisk(from_rod, to_rod);
        cout << "Move disk " << to_rod.back() << " from rod " << from << " to rod " << to << endl;
        return;
    }

    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod, from, 6 - from - to);
    moveDisk(from_rod, to_rod);
    cout << "Move disk " << to_rod.back() << " from rod " << from << " to rod " << to << endl;
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod, 6 - from - to, to);
}

int main()
{
    int numDisks;
    cout << "Enter the number of disks: ";
    cin >> numDisks;

    vector<int> source;
    vector<int> destination;
    vector<int> auxiliary;

    for (int i = numDisks; i >= 1; --i)
    {
        source.push_back(i);
    }

    towerOfHanoi(numDisks, source, destination, auxiliary, 1, 3);
    return 0;
}
