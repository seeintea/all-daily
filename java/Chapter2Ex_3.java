import java.util.Scanner;

public class Chapter2Ex_3 {
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
		System.out.print("第"+n+"项的值为:");
		// 计算斐波那契数
		int fb = 1;
		int fa = 1;
		int temp = 0;
		boolean state = true;
		if(n==1 || n==2)
			state = false;
		while(state){
			temp = fa;
			fa += fb;
			fb = temp;
			if(--n==2)
				state = false;
		}
		System.out.println(fa);
	}
}