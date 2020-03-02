import java.lang.Math;

public class Chapter2Ex_5 {
	// 判断素数
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

		int random = 0;
		// 取100个随机数
		for(int i=0; i<100; i++){
			random = (int)(Math.random()*1000);
			if(prime(random))
				System.out.println(random+" 不是素数");
			else
				System.out.println(random+" 是素数");
		}
	}
}