#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *sortedSquares(int *A, int ASize, int *returnSize) {

  *returnSize = ASize;
  int length = ASize - 1;

  // use dual pointer
  int *pFront = A;
  int *pRear = A + ASize - 1;

  int *result = (int *)malloc(sizeof(int) * (*returnSize));

  while ((pFront <= pRear) && (length >= 0)) {
    // postive or negative?
    *pFront = (*pFront < 0) ? (-1 * (*pFront)) : *pFront;
    *pRear = (*pRear < 0) ? (-1 * (*pRear)) : *pRear;

    // Comparing
    if (*pFront > *pRear) {
      result[length] = (*pFront) * (*pFront);
      (*pFront)++; // move front pointer to the next;
    } else {
      result[length] = (*pRear) * (*pRear);
      (*pRear)--; // move rear pointer forward;
    }
    length--;
  }
  return result;
}
