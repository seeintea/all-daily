import java.util.Scanner;

public class Chapter2Ex_6 {
	/**
	 * [main description]
	 * @Author:  LiWei-Gu:1821414u@gmail.com
	 * @DateTime 2020-03-02
	 */
	public static void main(String[] args) {
		int n = 0;
		Scanner scanner = new Scanner(System.in);
		if(scanner.hasNext()){
			n = scanner.nextInt(); 
		}
		scanner.close();
		// 打印金字塔
		for(int i=1; i<=n; i++){
			for(int j=n-i; j>0; j--)
				System.out.print(" ");
			for(int k=0; k<2*i-1; k++)
				System.out.print("*");
			// 换行
			System.out.println();
		}
	}
}