/*************************************************************************
	> File Name: RegExpTest.java
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Tue 30 May 2017 01:56:23 AM CST
 ************************************************************************/
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class RegExpTest {

	public static void main(String[] args) {
		String str = "北京市(朝阳区)(西城区)(海淀区)";
		Pattern p = Pattern.compile(".*?(?=\\()");
		Matcher m = p.matcher(str);
		if(m.find()) {
			System.out.println(m.group());
		}
	}
}

