import java.util.Arrays;

public class slice {

	private int[] args;
	private int cap;
	private int length;

	public slice(int[] args, int cap,int length){
		this.args = args;
		this.cap = cap;
		this.length = length;
	}

	// 格式化打印
	public void sliceToString(){
		System.out.print("[");
		for(int i=0; i< this.length; i++) {
			System.out.print(this.args[i] + ",");
		}
		System.out.println(this.args[this.length]+"]");
	}

	// 扩容
	public void addCapacity() {
		this.cap *= 2;
		int[] temp = new int[cap];
		System.arraycopy(this.args, 0, temp, 0, this.length+1);
		this.args = temp;
	}

	/**
	 * [insertData description]
	 * @Author:  LiWei-Gu:1821414u@gmail.com
	 * @DateTime 2020-03-30
	 * @param    data                        [插入的数据]
	 * @param    position                    [插入的位置]
	 */
	public void insertData(int data, int position) {
		// 判断是否需要扩容
		int tempLength = this.length + 1;
		if(tempLength == this.cap)
			addCapacity();
		if(tempLength == position){ // 判断需要增加的数据是否为数组末尾
			this.args[position] = data;
			this.length = tempLength;
			return;
		} else if(position < tempLength) {	// 判断增加的数据是否在合理长度范围内
			int[] temp = new int[this.cap];
			System.arraycopy(this.args, 0, temp, 0, position);
			temp[position] = data;
			System.arraycopy(this.args, position, temp, position+1, tempLength-position);
			this.args = temp;
			this.length = tempLength;
		} else {
			System.out.println("Error:数组越界，可选范围在 0 - "+ tempLength + "之间！");
			return;
		}
	}

	/**
	 * [deleteData description]
	 * @Author:  LiWei-Gu:1821414u@gmail.com
	 * @DateTime 2020-03-30
	 * @param    position                    [删除数据的位置]
	 */
	public void deleteData(int position){
		if( this.length < position){
			System.out.println("Error:数组越界，可选范围在 0 - "+ this.length + "之间！");
		} else {
			int[] temp = new int[this.cap];
			System.arraycopy(this.args, 0, temp, 0, position);
			System.arraycopy(this.args, position+1, temp, position, this.length-position+1);
			System.out.println("被删除的数据为:" + this.args[position]);
			this.args = temp;
			this.length--;
		}
	}
 
	public static void main(String[] args){
		int[] arr = new int[]{1,2,3,4,5};
		slice sl = new slice(arr, 5, 4);
		sl.sliceToString();
		sl.insertData(6, 6);
		sl.insertData(6, 3);
		sl.sliceToString();
		sl.deleteData(7);
		sl.deleteData(3);
		sl.sliceToString();
	}
}














