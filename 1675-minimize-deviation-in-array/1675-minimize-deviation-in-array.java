class Solution {
    public int minimumDeviation(int[] nums) {
        TreeSet<Integer> ts= new TreeSet<>();
     
     for(int i:nums){
       if(i%2==1) i=i*2;    
       ts.add(i);
     }
     
     int diff=Integer.MAX_VALUE;
     while(true){
       int max=ts.last();
       int min=ts.first();
       diff=Math.min(diff,max-min); 
       if(max%2==0)
       {
         ts.remove(max);
         ts.add(max/2);
       }else{
         break;
       }
     }
     return diff;
    }
}