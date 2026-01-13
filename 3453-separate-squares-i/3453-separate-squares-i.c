double getAreaBelow(int** squares, int squaresSize, double y) {
    double currentArea = 0.0;
    for (int i = 0; i < squaresSize; i++) {
        double bottom = squares[i][1];
        double len = squares[i][2];
        double top = bottom + len;

        if (y >= top) {
            currentArea += len * len;
        } else if (y > bottom) {
            currentArea += len * (y - bottom);
        }
    }
    return currentArea;
}

double separateSquares(int** squares, int squaresSize, int* squaresColSize) {
    double totalArea = 0.0;
    double minY = 2e9;
    double maxY = 0.0;

    for (int i = 0; i < squaresSize; i++) {
        double l = squares[i][2];
        double bottom = squares[i][1];
        
        totalArea += l * l;
        
        if (bottom < minY) minY = bottom;
        if (bottom + l > maxY) maxY = bottom + l;
    }

    double targetArea = totalArea / 2.0;
    double low = minY;
    double high = maxY;
    
    for (int i = 0; i < 70; i++) {
        double mid = low + (high - low) / 2.0;
        double areaBelow = getAreaBelow(squares, squaresSize, mid);

        if (areaBelow < targetArea) {
            low = mid;
        } else {
            high = mid;
        }
    }
    
    return high;
}