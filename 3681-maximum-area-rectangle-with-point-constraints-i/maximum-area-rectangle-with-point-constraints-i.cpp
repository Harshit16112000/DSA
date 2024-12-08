class Solution {
public:

    int findArea(vector<vector<int>>& points)
    {
        vector<int> tr,tl,br,bl;
        bl = points[0];
        tl = points[1];
        br = points[2];
        tr = points[3];

        if(bl[0] != tl[0] || br[0] != tr[0])  return -1;
        if(bl[1] != br[1] || tl[1] != tr[1])  return -1;

        return (tl[1]-bl[1]) * (br[0] - bl[0]);
    }

    bool hasPointInBetween(vector<vector<int>> point, vector<vector<int>>points)
    {
        vector<int> tr,tl,br,bl;
        bl = point[0];
        tl = point[1];
        br = point[2];
        tr = point[3];

        for(int i=0;i<points.size();i++)
        {
            if(points[i] == bl || points[i] == tl || points[i] == br || points[i] == tr)
             continue;

            int x = points[i][0];
            int y = points[i][1];

           if (x >= bl[0] && x <= br[0] && y >= bl[1] && y <= tl[1]) {
                return true; 
            }
        }
        return false;

    }
    int maxRectangleArea(vector<vector<int>>& points) {
       int n = points.size();
       int area = -1;
       if(n < 4)  return area;

       
       for(int i=0;i<n;i++)
       {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                for(int l= k+1;l<n;l++)
                {
                    vector<vector<int>> point = {points[i], points[j],
                    points[k], points[l]};
                    sort(point.begin(), point.end());

                    int ar = findArea(point);
                    if(ar == -1)  continue;

                    if(hasPointInBetween(point, points))
                      continue;
                    area = max(area,ar);
                }
            }
        }
       }

       return area;

    }
};