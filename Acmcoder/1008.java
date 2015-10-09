
import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int num, last, count;
        while(true){
            num = sc.nextInt();
            if(num == 0)
                return;
            last = 0;
            count = 0;
            for(int i = 0; i < num; i++){
                int request = sc.nextInt();
                if(request > last){
                    count += 6 * (request - last) + 5;
                    last = request;
                } else {
                    count += 4 * (last - request) + 5;
                    last = request;
                }
            }
            System.out.println(count);
        }
    }
}
