class Solution {
    public String multiply(String num1, String num2) {
        StringBuilder res = new StringBuilder("");
        int i1 = num1.length() - 1;
        int i2 = num2.length() - 1;
        int carry = 0;
        int rest = 0;
        List<StringBuilder> Vec = new ArrayList<StringBuilder>();
        if(num1.length() == 0 || num2.length() == 0)
            return "0";
        if(num1.equals("0") || num2.equals("0"))
            return "0";
        while(i2 > -1){                                 //to get a vector string to add
            int mul2 = num2.charAt(i2) - '0';
            StringBuilder tmp = new StringBuilder("");
            while(i1 > -1){
                int mul1 = num1.charAt(i1) -'0';
                rest = (carry + mul1 * mul2) %10;         //count for rest
                carry = (carry + mul1 * mul2) /10;       //count for carry
                tmp.insert(0,(char)(rest + '0'));
                i1--;
                if(i1 == -1 && carry != 0){
                    tmp.insert(0,(char)(carry+ '0'));
                    carry = 0;
                }
            }
            Vec.add(tmp);
            i1 = num1.length() - 1;
            i2--;
        }
        for(int i = 0; i < Vec.size(); i++){
            int j = i;
            while(j > 0){
                Vec.get(i).append("0");
                j--;
            }
        }
        rest = 0;
        int index = 0;
        do{
            rest = 0;                //reset
            for(int i = 0; i < Vec.size(); i++){
                rest += (index <= Vec.get(i).length() -1)? (Vec.get(i).charAt(Vec.get(i).length() -1 -index) - '0') : 0;
            }
            rest += carry;               //add the carry
            carry = rest /10;
            rest = rest % 10;
            res.insert(0,(char)(rest + '0'));
            index ++;
        }while(carry != 0 || rest != 0 || index < Vec.get(Vec.size() - 1).length());
        res.deleteCharAt(0);
        return ""+res;
    }
}