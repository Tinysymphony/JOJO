package wytiny;

import java.util.Scanner;

public class Main {
    //every 49 numbers, there shall be a period.
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int [] arr = new int[50];
        int a, b, n;
        while(true){
            a = sc.nextInt() % 7;
            b = sc.nextInt() % 7;
            n = sc.nextInt();
            if(a == 0 && b == 0 && n == 0)
                return;
            for(int i = 1; i <= 49; i++){
                if(i == 1 || i == 2){
                    arr[i] = 1;
                } else {
                    arr[i] = (a * arr[i - 1] + b * arr[i - 2]) % 7;
                }
            }
            System.out.println(arr[n % 49]);
        }
    }
}
