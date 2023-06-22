#include<bits/stdc++.h>
using namespace std;
vector<string> vec;
vector<string> vec1;

void combinations(string s1){
    vec.pop_back();
    int index=0;
    for(index;index<s1.length();index++){
        if(s1[index]=='x') break;
    }
    if(index==s1.length()){
        vec.push_back(s1);
        return;
    }
    else{
        s1[index]='0';
        vec.push_back(s1);
        combinations(vec[vec.size()-1]);
        s1[index]='1';
        vec.push_back(s1);
        combinations(vec[vec.size()-1]);
    }
}

void combinations1(string s1){
    vec1.pop_back();
    int index=0;
    for(index;index<s1.length();index++){
        if(s1[index]=='x') break;
    }
    if(index==s1.length()){
        vec1.push_back(s1);
        return;
    }
    else{
        s1[index]='0';
        vec1.push_back(s1);
        combinations1(vec1[vec1.size()-1]);
        s1[index]='1';
        vec1.push_back(s1);
        combinations1(vec1[vec1.size()-1]);
    }
}

bool checkStr(string s1, string s2){
    for(int i=0;i<s1.length();i++){
        if(s1[i]!=s2[i] && s2[i]!='x') return false;
    }
    return true;
}

// void vectorPrint(vector<string> v){
//     for(auto x:v){
//         cout<<x<<" ";
//     }
//     cout<<endl;
// }

// void setPrint(set<string> set){
//     for(auto x:set){
//         cout<<x<<" ";
//     }
//     cout<<endl;
// }

vector<string> removeRedundant(set<string> set1){
    vector<string> v;
    for(auto x: set1){
        v.push_back(x);
    }
    int count1=0;
    while(count1!=set1.size()){
        string s1=v[0];
        v.erase(v.begin());
        vec.clear();
        vec.push_back(s1);
        combinations(vec[0]);
        int count=0;
        for(int i=0;i<vec.size();i++){
            for(int j=0;j<v.size();j++){
                if(checkStr(vec[i], v[j])){
                    count++;
                    break;
                }
            }
        }
        if(count!=vec.size()){
            v.push_back(s1);
        }
        count1++;
    }
    return v;
}

int compare(string s1, string s2){
    int index=-1;
    int count=0;
    for(int i=0;i<s1.length();i++){
        if(s1[i]=='x' && s2[i]!='x') return -1;
        if(s2[i]=='x' && s1[i]!='x') return -1;
        if(s1[i]!=s2[i]){
            count++;
            index=i;
        }
    }
    if(count==1) return index;
    else return -1;
}

set<string> grouping(set<string> set1){
    set<string>::iterator it;
    set<string> set2=set1;
    for(it=set1.begin();it!=set1.end();it++){
        string s1=*it;
        set<string>::iterator it1;
        it1=it;
        it1++;
        int index;
        for(it1;it1!=set1.end();it1++){
            string s2=*it1;
            index=compare(s1, s2);
            if(index!=-1){
                if(set2.find(s1)!=set2.end()) set2.erase((set2.find(s1)));
                if(set2.find(s2)!=set2.end()) set2.erase((set2.find(s2)));
                s2[index]='x';
                set2.insert(s2);
            }
        }
    }
    return set2;
}

vector<string> grayCodeGenerator(int n){
    vector<string> v={"0", "1"};
    if(n!=1){
        int count=1;
        while(count!=n){
            for(int i=v.size()-1;i>=0;i--){
                v.push_back(v[i]);
            }
            for(int i=0;i<v.size();i++){
                if(i<v.size()/2) v[i]="0"+v[i];
                else v[i]="1"+v[i];
            }
            count++;
        }
    }
    return v;
}

map<string, int> mapping(int n){
    map<string, int> M;
    vector<string> v={"0", "1"};
    if(n!=1){
        int count=1;
        while(count!=n){
            for(int i=v.size()-1;i>=0;i--){
                v.push_back(v[i]);
            }
            for(int i=0;i<v.size();i++){
                if(i<v.size()/2) v[i]="0"+v[i];
                else v[i]="1"+v[i];
            }
            count++;
        }
    }
    for(int i=0;i<v.size();i++){
        M[v[i]]=i;
    }
    return M;
}

vector<string> expressionToBinary(string s,int n){
    vector<string> v;
    int i=0;
    while(i<s.length()){
        string kkk="";
        for(int i=0;i<n;i++) kkk=kkk+'x';
        while(s[i]!='+' && i<s.length()){
            if(s[i]!='\''){
                int ss=int(s[i])-65;
                kkk[ss]='1';
            }
            if(s[i]=='\''){
                int ss=int(s[i-1])-65;
                kkk[ss]='0';
            }
            i++;
        }
        v.push_back(kkk);
        i++;
    }
    for(int i=0;i<v.size();i++){
        vec1.push_back(v[i]);
        combinations1(vec1[vec1.size()-1]);
    }
    return vec1;
}

void printKmap(vector<vector<int>> v){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int choice;
    cout<<"enter 0 for expression to k-map:"<<endl;
    cout<<"enter 1 for k-map to expression:"<<endl;
    cin>>choice;

    if(choice==0){
        int n;
        cout<<"enter no. of variables: ";
        cin>>n;
        string s;
        cout<<"enter minterm expression:"<<endl;
        cout<<"enter expression string in capital letters only without space in between:"<<endl;
        cin>>s;
        if(s=="0"){
            int rowNum=n/2;
            int colNum=n-n/2;
            vector<vector<int>> Kmap(pow(2, rowNum), vector<int>(pow(2, colNum), 0));
            printKmap(Kmap);
        }
        else{
            vector<string> positions=expressionToBinary(s, n);
            int rowNum=n/2;
            int colNum=n-n/2;
            map<string, int> rowMap=mapping(rowNum);
            map<string, int> colMap=mapping(colNum);
            vector<vector<int>> Kmap(pow(2, rowNum), vector<int>(pow(2, colNum), 0));
            string ss1, ss2;
            for(int i=0;i<positions.size();i++){
                ss1=positions[i].substr(0, rowNum);
                ss2=positions[i].substr(rowNum);
                Kmap[rowMap[ss1]][colMap[ss2]]=1;
            }
            cout<<"\nk-map :\n\n";
            printKmap(Kmap);
        }
        cout<<"--------------------\n";
    }

    else{
        int n;
        cout<<"enter no. of variables: ";
        cin>>n;
        cout<<"input k-map dtrectly in matrix format:\n";
        int rowNum=n/2;
        int colNum=n-n/2;
        vector<int> v;
        vector<vector<pair<int, int>>> kMapInput(pow(2, rowNum), vector<pair<int, int>>(pow(2, colNum), make_pair(0, 0)));
        int input;
        for(int i=0;i<kMapInput.size();i++){
            for(int j=0;j<kMapInput[i].size();j++){
                cin>>input;
                kMapInput[i][j]=make_pair(input, stoi(grayCodeGenerator(rowNum)[i]+grayCodeGenerator(colNum)[j], 0, 2));
                if(kMapInput[i][j].first==1) v.push_back(kMapInput[i][j].second);
            }
        }
        set<string> set1;
        for(int i=0;i<v.size();i++){
            bitset<32> b(v[i]);
            string s=b.to_string();
            s=s.substr(32-n);
            set1.insert(s);
        }
        while(1){
            if(grouping(set1)==set1) break;
            else{
                set1=grouping(set1);
            }
        }
        string bb;
        for(int i=0;i<n;i++){
            bb=bb+"x";
        }
        vector<string> ans=removeRedundant(set1);
        cout<<"\nmost simplified expression is:\n";
        if(ans.empty()){
            cout<<"0"<<endl;
        }
        else if(ans.size()==1 && ans[0]==bb) cout<<"1"<<endl;
        else{
            string temp;
            char c;
            for(int i=0;i<ans.size();i++){
                temp=ans[i];
                for(int j=0;j<temp.length();j++){
                    if(temp[j]=='0'){
                        c=j+65;
                        cout<<c<<"'";
                    }
                    else if(temp[j]=='1'){
                        c=j+65;
                        cout<<c;
                    }
                }
                if(i!=ans.size()-1) cout<<" + ";
            }
            cout<<endl;
        }
        cout<<"--------------------"<<endl;
    }

    return 0;
}