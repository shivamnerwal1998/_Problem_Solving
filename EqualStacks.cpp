stack<int> initializeStack(vector<int> h)
{
    stack<int> st ;
    int height = 0 ; 
    for( int i = h.size()-1 ; i >= 0  ; i-- )
    {
        height += h[i] ; 
        st.push(height) ; 
        
    }
    return st ;
    
}

int findLargest( int h1 , int h2 , int h3 )
{
    int largest = ( (h1 > h2) ? h1 : h2 ) ; 
    return (largest > h3 ? largest : h3) ; 
    
}
int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
    
    stack<int> stack_1 ; 
    stack<int> stack_2 ;
    stack<int> stack_3 ; 
     
    stack_1 = initializeStack(h1) ;
    stack_2 = initializeStack(h2) ; 
    stack_3 = initializeStack(h3) ; 
        int h_1 = 0 , 
            h_2 = 0 ,
            h_3 = 0 ;
        
    while( 1 )
    {
        if( stack_1.empty() || stack_2.empty() ||  stack_3.empty( ) ) break ; 
        
        h_1 = stack_1.top() ; 
        h_2 = stack_2.top(); 
        h_3 = stack_3.top(); 
        
          
        
        if( h_1 == h_2 && h_1 == h_3 ) return h_1 ; 
        
        int largest = findLargest( h_1 , h_2 , h_3 ) ;
        
        if( largest == h_1 ) stack_1.pop() ; 
        
        else if( largest == h_2 ) stack_2.pop();
         
        else if( largest == h_3 ) stack_3.pop() ;  
        
    
    }
    return 0 ; 
     

}
