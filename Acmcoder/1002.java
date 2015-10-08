
import java.util.Scanner;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
	// write your code here
        Scanner sc = new Scanner(System.in);
        int times;
        BigInteger a, b, sum;
        times = sc.nextInt();
        for (int i = 1; i <= times; i++){
            a = sc.nextBigInteger();
            b = sc.nextBigInteger();
            sum = a.add(b);
            System.out.println("Case " + i + ":");
            System.out.println(a + " + " + b + " = " + sum);
            if(i < times)
                System.out.println();
        }
        sc.close();
    }
}
