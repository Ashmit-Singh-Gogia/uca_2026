import java.util.*;

public class Pascal_First_Type {

    public static int getPascalValue(int n, int r) {
        // 5c3
        int combinationValue = 1; // ncr
        for (int i = 0; i < r; i++) {
            combinationValue *= (n - i);
            combinationValue /= (i + 1);
        }
        return combinationValue;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int r = sc.nextInt(), c = sc.nextInt();
        int pascalValue = getPascalValue(r - 1, c - 1);
        System.out.printf("Pascal Value at row %d and %d is %d\n", r, c, pascalValue);
    }
}