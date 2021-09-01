
// Greedy Approach 

int twoStacks(int maxSum, vector<int> a, vector<int> b) {
    
    int n = a.size() - 1 , 
        m = b.size() - 1 ;
        
    int count = 0 , 
        i = 0 , 
        j = 0 ;
    
    int sum = 0 ;   
        
    while( 1 )
    {
     
        
        if( a[i] < b[j] )
        {
            if( (sum + a[i] ) <= maxSum ) 
            {
                sum += a[i] ;
                count++ ;
                i++ ;
                if( i > n  || sum == maxSum ) break ;    
            }
            else return count ;  
            
        }
        else 
        {
            if( sum + b[j] <= maxSum )
            {
                sum += b[j] ; 
                count++ ; 
                j++ ;
                if( j > m  || sum == maxSum ) break ;  
            }
            else return count ; 
            
        }
        
      
        
    }
    
      while( i <= n   )
        {
        
            
            if( sum + a[i] <= maxSum )
            {
                sum += a[i] ; 
                count++ ; 
                i++ ; 
            }
            else return count ; 
          
            
        }
            
            
        
        while( j <= m  )
        {
         
                if( sum + b[j] <= maxSum )
            {
                sum += b[j] ; 
                count++ ; 
                j++ ; 
            }
            else return count ; 
            
        } 
        return count ; 
    
}

// efficient approach
