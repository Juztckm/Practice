/*OSHN*/
#include <bits/stdc++.h>
using namespace std;

template <typename T, size_t S>
class Array
{
public:
    constexpr size_t Size() const { return S;}
    T& operator[](size_t index){ return m_Data[index]; }
    constexpr T& operator[](size_t index) const { return m_Data[index]; }
private:
    T m_Data[S];
};

int main()
{
    vector<int> v;
    cout<<v.data()<<'\n';

    const int sz = 10;
    Array<int, sz> arr;
    memset(&arr[0],0,arr.Size()* sizeof(int));
    Array<string, sz> str;
    str[0] = "string";
    for (size_t i = 0; i < sz; i++)
    {
        cout << arr[i] <<' ';
    }
    return 0;
}
