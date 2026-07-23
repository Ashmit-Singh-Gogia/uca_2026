import java.util.*;

public class Count_Inversions {
    static int pairs = 0;

    public static int countPairs(int[] left, int[] right) {
        int n1 = left.length, n2 = right.length;
        int i = 0, j = 0;
        int c = 0;
        while (i < n1 && j < n2) {
            if (left[i] > right[j]) {
                c += (n1 - i);
                j++;
            } else {
                i++;
            }
        }
        return c;
    }

    public static int[] merge(int[] left, int[] right) {
        int n1 = left.length;
        int n2 = right.length;

        int[] result = new int[n1 + n2];

        int i = 0, j = 0, k = 0;

        while (i < n1 && j < n2) {
            if (left[i] <= right[j]) {
                result[k++] = left[i++];
            } else {
                result[k++] = right[j++];
            }
        }

        while (i < n1) {
            result[k++] = left[i++];
        }

        while (j < n2) {
            result[k++] = right[j++];
        }

        return result;
    }

    public static int[] mergeSort(int[] nums, int low, int high) {
        if (low >= high) {
            return new int[] { nums[low] };
        }
        int mid = low + (high - low) / 2;
        int[] left = mergeSort(nums, low, mid);
        int[] right = mergeSort(nums, mid + 1, high);
        pairs += countPairs(left, right);
        return merge(left, right);
    }

    public static int countInversions(int[] nums) {
        pairs = 0;
        mergeSort(nums, 0, nums.length - 1);
        return pairs;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] testCase1 = new int[] { 4, 3, 2, 1 };
        int[] testCase2 = new int[] { 1, 2, 3, 4 };
        int[] testCase3 = new int[] { 2, 4, 1, 3, 5 };
        int[] testCase4 = new int[] { 5, 2, 6, 1, 2 };
        int[] testCase5 = new int[] { 1, 2, 4, 1, 3, 5 };

        System.out.printf("Expected : %d , Actual Output : %d\n", 6, countInversions(testCase1));
        System.out.printf("Expected : %d , Actual Output : %d\n", 0, countInversions(testCase2));
        System.out.printf("Expected : %d , Actual Output : %d\n", 3, countInversions(testCase3));
        System.out.printf("Expected : %d , Actual Output : %d\n", 6, countInversions(testCase4));
        System.out.printf("Expected : %d , Actual Output : %d\n", 3, countInversions(testCase5));
    }
}