//Cyclic Redundancy Check

#include<bits/stdc++.h>
using namespace std;

int main()
{
    //Sender Side

    cout<<"======Sender Side=======\n\n";
    string data_w, data;

    cout << "please enter the data word: ";
    cin >> data_w;
    data = data_w;

    string div;
    cout << "please enter the divisor: ";
    cin >> div;
    int len_div = div.length();
    string div1 = div;
    for(int i = 0; i < len_div - 1; i++) //append (len_div - 1) bits to the original message
    {
        data += '0';
    }

    //binary division operation
    int l  = data_w.length();
    string result = "", temp = "";
    for(int i = 0; i < len_div; i++)
    {
        temp += data[i];
    }
    string rem = temp;
    char qt[100];
    for(int i=0;i<l;i++)
		 {
		 qt[i]=temp[0];
		 if(qt[i]=='0')
		 	for(int j=0;j<len_div;j++)
			 div[j]='0';
		 else
		   for(int j=0;j<len_div;j++)
				div[j]=div1[j];
		   for(int j=len_div-1;j>0;j--)
		    {
			if(temp[j]==div[j])
			rem[j-1]='0';
		 	else
		 	rem[j-1]='1';
		    }
		 rem[len_div-1]=data[i+len_div];
		 temp = rem;
		 }
	 rem = temp;

    cout<<"\nHere, Quotient is: ";
    for(int i = 0; i < l; i++){
    cout<<qt[i];
    }

    cout<<"\nRemainder is: ";
    cout<<rem<<'\n';
    cout<<"\nCRC codeword is: ";
    cout<<data_w<<rem<<'\n';
    cout<<"--------------------\n";
    cout<<"--------------------\n";
    cout<<'\n';


    //Receiver side

    cout<<"======Receiver Side=======\n\n";
    string rcw;
    cout<<"Enter the received code word: ";
    cin >> rcw;

    //binary division operation
    l  = rcw.length();
    result = "", temp = "";
    div = div1;
    for(int i = 0; i < len_div; i++)
    {
        temp += rcw[i];
    }
    bool is = 0;
    rem = temp;
    for(int i=0;i<l;i++)
		 {
		 qt[i]=temp[0];
		 if(qt[i]=='0')
		 	for(int j=0;j<len_div;j++)
			 div[j]='0';
		 else
		   for(int j=0;j<len_div;j++)
				div[j]=div1[j];
		   for(int j=len_div-1;j>0;j--)
		    {
			if(temp[j]==div[j])
			rem[j-1]='0';
		 	else
		 	rem[j-1]='1';
		    }
		 rem[len_div-1]=rcw[i+len_div];
		 temp = rem;
		 int cnt = 0;
		 for(int j = 0; j < temp.length(); j++)
         {
             if(temp[j] != '0')
             {
                 cnt++;
                 break;
             }
         }
         if(!cnt)
         {
             is = 1;
             break;
         }
		 }
	 rem = temp;
	 cout<<"\n";
	 if(is)
     {
         cout<<"<===Accepted===>\n";
     }
     else{
        cout<<"received code word contains errors...\n";
     }
  return 0;
}
