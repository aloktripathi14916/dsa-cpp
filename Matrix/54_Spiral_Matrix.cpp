/*
Problem: Spiral Matrix
Platform: LeetCode (LC 54)
Topic: Matrix Traversal

---------------------------------------------------------

Approach: Layer by Layer (Spiral Order)

- Maintain boundaries: top, bottom, left, right
- Traverse in this order: top row → right column → bottom row → left column
- Shrink the boundaries after completing one layer
- Repeat until all elements are traversed

Time Complexity: O(m*n)
Space Complexity: O(1) extra + O(m*n) output vector

Example:
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

Output: [1,2,3,6,9,8,7,4,5]
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& v) {
        vector<int> p;

        int m = v.size();
        int n = v[0].size();

        int srow = 0, erow = m - 1;
        int scol = 0, ecol = n - 1;

        while(srow <= erow && scol <= ecol)
        {
            // top row
            for(int i = scol; i <= ecol; i++)
                p.push_back(v[srow][i]);

            // right column
            for(int i = srow + 1; i <= erow; i++)
                p.push_back(v[i][ecol]);

            // bottom row
            if(srow < erow)
            {
                for(int i = ecol - 1; i >= scol; i--)
                    p.push_back(v[erow][i]);
            }

            // left column
            if(scol < ecol)
            {
                for(int i = erow - 1; i > srow; i--)
                    p.push_back(v[i][scol]);
            }

            srow++;
            erow--;
            scol++;
            ecol--;
        }

        return p;
    }
};
