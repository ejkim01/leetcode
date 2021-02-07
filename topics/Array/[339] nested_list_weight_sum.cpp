/*
Given a nested list of integers, return the sum of all integers in the list weighted by their depth.
Each element is either an integer, or a list -- whose elements may also be integers or other lists.
Example 1:
Given the list [[1,1],2,[1,1]], return 10. (four 1's at depth 2, one 2 at depth 1)
Example 2:
Given the list [1,[4,[6]]], return 27. (one 1 at depth 1, one 4 at depth 2, and one 6 at depth 3; 1 + 4*2 + 6*3 = 27)
*/

int depthSum(vector<NestedInteger>& nestedList) {
    stack<pair<NestedInteger, int>> st;

    for (int i=nestedList.size()-1; i>=0; i--) {
        st.push(make_pair(nestedList[i], 1));
    }

    int sum = 0;
    while (!st.empty()) {
        auto p = st.top(); st.pop();

        if (p.first.isInteger()) {
            sum += p.first.getInteger()*p.second;
        } else {
            for (int i=0; i<p.first.getList().size(); i++)
                st.push(make_pair(p.first.getList()[i], p.second+1));
        }
    }
    return sum;
}
