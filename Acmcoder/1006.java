
import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        double deg;
        while(true){
            deg = sc.nextDouble();
            if(deg == -1)
                return;
            System.out.println(String.format("%.3f", cal(deg) * 100));
        }
    }

    static double cal(double deg){
        final int total = 12 * 60 * 60;
        double count = 0;
        for(int i = 0; i < 12; i++){
            for(int j = 0; j < 60; j++){
                count += happyTime(deg, i, j);
            }
        }
        return count / total;
    }

    static double happyTime(double deg, double hour, double minute){
        //currentHour = 30 * hour + minute / 2 + second / 120 (deg)
        //currentMinute = 6 * minute + second / 10 (deg)
        //currentSecond = 6 * second (deg)
        double happpSeconds = 0, a, b;
        double[][][] ranges = new double[3][2][2];

        //deg <= |hour - minute| <= 360 - deg
        a = 1.0 / 120 - 0.1;
        b = 30 * hour - 5.5 * minute;
        ranges[0][0] = range(deg, a, b);
        ranges[0][1] = range(deg, -a, -b);

        //deg <= |hour - second| <= 360 - deg
        a = 1.0 / 120 - 6;
        b = 30 * hour + minute / 2;
        ranges[1][0] = range(deg, a, b);
        ranges[1][1] = range(deg, -a, -b);

        //deg <= |minute - second| <= 360 - deg
        a = 0.1 - 6;
        b = 6 * minute;
        ranges[2][0] = range(deg, a, b);
        ranges[2][1] = range(deg, -a, -b);

        happpSeconds = combineRanges(ranges);

        return happpSeconds;
    }

    // handle: deg <= a * s + b <= 360 - deg
    // return: result[0] <= s <= result[1]
    static double[] range(double deg, double a, double b){
        double[] result = new double[2];
        if(a > 0){
            result[0] = (deg - b) / a;
            result[1] = (360 - deg - b) / a;
        } else {
            result[0] = (360 - deg - b) / a;
            result[1] = (deg - b) / a;
        }

        if(result[0] < 0){
            result[0] = 0;
        }
        if(result[1] > 60){
            result[1] = 60;
        }
        if(result[0] > result[1]){
            result[0] = result[1] = 0;
        }

        return result;
    }

    static double combineRanges(double[][][] ranges){
        double result = 0;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                for(int k = 0; k < 2; k++){
                    result += overlap(ranges[0][i], ranges[1][j], ranges[2][k]);
                }
            }
        }
        return result;
    }

    static double overlap(double[] r1, double[] r2, double[] r3){
        double[][] tmp = new double[3][2];
        tmp[0] = r1;
        tmp[1] = r2;
        tmp[2] = r3;
        double min = 0, max = 60;
        for(int i = 0; i < 3; i++){
            if(tmp[i][0] > min)
                min = tmp[i][0];
            if(tmp[i][1] < max)
                max = tmp[i][1];
        }
        if(max < min)
            return 0;
        return max - min;
    }
}
