import java.util.*;
class Solution {
    public ArrayList<Integer> maxOfSubarrays(int[] arr, int k) {
        ArrayList<Integer> ans = new ArrayList<>();
        for(int i=0;i<=arr.length-k;i++){
            int max=0;
            for(int j=i;j<i+k;j++){
                if(arr[j]>max){
                    max=arr[j];
                    
                }
                
            }
            ans.add(max);
        }
        return ans;
    }
}