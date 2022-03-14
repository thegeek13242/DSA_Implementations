import java.util.*;

public class fibo_dp_optimised {
    int fibo(int term, HashMap memo) {
        if (memo.containsKey(term))
            return (int) memo.get(term);
        if (term == 1)
            return 0;
        if (term == 2)
            return 1;
        memo.put(term, fibo(term - 1, memo) + fibo(term - 2, memo));
        return (int) memo.get(term);
    }

    public static void main(String[] args) {
        fibo_dp_optimised ob = new fibo_dp_optimised();
        HashMap<Integer, Integer> memo = new HashMap<Integer, Integer>();
        System.out.println(ob.fibo(40, memo));

    }
}