import java.util.*;
import java.math.BigInteger;

public class Remainders {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        while(true){
            int b = s.nextInt();
            if(b==0){
                break;
            }
            String p = s.next();
            String m = s.next();
            BigInteger pI = new BigInteger(p, b);
            BigInteger mI = new BigInteger(m, b);
            BigInteger md = pI.mod(mI);
            System.out.println(md.toString(b));
        }
    }
}
