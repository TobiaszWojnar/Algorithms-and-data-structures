package l2;
import java.util.Scanner;

public class GetData {
    public static String[] hasValidArgs (String[] args){

        String [] arguments = new String[2];

        if (args.length<4){
            throw new IndexOutOfBoundsException("IndexOutOfBoundsException\n not enough parameters");
        }

        if(!args[0].equals("--type")&& !args[2].equals("--type")){
            System.out.println(args[0]);
            throw new IllegalArgumentException("IllegalArgumentException\nno type");
        }
        if(!args[0].equals("--comp") && !args[2].equals("--comp")){
            throw new IllegalArgumentException("IllegalArgumentException\nno comp");
        }


        if(args[0].equals("--type")){
            if (args[1].equals("insert") || args[1].equals("merge") || args[1].equals("quick")){
                arguments[0] = args[1];
            } else {
                throw new IllegalArgumentException("IllegalArgumentException\n "+args[1]+" - invalid type");
            }
            if (args[3].equals(">=") || args[3].equals("<=")){
                arguments[1] = args[3];
            } else {
                throw new IllegalArgumentException("IllegalArgumentException\n "+args[3]+" - invalid comp");
            }
        } else {
            if (args[3].equals("insert") || args[3].equals("merge") || args[3].equals("quick")){
                arguments[0] = args[3];
            } else {
                throw new IllegalArgumentException("IllegalArgumentException\n "+args[1]+" - invalid type");
            }
            if (args[1].equals(">=") || args[1].equals("<=")){
                arguments[1] = args[1];
            } else {
                throw new IllegalArgumentException("IllegalArgumentException\n "+args[3]+" - invalid comp");
            }
        }
        return arguments;
    }

    public static int[] getTable (){
        String[] splited;
        String line;
        int n;
        int[] table;

        Scanner myIn = new Scanner(System.in);  // Create a Scanner object
        System.out.println("Enter length of table:");
        line = myIn.nextLine();
        try {
            n = Integer.parseInt(line);
        } catch (NumberFormatException e){
            System.out.println("NumberFormatException: " + line + " - not integer");
            return null;
        }

        table = new int[n];
        line = myIn.nextLine();
        splited=line.split(" ");
        if (table.length!=splited.length){
            throw new IndexOutOfBoundsException ("IndexOutOfBoundsException: number of numbers not correct");
        }
        for (int i=0;i<n;i++){
            try {
                table[i]= Integer.parseInt(splited[i]);
            } catch (NumberFormatException e){
                System.out.println("NumberFormatException: " + splited[i] + " - not integer");
                return null;
            }
        }
        return table;
    }
}
