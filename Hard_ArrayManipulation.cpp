/*
 
    Brute force approach 
    Time complexity : O ( n ^ 2 )
    
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
/*  Efficient approach ( Using prefix sum technique  )
    Time complexity O ( M + N  ) 
    M <- number of queries
    N <- size of Array 
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
        
        arr[left_index-1] += sum ;
        if( right_index <= n-1 ) arr[right_index] -= sum ;
             
    
    } 
    for( int i = 1 ; i < n ; i++ )
    {
        arr[i] = arr[i-1] + arr[i] ; 
        result = max( arr[i] , result ) ;
    }
    return result ;
    
}
 
