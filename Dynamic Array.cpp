/*
  Declare a 2-dimensional array, , of  empty arrays. All arrays are zero indexed.
Declare an integer, , and initialize it to .

There are  types of queries, given as an array of strings for you to parse:

Query: 1 x y
Let .
Append the integer  to .
Query: 2 x y
Let .
Assign the value  to .
Store the new value of  to an answers array.
Note:  is the bitwise XOR operation, which corresponds to the ^ operator in most languages. Learn more about it on Wikipedia.  is the modulo operator.
Finally, size(arr[idx]) is the number of elements in arr[idx]

Function Description

Complete the dynamicArray function below.

dynamicArray has the following parameters:
- int n: the number of empty arrays to initialize in 
- string queries[q]: query strings that contain 3 space-separated integers

Returns

int[]: the results of each type 2 query in the order they are presented
Input Format

The first line contains two space-separated integers, , the size of  to create, and , the number of queries, respectively.
Each of the  subsequent lines contains a query string, .

Constraints

It is guaranteed that query type  will never query an empty array or index.
Sample Input

2 5
1 0 5
1 1 7
1 0 3
2 1 0
2 1 1
Sample Output

7
3
*/


vector<int> dynamicArray(int n, vector<vector<int>> queries) {
    
    vector<vector<int>> arr( n ) ;
    
    
                    
    vector<int> result  ;
    int last_answer = 0  ; 
    for( int i = 0 ;  i < queries.size() ; i++)
    {
        
            int q = queries[i][0] ; 
            int x = queries[i][1] ;
            int y = queries[i][2] ;
            int idx ;
            switch (q) 
            {
                case 1 :
                 
                 idx = ((x ^ last_answer) % n)  ;
                 arr[idx].emplace_back(y) ;
                 
                break; 
                
                case 2 :
                    idx = ((x ^ last_answer) % n)  ;
                    last_answer = arr[idx][y%( arr[idx].size() )] ;
                    result.emplace_back(last_answer) ; 
                
                break; 
                
            }       
            
        
    }
   return result ;

}
