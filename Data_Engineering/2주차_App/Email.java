package kr.ac.sejong.kmooc.data_engineering;

public class Email {
	//데이터 추상화
	int from;	//보낸사람
	int to;		//받는사람
	
	//프로시저 추상화\
	public Email(int from, int to) {
		this.from=from;
		this.to=to;
	}
	public String toString() {
		return from +" -> "+to;
	}

}
