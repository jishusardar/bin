package Basic.problems_ids;

public class add_digits {
    public int add_digits(int n){
        while(n>=10){
            int temp=0;
            while(n!=0){
                int rem=n%10;
                n/=10;
                temp+=rem;
            }
            n=temp;
        }
        return n;
    }
}
