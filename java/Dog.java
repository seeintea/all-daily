public class Dog {
	public int weightInKilogram;

	// static variables
	public static String binomen = "Canis familiaris";

	// constructor for dogs
	public Dog(int w) {
		this.weightInKilogram = w;
	}

	public void makeNoise(){
		if(weightInKilogram < 10) {
			System.out.println("yip!");
		}else if(weightInKilogram < 30 ){
			System.out.println("bark!");
		}else {
			System.out.println("wooof!");
		}
	}

	//Non-statci compare with self 
	public Dog minDog(Dog d){
		if(weightInKilogram > d.weightInKilogram){
			return d;
		}
		return this;
	}

	// static method compare dog size
	public static Dog maxDog(Dog d1, Dog d2){
		if(d1.weightInKilogram>d2.weightInKilogram) {
			return d1;
		}
		return d2;
	}
}