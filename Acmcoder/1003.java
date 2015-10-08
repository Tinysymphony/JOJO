import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int times = sc.nextInt();
        int caseCount = 0;
        while(times-- > 0){
            int num = sc.nextInt();
            int max = sc.nextInt();
            int tmpMax = max >= 0 ? max : 0, left, right;
            left = right = 1;
            int i = 1;
            int flag = max >= 0 ? 0 : 2;
            while(++i <= num){
                int tmp = sc.nextInt();
                tmpMax += tmp;
                if(tmpMax > max) {
                    max = tmpMax;
                    right = i;
                    if (flag != 0) {
                        left = flag;
                        flag = 0;
                    }
                }
                if (tmpMax < 0) {
                    tmpMax = 0;
                    flag = i + 1;
                }
            }
            System.out.println("Case " + ++caseCount + ":");
            System.out.println(max + " " + left + " " + right);
            if(times != 0)
                System.out.println();
        }
        sc.close();
    }
}
