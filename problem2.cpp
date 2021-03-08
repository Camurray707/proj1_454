#include <iostream>
#include <sstream>
#include "vector"
#include "queue"
#include "cmath"
using namespace std;

void trace(vector<int> parent, vector<int> label, int a)
{
    int parentval = parent[0];
    std::vector<int> inorder;
    inorder.push_back(label[0]);
    while (parentval != a)
    {
        inorder.push_back(label[parentval]);
        parentval = parent[parentval];
    }
    string complete;
    for (int i = inorder.size() - 1; i >= 0; i--)
    {
        string b = to_string(inorder[i]);
        complete += b;
    }
    cout << "num: " << complete <<endl;
}

int Delta(int current, int val, int input)
{
    return (10 * current + val) % input;
}
int main()
{
    int a;
    cout << "Enter a number k\n";
    cin >> a;
    if (a > 99999)
    {
        cout << "K cannot be greater than 99999\n";
    }
    cin.ignore();
    string x;
    cout << "Enter Q as a whitespace seperated list: \n";
    getline(cin, x);
    istringstream check1(x);
    vector<string> tokens;
    string intermediate;
    while (getline(check1, intermediate, ' '))
    {
        tokens.push_back(intermediate);
    }
    std::vector<int> vals;
    for (int i = 0; i < tokens.size(); i++)
    {
        vals.push_back(stoi(tokens.at(i)));
    }
    //vals now contains input in a vector with whitespace removed
    for (int i = 0; i < vals.size(); i++)
    {
        if (vals.at(i) > 9)
        {
            vals.erase(vals.begin() + i);
        }
    }
    //algo for find string
    //initalize queue
    queue<int> queue;

    //create vector visited
    vector<bool> visisted(a, 0);

    //visisted.push_back(1);
    int size = visisted.size();
    vector<int> label(size, 0);
    vector<int> parent(size, 0);
    int next = a;
    queue.push(next);

    while (!queue.empty())
    {
        int current = queue.front();
        queue.pop();
        bool fin = false;
        for (int i = 0; i < vals.size(); i++)
        {
            next = Delta(current, vals.at(i), a);
            if (next == 0)
            {
                fin = true;
                visisted[next] = 1;
                parent[next] = current;
                label[next] = vals.at(i);
                break;
            }
            else if (!visisted[next])
            {
                visisted[next] = 1;
                parent[next] = current;
                label[next] = vals.at(i);
                queue.push(next);
            }
        }
        if (fin == true)
        {
            break;
        }
    }
    if (next != 0)
    {
        cout << "no solution";
    }
    else
    {
        trace(parent, label, a);
    }
    return 0;
}
