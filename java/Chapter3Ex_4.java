public class Chapter3Ex_4 {
	public static void main(String[] args) {

		Animal a = new Animal();
		a.move();
		a.move(3);
		Animal b = new Animal("Cow", 4);
		b.move();
		b.move(5);
		Fish f = new Fish();
		f.move();
		f.move(7);
	}
}

class Animal {
	private String name;
	private int legs;

	public Animal(){
		this.name = "AAA";
		this.legs = 4;
	}

	public Animal(String name, int legs){
		this.name = name;
		this.legs = legs;
	}

	public void move() {
		System.out.println( this.name + " Moving!");
	}

	public void move(int n){
		if(n<0) return; 
		for(int i=1; i<n; i++)
			System.out.println( this.name + " Moving!");
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getLegs() {
		return legs;
	}

	public void setLegs(int legs) {
		this.legs = legs;
	}
}

class Fish extends Animal {
	public Fish() {
		super("Fish",0);	
	}
}