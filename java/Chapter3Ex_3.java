public class Chapter3Ex_3 {
	public static void main(String[] args) {
		Person p1 = new Person("boy", 25, true);
		Person p2 = new Person("girl1", 21, false);
		Person p3 = new Person("girl2", 24, false, p1);
		p1.marray(p2);
	}
}

class Person {
	
	private String name;
	private int age;
	private boolean gender;	// true-man false-famale
	private Person partner;

	/**
	 * [Person 构造函数]
	 * @Author:  LiWei-Gu:1821414u@gmail.com
	 * @DateTime 2020-03-09
	 */
	public Person(String name, int age, boolean gender){
		this.name = name;
		this.age = age;
		this.gender = gender;
		this.partner = null;
	}

	public Person(String name, int age, boolean gender, Person partner){
		this.name = name;
		this.age = age;
		this.gender = gender;
		this.partner = partner;
		partner.setPartner(this);
	}

	public void marray(Person p){
		if(this.partner != null){
			System.out.println("已婚");
			return;
		}
		boolean myResult = this.marrayMatch(this.gender, this.age);
		if(!myResult)
			return;
		int marrayAge = p.getAge();
		boolean marrayGender = p.isGender();
		boolean marryResult = this.marrayMatch(marrayGender, marrayAge);
		if(!marryResult)
			return;
		this.partner = p;
		p.setPartner(this);
		System.out.println("结婚登记");
	}

	private boolean marrayMatch(boolean mGender, int mAge){
		if(mGender && mAge < 24){
			System.out.println("男性年龄要求大于24");
			return false;
		} else if(!mGender && mAge < 22){
			System.out.println("女性年龄要求大于22");
			return false;
		}
		return true;
	}

	/**
	 * [Get Set function]
	 * @Author:  LiWei-Gu:1821414u@gmail.com
	 * @DateTime 2020-03-09
	 */
	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getAge() {
		return age;
	}

	public void setAge(int age) {
		this.age = age;
	}

	public boolean isGender() {
		return gender;
	}

	public void setGender(boolean gender) {
		this.gender = gender;
	}

	public Person getPartner() {
		return partner;
	}

	public void setPartner(Person partner) {
		this.partner = partner;
	}
}