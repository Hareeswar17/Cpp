#include <bits/stdc++.h> 
using namespace std;
int main(){
    int x;
    int Q;
    int median = x;
    priority_queue<int> leftHeap;
    priority_queue<int,vector<int>,greater<int>> rightHeap;
    while(Q--){
        int A,B;
        cin >> A >> B;
        vector<int> nums = {A,B};
        for(auto num : nums){
            if(num <= median){
                leftHeap.push(num);
            }
            else{
                rightHeap.push(num);
            }
        }
        if(leftHeap.size() > rightHeap.size()){
            rightHeap.push(median);
            median = leftHeap.top();
            leftHeap.pop();
        }
        else if(rightHeap.size() > leftHeap.size()+1){
            leftHeap.push(median);
            median = rightHeap.top();
            rightHeap.pop();
        }
        cout << median << " ";
    }
    return 0;
}
/*
278117031
7
167642909 517897721
148434323 567739597
319926999 481642530
659199879 252516557
49913403 798318034
89701408 892537201
199166668 742285869
*/