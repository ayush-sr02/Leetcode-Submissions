class Solution {

    boolean isValid(int i, int j, int n, int m){
        return i>=0 && j>=0 && i<n && j<m;
    }

    public int orangesRotting(int[][] grid) {
        int ans=0,n=grid.length,m=grid[0].length;
        Queue<ArrayList<Integer>> q = new LinkedList<>();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.offer(new ArrayList<>(Arrays.asList(0,i,j)));
                }
            }
        }
        while(q.size()!=0){
            int size = q.size();
            while(size-->0){
                int time = q.peek().get(0);
                int x = q.peek().get(1);
                int y = q.peek().get(2);
                q.poll();
                ans=Math.max(ans,time);
                for(int i=-1;i<=1;i++){
                    for(int j=-1;j<=1;j++){
                        if(Math.abs(i)!=Math.abs(j)){
                            int xd = x+i, yd = y+j;
                            if(isValid(xd,yd,n,m)==true){
                                if(grid[xd][yd]==1){
                                    q.offer(new ArrayList<>(Arrays.asList(time+1,xd,yd)));
                                    grid[xd][yd]=2;
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return ans;
    }
}