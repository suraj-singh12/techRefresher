import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner inp = new Scanner(System.in);

        String s = inp.next();
        int ctr = 0;
        char prev = s.charAt(0);
        for(int i = 1; i < s.length(); ++i) {
            if(s.charAt(i) == (char)(prev + 1) || s.charAt(i) == prev) {
                ctr = i;
                prev = s.charAt(i);
            }
        }
        inp.close();
        System.out.println(ctr);
    }
}