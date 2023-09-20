class Solution {
    public boolean isNumber(String s) {
        return s.matches("(\\s*)[+-]?((\\.[0-9]+)|([0-9]+(\\.[0-9]*)?))([eE][+-]?[0-9]+)?(\\s*)");
    }
}