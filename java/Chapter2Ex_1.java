import java.util.Scanner;

public class Chapter2Ex_1 {
	/**
	 * [main description]
	 * @Author:  LiWei-Gu:1821414u@gmail.com
	 * @DateTime 2020-03-02
	 */
	public static void main(String[] args) {	
		int grade = 0;	
		// 接受输入的数据
		Scanner scanner = new Scanner(System.in);
		if(scanner.hasNext()){
			grade = scanner.nextInt();
		}
		scanner.close();
		grade /= 10;

		switch(grade){
			case 10:
			case 9 :
				System.out.println("A");
			break;
			case 8:
				System.out.println("B");
			break;
			case 7:
				System.out.println("C");
			break;
			case 6:
				System.out.println("D");
			break;
			default:
				System.out.println("E");
			break;
		}
	}
}