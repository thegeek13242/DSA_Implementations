import java.util.*;

/* 
* Given a target sum and an array
* find whether it is possible to 
* get the target sum using the values in array 
*/

public class canSum {
    boolean canSumImp(int targetSum, int[] values, HashMap memo)
    {
        if(memo.containsKey(targetSum))
            return (boolean)memo.get(targetSum);
        if(targetSum == 0)
            return true;
        if(targetSum < 0)
            return false;
        for(int i:values)
        {
            memo.put(targetSum-i,canSumImp(targetSum-i,values,memo));
            return (boolean) memo.get(targetSum-i);
        }
        return false;
    }

    public static void main(String[] args) {
        canSum ob = new canSum();
        HashMap<Integer, Boolean> memo = new HashMap<>();
        int[] arr = {3,5,6};
        System.out.println(ob.canSumImp(300, arr, memo));
    }
}
