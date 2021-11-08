/////////////////      ====>           TRADITONAL CHECKSUM       <=======

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int , int> pi;

#define pb push_back

string toBin(int n)
{
    string s = "";
    while(n)
    {
        int t = n%2;
        if(t == 0)
        {
            s += '0';
        }
        else{
            s += '1';
        }
        n = n/2;
    }
    reverse(s.begin() , s.end());
    return s;
}

int main(int argc, char ** argv)
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;  //num of blocks or input
    vector<string>s;

    //Sender side

    vector<int>input(n);
    for(int i = 0; i < n; i++)
    {
        cin >> input[i];
        string str = toBin(input[i]);
        s.pb(str); //store the binary form of the input
    }
    int carry = 0;
    for(int i = 0; i < s.size() - 1; i++)
    {
        string str1 = s[i];
        string str2 = s[i + 1];
        int l = str1.size();
        int m = str2.size();
        if(l > m)
        {
            int r = l - m;
            string extra = "";
            for(int i = 0; i < r; i++)
            {
                extra += '0';
            }
            extra += str2;
            str2 = extra;
        }
        else{
            int r = m - l;
            string extra = "";
            for(int i = 0; i < r; i++)
            {
                extra += '0';
            }
            extra += str1;
            str1 = extra;
        }

        string str3 = "";
        for(int j = str1.size(); j >= 0; j--)
        {
            if(str1[j] == '0' && str2[j] == '0')
            {
                if(carry == 1)
                {
                    str3 += '1';
                }
                else{
                    str3 += '0';
                }
            }
            else if((str1[j] == '0' && str2[j] == '1') || (str1[j] == '1' && str2[j] == '0'))
            {

                if(carry == 1)
                {
                    carry = 1;
                    str3 += '0';
                }
                else{
                    str3 += '1';
                }
            }

             else if(str1[j] == '1' && str2[j] == '1')
            {
                if(carry == 1)
                {
                    carry = 1;
                    str3 += '1';
                }
                else{
                    carry = 1;
                    str3 += '0';
                }
            }

        }

        reverse(str3.begin(),str3.end());

        s[i + 1] = str3;
        if(carry == 1)
        {
             for(int j = str1.size(); j >= 0; j--)
              {
                  if(s[i + 1][j] == '0')
                  {
                      s[i + 1][j] = '1';
                      carry = 0;
                      break;
                  }
                  else if(s[i + 1][j] == '1')
                  {
                      s[i + 1][j] = '0';
                      carry = 1;
                  }
              }
        }
    }
    string CheckSum = s[s.size() - 1];

    for(int i = 0; i < CheckSum.size(); i++)  //1's complement
    {
        if(CheckSum[i] == '0')
        {
            CheckSum[i] = '1';
        }
        else{
            CheckSum[i] = '0';
        }
    }
    cout<<"\n\nCheckSum: "<<CheckSum<<"\n\n";
    s.clear();

    //Receiver Side

    for(int i = 0; i < n; i++)
    {
        string str = toBin(input[i]);
        s.pb(str); //store the binary form of the input
    }
    s.pb(CheckSum); // input CheckSum

    carry = 0;
    for(int i = 0; i < s.size() - 1; i++)
    {
        string str1 = s[i];
        string str2 = s[i + 1];
        int l = str1.size();
        int m = str2.size();
        if(l > m)
        {
            int r = l - m;
            string extra = "";
            for(int i = 0; i < r; i++)
            {
                extra += '0';
            }
            extra += str2;
            str2 = extra;
        }
        else{
            int r = m - l;
            string extra = "";
            for(int i = 0; i < r; i++)
            {
                extra += '0';
            }
            extra += str1;
            str1 = extra;
        }

        string str3 = "";

        for(int j = str1.size(); j >= 0; j--)
        {
            if(str1[j] == '0' && str2[j] == '0')
            {
                if(carry == 1)
                {
                    str3 += '1';
                }
                else{
                    str3 += '0';
                }
            }
            else if((str1[j] == '0' && str2[j] == '1') || (str1[j] == '1' && str2[j] == '0'))
            {

                if(carry == 1)
                {
                    carry = 1;
                    str3 += '0';
                }
                else{
                    str3 += '1';
                }
            }

             else if(str1[j] == '1' && str2[j] == '1')
            {
                if(carry == 1)
                {
                    carry = 1;
                    str3 += '1';
                }
                else{
                    carry = 1;
                    str3 += '0';
                }
            }

        }

        reverse(str3.begin(),str3.end());

        s[i + 1] = str3;
        if(carry == 1) //summing Carry bit
        {
             for(int j = str1.size(); j >= 0; j--)
              {
                  if(s[i + 1][j] == '0')
                  {
                      s[i + 1][j] = '1';
                      carry = 0;
                      break;
                  }
                  else if(s[i + 1][j] == '1')
                  {
                      s[i + 1][j] = '0';
                      carry = 1;
                  }
              }
        }
    }
    string Sum = s[s.size() - 1];
    bool ok = 1;
    for(int i = 0; i < Sum.size(); i++)
    {
        if(Sum[i] == '0')
        {
            ok = 0;
            break;
        }
    }
    if(ok)
    {
        cout<<"=====>   Accepted  <======\n";
    }
    else{
        cout<<"=====>  Data is Corrupted...  <======\n";
    }
    return 0;
}
