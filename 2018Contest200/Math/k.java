import java.io.*;
import java.math.*;
import java.util.*;

public class k {
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		int T;
		T = in.nextInt();
		int i = 1;
		while(T > 0){
			BigInteger n;
			n = in.nextBigInteger();
			BigInteger x1 = new BigInteger ("8");
			BigInteger x2 = new BigInteger ("7");
			BigInteger x3 = new BigInteger ("1");
			BigInteger ant = (n.multiply(n.multiply(x1))).subtract(n.multiply(x2)).add(x3);
			System.out.println("Case "+(i++)+": "+ant);
			T--;
		}
	}
}

