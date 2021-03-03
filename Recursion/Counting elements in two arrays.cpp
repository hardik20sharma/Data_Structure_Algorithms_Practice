// GeeksForGeeks - hardik20sharma

int binary_search(int arr[], int low, int high, int k)
{
    int mid;
    while(low <= high)
    {
        mid = low + (high - low) / 2;
        
        if(arr[mid] <= k)
            low = mid + 1;
        else
            high = mid - 1;
    }
    
    return high;
}

// GeeksForGeeks - hardik20sharma
vector<int> countEleLessThanOrEqual(int arr1[], int arr2[], int m, int n)
{
    vector<int> res;
    
    sort(arr2, arr2 + n);
    
    for(int i=0; i<m; i++)
        res.push_back( binary_search(arr2, 0, n-1, arr1[i]) + 1);

    return res;
}   
