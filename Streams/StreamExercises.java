/* Author: Lamiaa Dakir
   File: StreamExercises.java
*/

import java.util.stream.*;
import java.util.*;
public class StreamExercises
{
  public static Optional<String> longest(List<String> strings)
  {
    return strings.stream().max(Comparator.comparing(String:: length));
  }

  public static <A extends Comparable<? super A>> Stream<A> top5(Stream<A> input)
  {
    return input.sorted(Comparator.reverseOrder()).limit(5);
  }

  //From Lambda.java
  public static boolean isPrime(int n)
  {
   return n > 1 && IntStream.range(2,n).filter(d -> n % d == 0).count() == 0;
  }

  public static int sumPrimes(int lo, int hi)
  {
    return IntStream.range(lo,hi+1).filter(d -> isPrime(d) == true).sum();
  }


  public static void main(String[] args)
  {
    System.out.println(longest(Arrays.asList("these","are","some","strings","in","a","list")));
      // prints Optional[strings]

    System.out.println(longest(new ArrayList<>()));
      // prints Optional.empty

    System.out.println(top5(Stream.of(6,2,9,10,3,8,6,34)).collect(Collectors.toList()));
      // prints [34, 10, 9, 8, 6]

    System.out.println(sumPrimes(5,15));
      // prints 36

    System.out.println(longest(Arrays.asList("these", "are", "some", "strings", "in", "a", "list"))); // prints Optional[strings]
    System.out.println(longest(new ArrayList<>())); // prints Optional.empty
    //Tests for top5
    System.out.println(top5(Arrays.asList("these", "are", "some", "strings", "in", "a", "list").stream()).collect(Collectors.toList())); // prints [these, strings, some, list, in]
    System.out.println(top5(Stream.of("Java", "Magazine", "is", "the", "best")).collect(Collectors.toList())); // prints ["the", "is", "best", "Magazine", "Java"]
    System.out.println(top5(Stream.of(6, 2, 9, 10, 3, 8, 6, 34)).collect(Collectors.toList())); // prints [34, 10, 9, 8, 6]
    System.out.println(top5(Stream.of(-1, -2, -4, -5, -6)).collect(Collectors.toList())); //prints [-1, -2, -4, -5, -6]

    //Tests for sumPrimes
    System.out.println(sumPrimes(1, 1)); //prints 0
    System.out.println(sumPrimes(-1, -1)); //prints 0
    System.out.println(sumPrimes(-1, 2)); //prints 2
    System.out.println(sumPrimes(12, 13)); //prints 13
    System.out.println(sumPrimes(5, 15)); // prints 36
    }
}
