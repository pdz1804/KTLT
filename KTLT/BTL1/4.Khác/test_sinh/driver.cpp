#include <bits/stdc++.h>

using namespace std;

const string NAME = "main";
const string TESTNAME = "test";
const string MERLIN = "merlinPack";
const string ACLEPIUS = "aclepiusPack";
const string MUSHGHOST = "mushGhostPack";

const int nTest = 100;

/* Main File */
const int minN = 10, maxN = 10;
const int minHP = 100, maxHP = 200;
const int minLevel = 1, maxLevel = 10;
const int minItem = 1, maxItem = 99;

const int minEvent = 1, maxEvent = 10;
int event[17] = {0, 1, 2, 3, 4, 5, 6, 7, 11, 12, 13, 15, 16, 17, 18, 19, 99};
//int event[17] = {0, 1, 2, 3, 4, 5, 6, 7, 12, 12, 11, 11, 12, 12, 12, 12, 12};

/* Aclepius File */
const int minArr = 5, maxArr = 10;
const int minVal = 10, maxVal = 20;

/* Mush Ghost File*/
const int minM = 5, maxM = 10;
const int minA = -99, maxA = 100; 
const int minAdd = -10, maxAdd = 10;

/* Merlin File */
const int minCase = 10, maxCase = 20;
const string str = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
const int minStr = 0, maxStr = 61;
const int minLen = 30, maxLen = 60;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

void mainFile()
{
    ofstream inp((TESTNAME +".inp").c_str());

    int healthPoint, level, remedy, maidenKiss, phoenixDown;
    healthPoint = minHP + rand() % (maxHP - minHP + 1);
    level = minLevel + rand() % (maxLevel - minLevel + 1);
    remedy = minItem + rand() & (maxItem - minItem + 1);
    maidenKiss = minItem + rand() & (maxItem - minItem + 1);
    phoenixDown = minItem + rand() & (maxItem - minItem + 1);

    inp << healthPoint << ' ' << level << ' ' << remedy << ' ' << maidenKiss << ' ' << phoenixDown << '\n';
    int n = minN + rand() % (maxN - minN + 1);        

    for (int i = 1; i <= n; ++i)
    {
        int index = minEvent + rand() % (maxEvent - minEvent + 1);
        if (event[index] == 13)
        {
            inp << event[index];
            for (int j = 0; j < 4; ++j) inp << 1 + rand() % 4;
        }
        else inp << event[index];
        if (i != n) inp << ' ';
    }
    inp << '\n';
    inp << (MUSHGHOST + ".txt," + ACLEPIUS + ".txt," + MERLIN + ".txt").c_str();
    inp.close();
}

void mushGhostFile()
{
    ofstream inp2((MUSHGHOST + ".txt").c_str());

    int m = minM + rand() % (maxM - minM + 1);
    inp2 << m << '\n';

    int random = rand() % 3;
    if (random == 0)
    {
        int out = minA + rand() % (maxA - minA + 1);
        int add = minAdd + rand() % (maxAdd - minAdd + 1);
        inp2 << out;
        for (int i = 1; i < m; ++i)
        {
            out += add;
            inp2 << ',' << min(maxA, max(minA, out));
        }
    }
    else if (random == 1)
    {
        int out = minA + rand() % (maxA - minA + 1);
        int add = rand() % maxAdd;
        int idx = rand() % m;

        inp2 << max(minA, out - add * (idx + 1));
        for (int i = 1; i < idx - 1; ++i) inp2 << ',' << max(minA, out - add * (idx - i + 1));
        inp2 << ',' << out;
        for (int i = idx; i < m; ++i) inp2 << ',' << max(minA, out - add * (i - idx + 1));
    }
    else
    {
        int tmp = minA + rand() % (maxA - minA + 1);
        inp2 << min(maxA, max(minA, tmp));
        for (int i = 1; i < m; ++i)
        {
            tmp = minA + rand() % (maxA - minA + 1);
            inp2 << ',' << min(maxA, max(minA, tmp));
        }
    }

    inp2.close();
}

void aclepiusFile()
{
    ofstream inp((ACLEPIUS + ".txt").c_str());

    int n = minArr + rand() % (maxArr - minArr + 1);
    int m = minArr + rand() % (maxArr - minArr + 1);

    inp << n << ' ' << m << '\n';
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            inp << minVal + rand() % (maxVal - minVal + 1) << ' ';
        }
        inp << '\n';
    }
    inp.close();
}

void merlinFile()
{
    ofstream inp((MERLIN + ".txt").c_str());
    
    int n = minCase + rand() % (maxCase - minCase + 1);
    inp << n << '\n';
    for (int i = 0; i < n; ++i)
    {
        int len = minLen + rand() % (maxLen - minLen + 1);
        for (int j = 0; j < minLen; ++j)
        {
            inp << str[minStr + rand() % (maxStr - minStr + 1)];
        }
        if (rand() % 2) inp << "mErLin";
        if (rand() % 2) inp << "merlin";
        if (rand() % 2) inp << "Merlin";
        inp << '\n';
    }
    inp.close();
}

int main()
{
    srand(time(NULL));
    for (int iTest = 1; iTest <= nTest; ++iTest)
    {
        mainFile();
        mushGhostFile();
        aclepiusFile();
        merlinFile();

        /* CODE DRIVER */

        system((NAME + ".exe " + TESTNAME + ".inp").c_str());
        system((NAME + "2.exe " + TESTNAME + ".inp").c_str());

        if (system(("fc " + TESTNAME + ".out " + TESTNAME + ".ans").c_str()) != 0)
        {
            cout << "Test " << iTest << " WA\n"; return 0;
        }
        cout << "Test " << iTest << " AC\n" << "--------------------------------" << '\n';
    }
}
