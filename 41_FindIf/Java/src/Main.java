import java.util.Iterator;
import java.util.Vector;

public class Main {

    public static void main(String[] args) {
        Matcher<String> matcher = new Matcher<>("foo");
        Vector<String> vector = new Vector<>();

        for (int i = 0; i < 50000000 - 1; i++ ) {
            vector.add(""+i);
        }

        vector.add("foo");

        long startTime = System.nanoTime();
        String element = findIf(vector.iterator(), matcher);
        long endTime = System.nanoTime();

        double totalTime = (endTime - startTime) / 1000000000.00;


        if (element == null) {
            System.out.println("Did NOT find element: " + matcher.getValue());
        } else {
            System.out.println("Found element: " + element);
        }
        System.out.println("Elapsed time: " + totalTime + " seconds");

    }

    private static <E> E findIf(Iterator<E> iter, IMatcher<E> matcher) {
        E element;

        while (iter.hasNext()) {
            element = iter.next();
            if (matcher.match(element)) {
                return element;
            }
        }
        return null;
    }

}










