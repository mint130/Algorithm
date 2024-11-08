import java.util.HashSet;

class Solution {
	 private static HashSet<Integer> PrimeNumbers = new HashSet<>();
	 private static boolean[] IsSelected;
	
	 public int solution(String numbers) {
		 	StringBuilder currentNum = new StringBuilder();
		 	IsSelected = new boolean[numbers.length()];
		 
	        combination(numbers, currentNum, 0);
	        return PrimeNumbers.size();
	    }
	    
	    private static void combination(String numbers, StringBuilder nums, int count) {
	        if (numbers.length() == count) return;
	        
	        for (int i = 0; i < numbers.length(); i++) {
	        	if (IsSelected[i])	continue;
	        	
	            nums.append(numbers.charAt(i));
	            IsSelected[i] = true;
	            
	            int value = Integer.parseInt(nums.toString());
	            if (isPrimeNumber(value)) {
	            	PrimeNumbers.add(value);
	            }
	            
	            combination(numbers, nums, count + 1);
	            
	            nums.deleteCharAt(nums.length() - 1);
	            IsSelected[i] = false;
	        }
	    }
	    
	    private static boolean isPrimeNumber(int num) {
	        if (num < 2)    return false;
	        
	        for (int i = 2; i * i <= num; i++) {
	            if (num % i == 0)   return false;
	        }
	        
	        return true;
	    }
}