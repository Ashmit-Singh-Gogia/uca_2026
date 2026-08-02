import java.util.Arrays;

public class QuickSelect {

    public static int[] getSmallestK(int[] arr, int k) {
        quickSelect(arr, 0, arr.length - 1, k - 1);
        return Arrays.copyOfRange(arr, 0, k);
    }

    private static void quickSelect(int[] arr, int left, int right, int kIndex) {
        if (left >= right)
            return;

        int pivotIndex = partition(arr, left, right);

        if (pivotIndex == kIndex) {
            return;
        } else if (pivotIndex > kIndex) {
            quickSelect(arr, left, pivotIndex - 1, kIndex);
        } else {
            quickSelect(arr, pivotIndex + 1, right, kIndex);
        }
    }

    private static int partition(int[] arr, int left, int right) {
        int pivot = arr[right];
        int i = left;

        for (int j = left; j < right; j++) {
            if (arr[j] <= pivot) {
                swap(arr, i, j);
                i++;
            }
        }

        swap(arr, i, right);
        return i;
    }

    private static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void main(String[] args) {
        int[] data = { 10, 4, 5, 8, 6, 11, 26 };
        int k = 3;

        int[] result = getSmallestK(data, k);

        System.out.println("Smallest " + k + " elements: " + Arrays.toString(result));
    }
}