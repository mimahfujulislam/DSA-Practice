#include <iostream>
using namespace std;

int lcs(int X[], int Y[], int m, int n) {
   int L[11][11] = {0};

   for (int i = 0; i <= m; i++) {
       for (int j = 0; j <= n; j++) {
           if (i == 0 || j == 0)
               L[i][j] = 0;
           else if (X[i-1] == Y[j-1])
               L[i][j] = L[i-1][j-1] + 1;
           else
               L[i][j] = max(L[i-1][j], L[i][j-1]);
       }
   }

   int len = L[m][n];
   int lcs[10];
   int i = m, j = n;
   int index = len - 1;
   while (i > 0 && j > 0) {
       if (X[i-1] == Y[j-1]) {
           lcs[index] = X[i-1];
           i--;
           j--;
           index--;
       }

       else if (L[i-1][j] >= L[i][j-1])
           i--;
       else
           j--;
   }
   cout << "\nLCS is: ";
   for (int i = 0; i < len; i++)
       cout << lcs[i] << " ";
   cout << "\nLength: " << len << endl;

   return len;
}

int main() {
   int A1[] = {2,1,7,3,5,4,8,9,3,6};
   int profits[] = {1,3,5,2,4,3,6,7,8,9};
   int m = sizeof(A1)/sizeof(A1[0]);
   int n = sizeof(profits)/sizeof(profits[0]);
   lcs(A1, profits, m, n);
   return 0;
}
