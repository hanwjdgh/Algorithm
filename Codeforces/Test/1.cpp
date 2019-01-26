#include <iostream>
#include <vector>

using namespace std;

bool solution(vector<int> arrA, vector<int> arrB) {
   bool answer = false;

   if (arrA.size() != arrB.size())
      answer = false;

   else {
      for (int j = 0; j < arrB.size(); j++) {
         int idx = 0;
         if (arrA[0] == arrB[j]) {
            idx = j;

            int start = 0, cnt = 0;

            while (start < arrA.size()) {
               if (arrB[idx] == arrA[start]) {
                  idx++;
                  start++;
                  cnt++;
               }
               else {
                  answer = false;
                  break;
               }

               if (idx >= arrB.size()) {
                  idx %= arrB.size();
               }
            }
            if (cnt != arrA.size())
               answer = false;
            else
               answer = true;
         }
         if (answer)
            break;
      }

   }

   return answer;
}