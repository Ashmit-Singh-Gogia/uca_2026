import java.util.*;

public class Rotate_Image {
    public static void rotate(int[][] matrix) {
        int n = matrix.length;
        int[][] temp = new int[n][n];
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                temp[c][n - r - 1] = matrix[r][c];
            }
        }

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                matrix[r][c] = temp[r][c];
            }
        }

    }

    public static void main(String[] args) {
        int[][] testCase1 = new int[][] { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
        int[][] testCase2 = new int[][] { { 5, 1, 9, 11 }, { 2, 4, 8, 10 }, { 13, 3, 6, 7 }, { 15, 14, 12, 16 } };
        rotate(testCase1);
        rotate(testCase2);

        for (int[] arr : testCase1) {
            for (int el : arr) {
                System.out.print(el + " ");
            }
            System.out.println();
        }
        System.out.println();
        System.out.println();
        for (int[] arr : testCase2) {
            for (int el : arr) {
                System.out.print(el + " ");
            }
            System.out.println();
        }

    }
}
