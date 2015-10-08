
import java.util.Scanner;
import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()){
            int num = sc.nextInt();
            if(num == 0)
                return;
            HashMap<String, Integer>ballons = new HashMap<String, Integer>();
            String maxColor = "", currentColor ="";
            int times = 0;
            while(num-- > 0){
                currentColor = sc.next();
                if(ballons.containsKey(currentColor)){
                    ballons.put(currentColor, ballons.get(currentColor) + 1);
                } else {
                    ballons.put(currentColor, 1);
                }
            }
            for(Map.Entry<String, Integer> entry : ballons.entrySet()){
                if(entry.getValue() > times){
                    maxColor = entry.getKey();
                    times = entry.getValue();
                }
            }
            System.out.println(maxColor);
        }
    }
}
