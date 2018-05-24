/*************************************************************************
	> File Name: findMaxForm1.java
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Tue 25 Apr 2017 11:10:59 PM CST
 ************************************************************************/

public class findMaxForm1 {
	public static int findMaxForm(String[] strs, int m, int n) {
		int[][] dp = new int[m+1][n+1];
		for (String s : strs) {
			int[] count = count(s);
			for (int i=m;i>=count[0];i--) 
				for (int j=n;j>=count[1];j--)
					/**
					 *                      * dp表示以当前的能用的0和1 的组合，能获得的最大情况
					 *                                           * */
					dp[i][j] = Math.max(1 + dp[i-count[0]][j-count[1]], dp[i][j]);
		}
		return dp[m][n];
	}

	/**
	 *      * 统计0和1的数量
	 *           * */
	public static int[] count(String str) {
		int[] res = new int[2];
		for (int i=0;i<str.length();i++)
			res[str.charAt(i) - '0']++;
		return res;
	}

	public static void main(String[] args){
		String[] strs = {"00", "000"};
		int m = 1;
		int n = 10;
		int number = 0;

		number = findMaxForm(strs, m, n);
		System.out.println( number + ", true is 0" );

		String[] strs11 = {"10", "0", "1"};
		m = 1; n = 1;
		number = findMaxForm(strs11, m, n);
		System.out.println( number + ", true is 2");

		String[] strs1 = {"10", "0", "1", "0", "1", "0", "1", "11", "0", "1"};
		m = 10; n = 10;
		number = findMaxForm(strs1, m, n);
		System.out.println( number + ", true is 10");

		String[] strs2 = {"10", "0001", "111001", "1", "0"};
		m = 5; n = 3;
		number = findMaxForm(strs2, m, n);
		System.out.println( number + ", true is 3");

		String[] strs3 = {"0","1101","01","00111","1","10010","0","0","00","1","11","0011"};
		m = 63; n = 36;
		number = findMaxForm(strs3, m, n);
		System.out.println( number + ", true is 12");

		String[] strs4 = {"10","0001","111001","1","0"};
		m = 3; n = 4;
		number = findMaxForm(strs4, m, n);
		System.out.println( number + ", true is 3");

		String[] strs5 = {"0","11","1000","01","0","101","1","1","1","0","0","0","0","1","0","0110101","0","11","01","00","01111","0011","1","1000","0","11101","1","0","10","0111"};
		m = 9; n = 80;
		number = findMaxForm(strs5, m, n);
		System.out.println( number + ", true is 17");

		String[] strs6 = {"111","1000","1000","1000"};
		m = 9; n = 3;
		number = findMaxForm(strs6, m, n);
		System.out.println( number + ", true is 3");

		String[] strs7 = {"11","1000","1000","1000"};
		m = 9; n = 3;
		number = findMaxForm(strs7, m, n);
		System.out.println( number + ", true is 3");

		String[] strs8 = {"11","10","00","10", "00", "11", "10"};
		m = 3; n = 3;
		number = findMaxForm(strs8, m, n);
		System.out.println( number + ", true is 3");

		String[] strs9 = {"00","10","00","10", "00", "11", "10", "11", "11", "10", "10" , "10", "10"};
		m = 6; n = 6;
		number = findMaxForm(strs9, m, n);
		System.out.println( number + ", true is 6");

	}
}


