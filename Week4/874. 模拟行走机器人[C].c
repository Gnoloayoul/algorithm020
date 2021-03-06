//binary search, O(NlogK + KlogK)
bool lessThan(int rowOrCol, int a0, int b0, int a1, int b1) {
    if (rowOrCol == 0) 
        return b0 < b1 || b0 == b1 && a0 <= a1;
    else
        return a0 < a1 || a0 == a1 && b0 <= b1;
}

void quickSort(int **obst, int rowOrCol, int left, int right) {
    if (left >= right)
        return;

    int l = left, r = right;
    int a = obst[l][0], b = obst[l][1];
    while (l < r) {
        while (l < r && lessThan(rowOrCol, a, b, obst[r][0], obst[r][1]))
            r--;
        obst[l][0] = obst[r][0];
        obst[l][1] = obst[r][1];
        while (l < r && lessThan(rowOrCol, obst[l][0], obst[l][1], a, b))
            l++;
        obst[r][0] = obst[l][0];
        obst[r][1] = obst[l][1];
    }
    obst[l][0] = a;
    obst[l][1] = b;
    quickSort(obst, rowOrCol, left, l - 1);
    quickSort(obst, rowOrCol, r + 1, right);
}

void move(int **obstRow, int **obstCol, int size, 
          int *p, int *q, int direction, int step) {

    int l = 0, r = size - 1;
    if (direction == 0) {
        while (l < r) {
            int m = (l + r) / 2;
            if (obstCol[m][0] < *p || obstCol[m][0] == *p && obstCol[m][1] <= *q)
                l = m + 1;
            else
                r = m;
        }
        if (size == 0 || obstCol[l][0] != *p || 
            obstCol[l][0] == *p && obstCol[l][1] > *q + step)
            *q += step;
        else
            *q = obstCol[l][1] - 1;
    } else if (direction == 1) {
        while (l < r) {
            int m = (l + r) / 2;
            if (obstRow[m][1] < *q || obstRow[m][1] == *q && obstRow[m][0] <= *p)
                l = m + 1;
            else
                r = m;
        }
        if (size == 0 || obstRow[l][1] != *q || 
            obstRow[l][1] == *q && obstRow[l][0] > *p + step)
            *p += step;
        else
            *p = obstRow[l][0] - 1;
    } else if (direction == 2) {
        while (l < r) {
            int m = (l + r + 1) / 2;
            if (obstCol[m][0] < *p || obstCol[m][0] == *p && obstCol[m][1] < *q)
                l = m;
            else
                r = m - 1;
        }
        if (size == 0 || obstCol[l][0] != *p ||
            obstCol[l][0] == *p && obstCol[l][1] < *q - step)
            *q -= step;
        else
            *q = obstCol[l][1] + 1;
    } else {
        while (l < r) {
            int m = (l + r + 1) / 2;
            if (obstRow[m][1] < *q || obstRow[m][1] == *q && obstRow[m][0] < *p)
                l = m;
            else
                r = m - 1;
        }
        if (size == 0 || obstRow[l][1] != *q ||
            obstRow[l][1] == *q && obstRow[l][0] < *p - step)
            *p -= step;
        else
            *p = obstRow[l][0] + 1;
    }
}

int robotSim(int *commands, int commandsSize, int **obstacles, 
             int obstaclesRowSize, int *obstaclesColSizes) {
    
    int **obstRow = malloc(sizeof(int *) * obstaclesRowSize);
    int **obstCol = malloc(sizeof(int *) * obstaclesRowSize);
    int i;
    for (i = 0; i < obstaclesRowSize; i++) {
        obstRow[i] = malloc(sizeof(int) * 2);
        obstCol[i] = malloc(sizeof(int) * 2);
        obstRow[i][0] = obstacles[i][0];
        obstRow[i][1] = obstacles[i][1];
        obstCol[i][0] = obstacles[i][0];
        obstCol[i][1] = obstacles[i][1];
    }

    quickSort(obstRow, 0, 0, obstaclesRowSize - 1);
    quickSort(obstCol, 1, 0, obstaclesRowSize - 1);

    int direction = 0, p = 0, q = 0, max = 0;
    for (i = 0; i < commandsSize; i++) {
        if (commands[i] == -2) {
            direction = (direction + 4 - 1) % 4;
        } else if (commands[i] == -1) {
            direction = (direction + 1) % 4;
        } else {
            move(obstRow, obstCol, obstaclesRowSize, 
                 &p, &q, direction, commands[i]);
        }
        if (p * p + q * q > max)
            max = p * p + q * q;
    }

    for (i = 0; i < obstaclesRowSize; i++) {
        free(obstRow[i]);
        free(obstCol[i]);
    }
    if (obstaclesRowSize > 0) {
        free(obstRow);
        free(obstCol);
    }

    return max;
}