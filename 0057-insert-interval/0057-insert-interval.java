class Solution {
        
   public int[][] insert(int[][] intervals, int[] ni) {
       
        if (intervals.length == 0) {
            return new int[][]{ni};
        }
        
        int m = ni[0];
        int l = ni[1];
        
        for (int[] interval : intervals) {
            
            if (m <= interval[1] && l >= interval[0]) {
                m = Math.min(interval[0], m);
                l = Math.max(interval[1], l);
            }
            
        }
        
        List<List<Integer>> ans = new ArrayList<>();
        boolean f = false;
        
        for (int[] interval : intervals) {
            if (m <= interval[1] && l >= interval[0]) {
                if (!f) {
                    f = true;
                    List<Integer> temp = new ArrayList<>();
                    temp.add(m);
                    temp.add(l);
                    ans.add(temp);
                }
                continue;
            }
            ans.add(Arrays.asList(interval[0], interval[1]));
        }
        
        if (!f) {
            ans.add(Arrays.asList(m, l));
        }

        // Convert List of Lists to a 2D array
        int[][] result = new int[ans.size()][];
       
        for (int i = 0; i < ans.size(); i++) {
            
            List<Integer> row = ans.get(i);
            result[i] = new int[row.size()];
            
            for (int j = 0; j < row.size(); j++) {
                result[i][j] = row.get(j);
            }
            
        }

        if (!f) {
            Arrays.sort(result, Comparator.comparingInt(a -> a[0]));
        }
        return result;
    }    
}