long largestRectangle(vector<int> h) {
    
    stack<int> s ; 
    int n = h.size() ; 
    int left_smaller[n]; 
    int right_smaller[n];
     
    for( int i = 0 ; i < n ; i++  ){
        
        while( !s.empty() && h[s.top()] >= h[i] ) s.pop() ; 
        if( s.empty() ) left_smaller[i] = 0 ;
        else left_smaller[i] = s.top()+1 ; 
        s.push(i) ; 
    }
    while( !s.empty()  ) s.pop() ; 
    
    int maxA = 0 ;  
    for( int i = n-1 ; i >= 0 ; i--)
    {
           while( !s.empty() && h[s.top()] >= h[i] ) s.pop() ; 
            if( s.empty() ) right_smaller[i] = n-1 ;
            else right_smaller[i] = s.top()-1 ; 
            s.push(i) ;
            int a ; 
            a = h[i] *( right_smaller[i] - left_smaller[i] + 1  ) ; 
            maxA = max( maxA , a ) ;  
        
    }
    return maxA ; 
    
}
