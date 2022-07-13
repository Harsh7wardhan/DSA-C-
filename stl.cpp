/* ***************************************************STL :: VECTORS**************************************************************** */
/* #include<iostream>
#include<vector>
using namespace std;
void display( vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
        cout<<v.at(i)<<" ";
    }
    
}
int main()
{
    //ways to create a vector
    vector<int> vec1;//zero length int vector
    vector<char> vec2(4);//4 element char vector
    vector<char> vec3(vec2);//vec3 from vec 2
    vector<int> v(6,3);//6 element vector of 3s
    int element,size=5;
    for(int i=0;i<size;i++)
    {
        cin>>element;
        vec1.push_back(element);

    }
    
    vector<int> :: iterator iter = vec1.begin();
    display(vec1);
    cout<<endl;
    vec1.insert(iter+1,5,566);
    display(vec1);
    
} */
/* *****************************************STL :: LIST*************************************************************************
#include<iostream>
#include<list>
using namespace std;
void display(list<int> &lst)
{   
    list<int> :: iterator it;
    for(it=lst.begin();it!=lst.end();it++)
    {
        cout<<*it<<" ";
    }
}



int main()
{
    
    list<int> list;
    
    list.push_back(2);
    list.push_back(3);
    list.push_back(6);
    list.push_back(9);
    list.push_back(8);

    display(list);

    list<int> list2;
    list<int> iterator :: it;
    iter=list2.begin()
    *it=90;
    it++;

    *it=77;
    it++;

    *it=89;
    it++;

    display(list2);

}
//removal methods
//list.pop_front()
//list.remove(num)

/* //sorting 
list.sort()
//merge
list1.merge(list2)
//reversing
list1.reverse() */ 
/* 
****************************************************** STL :: MAPS******************************************************************* */
