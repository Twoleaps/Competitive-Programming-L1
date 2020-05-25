#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;
void vectorDemo(){
    vector<int> a={11,2,3,8,56};  //declaring and initialising vectors
    sort(a.begin(), a.end());     //Agorithm to sort vector 
    bool present=binary_search(a.begin(), a.end(), 80); //false //To check weather a given element is present or not
    present=binary_search(a.begin(), a.end(), 8); //true
    a.push_back(100);  //To enter elements at the end of the vector
    a.push_back(100);
    a.push_back(100);
    a.push_back(100);
    a.push_back(110);

    //either u can use this 
   vector<int>::iterator it=lower_bound(a.begin(), a.end(), 100);
    //or we can write it in 
    auto it=lower_bound(a.begin(), a.end(), 100);
    //returns the first occuraance of the index of element >= 100

    vector<int>::iterator it2=upper_bound(a.begin(), a.end(), 100);
    //returns the first occuraance of the index of element > 100

    cout<<*it<<" "<<*it2<<"\n";
    cout<<it2-it<<"\n";

    //an easier way to print all the elements of the vector
    for(int x : a){
        cout<<x<<" ";
    }
    cout<<"\n";
}

void setDemo(){
    set<int> s;
    s.insert(1); //To insert elements in a set
    s.insert(2); //All the elements gets sorted itself in O(mlogn)time
    s.insert(-1);
    s.insert(-10);
    for(int x : s){
        cout<<x<<" ";
    }
    auto it=s.find(-1);  //To find a given element in O(nlogn) time
    if(it==s.end()){
        cout<<"not present\n";
    }else{
        cout<<"present\n";
        cout<<*it<<"\n";
    }
    auto it2=s.upper_bound(-1);
    auto it3=s.upper_bound(0);
    cout<<*it2<<" "<<*it3<<"\n";
    auto it4=s.upper_bound(2);
    if(it4==s.end()){
        cout<<"cant find that\n";
    }
    s.erase(-1);
    cout<<endl;
}

void mapDemo(){
    map<int, int>a;  //Mappping can be done between any to datatypes
    a[1]=10;         //It can be between an integer and a string like here
    a[2]=-1;
    a[3]=2;
    a[100002]=24;
    map<char, int>a1;
    string x="Chirag Sinha";
    for(char c : x){
        a1[c]++;
    }
    cout<<a1['i']<<a1['a']<<endl;  //to count the frequency of each character
    a.find(-1);
    a.erase(-1); 
}

//A simple but good question to undes=rstand the basic approach of using STL
void powerOfSTL(){
    //To find the number for a given set of interval and add the number 
    //between those intervals.
    set<pair<int, int>>s;
    s.insert({2,3});
    s.insert({10,20});
    s.insert({30,400});
    s.insert({401,450});
    //Rule to compare pairs is
    //pair {a,b} is less than pair {c,d}
    //iff(a<b) or (a==b and c<d)
    int point=401;
    auto it=s.upper_bound({point, INT8_MAX});
    if(it==s.begin()){
        cout<<"The given point does not lie in any of the interval"<<"\n";
        return ;
    }
    it--;
    pair<int, int> current = *it;
    if(current.first <= point && point <=current.second){
        cout<<"yes its present "<<current.first<<" "<<current.second<<"\n";
    }else{
        cout<<"The given point does not lie in any of the interval"<<"\n";
    }
}

int main(){
    vectorDemo();
    setDemo();
    powerOfSTL();
    return 0;
}


//Contributed by Chirag Sinha
