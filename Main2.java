import java.util.*;


public class Main2 {
    public static void main(String[] args) {
        Scanner inp = new Scanner(System.in);

        String s = inp.next();
        int n = s.length();

        int sum = 0;
        for(int i = 0; i < n; ++i) {
            if(s.charAt(i) >= '0' && s.charAt(i) <= '9') {
                int tmp = 0;
                while(i < n && s.charAt(i) >= '0' && s.charAt(i) <= '9') {
                    tmp  = tmp * 10 + (int)(s.charAt(i) - '0');
                    i++;
                }
                sum += tmp;
            }
        }
        System.out.println(sum);
    }    
}
