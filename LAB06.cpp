#include<bits/stdc++.h>
using namespace std;
int main(){
    int num_state,num_symbol,i,j,k;
    //freopen("DREinput.txt","r",stdin);
    //cout<<"Enter the number of state and number of symbol : ";
    cin>>num_state>>num_symbol;
    char states[num_state],alpha[num_symbol],final,start,transition[num_state][num_symbol];
    //cout<<"Enter the symbols of alphabet: ";
    for(i=0;i<num_symbol;i++)cin>>alpha[i];
    //cout<<"Enter the name of the states: ";
    for(i=0;i<num_state;i++)cin>>states[i];
   // cout<<"Enter the starting point ";
    cin>>start;
    //cout<<"Enter the final point ";
    cin>>final;
    //cout<<"Transition:"<<endl;
    for(i=0;i<num_state;i++){
       // cout<<"For state "<<states[i]<<endl;
        for(j=0;j<num_symbol;j++){
            //cout<<"If symbol is "<<alpha[j]<<"output is ";
            cin>>transition[i][j];
        }
    }
//     cout<<"Transition:"<<endl;
//   for(i=0;i<num_state;i++){
//         //cout<<"For state "<<states[i]<<endl;
//         for(j=0;j<num_symbol;j++){
//             //cout<<"If symbol is "<<alpha[j]<<"output is ";
//             cout<<transition[i][j]<<" ";
//         }
//         cout<<endl;
//     }
vector<vector<vector<string>>> RE;
vector<vector<string>> str2;
for(i=0;i<num_state;i++){
    vector<string>str1;
    for(j=0;j<num_state;j++){
        bool flag=false;
        
        for(int m=0;m<num_symbol;m++){
            if(transition[i][m] == states[j] && i==j)
            {   
                string s;
                s=alpha[m];
                s=s+" + ^";//^ for Epsilon;
                flag=true;
                str1.push_back(s);
                break;
            }
            else if(transition[i][m] == states[j] && i!=j){
                string s;
                s=alpha[m];
                str1.push_back(s);
                flag=true;
                break;
            }
        }
        if(flag==false)str1.push_back("#");
    }
    str2.push_back(str1);
}
  RE.push_back(str2);
//   cout<<"RE(0)"<<endl;
//   for(i=0;i<num_state;i++){
//     for(j=0;j<num_state;j++){
//         cout<<RE[0][i][j]<<"\t";
//     }
//     cout<<endl;
//   }
for(k=1;k<num_state;k++){
    vector<vector<string>>str2;
    for(i=0;i<num_state;i++){
        vector<string> str1;
        for(j=0;j<num_state;j++){
            string s;
            s="( ("+RE[k-1][i][j]+" )"+" + ( "+" ( "+RE[k-1][i][k-1]+" )"+" ( "+RE[k-1][k-1][k-1]+" )* ( "+RE[k-1][k-1][j]+" ) )";
            str1.push_back(s);
        }
        str2.push_back(str1);
    }
    RE.push_back(str2);
}
    for(k=0;k<num_state;k++){
        cout<<"For K = " <<k<<endl;
        for(i=0;i<num_state;i++){
            for(j=0;j<num_state;j++){
                cout<<RE[k][i][j]<<"\t\t";
            }
            cout<<endl;
        }
        cout<<"\n\n";
    }
    //cout<<RE[1][0][1];
}