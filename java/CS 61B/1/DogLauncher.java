public class DogLauncher {
	public static void main(String[] arg){
		// create Dog Object
		// using constructor function
		Dog yip = new Dog(9);
		Dog wof = new Dog(35);
		Dog maxDog = Dog.maxDog(yip,wof);
		//d.weightInKilogram = 25;
		//d.makeNoise();
		maxDog.makeNoise();
		Dog minDog = yip.minDog(wof);
		minDog.makeNoise();

		System.out.println(Dog.binomen);
		System.out.println(yip.binomen);

	}
}