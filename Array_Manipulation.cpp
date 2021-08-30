/*
 
    Brute force approach 
    
    
*/
long arrayManipulation(int n, vector<vector<int>> queries) {
    
    vector<long> arr(n,0) ; 
    
    int m = queries.size() ;
    long result = INT_MIN;  
    
    for( int i = 0 ; i < m ; i++  )
    {
        int left_index = queries[i][0] ; 
        int right_index = queries[i][1] ;
        int sum = queries[i][2] ; 
        for( int j = left_index - 1 ; j <= right_index-1 ; j++  )
        {
            arr[j] += sum ;
            result = max(arr[j] , result) ; 
        } 
        
        
    } 
    return result ;
    
}
