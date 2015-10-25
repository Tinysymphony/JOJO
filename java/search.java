/*
 * wytiny 10.25
 * 中文分词程序，在拥有字典的情况下进行分词
 */
package wytiny;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    static private Map map;
    static File dict;
    static private int MaxLen = 5;

    public static void main(String[] args){
        String path = new File("").getAbsolutePath() + "/" + "dictionary.txt";
        initMap(path);
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()){
            System.out.println(split(sc.nextLine()));
        }
        clear();
    }

    static private String split(String line){
        String str = line, result = "";
        while(str.length() != 0){
            int end = MaxLen;
            if(str.length() < MaxLen){
                end = str.length();
            }
            String tmp = str.substring(0, end);
            while(true) {
                if (query(tmp) || tmp.length() == 1) {
                    result += tmp + "/";
                    str = str.substring(tmp.length(), str.length());
                    break;
                }
                tmp = tmp.substring(0, tmp.length() - 1);
            }
        }
        return result.substring(0, result.length() - 1);
    }

    static private void initMap(String path){
        dict = new File(path);
        map = new HashMap<String, Boolean>();
        String encoding = "GBK";
        try {
            if(dict.exists() && dict.isFile()){
                InputStreamReader read = new InputStreamReader(new FileInputStream(dict), encoding);
                BufferedReader bufferedReader = new BufferedReader(read);
                String line = "";
                while ((line = bufferedReader.readLine()) != null){
                    map.put(line, true);
                    if(line.length() > MaxLen)
                        MaxLen = line.length();
                }
                read.close();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static private boolean query(String str){
        return map.containsKey(str);
    }

    static private void clear(){
        map.clear();
    }
}
