/*
    Given an array of distinct elements, you can choose any subset from the array and reorder them. You can place following operators between them: +, -, *, /, (, ) and evaluate the value of the expression. Your task is to find the minimum positive number which cannot be formed using the array elements. You can use the elements of an array only once for an expression.

    Example 1:
    Input: [1, 2]
    Output: 4
    Explanation:
    1 and 2 are already present in the array.
    You can make 3 by adding 1 and 2 i.e. 3 = 1+2
    There no possible way to make 4.

    Example 2:
    Input: [1,2,3]
    Output: 10
*/

/*
brute force approach
    We generate every possible permutation of the given array.
     For each possible missing positive value starting from 1 to a maximum possible missing value (let's say 100000009), we iterate and apply depth-first search (DFS) with the current permutation. 
     We examine whether obtaining the current target is possible by applying three operations: addition, subtraction, multiplication, and division. When we encounter a target that cannot be achieved using these operations, we identify it as our first missing positive integer.
*/

bool evaluateExpression(vector<int>& expr, int target, int idx, int current) {
    if (idx == expr.size()) {
        return current == target; 
    }

    if (evaluateExpression(expr, target, idx + 1, current + expr[idx])) {
        return true;
    }
    
    if (evaluateExpression(expr, target, idx + 1, current - expr[idx])) {
        return true;
    }
    
    if (evaluateExpression(expr, target, idx + 1, current * expr[idx])) {
        return true;
    }
    
    if (evaluateExpression(expr, target, idx + 1, current / expr[idx])) {
        return true;
    }

    return false;
}

bool canObtainTarget(vector<int>& nums, int target) {
    vector<int> expr = nums;
    
    do {
        if (evaluateExpression(expr, target, 0, 0)) {
            return true;
        }
    } while (std::next_permutation(expr.begin(), expr.end()));

    return false;
}

int smallestMissing(vector<int> &nums){
    int maxPossibleMissing = 100000009;
    
    for(int target = 1; target <= maxPossibleMissing; target++){
        if(!canObtainTarget(nums, target)){
            return target;
        }
    }
    
    return maxPossibleMissing + 1;
}