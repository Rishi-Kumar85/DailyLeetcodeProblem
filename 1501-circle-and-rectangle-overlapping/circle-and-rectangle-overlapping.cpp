class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        
        int closestX = max(x1, min(xCenter, x2));
        int closestY = max(y1, min(yCenter, y2));

        // Difference between circle center
        // and closest rectangle point.

        int dx = closestX - xCenter;
        int dy = closestY - yCenter;

        // Compare squared distance with squared radius.

        return (dx * dx + dy * dy) <= radius * radius;
    }
};