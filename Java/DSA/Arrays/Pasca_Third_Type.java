import java.util.*;

public class Pasca_Third_Type {

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

    public static List<List<Integer>> generate(int r) {
        List<List<Integer>> pascalTriangle = new ArrayList<>();
        for (int row = 1; row <= r; row++) {
            pascalTriangle.add(getPascalRow(row));
        }
        return pascalTriangle;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int r = sc.nextInt();
        List<List<Integer>> ans = generate(r);
        for (List<Integer> list : ans) {
            for (int el : list) {
                System.out.print(el + " ");
            }
            System.out.println();
        }
    }
}
