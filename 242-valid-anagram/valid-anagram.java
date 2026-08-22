class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length())
            return false;

        Map<Character, Integer> mpp = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            mpp.put(ch, mpp.getOrDefault(ch, 0) + 1);
        }

        for (int i = 0; i < t.length(); i++) {
            char ch = t.charAt(i);
            if (!mpp.containsKey(ch) || mpp.get(ch) <= 0) {
                return false;
            }
            mpp.put(ch, mpp.get(ch) - 1);

        }
        for (int count : mpp.values()) {
            if (count > 0) {
                return false;
            }
        }
        return true;
    }
}