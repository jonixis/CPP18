import java.util.Iterator;
import java.util.Vector;

public class Main {

    public static void main(String[] args) {
        Matcher<String> matcher = new Matcher<>("foo49999999");
        Vector<String> vector = new Vector<>();

        for (int i = 0; i <= 50000000; i++) {
            vector.add("foo" + i);
        }

        String element = findIf(vector.iterator(), matcher);

        if (element == null) {
            System.out.println("Did NOT find element: " + matcher.getValue());
        } else {
            System.out.println("Found element: " + element);
        }

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










