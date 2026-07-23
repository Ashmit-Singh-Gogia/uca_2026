import java.util.*;

public class ReversePairs {
    static int pairs = 0; // counts the reverse pairs

    public static int countPairs(int[] left, int[] right) {
        int n1 = left.length, n2 = right.length;
        int i = 0, j = 0;
        int c = 0;
        while (i < n1 && j < n2) {
            if (left[i] > 2 * right[j]) {
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

    public static int reversePairs(int[] nums) {
        pairs = 0;
        mergeSort(nums, 0, nums.length - 1);
        return pairs;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] testCase1 = new int[] { 1, 3, 2, 3, 1 };
        int[] testCase2 = new int[] { 2, 4, 3, 5, 1 };
        System.out.printf("Expected : %d , Actual Output : %d\n", 2, reversePairs(testCase1));
        System.out.printf("Expected : %d , Actual Output : %d\n", 3, reversePairs(testCase2));
    }
}
