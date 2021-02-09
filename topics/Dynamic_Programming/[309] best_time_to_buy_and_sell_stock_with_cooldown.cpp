/*
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:
Input: [1,2,3,0,2]
Output: 3 
Explanation: transactions = [buy, sell, cooldown, buy, sell]
*/

int maxProfit(vector<int>& prices) {
    int sold = 0;
    int rest = 0;
    int hold = INT_MIN;
    for (const int price : prices) {
        int prev_sold = sold;
        sold = hold + price;
        hold = max(hold, rest - price);
        rest = max(rest, prev_sold);
    }
    return max(rest, sold);
}
