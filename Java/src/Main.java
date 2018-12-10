import java.util.Scanner;

public class Main {
    static int Ami(int n){
        int ans = 1;
        for(int i = 2;i*i <= n;i++){
            if(n%i == 0) ans += (i+n/i);
        }
        return ans;
    }
    static public void main(String argc[]){
        int n,m;
        Scanner IN = new Scanner(System.in);
        m = IN.nextInt();
        n = IN.nextInt();
        for(int i = m;i <= n;i++){
            if(i == Ami(Ami(i))) System.out.println(i);
        }

        return;
    }
}
