class Solution {
    public int maxVowels(String s, int k) {
        HashSet <Character> set = new HashSet<>();
        set.add('a');
        set.add('e');
        set.add('i');
        set.add('u');
        set.add('o');
        int n = s.length();
        int i=0,j=0;
        int max =0;
        int curr=0;
        while(j<n){
            if(set.contains(s.charAt(j))){
                curr++;
            }
            if(j-i+1 < k){
                j++;
            }else if(j-i+1 == k){
                max = Math.max(max,curr);
                if(set.contains(s.charAt(i))){
                    curr--;
                }
                i++;j++;

            }
        }
        
        return max;
    }
}