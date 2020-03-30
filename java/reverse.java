import java.util.Arrays;

public class reverse {

	public static void arrayReverse(int[] arr) {
		int length = arr.length;
		int temp = 0;
		for(int i=0; i<arr.length/2; i++) {
			temp = arr[i];
			arr[i] = arr[--length];
			arr[length] = temp;
		}
	}

	public static void main(String[] args){
		int[] arr = new int[]{1,2,3,4,5,6};
		System.out.println(Arrays.toString(arr));
		arrayReverse(arr);
		System.out.println(Arrays.toString(arr));
	}
	
}