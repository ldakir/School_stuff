/* Author: Lamiaa Dakir
   File: Vote.java
*/
import java.io.*;
import java.util.stream.*;
import java.util.Arrays;

public class Vote{

  public static void main(String[] args) throws IOException
  {
    Stream<String> lines= new BufferedReader(new FileReader("voterdata.csv")).lines();
    Stream<String[]> splitLines= lines.map(line -> line.split(";"));

    Stream<String[]> Governor= splitLines.filter(x -> x[2].equals("Governor"));
    Stream<Tuple<Integer,Integer>> votes= Governor.map(x->{
      if (x[4].equals("Democratic")){
        return new Tuple<>(Integer.valueOf(x[6]), 0);
      }
      else if (x[4].equals("Republican"))
      {
        return new Tuple<>(0,Integer.valueOf(x[6]));
      }
      else{
        return new Tuple<>(0,0);
      }
    }
    );

    Tuple<Integer,Integer> result= votes.reduce((tuple1, tuple2) -> {
      return new Tuple<>((tuple1.fst+tuple2.fst),(tuple1.snd+tuple2.snd));
    }).get();
    System.out.println(result.fst);
    System.out.println(result.snd);

  }

}
