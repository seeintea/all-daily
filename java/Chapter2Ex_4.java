import java.lang.Math;

public class Chapter2Ex_4 {
	/**
	 * [main description]
	 * @Author:  LiWei-Gu:1821414u@gmail.com
	 * @DateTime 2020-03-02
	 */
	public static void main(String[] args) {
		// 返回结果
		double sum = 0;
		// 基准数
		double base = 1;
		// 加减标志
		int n = 0;
		double count = 0;
		// 循环位
		boolean state = true;
		while(state){
			count = base/(2*n+1);
			if(n%2==0){
				sum += count;
			} else {
				sum -= count;
			}
			n++;
			// 求出前五十项和
			if(n==49){
				System.out.println("前50项的值为:"+sum);
				if(1e-5 > count)
					state = false;
			}
			// 最后一项小于1e-5的和值
			if(1e-5 > count){
				System.out.println("最后一项的值为:"+count);
				System.out.println("最后一项小于1e-5的和值:"+sum);
				if(n>49)
					state = false;
			}
		}
	}
}