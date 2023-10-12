package util;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
//import java.io.FileWriter;

public class ReadText {
	File src;
	FileReader fr;
	BufferedReader bufReader;

	public ReadText (String fName) {
		src = new File("c:\\temp\\"+fName+".txt"); // 원본 파일 경로명
		
		try {
			fr = new FileReader(src); // 파일 입력 문자 스트림 생성
			bufReader = new BufferedReader(fr);

		} catch (FileNotFoundException fe) {
			System.out.println("File Not Found");
		} catch (IOException e) {
			System.out.println("File Open Error!");
		}
	}
	
	/**
	 * 
	 * @return null if nothing to read, otherwise return a line (ends with EOL)
	 */
	public String readLine() {
		String line="";
		
		try {
			line= bufReader.readLine();
		} catch (IOException e) {
			System.out.println("File Read Error!");
		}
		return line;
	}
}