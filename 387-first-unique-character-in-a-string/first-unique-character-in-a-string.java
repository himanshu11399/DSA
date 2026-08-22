class Solution {
    public int firstUniqChar(String s) {
        Map<Character, Integer> mpp = new HashMap<>();

        for (int i = 0; i < s.length(); i++) {
            mpp.put(s.charAt(i), mpp.getOrDefault(s.charAt(i), 0) + 1);
        }
        int idx = -1;
        for (int i = 0; i < s.length(); i++) {
            if (mpp.get(s.charAt(i)) == 1) {
                idx = i;
                break;
            }
        }
        return idx;
    }
}