
#leetcode 414 Third Maximum Numbe

Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).

##Example 1:
Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.
Example 2:
Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.

##Example 3:
Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.

===================
```cpp
class Solution {
public:
        int thirdMax(vector<int>& nums) {
                int first,second,third;
                int min=std::numeric_limits<int>::min(),tmp,tmp2;
                first=second=third=min;
                for (vector<int>::iterator it = nums.begin() ; it != nums.end(); ++it)
                {
                        if(*it > first){
                                tmp = first;
                                first = *it;
                                if(tmp <= second)
                                        continue;
                                else{
                                        tmp2 = second;
                                        second = tmp;
                                        if(tmp2 <= third)
                                                continue;
                                        else
                                                third = tmp2;
                                }
                        }
                        else if(*it  > second ){
                                tmp2 = second;
                                second = *it;
                                if(tmp2 <= third)
                                        continue;
                                else
                                        third = tmp2;
                        }
                        else if(*it  > third ){
                                third = *it ;
                        }
                }

                if(third == second)
                        return first;
                else if(min == third)
                        return first;
                else
                        return third;

        }
};
int main(void)                                                     
{                                                                  
//      char j = 128, j2=1;                                                  
//      printf("%02X = %016X =%02x\n", (unsigned char) (j),  (long long)j,j2);             
//      char i = 0;                                                    
//      for (i = 0; i < 8; i++)                                        
//      {                                                              
//              int num = (j << 8) | (i);                                  
//              j++;                                                       
//              printf("%04X = %04x = %d\n", (unsigned int)num, num, num); 
//      }        
        std::vector<int> myvector;

        myvector.push_back(1);
        myvector.push_back(2);
        myvector.push_back(2);
        myvector.push_back(3);
        myvector.push_back(5);
        Solution sol;
        int ret =sol.thirdMax(myvector);
        return(0);                                                     
}     