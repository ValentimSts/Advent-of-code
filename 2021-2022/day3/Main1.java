import java.io.IOException;

public class Main1 {

    public static void main(String[] args) {

        int res;
        Part1 ia = new Part1("day3.txt");
        
        try {

            res = ia.getFinalRes();
            System.out.println(res);

        } catch(IOException e) {
            System.out.println("Error <ending>");
            return;
        }
    }
}
