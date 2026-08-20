class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        Set<Integer> st = new HashSet<>();

        for (int i = 0; i < nums1.length; i++) {
            st.add(nums1[i]);
        }

        ArrayList<Integer> ans = new ArrayList<>();
        for (int i = 0; i < nums2.length; i++) {
            if (st.contains(nums2[i])) {
                ans.add(nums2[i]);
                st.remove(nums2[i]);
            }
        }

        int[] result = new int[ans.size()];
        for (int i = 0; i < ans.size(); i++) {
            result[i] = ans.get(i);
        }
        return result;
    }
}