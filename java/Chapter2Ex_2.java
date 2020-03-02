public class Chapter2Ex_2 {
	/**
	 * [main description]
	 * @Author:  LiWei-Gu:1821414u@gmail.com
	 * @DateTime 2020-03-02
	 */
	public static void main(String[] args) {
		double PI = 0;
		double base = 4.0;
		boolean state = true;
		int n = 0;
		int div = 0;
		while(state){
			div = 2*n+1;
			if(n++%2 == 0)
				PI += base/div;
			else
				PI -= base/div;
			if(3.1415<PI && PI<3.1416)
				state = false;
		}
		System.out.println("值为:" + PI);
	}
}