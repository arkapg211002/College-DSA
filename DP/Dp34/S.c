#include <stdio.h>
#include <string.h>

int isAllStars(char* S1, int i) {
  for (int j = 1; j <= i; j++) {
    if (S1[j - 1] != '*')
      return 0;
  }
  return 1;
}

int wildcardMatching(char* S1, char* S2) {

  int n = strlen(S1);
  int m = strlen(S2);

  int prev[m + 1];
  int cur[m + 1];

  memset(prev, 0, sizeof(prev));
  memset(cur, 0, sizeof(cur));

  prev[0] = 1;

  for (int i = 1; i <= n; i++) {
    cur[0] = isAllStars(S1, i);
    for (int j = 1; j <= m; j++) {

      if (S1[i - 1] == S2[j - 1] || S1[i - 1] == '?')
        cur[j] = prev[j - 1];

      else {
        if (S1[i - 1] == '*')
          cur[j] = prev[j] || cur[j - 1];

        else cur[j] = 0;
      }
    }
    memcpy(prev, cur, sizeof(prev));
  }

  return prev[m];
}

int main() {

  char S1[] = "ab*cd";
  char S2[] = "abdefcd";

  if (wildcardMatching(S1, S2))
    printf("String S1 and S2 do match\n");
  else printf("String S1 and S2 do not match\n");

  return 0;
}
