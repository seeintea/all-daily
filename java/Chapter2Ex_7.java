import java.util.Scanner;
import java.lang.Math;

public class Chapter2Ex_7 {

	// 判断质数
	public static boolean isPrime(int num){
		int sqrt = (int)Math.sqrt(num);
		for(int i=3; i<=sqrt; i++){
			if(num%i==0)
				return true;
		}
		return false;
	}
	
	public static boolean prime(int num){
		if(num==1) return false;
		if(num%2==0 || isPrime(num)) return true;
		return false;
	}

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
		if(n%2!=0)
			System.out.println("请输入一个偶数!");
		else {
			int temp = 0;
			int half = n/2;
			for(int i=1; i<=half; i++){
				if(!prime(i)){
					temp = n - i;
					if(!prime(temp))
						System.out.println(n+"="+i+"+"+temp);
				}
			}
		}
	}
}