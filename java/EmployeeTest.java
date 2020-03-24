public class EmployeeTest {
	public static void main(String[] args) {
		Employee[] emp = new Employee[4];
		emp[0] = new SalariedEmployee("ts0", 1, 1000);
		emp[1] = new HourlyEmployee("ts1", 2, 200, 21);
		emp[2] = new SalesEmployee("ts2", 3, 30000, 0.3);
		emp[3] = new BasedPlusSalesEmployee("ts3", 4, 40000, 0.4, 1000);

		for(int i=0; i<emp.length; i++)
			System.out.println(emp[i].getName()+ " 3月应得工资: " + emp[i].getSalary(3));
	}
}

class Employee {
	private String name;
	private int month;

	public Employee(String name, int month) {
		this.name = name;
		this.month = month;
	}

	public String getName() {
		return name;
	}

	public double getSalary(int month) { 
		if(this.month == month) {
			return 100.0;
		}
		return 0.0;
	}
}

class SalariedEmployee extends Employee {
	private double monthSalary;

	public SalariedEmployee(String name, int month, double monthSalary) {
		super(name, month);
		this.monthSalary = monthSalary;
	}

	public double getSalary(int month) {
		double sum = monthSalary + super.getSalary(month);
		return sum;
	}
}

class HourlyEmployee extends Employee {
	private int hours;
	private double hourSalary;

	public HourlyEmployee(String name, int month, int hours ,double hourSalary){
		super(name, month);
		this.hours = hours;
		this.hourSalary = hourSalary;
	}

	public double getSalary(int month) {
		double sum = super.getSalary(month);
		if(hours <= 160) {
			sum += hours*hourSalary;
		} else {
			sum += 160*hourSalary + (hours-160)*1.5*hourSalary;
		}
		return sum;
	}
}

class SalesEmployee extends Employee{
	private double salesCount;
	private double rate;

	public SalesEmployee(String name,int month,double salesCount,double rate){
		super(name,month);
		this.salesCount = salesCount;
		this.rate = rate;
	}

	public double getSalary(int month){
		double sum = salesCount*rate + super.getSalary(month);
		return sum;
	}
}

class BasedPlusSalesEmployee extends SalesEmployee {
	private double based;

	public BasedPlusSalesEmployee(String name,int month,double salesCount,double rate,double basedPlus){
		super(name,month,salesCount,rate);
		this.based = based;
	}	

	public double getSalary(int month){
		double sum =  based + super.getSalary(month);
		return sum;
	}
}
















