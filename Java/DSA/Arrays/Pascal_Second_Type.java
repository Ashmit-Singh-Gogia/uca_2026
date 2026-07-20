import java.util.*;

public class Pascal_Second_Type {

    public static List<Integer> getPascalRow(int r) {
        List<Integer> list = new ArrayList<>();
        int p = 1;
        list.add(p);
        for (int c = 1; c < r; c++) {
            p *= (r - c);
            p /= (c);
            list.add(p);
        }
        return list;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int r = sc.nextInt();
        List<Integer> rthPascalRow = getPascalRow(r);
        for (int el : rthPascalRow) {
            System.out.print(el + " ");
        }

    }
}