import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

import java.util.ArrayList;

import java.lang.Math;

public class Part1 {
    
    /** file to be read */
    private String _filename;
    
    /** list of all the binary numbers in the input file */
    private ArrayList<ArrayList<Integer>> _input;

    /** list containing both the gamma rate and epsilon rate */
    private ArrayList<ArrayList<Integer>> _res;


    public Part1(String filename) {
        _filename = filename;
        _input = new ArrayList<ArrayList<Integer>>();
        _res = new ArrayList<ArrayList<Integer>>();
    }

    
    public String getFilename() { return _filename; }
    public void setFilename(String filename) { _filename = filename; }

    public ArrayList<ArrayList<Integer>> getInput() { return _input; }

    public ArrayList<ArrayList<Integer>> getRes() { return _res; }


    public void computeInput(String txtfile) throws IOException {

        try(BufferedReader input = new BufferedReader(new FileReader(txtfile))) {
            
            String lines;

            while ((lines = input.readLine()) != null) {

                String line = new String(lines.getBytes(), "UTF-8");

                ArrayList<Integer> binaryNumber = new ArrayList<Integer>();

                for(int i = 0; i < line.length(); i++) {
                    
                    binaryNumber.add(Character.getNumericValue(line.charAt(i)));
                }

                _input.add(binaryNumber);
            }

        } catch(IOException e) {
            System.out.println("Error: computeInput()");
            return;
        }
    }


    public void calcRes(String txtfile) throws IOException {

        int zero = 0;
        int one = 0;

        ArrayList<Integer> gammaRate = new ArrayList<Integer>();
        ArrayList<Integer> epsilonRate = new ArrayList<Integer>();

        _res.add(gammaRate);
        _res.add(epsilonRate);

        computeInput(txtfile);

        int size = _input.get(0).size();

        for(int counter = 0; counter < size; counter++) {

            for(ArrayList<Integer> number: _input) {
    
                if(number.get(counter) == 0) { zero++; }
                else if(number.get(counter) == 1) { one++; }
            }
    
            if(zero > one) {
                _res.get(0).add(0);
                _res.get(1).add(1);
            }
            else if(one > zero) {
                _res.get(0).add(1);
                _res.get(1).add(0);
            }
    
            zero = 0;
            one = 0;
        }
    }


    public int getDecimalValue(ArrayList<Integer> values) {

        int res = 0, size = values.size();

        for(int i = 0; i < size; i++) {
            res += Math.pow(2, size-1 - i)*values.get(i);  
        }

        return res;
    }


    public void printRate(ArrayList<Integer> rate) {

        for(int n: rate) {
            System.out.print(n);
        }
        System.out.println();
    }


    public int getFinalRes() throws IOException {
        
        calcRes(_filename);
        
        ArrayList<Integer> gammaRate = _res.get(0);
        ArrayList<Integer> epsilonRate = _res.get(1);

        System.out.println("----------\nBinary:");
        printRate(gammaRate);
        printRate(epsilonRate);
        System.out.println("----------");

        int gRate = getDecimalValue(gammaRate);
        int eRate = getDecimalValue(epsilonRate);

        System.out.println("Decimal:");
        System.out.println(gRate);
        System.out.println(eRate);
        System.out.println("----------");

        return gRate * eRate;
    }
}
