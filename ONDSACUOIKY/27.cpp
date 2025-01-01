#include <iostream>
#include <string>

#define LOAD 0.7
#define EMPTY 0
#define DELETE -1
using namespace std;

struct Hocsinh
{
    int Maso;
    string Hoten;
    int Namsinh;
    bool Gioitinh;
    double TBK;
};

struct Hashtable
{
    int M; // Kich thuoc bang bam
    int n; // so phan tu trong bang bam
    Hocsinh *table;
};

void CreateHashtable(Hashtable &, int);
int Insert(Hashtable &, Hocsinh);
void PrintHashtable(Hashtable);
void DeleteHashtable(Hashtable &);

void Input(Hocsinh &x)
{
    cin >> x.Maso;
    getline(cin >> ws, x.Hoten);
    cin >> x.Namsinh;
    cin >> x.Gioitinh;
    cin >> x.TBK;
}
int main()
{
    Hashtable hashtable;

    int m, n;
    Hocsinh hs;

    cin >> m;
    CreateHashtable(hashtable, m);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Input(hs);
        Insert(hashtable, hs);
    }
    PrintHashtable(hashtable);
    DeleteHashtable(hashtable);
    return 0;
}

void CreateHashtable(Hashtable &ht, int m)
{
    ht.table = new Hocsinh[m];
    if (ht.table == NULL)
        exit(1);
    for (int i = 0; i < m; i++)
    {
        ht.table[i].Maso = EMPTY;
    }
    ht.M = m;
    ht.n = 0;
}

void PrintHashtable(Hashtable ht)
{
    for (int i = 0; i < ht.M; i++)
    {
        Hocsinh hs = ht.table[i];
        if (hs.Maso > 0)
            cout << '[' << hs.Maso << ",  " << hs.Hoten << "  , " << hs.Gioitinh << ", " << hs.Namsinh << ", " << hs.TBK << "]\n";
        else
            cout << "[" << hs.Maso << ",  " << "  , " << ", " << ", " << "]\n";
    }
}
void DeleteHashtable(Hashtable &ht)
{
    delete[] ht.table;
    ht.table = NULL;
    ht.M = 0;
}

int Insert(Hashtable &ht, Hocsinh x)
{
    if (1.0 * (ht.n + 1) / ht.M > LOAD)
        return 0;
    int index = x.Maso % ht.M;
    int i = 0;
    if (ht.table[index].Maso <= 0)
    {
        ht.table[index] = x;
        ht.n++;
        return 1;
    }
    while (ht.table[index].Maso > 0 && ht.table[index].Maso != x.Maso)
    {
        i++;
        index = (x.Maso + i) % ht.M;
        if (i >= ht.M)
            return 0;
    }
    if (ht.table[index].Maso <= 0)
    {
        ht.table[index] = x;
        ht.n++;
        return 1;
    }
    if (ht.table[index].Maso > 0 && ht.table[index].Maso == x.Maso)
        return 0;
}