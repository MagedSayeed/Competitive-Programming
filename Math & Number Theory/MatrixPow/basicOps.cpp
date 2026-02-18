typedef int matrixType;
typedef vector<matrixType> row;
typedef vector<row> matrix;

/// Zero matrix
matrix zero(int n, int m) {
    return matrix(n, row(m, 0));
}

//// identity Matrix -> diagonal = 1
matrix identity(int n) {
    matrix ret = zero(n, n);
    for (int i = 0; i < n; ++i) {
        ret[i][i] = 1;
    }
    return ret;
}

/// matrix trace sum of diagonal values
matrixType matrixTrace(matrix a) {
    matrixType ret = 0;
    for (int i = 0; i < a.size(); ++i) {
        ret += a[i][i];
    }
    return ret;
}

/**
 * clockwise Rotation
 * Before       After
 * 1 7 4        0 1
 * 0 9 4        9 7
 *              4 4
 */
matrix rotation(matrix v) {
    matrix ret = zero(v[0].size(), v.size());
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[0].size(); ++j) {
            ret[j][v.size() - i - 1] = v[i][j];
        }
    }
    return ret;
}

/**
 * clockwise Reflection
 * around Y axis
 * Before       After
  * 1 7 4       4 7 1
 * 0 9 4        4 9 0
 */
matrix reflection(matrix v) {
    matrix ret = zero(v.size(), v[0].size());
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[0].size(); ++j) {
            ret[i][v[0].size() - j - 1] = v[i][j];
        }
    }
    return ret;
}

matrix addIdentity(matrix v) {
    for (int i = 0; i < v.size(); ++i) {
        v[i][i]++;
    }
    return v;
}

/**
 *  Matrix Multiplication
 *  (A*B) *(B*C) => B is a shared column and Result is A*C
 *  cell (i , j) = ith Row * jth Column
 *
 */
matrix multiply(matrix &a, matrix &b) {
    matrix ret = zero(a.size(), b[0].size());
    for (int i = 0; i < a.size(); ++i)
        for (int j = 0; j < b[0].size(); ++j)
            for (int k = 0; k < a[0].size(); ++k)
                ret[i][j] += a[i][k] * b[k][j];

    return ret;
}
matrix pow(const matrix &a, int k) {
    if (k == 0) {
        return identity(a.size());
    }
    if (k & 1)return multiply(a, pow(a, k - 1));
    return pow(multiply(a, a), k / 2);
}


/**
 * Sum of Powers of matrix a
 * (a^1 + a^2 + a^3 + a^4 + a^5 + a^6) = (a^1 + a^2 + a^3) + (a^1 * a^3 + a^2 * a^3 + a^3 * a^3)
 * (a^1 + a^2 + a^3) + a^3 * (a^1 + a^2 + a^3) = (a^1 + a^2 + a^3) * (I  + a^3). => I identity
 what if n is odd ?
 * (a^1 + a^2 + a^3 + a^4 + a^5 + a^6 + a^7) = a + a * (a^1 + a^2 + a^3 + a^4 + a^5 + a^6)
    = a (1 + a^1 + a^2 + a^3 + a^4 + a^5 + a^6)

 */
matrix sumPows(matrix a, int k) {
    if (k == 0) {
        return zero(a.size(), a.size());
    }
    if (k & 1) {
        return multiply(a, addIdentity(sumPows(a, k - 1)));
    }
    return multiply(sumPows(a, k / 2), addIdentity(pow(a, k / 2)));
}
