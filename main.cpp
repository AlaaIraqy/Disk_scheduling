#include<iostream>
#include<set>
#include<queue>
using namespace std;

vector<int> FIFO(vector<int> s)
{
    int headMovements=0;
    for(int i=0; i<s.size(); i++)
    {
        if(i>0)
        {
            headMovements+=abs(s[i]-s[i-1]);
        }
    }
    s.push_back(headMovements);
    return s;
}
vector<int> SCAN(vector<int> s,int start,int diskSize,int direction){
    set<int> mp;
    set<int>::iterator it;
    vector<int> output;
    int headMovements=0;
    for(int i=0;i<s.size();i++){
    mp.insert(s[i]);
    }
    if(direction==1){
        for(int i=start;i<diskSize;i++){
            it=mp.find(i);
            if (it != mp.end()){
                output.push_back(i);
                mp.erase(it);
            }
            }
            for(int i=diskSize;i>=0;i--){
            it=mp.find(i);
            if (it != mp.end()){
                output.push_back(i);
                mp.erase(it);
            }
            }
            for(int i=0;i<output.size();i++){
             if(i>0)
        {
            headMovements+=abs(output[i]-output[i-1]);
        }
            }
            output.push_back(headMovements);

    }
    if(direction==0){
        for(int i=start;i>=0;i--){
            it=mp.find(i);
            if (it != mp.end()){
                output.push_back(i);
                mp.erase(it);
            }
            }
            for(int i=0;i<diskSize;i++){
            it=mp.find(i);
            if (it != mp.end()){
                output.push_back(i);
                mp.erase(it);
            }
            }
            for(int i=0;i<output.size();i++){
             if(i>0)
        {
            headMovements+=abs(output[i]-output[i-1]);
        }
            }
            output.push_back(headMovements);

    }
            return output;
}
vector<int> CSCAN(vector<int> s,int start,int diskSize,int direction){
    set<int> mp;
    set<int>::iterator it;
    vector<int> output;
    int headMovements=0;
    for(int i=0;i<s.size();i++){
    mp.insert(s[i]);
    }
     if(direction==1){
        for(int i=start;i<diskSize;i++){
            it=mp.find(i);
            if (it != mp.end()){
                output.push_back(i);
                mp.erase(it);
            }
            }
            for(int i=0;i<diskSize;i++){
            it=mp.find(i);
            if (it != mp.end()){
                output.push_back(i);
                mp.erase(it);
            }
            }
            for(int i=0;i<output.size();i++){
             if(i>0)
        {
            headMovements+=abs(output[i]-output[i-1]);
        }
            }
            output.push_back(headMovements);

    }
     if(direction==0){
        for(int i=start;i>=0;i--){
            it=mp.find(i);
            if (it != mp.end()){
                output.push_back(i);
                mp.erase(it);
            }
            }
            for(int i=diskSize;i>=0;i--){
            it=mp.find(i);
            if (it != mp.end()){
                output.push_back(i);
                mp.erase(it);
            }
            }
            for(int i=0;i<output.size();i++){
             if(i>0)
        {
            headMovements+=abs(output[i]-output[i-1]);
        }
            }
            output.push_back(headMovements);

    }
            return output;

}

int main()
{
    while(true){
    cout<<"Select scheduling policy: "<<endl;
    cout<<"1- FIFO  2- SCAN  3- C-SCAN  4- EXIT"<<endl;
    int select;
    vector<int> input;
    int movements;
    float avgMovements;
    cin>>select;
    if(select==1)
    {
        cout<<"Enter number of requests: "<<endl;
        int sizeOfrequests;
        cin>>sizeOfrequests;
        int k;
        cout<<"Enter requests: "<<endl;
        for(int i=0; i<sizeOfrequests; i++)
        {
            cin>>k;
            input.push_back(k);
        }
        vector<int> output=FIFO(input);
        movements=output.back();
        output.pop_back();
        avgMovements=(float)(movements*1.0/(input.size()-1));
        for(int i=0; i<output.size()-1; i++)
        {
            cout<<output[i]<<"->";
        }
        cout<<output.back()<<endl;
        cout<<"head movements : "<<movements<<endl;
        cout<<"average head movements : "<<avgMovements<<endl;
    }
    if(select==2){
    int startPos;
    int diskSize;
    int direction;
    cout<<"Enter starting position: "<<endl;
        cin>>startPos;
        input.push_back(startPos);
        cout<<"Enter Disk size: "<<endl;
        cin>>diskSize;
    cout<<"Enter number of requests: "<<endl;
        int sizeOfrequests;
        cin>>sizeOfrequests;
        int k;
        cout<<"Enter requests: "<<endl;
        for(int i=0; i<sizeOfrequests; i++)
        {
            cin>>k;
            input.push_back(k);
        }
        cout<<"Enter direction(for forward enter 1, for backward enter 0): "<<endl;
        cin>>direction;
        vector<int> output=SCAN(input,startPos,diskSize,direction);
        movements=output.back();
        output.pop_back();
        avgMovements=(float)(movements*1.0/(input.size()-1));
        for(int i=0; i<output.size()-1; i++)
        {
            cout<<output[i]<<"->";
        }
        cout<<output.back()<<endl;
        cout<<"head movements : "<<movements<<endl;
        cout<<"average head movements : "<<avgMovements<<endl;

    }
    if(select==3){
    int startPos;
    int diskSize;
    int direction;
    cout<<"Enter starting position: "<<endl;
        cin>>startPos;
        input.push_back(startPos);
        cout<<"Enter Disk size: "<<endl;
        cin>>diskSize;
    cout<<"Enter number of requests: "<<endl;
        int sizeOfrequests;
        cin>>sizeOfrequests;
        int k;
        cout<<"Enter requests: "<<endl;
        for(int i=0; i<sizeOfrequests; i++)
        {
            cin>>k;
            input.push_back(k);
        }
        cout<<"Enter direction(for forward enter 1, for backward enter 0): "<<endl;
        cin>>direction;
        vector<int> output=CSCAN(input,startPos,diskSize,direction);
        movements=output.back();
        output.pop_back();
        avgMovements=(float)(movements*1.0/(input.size()-1));
        for(int i=0; i<output.size()-1; i++)
        {
            cout<<output[i]<<"->";
        }
        cout<<output.back()<<endl;
        cout<<"head movements : "<<movements<<endl;
        cout<<"average head movements : "<<avgMovements<<endl;

    }if(select==4){
    exit(0);
    }
    }

    return 0;
}
