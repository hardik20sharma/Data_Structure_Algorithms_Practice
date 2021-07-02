#include<bits/stdc++.h>
using namespace std;

vector<int> Union (vector<int> vec1, vector<int> vec2)
{
    int i = 0, j = 0;
    vector<int> union_vec;

    while(i < vec1.size() && j < vec2.size())
        if(vec1[i] == vec2[j])
        {
            union_vec.push_back(vec1[i]);
            i++;
            j++;
        }
        else if(vec1[i] > vec2[j])
            union_vec.push_back(vec2[j++]);
        else
            union_vec.push_back(vec1[i++]);

    while(i < vec1.size())
        union_vec.push_back(vec1[i++]);

    while(j < vec2.size())
        union_vec.push_back(vec2[j++]);

    return union_vec;
}

vector<int> Intersection(vector<int> vec1, vector<int> vec2)
{
    int i = 0, j = 0;
    vector<int> intersection_vec;

    while(i < vec1.size() && j < vec2.size())
        if(vec1[i] == vec2[j])
        {
            intersection_vec.push_back(vec1[i]);
            i++;
            j++;
        }
        else if(vec1[i] > vec2[j])
            j++;
        else
            i++;

    return intersection_vec;
}

int main()
{
    vector<int> vec1 {1, 2, 3, 4, 5};
    vector<int> vec2 {4, 5, 6, 7, 8};

    vector<int> union_vec = Union(vec1, vec2), intersection_vec = Intersection(vec1, vec2);

    cout << "Union: ";
    for(int i : union_vec)
        cout << i << " ";

    cout << "\nIntersection: ";
    for(int i : intersection_vec)
        cout << i << " ";
}