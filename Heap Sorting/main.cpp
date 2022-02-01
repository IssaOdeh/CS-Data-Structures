#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    srand(time(NULL));//Seed for rand()
    vector<int> v;//Container
    int temp, mean = 0;
    for(int i = 0; i < 100; i++)
    {
        temp = rand()%1000;//Generate a random number between 0 to 999
        mean += temp;//For mean calculation
        v.push_back(temp);
    }
    mean /= 100;//Calculate mean
    
    make_heap(v.begin(), v.end());//Make a heap of 100 random integers
    
    v.push_back(mean);//Insert mean into heap
    push_heap(v.begin(), v.end());//Reorder heap after adding mean
    
    cout<<"Maximum element before deletion: "<<v.front()<<endl;
    pop_heap(v.begin(), v.end());//Delete maximum element from heap
    v.pop_back();//Remove maximum element from back of container
    cout<<"Maximum element after deletion: "<<v.front()<<endl;
    
    cout<<"\nHeap before sorting: ";
    for(int i : v)
        cout<<i<<" ";
    cout<<endl;
    
    sort_heap(v.begin(), v.end());//Sort heap
    cout<<"Heap after sorting: ";
    for(int i : v)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}