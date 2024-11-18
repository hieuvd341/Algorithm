#include <map>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <set>
using namespace std;
int n = 1, k = 5;
vector<int> Account(1000000, 0);
bool FLAG = false;
struct Bank
{   
    int from_account;
    int to_account;
    int money;
    string time_point, atm;
};

vector<Bank> bank;

int ConvertId(string s)
{
    int pos = 0;
    while (isalpha(s[pos]))
    {
        pos++;
    }
    return stoi(s.substr(pos));
}

void Try(int tmp, vector<int> &sol, vector<bool> &marked)
{
    if (FLAG == true)
        return;
    if (sol.size() == k)
    {
        for (Bank a : bank)
            if (a.from_account == sol[k - 1] && a.to_account == n)
            {
                FLAG = true;
                return;
            }
    }
    for (int i = 0; i < bank.size(); ++i)
    {
        if (bank[i].from_account == tmp && marked[tmp] == false)
        {
            sol.push_back(tmp);
            marked[tmp] = true;
            Try(bank[i].to_account, sol, marked);
            sol.pop_back();
            marked[tmp] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    string id, stmp1, stmp2;
    set<string> account;
    Bank b;

    // Block1
    while (true)
    {
        getline(cin, id);
        if (id == "#")
            break;
        istringstream iss(id);
        iss >> stmp1 >> stmp2 >> b.money >> b.time_point >> b.atm;
        account.insert(stmp1);
        account.insert(stmp2);
        b.from_account = ConvertId(stmp1);
        b.to_account = ConvertId(stmp2);
        bank.push_back(b);
        Account[b.from_account] += b.money;
    }

    while (true)
    {
        cin >> id;
        if (id == "?number_transactions")
        {
            cout << bank.size() << '\n';
        }
        else if (id == "?total_money_transaction")
        {
            int sum = 0;
            for (const Bank &a : bank)
            {
                sum += a.money;
            }
            cout << sum << '\n';
        }
        else if (id == "?list_sorted_accounts")
        {
            for (string a : account)
            {
                cout << a << " ";
            }
            cout << '\n';
        }
        else if (id == "?total_money_transaction_from")
        {
            cin >> stmp1;
            cout << Account[ConvertId(stmp1)] << '\n';
        }
        else if (id == "?inspect_cycle")
        {
            vector<int> sol;
            vector<bool> marked(1000000, false);
            cin >> stmp1 >> k;
            n = ConvertId(stmp1);

            Try(n, sol, marked);
            cout << FLAG << '\n';
            FLAG = false;
        }
        else
            break;
    }

    return 0;
}