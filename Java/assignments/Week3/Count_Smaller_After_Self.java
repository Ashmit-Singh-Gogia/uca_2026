import java.util.*;

class Pair {
    int val;
    int index;

    Pair(int val, int index) {
        this.val = val;
        this.index = index;
    }

}

public class Count_Smaller_After_Self {

    // helper called in mergeSort
    public static void helperCount(Pair[] nums, int low, int mid, int high, int[] count) {
        int i = low, j = mid + 1;
        while (i <= mid && j <= high) {
            if (nums[i].val > nums[j].val) {
                count[nums[i].index] += (high - j + 1);
                i++;
            } else {
                j++;
            }
        }
    }

    public static void merge(Pair[] nums, int low, int mid, int high) {
        Pair[] mix = new Pair[high - low + 1];
        int i = low, j = mid + 1, k = 0;
        while (i <= mid && j <= high) {
            if (nums[i].val > nums[j].val) {
                mix[k++] = nums[i++];
            } else {
                mix[k++] = nums[j++];
            }
        }
        while (i <= mid) {
            mix[k++] = nums[i++];
        }
        while (j <= high) {
            mix[k++] = nums[j++];
        }
        for (int index = 0; index < mix.length; index++) {
            nums[index + low] = mix[index];
        }
    }

    public static void mergeSort(Pair[] nums, int low, int high, int[] count) {
        if (low >= high) {
            return;
        }
        int mid = low + (high - low) / 2;
        mergeSort(nums, low, mid, count);
        mergeSort(nums, mid + 1, high, count);
        helperCount(nums, low, mid, high, count);
        merge(nums, low, mid, high);
    }

    // Entry method
    public static List<Integer> countSmaller(int[] nums) {
        int[] count = new int[nums.length];
        List<Integer> output = new ArrayList<>();
        Pair[] pairNums = new Pair[nums.length];
        for (int i = 0; i < nums.length; i += 1) {
            pairNums[i] = new Pair(nums[i], i);
        }
        mergeSort(pairNums, 0, nums.length - 1, count);
        for (int el : count) {
            output.add(el);
        }
        return output;
    }

    public static void main(String[] args) {
        int[] testCase1 = new int[] { 5, 2, 6, 1 };
        int[] testCase2 = new int[] { -1 };
        int[] testCase3 = new int[] { -1, -1 };
        System.out.printf("Input: %s , Actual Output : %s\n", Arrays.toString(testCase1), countSmaller(testCase1));
        System.out.printf("Input: %s , Actual Output : %s\n", Arrays.toString(testCase2), countSmaller(testCase2));
        System.out.printf("Input: %s , Actual Output : %s\n", Arrays.toString(testCase3), countSmaller(testCase3));
    }
}