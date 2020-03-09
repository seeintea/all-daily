public class Chapter3Ex_2{

	public static void main(String[] args) {
		TeacherTest ts = new TeacherTest();
		ts.teacherInfoPrint();
		System.out.println("修改后的薪水:");
		ts.teacherSalaryAdd();
	}
}

// Teacher 类
class Teacher {
	private String name;	// 姓名
	private int age;		// 年龄
	private double salary;	// 薪水

	/**
	 * [Teacher 构造函数]
	 * @Author:  LiWei-Gu:1821414u@gmail.com
	 * @DateTime 2020-03-09
	 */
	public Teacher(String name, int age, double salary){
		this.name = name;
		this.age = age;
		this.salary = salary;
	}

	/**
	 * [addSalary 增加薪水]
	 * @Author:  LiWei-Gu:1821414u@gmail.com
	 * @DateTime 2020-03-09
	 */
	public void addSalary() {
		this.salary += 5000;
	}

	/**
	 * [Get function]
	 * @Author:  LiWei-Gu:1821414u@gmail.com
	 * @DateTime 2020-03-09
	 */
	public String getName() {
		return name;
	}

	public int getAge() {
		return age;
	}

	public double getSalary() {
		return salary;
	}

}

// TeacherTest 类
class TeacherTest {
	public Teacher t = new Teacher("Teacher", 25, 3000.00);

	/**
	 * [teacherInfoPrint 打印函数]
	 * @Author:  LiWei-Gu:1821414u@gmail.com
	 * @DateTime 2020-03-09
	 */
	public void teacherInfoPrint(){
		System.out.println("打印教师信息:");
		System.out.println("教师名字:" + t.getName());
		System.out.println("教师年龄:" + t.getAge());
		System.out.println("教师薪水:" + t.getSalary());
	}

	/**
	 * [teacherSalaryAdd 增加薪水并打印]
	 * @Author:  LiWei-Gu:1821414u@gmail.com
	 * @DateTime 2020-03-09
	 */
	public void teacherSalaryAdd() {
		t.addSalary();
		System.out.println("教师薪水:" + t.getSalary());
	}
}
