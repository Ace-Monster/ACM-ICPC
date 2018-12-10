import java.util.Scanner;

public class Main {
    static public void main(String argc[]){
        String s = new String();
        int i = 1;
        for(i = 1;s.length() <= 1000;i++){
            s += i;
        }
        int n;
        Scanner IN = new Scanner(System.in);
        n = IN.nextInt();
        System.out.println(s.charAt(n-1));
        return;
    }
}

