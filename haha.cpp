 //storing given array's size in n
        int n = digits.size();
        
        //taking flag for putting a condition further in code
        bool flag = 0;
        
        //traversing from the last for incrementing with a condition i.e. digit should be < 9.
        for(int i = n-1; i>=0; i--){
            //checking condition whether digit < 9
            if(digits[i]<9){
                digits[i] = digits[i] + 1;
                flag = 1;
                break;
            }else{
                //if digit is not < 9, then we have to make it 0(coz 9 + 1 = 10(0 in this case, as we are taking ones place))
                digits[i] = 0;
            }
        }
        //checking if flag is still 0, if it is 0 then we have to insert 1 at the beginning
        if(flag==0){
            digits.insert(digits.begin(), 1);
        }
        return digits;