#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int , int> pi;

#define pb push_back
char arr[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E'};

int main(int argc, char ** argv)
{
    ios::sync_with_stdio(0);cin.tie(0);
    string input;
    cin >> input;
    int R = 1 , L = 0;
    for(int i = 0; i < input.size(); i++)
    {
        int p = input[i];
        R = (R + p)%65521;
        L = (L + R)%65521;
    }
    ll Checksum = (L * 65536) + R;
    string str  = "";
    while(Checksum) //16 bit Checksum
    {
        int t = Checksum%16;
        str += arr[t];
        Checksum /= 16;
    }
    reverse(str.begin() ,str.end());
    cout<<"\nAdler Checksum: "<<str<<'\n';
    cout<<"\nHere, L = ";
    for(int i = 0; i <= (str.size()/2); i++)
    {
        cout<<str[i];
    }
    cout<<'\n';
     cout<<"R = ";
    for(int i = (str.size()/2); i < str.size(); i++)
    {
        cout<<str[i];
    }
    cout<<'\n';
}

