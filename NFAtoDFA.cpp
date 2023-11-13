#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"NFA information: "<<endl;
    int num_of_states,num_of_symbol;
    int i,j,k;
    cout<<"Enter the number of states and number of symbols: ";
    cin>>num_of_states>>num_of_symbol;
    char start_state,final_state;    
    char states[num_of_states];
    cout<<"Enter the states: "<<endl;
    for(i=0;i<num_of_states;i++)
    {
        cin>>states[i];
    }
    cout<<"start state: ";
    cin>>start_state;
    cout<<"final state: ";
    cin>>final_state;
    char nfa_transition[num_of_states][num_of_symbol][num_of_states];
    cout<<"NFA transition table: "<<endl;
    for(i=0;i<num_of_states;i++)
    {
        cout<<"from states "<<states[i]<<endl;
        for(j=0;j<num_of_symbol;j++)
        {
            cout<<"by "<<j<<": ";
            for(k=0;k<num_of_states;k++)
            {
                cin>>nfa_transition[i][j][k];
            }
            cout<<endl;
        }
    }
    //cout<<nfa_transition[0][0][1]<<endl;
    queue <string> dfa_states;
    string mk_start_state;
    mk_start_state+=start_state;
    dfa_states.push(mk_start_state);
    string check_done[1000];
    int f=0,row=0;
    string dfa_transition[1000][num_of_symbol];
    while(1)
    {
        if(dfa_states.size()==0)
        {
            break;
        }
        string front=dfa_states.front();
        dfa_states.pop();
        check_done[f]=front;
        f++;
        for(j=0;j<num_of_symbol;j++)
        {
            set<char>add;
            add.clear();
            for(i=0;i<front.size();i++)
            {
                for(k=0;k<num_of_states;k++)
                {
                    if(nfa_transition[front[i]-'a'][j][k]!='x')
                    {
                        add.insert(nfa_transition[front[i]-'a'][j][k]);
                    }
                }
            }
            //cout<<dfa<<endl;
            string final_dfa;
            for(auto t: add)
            {
                final_dfa.push_back(t);
            }
            cout<<final_dfa<<endl;
            dfa_transition[row][j]=final_dfa;
            int flag=0;
            for(i=0;i<f;i++)
            {
                if(check_done[i]==final_dfa)
                {
                    flag=1;
                }
            }
            if(flag==0)
            {
                dfa_states.push(final_dfa);
            }
        }
        row++;
    }
    cout<<"dfa states are: "<<endl;
    for(i=0;i<row;i++)
    {
        cout<<check_done[i]<<endl;
    }
    cout<<"dfa transition table: "<<endl;
    for(i=0;i<row;i++)
    {
        cout<<"from states "<<check_done[i]<<":"<<endl;
        for(j=0;j<num_of_symbol;j++)
        {
            cout<<"by "<<j<<": "<<dfa_transition[i][j]<<endl;
        }
    }
}