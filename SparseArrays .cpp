vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
    
     
    vector<int> vec( queries.size() ,0) ;
    for( int i = 0 ; i < queries.size() ;  i++ )
    {
        for(int j = 0 ; j < strings.size(); j++ )
        {
            if( queries[i] == strings[j]  )
            {
                vec[i]++ ; 
            }
        }
    }   
    return vec ;

}
